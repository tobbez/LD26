#pragma once
#include <string>

#include "SDL.h"

class Sprite
{
public:
	Sprite(std::string const &name);
	~Sprite(void);

	void advance();

	bool overlaps(Sprite const &other);

	double x;
	double y;

	double dx;
	double dy;

	SDL_Surface *image;
};

