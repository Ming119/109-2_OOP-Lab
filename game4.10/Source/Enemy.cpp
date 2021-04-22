#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Enemy.h"

namespace game_framework {
	// Enemy
	Enemy::Enemy(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
		maxSpeed = 50;
		speed = 0;
		direction = false;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isCollisingLeft = isCollisingRight = isCollisingTop = isCollisingBottom = false;

	}

	void Enemy::setTopLeft(int x, int y) {
		posX = x;
		posY = y;
		texture.SetTopLeft(x, y);
	}

	void Enemy::setAngle(int ang) {
		angle = ang;
	}

	int Enemy::Top() {
		return texture.Top();
	}

	int Enemy::Left() {
		return texture.Left();
	}

	int Enemy::Angle() {
		return angle;
	}

	int Enemy::Height() {
		return texture.Height();
	}

	int Enemy::Width() {
		return texture.Width();
	}

	void Enemy::SetMoveLeft(bool m) {
		isMovingLeft = m;
	}

	void Enemy::SetMoveRight(bool m) {
		isMovingRight = m;
	}

	void Enemy::SetMoveUp(bool m) {
		isMovingUp = m;
	}

	void Enemy::SetMoveDown(bool m) {
		isMovingDown = m;
	}
	
	void Enemy::SetCollisionLeft(bool collide) {
		isCollisingLeft = collide;
	}

	void Enemy::SetCollisionRight(bool collide) {
		isCollisingRight = collide;
	}

	void Enemy::SetCollisionTop(bool collide) {
		isCollisingTop = collide;
	}

	void Enemy::SetCollisionBottom(bool collide) {
		isCollisingBottom = collide;
	}

	bool Enemy::CollisionDetection(Brick* brick) {

		if (brick->Property() != OBSTACLE) return false;
		
		int Woffset = (int)((this->Left() + this->Width() * DEFAULT_SCALE) * 0.05);
		int Hoffset = (int)((this->Top() + this->Height() * DEFAULT_SCALE) * 0.05);
		if ((this->Left()+Woffset) < (brick->Left() + brick->Width() * DEFAULT_SCALE)-Woffset &&
			(this->Left() + this->Width() * DEFAULT_SCALE)-Woffset > (brick->Left()+Woffset) &&
			(this->Top()+Hoffset) < (brick->Top() + brick->Height() * DEFAULT_SCALE)-Hoffset &&
			(this->Top() + this->Height() * DEFAULT_SCALE)-Hoffset > (brick->Top()+Hoffset)) {
			
			this->SetCollisionBottom(true);

			if ((this->Top() + Hoffset) < (brick->Top() + brick->Height() * DEFAULT_SCALE) - Hoffset &&
				(this->Top() + this->Height() * DEFAULT_SCALE) - Hoffset > (brick->Top() + Hoffset))
				
			


			return true;
		}
		else {
			/*this->SetCollisionLeft(false);
			this->SetCollisionRight(false);
			this->SetCollisionTop(false);
			this->SetCollisionBottom(false);
			return false;*/
		}
		return false;
		

		/*if (a->Left() < b->Left() + b->Width() * DEFAULT_SCALE &&
			a->Left() + a->Width() * DEFAULT_SCALE > b->Left() &&
			a->Top() < b->Top() + b->Height() * DEFAULT_SCALE &&
			a->Top() + a->Height() * DEFAULT_SCALE > b->Top())
		{
			a->SetCollisionBottom(true);
			if (a->Left() < b->Left() + b->Width() * DEFAULT_SCALE && a->Left() + a->Width() * DEFAULT_SCALE > b->Left()) {
				a->SetCollisionRight(true);
				b->SetCollisionLeft(true);
			}
			else {
				a->SetCollisionLeft(true);
				b->SetCollisionRight(true);
			}

			if (a->Top() < b->Top() + b->Height() * DEFAULT_SCALE && a->Top() + a->Height() * DEFAULT_SCALE > b->Top()) {
				a->SetCollisionBottom(true);
				b->SetCollisionTop(true);
			}
			else {
				a->SetCollisionTop(true);
				b->SetCollisionBottom(true);
			}
		}*/
		
	}



