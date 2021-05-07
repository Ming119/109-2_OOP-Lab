#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"

namespace game_framework {

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g)
: CGameState(g)
{
	intro_done = false;
}

void CGameStateInit::OnInit()
{
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

	// option.push_back("  Resolution");
	// option.push_back("  Fullscreen");
	// option.push_back("  Smooth GFX");
	// option.push_back("  Show FPS");
	// option.push_back("  Change language");
	// option.push_back("  Stage select");
	// option.push_back("  Credits");
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

	for (int i = 0; i < 4; i++) {
		option_sel.push_back(1);
	}
	if (OPEN_AS_FULLSCREEN) {
		option_sel.at(static_cast<int>(OPTION::FULLSCREEN)) = 0;
	}

	// Test
	test_int.LoadBitmap();
	test_int.SetInteger(current_select);


	// Loading Audio
	CAudio::Instance()->Load(AUDIO_CHOOSE, "sounds\\choose.wav");
	CAudio::Instance()->Load(AUDIO_SELECT, "sounds\\select.wav");
	CAudio::Instance()->Load(AUDIO_RETURN, "sounds\\return.wav");
	CAudio::Instance()->Load(AUDIO_RING, "sounds\\ring.wav");

	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//
}

void CGameStateInit::OnBeginState()
{
	CAudio::Instance()->Load(AUDIO_TITLE, "sounds\\title.mp3");
	CAudio::Instance()->Load(AUDIO_OPTIONS, "sounds\\options.mp3");
	CAudio::Instance()->Load(AUDIO_CRUSADER, "sounds\\crusader.mp3");
	CAudio::Instance()->Play(AUDIO_TITLE, true);
	
	CAudio::Instance()->Stop(AUDIO_OPTIONS);


	page = static_cast<int>(MENU::START_GAME);
	current_select = 0;
	option_select = 0;
	
}

