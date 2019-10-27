#pragma once

#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/events.h>

#include "bunker_render.h"

class RenderEngine
{
private:
	ALLEGRO_DISPLAY *display;
	ALLEGRO_BITMAP *background, *sideMenu;
	int sideMenuPosition;

	BunkerRender *bunkerRender;
	ALLEGRO_BITMAP* bunkerSprite[6];

	void renderBackground();
	void renderInterface();
	void renderTowers();
	void renderCreeps();


	void loadSprite(ALLEGRO_BITMAP** container, const char* path, int size);

public:
	void attack();
	void init();
	void draw();
	ALLEGRO_DISPLAY* getDisplay();
	void finalizeRender();
};

