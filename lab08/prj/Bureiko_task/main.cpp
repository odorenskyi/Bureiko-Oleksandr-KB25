#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <sstream>
#include <windows.h>
#include "../Modules_Bureiko.h"

using namespace std;

// 8.2.1: прізвище, ім'я та знак копірайту
string get_developer_info() {
    // \xA9 - ©
    return "Розробник: Бурейко Олександр (КБ-25, ЦНТУ) \xA9";
}

// 8.2.2: a + 1 > |b - 2|
bool check_logical_expr(char a, char b) {
    return (a + 1) > abs(b - 2);
}

// 8.2.3: форматоване виведення та обчислення S
string format_values_and_calc(double x, double y, double z) {
    stringstream ss;

    ss << "Значення у десятковій системі (DEC):\n";
    ss << "x = " << dec << x << "\n";
    ss << "y = " << dec << y << "\n";
    ss << "z = " << dec << z << "\n\n";

    ss << "Значення у шістнадцятковій системі (HEX, приведені до цілих):\n";
    ss << "x = 0x" << hex << (int)x << "\n";
    ss << "y = 0x" << hex << (int)y << "\n";
    ss << "z = 0x" << hex << (int)z << "\n\n";

    // повертаємо формат виведення до стандартного для дробових чисел
    ss << "Результат обчислення функції S = " << defaultfloat << s_calculation(x, y, z) << "\n";

    return ss.str();
}

int main() {
    // встановлюємо кодування Windows-1251 для кирилиці
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x, y, z;
    char a, b;

    cout << "Введіть значення x, y, z (x має бути > 3): ";
    cin >> x >> y >> z;

    cout << "Введіть символи a, b (через пробіл): ";
    cin >> a >> b;

    cout << "\n========================================\n";

    // 8.2.1
    cout << get_developer_info() << "\n\n";

    // 8.2.2
    cout << "Результат логічного виразу a + 1 > |b - 2|: "
         << boolalpha << check_logical_expr(a, b) << "\n\n";

    // 8.2.3
    cout << format_values_and_calc(x, y, z);

    cout << "========================================\n";

    system("pause");
    return 0;
}
