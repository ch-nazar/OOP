#include "geometry.h"
#include <cmath>

using namespace std;

int Triangle::checkPoint(Point p) const {
    double cp1 = crossProduct(a_, b_, p);
    double cp2 = crossProduct(b_, c_, p);
    double cp3 = crossProduct(c_, a_, p);
    
    bool hasPos = (cp1 > 1e-9) || (cp2 > 1e-9) || (cp3 > 1e-9);
    bool hasNeg = (cp1 < -1e-9) || (cp2 < -1e-9) || (cp3 < -1e-9);
    bool hasZero = abs(cp1) <= 1e-9 || abs(cp2) <= 1e-9 || abs(cp3) <= 1e-9;

    if (hasPos && hasNeg) return -1; // Зовні
    if (hasZero) return 0;           // На межі
    return 1;                        // Всередині
}