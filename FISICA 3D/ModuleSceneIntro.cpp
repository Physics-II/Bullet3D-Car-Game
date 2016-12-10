#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(8.0f, 8.0f, 0.0f));
	App->camera->LookAt(vec3(10, 0, 10));

	exit = new Cube(10, 0, 10);
	exit->SetPos(0, 0, 10);
	exit->color = Green;
	exitp = App->physics->AddBody(*exit, 0);
	
	firstpl = new Cube(8,0,40);
	firstpl->SetPos(0, 0, 35);
	firstpl->color = Green;
	firstplp = App->physics->AddBody(*firstpl, 0);

	gcurbe = new Cube(8, 0, 10);
	gcurbe->SetPos(1, 0, 58);
	gcurbe->SetRotation(15, vec3(0, 1, 0));
	gcurbep = App->physics->AddBody(*gcurbe, 0);

	gcurbe2 = new Cube(8, 0, 11.2);
	gcurbe2->SetPos(4.6, 0, 66.8);
	gcurbe2->SetRotation(30, vec3(0, 1, 0));
	gcurbe2p = App->physics->AddBody(*gcurbe2, 0);
	
	ramp1 = new Cube(8, 0, 8);
	ramp1->SetPos(6.6, 0, 70);
	ramp1->SetRotation(45, vec3(-1, 1, 0));
	ramp1p = App->physics->AddBody(*ramp1, 0);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();
	
	exit->Render();
	firstpl->Render();
	gcurbe->Render();
	gcurbe2->Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

