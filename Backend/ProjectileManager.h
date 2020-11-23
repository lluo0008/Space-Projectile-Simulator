#pragma once
#include <vector>
#include <chrono>
#include "Projectile.h"
#include "Environment.h"
#include "DataStructures.h"

using namespace std;

typedef chrono::high_resolution_clock Clock;
typedef chrono::milliseconds milliseconds;

class ProjectileManager {
private:
	Size projectileSize;
	const double dT = 0.05;
	launchParams currentParams;
	vector<Projectile> launchedProjectiles;
	int colorCounter = 0;
	Clock::time_point t_start;

	void clear();

public:
	ProjectileManager(Environment* env, Size projectileSize);
	void setProjectileSize(Size size);
	void setWindSpeed(double windSpeed);
	void setLaunchVelocity(double launchVelocity);
	void setLaunchAngle(double launchAngle);
	double getWindSpeed();
	double getLaunchVelocity();
	double getLaunchAngle();
	Size getProjectileSize();
	vector<Projectile> getLaunchedProjectiles();
	Projectile getProjectile(int index);
	void launchCurrent();
	void update();
};