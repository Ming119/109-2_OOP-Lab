#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include "Item.h"
#include <iostream>
#include <time.h>
#include <ctime>

using namespace std;

namespace game_framework {

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g) {
	intro_done = false;
	onStageSelect = false;
}

void CGameStateInit::OnInit() {

	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//   等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(0);	// 一開始的loading進度為0%

	//
	// 開始載入資料
	//
	// Loading Images

	stringHandler.LoadBitmap();

	// Intro
	intro.AddBitmap(INTRO_1);
	intro.AddBitmap(INTRO_1);
	intro.AddBitmap(INTRO_1);
	intro.AddBitmap(INTRO_2);
	intro.AddBitmap(INTRO_3);
	intro.AddBitmap(INTRO_4);
	intro.AddBitmap(INTRO_4);
	intro.SetDelayCount(3);


	// Background
	background1.LoadBitmap(BG_OPENING_1);
	background2.LoadBitmap(BG_OPENING_2);
	background3.LoadBitmap(BG_OPENING_3);
	background4.LoadBitmap(BG_OPENING_4);
	background5.LoadBitmap(BG_OPENING_5);

	optionBG.LoadBitmap(BG_OPTION);


	// Logo
	logo1.LoadBitmap(LOGO_1);
	logo2.LoadBitmap(LOGO_2);

	logo.AddBitmap(LOGO_CHARACTER_1);
	logo.AddBitmap(LOGO_CHARACTER_2);
	logo.AddBitmap(LOGO_CHARACTER_3);
	logo.AddBitmap(LOGO_CHARACTER_4);
	logo.AddBitmap(LOGO_CHARACTER_3);
	logo.AddBitmap(LOGO_CHARACTER_2);
	logo.SetDelayCount(3);


	// Menu
	menu.push_back("START GAME");
	menu.push_back("TUTORIAL");
	menu.push_back("EXTRAS");
	menu.push_back("OPTION");
	menu.push_back("EXIT");

	option.push_back("  RESOLUTION");
	option.push_back("  FULLSCREEN");
	option.push_back("  SMOOTH GFX");
	option.push_back("  SHOW FPS");
	option.push_back("  CHANGE LANGUAGE");
	option.push_back("  STAGE SELECT");
	option.push_back("  CREDITS");
	option.push_back("BACK");

	bin_select.push_back("YES");
	bin_select.push_back("NO");
	tri_select.push_back("TINY");
	tri_select.push_back("NORMAL");
	tri_select.push_back("  MAX");


	// stages
	stages.push_back("BULE OCEAN ZONE ACT ONE");
	stages.push_back("BULE OCEAN ZONE ACT TWO");
	stages.push_back("BULE OCENA ZONE ACT THREE");
	stages.push_back("CHILPOCTLI TEMPLE ZONE ACT ONE");
	stages.push_back("EXOTIC HELL ACT ONE");
	stages.push_back("EXOTIC PARADISE ACT ONE");
	stages.push_back("EXOTIC PARADISE ACT TWO");
	stages.push_back("EXOTIC PARADISE ACT THREE");
	stages.push_back("PROTOTYPE ACT ONE");
	stages.push_back("SUPER BOSS ACT ONE");
	stages.push_back("SUPER BOSS ACT TWO");
	stages.push_back("TEMPLATE ACT ONE");
	stages.push_back("TEST ZONE ACT ONE");
	stages.push_back("TUTORIAL ACT ONE");
	stages.push_back("TUTORIAL ACT TWO");

	for (int i = 0; i < 4; i++) {
		option_sel.push_back(1);
	}
	if (OPEN_AS_FULLSCREEN) {
		option_sel.at(static_cast<int>(OPTION::FULLSCREEN)) = 0;
	}


	// Loading Audio
	CAudio::Instance()->Load(AUDIO_CHOOSE, "sounds\\choose.wav");
	CAudio::Instance()->Load(AUDIO_SELECT, "sounds\\select.wav");
	CAudio::Instance()->Load(AUDIO_RETURN, "sounds\\return.wav");
	CAudio::Instance()->Load(AUDIO_RING, "sounds\\ring.wav");
	CAudio::Instance()->Load(AUDIO_SPRING, "sounds\\spring.wav");
	

	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//
}

