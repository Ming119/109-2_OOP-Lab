//#include "Brick.h"
#include "Level.h"
//#include "Actor.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	enum AUDIO_ID {				// 定義各種音效的編號
		AUDIO_1UP,					// 0
		AUDIO_ACIDSHIELD,			// 1
		AUDIO_BIGRING,				// 2
		AUDIO_BIGSHOT,				// 3
		AUDIO_BOSS,					// 4
		AUDIO_BOSSHIT,				// 5
		AUDIO_BRAKE,				// 6
		AUDIO_BUMPER,				// 7
		AUDIO_CASH,					// 8
		AUDIO_CHECKPOINT,			// 9
		AUDIO_CHOOSE,				// 10
		AUDIO_CRUSADER,				// 11
		AUDIO_DEATH,				// 12
		AUDIO_DENY,					// 13
		AUDIO_DESTROYPOP,			// 14
		AUDIO_DOOR1,				// 15
		AUDIO_DOOR2,				// 16 
		AUDIO_ENDSIGN,				// 17
		AUDIO_FIRE,					// 18
		AUDIO_FIRE2,				// 19
		AUDIO_FIRESHIELD,			// 20
		AUDIO_FLOORFALL,			// 21
		AUDIO_GLASSES,				// 22
		AUDIO_GOAL,					// 23
		AUDIO_INVINCIBLE,			// 24
		AUDIO_JUMP,					// 25
		AUDIO_LUMINOUS_VEIN,		// 26
		AUDIO_OPTIONS,				// 27
		AUDIO_PUFF,					// 28
		AUDIO_RETURN,				// 29
		AUDIO_RING,					// 30
		AUDIO_RINGCOUNT,			// 31
		AUDIO_RINGLESS,				// 32
		AUDIO_SCRATCH,				// 33
		AUDIO_SELECT,				// 34
		AUDIO_SHIELD,				// 35
		AUDIO_SHOT,					// 36
		AUDIO_SPEED,				// 37
		AUDIO_SPIKES,				// 38
		AUDIO_SPIKES_APPEARING,		// 39
		AUDIO_SPIKES_DISAPPEARING,	// 40
		AUDIO_SPIN,					// 41
		AUDIO_SPINDASH1,			// 42
		AUDIO_SPINDASH2,			// 43
		AUDIO_SPRING,				// 44
		AUDIO_SWITCH,				// 45
		AUDIO_TELEPORTER,			// 46
		AUDIO_TITLE,				// 47

		// Test
		AUDIO_DING,
		AUDIO_LAKE,
		AUDIO_NTUT
	};

	enum class MENU {
		START_GAME,
		TUTORIAL,
		EXTRAS,
		OPTION,
		EXIT,
		COUNT
	};

	enum class EXTRAS {
		COUNT
	};

	enum class OPTION {
		RESOLUTION,
		FULLSCREEN,
		SMOOTH_GFX,
		SHOW_FPS,
		CHANGE_LANGUAGE,
		STAGE_SELECT,
		CREDITS,
		BACK,
		COUNT
	};

	enum class OPTION_SELECT {
		NO,
		YES,
		TINY = 0,
		NORMAL = 1,
		MAX,
	};



	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  					// 遊戲的初值及圖形設定
		void OnBeginState();				// 設定每次重玩所需的變數
		void OnKeyDown(UINT, UINT, UINT);	// 處理鍵盤Up的動作

	protected:
		void OnMove();
		void OnShow();						// 顯示這個狀態的遊戲畫面

	private:
		int page;
		int current_select;
		int option_select;
		vector<int> option_sel;

		// Intro animate
		CAnimation	intro;
		bool		intro_done;

		// Background
		CMovingBitmap background1;
		CMovingBitmap background2;
		CMovingBitmap background3;
		CMovingBitmap background4;
		CMovingBitmap background5;

		CMovingBitmap optionBG;
		
		// Logo
		CAnimation logo;		// Logo animate
		CMovingBitmap logo1;	// 
		CMovingBitmap logo2;	// 

		// Menu
		CString stringHandler;
		vector<string> menu;
		
		// Option
		vector<string> option;
		vector<string> bin_select;
		vector<string> tri_select;
			
		// Test
		CInteger test_int = CInteger(2);
		// CInteger test_int2 = CInteger(3);
	};



	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();

		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);

	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面

	private:
		CString stringHandler;
		CMovingBitmap Score;
		CMovingBitmap Time;
		CMovingBitmap Rings;

		Level* level;
		int current_actor;
		int current_level;
	};



	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnInit();
		void OnBeginState();	// 設定每次重玩所需的變數
		
	protected:
		void OnMove();			// 移動遊戲元素
		void OnShow();			// 顯示這個狀態的遊戲畫面

	private:
		int counter;			// 倒數之計數器
	};

}