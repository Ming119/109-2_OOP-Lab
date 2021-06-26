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

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g) 
{
	intro_done = false;
	optionStage = -1;
}

void CGameStateInit::OnInit() {
	ShowInitProgress(0);

	// Loading Images
	stringHandler.LoadBitmap();
	numberHandler.LoadBitmap();

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
	menu.push_back("ABOUT");
	menu.push_back("OPTION");
	menu.push_back("EXIT");

	option.push_back("  FULLSCREEN");
	option.push_back("  STAGE SELECT");
	option.push_back("BACK");

	bin_select.push_back("YES");
	bin_select.push_back("NO");


	// stages
	stages.push_back("BULE OCEAN ZONE ACT ONE");
	stages.push_back("BULE OCEAN ZONE ACT TWO");
	stages.push_back("EXOTIC PARADISE ACT ONE");
	stages.push_back("EXOTIC PARADISE ACT TWO");
	stages.push_back("TUTORIAL ACT ONE");

	for (int i = 0; i < 4; i++)
		option_sel.push_back(1);


	if (OPEN_AS_FULLSCREEN)
		option_sel.at(static_cast<int>(OPTION::FULLSCREEN)) = 0;


	// Loading Audio
	CAudio::Instance()->Load(AUDIO_CHOOSE,	"sounds\\choose.wav");
	CAudio::Instance()->Load(AUDIO_SELECT,	"sounds\\select.wav");
	CAudio::Instance()->Load(AUDIO_RETURN,	"sounds\\return.wav");
	CAudio::Instance()->Load(AUDIO_RING,	"sounds\\ring.wav");
	CAudio::Instance()->Load(AUDIO_SPRING,	"sounds\\spring.wav");
	CAudio::Instance()->Load(AUDIO_DEAD,	"sounds\\dead.wav");

}

