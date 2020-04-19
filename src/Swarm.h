#ifndef SWARM_H_
#define SWARM_H_


#include "Particle.h"
#include <vector>


namespace graphics {

class Swarm {
public:
	constexpr static int NUM_PARTICLES = 1000000;

public:
	Swarm();
	virtual ~Swarm();
	const std::vector<Particle> getParticles();
	void addNewParticle(Particle& particle);
	unsigned int getNumParticles();

private:
	std::vector<Particle> particles_;
	unsigned int numParticles_;
};

} /* namespace graphics */

#endif /* SWARM_H_ */
