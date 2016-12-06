#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;



	//floor 1

	Cube*ramp1, *plane1, *obs1, *obs2, *obs3, *rampJump2, *corved1, *corved2, *corved3, *minicorved1, *minicorved2, *minicorbed3, *minicorved4;
	PhysBody3D *ramp1P, *plane1P, *obs1P, *obs2P, *obs3P, *rampJump2P, *corved1P, *corved2P, *corved3P, *minicorved1P, *minicorved2P, *minicorbed3P, *minicorved4P;

};
