#include "bunker_render.h"



BunkerRender::BunkerRender(ALLEGRO_BITMAP** sprite)
{
	this->sprite = sprite;
	spriteIterator = 0;

	spriteTimer = al_create_timer(BUNKER_ANIMATION_PERIOD);
	al_set_timer_count(spriteTimer, 0);
}

void BunkerRender::startSpriteAnimation()
{
	al_start_timer(spriteTimer);
}

void BunkerRender::render()
{
	spriteIterator = al_get_timer_count(spriteTimer);
	if (spriteIterator >= BUNKER_SPRITES)
	{
		al_stop_timer(spriteTimer);
		al_set_timer_count(spriteTimer, 0);
		spriteIterator = 0;
	}

	al_draw_bitmap(sprite[spriteIterator], 30, 30, 0);
}
