TestingFields_MapScripts::
	.byte 0

TestingFields_EventScript_WarpSign3::
	msgbox TestingFields_Text_WarpSign3, MSGBOX_SIGN
	end

TestingFields_Text_WarpSign3:
	.string "Warp to Moving Truck Exterior$"

TestingFields_EventScript_WarpSign2::
	msgbox TestingFields_Text_WarpSign2, MSGBOX_SIGN
	end

TestingFields_Text_WarpSign2:
	.string "Warp to Moving Truck Interior$"

TestingFields_EventScript_WarpSign1::
	msgbox TestingFields_Text_WarpSign1, MSGBOX_SIGN
	end

TestingFields_Text_WarpSign1:
	.string "Warp to Norman Fight$"

TestingFields_EventScript_WarpToTestingTown::
    warp MAP_TESTING_TOWN, 15, 27
	waitstate
	release
	end
