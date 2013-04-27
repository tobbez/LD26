#include "Sprite.h"
#include "ImageManager.h"

void Sprite::advance(void)
{
	x += dx;
	y += dy;

	dx *= 0.9;
	dy *= 0.9;
}

bool Sprite::overlaps(Sprite const &other)
{
	if (x + image->w < other.x) return false;
	if (other.x + other.image->w < x) return false;

	if (y + image->h < other.y) return false;
	if (other.y + other.image->h < y) return false;

	return true;
}

Sprite::Sprite(std::string const &name)
{
	x = 0;
	y = 0;

	dx = 0;
	dy = 0;

	image = ImageManager::load_image(name);
}

Sprite::~Sprite(void)
{
}
