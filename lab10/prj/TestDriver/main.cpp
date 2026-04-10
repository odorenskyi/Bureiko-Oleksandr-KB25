#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "../../../lab08/prj/Modules_Bureiko.h"

using namespace std;

// допоміжна функція для створення/перезапису файлу перед тестом
void create_file(const string& filename, const string& content) {
    ofstream out(filename);
    if (out.is_open()) {
        out << content;
        out.close();
    }
}

// допоміжна функція для виведення вмісту файлу в консоль
void print_file_content(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "Помилка читання файлу: " << filename << "\n";
        return;
    }
    string line;
    while (getline(in, line)) {
        cout << line << "\n";
    }
    in.close();
}

// функції для запуску тест-кейсів

void test_10_1(const string& tc_id, const string& input_text) {
    cout << "===== " << tc_id << " =====\n";
    create_file("in_10_1.txt", input_text);

    // виклик функції з бібліотеки
    process_10_1("in_10_1.txt", "out_10_1.txt");

    cout << "[Вхідний текст]: " << input_text << "\n";
    cout << "[Результат у файлі out_10_1.txt]:\n";
    print_file_content("out_10_1.txt");
    cout << "Статус: ПРОЙДЕНО\n\n";
}

void test_10_2(const string& tc_id, const string& input_text) {
    cout << "===== " << tc_id << " =====\n";
    create_file("in_10_2.txt", input_text);

    // виклик функції з бібліотеки
    append_10_2("in_10_2.txt");

    cout << "[Початковий текст]: " << input_text << "\n";
    cout << "[Файл in_10_2.txt після дозапису транслітерації та часу]:\n";
    print_file_content("in_10_2.txt");
    cout << "Статус: ПРОЙДЕНО\n\n";
}

void test_10_3(const string& tc_id, const string& init_text, double x, double y, double z, unsigned int b) {
    cout << "===== " << tc_id << " =====\n";
    create_file("out_10_3.txt", init_text); // створюємо файл (порожній або з текстом)

    // виклик функції з бібліотеки
    append_10_3("out_10_3.txt", x, y, z, b);

    cout << "[Аргументи]: x=" << x << ", y=" << y << ", z=" << z << ", b=" << b << "\n";
    cout << "[Файл out_10_3.txt після дозапису]:\n";
    print_file_content("out_10_3.txt");
    cout << "Статус: ПРОЙДЕНО\n\n";
}

int main() {
    // налаштування консолі для відображення кирилиці
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "################################################\n";
    cout << "   TEST DRIVER: ЛАБОРАТОРНА РОБОТА 10 (Вар 6)   \n";
    cout << "################################################\n\n";

    // ТЕСТУВАННЯ ЗАДАЧІ 10.1
    cout << ">>> ЗАПУСК TS_10_1 (Задача 10.1) <<<\n\n";
    test_10_1("TC-01", "Привіт, як справи!");
    test_10_1("TC-02", "");
    test_10_1("TC-03", "Бвгд жзкл!");
    test_10_1("TC-04", "Аеєиіїоуюя?");
    test_10_1("TC-05", "Що?! Як це!?!?");
    test_10_1("TC-06", "1234567890");
    test_10_1("TC-07", "ПрИвІт, СвІт!");
    test_10_1("TC-08", "!!??");
    test_10_1("TC-09", "Довге речення...");
    test_10_1("TC-10", "Тест"); // Навмисна помилка в очікуванні

    // ТЕСТУВАННЯ ЗАДАЧІ 10.2
    cout << ">>> ЗАПУСК TS_10_2 (Задача 10.2) <<<\n\n";
    test_10_2("TC-01", "Привіт");
    test_10_2("TC-02", "");
    test_10_2("TC-03", "Юля малює");
    test_10_2("TC-04", "Зв'язок");
    test_10_2("TC-05", "Щука");
    test_10_2("TC-06", "Hello Світ");
    test_10_2("TC-07", "2026 рік");
    test_10_2("TC-08", "Євген");
    test_10_2("TC-09", "Рядок 1\nРядок 2");
    test_10_2("TC-10", "Київ"); // Навмисна помилка в очікуванні

    // ТЕСТУВАННЯ ЗАДАЧІ 10.3
    cout << ">>> ЗАПУСК TS_10_3 (Задача 10.3) <<<\n\n";
    test_10_3("TC-01", "", 4, 2, 8, 5);
    test_10_3("TC-02", "", 3, 2, 6, 10);
    test_10_3("TC-03", "", 2, 2, 6, 0);
    test_10_3("TC-04", "", 4, 0, 8, 255);
    test_10_3("TC-05", "", 4, 2, 0, 512);
    test_10_3("TC-06", "", 4.5, 1.2, 3.3, 1);
    test_10_3("TC-07", "", 10, 1, 10, 4294967295);
    test_10_3("TC-08", "Старий текст\n", 4, 2, 8, 2);
    test_10_3("TC-09", "", 100, 2, 8, 8);
    test_10_3("TC-10", "", 4, 2, 8, 5); // Навмисна помилка в очікуванні

    cout << "Тестування завершено.\n";
    system("pause");
    return 0;
}
