#pragma once
#include <vector>
#include "Projectile.h"
#include "Environment.h"

using namespace std;

struct projectileData {
	double x = 0;
	double y = 0;
	double lastX = 0;
	double lastY = 0;
	double vx = 0;
	double vy = 0;
	double speed = 0;
	double lastTime = 0;
};

struct launchParams {
	double launchAngle;
	double launchVelocity;
	double windSpeed;
	Environment env;
};

enum Size { SMALL, MEDIUM, LARGE };

enum Colors {
	RED,
	GREEN,
	BLUE,
	ORANGE,
	YELLOW,
	PINK,
	BLACK, 
	WHITE,
	PURPLE,
	BROWN,
};

enum Environments {
	EARTH,
	MARS,
	JUPITER,
	MOON
};

class ProjectileManager {
private:
	Size projectileSize;
	const double dT;
	launchParams currentParams;

public:
	ProjectileManager(Environment env, Size projectileSize);
	void setProjectileSize(Size size);
	void setWindSpeed(double windSpeed);
	void setLaunchVelocity(double launchVelocity);
	void setLaunchAngle(double launchAngle);
	double getWindSpeed();
	double getLaunchVelocity();
	double getLaunchAngle();
	vector<Projectile> getLaunchedProjectiles();
	Projectile getProjectile(int index);
	void launchCurrent();
	void update();
	void clear();
};