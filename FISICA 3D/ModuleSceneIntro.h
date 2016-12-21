#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"
#include "Timer.h"

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
	// map exterior walls
	Cube *wall1, *wall2, *wall3, *wall4, *wall5, *wall6;
	PhysBody3D *wall1b, *wall2b, *wall3b, *wall4b, *wall5b, *wall6b;

	// map interior walls
	Cube *i_wall1, *i_wall2, *i_wall3, *i_wall4, *i_wall5, *i_wall6, *i_wall7, *i_wall8, *i_wall9, *i_wall10, *i_wall11, *i_wall12, *i_wall13, *i_wall14, *i_wall15, *i_wall16, *i_wall17, *i_wall18, *i_wall19, *i_wall20, *i_wall21;
	PhysBody3D *i_wall1b, *i_wall2b, *i_wall3b, *i_wall4b, *i_wall5b, *i_wall6b, *i_wall7b, *i_wall8b, *i_wall9b, *i_wall10b, *i_wall11b, *i_wall12b, *i_wall13b, *i_wall14b, *i_wall15b, *i_wall16b, *i_wall17b, *i_wall18b, *i_wall19b, *i_wall20b, *i_wall21b;

	Cube *i_wall22, *i_wall23, *i_wall24, *i_wall25, *i_wall26, *i_wall27, *i_wall28, *i_wall29, *i_wall30, *i_wall31, *i_wall32, *i_wall33, *i_wall34, *i_wall35, *i_wall36, *i_wall37, *i_wall38, *i_wall39, *i_wall40;
	PhysBody3D *i_wall22b, *i_wall23b, *i_wall24b, *i_wall25b, *i_wall26b, *i_wall27b, *i_wall28b, *i_wall29b, *i_wall30b, *i_wall31b, *i_wall32b, *i_wall33b, *i_wall34b, *i_wall35b, *i_wall36b, *i_wall37b, *i_wall38b, *i_wall39b, *i_wall40b;

	// Buttons
	Cube *b1, *b2, *b3, *b4, *end;
	PhysBody3D *b1b, *b2b, *b3b, *b4b, *endb;

	bool b1pressed, b2pressed, b3pressed, b4pressed, endpressed, win_condit;

	//Sensors
	Cube *s, *s2,*s3, *s4, *s5;
	PhysBody3D *sensor, *sensor2, *sensor3, *sensor4, *sensor5;

	// FX and music
	uint lose;
	uint music;

	Timer pTime;
};