void CGameStateInit::OnBeginState() {
	CAudio::Instance()->Load(AUDIO_TITLE, "sounds\\title.mp3");
	CAudio::Instance()->Load(AUDIO_OPTIONS, "sounds\\options.mp3");
	CAudio::Instance()->Load(AUDIO_CRUSADER, "sounds\\crusader.mp3");
	CAudio::Instance()->Play(AUDIO_TITLE, true);
	
	CAudio::Instance()->Stop(AUDIO_OPTIONS);


	page = static_cast<int>(MENU::START_GAME);
	current_select = 0;
	option_select = 0;
	stageSelect = 0;
}

void CGameStateInit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {

	const char KEY_ENTER	= 0x0D;	// keyboard ENTER
	const char KEY_ESC		= 0x1B;	// keyboard ESC
	const char KEY_SPACE	= 0x20; // keyboard SPACE
	const char KEY_LEFT		= 0x25; // keyboard左箭頭
	const char KEY_UP		= 0x26; // keyboard上箭頭
	const char KEY_RIGHT	= 0x27; // keyboard右箭頭
	const char KEY_DOWN		= 0x28; // keyboard下箭頭
	
	switch (page) {

		// START GAME
		case static_cast<int>(MENU::START_GAME) :
			if (nChar == KEY_ENTER || nChar == KEY_SPACE) {
				CAudio::Instance()->Play(AUDIO_SELECT, false);

				switch (current_select) {
					case static_cast<int>(MENU::START_GAME) :
						CGame::Instance()->SetLevel(0);
						GotoGameState(GAME_STATE_RUN);
						break;

						case static_cast<int>(MENU::TUTORIAL) :
							CGame::Instance()->SetLevel(13);
							GotoGameState(GAME_STATE_RUN);
							break;

							case static_cast<int>(MENU::EXTRAS) :
								page = static_cast<int>(MENU::EXTRAS);
								break;

								case static_cast<int>(MENU::OPTION) :
									CAudio::Instance()->Stop(AUDIO_TITLE);
									CAudio::Instance()->Play(AUDIO_OPTIONS, true);
									current_select = 0;
									page = static_cast<int>(MENU::OPTION);
									break;

									case static_cast<int>(MENU::EXIT) :
										Sleep(500);
										PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);
										break;
				}

			}
			else if (nChar == KEY_UP) {
				CAudio::Instance()->Play(AUDIO_CHOOSE, false);
				current_select -= 1;

			}
			else if (nChar == KEY_DOWN) {
				CAudio::Instance()->Play(AUDIO_CHOOSE, false);
				current_select += 1;
			}

		if (current_select < 0)
			current_select = static_cast<int>(MENU::COUNT) - 1;
		else
			current_select %= static_cast<int>(MENU::COUNT);

		break;


		// EXTRAS
		case static_cast<int>(MENU::EXTRAS) :
			if (nChar == KEY_ESC) {
				CAudio::Instance()->Play(AUDIO_RETURN, false);
				page = static_cast<int>(MENU::START_GAME);

			}
			else {

			}
		break;


		// OPTION
		case static_cast<int>(MENU::OPTION) :
			if (!onStageSelect) {
				if (nChar == KEY_ESC) {
					CAudio::Instance()->Play(AUDIO_RETURN, false);
					CAudio::Instance()->Stop(AUDIO_OPTIONS);
					CAudio::Instance()->Play(AUDIO_TITLE, true);
					intro_done = false;
					current_select = 0;
					page = static_cast<int>(MENU::START_GAME);

				}
				else if (nChar == KEY_UP) {
					CAudio::Instance()->Play(AUDIO_CHOOSE, false);
					current_select -= 1;

				}
				else if (nChar == KEY_DOWN) {
					CAudio::Instance()->Play(AUDIO_CHOOSE, false);
					current_select += 1;

				}
				else if (nChar == KEY_LEFT && current_select < 4) {
					CAudio::Instance()->Play(AUDIO_SELECT, false);
					option_sel.at(current_select) -= 1;
					if (option_sel.at(current_select) < 0)
						option_sel.at(current_select) = (current_select == 0) ? 2 : 1;
					else
						option_sel.at(current_select) %= (current_select == 0) ? 3 : 2;

				}
				else if (nChar == KEY_RIGHT && current_select < 4) {
					CAudio::Instance()->Play(AUDIO_SELECT, false);
					option_sel.at(current_select) += 1;
					option_sel.at(current_select) %= (current_select == 0) ? 3 : 2;

				}
				else if (nChar == KEY_ENTER || nChar == KEY_SPACE) {
					CAudio::Instance()->Play(AUDIO_SELECT, false);
					if (current_select < 4) {
						option_sel.at(current_select) += 1;
						option_sel.at(current_select) %= (current_select == 0) ? 3 : 2;
					}
					else if (current_select == static_cast<int>(OPTION::CHANGE_LANGUAGE)) {

					}
					else if (current_select == static_cast<int>(OPTION::STAGE_SELECT)) {
						onStageSelect = true;
					}
					else if (current_select == static_cast<int>(OPTION::CREDITS)) {

					}
					else if (current_select == static_cast<int>(OPTION::BACK)) {
						CAudio::Instance()->Stop(AUDIO_OPTIONS);
						CAudio::Instance()->Play(AUDIO_TITLE, true);
						current_select = 0;
						intro_done = false;
						page = static_cast<int>(MENU::START_GAME);
					}
				}


				// 
				switch (current_select) {
					case static_cast<int>(OPTION::RESOLUTION) :
						break;

						case static_cast<int>(OPTION::FULLSCREEN) :
							if (CDDraw::IsFullScreen() && option_sel.at(static_cast<int>(OPTION::FULLSCREEN)) ||
								!CDDraw::IsFullScreen() && !option_sel.at(static_cast<int>(OPTION::FULLSCREEN)))
								CDDraw::SetFullScreen(!(option_sel.at(static_cast<int>(OPTION::FULLSCREEN))));
							break;

							case static_cast<int>(OPTION::SMOOTH_GFX) :
								break;

								case static_cast<int>(OPTION::SHOW_FPS) :
									break;

				}

				if (current_select < 0)
					current_select = static_cast<int>(OPTION::COUNT) - 1;
				else
					current_select %= static_cast<int>(OPTION::COUNT);

				break;

			}
			else {
				if (nChar == KEY_ESC) {
					CAudio::Instance()->Play(AUDIO_RETURN, false);
					onStageSelect = false;
				}
				else if (nChar == KEY_UP) {
					CAudio::Instance()->Play(AUDIO_CHOOSE, false);
					stageSelect--;
					if (stageSelect < 0) stageSelect = static_cast<int>(LEVELS::COUNT) - 1;
				}
				else if (nChar == KEY_DOWN) {
					CAudio::Instance()->Play(AUDIO_CHOOSE, false);
					stageSelect++;
					stageSelect %= static_cast<int>(LEVELS::COUNT);
				}
				else if (nChar == KEY_ENTER || nChar == KEY_SPACE) {
					CAudio::Instance()->Play(AUDIO_SELECT, false);
					CGame::Instance()->SetLevel(stageSelect);
					GotoGameState(GAME_STATE_RUN);
				}
			}
	}
	
}

