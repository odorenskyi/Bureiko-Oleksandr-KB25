#ifndef MODULES_BUREIKO_H
#define MODULES_BUREIKO_H

// ЛР№8
double s_calculation(double x, double y, double z);

// ЛР№9
// Задача 9.1: Розрахунок вартості електроенергії
double calc_electricity_cost(double kwh);

// Задача 9.2: Шкала Бофорта (мінімальна швидкість вітру)
int get_min_beaufort(double v1, double v2, double v3, double v4, double v5, double v6);

// Задача 9.3: Побітовий аналіз числа
int count_bits_by_condition(unsigned int N);

// ЛР№10
// Задача 10.1: Обробка тексту та запис авторської інформації
void process_10_1(const char* input_filename, const char* output_filename);

// Задача 10.2: Транслітерація тексту та дозапис дати/часу
void append_10_2(const char* input_filename);

// Задача 10.3: Дозапис результатів обчислення та двійкового коду
void append_10_3(const char* output_filename, double x, double y, double z, unsigned int b);

#endif // MODULES_BUREIKO_H
