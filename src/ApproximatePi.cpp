#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "Screen.h"
#include "Particle.h"
#include "Swarm.h"
using namespace graphics;


int main() {
	Screen screen;

	if (screen.init() == false) {
		std::cout << "Error initializing SDL." << std::endl;
	}

	Uint8 red = 0xFF;
	Uint8 green = 0xFF;
	Uint8 blue = 0xFF;

	Swarm swarm;

	unsigned int iteration = 1;
	int countIn = 0;
	int countOut = 0;
	double estimateOfPi = 0.0;
	while (iteration < Swarm::NUM_PARTICLES) {
		Particle particle;
		swarm.addNewParticle(particle);

		const std::vector<Particle> particles = swarm.getParticles();

		for (auto i = 0; i < swarm.getNumParticles(); i++) {
			Particle particle = particles.at(i);

			int x = (int) (Screen::ORIGIN_X + particle.x()*100);
			int y = (int) (Screen::ORIGIN_Y - particle.y()*100);

			if (sqrt(particle.x()*particle.x() + particle.y()*particle.y()) > 1.0) {
				screen.setPixel(x, y, red, 0, 0);
				countOut++;
			} else {
				screen.setPixel(x, y, red, green, blue);
				countIn++;
			}
		}

		estimateOfPi = 4.0 * countIn / (countIn + countOut);

		screen.update(iteration++, estimateOfPi);

		if (!screen.processEvents()) {
			break;
		}
	}

	screen.close();

	return 0;
}
