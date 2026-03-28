#include <iostream>
#include <cmath>
#include <windows.h>
#include "../../../lab08/prj/Modules_Bureiko.h"

using namespace std;

// функція для тестування задачі 9.1
void test_9_1(double kwh, double expected) {
    double result = calc_electricity_cost(kwh);
    cout << "Вхідні дані: kwh=" << kwh << "\n";
    cout << "Результат: " << result << " | Очікувано: " << expected << "\n";
    // використовуємо 1e-4 для порівняння дробних чисел
    if (abs(result - expected) < 1e-4) {
        cout << "Статус: ПРОЙДЕНО\n\n";
    } else {
        cout << "Статус: НЕ ПРОЙДЕНО\n\n";
    }
}

// функція для тестування задачі 9.2
void test_9_2(double v1, double v2, double v3, double v4, double v5, double v6, int expected) {
    int result = get_min_beaufort(v1, v2, v3, v4, v5, v6);
    cout << "Вхідні дані: " << v1 << ", " << v2 << ", " << v3 << ", " << v4 << ", " << v5 << ", " << v6 << "\n";
    cout << "Результат: " << result << " | Очікувано: " << expected << "\n";
    if (result == expected) {
        cout << "Статус: ПРОЙДЕНО\n\n";
    } else {
        cout << "Статус: НЕ ПРОЙДЕНО\n\n";
    }
}

// Функція для тестування задачі 9.3
void test_9_3(unsigned int N, int expected) {
    int result = count_bits_by_condition(N);
    cout << "Вхідні дані: N=" << N << "\n";
    cout << "Результат: " << result << " | Очікувано: " << expected << "\n";
    if (result == expected) {
        cout << "Статус: ПРОЙДЕНО\n\n";
    } else {
        cout << "Статус: НЕ ПРОЙДЕНО\n\n";
    }
}

int main() {
    // встановлюємо кодування для коректного відображення кирилиці в консолі Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "============= TS_9_1: Задача 9.1 (Тарифи) =============\n\n";
    test_9_1(100, 30.84);
    test_9_1(150, 46.26);
    test_9_1(151, 46.6794);
    test_9_1(500, 193.05);
    test_9_1(800, 318.87);
    test_9_1(801, 320.2104);
    test_9_1(1000, 586.95);
    test_9_1(0, 0.0);
    test_9_1(-10, 0.0);
    test_9_1(100, 999.99); // навмисна помилка

    cout << "============= TS_9_2: Задача 9.2 (Шкала Бофорта) =============\n\n";
    test_9_2(0.1, 5.0, 10.0, 3.0, 4.0, 2.0, 0);
    test_9_2(2.0, 1.0, 10.0, 3.0, 4.0, 2.0, 1);
    test_9_2(1.6, 5.0, 10.0, 3.0, 4.0, 2.0, 2);
    test_9_2(5.4, 6.0, 10.0, 8.0, 9.0, 7.0, 3);
    test_9_2(12.0, 13.0, 15.0, 20.0, 18.0, 14.0, 6);
    test_9_2(21.0, 25.0, 30.0, 22.0, 23.0, 24.0, 9);
    test_9_2(33.0, 34.0, 35.0, 40.0, 50.0, 33.5, 12);
    test_9_2(7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 4);
    test_9_2(-5.0, 10.0, 5.0, 8.0, 12.0, 6.0, 0);
    test_9_2(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 10); // навмисна помилка

    cout << "============= TS_9_3: Задача 9.3 (Аналіз бітів) =============\n\n";
    test_9_3(0, 0);
    test_9_3(1, 1);
    test_9_3(512, 9);
    test_9_3(513, 8);
    test_9_3(255, 8);
    test_9_3(1023, 0);
    test_9_3(1024, 1);
    test_9_3(500700, 6);
    test_9_3(170, 4);
    test_9_3(512, 99); // навмисна помилка

    system("pause");
    return 0;
}
