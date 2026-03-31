#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <cmath>

class Point {
private:
    double x_, y_;
public:
    Point(double x = 0, double y = 0) : x_(x), y_(y) {}
    double x() const { return x_; }
    double y() const { return y_; }
    
    friend std::istream& operator>>(std::istream& is, Point& p) { 
        return is >> p.x_ >> p.y_; 
    }
};

class Triangle {
private:
    Point a_, b_, c_;
    double crossProduct(Point p1, Point p2, Point p3) const {
        return (p2.x() - p1.x()) * (p3.y() - p1.y()) - (p2.y() - p1.y()) * (p3.x() - p1.x());
    }
public:
    Triangle(Point a, Point b, Point c) : a_(a), b_(b), c_(c) {}
    
    bool isDegenerate() const { 
        return std::abs(crossProduct(a_, b_, c_)) < 1e-9; 
    }
    
    int checkPoint(Point p) const; 

    void showPoints() const {
        std::cout << "  A (" << a_.x() << ", " << a_.y() << ")\n"
                  << "  B (" << b_.x() << ", " << b_.y() << ")\n"
                  << "  C (" << c_.x() << ", " << c_.y() << ")\n";
    }
};

#endif