#include <string>
#include <map>

#include "SDL.h"
#include "SDL_image.h"

#include "ImageManager.h"


static std::map<std::string, SDL_Surface*> _images;
SDL_Surface *ImageManager::load_image(std::string const &name) {
	std::string path = "images/" + name + ".png";
	if (_images.find(path) == _images.end()) {
		_images[path] = IMG_Load(path.c_str());
	}

	return _images[path];
}

void ImageManager::unload_all(void){
	auto it = _images.begin();
	while (it != _images.end())
	{
		SDL_FreeSurface(it->second);
		it = _images.erase(it);
	}
}