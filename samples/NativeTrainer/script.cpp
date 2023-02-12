#include "script.h"
#include "keyboard.h"

#include "stdio.h"
#include <string>
#include <windows.h>
#include <ctime>
#include "Pattern.h"
#include <Psapi.h>
using namespace std;

#pragma warning(disable : 4244 4305) // double <-> float conversions

#include "MenuFunctions.h"

char *model;
HANDLE mainFiber;
DWORD wakeAt;
char str[50];


void BypassOnlineVehicleKick(Vehicle vehicle)
{
	Player player = PLAYER::PLAYER_ID();
	int var;
	DECORATOR::DECOR_REGISTER("Player_Vehicle", 3);
	DECORATOR::DECOR_REGISTER("Veh_Modded_By_Player", 3);
	DECORATOR::DECOR_SET_INT(vehicle, "Player_Vehicle", NETWORK::_0xBC1D768F2F5D6C05(player));
	DECORATOR::DECOR_SET_INT(vehicle, "Veh_Modded_By_Player", GAMEPLAY::GET_HASH_KEY(PLAYER::GET_PLAYER_NAME(player)));
	DECORATOR::DECOR_SET_INT(vehicle, "Not_Allow_As_Saved_Veh", 0);
	if (DECORATOR::DECOR_EXIST_ON(vehicle, "MPBitset"))
	{
		var = DECORATOR::DECOR_GET_INT(vehicle, "MPBitset");
	}
	GAMEPLAY::SET_BIT(&var, 3);
	DECORATOR::DECOR_SET_INT(vehicle, "MPBitset", var);
	VEHICLE::SET_VEHICLE_IS_STOLEN(vehicle, false);
}

char* AddStrings(char* string1, char* string2)
{
	memset(str, 0, sizeof(str));
	strcpy_s(str, "");
	strcpy_s(str, string1);
	strcat_s(str, string2);
	return str;
}
Vehicle veh;

int CREATE_VEHICLE(char* hash, float x, float y, float z)
{
	DWORD model = GAMEPLAY::GET_HASH_KEY(hash);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model))
	{
		Player playerPed = PLAYER::PLAYER_PED_ID();
		STREAMING::REQUEST_MODEL(model);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		while (!STREAMING::HAS_MODEL_LOADED(model) && !STREAMING::HAS_PTFX_ASSET_LOADED()) WAIT(0);
		{
			Vehicle veh = VEHICLE::CREATE_VEHICLE(model, x, y, z, ENTITY::GET_ENTITY_HEADING(playerPed), TRUE, TRUE);
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
			BypassOnlineVehicleKick(veh);
			VEHICLE::SET_VEHICLE_ENGINE_ON(veh, TRUE, TRUE, 1);
		}
	}
	return veh;
}

void addVehOption(char* option, char* model11, char *notification)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		CREATE_VEHICLE(model11, coords.x, coords.y, coords.z);
		drawNotification(notification);
	}
}
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

char* VehName;
uint32_t hash_veh;
int SpawnedVeh;
bool GodModeTog = false, VehicleGod = false;
char* VehicleString;
bool SpawningVehicle;
bool PlayerGodmod;
bool NoCops; 
BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID());

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
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(VehicleHandle, "Extinct");
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

