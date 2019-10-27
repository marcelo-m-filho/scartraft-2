#pragma once

#include <allegro5/allegro.h>

constexpr auto BUNKER_SPRITES = 6;
constexpr auto BUNKER_ANIMATION_PERIOD = (1.0 / 20.0);

class BunkerRender
{
public:
	ALLEGRO_BITMAP** sprite;
	ALLEGRO_TIMER* spriteTimer;

	int spriteIterator;

	BunkerRender(ALLEGRO_BITMAP** sprite);

	void startSpriteAnimation();

	void render();
};

