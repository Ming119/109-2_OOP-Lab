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

	Level::Level() {
		count_ring = 0;
	}

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
		count_ring = 0;


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
				for (int i = 0; i < sizeof(BULEOCEAN1Brick) / sizeof(BULEOCEAN1Brick[0]); i++) {
					const int id = BULEOCEAN1Brick[i][0];
					const int x = BULEOCEAN1Brick[i][1] * DEFAULT_SCALE;
					const int y = (BULEOCEAN1Brick[i][2] - spawnPoint.y) * DEFAULT_SCALE + SIZE_Y / 2;

					bricks.push_back(new Brick(id, x, y));
				}
				
				// Item
				for (int i = 0; i < sizeof(BULEOCEAN1Items)/sizeof(BULEOCEAN1Items[0]); i++) {
					const int id = BULEOCEAN1Items[i][0];
					const int x = BULEOCEAN1Items[i][1] * DEFAULT_SCALE;
					const int y = (BULEOCEAN1Items[i][2] - spawnPoint.y - 15) * DEFAULT_SCALE + SIZE_Y / 2;

					switch (id) {

					case 0:
						items.push_back(new Ring(x, y));
						break;

					case 16:
						items.push_back(new LOOR_RING(x, y));
						break;

					case 17:
						items.push_back(new LOOP_TOP_HIED(x, y));
						break;

					case 18:
						items.push_back(new LOOP_LEFT(x, y));
						break;

					case 19:
						items.push_back(new LOOP_OFF(x, y));
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

					case 26:
						items.push_back(new GATE_YELLOW(x, y));
						break;

					case 27:
						items.push_back(new SEND(x, y));
						break;

					case 28:
						items.push_back(new BIG_Ring(x, y));
						break;

					case 33:
						items.push_back(new LOOP_TOP_UP_DOWN(x, y));
						break;

					case 34:
						items.push_back(new LOOP_TOP_NOT_U_D(x, y));
						break;

					case 35:
						items.push_back(new LOOP_TOP(x, y));
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

					case 66:
						items.push_back(new SPIKES_UP(x, y));
						break;

					case 63:
						items.push_back(new SPIKES_DOWN(x, y));
						break;

					case 64:
						items.push_back(new SPIKES_LEFT(x, y));
						break;

					case 65:
						items.push_back(new SPIKES_RING(x, y));
						break;

					default: break;
					}
					
				}

				// Enemy
				for (int i = 0; i < sizeof(BULEOCEAN1Enemies) / sizeof(BULEOCEAN1Enemies[0]); i++) {
					const int id = BULEOCEAN1Enemies[i][0];
					const int x = BULEOCEAN1Enemies[i][1] * DEFAULT_SCALE;
					const int y = (BULEOCEAN1Enemies[i][2] - spawnPoint.y) * DEFAULT_SCALE + SIZE_Y/2;

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
			spawnPoint.x = 40;
			spawnPoint.y = 3000;
			CAudio::Instance()->Stop(AUDIO_TITLE);
			CAudio::Instance()->Play(AUDIO_CRUSADER, true);

			// Background
			background.LoadBitmap(LEVEL1_BG);

			// Brick
			for (int i = 0; i < sizeof(BULEOCEAN2Brick) / sizeof(BULEOCEAN2Brick[0]); i++) {
				const int id = BULEOCEAN2Brick[i][0];
				const int x = BULEOCEAN2Brick[i][1] * DEFAULT_SCALE;
				const int y = (BULEOCEAN2Brick[i][2] - spawnPoint.y) * DEFAULT_SCALE + SIZE_Y / 2;

				bricks.push_back(new Brick(id, x, y));
			}

			// Item
			for (int i = 0; i < sizeof(BULEOCEAN2Items) / sizeof(BULEOCEAN2Items[0]); i++) {
				const int id = BULEOCEAN2Items[i][0];
				const int x = BULEOCEAN2Items[i][1] * DEFAULT_SCALE;
				const int y = (BULEOCEAN2Items[i][2] - spawnPoint.y - 15) * DEFAULT_SCALE + SIZE_Y / 2;

				switch (id) {

				case 0:
					items.push_back(new Ring(x, y));
					break;

				case 16:
					items.push_back(new LOOR_RING(x, y));
					break;

				case 17:
					items.push_back(new LOOP_TOP_HIED(x, y));
					break;

				case 18:
					items.push_back(new LOOP_LEFT(x, y));
					break;

				case 19:
					items.push_back(new LOOP_OFF(x, y));
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

				case 26:
					items.push_back(new GATE_YELLOW(x, y));
					break;

				case 27:
					items.push_back(new SEND(x, y));
					break;

				case 28:
					items.push_back(new BIG_Ring(x, y));
					break;

				case 33:
					items.push_back(new LOOP_TOP_UP_DOWN(x, y));
					break;

				case 34:
					items.push_back(new LOOP_TOP_NOT_U_D(x, y));
					break;

				case 35:
					items.push_back(new LOOP_TOP(x, y));
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

				case 66:
					items.push_back(new SPIKES_UP(x, y));
					break;

				case 63:
					items.push_back(new SPIKES_DOWN(x, y));
					break;

				case 64:
					items.push_back(new SPIKES_LEFT(x, y));
					break;

				case 65:
					items.push_back(new SPIKES_RING(x, y));
					break;

				default: break;
				}

			}

			// Enemy
			for (int i = 0; i < sizeof(BULEOCEAN2Enemies) / sizeof(BULEOCEAN2Enemies[0]); i++) {
				const int id = BULEOCEAN2Enemies[i][0];
				const int x = BULEOCEAN2Enemies[i][1] * DEFAULT_SCALE;
				const int y = (BULEOCEAN2Enemies[i][2] - spawnPoint.y) * DEFAULT_SCALE + SIZE_Y / 2;

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
					
					default: break;
				}

			}
			break;

		case  static_cast<int>(LEVELS::BULE_OCEAN_3) :
			spawnPoint.x = 35;
			spawnPoint.y = 280;
			CAudio::Instance()->Stop(AUDIO_TITLE);
			CAudio::Instance()->Play(AUDIO_CRUSADER, true);

			// Background
			background.LoadBitmap(LEVEL1_BG);

			// Brick
			for (int i = 0; i < sizeof(BULEOCEAN3Brick) / sizeof(BULEOCEAN3Brick[0]); i++) {
				const int id = BULEOCEAN3Brick[i][0];
				const int x = BULEOCEAN3Brick[i][1] * DEFAULT_SCALE;
				const int y = (BULEOCEAN3Brick[i][2] - spawnPoint.y) * DEFAULT_SCALE + SIZE_Y / 2;

				bricks.push_back(new Brick(id, x, y));
			}

			// Item
			for (int i = 0; i < sizeof(BULEOCEAN3Items) / sizeof(BULEOCEAN3Items[0]); i++) {
				const int id = BULEOCEAN3Items[i][0];
				const int x = BULEOCEAN3Items[i][1] * DEFAULT_SCALE;
				const int y = (BULEOCEAN3Items[i][2] - spawnPoint.y - 15) * DEFAULT_SCALE + SIZE_Y / 2;

				switch (id) {

				case 0:
					items.push_back(new Ring(x, y));
					break;

				case 16:
					items.push_back(new LOOR_RING(x, y));
					break;

				case 17:
					items.push_back(new LOOP_TOP_HIED(x, y));
					break;

				case 18:
					items.push_back(new LOOP_LEFT(x, y));
					break;

				case 19:
					items.push_back(new LOOP_OFF(x, y));
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

				case 26:
					items.push_back(new GATE_YELLOW(x, y));
					break;

				case 27:
					items.push_back(new SEND(x, y));
					break;

				case 28:
					items.push_back(new BIG_Ring(x, y));
					break;

				case 33:
					items.push_back(new LOOP_TOP_UP_DOWN(x, y));
					break;

				case 34:
					items.push_back(new LOOP_TOP_NOT_U_D(x, y));
					break;

				case 35:
					items.push_back(new LOOP_TOP(x, y));
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

				case 66:
					items.push_back(new SPIKES_UP(x, y));
					break;

				case 63:
					items.push_back(new SPIKES_DOWN(x, y));
					break;

				case 64:
					items.push_back(new SPIKES_LEFT(x, y));
					break;

				case 65:
					items.push_back(new SPIKES_RING(x, y));
					break;

				default: break;
				}

			}

			// Enemy
			for (int i = 0; i < sizeof(BULEOCEAN3Enemies) / sizeof(BULEOCEAN3Enemies[0]); i++) {
				const int id = BULEOCEAN3Enemies[i][0];
				const int x = BULEOCEAN3Enemies[i][1] * DEFAULT_SCALE;
				const int y = (BULEOCEAN3Enemies[i][2] - spawnPoint.y) * DEFAULT_SCALE + SIZE_Y / 2;

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

					default: break;
				}
			}
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
	int Level::getCountRing() {
		return count_ring;
	}


	void Level::OnMove() {
		// Actor
		/*actor1.OnMove();
		actor2.OnMove();
		actor3.OnMove();*/
		
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
				count_ring++;
				
				//TRACE("ring = %d\n", count_ring);
			}


		}

		// Enemy
		for (int i = 0; i < es; i++) {
			enemies.at(i)->OnMove();
		}

		CurrentActor()->OnMove(bricks);
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