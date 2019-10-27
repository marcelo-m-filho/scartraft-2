#include <allegro5/allegro.h>
#include "render_engine.h"
#include "logic_engine.h"

constexpr auto FPS = 60.0;

int main()
{
	al_init();

	RenderEngine renderEngine;
	renderEngine.init();
	LogicEngine logicEngine(&renderEngine);

	auto running = true;
	while (running)
		running = logicEngine.mainLoop();

	renderEngine.finalizeRender();
	logicEngine.finalizeLogic();
}