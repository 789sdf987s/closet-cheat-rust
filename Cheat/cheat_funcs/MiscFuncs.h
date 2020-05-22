bool jump = false;
bool air = false;
bool war = false;
bool once = false;
void Misc(UINT64 TodCycle)
{
	if (AlwaysDay) {
		safe_write(TodCycle + 0x10, 12.00f, float);
	}

	//if (Vars::Misc::Sped)
	//	LocalPlayer.BasePlayer->Sped();

	if (SpiderMan)
		LocalPlayer.BasePlayer->SpiderMan();




	//if (FakeAdmin)
		LocalPlayer.BasePlayer->FakeAdmin(4);



	/*if (Vars::Misc::WalkOnWater) {
		if (GetAsyncKeyState(VK_MBUTTON)) {
			LocalPlayer.BasePlayer->WalkWater();

			jump = true;
		}
		else if (jump) {
			LocalPlayer.BasePlayer->WalkWater();
			jump = false;
		}
	}*/


















}
