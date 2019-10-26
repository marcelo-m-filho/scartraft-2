#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/events.h>

int main()
{
	al_init();

	auto display = al_create_display(800, 600);

	//auto eventQueue = al_create_event_queue();
	//al_register_event_source(eventQueue, al_get_display_event_source(display));
	
	al_init_image_addon();

	auto background = al_load_bitmap("assets/background/terran.tga");

	while (true) {
		al_draw_bitmap(background, 0, 0, 0);		
		al_flip_display();
	}
}