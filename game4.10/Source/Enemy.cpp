#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Enemy.h"
#include "Level.h"


namespace game_framework {
	// Enemy
	Enemy::Enemy(int x, int y, int ang) {
		pos.x = x;
		pos.y = y;
		spawn = pos;
		angle = ang;
		speed = 5;
		cameraSpeed = 50;
		movingRange = 100;
		refBrick = nullptr;

		direction = false;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isCollisingLeft = isCollisingRight = isCollisingTop = isCollisingBottom = false;

	}

	void Enemy::setTopLeft(POINT xy) {
		pos.x = xy.x;
		pos.y = xy.y;
		texture.SetTopLeft(xy.x, xy.y);
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
		
		/*int Woffset = (int)((this->Left() + this->Width() * DEFAULT_SCALE) * 0.05);
		int Hoffset = (int)((this->Top() + this->Height() * DEFAULT_SCALE) * 0.05);*/
		int Woffset = 1;
		int Hoffset = 1;

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

	void Enemy::LookingForRefBrick() {
	
		/*const int bs = bricks.size();

		do {
			for (int b = 0; b < bs; b++) {
				if (CollisionDetection(bricks.at(b))) {
					this->refBrick = bricks.at(b);
					break;
				}
			}

			if (this->refBrick == nullptr) spawn.y++;
		} while (this->refBrick == nullptr);*/

		
		

	}

	// Ladybug
	Ladybug::Ladybug(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Ladybug::OnInit(vector<Brick*> b) {
		texture.AddBitmap(ENEMY_LADYBUG_1);
		texture.AddBitmap(ENEMY_LADYBUG_2);
		texture.AddBitmap(ENEMY_LADYBUG_3);
		texture.SetDelayCount(3);

		LookingForRefBrick();

		setTopLeft(spawn);
	}

	void Ladybug::OnMove() {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			} 
			if (pos.x < spawn.x - movingRange){
				direction = !direction;
				pos.x += speed;
			}
				

			// 移動
			if (direction == true) 
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;



		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
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

	void Fly::OnInit(vector<Brick*>) {
		texture.AddBitmap(ENEMY_FLY_1);
		texture.AddBitmap(ENEMY_FLY_2);
		texture.SetDelayCount(3);
		setTopLeft(pos);
	}

	void Fly::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
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
		setTopLeft(pos);
	}

	void Bamboo::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
		texture.OnMove();
	}

	void Bamboo::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Spider
	Spider::Spider(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Spider::OnInit(vector<Brick*>) {
		texture.AddBitmap(ENEMY_SPIDER_1);
		texture.AddBitmap(ENEMY_SPIDER_2);
		texture.SetDelayCount(3);
		setTopLeft(pos);
	}

	void Spider::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
		texture.OnMove();
	}

	void Spider::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Rocket
	Rocket::Rocket(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Rocket::OnInit(vector<Brick*>) {
		texture.AddBitmap(ENEMY_ROCKET_1);
		texture.AddBitmap(ENEMY_ROCKET_2);
		texture.SetDelayCount(3);
		setTopLeft(pos);
	}

	void Rocket::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
		texture.OnMove();
	}

	void Rocket::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Shark
	Shark::Shark(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Shark::OnInit(vector<Brick*>) {
		texture.AddBitmap(ENEMY_SHARK_1);
		texture.AddBitmap(ENEMY_SHARK_2);
		texture.SetDelayCount(3);
		setTopLeft(pos);
	}

	void Shark::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
		texture.OnMove();
	}

	void Shark::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Mosquito
	Mosquito::Mosquito(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Mosquito::OnInit(vector<Brick*>) {
		texture.AddBitmap(ENEMY_MOSQUITO_1);
		texture.AddBitmap(ENEMY_MOSQUITO_2);
		texture.SetDelayCount(3);
		setTopLeft(pos);
	}

	void Mosquito::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
		texture.OnMove();
	}

	void Mosquito::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Groundhog
	Groundhog::Groundhog(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Groundhog::OnInit(vector<Brick*>) {
		texture.AddBitmap(ENEMY_GROUNDHOG_1);
		texture.AddBitmap(ENEMY_GROUNDHOG_2);
		texture.AddBitmap(ENEMY_GROUNDHOG_3);
		texture.SetDelayCount(3);
		setTopLeft(pos);
	}

	void Groundhog::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
		texture.OnMove();
	}

	void Groundhog::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Red
	Red::Red(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Red::OnInit(vector<Brick*>) {
		texture.AddBitmap(ENEMY_RED_1);
		texture.AddBitmap(ENEMY_RED_2);
		texture.AddBitmap(ENEMY_RED_3);
		texture.SetDelayCount(3);
		setTopLeft(pos);
	}

	void Red::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
		texture.OnMove();
	}

	void Red::OnShow(int scale) {
		texture.OnShow(scale);
	}


