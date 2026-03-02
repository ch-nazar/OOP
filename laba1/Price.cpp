#define _CRT_SECURE_NO_WARNINGS
#include "Price.h"
#include <cstdio>

void normalize(Price& p) {
    if (p.kopecks >= 100) {
        p.hryvnia += p.kopecks / 100;
        p.kopecks %= 100;
    }
}

void add(Price& target, const Price& other) {
    target.hryvnia += other.hryvnia;
    target.kopecks += other.kopecks;
    normalize(target);
}

void multiply(Price& p, int quantity) {
    p.hryvnia *= quantity;
    p.kopecks *= quantity;
    normalize(p);
}

void roundToTen(Price& p) {
    int remainder = p.kopecks % 10;
    
    if (remainder < 5) {
        p.kopecks -= remainder;
    } else {
        p.kopecks += (10 - remainder);
    }
    
    normalize(p);
}

void print(const Price& p) {
    printf("%d грн %02d коп", p.hryvnia, p.kopecks);
}

void processCheque(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Помилка файлу!\n");
        return;
    }

    Price total = {0, 0}, cur;
    int qty;

    
    while (fscanf(f, "%d %hi %d", &cur.hryvnia, &cur.kopecks, &qty) == 3) {
        
        if (cur.hryvnia < 0 || cur.kopecks < 0 || qty <= 0) {
            
            continue; 
        }
        
        multiply(cur, qty);
        add(total, cur);
    }
    fclose(f);

    Price toPay = total;
    roundToTen(toPay);

    printf("Сума: ");      print(total);
    printf("\nДо оплати: "); print(toPay);
    printf("\n");
}