/**
 * Lily de Loe
 * 2020/10/26
 * revised: 2020/11/16
 */

#define _USE_MATH_DEFINES

#include "Projectile.h"
#include "RungeKutta.h"
#include <math.h>
#include "Environment.h"
#include <vector>

using namespace std;

double Projectile::getMass() {
    return mass;
} //end getStarting_mass

vector<double> Projectile::getVelocity() {
    vector <double> velocity;
    velocity.push_back(data.vx);
    velocity.push_back(data.vy);

    return velocity;
} //end getVelocity

double Projectile::getVMag(double vxa, double vy) {
    //calculate the magnitude of velocity
    double vxa2 = pow(vxa, 2);
    double vy2 = pow(vy, 2);
    double v = sqrt(vxa2 + vy2);
    return v;
} //end getVMag

double Projectile::getVxa(double vx, double vw) {
    //calculate the velocity in the x direction with wind
    double vxa = vx - vw;
    return vxa;
} //end getVxa

double Projectile::getDrag( double v, double m) {
    //calculate the radius of the projectile
    double R3 = (m*3.0)/(M_PI*4*density);
    double R = cbrt(R3);
    //calculate its cross sectional area
    double A = M_PI*pow(R,2);
    //calculate and return the drag force
    double Fd = launchedWith.env->AIR_DENSITY*pow(v, 2)*A* drag_coeff/2.0;
    return Fd;
} //end getDrag

double Projectile::fy(double tk, double vxak, double vyk){
    //initialize variables
    double Fd;
    double v;
    //calculate the magnitude of velocity, mass and drag force
    v = getVMag(vxak,vyk);
    Fd = getDrag(data.speed, mass);
    //calculate and return fy
    double fy = -1.0*launchedWith.env->G - Fd*vyk/(mass*v);
    
    return fy;
} //end fy

double Projectile::fx(double tk, double vxak, double vyk) {
    //initialize variables
    double Fd;
    double v;
    //calculate the magnitude of velocity, mass and drag force
    v = getVMag(vxak,vyk);
    Fd = getDrag(v, mass);
    //calculate and return fx
    double fx = -1.0*Fd*vxak/(mass*v);
    return fx;
} //end fx

Projectile::Projectile(Size projectileSize, Colors c, launchParams params)
{
    drag_coeff = 0.5;
    if (projectileSize == SMALL) {
        radius = 1;
        density = 1;
        mass = 1;
    }
    else if (projectileSize == MEDIUM) {
        radius = 5;
        density = 5;
        mass = 5;
    }
    else if (projectileSize == LARGE) {
        radius = 10;
        density = 10;
        mass = 10;
    }
    color = c;
    launchedWith = params;
}


projectileData Projectile::getData()
{
    return data;
}

void Projectile::setData(projectileData data){
    //POSITION AND OTHER PARAMETERS NEED TO BE WORKED IN
    std::vector <double> velocity = getVelocity();
    data.vx = velocity[0];
    data.vy = velocity[1];
}

bool Projectile::isActive()
{
    if (data.y < 0) {
        return false;
    }
    return true;
} 

vector<double> Projectile::getFunction(double time, std::vector<double> values) {
    std::vector <double> temp;
    temp.push_back(fx(time, values[0], values[1]));
    temp.push_back(fy(time, values[0], values[1]));
    return temp;
}
