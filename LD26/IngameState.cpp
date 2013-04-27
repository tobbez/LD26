#include <string>

#include "IngameState.h"
#include "ImageManager.h"
#include "Util.h"


using Util::blit_at;
using Util::zround;

STATE_TYPE IngameState::advance(SDL_Surface *screen, Uint8 *keys)
{
	double movement_speed = 0.045;
	if (keys[SDLK_LEFT]) {
		player->dx -= movement_speed;
	}
	if (keys[SDLK_RIGHT]) {
		player->dx += movement_speed;
	}
	if (keys[SDLK_UP]) {
		player->dy -= movement_speed;
	}
	if (keys[SDLK_DOWN]) {
		player->dy += movement_speed;
	}

	player->advance();

	if (player->x < 0) {
		player->x = 0;
		if (player->dx < 0) {
			player->dx = 0;
		}
	}
	if (player->x + player->image->w > screen->w) {
		player->x = screen->w - player->image->w;
		if (player->dx > 0) {
			player->dx = 0;
		}
	}

	if (player->y < 0) {
		player->y = 0;
		if (player->dy < 0) {
			player->dy = 0;
		}
	}
	if (player->y + player->image->h > screen->h) {
		player->y = screen->h - player->image->h;
		if (player->dy > 0) {
			player->dy = 0;
		}
	}


	if (player->overlaps(*potato)) {
		timeleft += 6;
		Util::Score::set_score(Util::Score::get_score() + 1);
		new_round();
	}

	SDL_FillRect(screen, NULL, 0);
	blit_at(potato->image, screen, zround(potato->x), zround(potato->y));
	blit_at(player->image, screen, zround(player->x), zround(player->y));

	Util::draw_int(ImageManager::load_image("numbers"), 35, screen, screen->w - Util::get_text_width(35, Util::to_string((int)timeleft)), 4, Util::to_string((int)timeleft));

	ticks++;
	if (ticks % 100 == 0) {
		timeleft--;
	}

	if (timeleft == 0) {
		next_state = STATE_TYPE::GAMEOVER;
	}

	return next_state;
}

void IngameState::new_round()
{
	delete player;
	delete potato;
	player = new Sprite("player");
	potato = new Sprite("potato");

	player->x = Util::Random::random_int(0, 800 - player->image->w);
	player->y = Util::Random::random_int(0, 600 - player->image->h);

	do {
		potato->x = Util::Random::random_int(0, 800 - player->image->w);
		potato->y = Util::Random::random_int(0, 600 - player->image->h);
	} while(player->overlaps(*potato));
}

void IngameState::handle_event(SDL_Event const &ev)
{
	if (ev.type == SDL_KEYUP && ev.key.keysym.sym == SDLK_ESCAPE) {
		next_state = STATE_TYPE::MENU;
	}
}

IngameState::IngameState(void) 
	: player(NULL), potato(NULL)
{
	next_state = STATE_TYPE::INGAME;

	new_round();

	timeleft = 56;

	ticks = 0;

	Util::Score::set_score(0);
}


IngameState::~IngameState(void)
{
}
