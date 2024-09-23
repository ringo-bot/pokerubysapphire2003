TestingTown_MapScripts::
	.byte 0

TestingTown_EventScript_TownSign::
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
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
    msgbox TestingTown_Text_Flagged_2
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