void CGameStateInit::OnMove() {
	if (!intro_done) {
		// Intro animate
		intro.OnMove();
	} else {

		// Background animate
		background1.SetTopLeft(0, 0);
		background2.SetTopLeft(0, (int)(SIZE_Y / 3));
		background3.SetTopLeft(0, (int)(SIZE_Y / 3) + (int)((background2.Height() - 32) * DEFAULT_SCALE));
		background4.SetTopLeft(0, (int)(SIZE_Y / 3) + (int)((background2.Height() - 32 + background3.Height()) * DEFAULT_SCALE));
		background5.SetTopLeft(0, (int)(SIZE_Y - background3.Height() - background4.Height() * (DEFAULT_SCALE-1)));

		
		// Logo
		logo.SetTopLeft((SIZE_X - logo.Width() * DEFAULT_SCALE) / 2, SIZE_Y * 2 / 100);
		logo1.SetTopLeft((SIZE_X - logo1.Width() * DEFAULT_SCALE) / 2, SIZE_Y * 6 / 100);
		logo2.SetTopLeft((SIZE_X - logo2.Width() * DEFAULT_SCALE) / 2, SIZE_Y * 46 / 100);
		logo.OnMove();
		
	}
}

void CGameStateInit::OnShow() {

	// 1280*960
	if (!intro_done) {
		intro.SetTopLeft((SIZE_X - logo.Width() * DEFAULT_SCALE) / 2, SIZE_Y * 2 / 100);
		intro.OnShow();

		if (intro.IsFinalBitmap()) {
			intro.Reset();
			intro_done = true;
		}
	}

	if (intro_done) {

		switch (page) {
		
		// START GAME
		case static_cast<int>(MENU::START_GAME):
			// Background
			background1.ShowBitmap((double)SIZE_X / background1.Width());
			background2.ShowBitmap();
			background3.ShowBitmap();
			background4.ShowBitmap();
			background5.ShowBitmap();

			// Logo
			logo1.ShowBitmap();
			logo.OnShow();
			logo2.ShowBitmap();

			// Menu
			for (int i = 0; i < static_cast<int>(MENU::COUNT); i++) {
				stringHandler.SetTopLeft(SIZE_X * 35 / 100, SIZE_Y * (70 + 5 * i) / 100);
				stringHandler.SetFocus(i == current_select);
				stringHandler.ShowBitmap(menu.at(i));
			}

			break;

		// EXTRAS
		case static_cast<int>(MENU::EXTRAS) :
			// Background
			background1.ShowBitmap((double)SIZE_X / background1.Width());
			background2.ShowBitmap();
			background3.ShowBitmap();
			background4.ShowBitmap();
			background5.ShowBitmap();

			break;

		// OPTION
		case static_cast<int>(MENU::OPTION) :
			// Background
			for (int y = 0; y < SIZE_Y; y += (optionBG.Height() * DEFAULT_SCALE)) {
				for (int x = 0; x < SIZE_X; x += (optionBG.Width() * DEFAULT_SCALE)) {
					optionBG.SetTopLeft(x, y);
					optionBG.ShowBitmap();
				}
			}

			// Option
		if (!onStageSelect) {
			stringHandler.SetFocus(false);
			stringHandler.SetTopLeft(SIZE_X * 7 / 100, SIZE_Y * 19 / 100);
			stringHandler.ShowBitmap("GRAPHICS");
			stringHandler.SetTopLeft(SIZE_X * 7 / 100, SIZE_Y * 60 / 100);
			stringHandler.ShowBitmap("GAME");

			for (int i = 0; i < static_cast<int>(OPTION::COUNT); i++) {
				if (i < 4) {
					stringHandler.SetTopLeft(SIZE_X * 7 / 100, SIZE_Y * (27 + 8 * i) / 100);
				}
				else {
					stringHandler.SetTopLeft(SIZE_X * 7 / 100, SIZE_Y * (37 + 8 * i) / 100);
				}
				stringHandler.SetFocus(i == current_select);
				stringHandler.ShowBitmap(option.at(i));

				if (i == 0) {
					const int size = tri_select.size();
					for (int j = 0; j < size; j++) {
						stringHandler.SetTopLeft(SIZE_X * (50 + 15 * j) / 100, SIZE_Y * (27 + 8 * i) / 100);
						stringHandler.SetFocus(j == option_sel.at(i));
						stringHandler.ShowBitmap(tri_select.at(j));
					}

				}
				else if (i < 4) {
					const int size = bin_select.size();
					for (int j = 0; j < size; j++) {
						stringHandler.SetTopLeft(SIZE_X * (50 + 15 * j) / 100, SIZE_Y * (27 + 8 * i) / 100);
						stringHandler.SetFocus(j == option_sel.at(i));
						stringHandler.ShowBitmap(bin_select.at(j));
					}
				}
			}
		}
		else {
			stringHandler.SetFocus(false);
			for (int i = 0; i < 14; i++) {
				stringHandler.SetFocus(i == stageSelect);
				stringHandler.SetTopLeft(25, 25 + SIZE_Y * (7 * i) / 100);
				stringHandler.ShowBitmap(stages.at(i));
			}
		}
			break;
		}
	}
}								



