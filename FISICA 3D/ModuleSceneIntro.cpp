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

	App->camera->Move(vec3(4.0f, 4.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	btCollisionShape* sphere = new btSphereShape(1);

	ramp1 = new Cube(10.0, 0.1, 14.0);
	ramp1->SetPos(0, 1, 0);
	ramp1->SetRotation(30, vec3(1, 0, 0));

	ramp1P = App->physics->AddBody(*ramp1, 0);

	plane1 = new Cube(10.0, 0.1, 14.0);
	plane1->SetPos(0, 4.47, -13);
	
	plane1P = App->physics->AddBody(*plane1, 0);

	plane2 = new Cube(10.0, 0.1, 14.0);
	plane2->SetPos(0, 4.47, -30);

	plane2P = App->physics->AddBody(*plane2, 0);

	/*obs1 = new Cube(5, 0.1, 7);
	obs1->SetPos(3, 5, -27);
	obs1->SetRotation(20, vec3(1, 0, 0));

	obs1P = App->physics->AddBody(*obs1, 0);

	obs2 = new Cube(5, 0.1, 7);
	obs2->SetPos(-3, 5, -34);
	obs2->SetRotation(20, vec3(1, 0, 0));

	obs2P = App->physics->AddBody(*obs2, 0);

	obs3 = new Cube(5, 0.1, 7);
	obs3->SetPos(-0, 5, -41);
	
	obs3P = App->physics->AddBody(*obs3, 0);*/
	
	rampJump2 = new Cube(7, 0.1, 9);
	rampJump2->SetPos(3, 7.5, -51);
	rampJump2->SetRotation(40, vec3(1, 0, 0));

	rampJump2P = App->physics->AddBody(*rampJump2, 0);
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
	
	
	
	ramp1->Render();
	plane1->Render();
	/*obs1->Render();
	obs2->Render();
	obs3->Render();*/
	rampJump2->Render();
	/*Sphere s(1);
	s.SetPos(App->camera->Position.x, App->camera->Position.y, App->camera->Position.z);
	float force = 30.0f;
	AddBody(s)->Push(-(App->camera->Z.x * force), -(App->camera->Z.y * force), -(App->camera->Z.z * force));*/
	


	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

