#ifndef _ACTOR_
#define _ACTOR_

#include "Brick.h"

namespace game_framework {
	enum CHARACTERS {
		SONIC,
		MILES,
		KNUCKLES
	};

	class Actor {
	protected:
		const int maxVelocity = 40;	// only on x-axis
		const int maxAcceleration = 4;	// only on x-axis

		const int   gravity = 10;
		const float friction = 0.9f;

		POINT pos;

		POINT velocity;
		POINT acceleration;
		POINT delta;

		Brick* refBrick;

		CAnimation idle;
		CAnimation lookUp;
		CAnimation lookDown;
		CAnimation moving;
		CAnimation jump;

		int angle;		// angle = ang(actor's x-axis, real x-axis)
		int jumpStrength;
		
		bool ignoreHorizontal;
		bool isMovingLeft;
		bool isMovingRight;
		bool isLookingUp;
		bool isLookingDown;
		bool isJumping;		

		

	public:
		Actor();
		~Actor();

		virtual void OnInit() = 0;
		virtual void OnMove(vector<Brick*>) = 0;
		virtual void OnShow() = 0;
		
		POINT Moving(vector<Brick*>);

		int Top();
		int Left();
		int Buttom();
		int Right();
		int Width();
		int Height();

		POINT getDelta();

		void setTopLeft(int, int);
		void setTopLeft(POINT);
		void SetMoveLeft(bool);
		void SetMoveRight(bool);
		void SetIsLookingUp(bool);
		void SetIsLookingDown(bool);
		void SetIsJumping(bool);

		bool IsJumping();

		void LookingForRefBrick(vector<Brick*>);
		void checkLevingRefBrick();



		/*
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
		*/

	};

	class Sonic : public Actor {
	public:
		Sonic();
		~Sonic();

		void OnInit() override;
		void OnMove(vector<Brick*>) override;
		void OnShow() override;
	};

	class Miles : public Actor {
	public:
		Miles();
		~Miles();

		void OnInit() override;
		void OnMove(vector<Brick*>) override;
		void OnShow() override;
	};

	class Knuckles : public Actor {
	public:
		Knuckles();
		~Knuckles();

		void OnInit() override;
		void OnMove(vector<Brick*>) override;
		void OnShow() override;
	};
}

#endif // !_ACTOR_