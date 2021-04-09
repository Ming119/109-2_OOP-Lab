#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Brick.h"
#include "Item.h"
#include "Enemy.h"
#include "Actor.h"

namespace game_framework {

	enum class LEVELS {
		BULE_OCEAN_1,
		BULE_OCEAN_2,
		BULE_OCEAN_3,
		CHILPOCTLI_TEMPLE,
		EXOTIC_HELL,
		EXOTIC_PARADISE_1,
		EXOTIC_PARADISE_2,
		EXOTIC_PARADISE_3,
		PROTOTYPE_1,
		SUPER_BOSS_1,
		SUPER_BOSS_2,
		TEMPLATE,
		TEST,
		TUTORIAL_1,
		TUTORIAL_2,
		COUNT
	};

	class Level {
	private:
		int max_x;
		int max_y;


		POINT spawnPoint;

		CMovingBitmap background;
		
		Actor actor1;
		Actor actor2;
		Actor actor3;

		vector<Brick*> bricks;
		vector<Item*> items;
		vector<Enemy*> enemies;

	public:
		Level();
		~Level();

		void OnInit(int);
		void OnMove();
		void OnShow();

		void SetMoveLeft(bool);
		void SetMoveRight(bool);
		void SetMoveUp(bool);
		void SetMoveDown(bool);
	};





}

#endif