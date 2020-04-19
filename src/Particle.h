#ifndef PARTICLE_H_
#define PARTICLE_H_


namespace graphics {

class Particle {
public:
	Particle();
	virtual ~Particle();
	double x();
	double y();

private:
	double x_;
	double y_;
};

} /* namespace graphics */

#endif /* PARTICLE_H_ */
