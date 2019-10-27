#include "logic_engine.h"

LogicEngine::LogicEngine(RenderEngine* renderEngine)
{
	this->renderEngine = renderEngine;
	al_install_mouse();
	al_register_event_source(eventQueue, al_get_display_event_source(this->renderEngine->getDisplay()));
	al_register_event_source(eventQueue, al_get_timer_event_source(gameLoopTimer));
	al_register_event_source(eventQueue, al_get_mouse_event_source());
	al_start_timer(gameLoopTimer);
}

bool LogicEngine::mainLoop()
{
	bool status = true;
	ALLEGRO_EVENT event;
	al_wait_for_event(eventQueue, &event);

	switch (event.type)
	{
	case ALLEGRO_EVENT_DISPLAY_CLOSE:
		status = false;
		break;
	case ALLEGRO_EVENT_TIMER:
		renderEngine->draw();
		break;
	case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
		renderEngine->attack();
	default:
		break;
	}
	return status;
}

void LogicEngine::finalizeLogic()
{
	al_destroy_timer(gameLoopTimer);
}