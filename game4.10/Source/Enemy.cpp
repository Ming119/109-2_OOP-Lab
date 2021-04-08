#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Enemy.h"

namespace game_framework {
	// Enemy
	Enemy::Enemy() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Enemy::Enemy(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;

		direction = false;
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

	void Enemy::OnMove() {
		//// 落地檢查
		//if () {

		//}

		// 方向檢查
		if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE)) {
			direction = !direction;
		}

		//// 碰撞檢查
		//if () {

		//}

		//// 死亡檢查
		//if () {

		//}


		// 移動
		if (direction == true)
			posX += 5;
		else if (direction == false)
			posX -= 5;

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Enemy::OnShow() {
		if (!direction)
			texture.OnShow(DEFAULT_SCALE, true);
		else
			texture.OnShow();
	}


	//void Enemy::getEnemiesData(int (&array)[][MAX_ENEMY_SIZE][3]) {
	//	for (int i = 0; i < static_cast<int>(LEVELS::COUNT); ++i)
	//		for (int j = 0; j < MAX_ENEMY_SIZE; ++j)
	//			for (int k = 0; k < 3; k++) 
	//				array[i][j][k] = enemiesData[i][j][k];
	//}

	//void Enemy::getEnemiesData(int (&array)[][3], int level) {
	//	for (int i = 0; i < MAX_ENEMY_SIZE; ++i)
	//		for (int j = 0; j < 3; ++j)
	//			array[i][j] = enemiesData[level][i][j];
	//}



	// Ladybug
	Ladybug::Ladybug() : Enemy::Enemy() {}

	Ladybug::Ladybug(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Ladybug::OnInit() {
		texture.AddBitmap(IDB_BITMAP122);
		texture.AddBitmap(IDB_BITMAP123);
		texture.AddBitmap(IDB_BITMAP124);
		texture.SetDelayCount(3);
		setTopLeft(posX, posY);
	}

	void Ladybug::OnMove() {
		
		// 落地檢查
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true) 
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
		

		//// 碰撞檢查
		//if () {

		//}

		//// 死亡檢查
		//if () {

		//}

		
	}

	void Ladybug::OnShow() {
		texture.OnShow();
	}



	// Fly
	Fly::Fly() : Enemy::Enemy() {}

