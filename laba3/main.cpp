#include <iostream>
#include <windows.h>
#include "NonlinearSolver.h"

int main() {
    SetConsoleOutputCP(CP_UTF8); 
    
    NonlinearSolver* solver = new NonlinearSolver();

    solver->setVolumes(0.0, 2.0);
    solver->setTolerance(0.0001);

    double root_dichotomy;
    int iter_dichotomy;
    std::cout << "--- Метод дихотомії ---" << std::endl;
    
    int err1 = solver->solveDichotomy(root_dichotomy, iter_dichotomy);
    if (err1 == 0) {
        std::cout << "Знайдений корінь: x = " << root_dichotomy << std::endl;
        std::cout << "Кількість ітерацій:  " << iter_dichotomy << std::endl;
    }

    double root_newton;
    int iter_newton;
    std::cout << "\n--- Метод Ньютона (дотичних) ---" << std::endl;
    
    double initial_guess = 1.0; 
    
    int err2 = solver->solveNewton(initial_guess, root_newton, iter_newton);
    if (err2 == 0) {
        std::cout << "Знайдений корінь: x = " << root_newton << std::endl;
        std::cout << "Кількість ітерацій:  " << iter_newton << std::endl;
    }

    delete solver;

    return 0;
}