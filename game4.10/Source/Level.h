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
		int max_x, max_y;
		int rings;
		int score;
		int level;

		POINT spawnPoint;

		CMovingBitmap background;
		
		Sonic	 actor1;
		Miles	 actor2;
		Knuckles actor3;
		Actor*	 currentActor;

		vector<Brick*>  bricks;
		vector<Item*>	items;
		vector<Enemy*>	enemies;

	public:
		/* Constructor */
		Level();
		Level(int);
		~Level();

		/* Getter */
		Actor* CurrentActor();
		int getRings();
		int getScore();

		/* Setter */
		void SetCurrentActor(int);
		void SetMoving(POINT);
		
		/* Member Function */
		void addItem(int, int, int);
		void addEnemy(int, int, int);

		//
		void OnInit(int);
		void OnMove();
		void OnShow();
	};
}

#endif