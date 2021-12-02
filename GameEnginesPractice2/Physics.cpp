#include "Physics.h"
#include <cmath>

Physics::Physics()
{
}

Physics::~Physics()
{
}

void Physics::Update(float time)
{
	for (auto& body : bodies) {
		float curr_time = (time - body.start_time) / body.period * 6.28f;
		body.pos[0] = body.orbit * cos(curr_time);
		body.pos[1] = body.orbit * sin(curr_time);
	}
}

void Physics::addBody(Info body)
{
	bodies.push_back(body);
}

Physics::Info Physics::getBodyInfo(unsigned num)
{
	return bodies[num];
}

Physics::Info::Info(Ogre::Vector3 position, Ogre::Vector3 velocity, float mass, float radius)
	: pos(position), vel(velocity), m(mass), r(radius) {
	// assumption that orbit are circle and non-gravitational
	orbit = pos.distance({ 0, 0, 0 });
	period = 6.28f * orbit / vel.distance({0, 0, 0});
	float angle = (pos[1] >= 0) ? std::acosf(pos[0] / orbit) : 2 * 3.14f - std::acosf(pos[0] / orbit);
	start_time = angle * period / 6.28f;
}
