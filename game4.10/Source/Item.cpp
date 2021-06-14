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
	/* Constructor */
	// Item
	Item::Item(int _id, int x, int y) {
		id = _id;
		pos.x = x;
		pos.y = y;
		angle = 0;

		cameraSpeed = 50;
		delta = POINT();

	}

	/* Getter */
	int Item::ID() { return id; }

	int Item::Height() { return texture.Height(); }

	int Item::Width() { return texture.Width(); }

	int Item::Top() { return texture.Top(); }

	int Item::Left() { return texture.Left(); }

	int Item::Bottom() { return this->Top() + this->Height() * DEFAULT_SCALE; }

	int Item::Right() { return this->Left() + this->Width() * DEFAULT_SCALE; }

	/* Setter */
	void Item::SetID(int _id) { id = _id; }

	void Item::SetAngle(int ang) { angle = ang; }

	void Item::SetMoving(POINT _delta) { delta = _delta; }

	void Item::SetCurrentActor(Actor* actor) { currnetActor = actor; }

	void Item::setTopLeft(int x, int y) {
		pos.x = x;
		pos.y = y;

		texture.SetTopLeft(pos.x, pos.y);
	}

	void Item::setTopLeft(POINT xy) {
		pos = xy;

		texture.SetTopLeft(pos.x, pos.y);
	}

	/* Member Function */
	void Item::CameraMove() {
		pos.x -= delta.x;
		pos.y -= delta.y;

		setTopLeft(pos);
	}

	bool Item::CollisionDetection(Actor* actor) {
		if (this->Left() < actor->Right() &&
			this->Right() > actor->Left() &&
			this->Top() < actor->Bottom() &&
			this->Bottom() > actor->Top()) {

			return true;
		}

		return false;
	}


	// Ring
	Ring::Ring(int id, int x, int y) : Item::Item(id, x, y) {
		isDead = isDeadFinish = false;
	}

	Ring::~Ring() {}

	bool Ring::IsChange() { return isDeadFinish; }

	void Ring::OnInit() {
		texture.AddBitmap(ITEMS_YELLOW_RING_1);
		texture.AddBitmap(ITEMS_YELLOW_RING_2);
		texture.AddBitmap(ITEMS_YELLOW_RING_3);
		texture.AddBitmap(ITEMS_YELLOW_RING_4);
		texture.AddBitmap(ITEMS_YELLOW_RING_5);
		texture.AddBitmap(ITEMS_YELLOW_RING_6);
		texture.AddBitmap(ITEMS_YELLOW_RING_7);
		texture.AddBitmap(ITEMS_YELLOW_RING_8);
		texture.SetDelayCount(2);

		deadAnimate.AddBitmap(ITEM_YELLOW_RING_DEAD_1);
		deadAnimate.AddBitmap(ITEM_YELLOW_RING_DEAD_2);
		deadAnimate.AddBitmap(ITEM_YELLOW_RING_DEAD_3);
		deadAnimate.AddBitmap(ITEM_YELLOW_RING_DEAD_4);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);
		
	}
	
	void Ring::OnMove() {
		CameraMove();

		if (CollisionDetection(currnetActor))
			isDead = true;

		setTopLeft(pos);
		deadAnimate.SetTopLeft(pos.x, pos.y);
		if (isDead) {
			if (deadAnimate.IsFinalBitmap()) 
				isDeadFinish = true;
			else if (deadAnimate.GetCurrentBitmapNumber() == 1)
				CAudio::Instance()->Play(AUDIO_RING, false);

			deadAnimate.OnMove();
		} else 
			texture.OnMove();
	}

	void Ring::OnShow(int scale) {
		if (isDead)
			deadAnimate.OnShow(scale);
		else 
			texture.OnShow(scale);
	}
	
	// BIG_Ring
	BIG_Ring::BIG_Ring(int id, int x, int y) : Item::Item(id, x, y) {
		isDead = isDeadFinish = false;
	}

	BIG_Ring::~BIG_Ring() {}

	bool BIG_Ring::IsChange() { return isDeadFinish; }

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

		// 
		deadAnimate.AddBitmap(ITEM_YELLOW_RING_DEAD_1);
		deadAnimate.SetDelayCount(3);

		setTopLeft(pos);

	}

	void BIG_Ring::OnMove() {
		CameraMove();

		if (CollisionDetection(currnetActor))
			isDead = true;

		setTopLeft(pos);
		deadAnimate.SetTopLeft(pos.x, pos.y);
		if (isDead) {
			if (deadAnimate.IsFinalBitmap())
				isDeadFinish = true;
			else if (deadAnimate.GetCurrentBitmapNumber() == 1)
				CAudio::Instance()->Play(AUDIO_RING, false);
			deadAnimate.OnMove();
		} else
			texture.OnMove();
	}

	void BIG_Ring::OnShow(int scale) {
		if (isDead)
			deadAnimate.OnShow(scale);
		else 
			texture.OnShow(scale);
	}
	
	// RED_SPRING_PADS_UP
	RED_SPRING_PADS_UP::RED_SPRING_PADS_UP(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	bool RED_SPRING_PADS_UP::IsChange() { return isTouch; }

	void RED_SPRING_PADS_UP::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_UP_21);
		texture.AddBitmap(ITEM_RED_SPRING_PADS_UP_21_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}
	
	void RED_SPRING_PADS_UP::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		} else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		} else {
			texture.Reset();
		}

	}


	void RED_SPRING_PADS_UP::OnShow(int scale) {
		texture.OnShow(scale);
	}

	
	// RED_SPRING_PADS_DOWN

	RED_SPRING_PADS_DOWN::RED_SPRING_PADS_DOWN(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	RED_SPRING_PADS_DOWN::~RED_SPRING_PADS_DOWN() {}

	bool RED_SPRING_PADS_DOWN::IsChange() { return isTouch; }

	void RED_SPRING_PADS_DOWN::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_DOWN_47);
		texture.AddBitmap(ITEM_RED_SPRING_PADS_DOWN_47_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_DOWN::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void RED_SPRING_PADS_DOWN::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// RED_SPRING_PADS_LEFT
	RED_SPRING_PADS_LEFT::RED_SPRING_PADS_LEFT(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	RED_SPRING_PADS_LEFT::~RED_SPRING_PADS_LEFT() {}

	bool RED_SPRING_PADS_LEFT::IsChange() { return isTouch; }

	void RED_SPRING_PADS_LEFT::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_22);
		texture.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_22_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}
	
	void RED_SPRING_PADS_LEFT::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void RED_SPRING_PADS_LEFT::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// RED_SPRING_PADS_LEFT_U

	RED_SPRING_PADS_LEFT_U::RED_SPRING_PADS_LEFT_U(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	RED_SPRING_PADS_LEFT_U::~RED_SPRING_PADS_LEFT_U() {}

	bool RED_SPRING_PADS_LEFT_U::IsChange() { return isTouch; }

	void RED_SPRING_PADS_LEFT_U::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_U_43);
		texture.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_U_43_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_LEFT_U::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void RED_SPRING_PADS_LEFT_U::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// RED_SPRING_PADS_LEFT_D
	RED_SPRING_PADS_LEFT_D::RED_SPRING_PADS_LEFT_D(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	RED_SPRING_PADS_LEFT_D::~RED_SPRING_PADS_LEFT_D() {}

	bool RED_SPRING_PADS_LEFT_D::IsChange() { return isTouch; }

	void RED_SPRING_PADS_LEFT_D::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_D_45);
		texture.AddBitmap(ITEM_RED_SPRING_PADS_LEFT_D_45_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_LEFT_D::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void RED_SPRING_PADS_LEFT_D::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// RED_SPRING_PADS_RING
	RED_SPRING_PADS_RING::RED_SPRING_PADS_RING(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	RED_SPRING_PADS_RING::~RED_SPRING_PADS_RING() {}

	bool RED_SPRING_PADS_RING::IsChange() { return isTouch; }

	void RED_SPRING_PADS_RING::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_RING_23);
		texture.AddBitmap(ITEM_RED_SPRING_PADS_RING_23_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_RING::OnMove() {
		CameraMove();

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void RED_SPRING_PADS_RING::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// RED_SPRING_PADS_RING_U
	RED_SPRING_PADS_RING_U::RED_SPRING_PADS_RING_U(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	RED_SPRING_PADS_RING_U::~RED_SPRING_PADS_RING_U() {}

	bool RED_SPRING_PADS_RING_U::IsChange() { return isTouch; }

	void RED_SPRING_PADS_RING_U::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_RING_U_44);
		texture.AddBitmap(ITEM_RED_SPRING_PADS_RING_U_44_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_RING_U::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void RED_SPRING_PADS_RING_U::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// RED_SPRING_PADS_RING_D
	RED_SPRING_PADS_RING_D::RED_SPRING_PADS_RING_D(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	RED_SPRING_PADS_RING_D::~RED_SPRING_PADS_RING_D() {}

	bool RED_SPRING_PADS_RING_D::IsChange() { return isTouch; }

	void RED_SPRING_PADS_RING_D::OnInit() {
		texture.AddBitmap(ITEM_RED_SPRING_PADS_RING_D_46);
		texture.AddBitmap(ITEM_RED_SPRING_PADS_RING_D_46_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void RED_SPRING_PADS_RING_D::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void RED_SPRING_PADS_RING_D::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// YELLOW_SPRING_PADS_UP
	YELLOW_SPRING_PADS_UP::YELLOW_SPRING_PADS_UP(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	YELLOW_SPRING_PADS_UP::~YELLOW_SPRING_PADS_UP() {}

	bool YELLOW_SPRING_PADS_UP::IsChange() { return isTouch; }

	void YELLOW_SPRING_PADS_UP::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_UP_20);
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_UP_20_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_UP::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void YELLOW_SPRING_PADS_UP::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// YELLOW_SPRING_PADS_DOWN
	YELLOW_SPRING_PADS_DOWN::YELLOW_SPRING_PADS_DOWN(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	YELLOW_SPRING_PADS_DOWN::~YELLOW_SPRING_PADS_DOWN() {}

	bool YELLOW_SPRING_PADS_DOWN::IsChange() { return isTouch; }

	void YELLOW_SPRING_PADS_DOWN::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_DOWN_54);
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_DOWN_54_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_DOWN::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void YELLOW_SPRING_PADS_DOWN::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// YELLOW_SPRING_PADS_LEFT
	YELLOW_SPRING_PADS_LEFT::YELLOW_SPRING_PADS_LEFT(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	YELLOW_SPRING_PADS_LEFT::~YELLOW_SPRING_PADS_LEFT() {}

	bool YELLOW_SPRING_PADS_LEFT::IsChange() { return isTouch; }

	void YELLOW_SPRING_PADS_LEFT::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_48);
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_48_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_LEFT::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void YELLOW_SPRING_PADS_LEFT::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// YELLOW_SPRING_PADS_LEFT_U
	YELLOW_SPRING_PADS_LEFT_U::YELLOW_SPRING_PADS_LEFT_U(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	YELLOW_SPRING_PADS_LEFT_U::~YELLOW_SPRING_PADS_LEFT_U() {}

	bool YELLOW_SPRING_PADS_LEFT_U::IsChange() { return isTouch; }

	void YELLOW_SPRING_PADS_LEFT_U::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_U_50);
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_U_50_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_LEFT_U::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void YELLOW_SPRING_PADS_LEFT_U::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// YELLOW_SPRING_PADS_LEFT_D
	YELLOW_SPRING_PADS_LEFT_D::YELLOW_SPRING_PADS_LEFT_D(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	YELLOW_SPRING_PADS_LEFT_D::~YELLOW_SPRING_PADS_LEFT_D() {}

	bool YELLOW_SPRING_PADS_LEFT_D::IsChange() { return isTouch; }

	void YELLOW_SPRING_PADS_LEFT_D::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_D_52);
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_LEFT_D_52_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_LEFT_D::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void YELLOW_SPRING_PADS_LEFT_D::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// YELLOW_SPRING_PADS_RING
	YELLOW_SPRING_PADS_RING::YELLOW_SPRING_PADS_RING(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	YELLOW_SPRING_PADS_RING::~YELLOW_SPRING_PADS_RING() {}

	bool YELLOW_SPRING_PADS_RING::IsChange() { return isTouch; }

	void YELLOW_SPRING_PADS_RING::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_49);
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_49_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_RING::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}
	}

	void YELLOW_SPRING_PADS_RING::OnShow(int scale) {
		texture.OnShow(scale);
	}


	// YELLOW_SPRING_PADS_RING_U
	YELLOW_SPRING_PADS_RING_U::YELLOW_SPRING_PADS_RING_U(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	YELLOW_SPRING_PADS_RING_U::~YELLOW_SPRING_PADS_RING_U() {}

	bool YELLOW_SPRING_PADS_RING_U::IsChange() { return isTouch; }

	void YELLOW_SPRING_PADS_RING_U::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_U_51);
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_U_51_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_RING_U::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void YELLOW_SPRING_PADS_RING_U::OnShow(int scale) {
		texture.OnShow(scale);
	}


	// YELLOW_SPRING_PADS_RING_D
	YELLOW_SPRING_PADS_RING_D::YELLOW_SPRING_PADS_RING_D(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	YELLOW_SPRING_PADS_RING_D::~YELLOW_SPRING_PADS_RING_D() {}

	bool YELLOW_SPRING_PADS_RING_D::IsChange() { return isTouch; }

	void YELLOW_SPRING_PADS_RING_D::OnInit() {
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_D_53);
		texture.AddBitmap(ITEM_YELLOW_SPRING_PADS_RING_D_53_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void YELLOW_SPRING_PADS_RING_D::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void YELLOW_SPRING_PADS_RING_D::OnShow(int scale) {
		texture.OnShow(scale);
	}


	// BULE_SPRING_PADS_UP
	BULE_SPRING_PADS_UP::BULE_SPRING_PADS_UP(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	BULE_SPRING_PADS_UP::~BULE_SPRING_PADS_UP() {}

	bool BULE_SPRING_PADS_UP::IsChange() { return isTouch; }

	void BULE_SPRING_PADS_UP::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_UP_55);
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_UP_55_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_UP::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void BULE_SPRING_PADS_UP::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// BULE_SPRING_PADS_DOWN
	BULE_SPRING_PADS_DOWN::BULE_SPRING_PADS_DOWN(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	BULE_SPRING_PADS_DOWN::~BULE_SPRING_PADS_DOWN() {}

	bool BULE_SPRING_PADS_DOWN::IsChange() { return isTouch; }

	void BULE_SPRING_PADS_DOWN::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_DOWN_62);
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_DOWN_62_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_DOWN::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void BULE_SPRING_PADS_DOWN::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// BULE_SPRING_PADS_LEFT
	BULE_SPRING_PADS_LEFT::BULE_SPRING_PADS_LEFT(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	BULE_SPRING_PADS_LEFT::~BULE_SPRING_PADS_LEFT() {}

	bool BULE_SPRING_PADS_LEFT::IsChange() { return isTouch; }

	void BULE_SPRING_PADS_LEFT::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_56);
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_56_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_LEFT::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void BULE_SPRING_PADS_LEFT::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// BULE_SPRING_PADS_LEFT_U
	BULE_SPRING_PADS_LEFT_U::BULE_SPRING_PADS_LEFT_U(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	BULE_SPRING_PADS_LEFT_U::~BULE_SPRING_PADS_LEFT_U() {}

	bool BULE_SPRING_PADS_LEFT_U::IsChange() { return isTouch; }

	void BULE_SPRING_PADS_LEFT_U::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_U_58);
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_U_58_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_LEFT_U::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void BULE_SPRING_PADS_LEFT_U::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// BULE_SPRING_PADS_LEFT_D
	BULE_SPRING_PADS_LEFT_D::BULE_SPRING_PADS_LEFT_D(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	BULE_SPRING_PADS_LEFT_D::~BULE_SPRING_PADS_LEFT_D() {}

	bool BULE_SPRING_PADS_LEFT_D::IsChange() { return isTouch; }

	void BULE_SPRING_PADS_LEFT_D::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_D_60);
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_LEFT_D_60_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_LEFT_D::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void BULE_SPRING_PADS_LEFT_D::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// BULE_SPRING_PADS_RING
	BULE_SPRING_PADS_RING::BULE_SPRING_PADS_RING(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	BULE_SPRING_PADS_RING::~BULE_SPRING_PADS_RING() {}

	bool BULE_SPRING_PADS_RING::IsChange() { return isTouch; }

	void BULE_SPRING_PADS_RING::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_RING_57);
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_RING_57_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_RING::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void BULE_SPRING_PADS_RING::OnShow(int scale) {
		texture.OnShow(scale);
	}


	// BULE_SPRING_PADS_RING_U
	BULE_SPRING_PADS_RING_U::BULE_SPRING_PADS_RING_U(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	BULE_SPRING_PADS_RING_U::~BULE_SPRING_PADS_RING_U() {}

	bool BULE_SPRING_PADS_RING_U::IsChange() { return isTouch; }

	void BULE_SPRING_PADS_RING_U::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_RING_U_59);
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_RING_U_59_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_RING_U::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void BULE_SPRING_PADS_RING_U::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// BULE_SPRING_PADS_RING_D

	BULE_SPRING_PADS_RING_D::BULE_SPRING_PADS_RING_D(int id, int x, int y) : Item::Item(id, x, y) {
		isTouch = false;
	}

	BULE_SPRING_PADS_RING_D::~BULE_SPRING_PADS_RING_D() {}

	bool BULE_SPRING_PADS_RING_D::IsChange() { return isTouch; }

	void BULE_SPRING_PADS_RING_D::OnInit() {
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_RING_D_61);
		texture.AddBitmap(ITEM_BULE_SPRING_PADS_RING_D_61_1);
		texture.SetDelayCount(3);

		setTopLeft(pos);
	}

	void BULE_SPRING_PADS_RING_D::OnMove() {
		CameraMove();
		setTopLeft(pos);

		if (CollisionDetection(currnetActor)) {
			isTouch = true;
		}
		else {
			isTouch = false;
		}

		if (isTouch && !texture.IsFinalBitmap()) {
			texture.OnMove();
		}
		else {
			texture.Reset();
		}

	}

	void BULE_SPRING_PADS_RING_D::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// GATE_YELLOW
	GATE_YELLOW::GATE_YELLOW(int id, int x, int y) : Item::Item(id, x, y) {}

	GATE_YELLOW::~GATE_YELLOW() {}

	bool GATE_YELLOW::IsChange() { return false; }

	void GATE_YELLOW::OnInit() {
		texture.AddBitmap(ITEMS_GATE_YELLOW);
		setTopLeft(pos);
	}

	void GATE_YELLOW::OnMove() {
		CameraMove();
		setTopLeft(pos);
	}

	void GATE_YELLOW::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// SEND
	SEND::SEND(int id, int x, int y) : Item::Item(id, x, y) {}

	SEND::~SEND() {}

	bool SEND::IsChange() { return false; }

	void SEND::OnInit() {
		texture.AddBitmap(ITEM_SEND_1);
		texture.AddBitmap(ITEM_SEND_2);
		texture.SetDelayCount(3);

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

	/*
	// SEND_BUTTON
	SEND_BUTTON::SEND_BUTTON(int id, int x, int y) : Item::Item(id, x, y) {}

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
	*/

	// LOOP_LEFT
	LOOP_LEFT::LOOP_LEFT(int id, int x, int y) : Item::Item(id, x, y) {}

	LOOP_LEFT::~LOOP_LEFT() {}

	bool LOOP_LEFT::IsChange() { return false; }

	void LOOP_LEFT::OnInit() {
		texture.AddBitmap(ITEMS_LOOP_LEFT);
		setTopLeft(pos);
	}

	void LOOP_LEFT::OnMove() {
		CameraMove();

	}

	void LOOP_LEFT::OnShow(int scale) {

	}
	
	// LOOP_RIGHT
	LOOP_RIGHT::LOOP_RIGHT(int id, int x, int y) : Item::Item(id, x, y) {}

	LOOP_RIGHT::~LOOP_RIGHT() {}

	bool LOOP_RIGHT::IsChange() { return false; }

	void LOOP_RIGHT::OnInit() {
		texture.AddBitmap(ITEMS_LOOP_RING);
		setTopLeft(pos);

	}

	void LOOP_RIGHT::OnMove() {
		CameraMove();

	}

	void LOOP_RIGHT::OnShow(int scale) {

	}
	
	// LOOP_TOP
	LOOP_TOP::LOOP_TOP(int id, int x, int y) : Item::Item(id, x, y) {}

	LOOP_TOP::~LOOP_TOP() {}

	bool LOOP_TOP::IsChange() { return false; }

	void LOOP_TOP::OnInit() {
		texture.AddBitmap(ITEMS_LOOP_TOP);
		setTopLeft(pos);

	}

	void LOOP_TOP::OnMove() {
		CameraMove();
	}

	void LOOP_TOP::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// LOOP_TOP_HIED
	LOOP_TOP_HIED::LOOP_TOP_HIED(int id, int x, int y) : Item::Item(id, x, y) {}

	LOOP_TOP_HIED::~LOOP_TOP_HIED() {}

	bool LOOP_TOP_HIED::IsChange() { return false; }

	void LOOP_TOP_HIED::OnInit() {
		texture.AddBitmap(ITEMS_LOOP_TOP_HIED);
		setTopLeft(pos);

	}

	void LOOP_TOP_HIED::OnMove() {
		CameraMove();
	}

	void LOOP_TOP_HIED::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// LOOP_OFF
	LOOP_OFF::LOOP_OFF(int id, int x, int y) : Item::Item(id, x, y) {}

	LOOP_OFF::~LOOP_OFF() {}

	bool LOOP_OFF::IsChange() { return false; }

	void LOOP_OFF::OnInit() {
		texture.AddBitmap(ITEMS_LOOP_OFF);
		setTopLeft(pos);

	}

	void LOOP_OFF::OnMove() {
		CameraMove();
	}

	void LOOP_OFF::OnShow(int scale) {
		texture.OnShow(scale);
	}
	
	// LOOP_TOP_NOT_U_D
	LOOP_TOP_NOT_U_D::LOOP_TOP_NOT_U_D(int id, int x, int y) : Item::Item(id, x, y) {}

	LOOP_TOP_NOT_U_D::~LOOP_TOP_NOT_U_D() {}

	bool LOOP_TOP_NOT_U_D::IsChange() { return false; }

	void LOOP_TOP_NOT_U_D::OnInit() {
		texture.AddBitmap(ITEMS_LOOP_TOP_NOT_U_D);
		setTopLeft(pos);

	}

	void LOOP_TOP_NOT_U_D::OnMove() {
		CameraMove();
	}

	void LOOP_TOP_NOT_U_D::OnShow(int scale) {
		texture.OnShow(scale);
	}

	// LOOP_TOP_UP_DOWN
	LOOP_TOP_UP_DOWN::LOOP_TOP_UP_DOWN(int id, int x, int y) : Item::Item(id, x, y) {}

	LOOP_TOP_UP_DOWN::~LOOP_TOP_UP_DOWN() {}

	bool LOOP_TOP_UP_DOWN::IsChange() { return false; }

	void LOOP_TOP_UP_DOWN::OnInit() {
		texture.AddBitmap(ITEMS_LOOP_TOP_UP_DOWN);
		setTopLeft(pos);

	}

	void LOOP_TOP_UP_DOWN::OnMove() {
		CameraMove();
	}

	void LOOP_TOP_UP_DOWN::OnShow(int scale) {
		texture.OnShow(scale);

	}



	// SPIKES_UP
	SPIKES_UP::SPIKES_UP(int id, int x, int y) : Item::Item(id, x, y) {
		isShow = false;
	}

	SPIKES_UP::~SPIKES_UP() {}

	bool SPIKES_UP::IsChange() { return isShow; }

	void SPIKES_UP::OnInit() {
		texture.AddBitmap(ITEM_SPIKES_UP);
		setTopLeft(pos);
	}

	void SPIKES_UP::OnMove() {
		CameraMove();

		// Handling when to show up.
		// Counting the time.

	}

	void SPIKES_UP::OnShow(int scale) {
		if (isShow)
			texture.OnShow(scale);
	}

	// SPIKES_DOWN
	SPIKES_DOWN::SPIKES_DOWN(int id, int x, int y) : Item::Item(id, x, y) {
		isShow = false;
	}

	SPIKES_DOWN::~SPIKES_DOWN() {}

	bool SPIKES_DOWN::IsChange() { return isShow; }

	void SPIKES_DOWN::OnInit() {
		texture.AddBitmap(ITEM_SPIKES_DOWN);
		setTopLeft(pos);
	}

	void SPIKES_DOWN::OnMove() {
		CameraMove();

		// Handling when to show up.
		// Counting the time.

	}

	void SPIKES_DOWN::OnShow(int scale) {
		if (isShow)
			texture.OnShow(scale);
	}

	// SPIKES_LEFT
	SPIKES_LEFT::SPIKES_LEFT(int id, int x, int y) : Item::Item(id, x, y) {
		isShow = false;
	}

	SPIKES_LEFT::~SPIKES_LEFT() {}

	bool SPIKES_LEFT::IsChange() { return isShow; }

	void SPIKES_LEFT::OnInit() {
		texture.AddBitmap(ITEM_SPIKES_LEFT);
		setTopLeft(pos);
	}

	void SPIKES_LEFT::OnMove() {
		CameraMove();

		// Handling when to show up.
		// Counting the time.

	}

	void SPIKES_LEFT::OnShow(int scale) {
		if (isShow)
			texture.OnShow(scale);
	}

	// SPIKES_RIGHT
	SPIKES_RIGHT::SPIKES_RIGHT(int id, int x, int y) : Item::Item(id, x, y) {
		isShow = false;
	}

	SPIKES_RIGHT::~SPIKES_RIGHT() {}

	bool SPIKES_RIGHT::IsChange() { return isShow; }

	void SPIKES_RIGHT::OnInit() {
		texture.AddBitmap(ITEM_SPIKES_RING);
		setTopLeft(pos);
	}

	void SPIKES_RIGHT::OnMove() {
		CameraMove();

		// Handling when to show up.
		// Counting the time.

	}

	void SPIKES_RIGHT::OnShow(int scale) {
		if (isShow)
			texture.OnShow(scale);
	}

}