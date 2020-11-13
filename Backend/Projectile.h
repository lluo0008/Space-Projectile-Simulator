//
// Created by lily on 10/26/20.
//

#ifndef UNTITLED_PROJECTILE_H
#define UNTITLED_PROJECTILE_H


#include "ODESystem.h"

class Projectile: ODESystem {
public:

        /**
         * Instantiates a particle object
         * @param starting_mass initial mass of the particle
         * @param creation_time time at creationvelocity
         * @param position position
         * @param velocity velocity
         * @param density density of the particle
         * @param drag_coeff drag coefficient of the particle
         * @param burn_rate burn rate of the particle
         * @param system_size system size
         * @param starting_radius starting radius of the particle
         * @param lifetime particle's lifetime
         */
        Projectile(double starting_mass, double creation_time, std::vector<double> position, std::vector<double> velocity,
                   double density, double drag_coeff, int system_size, double radius, double transitTime);

        /**
         * Provides the dimension of the system.
         * @return the dimension of the system
         */
        int getSystemSize();


        /**
         * Generates the current x and y velocities considering wind.
         * @return the current velocity data
         */
        std::vector<double> getCurrentValues();

        /**
         * Stores the ordinary differential equations for the x and y components
         * @return the x and y ODEs
         */
        std::vector<double> getFunction(double time, std::vector<double> values);

        /**
         * Calculates the current time and position values for the star.
         * @param current_time the current time
         * @return the array of time and position values
         */
        //std::vector<double> updatePosition(double current_time, double DELTA_T, Environment env);


        /**
         * gets the lifetime of the particle in seconds
         * @return the lifetime
         */
        double getTransitTime();

        /**
         * gets the mass in kilograms
         * @return the mass in kg
         */
        double getMass();

        /**
         * gets the velocity of the particle in m/s
         * @return the velocity
         */
        std::vector<double> getVelocity();

        /**
         * gets the creation time of the particle in seconds
         * @return the creation time
         */
        double getCreationTime();

        //function returns false
        bool update(double time) {
            return false;
        } //end update

private:

    /**
     * gets the position of the particle, in x-y coordinates
     * @return the position
     */
     std::vector<double> getPosition();

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


#endif //UNTITLED_PROJECTILE_H
