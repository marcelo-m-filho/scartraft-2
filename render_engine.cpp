#include "render_engine.h"


constexpr auto FPS = 60.0;
constexpr auto SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;

void RenderEngine::init()
{
	al_init_image_addon();


	display = al_create_display(800, 600);
	al_set_window_title(display, "Scartraft 2");

	background = al_load_bitmap("assets/background/terran.tga");
	sideMenu = al_load_bitmap("assets/interface/side-menu.tga");

	sideMenuPosition = SCREEN_WIDTH - al_get_bitmap_width(sideMenu);

}

void RenderEngine::draw()
{
	al_draw_bitmap(background, 0, 0, 0);
	al_draw_bitmap(sideMenu, sideMenuPosition, 0, 0);
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