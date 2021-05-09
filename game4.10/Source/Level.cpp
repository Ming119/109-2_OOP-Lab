#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <vector>
#include "audio.h"
#include "gamelib.h"
#include "Level.h"
#include "Data.h"
#include "mygame.h"

namespace game_framework {	

	Level::Level() { }

	Level::~Level() { }

	void Level::OnInit(int level) {

		//  
		bricks.clear();
		items.clear();
		enemies.clear();
		
		actor1.OnInit();
		actor2.OnInit();
		actor3.OnInit();

		currentActor = &actor1;



		switch (level) {
			// Level 1
			case static_cast<int>(LEVELS::BULE_OCEAN_1) :
				spawnPoint.x = 40;
				spawnPoint.y = 2550;
				CAudio::Instance()->Stop(AUDIO_TITLE);
				CAudio::Instance()->Play(AUDIO_CRUSADER, true);

				// Background
				background.LoadBitmap(LEVEL1_BG);

				// Brick
				for (int i = 0; i < sizeof(Level1Brick) / sizeof(Level1Brick[0]); i++) {
					int id = Level1Brick[i][0];
					int x = Level1Brick[i][1] * DEFAULT_SCALE;
					int y = (Level1Brick[i][2] - spawnPoint.y) * DEFAULT_SCALE + SIZE_Y / 2;

					bricks.push_back(new Brick(id, x, y));
				}
				
				// Item
				for (int i = 0; i < sizeof(Level1Items)/sizeof(Level1Items[0]); i++) {
					int id = Level1Items[i][0];
					int x = Level1Items[i][1] * DEFAULT_SCALE;
					int y = (Level1Items[i][2] - spawnPoint.y) * DEFAULT_SCALE + SIZE_Y / 2;
					TRACE("id = %d\n",id);

					switch (id) {

					case 0:
						items.push_back(new Ring(x, y));
						break;

					case 20:
							items.push_back(new YELLOW_SPRING_PADS_UP(x, y));
							break;

					case 21:
						items.push_back(new RED_SPRING_PADS_UP(x, y));
						break;
					
					case 22:
						items.push_back(new RED_SPRING_PADS_LEFT(x, y));
						break;

					case 23:
						items.push_back(new RED_SPRING_PADS_RING(x, y));
						break;

					case 50:
						items.push_back(new YELLOW_SPRING_PADS_LEFT_U(x, y));
						break;

					case 51:
						items.push_back(new YELLOW_SPRING_PADS_RING_U(x, y));
						break;

					case 52:
						items.push_back(new YELLOW_SPRING_PADS_LEFT_D(x, y));
						break;

					case 53:
						items.push_back(new YELLOW_SPRING_PADS_RING_D(x, y));
						break;
					
					case 54:
						items.push_back(new YELLOW_SPRING_PADS_DOWN(x, y));
						break;
					
					case 55:
						items.push_back(new BULE_SPRING_PADS_UP(x, y));
						break;
					
					case 56:
						items.push_back(new BULE_SPRING_PADS_LEFT(x, y));
						break;
					
					case 57:
						items.push_back(new BULE_SPRING_PADS_RING(x, y));
						break;
					
					case 58:
						items.push_back(new BULE_SPRING_PADS_LEFT_U(x, y));
						break;
					
					case 59:
						items.push_back(new BULE_SPRING_PADS_RING_U(x, y));
						break;
					
					case 60:
						items.push_back(new BULE_SPRING_PADS_LEFT_D(x, y));
						break;
					
					case 61:
						items.push_back(new BULE_SPRING_PADS_RING_D(x, y));
						break;
					
					case 62:
						items.push_back(new BULE_SPRING_PADS_DOWN(x, y));
						break;
					}

					/*
					case 1:
						break;
					}*/
					
				}

				// Enemy
				for (int i = 0; i < sizeof(Level1Enemies) / sizeof(Level1Enemies[0]); i++) {
					int id = Level1Enemies[i][0];
					int x = Level1Enemies[i][1] * DEFAULT_SCALE;
					int y = (Level1Enemies[i][2] - spawnPoint.y) * DEFAULT_SCALE + SIZE_Y/2;

					switch (id) {
					case static_cast<int>(ENEMIES_LIST::LADYBUG) :
						enemies.push_back(new Ladybug(x, y));
						break;

					case static_cast<int>(ENEMIES_LIST::FLY) :
						enemies.push_back(new Fly(x, y));
						break;

					case static_cast<int>(ENEMIES_LIST::BAMBOO) :
						enemies.push_back(new Bamboo(x, y));
						break;

					case static_cast<int>(ENEMIES_LIST::SPIDER) :
						enemies.push_back(new Spider(x, y));
						break;

					case static_cast<int>(ENEMIES_LIST::ROCKET) :
						enemies.push_back(new Rocket(x, y));
						break;

					case static_cast<int>(ENEMIES_LIST::SHARK) :
						enemies.push_back(new Shark(x, y));
						break;

					case static_cast<int>(ENEMIES_LIST::MOSQUITO) :
						enemies.push_back(new Mosquito(x, y));
						break;

					case static_cast<int>(ENEMIES_LIST::GROUNDHOG) :
						enemies.push_back(new Groundhog(x, y));
						break;

					case static_cast<int>(ENEMIES_LIST::RED) :
						enemies.push_back(new Red(x, y));
						break;

					case static_cast<int>(ENEMIES_LIST::CHEF) :
						enemies.push_back(new Chef(x, y));
						break;
					}

				}
			break;

		case static_cast<int>(LEVELS::BULE_OCEAN_2) :
			break;

		case  static_cast<int>(LEVELS::BULE_OCEAN_3) :
			break;

		case 3:
			break;
		}

		int bs = bricks.size();
		for (int i = 0; i < bs; i++) {
			bricks.at(i)->OnInit(level);
		}

		int is = items.size();
		for (int i = 0; i < is; i++) {
			items.at(i)->OnInit();
			items.at(i)->SetCurrentActor(&actor1);
		}
		
		int es = enemies.size();
		for (int i = 0; i < es; i++) {
			enemies.at(i)->OnInit(bricks);
		}

	}
	
