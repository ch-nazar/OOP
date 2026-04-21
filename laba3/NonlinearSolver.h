#ifndef NONLINEAR_SOLVER_H
#define NONLINEAR_SOLVER_H

class NonlinearSolver {
private:
    double a;
    double b;
    double eps;

    double f(double x);

    double df(double x);

public:
    NonlinearSolver();
    ~NonlinearSolver();

    void setVolumes(double vol_a, double vol_b);
    void setTolerance(double vol_eps);

    int solveDichotomy(double &x);
    int solveNewton(double initial_guess, double &x);
};

#endif