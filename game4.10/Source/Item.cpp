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
	Item::Item() {
		pos.x = 0;
		pos.y = 0;
		angle = 0;
		cameraSpeed = 50;
	}

	Item::Item(int x, int y) {
		pos.x = x;
		pos.y = y;
		angle = 0;
		cameraSpeed = 50;

		isDead = isDeadFinish =false;
		isBounce = isBounceFinish = false;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
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
		bounceAnimate.SetTopLeft(pos.x, pos.y);
	}

	void Item::setTopLeft(POINT xy) {
		pos = xy;

		texture.SetTopLeft(pos.x, pos.y);
		deadAnimate.SetTopLeft(pos.x, pos.y);
		bounceAnimate.SetTopLeft(pos.x, pos.y);
	}

	void Item::setAngle(int ang) {
		angle = ang;
	}

	void Item::SetMoveLeft(bool m) {
		isMovingLeft = m;
	}

	void Item::SetMoveRight(bool m) {
		isMovingRight = m;
	}

	void Item::SetMoveUp(bool m) {
		isMovingUp = m;
	}

	void Item::SetMoveDown(bool m) {
		isMovingDown = m;
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

	bool Item::IsBounce() {
		return isBounceFinish;
	}

	// Ring
	Ring::Ring() : Item::Item() {}

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
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isDead = true;

		}

		setTopLeft(pos);
		if (isDead) {
			if (deadAnimate.IsFinalBitmap()) {
				isDeadFinish = true;
				
			}
			else if (deadAnimate.GetCurrentBitmapNumber() == 1){
				CAudio::Instance()->Play(AUDIO_RING, false);
			}
			deadAnimate.OnMove();
		} else {
			texture.OnMove();
		}

		
		
		
		
	}

	void Ring::OnShow(int scale) {
		if (isDead) {
			deadAnimate.OnShow(scale);
		} else {
			texture.OnShow(scale);
		}
	}

	// RED_SPRING_PADS_UP
	RED_SPRING_PADS_UP::RED_SPRING_PADS_UP() : Item::Item() {}

	RED_SPRING_PADS_UP::RED_SPRING_PADS_UP(int x, int y) : Item::Item(x, y) {}

	RED_SPRING_PADS_UP::~RED_SPRING_PADS_UP() {}

	void RED_SPRING_PADS_UP::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_UP_21);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_RED_SPRING_PADS_UP_21_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_UP::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void RED_SPRING_PADS_UP::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}
	
	// RED_SPRING_PADS_DOWN
	RED_SPRING_PADS_DOWN::RED_SPRING_PADS_DOWN() : Item::Item() {}

	RED_SPRING_PADS_DOWN::RED_SPRING_PADS_DOWN(int x, int y) : Item::Item(x, y) {}

	RED_SPRING_PADS_DOWN::~RED_SPRING_PADS_DOWN() {}

	void RED_SPRING_PADS_DOWN::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_DOWN_47);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_RED_SPRING_PADS_DOWN_47_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_DOWN::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void RED_SPRING_PADS_DOWN::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// RED_SPRING_PADS_LEFT
	RED_SPRING_PADS_LEFT::RED_SPRING_PADS_LEFT() : Item::Item() {}

	RED_SPRING_PADS_LEFT::RED_SPRING_PADS_LEFT(int x, int y) : Item::Item(x, y) {}

	RED_SPRING_PADS_LEFT::~RED_SPRING_PADS_LEFT() {}

	void RED_SPRING_PADS_LEFT::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_22);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_22_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_LEFT::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void RED_SPRING_PADS_LEFT::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// RED_SPRING_PADS_LEFT_U
	RED_SPRING_PADS_LEFT_U::RED_SPRING_PADS_LEFT_U() : Item::Item() {}

	RED_SPRING_PADS_LEFT_U::RED_SPRING_PADS_LEFT_U(int x, int y) : Item::Item(x, y) {}

	RED_SPRING_PADS_LEFT_U::~RED_SPRING_PADS_LEFT_U() {}

	void RED_SPRING_PADS_LEFT_U::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_U_43);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_U_43_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_LEFT_U::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void RED_SPRING_PADS_LEFT_U::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// RED_SPRING_PADS_LEFT_D
	RED_SPRING_PADS_LEFT_D::RED_SPRING_PADS_LEFT_D() : Item::Item() {}

	RED_SPRING_PADS_LEFT_D::RED_SPRING_PADS_LEFT_D(int x, int y) : Item::Item(x, y) {}

	RED_SPRING_PADS_LEFT_D::~RED_SPRING_PADS_LEFT_D() {}

	void RED_SPRING_PADS_LEFT_D::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_D_45);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_D_45_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_LEFT_D::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void RED_SPRING_PADS_LEFT_D::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// RED_SPRING_PADS_RING
	RED_SPRING_PADS_RING::RED_SPRING_PADS_RING() : Item::Item() {}

	RED_SPRING_PADS_RING::RED_SPRING_PADS_RING(int x, int y) : Item::Item(x, y) {}

	RED_SPRING_PADS_RING::~RED_SPRING_PADS_RING() {}

	void RED_SPRING_PADS_RING::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_RING_23);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_RED_SPRING_PADS_RING_23_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_RING::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void RED_SPRING_PADS_RING::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// RED_SPRING_PADS_RING_U
	RED_SPRING_PADS_RING_U::RED_SPRING_PADS_RING_U() : Item::Item() {}

	RED_SPRING_PADS_RING_U::RED_SPRING_PADS_RING_U(int x, int y) : Item::Item(x, y) {}

	RED_SPRING_PADS_RING_U::~RED_SPRING_PADS_RING_U() {}

	void RED_SPRING_PADS_RING_U::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_RING_U_44);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_RED_SPRING_PADS_RING_U_44_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_RING_U::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void RED_SPRING_PADS_RING_U::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// RED_SPRING_PADS_RING_D
	RED_SPRING_PADS_RING_D::RED_SPRING_PADS_RING_D() : Item::Item() {}

	RED_SPRING_PADS_RING_D::RED_SPRING_PADS_RING_D(int x, int y) : Item::Item(x, y) {}

	RED_SPRING_PADS_RING_D::~RED_SPRING_PADS_RING_D() {}

	void RED_SPRING_PADS_RING_D::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_RING_D_46);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_RED_SPRING_PADS_RING_D_46_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_RING_D::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void RED_SPRING_PADS_RING_D::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}



	// YELLOW_SPRING_PADS_UP
	YELLOW_SPRING_PADS_UP::YELLOW_SPRING_PADS_UP() : Item::Item() {}

	YELLOW_SPRING_PADS_UP::YELLOW_SPRING_PADS_UP(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_UP::~YELLOW_SPRING_PADS_UP() {}

	void YELLOW_SPRING_PADS_UP::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_UP_20);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_UP_20_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_UP::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void YELLOW_SPRING_PADS_UP::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// YELLOW_SPRING_PADS_DOWN
	YELLOW_SPRING_PADS_DOWN::YELLOW_SPRING_PADS_DOWN() : Item::Item() {}

	YELLOW_SPRING_PADS_DOWN::YELLOW_SPRING_PADS_DOWN(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_DOWN::~YELLOW_SPRING_PADS_DOWN() {}

	void YELLOW_SPRING_PADS_DOWN::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_DOWN_54);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_DOWN_54_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_DOWN::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void YELLOW_SPRING_PADS_DOWN::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// YELLOW_SPRING_PADS_LEFT
	YELLOW_SPRING_PADS_LEFT::YELLOW_SPRING_PADS_LEFT() : Item::Item() {}

	YELLOW_SPRING_PADS_LEFT::YELLOW_SPRING_PADS_LEFT(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_LEFT::~YELLOW_SPRING_PADS_LEFT() {}

	void YELLOW_SPRING_PADS_LEFT::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_48);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_48_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_LEFT::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void YELLOW_SPRING_PADS_LEFT::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// YELLOW_SPRING_PADS_LEFT_U
	YELLOW_SPRING_PADS_LEFT_U::YELLOW_SPRING_PADS_LEFT_U() : Item::Item() {}

	YELLOW_SPRING_PADS_LEFT_U::YELLOW_SPRING_PADS_LEFT_U(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_LEFT_U::~YELLOW_SPRING_PADS_LEFT_U() {}

	void YELLOW_SPRING_PADS_LEFT_U::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_U_50);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_U_50_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_LEFT_U::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void YELLOW_SPRING_PADS_LEFT_U::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// YELLOW_SPRING_PADS_LEFT_D
	YELLOW_SPRING_PADS_LEFT_D::YELLOW_SPRING_PADS_LEFT_D() : Item::Item() {}

	YELLOW_SPRING_PADS_LEFT_D::YELLOW_SPRING_PADS_LEFT_D(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_LEFT_D::~YELLOW_SPRING_PADS_LEFT_D() {}

	void YELLOW_SPRING_PADS_LEFT_D::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_D_52);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_D_52_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_LEFT_D::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void YELLOW_SPRING_PADS_LEFT_D::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// YELLOW_SPRING_PADS_RING
	YELLOW_SPRING_PADS_RING::YELLOW_SPRING_PADS_RING() : Item::Item() {}

	YELLOW_SPRING_PADS_RING::YELLOW_SPRING_PADS_RING(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_RING::~YELLOW_SPRING_PADS_RING() {}

	void YELLOW_SPRING_PADS_RING::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_49);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_49_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_RING::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void YELLOW_SPRING_PADS_RING::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}


	// YELLOW_SPRING_PADS_RING_U
	YELLOW_SPRING_PADS_RING_U::YELLOW_SPRING_PADS_RING_U() : Item::Item() {}

	YELLOW_SPRING_PADS_RING_U::YELLOW_SPRING_PADS_RING_U(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_RING_U::~YELLOW_SPRING_PADS_RING_U() {}

	void YELLOW_SPRING_PADS_RING_U::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_U_51);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_U_51_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_RING_U::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void YELLOW_SPRING_PADS_RING_U::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}


	// YELLOW_SPRING_PADS_RING_D
	YELLOW_SPRING_PADS_RING_D::YELLOW_SPRING_PADS_RING_D() : Item::Item() {}

	YELLOW_SPRING_PADS_RING_D::YELLOW_SPRING_PADS_RING_D(int x, int y) : Item::Item(x, y) {}

	YELLOW_SPRING_PADS_RING_D::~YELLOW_SPRING_PADS_RING_D() {}

	void YELLOW_SPRING_PADS_RING_D::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_D_53);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_D_53_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_RING_D::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void YELLOW_SPRING_PADS_RING_D::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}


	// BULE_SPRING_PADS_UP
	BULE_SPRING_PADS_UP::BULE_SPRING_PADS_UP() : Item::Item() {}

	BULE_SPRING_PADS_UP::BULE_SPRING_PADS_UP(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_UP::~BULE_SPRING_PADS_UP() {}

	void BULE_SPRING_PADS_UP::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_UP_55);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_UP_55_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_UP::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void BULE_SPRING_PADS_UP::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// BULE_SPRING_PADS_DOWN
	BULE_SPRING_PADS_DOWN::BULE_SPRING_PADS_DOWN() : Item::Item() {}

	BULE_SPRING_PADS_DOWN::BULE_SPRING_PADS_DOWN(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_DOWN::~BULE_SPRING_PADS_DOWN() {}

	void BULE_SPRING_PADS_DOWN::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_DOWN_62);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_DOWN_62_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_DOWN::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void BULE_SPRING_PADS_DOWN::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// BULE_SPRING_PADS_LEFT
	BULE_SPRING_PADS_LEFT::BULE_SPRING_PADS_LEFT() : Item::Item() {}

	BULE_SPRING_PADS_LEFT::BULE_SPRING_PADS_LEFT(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_LEFT::~BULE_SPRING_PADS_LEFT() {}

	void BULE_SPRING_PADS_LEFT::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_56);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_56_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_LEFT::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void BULE_SPRING_PADS_LEFT::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// BULE_SPRING_PADS_LEFT_U
	BULE_SPRING_PADS_LEFT_U::BULE_SPRING_PADS_LEFT_U() : Item::Item() {}

	BULE_SPRING_PADS_LEFT_U::BULE_SPRING_PADS_LEFT_U(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_LEFT_U::~BULE_SPRING_PADS_LEFT_U() {}

	void BULE_SPRING_PADS_LEFT_U::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_U_58);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_U_58_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_LEFT_U::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void BULE_SPRING_PADS_LEFT_U::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// BULE_SPRING_PADS_LEFT_D
	BULE_SPRING_PADS_LEFT_D::BULE_SPRING_PADS_LEFT_D() : Item::Item() {}

	BULE_SPRING_PADS_LEFT_D::BULE_SPRING_PADS_LEFT_D(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_LEFT_D::~BULE_SPRING_PADS_LEFT_D() {}

	void BULE_SPRING_PADS_LEFT_D::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_D_60);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_D_60_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_LEFT_D::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void BULE_SPRING_PADS_LEFT_D::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

	// BULE_SPRING_PADS_RING
	BULE_SPRING_PADS_RING::BULE_SPRING_PADS_RING() : Item::Item() {}

	BULE_SPRING_PADS_RING::BULE_SPRING_PADS_RING(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_RING::~BULE_SPRING_PADS_RING() {}

	void BULE_SPRING_PADS_RING::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_RING_57);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_RING_57_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_RING::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void BULE_SPRING_PADS_RING::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}


	// BULE_SPRING_PADS_RING_U
	BULE_SPRING_PADS_RING_U::BULE_SPRING_PADS_RING_U() : Item::Item() {}

	BULE_SPRING_PADS_RING_U::BULE_SPRING_PADS_RING_U(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_RING_U::~BULE_SPRING_PADS_RING_U() {}

	void BULE_SPRING_PADS_RING_U::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_RING_U_59);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_RING_U_59_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_RING_U::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void BULE_SPRING_PADS_RING_U::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}


	// BULE_SPRING_PADS_RING_D
	BULE_SPRING_PADS_RING_D::BULE_SPRING_PADS_RING_D() : Item::Item() {}

	BULE_SPRING_PADS_RING_D::BULE_SPRING_PADS_RING_D(int x, int y) : Item::Item(x, y) {}

	BULE_SPRING_PADS_RING_D::~BULE_SPRING_PADS_RING_D() {}

	void BULE_SPRING_PADS_RING_D::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_RING_D_61);
		texture.SetDelayCount(3);

		bounceAnimate.AddBitmap(ITEM_BULE_SPRING_PADS_RING_D_61_1);
		bounceAnimate.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_RING_D::OnMove() {
		// Camera Move
		if (isMovingLeft) {
			pos.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;

		}

		if (CollisionDetection(currnetActor)) {
			isBounce = true;

		}

		setTopLeft(pos);
		if (isBounce) {
			if (bounceAnimate.IsFinalBitmap()) {
				isBounceFinish = true;

			}
			else if (bounceAnimate.GetCurrentBitmapNumber() == 1) {
				CAudio::Instance()->Play(AUDIO_SPRING, false);
			}
			bounceAnimate.OnMove();
		}
		else {
			texture.OnMove();
		}



	}

	void BULE_SPRING_PADS_RING_D::OnShow(int scale) {
		if (isBounce) {
			bounceAnimate.OnShow(scale);
		}
		else {
			texture.OnShow(scale);
		}
	}

}


