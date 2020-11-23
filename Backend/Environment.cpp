/**
 * Lily de Loe
 * 2020/10/26
 */

#include "Environment.h"

using namespace std;

EnvironmentException::EnvironmentException(string message) {
    message = "Warning: environment exception";
}

Environment::Environment(Environments e, double wind) {
    //checks if the wind is outside the bounds
    if (wind < -20 || wind > 20) {
        throw new EnvironmentException("Warning: wind speed not within the bounds of -20 to 20");
        return;
    }
    switch (e) {
        case EARTH:
            AIR_DENSITY = 1.2;
            G = 9.807;
            break;
        case MARS:
            AIR_DENSITY = 0.020;
            G = 3.711;
            break;
        case JUPITER:
            AIR_DENSITY = 1326;
            G = 24.79;
            break;
        case MOON:
            AIR_DENSITY = 0;
            G = 1.62;
            break;
        }

        wind_speed = wind;
} //end Environment

double Environment::getWind_speed() {
    return wind_speed;
} //end getWind_speed

void Environment::setWind_speed(double wind){
        if (wind < -20 || wind > 20) {
            throw new EnvironmentException("Warning: wind speed not within the bounds of -20 to 20");
            return;
        }
} //end setWind_speed