void CGameStateInit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
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
					GotoGameState(GAME_STATE_RUN);
					break;
				
				case static_cast<int>(MENU::TUTORIAL) :
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

		} else if (nChar == KEY_UP) {
			CAudio::Instance()->Play(AUDIO_CHOOSE, false);
			current_select -= 1;

		} else if (nChar == KEY_DOWN) {
			CAudio::Instance()->Play(AUDIO_CHOOSE, false);
			current_select += 1;
		}

		if (current_select < 0) {
			current_select = static_cast<int>(MENU::COUNT)-1;
		} else {
			current_select %= static_cast<int>(MENU::COUNT);
		}
		test_int.SetInteger(current_select);
		break;


	// EXTRAS
	case static_cast<int>(MENU::EXTRAS) :
		if (nChar == KEY_ESC) {
			CAudio::Instance()->Play(AUDIO_RETURN, false);
			page = static_cast<int>(MENU::START_GAME);

		} else {

		}
		break;


	// OPTION
	case static_cast<int>(MENU::OPTION) :
		if (nChar == KEY_ESC) {
			CAudio::Instance()->Play(AUDIO_RETURN, false);
			CAudio::Instance()->Stop(AUDIO_OPTIONS);
			CAudio::Instance()->Play(AUDIO_TITLE, true);
			intro_done = false;
			current_select = 0;
			page = static_cast<int>(MENU::START_GAME);

		} else if (nChar == KEY_UP) {
			CAudio::Instance()->Play(AUDIO_CHOOSE, false);
			current_select -= 1;

		} else if (nChar == KEY_DOWN) {
			CAudio::Instance()->Play(AUDIO_CHOOSE, false);
			current_select += 1;

		} else if (nChar == KEY_LEFT && current_select < 4) {
			CAudio::Instance()->Play(AUDIO_SELECT, false);
			option_sel.at(current_select) -= 1;
			if (option_sel.at(current_select) < 0)
				option_sel.at(current_select) = (current_select == 0) ? 2 : 1;
			else
				option_sel.at(current_select) %= (current_select == 0) ? 3 : 2;

		} else if (nChar == KEY_RIGHT && current_select < 4) {
			CAudio::Instance()->Play(AUDIO_SELECT, false);
			option_sel.at(current_select) += 1;
			option_sel.at(current_select) %= (current_select == 0) ? 3 : 2;

		} else if (nChar == KEY_ENTER || nChar == KEY_SPACE) {
			CAudio::Instance()->Play(AUDIO_SELECT, false);
			if (current_select < 4) {
				option_sel.at(current_select) += 1;
				option_sel.at(current_select) %= (current_select == 0) ? 3 : 2;
			} else if (current_select == static_cast<int>(OPTION::CHANGE_LANGUAGE)){

			} else if (current_select == static_cast<int>(OPTION::STAGE_SELECT)) {

			} else if (current_select == static_cast<int>(OPTION::CREDITS)) {

			} else if (current_select == static_cast<int>(OPTION::BACK)) {
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
			current_select = static_cast<int>(OPTION::COUNT)-1;
		else 
			current_select %= static_cast<int>(OPTION::COUNT);
		
		break;

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

		/* //Some Graph BUG Need to Fix
		background1.SetTopLeft(0, 0);
		background2.SetTopLeft(background2.Left() - 8, (int)(SIZE_Y / 3));
		background3.SetTopLeft(background3.Left() - 7, (int)(SIZE_Y / 3) + (int)((background2.Height() - 32) * DEFAULT_SCALE));
		background4.SetTopLeft(background4.Left() - 5, (int)(SIZE_Y / 3) + (int)((background2.Height() - 32 + background3.Height()) * DEFAULT_SCALE));
		background5.SetTopLeft(background5.Left() - 10, (int)(SIZE_Y - background3.Height() - background4.Height() * 3));
		
		if (background2.Left() + background2.Width() * DEFAULT_SCALE / 2 < 0) {
			background2.SetTopLeft(background2.Left() + background2.Width() * DEFAULT_SCALE / 2, (int)(SIZE_Y / 3));
		}
		if (background3.Left() + background3.Width() * DEFAULT_SCALE / 2 < 0) {
			background3.SetTopLeft(background3.Left() + background2.Width() * DEFAULT_SCALE / 2, (int)(SIZE_Y / 3));
		}
		if (background4.Left() + background4.Width() * DEFAULT_SCALE / 2 < 0) {
			background4.SetTopLeft(background4.Left() + background2.Width() * DEFAULT_SCALE / 2, (int)(SIZE_Y / 3));
		}
		if (background5.Left() + background5.Width() * DEFAULT_SCALE / 2 < 0) {
			background5.SetTopLeft(background5.Left() + background2.Width() * DEFAULT_SCALE / 2, (int)(SIZE_Y / 3));
		}
		*/
		

		// Logo
		logo.SetTopLeft((SIZE_X - logo.Width() * DEFAULT_SCALE) / 2, SIZE_Y * 2 / 100);
		logo1.SetTopLeft((SIZE_X - logo1.Width() * DEFAULT_SCALE) / 2, SIZE_Y * 6 / 100);
		logo2.SetTopLeft((SIZE_X - logo2.Width() * DEFAULT_SCALE) / 2, SIZE_Y * 46 / 100);
		logo.OnMove();

		// Test
		test_int.SetTopLeft(0, 0);
		
	}
}

void CGameStateInit::OnShow()
{

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

			// Test
			test_int.ShowBitmap();

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
			stringHandler.SetFocus(false);
			stringHandler.SetTopLeft(SIZE_X * 7 / 100, SIZE_Y * 19 / 100);
			stringHandler.ShowBitmap("GRAPHICS");
			stringHandler.SetTopLeft(SIZE_X * 7 / 100, SIZE_Y * 60 / 100);
			stringHandler.ShowBitmap("GAME");

			for (int i = 0; i < static_cast<int>(OPTION::COUNT); i++) {
				if (i < 4) {
					stringHandler.SetTopLeft(SIZE_X * 7 / 100, SIZE_Y * (27 + 8 * i) / 100);
				} else {
					stringHandler.SetTopLeft(SIZE_X * 7 / 100, SIZE_Y * (37 + 8 * i) / 100);
				}
				stringHandler.SetFocus(i == current_select);
				stringHandler.ShowBitmap(option.at(i));
				
				if (i == 0) {
					const int size = tri_select.size();
					for (int j = 0; j < size; j++) {
						stringHandler.SetTopLeft(SIZE_X * (50 + 15*j) / 100, SIZE_Y * (27 + 8 * i) / 100);
						stringHandler.SetFocus(j == option_sel.at(i));
						stringHandler.ShowBitmap(tri_select.at(j));
					}

				} else if (i < 4) {
					const int size = bin_select.size();
					for (int j = 0; j < size; j++) {
						stringHandler.SetTopLeft(SIZE_X * (50 + 15*j)/ 100, SIZE_Y * (27 + 8 * i) / 100);
						stringHandler.SetFocus(j == option_sel.at(i));
						stringHandler.ShowBitmap(bin_select.at(j));
					}
				}
			}




			break;
		}
	}

	/*
	//
	// Demo螢幕字型的使用，不過開發時請盡量避免直接使用字型，改用CMovingBitmap比較好
	//
	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f,*fp;
	f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
	fp=pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	pDC->TextOut(120,220,"Please click mouse or press SPACE to begin.");
	pDC->TextOut(5,395,"Press Ctrl-F to switch in between window mode and full screen mode.");
	if (ENABLE_GAME_PAUSE)
		pDC->TextOut(5,425,"Press Ctrl-Q to pause the Game.");
	pDC->TextOut(5,455,"Press Alt-F4 or ESC to Quit.");
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	*/


}								



