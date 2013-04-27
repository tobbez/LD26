#pragma once
#include <string>
#include "SDL.h"


namespace Util {
	void blit_at(SDL_Surface *src, SDL_Surface *dst, unsigned int x, unsigned int y);

	void draw_int(SDL_Surface *font, int cwidth, SDL_Surface *dst, unsigned int x, unsigned int y, std::string const &text);
	int get_text_width(int cwidth, std::string const &text);

	int zround(double d);

	namespace Random {
		void init();
		int random_int(int lower, int upper);
	}

	std::string to_string(int x);

	// Time for ugly hacks
	namespace Score {
		void set_score(int s);
		int get_score();
	}
}