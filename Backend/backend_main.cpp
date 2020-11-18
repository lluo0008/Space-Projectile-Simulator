#include <iostream>

#include "ProjectileManager.h"
#include <chrono>
#include <thread>
#include <functional>

using namespace std;

int count = 0;

Environment* earth = new Environment(EARTH, 10);
ProjectileManager manager = ProjectileManager(earth, SMALL);

// timer function to execute update asynchronously
void timer_start(function<void(void)> func, unsigned int interval) {
    thread([func, interval]() {
        while (true)
        {
            func();
            this_thread::sleep_for(chrono::milliseconds(interval));
        }
        }).detach();
}

void updater() { 
    manager.update(); 
    vector<Projectile> check = manager.getLaunchedProjectiles();
    Projectile current = check[0];

    if (current.isActive()) {
        //cout << "" << current.getData().x << /*", " << current.getData().y << */endl;
        //cout << "" << /*current.getData().x << ", " <<*/ current.getData().y << endl;
        cout << "" << current.getData().x << ", " << current.getData().y << endl;

    }
}

void test_backend() {
    cout << "> Backend testing!" << endl;

    cout << "> Launch Parameters:" << endl;
    cout << "> WIND SPEED: " << manager.getWindSpeed() << endl;
    cout << "> LAUNCH ANGLE: " << manager.getLaunchAngle() << endl;
    cout << "> LAUNCH VEL: " << manager.getLaunchVelocity() << endl;
    cout << "> Projectile Size: " << manager.getProjectileSize() << endl;

    cout << "> Launching projectile..." << endl;
    manager.launchCurrent();
    updater();
    
    timer_start(updater, 16);

    while (true);
}



int main() {
    cout << "Projectile Simulator Backend" << std::endl;

    test_backend();
}