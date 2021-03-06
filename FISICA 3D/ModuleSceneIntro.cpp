#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "Timer.h"

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

	music = App->audio->LoadFx("Game/Music/Heavy.ogg");
	//App->audio->PlayMusic("Game/Music/Heavy.ogg");

	App->camera->Move(vec3(8.0f, 8.0f, 40.0f));
	App->camera->LookAt(vec3(0, 0, 60));

	// labyrinth walls

	wall1 = new Cube(70, 10, 10);
	wall1->SetPos(40, 5, -100);
	wall1->color = Pink;
	wall1b = App->physics->AddBody(*wall1, 0);

	wall2 = new Cube(70, 10, 10);
	wall2->SetPos(-40, 5, -100);
	wall2->color = Pink;
	wall2b = App->physics->AddBody(*wall2, 0);

	wall3 = new Cube(10, 10, 270);
	wall3->SetPos(80, 5, 30);
	wall3->color = Pink;
	wall3b = App->physics->AddBody(*wall3, 0);

	wall4 = new Cube(10, 10, 270);
	wall4->SetPos(-80, 5, 30);
	wall4->color = Pink;
	wall4b = App->physics->AddBody(*wall4, 0);

	i_wall1 = new Cube(10, 10, 30);
	i_wall1->SetPos(40, 5, -90);
	i_wall1->color = Pink;
	i_wall1b = App->physics->AddBody(*i_wall1, 0);

	i_wall2 = new Cube(10, 10, 30);
	i_wall2->SetPos(-40, 5, -90);
	i_wall2->color = Pink;
	i_wall2b = App->physics->AddBody(*i_wall2, 0);

	i_wall3 = new Cube(50, 10, 10);
	i_wall3->SetPos(0, 5, -80);
	i_wall3->color = Pink;
	i_wall3b = App->physics->AddBody(*i_wall3, 0);

	i_wall4 = new Cube(30, 10, 10);
	i_wall4->SetPos(50, 5, -80);
	i_wall4->color = Pink;
	i_wall4b = App->physics->AddBody(*i_wall4, 0);

	i_wall5 = new Cube(30, 10, 10);
	i_wall5->SetPos(-50, 5, -80);
	i_wall5->color = Pink;
	i_wall5b = App->physics->AddBody(*i_wall5, 0);

	i_wall6 = new Cube(10, 10, 50);
	i_wall6->SetPos(20, 5, -60);
	i_wall6->color = Pink;
	i_wall6b = App->physics->AddBody(*i_wall6, 0);

	i_wall7 = new Cube(50, 10, 10);
	i_wall7->SetPos(40, 5, -60);
	i_wall7->color = Pink;
	i_wall7b = App->physics->AddBody(*i_wall7, 0);

	i_wall8 = new Cube(10, 10, 30);
	i_wall8->SetPos(-20, 5, -70);
	i_wall8->color = Pink;
	i_wall8b = App->physics->AddBody(*i_wall8, 0);

	i_wall9 = new Cube(50, 10, 10);
	i_wall9->SetPos(-40, 5, -60);
	i_wall9->color = Pink;
	i_wall9b = App->physics->AddBody(*i_wall9, 0);

	i_wall10 = new Cube(110, 10, 10);
	i_wall10->SetPos(-30, 5, -40);
	i_wall10->color = Pink;
	i_wall10b = App->physics->AddBody(*i_wall10, 0);

	i_wall11 = new Cube(50, 10, 10);
	i_wall11->SetPos(60, 5, -40);
	i_wall11->color = Pink;
	i_wall11b = App->physics->AddBody(*i_wall11, 0);

	i_wall12 = new Cube(10, 10, 30);
	i_wall12->SetPos(40, 5, -30);
	i_wall12->color = Pink;
	i_wall12b = App->physics->AddBody(*i_wall12, 0);

	i_wall13 = new Cube(50, 10, 10);
	i_wall13->SetPos(40, 5, -20);
	i_wall13->color = Pink;
	i_wall13b = App->physics->AddBody(*i_wall13, 0);

	i_wall14 = new Cube(90, 10, 10);
	i_wall14->SetPos(-40, 5, -20);
	i_wall14->color = Pink;
	i_wall14b = App->physics->AddBody(*i_wall14, 0);

	i_wall15 = new Cube(10, 10, 30);
	i_wall15->SetPos(0, 5, -10);
	i_wall15->color = Pink;
	i_wall15b = App->physics->AddBody(*i_wall15, 0);

	i_wall16 = new Cube(70, 10, 10);
	i_wall16->SetPos(50, 5, 0);
	i_wall16->color = Pink;
	i_wall16b = App->physics->AddBody(*i_wall16, 0);

	i_wall17 = new Cube(70, 10, 10);
	i_wall17->SetPos(-50, 5, 0);
	i_wall17->color = Pink;
	i_wall17b = App->physics->AddBody(*i_wall17, 0);

	i_wall18 = new Cube(10, 10, 30);
	i_wall18->SetPos(20, 5, 10);
	i_wall18->color = Pink;
	i_wall18b = App->physics->AddBody(*i_wall18, 0);

	i_wall19 = new Cube(50, 10, 10);
	i_wall19->SetPos(40, 5, 20);
	i_wall19->color = Pink;
	i_wall19b = App->physics->AddBody(*i_wall19, 0);

	i_wall20 = new Cube(70, 10, 10);
	i_wall20->SetPos(-30, 5, 20);
	i_wall20->color = Pink;
	i_wall20b = App->physics->AddBody(*i_wall20, 0);

	i_wall21 = new Cube(10, 10, 50);
	i_wall21->SetPos(-60, 5, 40);
	i_wall21->color = Pink;
	i_wall21b = App->physics->AddBody(*i_wall21, 0);

	i_wall22 = new Cube(10, 10, 30);
	i_wall22->SetPos(0, 5, 30);
	i_wall22->color = Pink;
	i_wall22b = App->physics->AddBody(*i_wall22, 0);

	i_wall23 = new Cube(90, 10, 10);
	i_wall23->SetPos(40, 5, 40);
	i_wall23->color = Pink;
	i_wall23b = App->physics->AddBody(*i_wall23, 0);

	i_wall24 = new Cube(10, 10, 50);
	i_wall24->SetPos(-30, 5, 60);
	i_wall24->color = Pink;
	i_wall24b = App->physics->AddBody(*i_wall24, 0);

	i_wall25 = new Cube(100, 10, 10);
	i_wall25->SetPos(15, 5, 60);
	i_wall25->color = Pink;
	i_wall25b = App->physics->AddBody(*i_wall25, 0);

	i_wall26 = new Cube(40, 10, 10);
	i_wall26->SetPos(-45, 5, 80);
	i_wall26->color = Pink;
	i_wall26b = App->physics->AddBody(*i_wall26, 0);

	i_wall27 = new Cube(10, 10, 70);
	i_wall27->SetPos(-60, 5, 110);
	i_wall27->color = Pink;
	i_wall27b = App->physics->AddBody(*i_wall27, 0);

	i_wall28 = new Cube(30, 10, 10);
	i_wall28->SetPos(-50, 5, 140);
	i_wall28->color = Pink;
	i_wall28b = App->physics->AddBody(*i_wall28, 0);

	i_wall29 = new Cube(10, 10, 50);
	i_wall29->SetPos(60, 5, 80);
	i_wall29->color = Pink;
	i_wall29b = App->physics->AddBody(*i_wall29, 0);

	i_wall30 = new Cube(60, 10, 10);
	i_wall30->SetPos(15, 5, 80);
	i_wall30->color = Pink;
	i_wall30b = App->physics->AddBody(*i_wall30, 0);

	i_wall31 = new Cube(110, 10, 10);
	i_wall31->SetPos(10, 5, 100);
	i_wall31->color = Pink;
	i_wall31b = App->physics->AddBody(*i_wall31, 0);

	i_wall32 = new Cube(10, 10, 90);
	i_wall32->SetPos(-10, 5, 120);
	i_wall32->color = Pink;
	i_wall32b = App->physics->AddBody(*i_wall32, 0);

	i_wall33 = new Cube(40, 10, 10);
	i_wall33->SetPos(-25, 5, 120);
	i_wall33->color = Pink;
	i_wall33b = App->physics->AddBody(*i_wall33, 0);

	i_wall34 = new Cube(70, 10, 10);
	i_wall34->SetPos(-40, 5, 160);
	i_wall34->color = Pink;
	i_wall34b = App->physics->AddBody(*i_wall34, 0);

	i_wall35 = new Cube(70, 10, 10);
	i_wall35->SetPos(40, 5, 160);
	i_wall35->color = Pink;
	i_wall35b = App->physics->AddBody(*i_wall35, 0);

	i_wall36 = new Cube(10, 10, 50);
	i_wall36->SetPos(10, 5, 140);
	i_wall36->color = Pink;
	i_wall36b = App->physics->AddBody(*i_wall36, 0);

	i_wall37 = new Cube(50, 10, 10);
	i_wall37->SetPos(30, 5, 100);
	i_wall37->color = Pink;
	i_wall37b = App->physics->AddBody(*i_wall37, 0);

	i_wall38 = new Cube(10, 10, 30);
	i_wall38->SetPos(50, 5, 130);
	i_wall38->color = Pink;
	i_wall38b = App->physics->AddBody(*i_wall38, 0);

	i_wall39 = new Cube(30, 10, 10);
	i_wall39->SetPos(40, 5, 140);
	i_wall39->color = Pink;
	i_wall39b = App->physics->AddBody(*i_wall39, 0);

	i_wall40 = new Cube(50, 10, 10);
	i_wall40->SetPos(30, 5, 120);
	i_wall40->color = Pink;
	i_wall40b = App->physics->AddBody(*i_wall40, 0);

	i_wall41 = new Cube(20, 10, 0);
	i_wall41->SetPos(0, 5, 167);
	i_wall41b = App->physics->AddBody(*i_wall41, 0);

	i_wall42 = new Cube(20, 10, 0);
	i_wall42->SetPos(0, 0, -105);
	i_wall42b = App->physics->AddBody(*i_wall42, 0);

	// buttons and sensors
	
	b1 = new Cube(10, 0.1f, 10);
	b1->SetPos(0, 0, -70);
	b1->color = Green;
	b1b = App->physics->AddBody(*b1, 0);

	s = new Cube(10, 10, 10);
	s->SetPos(0, 0, -70);
	sensor = App->physics->AddBody(*s, 0.0f);
	sensor->SetAsSensor(true);
	sensor->collision_listeners.add(this);

	b2 = new Cube(10, 0.1f, 10);
	b2->SetPos(0, 0, 90);
	b2->color = Green;
	b2b = App->physics->AddBody(*b2, 0);

	s2 = new Cube(10, 10, 10);
	s2->SetPos(0, 5, 90);
	sensor2 = App->physics->AddBody(*s2, 0.0f);
	sensor2->SetAsSensor(true);
	sensor2->collision_listeners.add(this);

	b4 = new Cube(10, 0.1f, 10);
	b4->SetPos(40, 0, 130);
	b4->color = Green;
	b4b = App->physics->AddBody(*b4, 0);

	s4 = new Cube(10, 10, 10);
	s4->SetPos(40, 5, 130);
	sensor4 = App->physics->AddBody(*s4, 0.0f);
	sensor4->SetAsSensor(true);
	sensor4->collision_listeners.add(this);

	//last sensor, needs to be pressed to open the gate

	end = new Cube(10, 0.1f, 10);
	end->SetPos(0, 0, 160);
	end->color = Green;
	endb = App->physics->AddBody(*end, 0);

	s5 = new Cube(10, 10, 10);
	s5->SetPos(0, 5, 160);
	sensor5 = App->physics->AddBody(*s5, 0.0f);
	sensor5->SetAsSensor(true);
	sensor5->collision_listeners.add(this);

	b1pressed = false;
	b2pressed = false;
	b3pressed = false;
	b4pressed = false;
	endpressed = false;
	win_condit = false;

	//end / start doors
	door = new Cube(7, 8, 1);
	door->SetPos(1, 5, 140);
	doorb = App->physics->AddBody(*door, 1);

	pivot = new Cube(1, 1, 1);
	pivot->SetPos(4, 5, 140);
	pivotb = App->physics->AddBody(*pivot, 0);

	App->physics->AddConstraintHinge(*doorb, *pivotb, { 4.5, 0, 0 }, { 0, 0, 0 }, {0, 1, 0}, { 0,1, 0}, true);
	
	//140
	door2 = new Cube(7, 8, 1);
	door2->SetPos(1, 5, 20);
	door2b = App->physics->AddBody(*door2, 1);

	pivot2 = new Cube(1, 1, 1);
	pivot2->SetPos(4, 5, 20);
	pivot2b = App->physics->AddBody(*pivot2, 0);

	App->physics->AddConstraintHinge(*door2b, *pivot2b, { 4.5, 0, 0 }, { 0, 0, 0 }, { 0, 1, 0 }, { 0,1, 0 }, true);

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
	mat4x4 m;
	doorb->GetTransform(&m);
	door->transform = m;
	door->Render();

	doorb->body->applyForce({ 0,-100,0 }, { 0, 4, 0 });

	mat4x4 m2;
	door2b->GetTransform(&m2);
	door2->transform = m2;
	door2->Render();

	door2b->body->applyForce({ 0,-100, 0 }, { 0, 4, 0 });

	Cube p(1000, 0, 10000);
	//p.axis = true;
	p.color = Black;
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
	b4->Render();
	end->Render();
	

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{

	if (body1 == (PhysBody3D*)App->player->vehicle || body2 == (PhysBody3D*)App->player->vehicle)
	{
		if (body1 == sensor || body2 == sensor)
		{
			if (b1pressed == false)
			{
				b1pressed = true;
				App->player->score += 100;
				b1->color = Red;
				LOG("Hit 1!");
			}
		}

		if (body1 == sensor2 || body2 == sensor2)
		{
			if (b2pressed == false)
			{
				b2pressed = true;
				App->player->score += 200;
				b2->color = Red;
				LOG("Hit 2!");
			}
		}

		if (body1 == sensor4 || body2 == sensor4)
		{
			if (b4pressed == false)
			{
				b4pressed = true;
				App->player->score += 300;
				b4->color = Red;
				LOG("Hit 4!")
			}
		}

		if (body1 == sensor5 || body2 == sensor5)
		{
			if (endpressed == false)
			{
				endpressed = true;
				win_condit = true;
				App->player->score += 500;
				App->player->max_score = App->player->score;
				end->color = Red;
				LOG("Hit End!")
			}
		}
	}
}

