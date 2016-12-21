#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(1.85, 1.0, 2.1);
	car.chassis_offset.Set(0, 0.1, 0);
	car.mass = 150.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 0.3f;
	float wheel_radius = 0.3f;
	float wheel_width = 0.3f;
	float suspensionRestLength = 0.7f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;

	vec3 direction(0, -1, 0);
	vec3 axis(1, 0, 0);

	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(0, 0, -100);
	App->camera->Follow(vehicle, 5, 15, 1.f);

	vehicle->GetTransform(&transf);

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = 0.0f;

	if (lives > 0)
	{
		if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		{
			acceleration = MAX_ACCELERATION;
		}

		if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		{
			if (turn > -TURN_DEGREES)
				turn -= TURN_DEGREES;
		}

		if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		{
			if (turn < TURN_DEGREES)
				turn += TURN_DEGREES;
		}

		if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		{
			acceleration = -(MAX_ACCELERATION);
		}

		if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
		{
			brake = BRAKE_POWER;
		}


		if (App->input->GetKey(SDL_SCANCODE_N) == KEY_DOWN)
		{
			if (lives > 0)
			{
				--lives;
				vehicle->SetPos(0, 0, -100);
				vehicle->Brake(BRAKE_POWER);
				vehicle->SetTransform(&transf);
			}
		}

		vehicle->ApplyEngineForce(-(acceleration));
		vehicle->Turn(-(turn));
		vehicle->Brake(brake);

		vehicle->Render();

		time = (float)App->scene_intro->pTime.Read() / 1000;

		char title[200];
		sprintf_s(title, "Press all the buttons and get out of the labyrinth!, Lives (press 'N' to reset): %u, Score: %u, Max Score: %u, Time: %.2f", lives, score, max_score, time);
		App->window->SetTitle(title);
	}

	if (lives == 0)
	{
		max_score = score;
		App->scene_intro->pTime.Stop();
		
		char title[200];
		sprintf_s(title, "GAME OVER. Press 'ENTER' to play again. Score: %u, Max Score: %u, Time elapsed: %.2f", score, max_score, App->scene_intro->pTime.Read());
		App->window->SetTitle(title);
		App->audio->PlayFx(App->scene_intro->lose);

		if (App->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN)
		{
			Restart();
		}
	}

	if (App->scene_intro->win_condit)
	{
		if (lives > 1)
		{
			score += (lives * 100); //bonus if you finish with extra lives!
		}

		max_score += score;
		App->scene_intro->pTime.Stop();

		char title[200];
		sprintf_s(title, "WINNER!!! Press 'ENTER' to play again. Score %u, Max Score: %u, Time elapsed: %.2f", score, max_score, App->scene_intro->pTime.Read());

		if (App->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN)
		{
			Restart();
		}
	}

	return UPDATE_CONTINUE;
}

void ModulePlayer::Restart()
{
	lives = 5;
	score = 0;
	vehicle->SetPos(0, 0, -100);
	vehicle->SetTransform(&transf);

	App->scene_intro->b1pressed = false;
	App->scene_intro->b2pressed = false;
	App->scene_intro->b3pressed = false;
	App->scene_intro->b4pressed = false;
	App->scene_intro->endpressed = false;
	App->scene_intro->win_condit = false;

	App->scene_intro->b1->color = Green;
	App->scene_intro->b2->color = Green;
	App->scene_intro->b3->color = Green;
	App->scene_intro->b4->color = Green;
	App->scene_intro->end->color = Green;

	// needs to reset timer!
	App->scene_intro->pTime.Start();
}