/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g) {	
	current_level = CGame::Instance()->GetLevel();
}

CGameStateRun::~CGameStateRun() {
	
}

void CGameStateRun::OnInit() {
	stringHandler.LoadBitmap();
	
	current_actor = 0;

	Score.LoadBitmap(GUI_SCORE);
	Time.LoadBitmap(GUI_TIME);
	Rings.LoadBitmap(GUI_RING);
	
	struct tm {
		int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
		int tm_min;   // 分，范围从 0 到 59
		int tm_hour;  // 小时，范围从 0 到 23
	};

	/*
	time_t now = time(0);
	TRACE("Time =  %d\n", now);
	
	struct tm* localtime(const time_t* now);
	*/
	
	time_t t1, t2;
	t1 = time(NULL);
	Sleep(1234);
	t2 = time(NULL);
	TRACE("Time =  %d\n", t2 - t1);

	clock_t c1, c2;
	c1 = clock();
	Sleep(1234);
	c2 = clock();
	TRACE("Time_Clock =  %d\n", (c2 - c1) / (double)(CLOCKS_PER_SEC));

	long     i = 10000000L;
	clock_t start, finish;
	double   duration;
	/* 測量一個事件持續的時間*/
	TRACE("Time to do %ld empty loops is = ", i);
	start = clock();
	while (i--);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	TRACE("%f seconds = \n", duration);
	

	ringsCount.LoadBitmap();
	ringsCount.SetInteger(0);

}

