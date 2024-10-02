.set LOCALID_NORMAN, 2
.set LOCALID_WINGULL, 5
.set LOCALID_CACNEA, 1

TestingTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TestingTown_OnTransition
	.byte 0

TestingTown_OnTransition:
    setflag FLAG_HIDE_NORMAN_POKEMON
    setflag FLAG_HIDE_TEST
	end

TestingTown_EventScript_WarpTrigger::
    msgbox TestingTown_Text_WarpTrigger, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, TestingTown_Movement_WarpTrigger
    end

TestingTown_Movement_WarpTrigger:
    walk_up
    step_end

TestingTown_Text_WarpTrigger:
    .string "Hello, I cannot be activated\n"
    .string "with a warp.$"

TestingTown_EventScript_WarpToTrigger::
    msgbox TestingTown_Text_WarpToTrigger, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, TestingTown_EventScript_AcceptWarpTrigger
    msgbox TestingTown_Text_RejectWarpTrigger, MSGBOX_SIGN
    end

TestingTown_Text_WarpToTrigger:
    .string "Warp to trigger?$"

TestingTown_Text_RejectWarpTrigger:
    .string "Ok$"

TestingTown_EventScript_AcceptWarpTrigger:
    warp MAP_TESTING_TOWN, 4, 6
    end

TestingTown_EventScript_TestCameraWarp::
	lockall
    applymovement OBJ_EVENT_ID_PLAYER, TestingTown_Movement_HidePlayer
    waitmovement 0
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_TESTING_TOWN, 0
    setvar VAR_TEMP_1, 0
    warpsilent MAP_CHAPTER181NORMAN_FIGHT, 10, 10
    waitstate
	end

TestingTown_Movement_HidePlayer:
    set_invisible
    step_end

TestingTown_EventScript_AddObjectTest::
    msgbox TestingTown_Text_AddObjectTest, MSGBOX_SIGN
    addobject 8
    end

TestingTown_Text_AddObjectTest:
    .string "There is an object with an\n"
    .string "event flag below me.\l"
    .string "I will add that object to the map.$"

TestingTown_EventScript_RemoveObjectTest::
    msgbox TestingTown_Text_RemoveObjectTest, MSGBOX_DEFAULT
    closemessage
    removeobject 8
    end

TestingTown_Text_RemoveObjectTest:
    .string "I will remove myself now.$"

TestingTown_EventScript_EventFlagTest::
    msgbox TestingTown_Text_EventFlagTest, MSGBOX_SIGN
    clearflag FLAG_HIDE_TEST
    end

TestingTown_Text_EventFlagTest:
    .string "There is an object with an\n"
    .string "event flag below me.\l"
    .string "I will clear the flag now.$"

TestingTown_EventScript_EventFlagObject::
    msgbox TestingTown_Text_EventFlagObject, MSGBOX_DEFAULT
    setflag FLAG_HIDE_TEST
    closemessage
    end

TestingTown_Text_EventFlagObject:
    .string "I have an event flag.\n"
    .string "I will readd the flag now.$"

TestingTown_EventScript_NormanBeatPokemon::
    clearflag FLAG_HIDE_NORMAN_POKEMON    
	addobject LOCALID_WINGULL
	addobject LOCALID_CACNEA
    lockall
    applymovement LOCALID_NORMAN, TestingTown_Movement_NormanBeatWingull
    waitmovement 0
    removeobject LOCALID_WINGULL
    applymovement LOCALID_NORMAN, TestingTown_Movement_NormanBeatCacnea
    waitmovement 0
    removeobject LOCALID_CACNEA
    setflag FLAG_HIDE_NORMAN_POKEMON
    delay 16
    releaseall
    end

TestingTown_Movement_NormanBeatWingull:
    walk_down
    delay_16
    step_end

TestingTown_Movement_NormanBeatCacnea:
    walk_left
    walk_left
    face_down
    delay_16
    walk_up
    walk_right
    walk_right
    face_down
    step_end

TestingTown_EventScript_CameraManMoveCamera::
	lockall
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, TestingTown_Movement_MapTour
	waitmovement 0
	special RemoveCameraObject
	delay 60
	releaseall
	end

TestingTown_Movement_MapTour:
	walk_slow_diag_northwest
	walk_slow_diag_northwest
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
	walk_left
	walk_left
	walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
	step_end

TestingTown_EventScript_WarpToTestingFields::
    warp MAP_TESTING_FIELDS, 13, 4
	waitstate
	release
	end

TestingTown_EventScript_HiddenItem::
	msgbox TestingTown_Text_HiddenItem, MSGBOX_DEFAULT
	end

TestingTown_Text_HiddenItem:
    .string "There is a Rare Candy below me.\n"
    .string "It uses a TEMP FLAG$"

TestingTown_EventScript_Nurse::
	lock
	faceplayer
	msgbox TestingTown_Nurse_Text_Heal, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TestingTown_EventScript_NurseHeal
	msgbox TestingTown_Nurse_RejectHeal, MSGBOX_DEFAULT
    release
	end

TestingTown_EventScript_NurseHeal:
	msgbox TestingTown_Nurse_Healing, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox TestingTown_Nurse_FinishHealing, MSGBOX_DEFAULT
    release
	end

TestingTown_Nurse_Text_Heal:
    .string "Would you like to be healed?$"

TestingTown_Nurse_Healing:
    .string "Ok, I'll heal your Pokemon.$"

TestingTown_Nurse_FinishHealing:
    .string "All done!\n"
    .string "Your Pokemon are back to full health!$"

TestingTown_Nurse_RejectHeal:
    .string "Ok, come talk to me if you need healing.$"

TestingTown_EventScript_TownSign::
	msgbox TestingTown_Text_TownSign, MSGBOX_SIGN
	end

TestingTown_Text_TownSign:
	.string "Testing Town\n"
	.string "“A town that can be shaded any hue.”$"

TestingTown_EventScript_FlaggingSign::
	goto_if_set FLAG_FLAGGED_BY_TEST_SIGN, TestingTown_EventScript_Flagged
	msgbox TestingTown_Text_Flagged_4, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_ne TestingTown_EventScript_RejectFlag
    setflag FLAG_FLAGGED_BY_TEST_SIGN
    msgbox TestingTwon_Text_Flagged_6
	end

TestingTown_EventScript_Flagged:
    msgbox TestingTown_Text_Flagged_1, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq TestingTown_EventScript_RemoveFlag
    msgbox TestingTown_Text_Flagged_3
    end

TestingTown_EventScript_RemoveFlag:
    clearflag FLAG_FLAGGED_BY_TEST_SIGN
    msgbox TestingTown_Text_Flagged_2, MSGBOX_SIGN
    end

TestingTown_EventScript_RejectFlag:
    msgbox TestingTown_Text_Flagged_5
    end

TestingTown_Text_Flagged_1:
    .string "You are flagged, remove flag?$"

TestingTown_Text_Flagged_2:
    .string "Flag removed.$"

TestingTown_Text_Flagged_3:
    .string "Ok, you are still flagged.$"

TestingTown_Text_Flagged_4:
    .string "You are not flagged, add flag?$"

TestingTown_Text_Flagged_5:
    .string "Ok, no flag added.$"

TestingTwon_Text_Flagged_6:
    .string "Flag added.$"
