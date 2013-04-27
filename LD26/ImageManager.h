#pragma once
#include <string>
#include <map>

#include "SDL.h"

namespace ImageManager {
	SDL_Surface *load_image(std::string const &name);
	void unload_all(void);
}