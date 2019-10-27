#pragma once

#include <allegro5/allegro.h>
#include "render_engine.h"

class LogicEngine
{
	double FPS = 60.0;

	ALLEGRO_EVENT_QUEUE* eventQueue = al_create_event_queue();
	ALLEGRO_TIMER* gameLoopTimer = al_create_timer(1.0 / FPS);

	RenderEngine* renderEngine;

public:
	LogicEngine(RenderEngine* renderEngine);

	bool mainLoop();
	void finalizeLogic();
};

