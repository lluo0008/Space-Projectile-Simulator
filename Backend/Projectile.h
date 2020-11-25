#pragma once

/**
*
* Created by lily on 10/26/20.
* revised: 2020-11-16
*
**/

#ifdef PROJECTILE_EXPORTS
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif

#include <vector>
#include "DataStructures.h"

using namespace std;

class DLL Projectile {
public:

        /**
         * Instantiates a projectile object
         * @param projectileSize - size of the projectile 
         * @param c - color of the projectile
         * @param launchParams struct storing the launch angle, launch velocity, and windspeed
         */
        Projectile(Size projectileSize, Colors c, launchParams params);

        /**
         * Generates the current x and y velocities considering wind.
         * @return the current velocity data
         */
        //std::vector<double> getCurrentValues();

        /**
        * gets the current projectile data
        * @return a struct containing the last an current xy coordinates, the speed, and the most recent time
        */
        projectileData getData();

        /**
        * sets the current projectile data
        */
        void setData(projectileData data);

        /**
        * checks if the projectile is active
        * @return the status of the projectile
        */

        bool isActive(); // { return active; }
        void setActive(bool activity) { active = activity; }

        /**
         * Stores the ordinary differential equations for the x and y components
         * @return the x and y ODEs
         */
        vector<double> getFunction(double time, std::vector<double> values);

        /**
         * Calculates the current time and position values for the star.
         * @param current_time the current time
         * @return the array of time and position values
         */
        //std::vector<double> updatePosition(double current_time, double DELTA_T, Environment env);

        /**
         * gets the mass in kilograms
         * @return the mass in kg
         */
        double getMass();

        /**
         * gets the velocity of the particle in m/s
         * @return the velocity
         */
        vector<double> getVelocity();

        vector<double> getCurrentValues();

		Size getSize();

        Colors getColor() { return color;  }


private:
    double mass;
    double density;
    double drag_coeff;
    double radius;
    bool active = false;
    launchParams launchedWith;
    Colors color;
    projectileData data;
    Size size;

    /**
     * gets the position of the particle, in x-y coordinates
     * @return the position
     */
     //std::vector<double> getPosition();

    //this method calculates and returns the magnitude of the velocity (in m/s)
    //by accepting values for the x velocity (considering wind) and the y velocity
    double getVMag(double vxa, double vy);

    //this method calculates and returns the x velocity (in m/s) considering the velocity
    //of the wind in the simulations
    double getVxa(double vx, double vw);

    //this method computes the partial differential equation dy/dv for use in the
    //runge kutta class. The method takes in time and position data and returns the value
    //of the function fy, in addition to calculating the magnitude of velocity, current
    //projectile mass and force of drag. Variables use combinations of the units kg, m and s
    double getDrag( double v, double m);

    //this method computes the partial differential equation dy/dv for use in the
    //runge kutta class. The method takes in time and position data and returns the value
    //of the function fy, in addition to calculating the magnitude of velocity, current
    //projectile mass and force of drag. Variables use combinations of the units kg, m and s
    double fy(double tk, double vxak, double vyk);

    //this method computes the partial differential equation dx/dv for use in the
    //runge kutta class. The method takes in time and position data and returns the value
    //of the function fx, in addition to calculating the magnitude of velocity, current
    //projectile mass and force of drag. Variables use combinations of the units kg, m and s
    double fx(double tk, double vxak, double vyk);
};
