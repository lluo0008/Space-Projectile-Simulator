#pragma once

using namespace std;

struct projectileData {
	double x = 0;
	double y = 0;
	double lastX = 0;
	double lastY = 0;
	double speed = 0;
	double lastTime = 0;
};

struct launchParams {
	double launchAngle;
	double launchVelocity;
	double windSpeed;
	// Environment env; TODO implement Environment Class
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

class yeet {

};