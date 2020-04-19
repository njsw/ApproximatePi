#include "Particle.h"
#include <math.h>
#include <stdlib.h>


namespace graphics {

Particle::Particle() : x_(((2.0 * rand()) / RAND_MAX) - 1), y_(((2.0 * rand()) / RAND_MAX) - 1) {
	//
}

Particle::~Particle() {
	//
}

double Particle::x() {
	return x_;
}

double Particle::y() {
	return y_;
}

} /* namespace graphics */
