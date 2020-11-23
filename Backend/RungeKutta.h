#pragma once

/**
 * Lily de Loe
 * 2020/10/26
 */


#include <vector>
#include "Projectile.h"

    /**
	 * Performs one iteration of the Runge-Kutta approximation for an ODE system.
	 *
	 * @param system the system used in the Runge-Kutta approximation
	 * @param DELTA_T the time step
	 * @param current_time the current time
	 * @return the array of velocity components
	 */
vector<double> RungeKutta(Projectile &system, double DELTA_T, double current_time);