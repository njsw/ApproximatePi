#include "Screen.h"
#include <string>


namespace graphics {

Screen::Screen() : window_(nullptr, SDL_DestroyWindow),
		renderer_(nullptr, SDL_DestroyRenderer),
		texture_(nullptr, SDL_DestroyTexture),
		primaryBuffer_(nullptr),
		secondaryBuffer_(nullptr) {
	//
}

Screen::~Screen() {
	//
}

bool Screen::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	window_.reset(SDL_CreateWindow("Approximation of Pi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN));

	if (window_ == nullptr) {
		SDL_Quit();
		return false;
	}

	renderer_.reset(SDL_CreateRenderer(window_.get(), -1, SDL_RENDERER_PRESENTVSYNC));
	texture_.reset(SDL_CreateTexture(renderer_.get(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH,
			SCREEN_HEIGHT));

	if (renderer_ == nullptr) {
		SDL_Quit();
		return false;
	}

	if (texture_ == nullptr) {
		SDL_Quit();
		return false;
	}

	primaryBuffer_ = std::make_unique<Uint32[]>(SCREEN_WIDTH*SCREEN_HEIGHT);
	secondaryBuffer_ = std::make_unique<Uint32[]>(SCREEN_WIDTH*SCREEN_HEIGHT);
	memset(primaryBuffer_.get(), 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	memset(secondaryBuffer_.get(), 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	return true;
}

void Screen::update(int iteration, double estimateOfPi) {
	std::string title = "Approximation of Pi  |  Iteration = " + std::to_string(iteration) + "  |  Current Estimate = "
			+ std::to_string(estimateOfPi);
	const char* titleUpdate = title.c_str();
	SDL_SetWindowTitle(window_.get(), titleUpdate);

	SDL_UpdateTexture(texture_.get(), NULL, primaryBuffer_.get(), SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(renderer_.get());
	SDL_RenderCopy(renderer_.get(), texture_.get(), NULL, NULL);
	SDL_RenderPresent(renderer_.get());
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
		return;
	}

	Uint32 color = 0;
	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	primaryBuffer_[(y * SCREEN_WIDTH) + x] = color;
}

bool Screen::processEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}

	return true;
}

void Screen::close() {
	SDL_Quit();
}

} /* namespace graphics */
