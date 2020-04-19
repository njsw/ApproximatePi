#ifndef SCREEN_H_
#define SCREEN_H_


#include <SDL.h>
#include <memory>
#include <array>


namespace graphics {

class Screen {
public:
	constexpr static int SCREEN_WIDTH = 800 ;
	constexpr static int SCREEN_HEIGHT = 800;
	constexpr static int ORIGIN_X = SCREEN_WIDTH / 2;
	constexpr static int ORIGIN_Y = SCREEN_HEIGHT / 2;

public:
	Screen();
	virtual ~Screen();
	bool init();
	void update(int iteration, double estimateOfPi);
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	bool processEvents();
	void close();

private:
	std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_;
	std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer_;
	std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture_;
	std::unique_ptr<Uint32[]> primaryBuffer_;
	std::unique_ptr<Uint32[]> secondaryBuffer_;
};

} /* namespace graphics */

#endif /* SCREEN_H_ */
