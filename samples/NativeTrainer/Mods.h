#include "script.h"
#include "MenuFunctions.h"
namespace Mods {
	void TPToWaypoint()
	{
		int WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(8);
		if (UI::DOES_BLIP_EXIST(WaypointHandle))
		{
			Vector3 WaypointPos = UI::GET_BLIP_COORDS(WaypointHandle);
			int Handle = PLAYER::PLAYER_PED_ID();
			if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
				Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			ENTITY::SET_ENTITY_COORDS(Handle, WaypointPos.x, WaypointPos.y, WaypointPos.z, 0, 0, 0, 1);
			drawNotification("Teleported to ~g~Waypoint~HUD_COLOUR_WHITE~!");
		}
		else drawNotification("~r~Please set a Waypoint!");
	}
	void tuneUp(uint VehicleHandle)
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_VEHICLE_MOD(veh, 11, VEHICLE::GET_NUM_VEHICLE_MODS(veh, 11) - 1, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 12, VEHICLE::GET_NUM_VEHICLE_MODS(veh, 12) - 1, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 13, VEHICLE::GET_NUM_VEHICLE_MODS(veh, 13) - 1, 1);
			VEHICLE::TOGGLE_VEHICLE_MOD(veh, 18, 1);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(VehicleHandle, "Synergy");
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(VehicleHandle, 1);
			drawNotification("Vehicle ~g~Upgraded");
		}
		else
		{
			drawNotification("~r~You need to be in a Vehicle");
		}
	}
	void Godmod()
	{
		if (!PlayerGodmod)
		{
			drawNotification("Godmode ~g~Enabled");
			PlayerGodmod = true;
			PLAYER::SET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID(), true);
			PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), false);
			PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), false);
			PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), 1);
			PLAYER::GIVE_PLAYER_RAGDOLL_CONTROL(PLAYER::PLAYER_ID(), true);
			PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER::PLAYER_PED_ID(), false);
		}
		else
		{
			drawNotification("Godmode ~r~Disabled");
			PlayerGodmod = false;
			PLAYER::SET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID(), false);
			PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), false);
			PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), false);
			PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), 0);
			PLAYER::GIVE_PLAYER_RAGDOLL_CONTROL(PLAYER::PLAYER_ID(), false);
			PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER::PLAYER_PED_ID(), false);
		}
	}
}
