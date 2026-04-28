#include "NonlinearSolver.h"
#include <iostream>
#include <cmath>

NonlinearSolver::NonlinearSolver() {
    a = 0; b = 0; eps = 0.001;
}

NonlinearSolver::~NonlinearSolver() {}

void NonlinearSolver::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void NonlinearSolver::setTolerance(double vol_eps) {
    eps = vol_eps;
}

double NonlinearSolver::f(double x) {
    return (std::pow(x, 2) / 4.0) + x - 1.2502;
}

double NonlinearSolver::df(double x) {
    double delta_x = 1e-6;
    return (f(x + delta_x) - f(x)) / delta_x;
}

int NonlinearSolver::solveDichotomy(double &x, int &iterations) {
    double current_a = a;
    double current_b = b;
    iterations = 0;

    if (f(current_a) * f(current_b) > 0) {
        std::cerr << "Помилка: Немає розв'язку на заданому проміжку (f(a) * f(b) > 0)." << std::endl;
        return -1;
    }

    double c;
    do {
        iterations++;
        c = (current_a + current_b) / 2.0;
        
        if (f(current_a) * f(c) < 0) {
            current_b = c;
        } else {
            current_a = c;
        }
    } while (std::abs(current_b - current_a) > eps);

    x = (current_a + current_b) / 2.0;
    return 0;
}

int NonlinearSolver::solveNewton(double initial_guess, double &x, int &iterations) {
    double x_n = initial_guess;
    double x_next;
    int max_iterations = 1000;
    iterations = 0;

    for (int i = 0; i < max_iterations; ++i) {
        iterations++;
        double derivative = df(x_n);
        
        if (std::abs(derivative) < 1e-9) {
            std::cerr << "Помилка: Похідна занадто близька до нуля." << std::endl;
            return -1;
        }

        x_next = x_n - f(x_n) / derivative;

        if (std::abs(x_next - x_n) <= eps) {
            x = x_next;
            return 0;
        }
        x_n = x_next;
    }

    std::cerr << "Помилка: Метод не зійшовся за виділену кількість ітерацій." << std::endl;
    return -1;
}