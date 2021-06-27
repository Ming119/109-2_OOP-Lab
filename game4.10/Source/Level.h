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
		EXOTIC_PARADISE_1,
		EXOTIC_PARADISE_2,
		TUTORIAL_1,
		COUNT
	};
	
	class Level {
	private:
		int rings;
		int score;
		int level;
		bool debugMODE;

		POINT spawnPoint;
		POINT delta;

		CMovingBitmap background;
		
		int character;
		Sonic	 actor1;
		// Miles	 actor2;	// Deprecated 
		// Knuckles actor3;		// Deprecated 
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
		bool getDebug();

		/* Setter */
		void SetCurrentActor(int);
		void SetMoving(POINT);
		void SetDebug(bool);

		/* Member Function */
		void addItem(int, int, int);
		void addEnemy(int, int, int);
		void clean();

		//
		void OnInit(int);
		void OnMove();
		void OnShow();
	};
}

#endif