#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

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

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;


	//map
	Cube *exit, *firstpl, *gcube, *gplane, *ramp1, *ramp2, *ramp3, *ramp4, *plane2, *plane3, *plane4, *plane5;
	PhysBody3D *exitp,*firstplp, *gcubep, *gplanep, *ramp1p,*ramp2p, *ramp3p, *ramp4p, *plane2p, *plane3p, *plane4p, *plane5p;

	PhysBody3D *ground_plane;

};
