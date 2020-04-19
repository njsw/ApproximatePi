/*
 * Swarm.cpp
 *
 *  Created on: Apr 4, 2020
 *      Author: nlowing
 */

#include "Swarm.h"

namespace graphics {

Swarm::Swarm() : numParticles_(0) {
	//
}

Swarm::~Swarm() {
	//
}

const std::vector<Particle> Swarm::getParticles() {
	return particles_;
}

void Swarm::addNewParticle(Particle& particle) {
	particles_.push_back(particle);
	numParticles_++;
}

unsigned int Swarm::getNumParticles() {
	return numParticles_;
}

} /* namespace graphics */
