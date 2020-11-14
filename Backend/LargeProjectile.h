#pragma once
#include "Projectile.h"
class LargeProjectile :
    public Projectile
{
public:
    LargeProjectile(struct launchParams params);

private:
    double drag_coeff = 0.5;
    double density = 10;
    double mass = 10;
    double rad = 10;
};

