#include "CEraser.h"
#include "CBall.h"
#include "CBouncingBall.h"

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
		CMovingBitmap background;
		CMovingBitmap background1;			//
		CMovingBitmap background2;
		CMovingBitmap background3;
		CMovingBitmap background4;
		CMovingBitmap logo1;				//
		CMovingBitmap logo2;

		CAnimation logo;

		CMovingBitmap start_game;
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
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作 
		void OnRButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnRButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作

	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面

	private:
		const int		NUMBALLS;	// 球的總數
		CMovingBitmap	background;	// 背景圖
		CMovingBitmap	help;		// 說明圖
		CBall			*ball;		// 球的陣列
		CMovingBitmap	corner;		// 角落圖
		CEraser			eraser;		// 拍子
		CInteger		hits_left;	// 剩下的撞擊數
		CBouncingBall   bball;		// 反覆彈跳的球
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