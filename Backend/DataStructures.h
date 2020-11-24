#pragma once

using namespace std;

class Environment;

struct projectileData {
	double x = 0;
	double y = 50;
	double lastX = 0;
	double lastY = 0;
	double vx = 0;
	double vy = 0;
	double speed = 0;
	double lastTime = 0;
	double launchTime = 0;
};

struct launchParams {
	double launchAngle;
	double launchVelocity;
	double windSpeed;
	Environment* env;
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
	MOON,
	MARS,
	JUPITER
};
