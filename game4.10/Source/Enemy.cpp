#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Enemy.h"

namespace game_framework {
	// Enemy
	void Enemy::setPos(int x, int y) {
		posX = x;
		posY = y;
	}

	void Enemy::setAngle(int ang) {
		angle = ang;
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

	// Bamboo
	Bamboo::Bamboo() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Bamboo::Bamboo(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
	}

	void Bamboo::OnInit() {
		//texture.AddBitmap(IDB_BITMAP115);

	}

	void Bamboo::OnMove() {
		texture.OnMove();
	}

	void Bamboo::OnShow() {
		texture.OnShow();
	}



	// Chef
	Chef::Chef() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Chef::Chef(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
	}

	void Chef::OnInit() {

	}

	void Chef::OnMove() {
		texture.OnMove();
	}

	void Chef::OnShow() {
		texture.OnShow();
	}



	// Earthworm
	Earthworm::Earthworm() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Earthworm::Earthworm(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
	}

	void Earthworm::OnInit() {

	}

	void Earthworm::OnMove() {
		texture.OnMove();
	}

	void Earthworm::OnShow() {
		texture.OnShow();
	}



	// Fly
	Fly::Fly() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Fly::Fly(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
	}

	void Fly::OnInit() {

	}

	void Fly::OnMove() {
		texture.OnMove();
	}

	void Fly::OnShow() {
		texture.OnShow();
	}



	// Groundhog
	Groundhog::Groundhog() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Groundhog::Groundhog(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
	}

	void Groundhog::OnInit() {
		texture.AddBitmap(IDB_BITMAP116);
		texture.AddBitmap(IDB_BITMAP117);
		texture.AddBitmap(IDB_BITMAP118);
	}

	void Groundhog::OnMove() {
		texture.OnMove();
	}

	void Groundhog::OnShow() {
		texture.OnShow();
	}



	// Insect
	Insect::Insect() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Insect::Insect(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
	}

	void Insect::OnInit() {
		texture.AddBitmap(IDB_BITMAP119);
		texture.AddBitmap(IDB_BITMAP120);
		texture.AddBitmap(IDB_BITMAP121);
	}

	void Insect::OnMove() {
		texture.OnMove();
	}

	void Insect::OnShow() {
		texture.OnShow();
	}



	// Ladybug
	Ladybug::Ladybug() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Ladybug::Ladybug(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
	}

	void Ladybug::OnInit() {
		texture.AddBitmap(IDB_BITMAP122);
		texture.AddBitmap(IDB_BITMAP123);
		texture.AddBitmap(IDB_BITMAP124);
	}

	void Ladybug::OnMove() {
		texture.OnMove();
	}

	void Ladybug::OnShow() {
		texture.OnShow();
	}



	// Mosquito
	Mosquito::Mosquito() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Mosquito::Mosquito(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
	}

	void Mosquito::OnInit() {
		texture.AddBitmap(IDB_BITMAP125);
		texture.AddBitmap(IDB_BITMAP126);
	}

	void Mosquito::OnMove() {
		texture.OnMove();
	}

	void Mosquito::OnShow() {
		texture.OnShow();
	}



	// Penguin
	Penguin::Penguin() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Penguin::Penguin(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
	}

	void Penguin::OnInit() {
		texture.AddBitmap(IDB_BITMAP127);
		texture.AddBitmap(IDB_BITMAP128);
		texture.AddBitmap(IDB_BITMAP129);
		texture.AddBitmap(IDB_BITMAP130);
		texture.AddBitmap(IDB_BITMAP131);
	}

	void Penguin::OnMove() {
		texture.OnMove();
	}

	void Penguin::OnShow() {
		texture.OnShow();
	}



	// PinkMonster
	PinkMonster::PinkMonster() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	PinkMonster::PinkMonster(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
	}

	void PinkMonster::OnInit() {
		texture.AddBitmap(IDB_BITMAP132);
		texture.AddBitmap(IDB_BITMAP133);
		texture.AddBitmap(IDB_BITMAP134);
	}

	void PinkMonster::OnMove() {
		texture.OnMove();
	}

	void PinkMonster::OnShow() {
		texture.OnShow();
	}



	// Rocket
	Rocket::Rocket() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Rocket::Rocket(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
	}

	void Rocket::OnInit() {
		texture.AddBitmap(IDB_BITMAP135);
		texture.AddBitmap(IDB_BITMAP136);
	}

	void Rocket::OnMove() {
		texture.OnMove();
	}

	void Rocket::OnShow() {
		texture.OnShow();
	}



	// Shark
	Shark::Shark() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Shark::Shark(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
	}

	void Shark::OnInit() {
		texture.AddBitmap(IDB_BITMAP137);
		texture.AddBitmap(IDB_BITMAP138);
	}

	void Shark::OnMove() {
		texture.OnMove();
	}

	void Shark::OnShow() {
		texture.OnShow();
	}



	// Snails
	Snails::Snails() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Snails::Snails(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
	}

	void Snails::OnInit() {
		texture.AddBitmap(IDB_BITMAP139);
		texture.AddBitmap(IDB_BITMAP140);
	}

	void Snails::OnMove() {
		texture.OnMove();
	}

	void Snails::OnShow() {
		texture.OnShow();
	}



	// Spider
	Spider::Spider() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Spider::Spider(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
	}

	void Spider::OnInit() {
		texture.AddBitmap(IDB_BITMAP141);
		texture.AddBitmap(IDB_BITMAP142);
	}

	void Spider::OnMove() {
		texture.OnMove();
	}

	void Spider::OnShow() {
		texture.OnShow();
	}



	// Blue
	Blue::Blue() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Blue::Blue(int x, int y, int ang) {
		posX = x;
		posY = y;
		angle = ang;
	}

	void Blue::OnInit() {
		texture.AddBitmap(IDB_BITMAP143);
		texture.AddBitmap(IDB_BITMAP144);
		texture.AddBitmap(IDB_BITMAP145);
		texture.AddBitmap(IDB_BITMAP146);
		texture.AddBitmap(IDB_BITMAP147);
		texture.AddBitmap(IDB_BITMAP148);
		texture.AddBitmap(IDB_BITMAP149);
		texture.AddBitmap(IDB_BITMAP150);
	}

	void Blue::OnMove() {
		texture.OnMove();
	}

	void Blue::OnShow() {
		texture.OnShow();
	}



	// FlyShield
	FlyShield::FlyShield() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	FlyShield::FlyShield(int x, int y, int ang){
		posX = x;
		posY = y;
		angle = ang;
	}

	void FlyShield::OnInit() {
		texture.AddBitmap(IDB_BITMAP151);
		texture.AddBitmap(IDB_BITMAP152);
	}

	void FlyShield::OnMove() {
		texture.OnMove();
	}

	void FlyShield::OnShow() {
		texture.OnShow();
	}



	// Red
	Red::Red() {
		posX = 0;
		posY = 0;
		angle = 0;
	}

	Red::Red(int x, int y, int ang){
		posX = x;
		posY = y;
		angle = ang;
	}

	void Red::OnInit() {
		texture.AddBitmap(IDB_BITMAP153);
		texture.AddBitmap(IDB_BITMAP154);
		texture.AddBitmap(IDB_BITMAP155);
		texture.SetDelayCount(3);
		texture.SetTopLeft(posX, posY);
	}

	void Red::OnMove() {
		texture.OnMove();
	}

	void Red::OnShow() {
		texture.OnShow(DEFAULT_SCALE);
	}

	CAnimation Red::getTexture() {
		return texture;
	}
}
