#include "render_engine.h"
#include <sstream>


constexpr auto FPS = 60.0;
constexpr auto SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;

inline void RenderEngine::renderBackground()
{
	al_draw_bitmap(background, 0, 0, 0);
}

inline void RenderEngine::renderInterface()
{
	al_draw_bitmap(sideMenu, sideMenuPosition, 0, 0);
}

inline void RenderEngine::renderTowers()
{
	bunkerRender->render();
}

inline void RenderEngine::renderCreeps()
{

}

void RenderEngine::attack()
{
	bunkerRender->startSpriteAnimation();
}

void RenderEngine::loadSprite(ALLEGRO_BITMAP** container, const char* path, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::ostringstream oss;
		oss << path << "_" << i + 1 << ".tga";
		container[i] = al_load_bitmap(oss.str().c_str());
	}
}

void RenderEngine::init()
{
	al_init_image_addon();

	display = al_create_display(800, 600);
	al_set_window_title(display, "Scartraft 2");

	background = al_load_bitmap("assets/background/terran.tga");
	sideMenu = al_load_bitmap("assets/interface/side-menu.tga");

	loadSprite(bunkerSprite, "assets/towers/bunker/bunker", BUNKER_SPRITES);

	bunkerRender = new BunkerRender(bunkerSprite);

	sideMenuPosition = SCREEN_WIDTH - al_get_bitmap_width(sideMenu);

}

void RenderEngine::draw()
{
	renderBackground();
	renderInterface();
	renderTowers();
	renderCreeps();

	al_flip_display();
}

ALLEGRO_DISPLAY* RenderEngine::getDisplay()
{
	return display;
}

void RenderEngine::finalizeRender()
{
	al_destroy_display(display);
}