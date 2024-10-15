Chapter181TruckStuckInterior_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Chapter181TruckStuckInterior_OnLoad
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Chapter181TruckStuckInterior_OnWarp
	map_script MAP_SCRIPT_ON_RESUME, Chapter181TruckStuckInterior_OnResume
	.byte 0

Chapter181TruckStuckInterior_OnLoad:
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	end

Chapter181TruckStuckInterior_OnWarp:
    map_script_2 VAR_CHAPTER181_CUTSCENE_STATE, 2, Chapter181TruckStuckInterior_EventScript_TestExecuteTruckSequence
    .2byte 0

Chapter181TruckStuckInterior_OnResume:
	setstepcallback STEP_CB_TRUCK
	end

Chapter181TruckStuckInterior_EventScript_TestExecuteTruckSequence::
    setwarp MAP_CHAPTER181TRUCK_STUCK_EXTERIOR, 13, 8
    callnative ExecuteTruckSequence
    end

Chapter181TruckStuckInterior_EventScript_TestEndTruckSequence::
    callnative EndTruckSequence
    end
