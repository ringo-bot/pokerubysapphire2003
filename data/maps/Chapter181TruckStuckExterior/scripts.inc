.set LOCALID_TRUCK, 1
.set LOCALID_RALTS, 2

Chapter181TruckStuckExterior_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, Chapter181TruckStuckExterior_OnFrame
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Chapter181TruckStuckExterior_OnWarp
	.byte 0

Chapter181TruckStuckExterior_OnFrame:
    map_script_2 VAR_CHAPTER181_CUTSCENE_STATE, 3, Chapter181TruckStuckExterior_EventScript_PlayScene
    end

Chapter181TruckStuckExterior_OnWarp:
    map_script_2 VAR_CHAPTER181_CUTSCENE_STATE, 2, Chapter181TruckStuckExterior_EventScript_SetUpScene
    .2byte 0

Chapter181TruckStuckExterior_EventScript_SetUpScene::
    hideobjectat OBJ_EVENT_ID_PLAYER, MAP_CHAPTER181TRUCK_STUCK_EXTERIOR
    setvar VAR_CHAPTER181_CUTSCENE_STATE, 3
    end

Chapter181TruckStuckExterior_EventScript_PlayScene::
    applymovement LOCALID_RALTS, Chapter181TruckStuckExterior_Movement_RaltsEnterScene
	waitmovement 0
    applymovement LOCALID_TRUCK, Chapter181TruckStuckExterior_Movement_TruckUnstuck
	waitmovement 0
    warpsilent MAP_TESTING_TOWN, 1, 17
    waitstate 
    setvar VAR_CHAPTER181_CUTSCENE_STATE, 4
    return

Chapter181TruckStuckExterior_Movement_TruckUnstuck::
    walk_up
    walk_left
    walk_left
    walk_left
    walk_down
    step_end

Chapter181TruckStuckExterior_Movement_RaltsEnterScene::
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

Chapter181TruckStuckExterior_Movement_Test::
    walk_left
    walk_left
    walk_left
    step_end