	// Chef
	Chef::Chef(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Chef::OnInit(vector<Brick*>) {
		texture.AddBitmap(ENEMY_CHEF_1);
		texture.AddBitmap(ENEMY_CHEF_2);
		texture.AddBitmap(ENEMY_CHEF_3);
	}

	void Chef::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
		texture.OnMove();
	}

	void Chef::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Earthworm
	Earthworm::Earthworm(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Earthworm::OnInit(vector<Brick*>) {
		texture.AddBitmap(ENEMY_EARTHWORM_1);
		texture.AddBitmap(ENEMY_EARTHWORM_2);
	}

	void Earthworm::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
		texture.OnMove();
	}

	void Earthworm::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Insect
	Insect::Insect(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Insect::OnInit(vector<Brick*>) {
		texture.AddBitmap(ENEMY_INSECT_1, RGB(0,128,128));
		texture.AddBitmap(ENEMY_INSECT_2, RGB(0,128,128));
		texture.AddBitmap(ENEMY_INSECT_3, RGB(0,128,128));
		texture.SetDelayCount(3);
		setTopLeft(pos);
	}

	void Insect::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
		texture.OnMove();
	}

	void Insect::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Penguin
	Penguin::Penguin(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Penguin::OnInit(vector<Brick*>) {
		texture.AddBitmap(IDB_BITMAP127);
		texture.AddBitmap(IDB_BITMAP128);
		texture.AddBitmap(IDB_BITMAP129);
		texture.AddBitmap(IDB_BITMAP130);
		texture.AddBitmap(IDB_BITMAP131);
		texture.SetDelayCount(3);
		setTopLeft(pos);
	}

	void Penguin::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
		texture.OnMove();
	}

	void Penguin::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// PinkMonster
	PinkMonster::PinkMonster(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void PinkMonster::OnInit(vector<Brick*>) {
		texture.AddBitmap(IDB_BITMAP132, RGB(0,128,64));
		texture.AddBitmap(IDB_BITMAP133, RGB(0,128,64));
		texture.AddBitmap(IDB_BITMAP134, RGB(0,128,64));
		texture.SetDelayCount(3);
		setTopLeft(pos);
	}

	void PinkMonster::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
		texture.OnMove();
	}

	void PinkMonster::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Snails
	Snails::Snails(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Snails::OnInit(vector<Brick*>) {
		texture.AddBitmap(IDB_BITMAP139, RGB(0,128,64));
		texture.AddBitmap(IDB_BITMAP140, RGB(0,128,64));
		texture.SetDelayCount(3);
		setTopLeft(pos);
	}

	void Snails::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
		texture.OnMove();
	}

	void Snails::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Blue
	Blue::Blue(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Blue::OnInit(vector<Brick*>) {
		texture.AddBitmap(IDB_BITMAP143);
		texture.AddBitmap(IDB_BITMAP144);
		texture.AddBitmap(IDB_BITMAP145);
		texture.AddBitmap(IDB_BITMAP146);
		texture.AddBitmap(IDB_BITMAP147);
		texture.AddBitmap(IDB_BITMAP148);
		texture.AddBitmap(IDB_BITMAP149);
		texture.AddBitmap(IDB_BITMAP150);
		texture.SetDelayCount(3);
		setTopLeft(pos);
	}

	void Blue::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
		texture.OnMove();
	}

	void Blue::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// FlyShield
	FlyShield::FlyShield(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void FlyShield::OnInit(vector<Brick*>) {
		texture.AddBitmap(IDB_BITMAP151, RGB(0,128,128));
		texture.AddBitmap(IDB_BITMAP152, RGB(0,128,128));
		texture.SetDelayCount(3);
		setTopLeft(pos);
	}

	void FlyShield::OnMove() {
		// 落地檢查
		if (!isCollisingBottom)
			pos.y += 10;

		else {
			// 方向檢查
			if (pos.x > spawn.x + movingRange) {
				direction = !direction;
				pos.x -= speed;
			}
			if (pos.x < spawn.x - movingRange) {
				direction = !direction;
				pos.x += speed;
			}


			// 移動
			if (direction == true)
				pos.x += speed;
			else if (direction == false)
				pos.x -= speed;

		}

		if (isMovingLeft) {
			pos.x += cameraSpeed;
			spawn.x += cameraSpeed;
		}
		if (isMovingRight) {
			pos.x -= cameraSpeed;
			spawn.x -= cameraSpeed;
		}
		if (isMovingUp) {
			pos.y += cameraSpeed;
			spawn.y += cameraSpeed;
		}
		if (isMovingDown) {
			pos.y -= cameraSpeed;
			spawn.y -= cameraSpeed;
		}


		setTopLeft(pos);
		texture.OnMove();
	}

	void FlyShield::OnShow(int scale) {
		texture.OnShow(scale);
	}

}
