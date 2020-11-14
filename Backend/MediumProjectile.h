#pragma once
#include "Projectile.h"
class MediumProjectile :
    public Projectile
{
public:
    MediumProjectile(struct launchParams params);

private:
    double drag_coeff = 0.5;
    double density = 5;
    double mass = 5;
    double rad = 5;
    struct launchParams launchedWith;
};

