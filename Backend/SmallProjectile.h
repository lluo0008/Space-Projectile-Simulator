#pragma once
#include "Projectile.h"
class SmallProjectile :
    public Projectile
{
public:
    SmallProjectile(struct launchParams params);

private:
    double drag_coeff = 0.5;
    double density = 1;
    double mass = 1;
    double rad = 1;
    struct launchParams launchedWith;
};