int SpawnCar(int hash, int ped = PLAYER::PLAYER_PED_ID())
{
	Ped pedHandle = PLAYER::PLAYER_PED_ID();
	Vehicle vehHandle = PED::GET_VEHICLE_PED_IS_USING(pedHandle);

	if (!STREAMING::HAS_MODEL_LOADED(hash))
		STREAMING::REQUEST_MODEL(hash);
	else
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(pedHandle, true))
		{
			VEHICLE::DELETE_VEHICLE(&vehHandle);
		}
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		SpawnedVeh = VEHICLE::CREATE_VEHICLE(hash, coords.x, coords.y, coords.z, 0, 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(SpawnedVeh))
		{
			ENTITY::SET_ENTITY_HEADING(SpawnedVeh, ENTITY::GET_ENTITY_HEADING(pedHandle));
			PED::SET_PED_INTO_VEHICLE(pedHandle, SpawnedVeh, -1);
			//MaxVeh();
			ENTITY::SET_ENTITY_INVINCIBLE(SpawnedVeh, true);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(SpawnedVeh, false);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(SpawnedVeh, "Synergy");
			//if (spawncolor)
			//{
			BypassOnlineVehicleKick(SpawnedVeh);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehHandle, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehHandle, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
			//	}
			drawNotification("Vehicle ~g~Spawned");
		}
	}
}
#pragma region submenus
void Main()
{
	addTitle("Synergy GTA");
	addSubTitle("Main Menu");
	addSubmenuOption("Player Options", 2, "Modifications for YOU");
	addSubmenuOption("Players List", 3, "All Clients");
	addSubmenuOption("Weapon Options", 14, "Best Menu here");
	addSubmenuOption("Teleports", 13, "Where'd you come from");
	addSubmenuOption("Vehicle Options", 6, "Ooh Mod that car");
	addSubmenuOption("World Options", 15, "Change The Weather");
	addSubmenuOption("Menu Settings", 7, "Customise the Menu");

	normalMenuActions();
}

void Selfmenu()
{
	addTitle("Synergy GTA");
	addSubTitle("Player Options");
	addCheckBool("Toggle Invulnerability", PlayerGodmod, "Don't Be Dead");
	addCheckBool("Toggle Never Wanted", NoCops, "No Pesky Cops");
	addOption("Raise Wanted Level x1", "Ooh More Cops");
	addOption("Lower Wanted Level x1", "Yay Less Cops");
	addOption("Clean and Heal self", "Remove Blood and Heal");
	switch (getOption())
	{
		case 1: Godmod(); break;
		case 2: NoCops = !NoCops; break;
		case 3:if (bPlayerExists && PLAYER::GET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID()) < 5){PLAYER::SET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID(), PLAYER::GET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID()) + 1, 0);PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(PLAYER::PLAYER_ID(), 0);drawNotification("Wanted Level Raised");}break;
		case 4: if (bPlayerExists && PLAYER::GET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID()) > 0){PLAYER::SET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID(), PLAYER::GET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID()) - 1, 0);PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(PLAYER::PLAYER_ID(), 0);drawNotification("Wanted Level Lowered");}break;
		case 5: {ENTITY::SET_ENTITY_HEALTH(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID()), ENTITY::GET_ENTITY_MAX_HEALTH(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID())));PED::ADD_ARMOUR_TO_PED(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID()), PLAYER::GET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_PED_ID()) - PED::GET_PED_ARMOUR(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID())));if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID()), 0)){Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID()));if (ENTITY::DOES_ENTITY_EXIST(playerVeh) && !ENTITY::IS_ENTITY_DEAD(playerVeh))VEHICLE::SET_VEHICLE_FIXED(playerVeh);}drawNotification("Player Cleaned");}break;
	}

	normalMenuActions();
}


void PlayersListMenu()
{
	addTitle("Synergy GTA");
	addSubTitle("Players List");

	for (int i = 0; i < 30; i++)
	{
		addOption(PLAYER::GET_PLAYER_NAME(i), " ");
	}
	if (optionPress && PLAYER::IS_PLAYER_PLAYING(currentOption - 1))
	{
		selectedPlayer = currentOption - 1;
		changeSubmenu(4);
	}
	normalMenuActions();
}

void WeaponsMenu()
{
	addTitle("Synergy GTA");
	addSubTitle("Weapons Options");
	addOption("Give All Weapons", "Get all The Weapons");
	switch (getOption())
	{
	case 1:	for (int i = 0; i < sizeof(weaponNames) / sizeof(weaponNames[0]); i++) WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY((char *)weaponNames[i]), 1000, 0); drawNotification("Awarded All ~g~Weapons");break;
	}
	normalMenuActions();
}