void CGameStateInit::OnBeginState() {
	CAudio::Instance()->Load(AUDIO_TITLE, "sounds\\title.mp3");
	CAudio::Instance()->Load(AUDIO_OPTIONS, "sounds\\options.mp3");
	CAudio::Instance()->Load(AUDIO_CRUSADER, "sounds\\crusader.mp3");

	CAudio::Instance()->Play(AUDIO_TITLE, true);
	
	CAudio::Instance()->Stop(AUDIO_OPTIONS);
	CAudio::Instance()->Stop(AUDIO_CRUSADER);


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
				CGame::Instance()->SetLevel(static_cast<int>(LEVELS::TUTORIAL_1));
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
			
		if (nChar == KEY_UP) {
			CAudio::Instance()->Play(AUDIO_CHOOSE, false);
			current_select -= 1;
		}

		if (nChar == KEY_DOWN) {
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

		break;


	// OPTION
	case static_cast<int>(MENU::OPTION) :
			
		switch (optionStage) {
		case -1:
			if (nChar == KEY_ESC) {
				CAudio::Instance()->Play(AUDIO_RETURN, false);
				CAudio::Instance()->Stop(AUDIO_OPTIONS);
				CAudio::Instance()->Play(AUDIO_TITLE, true);

				intro_done = false;
				current_select = 0;
				page = static_cast<int>(MENU::START_GAME);
			}

			if (nChar == KEY_UP) {
				CAudio::Instance()->Play(AUDIO_CHOOSE, false);
				current_select -= 1;
			}

			if (nChar == KEY_DOWN) {
				CAudio::Instance()->Play(AUDIO_CHOOSE, false);
				current_select += 1;
			}

			if (nChar == KEY_LEFT && current_select < 4) {
				CAudio::Instance()->Play(AUDIO_SELECT, false);
				option_sel.at(current_select) -= 1;
				if (option_sel.at(current_select) < 0)
					option_sel.at(current_select) = (current_select == 0) ? 2 : 1;
				else
					option_sel.at(current_select) %= (current_select == 0) ? 3 : 2;
			}

			if (nChar == KEY_RIGHT && current_select < 4) {
				CAudio::Instance()->Play(AUDIO_SELECT, false);
				option_sel.at(current_select) += 1;
				option_sel.at(current_select) %= (current_select == 0) ? 3 : 2;
			}
			
			if (nChar == KEY_ENTER || nChar == KEY_SPACE) {
				CAudio::Instance()->Play(AUDIO_SELECT, false);
				if (current_select < 1) {
					option_sel.at(current_select) += 1;
					option_sel.at(current_select) %= 2;
				} else {
					if (current_select == static_cast<int>(OPTION::STAGE_SELECT))
						optionStage = 1;

					if (current_select == static_cast<int>(OPTION::BACK)) {
						CAudio::Instance()->Stop(AUDIO_OPTIONS);
						CAudio::Instance()->Play(AUDIO_TITLE, true);
						current_select = 0;
						intro_done = false;
						page = static_cast<int>(MENU::START_GAME);
					}
				}
			}


			// 
			switch (current_select) {

			case static_cast<int>(OPTION::FULLSCREEN) :
				if (CDDraw::IsFullScreen() && option_sel.at(static_cast<int>(OPTION::FULLSCREEN)) ||
				!CDDraw::IsFullScreen() && !option_sel.at(static_cast<int>(OPTION::FULLSCREEN)))
				CDDraw::SetFullScreen(!(option_sel.at(static_cast<int>(OPTION::FULLSCREEN))));
			break;
			}

			if (current_select < 0)
				current_select = static_cast<int>(OPTION::COUNT) - 1;
			else
				current_select %= static_cast<int>(OPTION::COUNT);

			break;
			
		case 0:
			if (nChar == KEY_ESC || nChar == KEY_ENTER || nChar == KEY_SPACE) {
				CAudio::Instance()->Play(AUDIO_RETURN, false);
				optionStage = -1;
			}

			break;

		case 1:
			if (nChar == KEY_ESC) {
				CAudio::Instance()->Play(AUDIO_RETURN, false);
				optionStage = -1;
			}

			if (nChar == KEY_UP) {
				CAudio::Instance()->Play(AUDIO_CHOOSE, false);
				stageSelect--;
				if (stageSelect < 0) stageSelect = static_cast<int>(LEVELS::COUNT) - 1;
			}
			
			if (nChar == KEY_DOWN) {
				CAudio::Instance()->Play(AUDIO_CHOOSE, false);
				stageSelect++;
				stageSelect %= static_cast<int>(LEVELS::COUNT);
			}
			
			if (nChar == KEY_ENTER || nChar == KEY_SPACE) {
				CAudio::Instance()->Play(AUDIO_SELECT, false);
				CGame::Instance()->SetLevel(stageSelect);
				optionStage = -1;
				GotoGameState(GAME_STATE_RUN);
			}
			
			break;

		case 2:
			if (nChar == KEY_ESC || nChar == KEY_ENTER || nChar == KEY_SPACE) {
				CAudio::Instance()->Play(AUDIO_RETURN, false);
				optionStage = -1;
			}

			break;

		default: break;
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
		case static_cast<int>(MENU::START_GAME) :
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

			stringHandler.SetFocus(true);
			stringHandler.SetTopLeft(SIZE_X/2 - (2*DEFAULT_SCALE*stringHandler.GetAlphabet()->Width()), 5 * SIZE_Y /100);
			stringHandler.ShowBitmap("ABOUT");
			stringHandler.SetFocus(false);


			numberHandler.SetTopLeft(9 * SIZE_X / 100, 10 * SIZE_Y / 100);
			numberHandler.SetInteger(2020);
			numberHandler.ShowBitmap();
			stringHandler.SetTopLeft(30 * SIZE_X / 100, 11 * SIZE_Y / 100);
			stringHandler.ShowBitmap("SPRING CSIE NTUT");

			stringHandler.SetFocus(true);
			stringHandler.SetTopLeft(5 * SIZE_X / 100, 25 * SIZE_Y/100);
			stringHandler.ShowBitmap("DEVELOPER");
			stringHandler.SetTopLeft(15 * SIZE_X / 100, 30 * SIZE_Y / 100);
			stringHandler.SetFocus(false);
			stringHandler.ShowBitmap("MING HSUAN HUANG");
			stringHandler.SetTopLeft(15 * SIZE_X / 100, 35 * SIZE_Y / 100);
			stringHandler.ShowBitmap("HO MING LI");

			stringHandler.SetFocus(true);
			stringHandler.SetTopLeft(5 * SIZE_X / 100, 45 * SIZE_Y / 100);
			stringHandler.ShowBitmap("INSTRUCTOR");
			stringHandler.SetFocus(false);
			stringHandler.SetTopLeft(15 * SIZE_X / 100, 50 * SIZE_Y / 100);
			stringHandler.ShowBitmap("PROF SHUO HAN CHEN");

			stringHandler.SetFocus(true);
			stringHandler.SetTopLeft(5 * SIZE_X / 100, 60 * SIZE_Y / 100);
			stringHandler.ShowBitmap("FRAMEWORK BY");
			stringHandler.SetFocus(false);
			stringHandler.SetTopLeft(15 * SIZE_X / 100, 65 * SIZE_Y / 100);
			stringHandler.ShowBitmap("PROF WOEI KAE CHEN");

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
			switch (optionStage) {
			case -1:
				stringHandler.SetFocus(false);
				stringHandler.SetTopLeft(SIZE_X * 7 / 100, SIZE_Y * 19 / 100);
				stringHandler.ShowBitmap("GRAPHICS");
				stringHandler.SetTopLeft(SIZE_X * 7 / 100, SIZE_Y * 35 / 100);
				stringHandler.ShowBitmap("GAME");

				for (int i = 0; i < static_cast<int>(OPTION::COUNT); i++) {
					const int size = bin_select.size();
					switch (i) {
					case 0:
						stringHandler.SetTopLeft(SIZE_X * 7 / 100, SIZE_Y * (27 + 8 * i) / 100);
						stringHandler.SetFocus(i == current_select);
						stringHandler.ShowBitmap(option.at(i));
						for (int j = 0; j < size; j++) {
							stringHandler.SetTopLeft(SIZE_X * (50 + 15 * j) / 100, SIZE_Y * (27 + 8 * i) / 100);
							stringHandler.SetFocus(j == option_sel.at(i));
							stringHandler.ShowBitmap(bin_select.at(j));
						}

						break;
					case 1:
						stringHandler.SetTopLeft(SIZE_X * 7 / 100, SIZE_Y * (37 + 8 * i) / 100);
						stringHandler.SetFocus(i == current_select);
						stringHandler.ShowBitmap(option.at(i));
						break;
					case 2:
						stringHandler.SetTopLeft(SIZE_X * 5 / 100, SIZE_Y * 90/ 100);
						stringHandler.SetFocus(i == current_select);
						stringHandler.ShowBitmap(option.at(i));
						break;

					}
				}
				
				break;

			case 1:
				stringHandler.SetFocus(false);
				for (int i = 0; i < static_cast<int>(LEVELS::COUNT); i++) {
					stringHandler.SetFocus(i == stageSelect);
					stringHandler.SetTopLeft(25, 50 + SIZE_Y * (8 * i) / 100);
					stringHandler.ShowBitmap(stages.at(i));
				}

				break;

			default: break;
			}
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
	level->clean();
	delete level;
}

void CGameStateRun::OnInit() {
	stringHandler.LoadBitmap();
	
	Score.LoadBitmap(GUI_SCORE);
	Time.LoadBitmap(GUI_TIME);
	Rings.LoadBitmap(GUI_RING);

	colon.LoadBitmap(T_TIME_COLON);
	score.LoadBitmap();
	t_min.LoadBitmap();
	t_sec.LoadBitmap();
	rings.LoadBitmap();

	current_actor = 0;
	game_time = 0;
	score.SetInteger(0);
	t_min.SetInteger(0);
	t_sec.SetInteger(0);
	rings.SetInteger(0);
	debugMODE = false;
	level = nullptr;

}

void CGameStateRun::OnBeginState() 
{
	current_level = CGame::Instance()->GetLevel();

	game_time = 0;
	t_min.SetInteger(0);
	t_sec.SetInteger(0);
	rings.SetInteger(0);

	level = new Level(current_level);
	level->OnInit(current_level);
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_ESC   = 0x1B; // keyboard ESC
	const char KEY_LEFT  = 0x25; // keyboard左箭頭
	const char KEY_UP    = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN  = 0x28; // keyboard下箭頭
	const char KEY_SPACE = 0x20; // keyboard SPACE
	const char KEY_Z     = 0x5A; // keyboard z
	const char KEY_Q     = 0x51;
	
	if (nChar == KEY_Q) {
		debugMODE = !debugMODE;
		level->SetDebug(debugMODE);
	}

	/*
	if (nChar == KEY_Z) {
		++current_actor %= 3;
		level->SetCurrentActor(current_actor);
	}
	*/

	if (nChar == KEY_LEFT) 
		level->CurrentActor()->SetMoveLeft(true);
	
	if (nChar == KEY_RIGHT) 
		level->CurrentActor()->SetMoveRight(true);
	
	if (nChar == KEY_UP) 
		level->CurrentActor()->SetIsLookingUp(true);

	if (nChar == KEY_DOWN) 
		level->CurrentActor()->SetIsLookingDown(true);

	if (!debugMODE && nChar == KEY_SPACE) 
		level->CurrentActor()->SetIsJumping(true);

	if (debugMODE && nChar == KEY_UP)
		level->CurrentActor()->SetMoveUp(true);

	if (debugMODE && nChar == KEY_DOWN)
		level->CurrentActor()->SetMoveDown(true);

	if (nChar == KEY_ESC) {
		CAudio::Instance()->Play(AUDIO_RETURN, false);
		CGameState::GotoGameState(GAME_STATE_INIT);
		level->clean();
	}
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT = 0x25; // keyboard左箭頭
	const char KEY_UP = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN = 0x28; // keyboard下箭頭
	const char KEY_SPACE = 0x20; // keyboard SPACE

	if (nChar == KEY_LEFT)
		level->CurrentActor()->SetMoveLeft(false);

	if (nChar == KEY_RIGHT)
		level->CurrentActor()->SetMoveRight(false);

	if (nChar == KEY_UP)
		level->CurrentActor()->SetIsLookingUp(false);

	if (nChar == KEY_DOWN)
		level->CurrentActor()->SetIsLookingDown(false);

	if (!debugMODE && nChar == KEY_SPACE)
		level->CurrentActor()->SetIsJumping(false);

	if (debugMODE && nChar == KEY_DOWN)
		level->CurrentActor()->SetMoveDown(false);

	if (debugMODE && nChar == KEY_UP)
		level->CurrentActor()->SetMoveUp(false);
}

void CGameStateRun::OnMove()
{	
	if (CGame::Instance()->GetFinish() || CGame::Instance()->GetDead())
		GotoGameState(GAME_STATE_OVER);

	level->OnMove();

	game_time++;
	int t_time = game_time / GAME_CYCLE_TIME;
	int mins = t_time / 60;
	int sec = t_time % 60;

	t_min.SetInteger(mins);
	t_sec.SetInteger(sec);
	score.SetInteger(level->getScore());
	rings.SetInteger(level->getRings());
}

void CGameStateRun::OnShow() {
	level->OnShow();

	Score.SetTopLeft(32, 20);
	score.SetTopLeft(64, 20);
	Time.SetTopLeft(32, 50);
	t_min.SetTopLeft(50, 50);
	colon.SetTopLeft(137, 56);
	t_sec.SetTopLeft(72, 50);
	Rings.SetTopLeft(32, 80);
	rings.SetTopLeft(64, 80);

	Score.ShowBitmap();
	Time.ShowBitmap();
	Rings.ShowBitmap();
	colon.ShowBitmap();
	score.ShowBitmap();
	t_min.ShowBitmap();
	t_sec.ShowBitmap();
	rings.ShowBitmap();
}



/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame* g) : CGameState(g) {
}

void CGameStateOver::OnInit() {
	stringHandler.LoadBitmap();
	bg.LoadBitmap(BG);
	CAudio::Instance()->Stop(AUDIO_CRUSADER);
}

void CGameStateOver::OnBeginState() {
	counter = 30 * 3;
}

void CGameStateOver::OnMove() {
	if ((--counter) < 0) {
		GotoGameState(GAME_STATE_INIT);
		CGame::Instance()->SetDead(false);
		CGame::Instance()->SetFinish(false);
	}
}

void CGameStateOver::OnShow() {
	bg.SetTopLeft(0, 0);
	bg.ShowBitmap();
	stringHandler.SetFocus(true);
	
	
	if (CGame::Instance()->GetDead()) {
		stringHandler.SetTopLeft(SIZE_X / 2 - 4 * DEFAULT_SCALE * (stringHandler.GetAlphabet()->Width()), SIZE_Y / 2 - stringHandler.GetAlphabet()->Height());
		stringHandler.ShowBitmap("YOU DEAD");
	}
	
	if (CGame::Instance()->GetFinish()) {
		stringHandler.SetTopLeft(SIZE_X / 2 -  4 * DEFAULT_SCALE * (stringHandler.GetAlphabet()->Width()), SIZE_Y / 2 - stringHandler.GetAlphabet()->Height());
		stringHandler.ShowBitmap("YOU WIN");
	}
}

}