/**
 * Lily de Loe
 * 2020/10/26
 */

#include "RungeKutta.h"
#include "Projectile.h"

using namespace std;

std::vector<double> RungeKutta(Projectile& system, double DELTA_T, double current_time) {
    //gets the dimension of the system
    int num_dims = 2;
//current time
    double t = current_time;
//vectors of the components of each Runge-Kutta step
    vector<double> q1,q2,q3,q4;
//get the system's current values
    vector<double> current_vals = system.getCurrentValues();
//vector of velocity components
    vector<double> v;
//initialize velocity components as the most current values
    for(int i = 0; i < num_dims; i++)
        v.push_back(current_vals[i]);
//temporary storage for velocity components
    std::vector<double> temp;
//calculate the Runge-Kutta iterations for each dimension
    q1 = system.getFunction(t, v);
//calculate the velocity components used in the next iteration
    for (int j = 0; j < num_dims; j++) {
        temp.push_back(v[j] + DELTA_T*q1[j]/2.0);
    }
    q2 = system.getFunction(t + DELTA_T/2.0, temp );
    for (int j = 0; j < num_dims; j++) {
        temp.push_back(v[j] + DELTA_T*q2[j]/2.0);
    }
    q3 = system.getFunction(t + DELTA_T/2.0, temp);
    for (int j = 0; j < num_dims; j++) {
        temp.push_back(v[j] + DELTA_T*q3[j]);
    }
    q4 = system.getFunction(t + DELTA_T, temp);
//calculate the change in the velocity components
    for (int j = 0; j < num_dims; j++) {
        v.push_back((DELTA_T/6.0)*(q1[j]+2.0*q2[j]+2.0*q3[j]+q4[j]));
    }
    return v;
}
