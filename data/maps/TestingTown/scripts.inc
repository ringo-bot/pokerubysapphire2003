TestingTown_MapScripts::
	.byte 0

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
