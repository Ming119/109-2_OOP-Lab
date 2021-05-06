#ifndef _ACTOR_
#define _ACTOR_

#include "Brick.h"

namespace game_framework {
	class Actor {
	private:
		int posX, posY;
		POINT spawnPoint;
		POINT speed;

		float maxSpeed;		// on x-axis
		float angle;		// angle = ang(actor's x-axis, real x-axis)
		float jumpStrength;
		
		bool ignoreHorizontal;
		bool isMovingLeft;
		bool isMovingRight;
		bool isLookingUp;
		bool isLookingDown;
		bool isJumping;
		
		const int   gravity  = 10;
		const float friction = 0.95f;
		POINT velocity;
		int acceleration;

		CAnimation idle;
		CAnimation lookUp;
		CAnimation lookDown;
		CAnimation moving;
		CAnimation jump;

	public:
		Actor();
		~Actor();

		void OnInit();
		void OnMove();
		void OnShow();
		
		int Top();
		int Left();
		int Width();
		int Height();

		void setTopLeft(int, int);
		void SetMoveLeft(bool);
		void SetMoveRight(bool);
		void SetIsLookingUp(bool);
		void SetIsLookingDown(bool);
		void SetIsJumping(bool);

		bool IsJumping();




		// Collision Detection
		bool Collision(Actor*, Actor*);
		bool orientedbox_collision(Actor*, Actor*);
		bool poxelperfect_collision(Actor*, Actor*);
		bool brick_collision(Actor*, Brick*);
















		// Sensors
		void render_corners(Actor*, float, float, POINT);
		//void corners(Actor*, float, float, BrickList, Brick, Brick, Brick, Brick, Brick, Brick, Brick, Brick);
		void corners_ex(Actor*, float, POINT, POINT, POINT, POINT, POINT, POINT, POINT, POINT, Brick, Brick, Brick, Brick, Brick, Brick, Brick, Brick);
		void corners_set_floor_priority(int);
		void corners_restore_floor_priority();
		void corners_set_slope_priority(int);
		void corners_restore_slope_priority();
		void corners_disable_detection(int, int, int, int);
		void get_collision_detectors(Actor, float, POINT, POINT, POINT, POINT, POINT, POINT, POINT, POINT);

		// Platform Movement Routines
		void handle_passable();
		void handle_collision_detectors();
		void handle_carrying();
		void handle_wall_collision();
		void handle_ceil_collision();
		void handle_floor_collision();
		void handle_slopes();
		void handle_jumping();
		void handle_acceleration();

		// Pre-defined Movement Routines
		//POINT platfrom_movement(Actor*, BrickList*, float);
		POINT particle_movement(Actor*, float);
		POINT eightdirections_movement(Actor*);
		POINT bullet_movement(Actor*);

	};

}

#endif // !_ACTOR_