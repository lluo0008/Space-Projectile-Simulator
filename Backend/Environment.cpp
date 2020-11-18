/**
 * Lily de Loe
 * 2020/10/26
 */

#include "Environment.h"

using namespace std;
double wind_speed;
double windSpeed;
double airDensity;
double gravity;

EnvironmentException::EnvironmentException(string message) {
    message = "Warning: environment exception";
}

Environment::Environment(Environments e, double wind) {
        switch (e) {
        case EARTH:
            windSpeed = 11.1;
            airDensity = 1.2;
            gravity = 9.807;
            break;
        case MARS:
            windSpeed = 22;
            airDensity = 0.020;
            gravity = 3.711;
            break;
        case JUPITER:
            windSpeed = 384;
            airDensity = 1326;
            gravity = 24.79;
            break;
        case MOON:
            windSpeed = 0;
            airDensity = 0;
            gravity = 1.62;
            break;
        }

        wind_speed = wind;
        //checks if the wind is outside the bounds
        if (wind < -20 || wind > 20) {
            throw new EnvironmentException("Warning: wind speed not within the bounds of -20 to 20");
        }
        //convert to m/s
        wind_speed = wind * 1000. / 3600.;
} //end Environment

double getWind_speed() {
    return wind_speed;
} //end getWind_speed

void setWind_speed(double wind){
        if (wind < -20 || wind > 20) {
            throw new EnvironmentException("Warning: wind speed not within the bounds of -20 to 20");
        }
        //convert to m/s
        wind_speed = wind * 1000. / 3600.;
} //end setWind_speed
