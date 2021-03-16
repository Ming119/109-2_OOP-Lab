/*
 * mygame.h: ���ɮ��x�C��������class��interface
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/

#include "CEraser.h"
#include "CBall.h"
#include "CBouncingBall.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	enum AUDIO_ID {				// �w�q�U�ح��Ī��s��
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
		AUDIO_TITLE					// 47
	};

	//
	//
	//
	class CPractice {
	public:
		CPractice();
		void LoadBitmap();
		void OnMove();
		void Onshow();
	private:
		CMovingBitmap pic;
		int x, y;
	};

	class CGameMap {
	public:
		CGameMap();
		void LoadBitmap();
		void OnShow();

		void OnMove();
		void OnKeyDown(UINT);
		void RandomBouncingBall();
		void InitializeBouncingBall(int, int, int);
		~CGameMap();

	protected:
		CMovingBitmap blue, green;
		int map[4][5];
		const int X, Y;
		const int MW, MH;

		CBouncingBall* bballs;
		int random_num;
	};
	//
	//
	//

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		// void OnBeginState();							// �]�w�C�������һݪ��ܼ�

	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap logo;								// csie��logo
	};



	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);

	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		const int		NUMBALLS;	// �y���`��
		CMovingBitmap	background;	// �I����
		CMovingBitmap	help;		// ������
		CBall			*ball;		// �y���}�C
		CMovingBitmap	corner;		// ������
		CEraser			eraser;		// ��l
		CInteger		hits_left;	// �ѤU��������
		CBouncingBall   bball;		// ���мu�����y

		CPractice		c_practice; //
		CGameMap		gamemap;	//
		// CMovingBitmap	practice;	//
		// int picX, picY;				//

	};


	/////////////////////////////////////////////////////////////////////////////
	// 
	/////////////////////////////////////////////////////////////////////////////
 
	class CGameStateLevel : public CGameState {
	public:
		CGameStateLevel(CGame* g);
		~CGameStateLevel();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		// void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);

	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��

	private:

	};



	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		int counter;	// �˼Ƥ��p�ƾ�
	};

}