void TeleportMenu()
{
	addTitle("Synergy GTA");
	addSubTitle("Teleport Options");
	addOption("Teleport To Waypoint", "Takes You To Waypoint");
	addOption("Teleport to Objective", "Takes you to Your Objective");
	switch (getOption())
	{
	case 1: TPToWaypoint(); break;
	}
	normalMenuActions();
}

void VehicleModsMenu()
{
	addTitle("Synergy GTA");
	addSubTitle("Vehicle Options");
	addSubmenuOption("Vehicle Spawner", 5);
	addOption("Max Upgrades", "Max out Your Car");
	addCheckBool("Vehicle Invincibility", VehicleGod, "Makes Your Car No Boom");
	switch (getOption())
	{
	case 2: tuneUp(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID())); break;
	case 3: VehicleGod = !VehicleGod; break;
	}

	normalMenuActions();
}

void WorldOptions()
{
	addTitle("Synergy GTA");
	addSubTitle("World Options");
	addChar("Change Weather", weather, &weathers, 0, 10, "Change The Weather");
	addChar("Timecycle", timecycle, &timecy, 0, 28, "Change The Timecycle");
	addIntOption("Set Hour", &Hour, 0, 24, "Changes The Hour");
	addIntOption("Set Minute", &Minute, 0, 24, "Changes The Minute");
	addIntOption("Set Second", &Second, 0, 24, "Changes The Second");
	switch (getOption())
	{
	case 1: GAMEPLAY::SET_OVERRIDE_WEATHER(weathero[weathers]); GAMEPLAY::SET_WEATHER_TYPE_PERSIST(weathero[weathers]); GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST(weathero[weathers]); GAMEPLAY::SET_WEATHER_TYPE_NOW(weathero[weathers]); break;
	case 2: GRAPHICS::SET_TIMECYCLE_MODIFIER(timecycle[timecy]); break;
	case 3: TIME::SET_CLOCK_TIME(Hour, Minute, Second); NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(Hour, Minute, Second); break;
	case 4: TIME::SET_CLOCK_TIME(Hour, Minute, Second); NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(Hour, Minute, Second); break;
	case 5: TIME::SET_CLOCK_TIME(Hour, Minute, Second); NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(Hour, Minute, Second); break;
	}

	normalMenuActions();
}

void Settings()
{
	addTitle("Synergy GTA");
	addSubTitle("Settings");
	addSubmenuOption("Title Background Color", 8, "Title BG Color");
	addSubmenuOption("Subtitle Background Color", 11, "Sub BG Color");
	addSubmenuOption("Menu Background Color",9, "Menu Background Color");
	addSubmenuOption("Scroller Color",10, "Scroller Color Settings");
	addIntOption("Change Title Font", &bannerTextFont, 0, 7, "Edit the Title font");
	addIntOption("Change SubTitle Font", &subFont, 0, 7, "Edit the Subtitle Font");
	addIntOption("Change Option Font", &optionsFont, 0, 7, "Change The Option Font");

	normalMenuActions();
}

