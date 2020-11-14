/**
 * Lily de Loe
 * 2020/10/26
 * revised: 2020/11/13
 */

#define _USE_MATH_DEFINES

#include "Projectile.h"
#include "RungeKutta.h"
#include <math.h>
#include "Environment.h"
#include <vector>

using namespace std;

//double transitTime;
//double creation_time;
//Environment environment;
//std::vector<double> position ;
//std::vector<double> velocity;
//int system_size;


//std::vector<double> Projectile::getCurrentValues() {
    //correct x velocity and store both velocity components
//    std::vector<double> temp;
    //temp.push_back(getVxa(velocity[0], environment.getWind_speed()));
//    temp.push_back(velocity[1]);

//    return temp;
//} //getCurrentValues

//std::vector<double> getPosition() {
    //return Helper.copyVector(position);
//    return vector<double>();
//} //end getPosition

double getMass() {
    return mass;
} //end getStarting_mass

std::vector<double> getVelocity() {
    std::vector <double> velocity;
    velocity.push_back(data.vx);
    velocity.push_back(data.vy);
    //return vector<double>();
} //end getVelocity

double getVMag(double vxa, double vy) {
    //calculate the magnitude of velocity
    double vxa2 = pow(vxa, 2);
    double vy2 = pow(vy, 2);
    double v = sqrt(vxa2 + vy2);
    return v;
} //end getVMag

double getVxa(double vx, double vw) {
    //calculate the velocity in the x direction with wind
    double vxa = vx - vw;
    return vxa;
} //end getVxa

double getDrag( double v, double m) {
    //calculate the radius of the projectile
    double R3 = (m*3.0)/(M_PI*4*density);
    double R = cbrt(R3);
    //calculate its cross sectional area
    double A = M_PI*pow(R,2);
    //calculate and return the drag force
    double Fd = /*launchedWith.env.AIR_DENSITY*/*pow(v, 2)*A* drag_coeff/2.0; // 1.0 is temp value so it compiles with no member environment variable; it would now be in launchParams struct
    return Fd;
} //end getDrag

double fy(double tk, double vxak, double vyk){
    //initialize variables
    //double m; //FIGURE OUT WHERE WE WANT TO DECLARE THIS
    double Fd;
    //double v;
    //calculate the magnitude of velocity, mass and drag force
    v = getVMag(vxak,vyk);
    Fd = getDrag(data.speed, mass);
    //calculate and return fy
    double fy = -1.0*/*launchedWith.env.G*/ - Fd*vyk/(mass*v); // 9.18 is temp value so it compiles with no member environment variable; it would now be in launchParams struct
    return fy;
} //end fy

double fx(double tk, double vxak, double vyk) {
    //initialize variables
    //double m; //FIGURE OUT WHERE WE WANT TO DECLARE THIS
    double Fd;
    double v;
    //calculate the magnitude of velocity, mass and drag force
    v = getVMag(vxak,vyk);
    Fd = getDrag(v, mass);
    //calculate and return fx
    double fx = -1.0*Fd*vxak/(mass*v);
    return fx;
    //return 0.0;
} //end fx

Projectile::Projectile(double m, double dens, double dragC, double rad, 
    enum Colors c, struct launchParams param) {
    mass = m;
    density = dens;
    drag_coeff = dragC;
    radius = rad;
    color = c;
    params = param;

}


ProjectileData Projectile::getData()
{
    return data;
}

void Projectile::setData(ProjectileData data){
    //POSITION AND OTHER PARAMETERS NEED TO BE WORKED IN
    std::vector <double> velocity = getVelocity();
    data.vx = velocity[0];
    data.vy = velocity[1];
}

bool Projectile::isActive()
{
    if (data.lastY < 0.01) {
        return false;
    }
    return true;
}

vector<double> Projectile::getFunction(double time, std::vector<double> values) {
    std::vector <double> temp;
    temp.push_back(fx(time, values[0], values[1]);
    temp.push_back(fy(time, values[0], values[1]);
    return temp;
}

//std::vector<double> Projectile::updatePosition(double current_time, double DELTA_T, Environment env) {
//    if (current_time == 0) return getPosition();
//    //get the updated Runge-Kutta velocities
//    this->environment = env;
//    std::vector<double> temp = RungeKutta(this, DELTA_T, current_time - getCreationTime());
//    velocity[0] += temp[0];
//    velocity[1] += temp[1];
//    //calculate the current positions
//    for(int i = 0; i < 2; i ++) {
//        position[i] += velocity[i] * DELTA_T;
//    }
//    return getPosition();
//}
