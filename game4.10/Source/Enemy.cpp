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
	Enemy::Enemy(int x, int y) {
		pos.x = x;
		pos.y = y;
		angle = 0;
		spawn = pos;
		speed = 4;
		cameraSpeed = 50;
		movingRange = 100;
		refBrick = nullptr;

		delta = POINT();

		direction = false;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isCollisingLeft = isCollisingRight = isCollisingTop = isCollisingBottom = false;

	}

	int Enemy::Angle() { return angle; }

	int Enemy::Height() { return texture.Height() * DEFAULT_SCALE; }

	int Enemy::Width() { return texture.Width() * DEFAULT_SCALE; }

	int Enemy::Top() { return texture.Top(); }

	int Enemy::Left() { return texture.Left(); }

	int Enemy::Buttom() { return this->Top() + this->Height(); }

	int Enemy::Right() { return this->Left() + this->Width(); }


	void Enemy::setTopLeft(POINT xy) {
		pos = xy;
		texture.SetTopLeft(pos.x, pos.y);
	}

	void Enemy::setTopLeft(int x, int y) {
		pos.x = x;
		pos.y = y;
		texture.SetTopLeft(pos.x, pos.y);
	}

	void Enemy::setAngle(int ang) { angle = ang; }

	void Enemy::SetMoveLeft(bool m) { isMovingLeft = m; }

	void Enemy::SetMoveRight(bool m) { isMovingRight = m; }

	void Enemy::SetMoveUp(bool m) { isMovingUp = m; }

	void Enemy::SetMoveDown(bool m) { isMovingDown = m; }
	
	void Enemy::SetMoving(POINT _delta) { delta = _delta; }

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

	void Enemy::CameraMove() {
		// Camera Move
		pos.x -= delta.x;
		pos.y += delta.y;
		
		/*if (isMovingLeft) {
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
		}*/

		setTopLeft(pos);
	}

	bool Enemy::CollisionDetection(Brick* brick) {

		if (brick->Property() != OBSTACLE && brick->Property() != CLOUD) return false;
		
		/*int Woffset = (int)((this->Left() + this->Width() * DEFAULT_SCALE) * 0.05);
		int Hoffset = (int)((this->Top() + this->Height() * DEFAULT_SCALE) * 0.05);*/
		int Woffset = 1;
		int Hoffset = 1;

		if ((this->Left()+Woffset) < (brick->Left() + brick->Width() * DEFAULT_SCALE)-Woffset &&
			(this->Left() + this->Width() * DEFAULT_SCALE)-Woffset > (brick->Left()+Woffset) &&
			(this->Top()+Hoffset) < (brick->Top() + brick->Height() * DEFAULT_SCALE)-Hoffset &&
			(this->Top() + this->Height() * DEFAULT_SCALE)-Hoffset > (brick->Top()+Hoffset)) {
			
			this->SetCollisionBottom(true);
			
			return true;
		}
		return false;
			
	}

	void Enemy::LookingForRefBrick(vector<Brick*> bricks) {

		const int bs = bricks.size();

		for (int b = 0; b < bs; b++) {
			if (CollisionDetection(bricks.at(b))) {
				this->refBrick = bricks.at(b);
				spawn.y -= (spawn.y + Height()) - refBrick->Top();
				break;
			}
		}
		
		setTopLeft(spawn);
			
	}

	// Ladybug
	Ladybug::Ladybug(int x, int y) : Enemy::Enemy(x, y) {}

	void Ladybug::OnInit(vector<Brick*> b) {
		texture.AddBitmap(ENEMY_LADYBUG_1);
		texture.AddBitmap(ENEMY_LADYBUG_2);
		texture.AddBitmap(ENEMY_LADYBUG_3);
		texture.SetDelayCount(3);
		setTopLeft(spawn);

		LookingForRefBrick(b);
	}

	void Ladybug::OnMove() {
		CameraMove();

		if (pos.x <= refBrick->Left()) {
			direction = !direction;
			pos.x += speed;
		}
		if (pos.x + Width() >= refBrick->Right()) {
			direction = !direction;
			pos.x -= speed;
		}	

		if (direction)
			pos.x += speed;
		else
			pos.x -= speed;

		setTopLeft(pos);
		texture.OnMove();
	}

	void Ladybug::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Fly
	Fly::Fly(int x, int y) : Enemy::Enemy(x, y) {}

	void Fly::OnInit(vector<Brick*> b) {
		texture.AddBitmap(ENEMY_FLY_1);
		texture.AddBitmap(ENEMY_FLY_2);
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Fly::OnMove() {
		CameraMove();

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

		setTopLeft(pos);
		texture.OnMove();
	}

	void Fly::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Bamboo
	Bamboo::Bamboo(int x, int y) : Enemy::Enemy(x, y) {}

	void Bamboo::OnInit(vector<Brick*> b) {
		texture.AddBitmap(ENEMY_BAMBOO_1);
		texture.AddBitmap(ENEMY_BAMBOO_2);
		texture.AddBitmap(ENEMY_BAMBOO_3);
		texture.AddBitmap(ENEMY_BAMBOO_4);
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Bamboo::OnMove() {
		CameraMove();

		if ((pos.y + Height() * DEFAULT_SCALE) >= refBrick->Top()) {
			direction = !direction;
			pos.y -= speed;
		}
		if (pos.y <= (spawn.y - Height()*DEFAULT_SCALE)) {
			direction = !direction;
			pos.y += speed;
		}

		if (direction)
			pos.y -= speed;
		else
			pos.y += speed;

		setTopLeft(pos);
		texture.OnMove();
	}

	void Bamboo::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Spider
	Spider::Spider(int x, int y) : Enemy::Enemy(x, y) {}

	void Spider::OnInit(vector<Brick*> b) {
		texture.AddBitmap(ENEMY_SPIDER_1);
		texture.AddBitmap(ENEMY_SPIDER_2);
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Spider::OnMove() {
		CameraMove();

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

		setTopLeft(pos);
		texture.OnMove();
	}

	void Spider::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Rocket
	Rocket::Rocket(int x, int y) : Enemy::Enemy(x, y) {}

	void Rocket::OnInit(vector<Brick*> b) {
		texture.AddBitmap(ENEMY_ROCKET_1);
		texture.AddBitmap(ENEMY_ROCKET_2);
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
		setTopLeft(spawn.x, spawn.y - 25);
	}

	void Rocket::OnMove() {
		if (pos.x <= refBrick->Left()) {
			direction = !direction;
			pos.x += speed;
		}
		if ((pos.x + Width() * DEFAULT_SCALE) >= (refBrick->Left() + refBrick->Width() * DEFAULT_SCALE)) {
			direction = !direction;
			pos.x -= speed;
		}

		if (direction)
			pos.x += speed;
		else
			pos.x -= speed;



		pos.x -= delta.x;
		// Camera Move
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
	Shark::Shark(int x, int y) : Enemy::Enemy(x, y) {}

	void Shark::OnInit(vector<Brick*> b) {
		texture.AddBitmap(ENEMY_SHARK_1);
		texture.AddBitmap(ENEMY_SHARK_2);
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Shark::OnMove() {
		CameraMove();

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

		setTopLeft(pos);
		texture.OnMove();
	}

	void Shark::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Mosquito
	Mosquito::Mosquito(int x, int y) : Enemy::Enemy(x, y) {}

	void Mosquito::OnInit(vector<Brick*> b) {
		texture.AddBitmap(ENEMY_MOSQUITO_1);
		texture.AddBitmap(ENEMY_MOSQUITO_2);
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Mosquito::OnMove() {
		CameraMove();

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

		setTopLeft(pos);
		texture.OnMove();
	}

	void Mosquito::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Groundhog
	Groundhog::Groundhog(int x, int y) : Enemy::Enemy(x, y) {}

	void Groundhog::OnInit(vector<Brick*> b) {
		texture.AddBitmap(ENEMY_GROUNDHOG_1);
		texture.AddBitmap(ENEMY_GROUNDHOG_2);
		texture.AddBitmap(ENEMY_GROUNDHOG_3);
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Groundhog::OnMove() {
		CameraMove();

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

		setTopLeft(pos);
		texture.OnMove();
	}

	void Groundhog::OnShow(int scale) {
		texture.OnShow(scale);
	}



	// Red
	Red::Red(int x, int y) : Enemy::Enemy(x, y) {}

	void Red::OnInit(vector<Brick*> b) {
		texture.AddBitmap(ENEMY_RED_1);
		texture.AddBitmap(ENEMY_RED_2);
		texture.AddBitmap(ENEMY_RED_3);
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
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

		pos.x -= delta.x;
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
	Chef::Chef(int x, int y) : Enemy::Enemy(x, y) {}

	void Chef::OnInit(vector<Brick*> b) {
		texture.AddBitmap(ENEMY_CHEF_1);
		texture.AddBitmap(ENEMY_CHEF_2);
		texture.AddBitmap(ENEMY_CHEF_3);
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
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

		pos.x -= delta.x;
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
	Earthworm::Earthworm(int x, int y) : Enemy::Enemy(x, y) {}

	void Earthworm::OnInit(vector<Brick*> b) {
		texture.AddBitmap(ENEMY_EARTHWORM_1);
		texture.AddBitmap(ENEMY_EARTHWORM_2);
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
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

		pos.x -= delta.x;
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
	Insect::Insect(int x, int y) : Enemy::Enemy(x, y) {}

	void Insect::OnInit(vector<Brick*> b) {
		texture.AddBitmap(ENEMY_INSECT_1, RGB(0,128,128));
		texture.AddBitmap(ENEMY_INSECT_2, RGB(0,128,128));
		texture.AddBitmap(ENEMY_INSECT_3, RGB(0,128,128));
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
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

		pos.x -= delta.x;
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
	Penguin::Penguin(int x, int y) : Enemy::Enemy(x, y) {}

	void Penguin::OnInit(vector<Brick*> b) {
		texture.AddBitmap(IDB_BITMAP127);
		texture.AddBitmap(IDB_BITMAP128);
		texture.AddBitmap(IDB_BITMAP129);
		texture.AddBitmap(IDB_BITMAP130);
		texture.AddBitmap(IDB_BITMAP131);
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
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

		pos.x -= delta.x;
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
	PinkMonster::PinkMonster(int x, int y) : Enemy::Enemy(x, y) {}

	void PinkMonster::OnInit(vector<Brick*> b) {
		texture.AddBitmap(IDB_BITMAP132, RGB(0,128,64));
		texture.AddBitmap(IDB_BITMAP133, RGB(0,128,64));
		texture.AddBitmap(IDB_BITMAP134, RGB(0,128,64));
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
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
		
		pos.x -= delta.x;
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
	Snails::Snails(int x, int y) : Enemy::Enemy(x, y) {}

	void Snails::OnInit(vector<Brick*> b) {
		texture.AddBitmap(IDB_BITMAP139, RGB(0,128,64));
		texture.AddBitmap(IDB_BITMAP140, RGB(0,128,64));
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
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

		pos.x -= delta.x;
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
	Blue::Blue(int x, int y) : Enemy::Enemy(x, y) {}

	void Blue::OnInit(vector<Brick*> b) {
		texture.AddBitmap(IDB_BITMAP143);
		texture.AddBitmap(IDB_BITMAP144);
		texture.AddBitmap(IDB_BITMAP145);
		texture.AddBitmap(IDB_BITMAP146);
		texture.AddBitmap(IDB_BITMAP147);
		texture.AddBitmap(IDB_BITMAP148);
		texture.AddBitmap(IDB_BITMAP149);
		texture.AddBitmap(IDB_BITMAP150);
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
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

		pos.x -= delta.x;
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
	FlyShield::FlyShield(int x, int y) : Enemy::Enemy(x, y) {}

	void FlyShield::OnInit(vector<Brick*> b) {
		texture.AddBitmap(IDB_BITMAP151, RGB(0,128,128));
		texture.AddBitmap(IDB_BITMAP152, RGB(0,128,128));
		texture.SetDelayCount(3);
		setTopLeft(spawn);
		LookingForRefBrick(b);
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

		pos.x -= delta.x;
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