/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
: CGameState(g)
{	
	current_level = 0;
	// ball = new CBall [NUMBALLS];
}

CGameStateRun::~CGameStateRun()
{
	// delete [] ball;
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	stringHandler.LoadBitmap();
	
	
	/*
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
	//
	// 開始載入資料
	//
	int i;
	for (i = 0; i < NUMBALLS; i++)
		ball[i].LoadBitmap();								// 載入第i個球的圖形
	eraser.LoadBitmap();
	background.LoadBitmap(IDB_BACKGROUND);					// 載入背景的圖形
	//
	// 完成部分Loading動作，提高進度
	//
	ShowInitProgress(50);
	Sleep(300); // 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 繼續載入其他資料
	//
	help.LoadBitmap(IDB_HELP,RGB(255,255,255));				// 載入說明的圖形
	corner.LoadBitmap(IDB_CORNER);							// 載入角落圖形
	corner.ShowBitmap(background);							// 將corner貼到background
	bball.LoadBitmap();										// 載入圖形
	hits_left.LoadBitmap();
	*/
	
	// CAudio::Instance()->Load(AUDIO_DING,  "sounds\\ding.wav");	// 載入編號0的聲音ding.wav
	// CAudio::Instance()->Load(AUDIO_LAKE,  "sounds\\lake.mp3");	// 載入編號1的聲音lake.mp3
	// CAudio::Instance()->Load(AUDIO_NTUT,  "sounds\\ntut.mid");	// 載入編號2的聲音ntut.mid
	//
	// 此OnInit動作會接到CGameStaterOver::OnInit()，所以進度還沒到100%
	//
}

void CGameStateRun::OnBeginState()
{
	TRACE("%d\n", current_level);
	level = new Level();
	level->OnInit(current_level);
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT = 0x25; // keyboard左箭頭
	const char KEY_UP = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN = 0x28; // keyboard下箭頭
	const char KEY_SPACE = 0x20;

	if (nChar == KEY_LEFT)
		level->SetMoveLeft(true);
	if (nChar == KEY_RIGHT)
		level->SetMoveRight(true);
	if (nChar == KEY_UP) {
		level->CurrentActor()->SetIsLookingUp(true);
		level->SetMoveUp(true);
	}
	if (nChar == KEY_DOWN) {
		level->CurrentActor()->SetIsLookingDown(true);
		level->SetMoveDown(true);
	}
	if (nChar == KEY_SPACE) {
		level->CurrentActor()->SetIsJumping(true);

	}
		
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard左箭頭
	const char KEY_UP    = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN  = 0x28; // keyboard下箭頭
	const char KEY_SPACE = 0x20;

	if (nChar == KEY_LEFT)
		level->SetMoveLeft(false);
	if (nChar == KEY_RIGHT)
		level->SetMoveRight(false);
	if (nChar == KEY_UP) {
		level->CurrentActor()->SetIsLookingUp(false);
		level->SetMoveUp(false);
	}
	if (nChar == KEY_DOWN) {
		level->CurrentActor()->SetIsLookingDown(false);
		level->SetMoveDown(false);
	}
	if (nChar == KEY_SPACE) {
		level->CurrentActor()->SetIsJumping(false);
	}
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	

	/*
	//
	// 如果希望修改cursor的樣式，則將下面程式的commment取消即可
	//
	// SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR));
	//
	// 移動背景圖的座標
	//
	if (background.Top() > SIZE_Y)
		background.SetTopLeft(60 ,-background.Height());
	background.SetTopLeft(background.Left(),background.Top()+1);
	//
	// 移動球
	//
	int i;
	for (i=0; i < NUMBALLS; i++)
		ball[i].OnMove();
	//
	// 移動擦子
	//
	eraser.OnMove();
	//
	// 判斷擦子是否碰到球
	//
	for (i=0; i < NUMBALLS; i++)
		if (ball[i].IsAlive() && ball[i].HitEraser(&eraser)) {
			ball[i].SetIsAlive(false);
			CAudio::Instance()->Play(AUDIO_DING);
			hits_left.Add(-1);
			//
			// 若剩餘碰撞次數為0，則跳到Game Over狀態
			//
			if (hits_left.GetInteger() <= 0) {
				CAudio::Instance()->Stop(AUDIO_LAKE);	// 停止 WAVE
				CAudio::Instance()->Stop(AUDIO_NTUT);	// 停止 MIDI
				GotoGameState(GAME_STATE_OVER);
			}
		}
	//
	// 移動彈跳的球
	//
	bball.OnMove();
	*/

	level->OnMove();

}