	// Ladybug
	Ladybug::Ladybug(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Ladybug::OnInit() {
		texture.AddBitmap(ENEMY_LADYBUG_1);
		texture.AddBitmap(ENEMY_LADYBUG_2);
		texture.AddBitmap(ENEMY_LADYBUG_3);
		texture.SetDelayCount(3);
		setTopLeft(posX, posY);
	}

	void Ladybug::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			posY += 10;
		else {
			// 方向檢查
			if (isCollisingLeft || isCollisingRight)
				direction = !direction;

			// 移動
			if (direction == true) 
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;


		setTopLeft(posX, posY);
		texture.OnMove();
		

		//// 碰撞檢查
		//if () {

		//}

		//// 死亡檢查
		//if () {

		//}

		
	}

	void Ladybug::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Fly
	Fly::Fly(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Fly::OnInit() {
		texture.AddBitmap(ENEMY_FLY_1);
		texture.AddBitmap(ENEMY_FLY_2);
		texture.SetDelayCount(3);
		setTopLeft(posX, posY);
	}

	void Fly::OnMove() {
		/*TRACE("Left: %d\n", this->isCollisingLeft);
		TRACE("Right: %d\n", this->isCollisingRight);
		TRACE("Top: %d\n", this->isCollisingTop);
		TRACE("Bottom: %d\n", this->isCollisingBottom);*/

		// 落地檢查
		if (!isCollisingBottom)
			posY += 10;
		else {
			// 方向檢查
			if (isCollisingLeft || isCollisingRight)
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Fly::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Bamboo
	Bamboo::Bamboo(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Bamboo::OnInit() {
		texture.AddBitmap(ENEMY_BAMBOO_1);
		texture.AddBitmap(ENEMY_BAMBOO_2);
		texture.AddBitmap(ENEMY_BAMBOO_3);
		texture.AddBitmap(ENEMY_BAMBOO_4);
		texture.SetDelayCount(3);
		setTopLeft(posX, posY);
	}

	void Bamboo::OnMove() {
		

		// 落地檢查
		if (!isCollisingBottom)
			posY += 10;
		else {
			// 方向檢查
			if (isCollisingLeft || isCollisingRight)
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Bamboo::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Spider
	Spider::Spider(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Spider::OnInit() {
		texture.AddBitmap(ENEMY_SPIDER_1);
		texture.AddBitmap(ENEMY_SPIDER_2);
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Spider::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			posY += 10;
		else {
			// 方向檢查
			if (isCollisingLeft || isCollisingRight)
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Spider::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Rocket
	Rocket::Rocket(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Rocket::OnInit() {
		texture.AddBitmap(ENEMY_ROCKET_1);
		texture.AddBitmap(ENEMY_ROCKET_2);
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Rocket::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			posY += 10;
		else {
			// 方向檢查
			if (isCollisingLeft || isCollisingRight)
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Rocket::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Shark
	Shark::Shark(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Shark::OnInit() {
		texture.AddBitmap(ENEMY_SHARK_1);
		texture.AddBitmap(ENEMY_SHARK_2);
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Shark::OnMove() {
		// 落地檢查
		//if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
		//	posY += 10;
		//else {
		//	// 方向檢查
		//	if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
		//		direction = !direction;

		//	// 移動
		//	if (direction == true) 
		//		posX += 5;
		//	else if (direction == false)
		//		posX -= 5;

		//}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Shark::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Mosquito
	Mosquito::Mosquito(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Mosquito::OnInit() {
		texture.AddBitmap(ENEMY_MOSQUITO_1);
		texture.AddBitmap(ENEMY_MOSQUITO_2);
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Mosquito::OnMove() {
		// 落地檢查
		//if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
		//	posY += 10;
		//else {
		//	// 方向檢查
		//	if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
		//		direction = !direction;

		//	// 移動
		//	if (direction == true) 
		//		posX += 5;
		//	else if (direction == false)
		//		posX -= 5;

		//}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Mosquito::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Groundhog
	Groundhog::Groundhog(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Groundhog::OnInit() {
		texture.AddBitmap(ENEMY_GROUNDHOG_1);
		texture.AddBitmap(ENEMY_GROUNDHOG_2);
		texture.AddBitmap(ENEMY_GROUNDHOG_3);
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Groundhog::OnMove() {
		// 落地檢查
		//if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
		//	posY += 10;
		//else {
		//	// 方向檢查
		//	if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
		//		direction = !direction;

		//	// 移動
		//	if (direction == true) 
		//		posX += 5;
		//	else if (direction == false)
		//		posX -= 5;

		//}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Groundhog::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Red
	Red::Red(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Red::OnInit() {
		texture.AddBitmap(ENEMY_RED_1);
		texture.AddBitmap(ENEMY_RED_2);
		texture.AddBitmap(ENEMY_RED_3);
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Red::OnMove() {
		// 落地檢查
		//if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
		//	posY += 10;
		//else {
		//	// 方向檢查
		//	if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
		//		direction = !direction;

		//	// 移動
		//	if (direction == true) 
		//		posX += 5;
		//	else if (direction == false)
		//		posX -= 5;

		//}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Red::OnShow(int scale) {
		texture.OnShow(scale);
	}


	// Chef
	Chef::Chef(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Chef::OnInit() {
		texture.AddBitmap(ENEMY_CHEF_1);
		texture.AddBitmap(ENEMY_CHEF_2);
		texture.AddBitmap(ENEMY_CHEF_3);
	}

	void Chef::OnMove() {
		// 落地檢查
		//if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
		//	posY += 10;
		//else {
		//	// 方向檢查
		//	if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
		//		direction = !direction;

		//	// 移動
		//	if (direction == true) 
		//		posX += 5;
		//	else if (direction == false)
		//		posX -= 5;

		//}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Chef::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Earthworm
	Earthworm::Earthworm(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Earthworm::OnInit() {
		texture.AddBitmap(ENEMY_EARTHWORM_1);
		texture.AddBitmap(ENEMY_EARTHWORM_2);
	}

	void Earthworm::OnMove() {
		// 落地檢查
		//if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
		//	posY += 10;
		//else {
		//	// 方向檢查
		//	if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
		//		direction = !direction;

		//	// 移動
		//	if (direction == true) 
		//		posX += 5;
		//	else if (direction == false)
		//		posX -= 5;

		//}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Earthworm::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Insect
	Insect::Insect(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Insect::OnInit() {
		texture.AddBitmap(ENEMY_INSECT_1, RGB(0,128,128));
		texture.AddBitmap(ENEMY_INSECT_2, RGB(0,128,128));
		texture.AddBitmap(ENEMY_INSECT_3, RGB(0,128,128));
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Insect::OnMove() {
		// 落地檢查
		//if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
		//	posY += 10;
		//else {
		//	// 方向檢查
		//	if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
		//		direction = !direction;

		//	// 移動
		//	if (direction == true) 
		//		posX += 5;
		//	else if (direction == false)
		//		posX -= 5;

		//}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Insect::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Penguin
	Penguin::Penguin(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Penguin::OnInit() {
		texture.AddBitmap(IDB_BITMAP127);
		texture.AddBitmap(IDB_BITMAP128);
		texture.AddBitmap(IDB_BITMAP129);
		texture.AddBitmap(IDB_BITMAP130);
		texture.AddBitmap(IDB_BITMAP131);
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Penguin::OnMove() {
		// 落地檢查
		//if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
		//	posY += 10;
		//else {
		//	// 方向檢查
		//	if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
		//		direction = !direction;

		//	// 移動
		//	if (direction == true) 
		//		posX += 5;
		//	else if (direction == false)
		//		posX -= 5;

		//}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Penguin::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// PinkMonster
	PinkMonster::PinkMonster(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void PinkMonster::OnInit() {
		texture.AddBitmap(IDB_BITMAP132, RGB(0,128,64));
		texture.AddBitmap(IDB_BITMAP133, RGB(0,128,64));
		texture.AddBitmap(IDB_BITMAP134, RGB(0,128,64));
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void PinkMonster::OnMove() {
		// 落地檢查
		//if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
		//	posY += 10;
		//else {
		//	// 方向檢查
		//	if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
		//		direction = !direction;

		//	// 移動
		//	if (direction == true) 
		//		posX += 5;
		//	else if (direction == false)
		//		posX -= 5;

		//}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void PinkMonster::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Snails
	Snails::Snails(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Snails::OnInit() {
		texture.AddBitmap(IDB_BITMAP139, RGB(0,128,64));
		texture.AddBitmap(IDB_BITMAP140, RGB(0,128,64));
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Snails::OnMove() {
		// 落地檢查
		//if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
		//	posY += 10;
		//else {
		//	// 方向檢查
		//	if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
		//		direction = !direction;

		//	// 移動
		//	if (direction == true) 
		//		posX += 5;
		//	else if (direction == false)
		//		posX -= 5;

		//}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Snails::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Blue
	Blue::Blue(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Blue::OnInit() {
		texture.AddBitmap(IDB_BITMAP143);
		texture.AddBitmap(IDB_BITMAP144);
		texture.AddBitmap(IDB_BITMAP145);
		texture.AddBitmap(IDB_BITMAP146);
		texture.AddBitmap(IDB_BITMAP147);
		texture.AddBitmap(IDB_BITMAP148);
		texture.AddBitmap(IDB_BITMAP149);
		texture.AddBitmap(IDB_BITMAP150);
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Blue::OnMove() {
		// 落地檢查
		//if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
		//	posY += 10;
		//else {
		//	// 方向檢查
		//	if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
		//		direction = !direction;

		//	// 移動
		//	if (direction == true) 
		//		posX += 5;
		//	else if (direction == false)
		//		posX -= 5;

		//}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Blue::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// FlyShield
	FlyShield::FlyShield(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void FlyShield::OnInit() {
		texture.AddBitmap(IDB_BITMAP151, RGB(0,128,128));
		texture.AddBitmap(IDB_BITMAP152, RGB(0,128,128));
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void FlyShield::OnMove() {
		// 落地檢查
		//if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
		//	posY += 10;
		//else {
		//	// 方向檢查
		//	if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
		//		direction = !direction;

		//	// 移動
		//	if (direction == true) 
		//		posX += 5;
		//	else if (direction == false)
		//		posX -= 5;

		//}

		if (isMovingLeft)
			posX += maxSpeed;
		if (isMovingRight)
			posX -= maxSpeed;
		if (isMovingUp)
			posY += maxSpeed;
		if (isMovingDown)
			posY -= maxSpeed;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void FlyShield::OnShow(int scale) {
		texture.OnShow(scale);
	}

}
