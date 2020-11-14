/**
 * Lily de Loe
 * 2020/10/26
 */

#ifndef UNTITLED_RUNGEKUTTA_H
#define UNTITLED_RUNGEKUTTA_H
#include <vector>
#include "Projectile.h"

class RungeKutta {
public:
    /**
	 * Performs one iteration of the Runge-Kutta approximation for an ODE system.
	 *
	 * @param system the system used in the Runge-Kutta approximation
	 * @param DELTA_T the time step
	 * @param current_time the current time
	 * @return the array of velocity components
	 */
    static std::vector<double> rungeKutta(Projectile &system, double DELTA_T, double current_time);
};


#endif //UNTITLED_RUNGEKUTTA_H
