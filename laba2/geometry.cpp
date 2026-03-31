#include "geometry.h"
#include <cmath>
#include <algorithm> 

using namespace std;

int Triangle::checkPoint(Point p) const {
    if ((abs(p.x() - a_.x()) < 1e-9 && abs(p.y() - a_.y()) < 1e-9) ||
        (abs(p.x() - b_.x()) < 1e-9 && abs(p.y() - b_.y()) < 1e-9) ||
        (abs(p.x() - c_.x()) < 1e-9 && abs(p.y() - c_.y()) < 1e-9)) {
        return 2;
    }

    if (isDegenerate()) {
        double cp1 = crossProduct(a_, b_, p);
        double cp2 = crossProduct(a_, c_, p);
        double cp3 = crossProduct(b_, c_, p);
        
        if (abs(cp1) > 1e-9 || abs(cp2) > 1e-9 || abs(cp3) > 1e-9) {
            return -1; 
        }
        
        double minX = min(min(a_.x(), b_.x()), c_.x());
        double maxX = max(max(a_.x(), b_.x()), c_.x());
        double minY = min(min(a_.y(), b_.y()), c_.y());
        double maxY = max(max(a_.y(), b_.y()), c_.y());
        
        if (p.x() >= minX - 1e-9 && p.x() <= maxX + 1e-9 &&
            p.y() >= minY - 1e-9 && p.y() <= maxY + 1e-9) {
            return 0; 
        } else {
            return -1; 
        }
    }

    double cp1 = crossProduct(a_, b_, p);
    double cp2 = crossProduct(b_, c_, p);
    double cp3 = crossProduct(c_, a_, p);
    
    bool hasPos = (cp1 > 1e-9) || (cp2 > 1e-9) || (cp3 > 1e-9);
    bool hasNeg = (cp1 < -1e-9) || (cp2 < -1e-9) || (cp3 < -1e-9);
    bool hasZero = abs(cp1) <= 1e-9 || abs(cp2) <= 1e-9 || abs(cp3) <= 1e-9;

    if (hasPos && hasNeg) return -1; 
    if (hasZero) return 0;           
    return 1;                        
}