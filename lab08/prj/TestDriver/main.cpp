#include <iostream>
#include <cmath>
#include <windows.h>
#include "../Modules_Bureiko.h"

using namespace std;

// expect_nan для перевірки критичних умов
void run_test(double x, double y, double z, double expected, bool expect_nan = false) {
    double result = s_calculation(x, y, z);
    cout << "Вхідні дані: x=" << x << ", y=" << y << ", z=" << z << "\n";

    if (expect_nan) {
        cout << "Результат: " << result << " | Очікувано: NaN\n";
        if (isnan(result) || isinf(result)) {
            cout << "Статус: ПРОЙДЕНО (Коректно оброблено вихід за межі ОДЗ)\n\n";
        } else {
            cout << "Статус: НЕ ПРОЙДЕНО\n\n";
        }
    } else {
        cout << "Результат: " << result << " | Очікувано: " << expected << "\n";
        // перевіряємо, чи результат є числом і чи збігається з очікуваним
        if (!isnan(result) && abs(result - expected) < 1e-4) {
            cout << "Статус: ПРОЙДЕНО\n\n";
        } else {
            cout << "Статус: НЕ ПРОЙДЕНО\n\n";
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "--- Модульне тестування s_calculation (З урахуванням граничних умов) ---\n\n";

    // нормальні умови
    run_test(4.0, 2.0, 8.0, 5.2501);
    run_test(5.0, 1.0, 10.0, 2.9231);

    // критична точка: x максимально близько до межі ОДЗ (x > 3)
    run_test(3.0001, 2.0, 6.0, 4.4168);

    // граничні умови, математично очікуємо NaN
    run_test(3.0, 2.0, 6.0, 0, true);   // x = 3 (логарифм від нуля)
    run_test(0.0, 2.0, 8.0, 0, true);   // x = 0 (ділення на 0 і логарифм від'ємного)
    run_test(-5.0, 2.0, 8.0, 0, true);  // x < 0 (корінь з від'ємного числа)

    // крайні умови для y та z
    run_test(4.0, 0.0, 8.0, 3.0);       // y = 0, весь лівий вираз перетворюється на 1 (1 + 8/4 = 3)
    run_test(4.0, 2.0, 0.0, 3.2501);    // z = 0, права частина обнуляється

    // 9: тестування великими числами
    run_test(1000.0, 0.5, 2000.0, 3.6541); // перевір точне значення при запуску

    // 10: спеціально провалений тест (демонстрація роботи драйвера)
    run_test(4.0, 2.0, 8.0, 999.99);    // навмисна помилка в очікуваному результаті

    return 0;
}
