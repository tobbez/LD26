#include "Util.h"

#include <math.h>
#include <time.h>

void Util::blit_at(SDL_Surface *src, SDL_Surface *dst, unsigned int x, unsigned int y) {
	SDL_Rect r;
	r.x = x;
	r.y = y;
	SDL_BlitSurface(src, NULL, dst, &r);
}

void Util::draw_int(SDL_Surface *font, int cwidth, SDL_Surface *dst, unsigned int x, unsigned int y, std::string const &text)
{
	SDL_Rect dr, sr;
	dr.x = x;
	dr.y = y;

	sr.x = 0;
	sr.y = 0;
	sr.w = cwidth;
	sr.h = font->h;

	for (unsigned int i = 0; i < text.length(); ++i) {
		sr.x = cwidth * (text.at(i) - 48);

		SDL_BlitSurface(font, &sr, dst, &dr);

		dr.x += cwidth + 4;
	}
}

int Util::get_text_width(int cwidth, std::string const &text)
{
	return cwidth * text.length() + 4 * (text.length() - 1);
}

int Util::zround(double d)
{
	return d > 0 ? (int)floor(d) : (int)ceil(d);
}

void Util::Random::init(void)
{
	srand((unsigned int)time(NULL));
}

int Util::Random::random_int(int lower, int upper)
{
	return lower + rand() % upper;
}

// All of this crap because <gcc-4.8.0 does not support to_string in mingw (http://gcc.gnu.org/bugzilla/show_bug.cgi?id=52015)
#if defined(__GNUC__) && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC__MINOR__ < 8))
#define NO_TO_STRING
#endif
#ifdef NO_TO_STRING
#include <sstream>
#endif
std::string Util::to_string(int x)
{
#ifdef NO_TO_STRING
	std::stringstream ss;
	ss << x;
	return ss.str();
#else
	return std::to_string(x);
#endif
}

static int _score;
void Util::Score::set_score(int s)
{
	_score = s;
}
int Util::Score::get_score()
{
	return _score;
}