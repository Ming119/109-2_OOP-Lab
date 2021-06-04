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

	/* Constructor */
	Level::Level() {
		rings = 0;
		score = 0;
		level = 0;
		character = 0;
		delta = POINT();
	}

	Level::Level(int l) {
		rings = 0;
		score = 0;
		level = l;
		character = 0;
		delta = POINT();
	}

	Level::~Level() {
		bricks.clear();
		items.clear();
		enemies.clear();
	}

	/* Getter */
	Actor* Level::CurrentActor() { return currentActor; }

	int Level::getRings() { return rings; }

	int Level::getScore() { return score; }

	/* Setter */
	void Level::SetCurrentActor(int actor) {
		character = actor;
		POINT pre = POINT();
		pre.x = currentActor->Left();
		pre.y = currentActor->Top();

		if (actor == SONIC)    currentActor = &actor1;
		if (actor == MILES)	   currentActor = &actor2;
		if (actor == KNUCKLES) currentActor = &actor3;

		POINT offset = POINT();
		offset.x = currentActor->Left() - pre.x;
		offset.y = currentActor->Top() - pre.y;

		int is = items.size();
		for (int i = 0; i < is; i++) {
			items.at(i)->SetCurrentActor(currentActor);
		}

		
		actor1.CameraMove(offset);
		actor2.CameraMove(offset);
		actor3.CameraMove(offset);
		SetMoving(offset);
	}

	void Level::SetMoving(POINT delta) {
		int bs = bricks.size();
		for (int i = 0; i < bs; i++)
			bricks.at(i)->SetMoving(delta);

		int is = items.size();
		for (int i = 0; i < is; i++)
			items.at(i)->SetMoving(delta);

		int es = enemies.size();
		for (int i = 0; i < es; i++)
			enemies.at(i)->SetMoving(delta);
	}

	/* Member Function */
	void Level::addItem(int id, int x, int y) {
		switch (id) {
		case -1: break;

		case 0:
			items.push_back(new Ring(id, x, y));
			break;

		case 16:
			items.push_back(new LOOP_RIGHT(id, x, y));
			break;

		case 17:
			items.push_back(new LOOP_TOP_HIED(id, x, y));
			break;

		case 18:
			items.push_back(new LOOP_LEFT(id, x, y));
			break;

		case 19:
			items.push_back(new LOOP_OFF(id, x, y));
			break;

		case 20:
			items.push_back(new YELLOW_SPRING_PADS_UP(id, x, y));
			break;

		case 21:
			items.push_back(new RED_SPRING_PADS_UP(id, x, y));
			break;

		case 22:
			items.push_back(new RED_SPRING_PADS_LEFT(id, x, y));
			break;

		case 23:
			items.push_back(new RED_SPRING_PADS_RING(id, x, y));
			break;

		case 26:
			items.push_back(new GATE_YELLOW(id, x, y));
			break;

		case 27:
			items.push_back(new SEND(id, x, y));
			break;

		case 28:
			items.push_back(new BIG_Ring(id, x, y));
			break;

		case 33:
			items.push_back(new LOOP_TOP_UP_DOWN(id, x, y));
			break;

		case 34:
			items.push_back(new LOOP_TOP_NOT_U_D(id, x, y));
			break;

		case 35:
			items.push_back(new LOOP_TOP(id, x, y));
			break;

		case 50:
			items.push_back(new YELLOW_SPRING_PADS_LEFT_U(id, x, y));
			break;

		case 51:
			items.push_back(new YELLOW_SPRING_PADS_RING_U(id, x, y));
			break;

		case 52:
			items.push_back(new YELLOW_SPRING_PADS_LEFT_D(id, x, y));
			break;

		case 53:
			items.push_back(new YELLOW_SPRING_PADS_RING_D(id, x, y));
			break;

		case 54:
			items.push_back(new YELLOW_SPRING_PADS_DOWN(id, x, y));
			break;

		case 55:
			items.push_back(new BULE_SPRING_PADS_UP(id, x, y));
			break;

		case 56:
			items.push_back(new BULE_SPRING_PADS_LEFT(id, x, y));
			break;

		case 57:
			items.push_back(new BULE_SPRING_PADS_RING(id, x, y));
			break;

		case 58:
			items.push_back(new BULE_SPRING_PADS_LEFT_U(id, x, y));
			break;
		
		case 59:
			items.push_back(new BULE_SPRING_PADS_RING_U(id, x, y));
			break;

		case 60:
			items.push_back(new BULE_SPRING_PADS_LEFT_D(id, x, y));
			break;

		case 61:
			items.push_back(new BULE_SPRING_PADS_RING_D(id, x, y));
			break;

		case 62:
			items.push_back(new BULE_SPRING_PADS_DOWN(id, x, y));
			break;

		case 66:
			items.push_back(new SPIKES_UP(id, x, y));
			break;

		case 63:
			items.push_back(new SPIKES_DOWN(id, x, y));
			break;

		case 64:
			items.push_back(new SPIKES_LEFT(id, x, y));
			break;

		case 65:
			items.push_back(new SPIKES_RIGHT(id, x, y));
			break;

		default: break;
		}
	}

	void Level::addEnemy(int id, int x, int y) {
		switch (id) {
		case -1: break;

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
		
		case static_cast<int>(ENEMIES_LIST::EARTHWORM) :
			enemies.push_back(new Earthworm(x, y));
			break;

		case static_cast<int>(ENEMIES_LIST::INSECT) :
			enemies.push_back(new Insect(x, y));
			break;

		case static_cast<int>(ENEMIES_LIST::PENGUIN) :
			enemies.push_back(new Penguin(x, y));
			break;

		case static_cast<int>(ENEMIES_LIST::PINKMONSTER) :
			enemies.push_back(new PinkMonster(x, y));
			break;

		case static_cast<int>(ENEMIES_LIST::SNAILS) :
			enemies.push_back(new Snails(x, y));
			break;

		case static_cast<int>(ENEMIES_LIST::BLUE) :
			enemies.push_back(new Blue(x, y));
			break;

		case static_cast<int>(ENEMIES_LIST::FLYSHIELD) :
			enemies.push_back(new FlyShield(x, y));
			break;

		default: break;
		}
	}

	//
	void Level::OnInit(int l) {
		level = l;
		rings = 0;
		score = 0;

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
			CAudio::Instance()->Stop(AUDIO_TITLE);
			CAudio::Instance()->Play(AUDIO_CRUSADER, true);

			spawnPoint.x = 40;
			spawnPoint.y = 2550;

			// Background
			background.LoadBitmap(LEVEL1_BG);

			// Brick
			for (int i = 0; i < sizeof(BULEOCEAN1Brick) / sizeof(BULEOCEAN1Brick[0]); i++) {
					const int id = BULEOCEAN1Brick[i][0];
					const int x = BULEOCEAN1Brick[i][1] * DEFAULT_SCALE;
					const int y = (BULEOCEAN1Brick[i][2] - spawnPoint.y) * DEFAULT_SCALE + SIZE_Y / 2;

					if (id != -1)
						bricks.push_back(new Brick(id, x, y));
				}
				
			// Item
			for (int i = 0; i < sizeof(BULEOCEAN1Items)/sizeof(BULEOCEAN1Items[0]); i++) {
				const int id = BULEOCEAN1Items[i][0];
				const int x = BULEOCEAN1Items[i][1] * DEFAULT_SCALE;
				const int y = (BULEOCEAN1Items[i][2] - spawnPoint.y - 15) * DEFAULT_SCALE + SIZE_Y / 2;

				if (id != -1)
					addItem(id, x, y);
					
			}

			// Enemy
			for (int i = 0; i < sizeof(BULEOCEAN1Enemies) / sizeof(BULEOCEAN1Enemies[0]); i++) {
				const int id = BULEOCEAN1Enemies[i][0];
				const int x = BULEOCEAN1Enemies[i][1] * DEFAULT_SCALE;
				const int y = (BULEOCEAN1Enemies[i][2] - spawnPoint.y) * DEFAULT_SCALE + SIZE_Y/2;

				if (id != -1)
					addEnemy(id, x, y);
			}
			
			break;

		// Level 2
		case static_cast<int>(LEVELS::BULE_OCEAN_2) :
			CAudio::Instance()->Stop(AUDIO_TITLE);
			CAudio::Instance()->Play(AUDIO_CRUSADER, true);

			spawnPoint.x = 40;
			spawnPoint.y = 3000;

			// Background
			background.LoadBitmap(LEVEL1_BG);

			// Brick
			for (int i = 0; i < sizeof(BULEOCEAN2Brick) / sizeof(BULEOCEAN2Brick[0]); i++) {
				const int id = BULEOCEAN2Brick[i][0];
				const int x = BULEOCEAN2Brick[i][1] * DEFAULT_SCALE;
				const int y = (BULEOCEAN2Brick[i][2] - spawnPoint.y) * DEFAULT_SCALE + SIZE_Y / 2;

				if (id != -1)
					bricks.push_back(new Brick(id, x, y));
			}

			// Item
			for (int i = 0; i < sizeof(BULEOCEAN2Items) / sizeof(BULEOCEAN2Items[0]); i++) {
				const int id = BULEOCEAN2Items[i][0];
				const int x = BULEOCEAN2Items[i][1] * DEFAULT_SCALE;
				const int y = (BULEOCEAN2Items[i][2] - spawnPoint.y - 15) * DEFAULT_SCALE + SIZE_Y / 2;

				if (id != -1)
					addItem(id, x, y);
			}

			// Enemy
			for (int i = 0; i < sizeof(BULEOCEAN2Enemies) / sizeof(BULEOCEAN2Enemies[0]); i++) {
				const int id = BULEOCEAN2Enemies[i][0];
				const int x = BULEOCEAN2Enemies[i][1] * DEFAULT_SCALE;
				const int y = (BULEOCEAN2Enemies[i][2] - spawnPoint.y) * DEFAULT_SCALE + SIZE_Y / 2;

				if (id != -1)
					addEnemy(id, x, y);

			}
			
			break;

		default: break;
		}

		int bs = bricks.size();
		for (int i = 0; i < bs; i++) {
			bricks.at(i)->OnInit(level);
		}

		int is = items.size();
		for (int i = 0; i < is; i++) {
			items.at(i)->OnInit();
			items.at(i)->SetCurrentActor(currentActor);
		}
		
		int es = enemies.size();
		for (int i = 0; i < es; i++) {
			enemies.at(i)->OnInit(bricks);
		}

	}

	void Level::OnMove() {
		delta = CurrentActor()->getDelta();
		SetMoving(delta);

		// Background
		background.SetTopLeft(0, 0);
		
		// Brick
		int bs = bricks.size();
		for (int i = 0; i < bs; i++) {
			bricks.at(i)->OnMove();
			
		}
		
		// Item
		int is = items.size();
		for (int i = 0; i < is; i++) {
			items.at(i)->OnMove();
			
			if (items.at(i)->IsChange() && items.at(i)->ID() == 0) {
				items.erase(items.begin()+i);
				is--; i--;
				rings++;
			}
		}

		// Enemy
		int es = enemies.size();
		for (int i = 0; i < es; i++) {
			enemies.at(i)->OnMove();

			/* Handling enemy die and score.
			if (enemies.at(i)->IsDead()) {
				items.erase(items.begin() + i);
				is--; i--;
				score += enmies.at(i)->score();
			}*/
		}

		// Actor
		CurrentActor()->OnMove(bricks, character);
		switch (CurrentActor()->Character())
		{
			case static_cast<int>(CHARACTERS::SONIC) :
				actor2.CameraMove(delta);
				actor2.OnMove(bricks, character);
				actor3.CameraMove(delta);
				actor3.OnMove(bricks, character);
				break;

			case static_cast<int>(CHARACTERS::MILES) :
				actor1.CameraMove(delta);
				actor1.OnMove(bricks, character);
				actor3.CameraMove(delta);
				actor3.OnMove(bricks, character);
				break;
			
			case static_cast<int>(CHARACTERS::KNUCKLES) :
				actor1.CameraMove(delta);
				actor1.OnMove(bricks, character);
				actor2.CameraMove(delta);
				actor2.OnMove(bricks, character);
				break;

			default:
				break;
		}
	}

	void Level::OnShow() {
		// Background
		background.ShowBitmap();

		// Brick
		int bs = bricks.size();
		for (int i = 0; i < bs; i++)
			bricks.at(i)->OnShow();

		// Item
		int is = items.size();
		for (int i = 0; i < is; i++)
			items.at(i)->OnShow();
		
		// Enemy
		int es = enemies.size();
		for (int i = 0; i < es; i++)
			enemies.at(i)->OnShow();

		// Actor
		actor1.OnShow();
		actor2.OnShow();
		actor3.OnShow();
	}

}