void CGameStateRun::OnShow()
{
	/*CInteger test;
	test.LoadBitmapA();
	test.SetTopLeft(0,0);
	test.SetInteger(static_cast<int>(OPTION_SELECT::YES));
	test.ShowBitmap();
	test.SetTopLeft(20, 0);
	test.SetInteger(static_cast<int>(OPTION_SELECT::NO));
	test.ShowBitmap();
	test.SetTopLeft(40, 0);
	test.SetInteger(static_cast<int>(OPTION_SELECT::TINY));
	test.ShowBitmap();
	test.SetTopLeft(60, 0);
	test.SetInteger(static_cast<int>(OPTION_SELECT::NORMAL));
	test.ShowBitmap();
	test.SetTopLeft(80, 0);
	test.SetInteger(static_cast<int>(OPTION_SELECT::MAX));
	test.ShowBitmap();

	stringHandler.SetFocus(true);
	stringHandler.SetTopLeft(SIZE_X/2 -200, SIZE_Y/2-50);
	stringHandler.ShowBitmap("COMMING SOON");*/


	level->OnShow();

	/*
	//
	//  注意：Show裡面千萬不要移動任何物件的座標，移動座標的工作應由Move做才對，
	//        否則當視窗重新繪圖時(OnDraw)，物件就會移動，看起來會很怪。換個術語
	//        說，Move負責MVC中的Model，Show負責View，而View不應更動Model。
	//
	//
	//  貼上背景圖、撞擊數、球、擦子、彈跳的球
	//
	background.ShowBitmap();			// 貼上背景圖
	help.ShowBitmap();					// 貼上說明圖
	hits_left.ShowBitmap();
	for (int i=0; i < NUMBALLS; i++)
		ball[i].OnShow();				// 貼上第i號球
	bball.OnShow();						// 貼上彈跳的球
	eraser.OnShow();					// 貼上擦子
	//
	//  貼上左上及右下角落的圖
	//
	corner.SetTopLeft(0,0);
	corner.ShowBitmap();
	corner.SetTopLeft(SIZE_X-corner.Width(), SIZE_Y-corner.Height());
	corner.ShowBitmap();
	*/
}



/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame* g)
	: CGameState(g)
{
}

void CGameStateOver::OnInit()
{
	/*
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
	//
	// 開始載入資料
	//
	Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 最終進度為100%
	//
	ShowInitProgress(100);
	*/
}

void CGameStateOver::OnBeginState()
{
	// counter = 30 * 5; // 5 seconds
}

void CGameStateOver::OnMove()
{
	/*
	counter--;
	if (counter < 0)
		GotoGameState(GAME_STATE_INIT);
	*/
}

void CGameStateOver::OnShow()
{
	/*
	CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f, * fp;
	f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
	fp = pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 0));
	char str[80];								// Demo 數字對字串的轉換
	sprintf(str, "Game Over ! (%d)", counter / 30);
	pDC->TextOut(240, 210, str);
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	*/
}

}