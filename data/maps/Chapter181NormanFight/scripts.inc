.set LOCALID_NORMAN, 1
.set LOCALID_CACNEA, 2
.set LOCALID_WINGULL, 3
.set LOCALID_BEAUTIFLY, 4
.set LOCALID_VOLBEAT, 5
.set LOCALID_DUSKULL, 6
.set LOCALID_GABBY, 7
.set LOCALID_TY, 8
.set LOCALID_LINOONE, 9

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
    call Chapter181NormanFight_EventScript_WildPokemonMove
    call Chapter181NormanFight_EventScript_NormanSummonLinoone
    call Chapter181NormanFight_EventScript_NormanDefeatPokemon
	msgbox Chapter181NormanFight_Text_NormanSummon, MSGBOX_DEFAULT
	closemessage
	special RemoveCameraObject
    setvar VAR_CHAPTER181_CUTSCENE_STATE, 2
    warpsilent MAP_CHAPTER181TRUCK_STUCK_INTERIOR, 2, 1
    waitstate 
    return

Chapter181NormanFight_EventScript_NormanDefeatPokemon:
    lockall
    applymovement LOCALID_LINOONE, Chapter181NormanFight_Movement_DefeatCacnea
    waitmovement 0    
    removeobject LOCALID_CACNEA
    applymovement LOCALID_LINOONE, Chapter181NormanFight_Movement_DefeatDuskull
    waitmovement 0    
    removeobject LOCALID_DUSKULL
    applymovement LOCALID_LINOONE, Chapter181NormanFight_Movement_DefeatBeautifly
    waitmovement 0
    removeobject LOCALID_BEAUTIFLY
    applymovement LOCALID_LINOONE, Chapter181NormanFight_Movement_DefeatWingull
    waitmovement 0
    removeobject LOCALID_WINGULL
    applymovement LOCALID_LINOONE, Chapter181NormanFight_Movement_DefeatVolbeat
    waitmovement 0
    removeobject LOCALID_VOLBEAT
    applymovement LOCALID_LINOONE, Chapter181NormanFight_Movement_ReturnNorman
    waitmovement 0
    releaseall
    return

Chapter181NormanFight_Movement_DefeatCacnea:
    walk_fast_down
    step_end

Chapter181NormanFight_Movement_DefeatDuskull:
    walk_fast_right
    step_end

Chapter181NormanFight_Movement_DefeatBeautifly:
    walk_fast_down
    step_end

Chapter181NormanFight_Movement_DefeatWingull:
    walk_fast_down
    walk_fast_left
    walk_fast_left
    walk_fast_up
    step_end

Chapter181NormanFight_Movement_DefeatVolbeat:
    walk_fast_right
    step_end

Chapter181NormanFight_Movement_ReturnNorman:
    walk_up
    walk_up
    enter_pokeball
    step_end

Chapter181NormanFight_EventScript_WildPokemonMove:
    lockall
    applymovement LOCALID_CACNEA, Chapter181NormanFight_Movement_Cacnea
    waitmovement 0    
    applymovement LOCALID_VOLBEAT, Chapter181NormanFight_Movement_Volbeat
    waitmovement 0
    applymovement LOCALID_DUSKULL, Chapter181NormanFight_Movement_Duskull
    waitmovement 0
    applymovement LOCALID_BEAUTIFLY, Chapter181NormanFight_Movement_Beautifly
    waitmovement 0
    applymovement LOCALID_WINGULL, Chapter181NormanFight_Movement_Wingull
    waitmovement 0
    releaseall
    return

Chapter181NormanFight_Movement_Wingull:
    walk_up
    walk_up
    walk_right
    face_up
    step_end

Chapter181NormanFight_Movement_Beautifly:
    walk_up
    walk_up
    walk_left
    face_up
    step_end

Chapter181NormanFight_Movement_Duskull:
    walk_up
    walk_up
    walk_up
    step_end

Chapter181NormanFight_Movement_Volbeat:
    walk_up
    walk_up
    step_end

Chapter181NormanFight_Movement_Cacnea:
    walk_up
    walk_up
    walk_up
    walk_right
    face_up
    step_end

Chapter181NormanFight_EventScript_NormanSummonLinoone:
    lockall
	msgbox Chapter181NormanFight_Text_NormanSummon, MSGBOX_DEFAULT
	closemessage
    @applymovement LOCALID_NORMAN, Chapter181NormanFight_Movement_NormanSummonOne
    @waitmovement 0 
    addobject LOCALID_LINOONE
    applymovement LOCALID_LINOONE, Chapter181NormanFight_Movement_ExitPokeball
    waitmovement 0
    applymovement LOCALID_NORMAN, Chapter181NormanFight_Movement_NormanSummonTwo
    waitmovement 0
    releaseall
	return

Chapter181NormanFight_Movement_ExitPokeball: 
    exit_pokeball
    step_end

Chapter181NormanFight_Movement_NormanSummonOne:
    walk_slow_down
    step_end

Chapter181NormanFight_Movement_NormanSummonTwo:
    walk_up
    face_down
    step_end

Chapter181NormanFight_Text_NormanSummon:
    .string "...$"

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
