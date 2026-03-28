#include "../Modules_Bureiko.h"
#include <cmath>
#include <algorithm>

// ЛР№8
double s_calculation(double x, double y, double z) {
    return pow(3.0 * sin(sqrt(12.0 * x) + log10(x - 3.0)), y) + (z / x);
}

// ЛР№9
// Задача 9.1: Тарифи на електроенергію
double calc_electricity_cost(double kwh) {
    if (kwh < 0) return 0.0; // перевірка коректності вводу

    if (kwh <= 150) {
        return kwh * 0.3084;
    }
    else if (kwh <= 800) {
        return (150 * 0.3084) + ((kwh - 150) * 0.4194);
    }
    else {
        return (150 * 0.3084) + (650 * 0.4194) + ((kwh - 800) * 1.3404);
    }
}

// Задача 9.2: Мінімальна швидкість вітру та шкала Бофорта
int get_min_beaufort(double v1, double v2, double v3, double v4, double v5, double v6) {
    // знаходимо мінімальне значення з 6 параметрів
    double min_v = std::min({v1, v2, v3, v4, v5, v6});

    if (min_v < 0) min_v = 0; // захист

    // умови за таблицею шкали Бофорта
    if (min_v < 0.3) return 0;
    else if (min_v <= 1.5) return 1;
    else if (min_v <= 3.4) return 2;
    else if (min_v <= 5.4) return 3;
    else if (min_v <= 7.9) return 4;
    else if (min_v <= 10.7) return 5;
    else if (min_v <= 13.8) return 6;
    else if (min_v <= 17.1) return 7;
    else if (min_v <= 20.7) return 8;
    else if (min_v <= 24.4) return 9;
    else if (min_v <= 28.4) return 10;
    else if (min_v <= 32.6) return 11;
    else return 12; // >= 32.7
}

// Задача 9.3: Аналіз бітів з тернарним оператором
int count_bits_by_condition(unsigned int N) {
    if (N == 0) return 0;

    // отримуємо 9-й біт (зсуваємо вправо на 9 позицій і робимо логічне І з 1)
    bool bit_9 = (N >> 9) & 1;
    int count = 0;

    // проходимо по всіх бітах числа, поки воно більше нуля
    while (N > 0) {
        int current_bit = N & 1; // отримуємо молодший біт

        // використання тернарного оператора за вимогою задачі
        // якщо bit_9 == 1, перевіряємо чи current_bit == 0 (якщо так - додаємо 1, інакше 0)
        // інакше перевіряємо чи current_bit == 1
        count += (bit_9 == 1) ? (current_bit == 0 ? 1 : 0) : (current_bit == 1 ? 1 : 0);

        N >>= 1; // зсуваємо число вправо для перевірки наступного біта
    }

    return count;
}
