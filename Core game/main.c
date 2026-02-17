#include "bot.h"

//inizialisation

void ft_on_tick(unsigned long tick);

bool ft_is_miner(const t_obj *obj);

bool ft_is_carrier(const t_obj *obj);

bool ft_is_tank(const t_obj *obj);

int main(int argc, char **argv)
{
	return core_startGame("alevadni", argc, argv, ft_on_tick, false);
}

// NOT SURE HOW TO GET STARTED?
// --> Check out the wiki coregame.sh/wiki/ with a helpful "My first core bot" beginners guide!

//filtr_count

bool ft_is_miner(const t_obj *obj)
{
	if (obj->type != OBJ_UNIT) return false;
	if (obj->s_unit.unit_type != UNIT_MINER) return false;
	return true;
}

bool ft_is_carrier(const t_obj *obj)
{
	if (obj->type != OBJ_UNIT) return false;
	if (obj->s_unit.unit_type != UNIT_CARRIER) return false;
	return true;
}

bool ft_is_tank(const t_obj *obj)
{
	if (obj->type != OBJ_UNIT) return false;
	if (obj->s_unit.unit_type != UNIT_TANK) return false;
	return true;
}

bool ft_is_warrior(const t_obj *obj)
{
	if (obj->type != OBJ_UNIT) return false;
	if (obj->s_unit.unit_type != UNIT_WARRIOR) return false;
	return true;
}



//loop funktion
void ft_on_tick(unsigned long tick)
{
	printf("-----> [⚡️ TICK %ld 🔥]\n", tick);
	//in the start of game get carrier for looting 
	if(core_get_objs_filter_count(ft_is_carrier) < 1)
	{
		core_action_createUnit(UNIT_CARRIER);
	}
	else
	{
		t_obj *own_core = ft_get_core_own();
		//else we have allready carrieKO | er another units


		//make new miner if we dont have thear priority
		if (core_get_objs_filter_count(ft_is_miner) < 3)
		{
			core_action_createUnit(UNIT_MINER);
		}
		else if (core_get_objs_filter_count(ft_is_carrier) < 2)
		{
			core_action_createUnit(UNIT_CARRIER);
		}
		else if(core_get_objs_filter_count(ft_is_warrior) < 5)
		{
			core_action_createUnit(UNIT_WARRIOR);
		}
		else if(own_core-> s_core.gems)
		{
			core_action_createUnit(UNIT_TANK);
		}
	}

	t_obj **my_units = ft_get_units_own();
	
	for (size_t i = 0; my_units && my_units[i] != NULL; i++)
	{	
		t_obj *unit = my_units[i];
		
		if (unit->s_unit.unit_type == UNIT_WARRIOR)
		{
			t_obj *opponent_core = ft_get_core_opponent();
			t_obj *own_core = ft_get_core_own();
			t_obj *nearest_enemy = ft_get_units_opponent_nearest(unit->pos);
 
			if (nearest_enemy)
				core_action_pathfind(unit, nearest_enemy->pos);
			else if (opponent_core)
				core_action_pathfind(unit, opponent_core->pos);
			else if (unit -> s_unit.gems > 100)
			{
				core_action_transferGems(unit, own_core->pos, unit->s_unit.gems);
			}
		}
		else if (unit->s_unit.unit_type == UNIT_MINER)
		{
			t_obj *opponent_core = ft_get_core_opponent();
			t_obj *nearest_deposit_or_gem_pile = ft_get_deposit_nearest(unit->pos);
			

			if(!nearest_deposit_or_gem_pile)
			{
				core_action_pathfind(unit, opponent_core->pos);
			}
			else if(nearest_deposit_or_gem_pile)
			{
					core_action_pathfind(unit, nearest_deposit_or_gem_pile->pos);
			}
			// if(unit->pos.x != 3 && unit->pos.x != 17)
			// {
			// 	core_action_pathfind(unit, (t_pos){3, 17});
			// }
			// if (unit->s_unit.gems > 0)
			// {
			// 	t_obj *own_core = ft_get_core_own();
			// 	core_action_pathfind(unit, own_core->pos);
			// 	core_action_transferGems(unit, own_core->pos, unit->s_unit.gems);
			// }
			// else
			// {
				
				// if (nearest_deposit_or_gem_pile)
				// 	core_action_pathfind(unit, nearest_deposit_or_gem_pile->pos);
			//}
		}
		else if (unit->s_unit.unit_type == UNIT_CARRIER)
		{
			t_obj *nearest_enemy = ft_get_units_opponent_nearest(unit->pos);
			t_obj *own_core = ft_get_core_own();
			t_obj *nearest_deposit_or_gem_pile = ft_get_gems_nearest(unit->pos);
				if (nearest_deposit_or_gem_pile)
					core_action_pathfind(unit, nearest_deposit_or_gem_pile->pos);
				else if(unit->s_unit.gems > 100)
				{
					core_action_pathfind(unit, own_core->pos);
					core_action_transferGems(unit, own_core->pos, unit->s_unit.gems);
				}
				else
				{
					if (nearest_enemy)
						core_action_pathfind(unit, nearest_enemy->pos);
				}
		}
		else if(unit->s_unit.unit_type == UNIT_TANK)
		{
			t_obj *enemy_core = ft_get_core_opponent();
			t_obj *own_core = ft_get_core_own();
			t_obj *nearest_enemy = ft_get_units_opponent_nearest(own_core->pos);

			//attack if tick is = 1000 or more
			if(tick >= 1000)
			{
				core_action_pathfind(unit, enemy_core->pos);
			}
			else if (nearest_enemy) {
				/*enemy close to home: defend the home*/
				core_action_attack(unit, nearest_enemy);
			}
			else {
				/*no enemy near home: stay near home*/
				core_action_pathfind(unit, own_core->pos);
			}
			
		}
	}
 
	free(my_units);
}