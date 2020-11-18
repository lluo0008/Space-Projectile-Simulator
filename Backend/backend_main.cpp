#include <iostream>

#include "ProjectileManager.h"
#include <chrono>
#include <thread>
#include <functional>

using namespace std;

//global variables because of multithreading; easier for this scenario
Environment* env = new Environment(EARTH, 10);
ProjectileManager manager = ProjectileManager(env, LARGE);

// timer function to execute update asynchronously - in the frontend just call update() once 
// every frame in the main thread to get new values loaded in to each projectile
void timer_start(function<void(void)> func, unsigned int interval) {
    thread([func, interval]() {
        while (true)
        {
            func();
            this_thread::sleep_for(chrono::milliseconds(interval));
        }
        }).detach();
}

// updater function so I don't have to deal with passing a parameter to a new thread; this is just for testing.
void updater() { 
    manager.update(); 
    vector<Projectile> check = manager.getLaunchedProjectiles();

    // for testing purposes - illustrates getting info about new projectiles to print
    for (int i = 0; i < check.size(); i++) {
        Projectile current = check[i];
        if (current.isActive()) {
            // example lines getting info from the projectiles
            // cout << "" << current.getData().x << ", " << current.getData().y << endl; // Position data
            cout << "Active Projectile - mass=" << current.getMass() << " color=" << current.getColor() << endl;
        }
    }
}

void test_backend() {
    // fancy print statements
    cout << "> Backend testing!" << endl;
    cout << "> AIR DENSITY: " << env->AIR_DENSITY << endl;
    cout << "> GRAVITY: " << env->G << endl;

    cout << "> Launch Parameters:" << endl;
    cout << "> WIND SPEED: " << manager.getWindSpeed() << endl;
    cout << "> LAUNCH ANGLE: " << manager.getLaunchAngle() << endl;
    cout << "> LAUNCH VEL: " << manager.getLaunchVelocity() << endl;
    cout << "> Projectile Size: " << manager.getProjectileSize() << endl;

    // launch a projectile
    cout << "> Launching projectile..." << endl;
    manager.launchCurrent();

    // run update every 16ms asynchronously. This is to mimic 60fps refresh, imgui won't need a
    // threaded timer just call update() once every frame in the main thread
    timer_start(updater, 16);

    //launch a second, small projectile 200ms after first one
    manager.setProjectileSize(SMALL);
    this_thread::sleep_for(milliseconds(200));
    manager.launchCurrent();

    while (true);
}



int main() {
    cout << "Projectile Simulator Backend Test" << std::endl;

    test_backend();
}