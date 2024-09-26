TestingFields_MapScripts::
	.byte 0

TestingFields_EventScript_WarpToTestingTown::
    warp MAP_TESTING_TOWN, 15, 27
	waitstate
	release
	end
