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

	lose = App->audio->LoadFx("Game/Music/Lose.wav");

	App->camera->Move(vec3(8.0f, 8.0f, 40.0f));
	App->camera->LookAt(vec3(0, 0, 60));

	wall1 = new Cube(70, 10, 10);
	wall1->SetPos(40, 5, -100);
	wall1b = App->physics->AddBody(*wall1, 0);


	wall2 = new Cube(70, 10, 10);
	wall2->SetPos(-40, 5, -100);
	wall2b = App->physics->AddBody(*wall2, 0);

	wall3 = new Cube(10, 10, 270);
	wall3->SetPos(80, 5, 30);
	wall3b = App->physics->AddBody(*wall3, 0);

	wall4 = new Cube(10, 10, 270);
	wall4->SetPos(-80, 5, 30);
	wall4b = App->physics->AddBody(*wall4, 0);

	i_wall1 = new Cube(10, 10, 30);
	i_wall1->SetPos(40, 5, -90);
	i_wall1b = App->physics->AddBody(*i_wall1, 0);

	i_wall2 = new Cube(10, 10, 30);
	i_wall2->SetPos(-40, 5, -90);
	i_wall2b = App->physics->AddBody(*i_wall2, 0);

	i_wall3 = new Cube(50, 10, 10);
	i_wall3->SetPos(0, 5, -80);
	i_wall3b = App->physics->AddBody(*i_wall3, 0);

	i_wall4 = new Cube(30, 10, 10);
	i_wall4->SetPos(50, 5, -80);
	i_wall4b = App->physics->AddBody(*i_wall4, 0);

	i_wall5 = new Cube(30, 10, 10);
	i_wall5->SetPos(-50, 5, -80);
	i_wall5b = App->physics->AddBody(*i_wall5, 0);

	i_wall6 = new Cube(10, 10, 50);
	i_wall6->SetPos(20, 5, -60);
	i_wall6b = App->physics->AddBody(*i_wall6, 0);

	i_wall7 = new Cube(50, 10, 10);
	i_wall7->SetPos(40, 5, -60);
	i_wall7b = App->physics->AddBody(*i_wall7, 0);

	i_wall8 = new Cube(10, 10, 30);
	i_wall8->SetPos(-20, 5, -70);
	i_wall8b = App->physics->AddBody(*i_wall8, 0);

	i_wall9 = new Cube(50, 10, 10);
	i_wall9->SetPos(-40, 5, -60);
	i_wall9b = App->physics->AddBody(*i_wall9, 0);

	i_wall10 = new Cube(110, 10, 10);
	i_wall10->SetPos(-30, 5, -40);
	i_wall10b = App->physics->AddBody(*i_wall10, 0);

	i_wall11 = new Cube(50, 10, 10);
	i_wall11->SetPos(60, 5, -40);
	i_wall11b = App->physics->AddBody(*i_wall11, 0);

	i_wall12 = new Cube(10, 10, 30);
	i_wall12->SetPos(40, 5, -30);
	i_wall12b = App->physics->AddBody(*i_wall12, 0);

	i_wall13 = new Cube(50, 10, 10);
	i_wall13->SetPos(40, 5, -20);
	i_wall13b = App->physics->AddBody(*i_wall13, 0);

	i_wall14 = new Cube(90, 10, 10);
	i_wall14->SetPos(-40, 5, -20);
	i_wall14b = App->physics->AddBody(*i_wall14, 0);

	i_wall15 = new Cube(10, 10, 30);
	i_wall15->SetPos(0, 5, -10);
	i_wall15b = App->physics->AddBody(*i_wall15, 0);

	i_wall16 = new Cube(70, 10, 10);
	i_wall16->SetPos(50, 5, 0);
	i_wall16b = App->physics->AddBody(*i_wall16, 0);

	i_wall17 = new Cube(70, 10, 10);
	i_wall17->SetPos(-50, 5, 0);
	i_wall17b = App->physics->AddBody(*i_wall17, 0);

	i_wall18 = new Cube(10, 10, 30);
	i_wall18->SetPos(20, 5, 10);
	i_wall18b = App->physics->AddBody(*i_wall18, 0);

	i_wall19 = new Cube(50, 10, 10);
	i_wall19->SetPos(40, 5, 20);
	i_wall19b = App->physics->AddBody(*i_wall19, 0);

	i_wall20 = new Cube(70, 10, 10);
	i_wall20->SetPos(-30, 5, 20);
	i_wall20b = App->physics->AddBody(*i_wall20, 0);

	i_wall21 = new Cube(10, 10, 50);
	i_wall21->SetPos(-60, 5, 40);
	i_wall21b = App->physics->AddBody(*i_wall21, 0);

	i_wall22 = new Cube(10, 10, 30);
	i_wall22->SetPos(0, 5, 30);
	i_wall22b = App->physics->AddBody(*i_wall22, 0);

	i_wall23 = new Cube(90, 10, 10);
	i_wall23->SetPos(40, 5, 40);
	i_wall23b = App->physics->AddBody(*i_wall23, 0);

	i_wall24 = new Cube(10, 10, 50);
	i_wall24->SetPos(-30, 5, 60);
	i_wall24b = App->physics->AddBody(*i_wall24, 0);

	i_wall25 = new Cube(100, 10, 10);
	i_wall25->SetPos(15, 5, 60);
	i_wall25b = App->physics->AddBody(*i_wall25, 0);

	i_wall26 = new Cube(40, 10, 10);
	i_wall26->SetPos(-45, 5, 80);
	i_wall26b = App->physics->AddBody(*i_wall26, 0);

	i_wall27 = new Cube(10, 10, 70);
	i_wall27->SetPos(-60, 5, 110);
	i_wall27b = App->physics->AddBody(*i_wall27, 0);

	i_wall28 = new Cube(30, 10, 10);
	i_wall28->SetPos(-50, 5, 140);
	i_wall28b = App->physics->AddBody(*i_wall28, 0);

	i_wall29 = new Cube(10, 10, 50);
	i_wall29->SetPos(60, 5, 80);
	i_wall29b = App->physics->AddBody(*i_wall29, 0);

	i_wall30 = new Cube(60, 10, 10);
	i_wall30->SetPos(15, 5, 80);
	i_wall30b = App->physics->AddBody(*i_wall30, 0);

	i_wall31 = new Cube(110, 10, 10);
	i_wall31->SetPos(10, 5, 100);
	i_wall31b = App->physics->AddBody(*i_wall31, 0);

	i_wall32 = new Cube(10, 10, 90);
	i_wall32->SetPos(-10, 5, 120);
	i_wall32b = App->physics->AddBody(*i_wall32, 0);

	i_wall33 = new Cube(40, 10, 10);
	i_wall33->SetPos(-25, 5, 120);
	i_wall33b = App->physics->AddBody(*i_wall33, 0);

	i_wall34 = new Cube(70, 10, 10);
	i_wall34->SetPos(-40, 5, 160);
	i_wall34b = App->physics->AddBody(*i_wall34, 0);

	i_wall35 = new Cube(70, 10, 10);
	i_wall35->SetPos(40, 5, 160);
	i_wall35b = App->physics->AddBody(*i_wall35, 0);

	i_wall36 = new Cube(10, 10, 50);
	i_wall36->SetPos(10, 5, 140);
	i_wall36b = App->physics->AddBody(*i_wall36, 0);

	i_wall37 = new Cube(50, 10, 10);
	i_wall37->SetPos(30, 5, 100);
	i_wall37b = App->physics->AddBody(*i_wall37, 0);

	i_wall38 = new Cube(10, 10, 30);
	i_wall38->SetPos(50, 5, 130);
	i_wall38b = App->physics->AddBody(*i_wall38, 0);

	i_wall39 = new Cube(30, 10, 10);
	i_wall39->SetPos(40, 5, 140);
	i_wall39b = App->physics->AddBody(*i_wall39, 0);

	i_wall40 = new Cube(50, 10, 10);
	i_wall40->SetPos(30, 5, 120);
	i_wall40b = App->physics->AddBody(*i_wall40, 0);

	//40, 0, 130
	
	b1 = new Cube(10, 0, 10);
	b1->SetPos(0, 0, -90);
	b1->color = Green;
	b1b = App->physics->AddBody(*b1, 0);

	s = new Cube(10, 10, 10);
	s->SetPos(0, 0, -90);
	sensor = App->physics->AddBody(*s, 0.0f);
	sensor->SetAsSensor(true);
	sensor->collision_listeners.add(this);

	b2 = new Cube(10, 0, 10);
	b2->SetPos(0, 0, 90);
	b2->color = Green;
	b2b = App->physics->AddBody(*b2, 0);

	s2 = new Cube(10, 10, 10);
	s2->SetPos(0, 5, 90);
	sensor2 = App->physics->AddBody(*s2, 0.0f);
	sensor2->SetAsSensor(true);
	sensor2->collision_listeners.add(this);

	b3 = new Cube(10, 0, 10);
	b3->SetPos(0, 0, -70);
	b3->color = Green;
	b3b = App->physics->AddBody(*b3, 0);

	s3 = new Cube(10, 10, 10);
	s3->SetPos(0, 0, -70);
	sensor3 = App->physics->AddBody(*s3, 0.0f);
	sensor3->SetAsSensor(true);
	sensor3->collision_listeners.add(this);

	b1pressed = false;
	b2pressed = false;
	b3pressed = false;
	win_condit = false;

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
	Plane p(1000, 1000, 0, 0);
	p.axis = true;
	p.color = Color(0.0f, 0.5f, 1.0f);
	p.Render();

	wall1->Render();
	wall2->Render();
	wall3->Render();
	wall4->Render();

	i_wall1->Render();
	i_wall2->Render();
	i_wall3->Render();
	i_wall4->Render();
	i_wall5->Render();
	i_wall6->Render();
	i_wall7->Render();
	i_wall8->Render();
	i_wall9->Render();
	i_wall10->Render();
	i_wall11->Render();
	i_wall12->Render();
	i_wall13->Render();
	i_wall14->Render();
	i_wall15->Render();
	i_wall16->Render();
	i_wall17->Render();
	i_wall18->Render();
	i_wall19->Render();
	i_wall20->Render();
	i_wall21->Render();
	i_wall22->Render();
	i_wall23->Render();
	i_wall24->Render();
	i_wall25->Render();
	i_wall26->Render();
	i_wall27->Render();
	i_wall28->Render();
	i_wall29->Render();
	i_wall30->Render();
	i_wall31->Render();
	i_wall32->Render();
	i_wall33->Render();
	i_wall34->Render();
	i_wall35->Render();
	i_wall36->Render();
	i_wall37->Render();
	i_wall38->Render();
	i_wall39->Render();
	i_wall40->Render();

	b1->Render();
	b2->Render();
	b3->Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{

	if (body1 == sensor || body2 == sensor)
	{
		if (b1pressed == false)
		{
			b1pressed = true;
			App->player->score += 100;
			b1->color = Red;
		}
	}

	if (body1 == sensor2 || body2 == sensor2)
	{
		if (b2pressed == false)
		{
			b2pressed = true;
			App->player->score += 100;
			b2->color = Red;
		}
	}

	if (body1 == sensor3 || body2 == sensor3)
	{
		if (b3pressed == false)
		{
			b3pressed = true;
			App->player->score += 100;
			b3->color = Red;
		}
	}
}