void TitleBGColor()
{
	addTitle("Synergy GTA");
	addSubTitle("Title Background Color");
	addIntOption("Title Background Red", &bannerRectRed, 0, 255, "Changes Top and Bottom Bar");
	addIntOption("Title Background Green", &bannerRectGreen, 0, 255, "Changes Top and Bottom Bar");
	addIntOption("Title Background Blue", &bannerRectBlue, 0, 255, "Changes Top and Bottom Bar");
	addIntOption("Title Background Visibility", &bannerRectOpacity, 0, 255, "Changes Top and Bottom Bar");

	normalMenuActions();
}
void subTitleBGColor()
{
	addTitle("Synergy GTA");
	addSubTitle("SubTitle Background Color");
	addIntOption("SubTitle Background Red", &subr, 0, 255, "Changes the Subtitle BG");
	addIntOption("SubTitle Background Green", &subg, 0, 255, "Changes the Subtitle BG");
	addIntOption("SubTitle Background Blue", &subb, 0, 255, "Changes the Subtitle BG");
	addIntOption("SubTitle Background Visibility", &suba, 0, 255, "Changes the Subtitle BG");

	normalMenuActions();
}
void menuBGColor()
{
	addTitle("Synergy GTA");
	addSubTitle("Menu Background Color");
	addIntOption("Menu Background Red", &backgroundRed, 0, 255, "Changes the menu BG");
	addIntOption("Menu Background Green", &backgroundGreen, 0, 255, "Changes the menu BG");
	addIntOption("Menu Background Blue", &backgroundBlue, 0, 255, "Changes the menu BG");
	addIntOption("Menu Background Visibility", &backgroundOpacity, 0, 255, "Changes the menu BG");

	normalMenuActions();
}
void shaderColor()
{
	addTitle("Synergy GTA");
	addSubTitle("Scroller Color");
	addIntOption("Scroller Red", &scrollerRed, 0, 255, "Changes the Scroller");
	addIntOption("Scroller Green", &scrollerGreen, 0, 255, "Changes the Scroller");
	addIntOption("Scroller Blue", &scrollerBlue, 0, 255, "Changes the Scroller");
	addIntOption("Scroller Visibility", &scrollerOpacity, 0, 255, "Changes the Scroller");

	normalMenuActions();
}


int SelectedClient;
void TeleportToClient(int Client)
{
	Vector3 Coords = ENTITY::GET_ENTITY_COORDS(Client, 1);
	if (PED::IS_PED_SITTING_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID()))
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), Coords.x, Coords.y, Coords.z, 1, 0, 0, 1);
	else
		ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), Coords.x, Coords.y, Coords.z, 1, 0, 0, 1);
}

void OnlinePlayerMods()
{
	addTitle("Synergy GTA");
	addSubTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
	addSubmenuOption("Nice Modifications", 12, "Be kind to Them");
	addOption("Teleport To Player", "Teleportation");

	switch(getOption())
	{
	case 2: TeleportToClient(PLAYER::GET_PLAYER_PED(selectedPlayer)); STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2"); GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL("scr_rcbarry2"); GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); break;
	}
	
	normalMenuActions();
}

void VehSpawner()
{
	addTitle("Synergy GTA");//addchar(array type, array, int value, min, max) max = array.size-1;
	addSubTitle("Vehicle Spawner");
	addChar("Super", g_pcSuperCars, &supercar, 0, 58, "Pick a Super Car to Spawn");
	addChar("Sport", g_pcSportsCars, &sportcar, 0, 28, "Pick a Sports Car To Spawn");
	addChar("Sport", g_pcSportsClassicCars, &sportclassic, 0, 19, "Pick a Classic Sports Car");
	addChar("Muscle", g_pcMuscleCars, &musclecar, 0, 11, "Pick a Muscle Car");
	addChar("Sedans", g_pcSedans, &sedans, 0, 22, "Pick a Sedan");
	addChar("Coupes", g_pcCoupes, &coupecar, 0, 9, "Pick a Coupe");
	addChar("Off Road", g_pcOffRoads, &offroad, 0, 18, "Pick an Off Road Vehicle");
	addChar("Emergency", g_pcEmergencyCars, &emergancy, 0, 17, "Pick an Emergency Vehicle");
	addChar("Service", g_pcServicVehicles, &service, 0, 5, "Pick a Service Vehicle");
	addChar("Military", g_pcMilitary, &military, 0, 6, "Pick a Military Vehicle");
	addChar("Motorcycles", g_pcMotorcycles, &motorcycles, 0, 20, "Pick a Motorcycle");
	addChar("Bycycles", g_pcBicycles, &bikes, 0, 6, "Get on Yer Bike");
	addChar("Helicopters", g_pcHelicopters, &helicopter, 0, 13, "Get in The Chopper!");
	addChar("Planes", g_pcPlanes, &planes, 0, 18, "Pick a Plane");
	addChar("Boats", g_pcBoats, &boats, 0, 12, "Wanna go Sailing?");
	addChar(g_VehMenu[1], g_pcSuperCars, &supercar, 0,58, "Spawn a Super Car");
	

	switch (getOption())
	{
	case 1: SpawnCar(g_uiSuperCars[supercar]); break;
	case 2: SpawnCar(g_uiSportsCars[sportcar]); break;
	case 3: SpawnCar(g_uiSportsClassicCars[sportclassic]); break;
	case 4: SpawnCar(g_uiMuscleCars[musclecar]); break;
	case 5: SpawnCar(g_uiSedans[sedans]); break;
	case 6: SpawnCar(g_uiCoupes[coupecar]); break;
	case 7: SpawnCar(g_uiOffRoads[offroad]); break;
	case 8: SpawnCar(g_uiEmergencyCars[emergancy]); break;
	case 9: SpawnCar(g_uiServicVehicles[service]); break;
	case 10: SpawnCar(g_uiMilitary[military]); break;
	case 11: SpawnCar(g_uiMotorcycles[motorcycles]); break;
	case 12: SpawnCar(g_uiBicycles[bikes]); break;
	case 13: SpawnCar(g_uiHelicopters[helicopter]); break;
	case 14: SpawnCar(g_uiPlanes[planes]); break;
	case 15: SpawnCar(g_uiBoats[boats]); break;
	}
	
	normalMenuActions();
}


