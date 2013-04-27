#include "GameoverState.h"
#include "ImageManager.h"
#include "Util.h"


STATE_TYPE GameoverState::advance(SDL_Surface *screen, Uint8 *keys)
{
	SDL_FillRect(screen, NULL, 0);
	std::string score_text = Util::to_string(Util::Score::get_score());
	SDL_Surface *font = ImageManager::load_image("numbers-large");
	Util::draw_int(font, 105, screen, screen->w/2 - Util::get_text_width(105, score_text)/2, screen->h/5 - font->h/2, score_text);

	int score = Util::Score::get_score();
	SDL_Surface *text = NULL;
	if (score == 0) {
		text = ImageManager::load_image("gameover-0");
	} else if (score <= 6) {
		text = ImageManager::load_image("gameover-1");
	} else if (score <= 13) {
		text = ImageManager::load_image("gameover-2");
	} else if (score <= 16) {
		text = ImageManager::load_image("gameover-3");
	} else {
		text = ImageManager::load_image("gameover-4");
	}

	Util::blit_at(text, screen, screen->w / 2 - text->w / 2, screen->h/3 * 2 - text->h/2);

	return next_state;
}

void GameoverState::handle_event(SDL_Event const &ev)
{
	if (ev.type == SDL_KEYUP && (ev.key.keysym.sym == SDLK_SPACE || ev.key.keysym.sym == SDLK_ESCAPE)) {
		next_state = STATE_TYPE::MENU;
	}
}

GameoverState::GameoverState(void)
{
	next_state = STATE_TYPE::GAMEOVER;
}


GameoverState::~GameoverState(void)
{
}
