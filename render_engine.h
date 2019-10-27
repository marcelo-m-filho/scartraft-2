#pragma once

#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/events.h>

class RenderEngine
{
private:
	ALLEGRO_DISPLAY *display;
	ALLEGRO_BITMAP *background, *sideMenu;
	int sideMenuPosition;
public:
	void init();
	void draw();
	ALLEGRO_DISPLAY* getDisplay();
	void finalizeRender();
};