void ClientNiceModifications()
{
	addTitle("Synergy GTA");
	addSubTitle("Nice Modifications");

	normalMenuActions();
}



#pragma endregion
Vector3 obje;
Vector3 fff;

DWORD64 GetModuleBase(HANDLE hProc, string &sModuleName)
{
	HMODULE *hModules;
	hModules = 0;
	char szBuf[50];
	DWORD cModules = 0;
	DWORD64 dwBase = 0;

	EnumProcessModules(hProc, hModules, 0, &cModules);
	hModules = new HMODULE[cModules / sizeof(HMODULE)];

	if (EnumProcessModules(hProc, hModules, cModules / sizeof(HMODULE), &cModules)) {
		for (int i = 0; i < cModules / sizeof(HMODULE); ++i) {
			if (GetModuleBaseName(hProc, hModules[i], szBuf, sizeof(szBuf))) {
				if (sModuleName.compare(szBuf) == 0) {
					dwBase = (DWORD64)hModules[i];
					break;
				}
			}
		}
	}
	return dwBase;
}
void otherHook()
{
	if (NoCops) { PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID()); }
	else { NoCops = false; }
	if(VehicleGod) ENTITY::SET_ENTITY_INVINCIBLE(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), true);
	else ENTITY::SET_ENTITY_INVINCIBLE(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), false);
	if (keyboardActive)
	{
		if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 1)
		{
			keyboardActive = false;
			switch (keyboardAction)
			{
			case 0: //addIntOption
				*keyboardVar = StoI(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
				break;
			}
		}
		else if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 2 || GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 3)
		{
			keyboardActive = false;
		}
	}
}
void Hook()
{
	while (true)
	{
		otherHook();
		monitorButtons();
		optionCount = 0;
		switch (submenu) 
		{
			case 1: Main(); break;
			case 2: Selfmenu(); break;
			case 3: PlayersListMenu(); break;
			case 4: OnlinePlayerMods(); break;
			case 5: VehSpawner(); break;
			case 6: VehicleModsMenu(); break;
			case 7: Settings(); break;
			case 8: TitleBGColor(); break;
			case 9: menuBGColor(); break;
			case 10: shaderColor(); break;
			case 11: subTitleBGColor(); break;
			case 12: ClientNiceModifications(); break;
			case 13: TeleportMenu(); break;
			case 14: WeaponsMenu(); break;
			case 15: WorldOptions(); break;
		}
		optionPress = false;
		WAIT(0);
	}
}



void ScriptMain()
{
	srand(GetTickCount());
	Hook();
}
