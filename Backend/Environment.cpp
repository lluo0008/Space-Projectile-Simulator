/**
 * Lily de Loe
 * 2020/10/26
 */

#include "Environment.h"
using namespace std;
double wind_speed;

EnvironmentException::EnvironmentException(string message) {
    message = "Warning: environment exception";
}

Environment::Environment(double wind){
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
