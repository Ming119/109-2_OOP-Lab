#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include "Item.h"
#include "Level.h"

namespace game_framework {
	// Item
	Item::Item(int x, int y) {
		pos.x = x;
		pos.y = y;
		angle = 0;
		cameraSpeed = 50;

		delta = POINT();

		isDead = isDeadFinish = false;
	}


	int Item::Top() {
		return texture.Top();
	}

	int Item::Left() {
		return texture.Left();
	}

	int Item::Height() {
		return texture.Height();
	}

	int Item::Width() {
		return texture.Width();
	}

	void Item::setTopLeft(int x, int y) {
		pos.x = x;
		pos.y = y;

		texture.SetTopLeft(pos.x, pos.y);
		deadAnimate.SetTopLeft(pos.x, pos.y);
	}

	void Item::setTopLeft(POINT xy) {
		pos = xy;

		texture.SetTopLeft(pos.x, pos.y);
		deadAnimate.SetTopLeft(pos.x, pos.y);
	}

	void Item::setAngle(int ang) {
		angle = ang;
	}

	void Item::SetMoving(POINT _delta) {
		delta = _delta;
	}

	void Item::SetCurrentActor(Actor* actor) {
		currnetActor = actor;
	}

	bool Item::CollisionDetection(Actor* actor) {
		if ((this->Left()) < (actor->Left() + actor->Width() * DEFAULT_SCALE) &&
			(this->Left() + this->Width() * DEFAULT_SCALE) > (actor->Left()) &&
			(this->Top()) < (actor->Top() + actor->Height() * DEFAULT_SCALE) &&
			(this->Top() + this->Height() * DEFAULT_SCALE) > (actor->Top())) {

			return true;
		}

		return false;
	}


	bool Item::IsDead() {
		return isDeadFinish;
	}

	void Item::CameraMove() {
		// Camera Move
		pos.x -= delta.x;
		pos.y -= delta.y;

		setTopLeft(pos);
	}

	// Ring
	Ring::Ring(int x, int y) : Item::Item(x, y) {}

	Ring::~Ring() {}

