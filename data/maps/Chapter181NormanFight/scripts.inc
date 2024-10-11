.set LOCALID_NORMAN, 1
.set LOCALID_CACNEA, 2
.set LOCALID_WINGULL, 3
.set LOCALID_BEAUTIFLY, 4
.set LOCALID_VOLBEAT, 5
.set LOCALID_DUSKULL, 6
.set LOCALID_GABBY, 7
.set LOCALID_TY, 8

Chapter181NormanFight_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, Chapter181NormanFight_OnFrame
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Chapter181NormanFight_OnWarp
	.byte 0

Chapter181NormanFight_OnFrame:
    map_script_2 VAR_CHAPTER181_CUTSCENE_STATE, 1, Chapter181NormanFight_EventScript_PlayScene
    end

Chapter181NormanFight_OnWarp:
    map_script_2 VAR_CHAPTER181_CUTSCENE_STATE, 0, Chapter181NormanFight_EventScript_SetUpScene
    .2byte 0

Chapter181NormanFight_EventScript_SetUpScene::
    hideobjectat OBJ_EVENT_ID_PLAYER, MAP_CHAPTER181NORMAN_FIGHT
    setvar VAR_CHAPTER181_CUTSCENE_STATE, 1
    end

Chapter181NormanFight_EventScript_PlayScene::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Chapter181NormanFight_Movement_Test
	waitmovement 0
	special RemoveCameraObject
    setvar VAR_CHAPTER181_CUTSCENE_STATE, 2
    warpsilent MAP_CHAPTER181TRUCK_STUCK_INTERIOR, 2, 1
    waitstate 
    return

Chapter181NormanFight_Movement_Test:
    walk_left
    walk_down
    walk_right
    walk_right
    walk_up
    walk_up
    walk_left
    walk_down
    step_end
