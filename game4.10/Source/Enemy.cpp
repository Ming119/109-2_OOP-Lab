#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Enemy.h"
#include "Level.h"


namespace game_framework {

	/* Constructor */
	Enemy::Enemy(int x, int y) {
		pos.x = x;
		pos.y = y;
		angle = 0;
		spawn = pos;
		speed = 4;
		refBrick = nullptr;
		delta = POINT();
		direction = false;
	}

	/* Getter */
	int Enemy::Angle() { return angle; }

	int Enemy::Height() { return texture.Height() * DEFAULT_SCALE; }

	int Enemy::Width() { return texture.Width() * DEFAULT_SCALE; }

	int Enemy::Top() { return texture.Top(); }

	int Enemy::Left() { return texture.Left(); }

	int Enemy::Bottom() { return this->Top() + this->Height(); }

	int Enemy::Right() { return this->Left() + this->Width(); }

	/* Setter */
	void Enemy::SetAngle(int a) { angle = a; }

	void Enemy::SetSpeed(int s) { speed = s; }

	void Enemy::SetMoving(POINT _delta) { delta = _delta; }

	void Enemy::SetTopLeft(int x, int y) {
		pos.x = x;
		pos.y = y;

		texture.SetTopLeft(pos.x, pos.y);
	}

	void Enemy::SetTopLeft(POINT xy) {
		pos = xy;
		texture.SetTopLeft(pos.x, pos.y);
	}

	/* Member Function */
	void Enemy::CameraMovement() {
		pos.x -= delta.x;
		pos.y -= delta.y;
		spawn.x -= delta.x;
		spawn.y -= delta.y;
		SetTopLeft(pos);
	}

	bool Enemy::CollisionDetection(Brick* brick) {

		if (brick->Property() != OBSTACLE && brick->Property() != CLOUD) return false;

		if (this->Left() < brick->Right() &&
			this->Right() > brick->Left() &&
			this->Top() < brick->Bottom() &&
			this->Bottom() > brick->Top()) {
						
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
		
		SetTopLeft(spawn);
	}



	/* Inheritance Enemy Class */

	// Ladybug
	Ladybug::Ladybug(int x, int y) : Enemy::Enemy(x, y) {}

	void Ladybug::OnInit(vector<Brick*> b) {
		texture.AddBitmap(ENEMY_LADYBUG_1);
		texture.AddBitmap(ENEMY_LADYBUG_2);
		texture.AddBitmap(ENEMY_LADYBUG_3);
		texture.SetDelayCount(3);
		SetTopLeft(spawn);

		LookingForRefBrick(b);
	}

	void Ladybug::OnMove() {
		CameraMovement();

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

		SetTopLeft(pos);
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
		SetTopLeft(spawn);
	}

	void Fly::OnMove() {
		CameraMovement();

		if (pos.y >= spawn.y + Height()) {
			direction = !direction;
			pos.y -= speed;
		}
		if (pos.y <= spawn.y - Height()) {
			direction = !direction;
			pos.y += speed;
		}

		if (direction)
			pos.y -= speed;
		else
			pos.y += speed;

		SetTopLeft(pos);
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
		SetTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Bamboo::OnMove() {
		CameraMovement();

		if ((pos.y + Height()) >= refBrick->Top()) {
			direction = !direction;
			pos.y -= speed;
		}
		if (pos.y <= spawn.y - Height()) {
			direction = !direction;
			pos.y += speed;
		}

		if (direction)
			pos.y -= speed;
		else
			pos.y += speed;
		
		SetTopLeft(pos);
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
		SetTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Spider::OnMove() {
		CameraMovement();

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

		SetTopLeft(pos);
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
		SetTopLeft(spawn);
		LookingForRefBrick(b);
		SetTopLeft(spawn.x, spawn.y - 25);
	}

	void Rocket::OnMove() {
		CameraMovement();

		if (pos.x <= refBrick->Left()) {
			direction = !direction;
			pos.x += speed;
		}
		if ((pos.x + Width()) >= refBrick->Right()) {
			direction = !direction;
			pos.x -= speed;
		}

		if (direction)
			pos.x += speed;
		else
			pos.x -= speed;

		SetTopLeft(pos);
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
		SetTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Shark::OnMove() {
		CameraMovement();

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

		SetTopLeft(pos);
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
		SetTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Mosquito::OnMove() {
		CameraMovement();

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

		SetTopLeft(pos);
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
		SetTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Groundhog::OnMove() {
		CameraMovement();

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

		SetTopLeft(pos);
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
		SetTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Red::OnMove() {
		CameraMovement();

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

		SetTopLeft(pos);
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
		SetTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Chef::OnMove() {
		CameraMovement();

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

		SetTopLeft(pos);
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
		SetTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Earthworm::OnMove() {
		CameraMovement();

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

		SetTopLeft(pos);
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
		SetTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Insect::OnMove() {
		CameraMovement();

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


		SetTopLeft(pos);
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
		SetTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Penguin::OnMove() {
		CameraMovement();

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


		SetTopLeft(pos);
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
		SetTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void PinkMonster::OnMove() {
		CameraMovement();

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

		SetTopLeft(pos);
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
		SetTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Snails::OnMove() {
		CameraMovement();

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

		SetTopLeft(pos);
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
		SetTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void Blue::OnMove() {
		CameraMovement();

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

		SetTopLeft(pos);
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
		SetTopLeft(spawn);
		LookingForRefBrick(b);
	}

	void FlyShield::OnMove() {
		CameraMovement();

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

		SetTopLeft(pos);
		texture.OnMove();
	}

	void FlyShield::OnShow(int scale) {
		texture.OnShow(scale);
	}
}
