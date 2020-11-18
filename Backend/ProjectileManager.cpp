#pragma once
#include "ProjectileManager.h"
#include "RungeKutta.h"

using namespace std;

ProjectileManager::ProjectileManager(Environment* env, Size projectileSize) {
	projectileSize = projectileSize;

	currentParams.launchAngle = 45;
	currentParams.launchVelocity = 10;
	currentParams.windSpeed = 10;
	currentParams.env = env;

	t_start = Clock::now();
}

void ProjectileManager::setProjectileSize(Size size) {
	projectileSize = size;
}

void ProjectileManager::setWindSpeed(double windSpeed) {
	currentParams.windSpeed = windSpeed;
}

void ProjectileManager::setLaunchVelocity(double launchVelocity) {
	currentParams.launchVelocity = launchVelocity;
}

void ProjectileManager::setLaunchAngle(double launchAngle) {
	currentParams.launchAngle = launchAngle;
}

double ProjectileManager::getWindSpeed() {
	return currentParams.windSpeed;
}

double ProjectileManager::getLaunchVelocity() {
	return currentParams.launchVelocity;
}
	
double ProjectileManager::getLaunchAngle() {
	return currentParams.launchAngle;
}
	
vector<Projectile> ProjectileManager::getLaunchedProjectiles() {
	return launchedProjectiles;
}
	
Projectile ProjectileManager::getProjectile(int index) {
	return launchedProjectiles[index];
}
	
void ProjectileManager::launchCurrent() {
	if (launchedProjectiles.size() == 10) {
		launchedProjectiles.erase(launchedProjectiles.begin());
	}

	colorCounter = (colorCounter + 1) % 10;
	Colors c = (Colors) colorCounter;


	Projectile toLaunch = Projectile(projectileSize, c, currentParams);
	launchedProjectiles.push_back(toLaunch);
}
	
void ProjectileManager::update() {
	Clock::time_point t_update = Clock::now();
	milliseconds ms = chrono::duration_cast<milliseconds>(t_start - t_update);
	double time = ms.count() / 1000.0;

	for (int i = 0; i < launchedProjectiles.size(); i++) {
		if (launchedProjectiles[i].isActive()) {
			RungeKutta(launchedProjectiles[i], dT, time); // TODO get system time
		}
	}
}
	
void ProjectileManager::clear() {
}