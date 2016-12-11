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

	App->camera->Move(vec3(8.0f, 8.0f, 40.0f));
	App->camera->LookAt(vec3(0, 0, 60));

	exit = new Cube(10, 0, 10);
	exit->SetPos(0, 0, 10);
	exit->color = Green;
	exitp = App->physics->AddBody(*exit, 0);
	
	firstpl = new Cube(8,0,40);
	firstpl->SetPos(0, 0, 35);
	firstpl->color = Green;
	firstplp = App->physics->AddBody(*firstpl, 0);

	ramp1 = new Cube(8, 0, 4);
	ramp1->SetPos(0,1,55);
	ramp1->SetRotation(30, vec3(-1, 0, 0));
	ramp1->color = Green;
	ramp1p = App->physics->AddBody(*ramp1, 0);

	gcube = new Cube(8, 9, 8);
	gcube->SetPos(0, 3.2, 78);
	gcubep = App->physics->AddBody(*gcube, 0);

	gplane = new Cube(15, 0, 6);
	gplane->SetPos(0, 0.5, 108);
	gplanep = App->physics->AddBody(*gplane, 0);

	ramp2 = new Cube(15, 0, 10);
	ramp2->SetPos(0, 0.5, 112.5);
	ramp2->SetRotation(30, vec3(-1, 0, 0));
	ramp2p = App->physics->AddBody(*ramp2, 0);

	ramp3 = new Cube(15, 0, 4);
	ramp3->SetPos(15, 2, 115);
	ramp3->SetRotation(30, vec3(-1, 0, 0));
	ramp2p = App->physics->AddBody(*ramp3, 0);

	ramp4 = new Cube(15, 0, 3);
	ramp4->SetPos(25, 4, 115);
	ramp4->SetRotation(35, vec3(0, 0, 1));
	ramp4p = App->physics->AddBody(*ramp4, 0);

	plane2 = new Cube(8,10,10);
	plane2->SetPos(35, 2.8, 115);
	plane2p = App->physics->AddBody(*plane2, 0);

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
	p.color = Blue;
	p.Render();
	
	exit->Render();
	firstpl->Render();
	gcube->Render();
	ramp1->Render();
	gplane->Render();
	ramp2->Render();
	ramp3->Render();
	ramp4->Render();

	plane2->Render();
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

