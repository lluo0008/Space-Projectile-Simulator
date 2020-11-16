/**
 * Lily de Loe
 * 2020/10/26
 */

#ifndef UNTITLED_ENVIRONMENT_H
#define UNTITLED_ENVIRONMENT_H

class Environment {
public:

    const double AIR_DENSITY = 1.2;
    const double G = 9.807;

    /**
     * Generates an environment object.
     * @param wind the cross-wind 
     * @param e the environments enum
     * @throws EnvironmentException creates exception if the wind is outside the bounds
     */
    Environment(Environments e, double wind);

    /**
     * Provides the wind speed.
     * @return the wind speed
     */
    double getWind_speed();

    /**
     * sets the wind speed
     * @param wind the wind speed
     */
    void setWind_speed(double wind);

private:
    double wind_speed;
};


#endif //UNTITLED_ENVIRONMENT_H

#ifndef UNTITLED_ENVIRONMENTEXCEPTION_H
#define UNTITLED_ENVIRONMENTEXCEPTION_H
#include "iostream"

using namespace std;

class EnvironmentException {
public:
    /**
    * exception for environment object
    * @param message exception message
    */
    EnvironmentException(string message);

};


#endif //UNTITLED_ENVIRONMENTEXCEPTION_H