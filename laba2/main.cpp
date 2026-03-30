#include "Geometry.h"
#include <iostream>
#include <limits>
#include <string>
#include <windows.h>

using namespace std;

void fixCin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "  [!] Помилка: введіть число. Спробуйте ще раз.\n";
}

double readCoord(const string& prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) return val;
        fixCin();
    }
}

Point readPoint(const string& name) {
    cout << "Введіть координати для " << name << ":\n";
    double x = readCoord("  -> X: ");
    double y = readCoord("  -> Y: ");
    return Point(x, y);
}

void processPoints(const Triangle& t) {
    int count;
    while (true) {
        count = readCoord("\nСкільки точок хочете перевірити? ");
        if (count > 0) break;
        cout << "  [!] Кількість має бути більшою за 0.\n";
    }

    for (int i = 0; i < count; ++i) {
        cout << "\n";
        Point p = readPoint("Точки " + to_string(i + 1));
        
        int res = t.checkPoint(p);
        
        cout << "  Результат: ";
        if (res == 1) cout << "ВСЕРЕДИНІ трикутника\n";
        else if (res == 0) cout << "НА МЕЖІ трикутника\n";
        else cout << "ЗОВНІ трикутника\n";
    }
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    cout << "=== Програма перевірки точок ===\n\n";
    
    Point a = readPoint("Вершини A");
    Point b = readPoint("Вершини B");
    Point c = readPoint("Вершини C");
    
    Triangle t(a, b, c);
    
    if (t.isDegenerate()) {
        cerr << "\n[!] Помилка: Трикутник вироджений (точки на одній прямій)!\n"; 
        return 1;
    }

    processPoints(t);
    return 0;
}