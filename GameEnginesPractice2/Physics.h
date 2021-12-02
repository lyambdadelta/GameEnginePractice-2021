#pragma once
#include <array>
#include <vector>
#include "Ogre.h"

class Physics {
public:
	struct Info {
		Ogre::Vector3 pos, vel;
		float m, r, orbit, period, start_time;
		Info(Ogre::Vector3 position, Ogre::Vector3 velocity, float mass, float radius);
	};

	Physics();
	~Physics();
	Physics(const Physics&) = delete;
	Physics& operator=(const Physics&) = delete;

	void Update(float time);

	void addBody(Info body);

	Info getBodyInfo(unsigned num);

private:
	std::vector<Info> bodies;
};
