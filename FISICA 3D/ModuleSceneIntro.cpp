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

	c1 = new Cube(10.0, 0.1, 14.0);
	c1->SetPos(0, 1, 0);
	c1->SetRotation(30, vec3(1, 0, 0));

	cube1 = App->physics->AddBody(*c1, 0);

	c2 = new Cube(10.0, 0.1, 14.0);
	c2->SetPos(0, 4.47, -13);
	
	cube2 = App->physics->AddBody(*c2, 0);

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
	
	
	
	c1->Render();
	c2->Render();
	/*Sphere s(1);
	s.SetPos(App->camera->Position.x, App->camera->Position.y, App->camera->Position.z);
	float force = 30.0f;
	AddBody(s)->Push(-(App->camera->Z.x * force), -(App->camera->Z.y * force), -(App->camera->Z.z * force));*/
	


	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

