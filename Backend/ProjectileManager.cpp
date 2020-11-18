#pragma once
#include "ProjectileManager.h"
#include "RungeKutta.h"

using namespace std;

ProjectileManager::ProjectileManager(Environment* env, Size projectileSize) {
	this->projectileSize = projectileSize;

	currentParams.launchAngle = 45;
	currentParams.launchVelocity = 30;
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

Size ProjectileManager::getProjectileSize() {
	return projectileSize;
}

void ProjectileManager::launchCurrent() {
	if (launchedProjectiles.size() == 10) {
		launchedProjectiles.erase(launchedProjectiles.begin());
	}

	colorCounter = (colorCounter + 1) % 10;
	Colors c = (Colors) colorCounter;

	Projectile toLaunch = Projectile(projectileSize, c, currentParams);

	projectileData launchData;
	launchData.vx = currentParams.launchVelocity * cos(currentParams.launchAngle);
	launchData.vy = currentParams.launchVelocity * sin(currentParams.launchAngle);
	toLaunch.setData(launchData);

	launchedProjectiles.push_back(toLaunch);
}
	
void ProjectileManager::update() {
	Clock::time_point t_update = Clock::now();
	milliseconds ms = chrono::duration_cast<milliseconds>(t_update - t_start);
	double time = ms.count() / 1000.0;

	for (int i = 0; i < launchedProjectiles.size(); i++) {
		if (launchedProjectiles[i].isActive()) {
			vector<double> temp = RungeKutta(launchedProjectiles[i], dT, time);
			projectileData tempData = launchedProjectiles[i].getData();
			tempData.vx += temp[2];
			tempData.vy += temp[3];
			// calculate current positions
			tempData.lastX = tempData.x;
			tempData.lastY = tempData.y;
			tempData.x += tempData.vx * dT;
			tempData.y += tempData.vy * dT;
			
			launchedProjectiles[i].setData(tempData);
		}
	}
}
	
void ProjectileManager::clear() {
}