	void Ring::OnInit() {
		texture.AddBitmap(ITEMS_YELLOW_RING_1);
		texture.AddBitmap(ITEMS_YELLOW_RING_2);
		texture.AddBitmap(ITEMS_YELLOW_RING_3);
		texture.AddBitmap(ITEMS_YELLOW_RING_4);
		texture.AddBitmap(ITEMS_YELLOW_RING_5);
		texture.AddBitmap(ITEMS_YELLOW_RING_6);
		texture.AddBitmap(ITEMS_YELLOW_RING_7);
		texture.AddBitmap(ITEMS_YELLOW_RING_8);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_YELLOW_RING_DEAD_1);
		deadAnimate.AddBitmap(ITEM_YELLOW_RING_DEAD_2);
		deadAnimate.AddBitmap(ITEM_YELLOW_RING_DEAD_3);
		deadAnimate.AddBitmap(ITEM_YELLOW_RING_DEAD_4);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}
	
	void Ring::OnMove() {
		CameraMove();

		if (CollisionDetection(currnetActor)) {
			isDead = true;

		}

		setTopLeft(pos);
		if (isDead) {
			if (deadAnimate.IsFinalBitmap()) {
				isDeadFinish = true;
			}
			else if (deadAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_RING, false);
			}
			deadAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}

	}

	void Ring::OnShow(int scale) {
		if (isDead) {
			deadAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}
	
	// BIG_Ring
	BIG_Ring::BIG_Ring(int x, int y) : Item::Item(x, y) {}

	BIG_Ring::~BIG_Ring() {}

	void BIG_Ring::OnInit() {
		texture.AddBitmap(ITEMS_BIG_RING_1);
		texture.AddBitmap(ITEMS_BIG_RING_2);
		texture.AddBitmap(ITEMS_BIG_RING_3);
		texture.AddBitmap(ITEMS_BIG_RING_4);
		texture.AddBitmap(ITEMS_BIG_RING_5);
		texture.AddBitmap(ITEMS_BIG_RING_6);
		texture.AddBitmap(ITEMS_BIG_RING_7);
		texture.AddBitmap(ITEMS_BIG_RING_8);
		texture.AddBitmap(ITEMS_BIG_RING_9);
		texture.AddBitmap(ITEMS_BIG_RING_10);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_YELLOW_RING_DEAD_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);

	}

	void BIG_Ring::OnMove() {
		CameraMove();
		CameraMove();

		if (CollisionDetection(currnetActor)) {
			isDead = true;

		}

		setTopLeft(pos);
		if (isDead) {
			if (deadAnimate.IsFinalBitmap()) {
				isDeadFinish = true;
			}
			else if (deadAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_RING, false);
			}
			deadAnimate.OnMove();
		}
		else {
			texture.OnMove();

		}
	}

	void BIG_Ring::OnShow(int scale) {
		if (isDead) {
			deadAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}
	
	// RED_SPRING_PADS_UP
	RED_SPRING_PADS_UP::RED_SPRING_PADS_UP(int x, int y) : Item::Item(x, y) {}

	void RED_SPRING_PADS_UP::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_UP_21);
		texture.AddBitmap(ITEM_RED_SPRING_PADS_UP_21_1);
		texture.SetDelayCount(3);


		deadAnimate.AddBitmap(ITEM_RED_SPRING_PADS_UP_21_1);
		deadAnimate.SetDelayCount(3);
		setTopLeft(pos);
	}
	
	void RED_SPRING_PADS_UP::OnMove() {
		CameraMove();

	}


	void RED_SPRING_PADS_UP::OnShow(int scale) {
		if (isDead) {
			deadAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
		//texture.OnShow(scale);
	}

	
	// RED_SPRING_PADS_DOWN

	RED_SPRING_PADS_DOWN::RED_SPRING_PADS_DOWN(int x, int y) : Item::Item(x, y) {}

	RED_SPRING_PADS_DOWN::~RED_SPRING_PADS_DOWN() {}

	void RED_SPRING_PADS_DOWN::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_DOWN_47);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_RED_SPRING_PADS_DOWN_47_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_DOWN::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();


	}

	void RED_SPRING_PADS_DOWN::OnShow(int scale) {
		
		texture.OnShow(scale);
	}

	// RED_SPRING_PADS_LEFT
	RED_SPRING_PADS_LEFT::RED_SPRING_PADS_LEFT(int x, int y) : Item::Item(x, y) {}

	RED_SPRING_PADS_LEFT::~RED_SPRING_PADS_LEFT() {}

	void RED_SPRING_PADS_LEFT::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_22);
		//texture.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_22_1);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_22_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}
	
	void RED_SPRING_PADS_LEFT::OnMove() {
		CameraMove();


		setTopLeft(pos);
		texture.OnMove();
		

	}

	void RED_SPRING_PADS_LEFT::OnShow(int scale) {
	
		texture.OnShow(scale);
	
	}

	// RED_SPRING_PADS_LEFT_U

	RED_SPRING_PADS_LEFT_U::RED_SPRING_PADS_LEFT_U(int x, int y) : Item::Item(x, y) {}

	RED_SPRING_PADS_LEFT_U::~RED_SPRING_PADS_LEFT_U() {}

	void RED_SPRING_PADS_LEFT_U::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_U_43);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_U_43_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_LEFT_U::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();


	}

	void RED_SPRING_PADS_LEFT_U::OnShow(int scale) {
		
		texture.OnShow(scale);
		
	}

	// RED_SPRING_PADS_LEFT_D
	RED_SPRING_PADS_LEFT_D::RED_SPRING_PADS_LEFT_D(int x, int y) : Item::Item(x, y) {}

	RED_SPRING_PADS_LEFT_D::~RED_SPRING_PADS_LEFT_D() {}

	void RED_SPRING_PADS_LEFT_D::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_D_45);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_D_45_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_LEFT_D::OnMove() {
		CameraMove();
		setTopLeft(pos);
		
		texture.OnMove();


	}

	void RED_SPRING_PADS_LEFT_D::OnShow(int scale) {
		
		texture.OnShow(scale);
		
	}

	// RED_SPRING_PADS_RING
	RED_SPRING_PADS_RING::RED_SPRING_PADS_RING(int x, int y) : Item::Item(x, y) {}

	RED_SPRING_PADS_RING::~RED_SPRING_PADS_RING() {}

	void RED_SPRING_PADS_RING::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_RING_23);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_RED_SPRING_PADS_RING_23_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_RING::OnMove() {
		CameraMove();

		setTopLeft(pos);
		
		texture.OnMove();


	}

	void RED_SPRING_PADS_RING::OnShow(int scale) {
	
		texture.OnShow(scale);
	}

	// RED_SPRING_PADS_RING_U
	RED_SPRING_PADS_RING_U::RED_SPRING_PADS_RING_U(int x, int y) : Item::Item(x, y) {}

	RED_SPRING_PADS_RING_U::~RED_SPRING_PADS_RING_U() {}

	void RED_SPRING_PADS_RING_U::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_RING_U_44);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_RED_SPRING_PADS_RING_U_44_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_RING_U::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();


	}

	void RED_SPRING_PADS_RING_U::OnShow(int scale) {
		
		texture.OnShow(scale);
		
	}

	// RED_SPRING_PADS_RING_D
	RED_SPRING_PADS_RING_D::RED_SPRING_PADS_RING_D(int x, int y) : Item::Item(x, y) {}

	RED_SPRING_PADS_RING_D::~RED_SPRING_PADS_RING_D() {}

	void RED_SPRING_PADS_RING_D::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_RING_D_46);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_RED_SPRING_PADS_RING_D_46_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_RING_D::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();

	}

	void RED_SPRING_PADS_RING_D::OnShow(int scale) {
		
		texture.OnShow(scale);
	}

	// YELLOW_SPRING_PADS_UP
	YELLOW_SPRING_PADS_UP::YELLOW_SPRING_PADS_UP(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_UP::~YELLOW_SPRING_PADS_UP() {}

	void YELLOW_SPRING_PADS_UP::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_UP_20);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_UP_20_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_UP::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();

	}

	void YELLOW_SPRING_PADS_UP::OnShow(int scale) {
		
		texture.OnShow(scale);
	}

	// YELLOW_SPRING_PADS_DOWN
	YELLOW_SPRING_PADS_DOWN::YELLOW_SPRING_PADS_DOWN(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_DOWN::~YELLOW_SPRING_PADS_DOWN() {}

	void YELLOW_SPRING_PADS_DOWN::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_DOWN_54);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_DOWN_54_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_DOWN::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();



	}

	void YELLOW_SPRING_PADS_DOWN::OnShow(int scale) {

		texture.OnShow(scale);
	}

	// YELLOW_SPRING_PADS_LEFT
	YELLOW_SPRING_PADS_LEFT::YELLOW_SPRING_PADS_LEFT(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_LEFT::~YELLOW_SPRING_PADS_LEFT() {}

	void YELLOW_SPRING_PADS_LEFT::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_48);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_48_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_LEFT::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();

	}

	void YELLOW_SPRING_PADS_LEFT::OnShow(int scale) {
		
		texture.OnShow(scale);

	}

	// YELLOW_SPRING_PADS_LEFT_U
	YELLOW_SPRING_PADS_LEFT_U::YELLOW_SPRING_PADS_LEFT_U(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_LEFT_U::~YELLOW_SPRING_PADS_LEFT_U() {}

	void YELLOW_SPRING_PADS_LEFT_U::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_U_50);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_U_50_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_LEFT_U::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();


	}

	void YELLOW_SPRING_PADS_LEFT_U::OnShow(int scale) {
		
		texture.OnShow(scale);
		
	}

	// YELLOW_SPRING_PADS_LEFT_D
	YELLOW_SPRING_PADS_LEFT_D::YELLOW_SPRING_PADS_LEFT_D(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_LEFT_D::~YELLOW_SPRING_PADS_LEFT_D() {}

	void YELLOW_SPRING_PADS_LEFT_D::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_D_52);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_D_52_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_LEFT_D::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();

	}

	void YELLOW_SPRING_PADS_LEFT_D::OnShow(int scale) {
		
		texture.OnShow(scale);
		
	}

	// YELLOW_SPRING_PADS_RING
	YELLOW_SPRING_PADS_RING::YELLOW_SPRING_PADS_RING(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_RING::~YELLOW_SPRING_PADS_RING() {}

	void YELLOW_SPRING_PADS_RING::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_49);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_49_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_RING::OnMove() {
		CameraMove();

		setTopLeft(pos);
		
		texture.OnMove();


	}

	void YELLOW_SPRING_PADS_RING::OnShow(int scale) {
		
		texture.OnShow(scale);

	}


	// YELLOW_SPRING_PADS_RING_U
	YELLOW_SPRING_PADS_RING_U::YELLOW_SPRING_PADS_RING_U(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_RING_U::~YELLOW_SPRING_PADS_RING_U() {}

	void YELLOW_SPRING_PADS_RING_U::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_U_51);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_U_51_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_RING_U::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();


	}

	void YELLOW_SPRING_PADS_RING_U::OnShow(int scale) {
		
		texture.OnShow(scale);

	}


	// YELLOW_SPRING_PADS_RING_D
	YELLOW_SPRING_PADS_RING_D::YELLOW_SPRING_PADS_RING_D(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_RING_D::~YELLOW_SPRING_PADS_RING_D() {}

	void YELLOW_SPRING_PADS_RING_D::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_D_53);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_D_53_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_RING_D::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();


	}

	void YELLOW_SPRING_PADS_RING_D::OnShow(int scale) {

		texture.OnShow(scale);

	}


	// BULE_SPRING_PADS_UP
	BULE_SPRING_PADS_UP::BULE_SPRING_PADS_UP(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_UP::~BULE_SPRING_PADS_UP() {}

	void BULE_SPRING_PADS_UP::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_UP_55);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_UP_55_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_UP::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();

	}

	void BULE_SPRING_PADS_UP::OnShow(int scale) {
		
		texture.OnShow(scale);

	}

	// BULE_SPRING_PADS_DOWN
	BULE_SPRING_PADS_DOWN::BULE_SPRING_PADS_DOWN(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_DOWN::~BULE_SPRING_PADS_DOWN() {}

	void BULE_SPRING_PADS_DOWN::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_DOWN_62);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_DOWN_62_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_DOWN::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();

	}

	void BULE_SPRING_PADS_DOWN::OnShow(int scale) {
		
		texture.OnShow(scale);
		
	}

	// BULE_SPRING_PADS_LEFT
	BULE_SPRING_PADS_LEFT::BULE_SPRING_PADS_LEFT(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_LEFT::~BULE_SPRING_PADS_LEFT() {}

	void BULE_SPRING_PADS_LEFT::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_56);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_56_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_LEFT::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();

	}

	void BULE_SPRING_PADS_LEFT::OnShow(int scale) {
		
		texture.OnShow(scale);

	}

	// BULE_SPRING_PADS_LEFT_U
	BULE_SPRING_PADS_LEFT_U::BULE_SPRING_PADS_LEFT_U(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_LEFT_U::~BULE_SPRING_PADS_LEFT_U() {}

	void BULE_SPRING_PADS_LEFT_U::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_U_58);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_U_58_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_LEFT_U::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();

	}

	void BULE_SPRING_PADS_LEFT_U::OnShow(int scale) {
		
		texture.OnShow(scale);
		
	}

	// BULE_SPRING_PADS_LEFT_D
	BULE_SPRING_PADS_LEFT_D::BULE_SPRING_PADS_LEFT_D(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_LEFT_D::~BULE_SPRING_PADS_LEFT_D() {}

	void BULE_SPRING_PADS_LEFT_D::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_D_60);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_D_60_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_LEFT_D::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();

	}

	void BULE_SPRING_PADS_LEFT_D::OnShow(int scale) {
		
		texture.OnShow(scale);
		
	}

	// BULE_SPRING_PADS_RING
	BULE_SPRING_PADS_RING::BULE_SPRING_PADS_RING(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_RING::~BULE_SPRING_PADS_RING() {}

	void BULE_SPRING_PADS_RING::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_RING_57);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_RING_57_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_RING::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();

	}

	void BULE_SPRING_PADS_RING::OnShow(int scale) {
	
		texture.OnShow(scale);
		
	}


	// BULE_SPRING_PADS_RING_U
	BULE_SPRING_PADS_RING_U::BULE_SPRING_PADS_RING_U(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_RING_U::~BULE_SPRING_PADS_RING_U() {}

	void BULE_SPRING_PADS_RING_U::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_RING_U_59);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_RING_U_59_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_RING_U::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();

	}

	void BULE_SPRING_PADS_RING_U::OnShow(int scale) {
		
		texture.OnShow(scale);
		
	}

	// BULE_SPRING_PADS_RING_D

	BULE_SPRING_PADS_RING_D::BULE_SPRING_PADS_RING_D(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_RING_D::~BULE_SPRING_PADS_RING_D() {}

	void BULE_SPRING_PADS_RING_D::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_RING_D_61);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_RING_D_61_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_RING_D::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();


	}

	void BULE_SPRING_PADS_RING_D::OnShow(int scale) {

		texture.OnShow(scale);
		
	}

	// GATE_YELLOW

	GATE_YELLOW::GATE_YELLOW(int x, int y) : Item::Item(x, y) {}

	GATE_YELLOW::~GATE_YELLOW() {}

	void GATE_YELLOW::OnInit() {
		texture.AddBitmap(ITEMS_GATE_YELLOW);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEMS_GATE_YELLOW);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void GATE_YELLOW::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();


	}

	void GATE_YELLOW::OnShow(int scale) {

		texture.OnShow(scale);

	}

	// SEND

	SEND::SEND(int x, int y) : Item::Item(x, y) {}

	SEND::~SEND() {}

	void SEND::OnInit() {
		texture.AddBitmap(ITEM_SEND_1);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_SEND_2);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void SEND::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();


	}

	void SEND::OnShow(int scale) {

		texture.OnShow(scale);
		
	}

	// SEND_BUTTON

	SEND_BUTTON::SEND_BUTTON(int x, int y) : Item::Item(x, y) {}

	SEND_BUTTON::~SEND_BUTTON() {}

	void SEND_BUTTON::OnInit() {
		texture.AddBitmap(ITEM_SEND_BUTTON_1);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEM_SEND_BUTTON_2);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void SEND_BUTTON::OnMove() {
		CameraMove();

		setTopLeft(pos);
		texture.OnMove();


	}

	void SEND_BUTTON::OnShow(int scale) {

		texture.OnShow(scale);

	}

	// LOOP_LEFT
	LOOP_LEFT::LOOP_LEFT(int x, int y) : Item::Item(x, y) {}

	LOOP_LEFT::~LOOP_LEFT() {}

	void LOOP_LEFT::OnInit() {
		texture.AddBitmap(ITEMS_LOOP_LEFT);

		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEMS_LOOP_LEFT);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);

	}

	void LOOP_LEFT::OnMove() {
		CameraMove();

		if (CollisionDetection(currnetActor)) {
			isDead = true;

		}

		setTopLeft(pos);
		if (isDead) {
			if (deadAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_RING, false);
			}
		}
		else {
			texture.OnMove();
		}

	}

	void LOOP_LEFT::OnShow(int scale) {
		if (isDead) {
			deadAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}
	
	// LOOR_RING
	LOOR_RING::LOOR_RING(int x, int y) : Item::Item(x, y) {}

	LOOR_RING::~LOOR_RING() {}

	void LOOR_RING::OnInit() {
		texture.AddBitmap(ITEMS_LOOP_RING);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEMS_LOOP_RING);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);

	}

	void LOOR_RING::OnMove() {
		CameraMove();

		if (CollisionDetection(currnetActor)) {
			isDead = true;

		}

		setTopLeft(pos);
		if (isDead) {
			if (deadAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_RING, false);
			}
		}
		else {
			texture.OnMove();
		}

	}

	void LOOR_RING::OnShow(int scale) {
		if (isDead) {
			deadAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}
	
	// LOOP_TOP
	LOOP_TOP::LOOP_TOP(int x, int y) : Item::Item(x, y) {}

	LOOP_TOP::~LOOP_TOP() {}

	void LOOP_TOP::OnInit() {
		texture.AddBitmap(ITEMS_LOOP_TOP);
		
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEMS_LOOP_TOP);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);

	}

	void LOOP_TOP::OnMove() {
		CameraMove();

		if (CollisionDetection(currnetActor)) {
			isDead = true;

		}

		setTopLeft(pos);
		if (isDead) {
			if (deadAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_RING, false);
			}
		}
		else {
			texture.OnMove();
		}

	}

	void LOOP_TOP::OnShow(int scale) {
		if (isDead) {
			deadAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// LOOP_TOP_HIED
	LOOP_TOP_HIED::LOOP_TOP_HIED(int x, int y) : Item::Item(x, y) {}

	LOOP_TOP_HIED::~LOOP_TOP_HIED() {}

	void LOOP_TOP_HIED::OnInit() {
		texture.AddBitmap(ITEMS_LOOP_TOP_HIED);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEMS_LOOP_TOP_HIED);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);

	}

	void LOOP_TOP_HIED::OnMove() {
		CameraMove();

		if (CollisionDetection(currnetActor)) {
			isDead = true;

		}

		setTopLeft(pos);
		if (isDead) {
			if (deadAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_RING, false);
			}
		}
		else {
			texture.OnMove();
		}

	}

	void LOOP_TOP_HIED::OnShow(int scale) {
		if (isDead) {
			deadAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// LOOP_OFF
	LOOP_OFF::LOOP_OFF(int x, int y) : Item::Item(x, y) {}

	LOOP_OFF::~LOOP_OFF() {}

	void LOOP_OFF::OnInit() {
		texture.AddBitmap(ITEMS_LOOP_OFF);
		
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEMS_LOOP_OFF);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);

	}

	void LOOP_OFF::OnMove() {
		CameraMove();

		if (CollisionDetection(currnetActor)) {
			isDead = true;

		}

		setTopLeft(pos);
		if (isDead) {
			if (deadAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_RING, false);
			}
		}
		else {
			texture.OnMove();
		}

	}

	void LOOP_OFF::OnShow(int scale) {
		if (isDead) {
			deadAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}
	
	// LOOP_TOP_NOT_U_D
	LOOP_TOP_NOT_U_D::LOOP_TOP_NOT_U_D(int x, int y) : Item::Item(x, y) {}

	LOOP_TOP_NOT_U_D::~LOOP_TOP_NOT_U_D() {}

	void LOOP_TOP_NOT_U_D::OnInit() {
		texture.AddBitmap(ITEMS_LOOP_TOP_NOT_U_D);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEMS_LOOP_TOP_NOT_U_D);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);

	}

	void LOOP_TOP_NOT_U_D::OnMove() {
		CameraMove();

		if (CollisionDetection(currnetActor)) {
			isDead = true;

		}

		setTopLeft(pos);
		if (isDead) {
			if (deadAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_RING, false);
			}
		}
		else {
			texture.OnMove();
		}

	}

	void LOOP_TOP_NOT_U_D::OnShow(int scale) {
		if (isDead) {
			deadAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	//LOOP_TOP_UP_DOWN
	LOOP_TOP_UP_DOWN::LOOP_TOP_UP_DOWN(int x, int y) : Item::Item(x, y) {}

	LOOP_TOP_UP_DOWN::~LOOP_TOP_UP_DOWN() {}

	void LOOP_TOP_UP_DOWN::OnInit() {
		texture.AddBitmap(ITEMS_LOOP_TOP_UP_DOWN);
		texture.SetDelayCount(3);

		deadAnimate.AddBitmap(ITEMS_LOOP_TOP_UP_DOWN);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);

	}

	void LOOP_TOP_UP_DOWN::OnMove() {
		CameraMove();

		if (CollisionDetection(currnetActor)) {
			isDead = true;

		}

		setTopLeft(pos);
		if (isDead) {
			if (deadAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_RING, false);
			}
		}
		else {
			texture.OnMove();
		}

	}

	void LOOP_TOP_UP_DOWN::OnShow(int scale) {
		if (isDead) {
			deadAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

}