#pragma once

/**
 * Lily de Loe
 * 2020/10/26
 */

#ifdef PROJECTILE_EXPORTS
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif

#include "DataStructures.h"

class DLL Environment {
public:

    double AIR_DENSITY;
    double G;

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


#include "iostream"

using namespace std;

class DLL EnvironmentException {
public:
    /**
    * exception for environment object
    * @param message exception message
    */
    EnvironmentException(string message);

};