	Fly::Fly(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Fly::OnInit() {

	}

	void Fly::OnMove() {
		// 落地檢查
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Fly::OnShow() {


		texture.OnShow();
	}



	// Bamboo
	Bamboo::Bamboo() : Enemy::Enemy() {}

	Bamboo::Bamboo(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Bamboo::OnInit() {
		//texture.AddBitmap(IDB_BITMAP115);

	}

	void Bamboo::OnMove() {
		// 落地檢查
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Bamboo::OnShow() {
		texture.OnShow();
	}



	// Spider
	Spider::Spider() : Enemy::Enemy() {}

	Spider::Spider(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Spider::OnInit() {
		texture.AddBitmap(IDB_BITMAP141);
		texture.AddBitmap(IDB_BITMAP142);
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Spider::OnMove() {
		// 落地檢查
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Spider::OnShow() {
		texture.OnShow();
	}



	// Rocket
	Rocket::Rocket() : Enemy::Enemy() {}

	Rocket::Rocket(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Rocket::OnInit() {
		texture.AddBitmap(IDB_BITMAP135);
		texture.AddBitmap(IDB_BITMAP136);
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Rocket::OnMove() {
		// 落地檢查
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();;
	}

	void Rocket::OnShow() {
		texture.OnShow();
	}



	// Shark
	Shark::Shark() : Enemy::Enemy() {}

	Shark::Shark(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Shark::OnInit() {
		texture.AddBitmap(IDB_BITMAP137);
		texture.AddBitmap(IDB_BITMAP138);
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Shark::OnMove() {
		// 落地檢查
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Shark::OnShow() {
		texture.OnShow();
	}



	// Mosquito
	Mosquito::Mosquito() : Enemy::Enemy() {}

	Mosquito::Mosquito(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Mosquito::OnInit() {
		texture.AddBitmap(IDB_BITMAP125);
		texture.AddBitmap(IDB_BITMAP126);
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Mosquito::OnMove() {
		// 落地檢查
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Mosquito::OnShow() {
		texture.OnShow();
	}



	// Groundhog
	Groundhog::Groundhog() : Enemy::Enemy() {}

	Groundhog::Groundhog(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Groundhog::OnInit() {
		texture.AddBitmap(IDB_BITMAP116);
		texture.AddBitmap(IDB_BITMAP117);
		texture.AddBitmap(IDB_BITMAP118);
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Groundhog::OnMove() {
		// 落地檢查
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Groundhog::OnShow() {
		texture.OnShow();
	}



	// Red
	Red::Red() : Enemy::Enemy() {}

	Red::Red(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Red::OnInit() {
		texture.AddBitmap(IDB_BITMAP153);
		texture.AddBitmap(IDB_BITMAP154);
		texture.AddBitmap(IDB_BITMAP155);
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Red::OnMove() {
		// 落地檢查
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Red::OnShow() {
		texture.OnShow();
	}


	// Chef
	Chef::Chef() : Enemy::Enemy() {}

	Chef::Chef(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Chef::OnInit() {

	}

	void Chef::OnMove() {
		// 落地檢查
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Chef::OnShow() {
		texture.OnShow();
	}



	// Earthworm
	Earthworm::Earthworm() : Enemy::Enemy() {}

	Earthworm::Earthworm(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Earthworm::OnInit() {

	}

	void Earthworm::OnMove() {
		// 落地檢查
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Earthworm::OnShow() {
		texture.OnShow();
	}



	// Insect
	Insect::Insect() : Enemy::Enemy() {}

	Insect::Insect(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Insect::OnInit() {
		texture.AddBitmap(IDB_BITMAP119, RGB(0,128,128));
		texture.AddBitmap(IDB_BITMAP120, RGB(0,128,128));
		texture.AddBitmap(IDB_BITMAP121, RGB(0,128,128));
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Insect::OnMove() {
		// 落地檢查
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Insect::OnShow() {
		texture.OnShow();
	}



	// Penguin
	Penguin::Penguin() : Enemy::Enemy() {}

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
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Penguin::OnShow() {
		texture.OnShow();
	}



	// PinkMonster
	PinkMonster::PinkMonster() : Enemy::Enemy() {}

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
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void PinkMonster::OnShow() {
		texture.OnShow();
	}



	// Snails
	Snails::Snails() : Enemy::Enemy() {}

	Snails::Snails(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void Snails::OnInit() {
		texture.AddBitmap(IDB_BITMAP139, RGB(0,128,64));
		texture.AddBitmap(IDB_BITMAP140, RGB(0,128,64));
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Snails::OnMove() {
		// 落地檢查
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Snails::OnShow() {
		texture.OnShow();
	}



	// Blue
	Blue::Blue() : Enemy::Enemy() {}

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
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void Blue::OnShow() {
		texture.OnShow();
	}



	// FlyShield
	FlyShield::FlyShield() : Enemy::Enemy() {}

	FlyShield::FlyShield(int x, int y, int ang) : Enemy::Enemy(x, y, ang) {}

	void FlyShield::OnInit() {
		texture.AddBitmap(IDB_BITMAP151, RGB(0,128,128));
		texture.AddBitmap(IDB_BITMAP152, RGB(0,128,128));
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void FlyShield::OnMove() {
		// 落地檢查
		if (posY < SIZE_Y - (Height() * DEFAULT_SCALE))
			posY += 10;
		else {
			// 方向檢查
			if (posX < 0 || posX > SIZE_X - (Width() * DEFAULT_SCALE))
				direction = !direction;

			// 移動
			if (direction == true)
				posX += 5;
			else if (direction == false)
				posX -= 5;

		}

		setTopLeft(posX, posY);
		texture.OnMove();
	}

	void FlyShield::OnShow() {
		texture.OnShow();
	}

}
