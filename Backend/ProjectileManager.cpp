#pragma once
#include "ProjectileManager.h"

using namespace std;

class ProjectileManager::ProjectileManager {
private:
	Size projectileSize;
	const double dT;
	launchParams currentParams;

public:
	ProjectileManager(Environment env, Size projectileSize) {
		this->projectileSize = projectileSize;

		this->currentParams.launchAngle = 45;
		this->currentParams.launchVelocity = 10;
		this->currentParams.windSpeed = env.getWind_speed();
		this->currentParams.env = env;
	}

	void setProjectileSize(Size size) {
		this->projectileSize = size;
	}

	void setWindSpeed(double windSpeed) {
		this->currentParams.windSpeed = windSpeed;
	}

	void setLaunchVelocity(double launchVelocity) {
		this->currentParams.launchVelocity = launchVelocity;
	}

	void setLaunchAngle(double launchAngle) {
		this->currentParams.launchAngle = launchAngle;
	}

	double getWindSpeed() {
		return this->currentParams.windSpeed;
	}

	double getLaunchVelocity() {
		return this->currentParams.launchVelocity;
	}
	
	double getLaunchAngle() {
		return this->currentParams.launchAngle;
	}
	
	vector<Projectile> getLaunchedProjectiles();
	
	Projectile getProjectile(int index);
	
	void launchCurrent();
	
	void update();
	
	void clear();
};