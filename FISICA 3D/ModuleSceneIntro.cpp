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

	gcube = new Cube(8, 6, 20);
	gcube->SetPos(0, 3.2, 78);
	gcubep = App->physics->AddBody(*gcube, 0);

	gplane = new Cube(20, 0, 9);
	gplane->SetPos(0, 1.3, 110);
	gplanep = App->physics->AddBody(*gplane, 0);

	ramp2 = new Cube(30, 0, 10);
	ramp2->SetPos(5, 0.5, 112.5);
	ramp2->SetRotation(20, vec3(-1, 0, 0));
	ramp2p = App->physics->AddBody(*ramp2, 0);

	ramp3 = new Cube(15, 0, 4);
	ramp3->SetPos(17, 0.8, 110);
	ramp3->SetRotation(3, vec3(0, 0, -1));
	ramp2p = App->physics->AddBody(*ramp3, 0);

	plane2 = new Cube(12,0.6,6);
	plane2->SetPos(28, 0.3, 110);
	plane2p = App->physics->AddBody(*plane2, 0);

	plane3 = new Cube(6, 0.6, 6);
	plane3->SetPos(35, 0.3, 110);
	plane3->SetRotation(15, vec3(0, 1, 0));
	plane3p = App->physics->AddBody(*plane3, 0);

	plane4 = new Cube(6, 0.6, 6);
	plane4->SetPos(40, 0.3, 108);
	plane4->SetRotation(30, vec3(0, 1, 0));
	plane4p = App->physics->AddBody(*plane4, 0);

	plane5 = new Cube(6, 0.6, 6);
	plane5->SetPos(44, 0.3, 107);
	plane5p = App->physics->AddBody(*plane5, 0);


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
	p.color = Color(0.0f, 0.5f, 1.0f);
	p.Render();
	
	exit->Render();
	firstpl->Render();
	gcube->Render();
	ramp1->Render();
	gplane->Render();
	ramp2->Render();
	ramp3->Render();
	plane2->Render();
	plane3->Render();
	plane4->Render();
	plane5->Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