	void Level::OnMove() {
		// Actor
		actor1.OnMove();
		actor2.OnMove();
		actor3.OnMove();

		if (CurrentActor()->IsJumping()) {
			
		}

		// Background
		background.SetTopLeft(0, 0);

		int bs = bricks.size();
		int es = enemies.size();
		
		// Brick
		for (int i = 0; i < bs; i++) {
			bricks.at(i)->OnMove();
		}
		
		// Item
		int is = items.size();
		for (int i = 0; i < is; i++) {
			items.at(i)->OnMove();
			if (items.at(i)->IsDead()) {
				items.erase(items.begin()+i);
				is--; i--;
			}
		}

		// Enemy
		for (int i = 0; i < es; i++) {
			enemies.at(i)->OnMove();
		}
	}

	void Level::OnShow() {
		// Background
		background.ShowBitmap();

		// Brick
		int bs = bricks.size();
		for (int i = 0; i < bs; i++) {
			bricks.at(i)->OnShow();
		}

		
		// Item
		int is = items.size();
		for (int i = 0; i < is; i++) {
			items.at(i)->OnShow();
		}

		// Enemy
		int es = enemies.size();
		for (int i = 0; i < es; i++) {
			enemies.at(i)->OnShow();
		}



		// Actor
		actor1.OnShow();
		actor2.OnShow();
		actor3.OnShow();
	}

	Actor* Level::CurrentActor() { return currentActor; }

	void Level::SetCurrentActor(int actor) {
		if (actor == SONIC)    currentActor = &actor1;
		if (actor == MILES)	   currentActor = &actor2;
		if (actor == KNUCKLES) currentActor = &actor3;
	}

	void Level::SetMoveLeft(bool m) {
		int bs = bricks.size();
		for (int i = 0; i < bs; i++) {
			bricks.at(i)->SetMoveLeft(m);
		}

		int is = items.size();
		for (int i = 0; i < is; i++) {
			items.at(i)->SetMoveLeft(m);
		}

		int es = enemies.size();
		for (int i = 0; i < es; i++) {
			enemies.at(i)->SetMoveLeft(m);
		}
	}

	void Level::SetMoveRight(bool m) {
		int bs = bricks.size();
		for (int i = 0; i < bs; i++) {
			bricks.at(i)->SetMoveRight(m);
		}

		int is = items.size();
		for (int i = 0; i < is; i++) {
			items.at(i)->SetMoveRight(m);
		}

		int es = enemies.size();
		for (int i = 0; i < es; i++) {
			enemies.at(i)->SetMoveRight(m);
		}
	}

	void Level::SetMoveUp(bool m) {
		int bs = bricks.size();
		for (int i = 0; i < bs; i++) {
			bricks.at(i)->SetMoveUp(m);
		}

		int is = items.size();
		for (int i = 0; i < is; i++) {
			items.at(i)->SetMoveUp(m);
		}

		int es = enemies.size();
		for (int i = 0; i < es; i++) {
			enemies.at(i)->SetMoveUp(m);
		}
	}

	void Level::SetMoveDown(bool m) {
		

		int bs = bricks.size();
		for (int i = 0; i < bs; i++) {
			bricks.at(i)->SetMoveDown(m);
		}

		int is = items.size();
		for (int i = 0; i < is; i++) {
			items.at(i)->SetMoveDown(m);
		}

		int es = enemies.size();
		for (int i = 0; i < es; i++) {
			enemies.at(i)->SetMoveDown(m);
		}
	}

	void Level::SetMoving(POINT delta) {
		int bs = bricks.size();
		for (int i = 0; i < bs; i++) {
			bricks.at(i)->SetMoving(delta);
		}

		int is = items.size();
		for (int i = 0; i < is; i++) {
			items.at(i)->SetMoving(delta);
		}

		int es = enemies.size();
		for (int i = 0; i < es; i++) {
			enemies.at(i)->SetMoving(delta);
		}
	}

}