void CGameStateRun::OnBeginState() {
	current_level = CGame::Instance()->GetLevel();
	TRACE("%d\n", current_level);
	level = new Level(current_level);
	level->OnInit(current_level);
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard左箭頭
	const char KEY_UP    = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN  = 0x28; // keyboard下箭頭
	const char KEY_SPACE = 0x20; // keyboard SPACE
	const char KEY_Z     = 0x5A; // keyboard z
	
	if (nChar == KEY_Z) {
		++current_actor %= 3;
		TRACE("current Actor: %d\n", current_actor);
		level->SetCurrentActor(current_actor);
	}

	if (nChar == KEY_LEFT) 
		level->CurrentActor()->SetMoveLeft(true);
	
	if (nChar == KEY_RIGHT) 
		level->CurrentActor()->SetMoveRight(true);
	
	if (nChar == KEY_UP) 
		level->CurrentActor()->SetIsLookingUp(true);
	
	if (nChar == KEY_DOWN) 
		level->CurrentActor()->SetIsLookingDown(true);
	
	if (nChar == KEY_SPACE) 
		level->CurrentActor()->SetIsJumping(true);

}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard左箭頭
	const char KEY_UP    = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN  = 0x28; // keyboard下箭頭
	const char KEY_SPACE = 0x20; // keyboard SPACE

	if (nChar == KEY_LEFT)
		level->CurrentActor()->SetMoveLeft(false);

	if (nChar == KEY_RIGHT)
		level->CurrentActor()->SetMoveRight(false);

	if (nChar == KEY_UP)
		level->CurrentActor()->SetIsLookingUp(false);

	if (nChar == KEY_DOWN) 
		level->CurrentActor()->SetIsLookingDown(false);

	if (nChar == KEY_SPACE) 
		level->CurrentActor()->SetIsJumping(false);

}

void CGameStateRun::OnMove() {
	int rings = level->getCountRing();
	
	level->SetMoving(level->CurrentActor()->getDelta());
	level->OnMove();

	ringsCount.SetInteger(level->getCountRing());

	Score.SetTopLeft(32, 20);
	Time.SetTopLeft(32, 50);
	Rings.SetTopLeft(32, 80);
	ringsCount.SetTopLeft(64, 80);
}

void CGameStateRun::OnShow() {
	level->OnShow();
	Score.ShowBitmap();
	Time.ShowBitmap();
	Rings.ShowBitmap();

	ringsCount.ShowBitmap();
}

void CGameStateRun::SetLevel(int level) {
	current_level = level;
}



/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame* g) : CGameState(g) {
}

void CGameStateOver::OnInit() { }

void CGameStateOver::OnBeginState() { }

void CGameStateOver::OnMove() {

}

void CGameStateOver::OnShow() {

}


}