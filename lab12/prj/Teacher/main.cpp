#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "../../../lab08/prj/Modules_Bureiko.h"

using namespace std;

void run_unit_tests() {
    ifstream test_file("C:\\BMTP\\Bureiko-Oleksandr-KB25\\lab12\\TestSuite\\test_cube.txt");
    ofstream log_file("C:\\BMTP\\Bureiko-Oleksandr-KB25\\lab12\\TestSuite\\TestResults.txt");

    if (!test_file.is_open()) {
        log_file << "Помилка: не вдалося відкрити файл з тестами test_cube.txt" << endl;
        return;
    }

    log_file << "=== Протокол тестування ClassLab12_Bureiko ===" << endl;

    double input_edge, expected_area;
    int test_id = 1;

    while (test_file >> input_edge >> expected_area) {
        ClassLab12_Bureiko cube(input_edge);
        double actual_area = cube.calculate_surface_area();

        log_file << "Test Case ID " << test_id << " -> Action: initialize with " << input_edge
                 << " -> Expected: " << expected_area
                 << " -> Result: " << actual_area;

        if (actual_area == expected_area) {
            log_file << " [PASSED]" << endl;
        } else {
            log_file << " [FAILED]" << endl;
        }
        test_id++;
    }

    test_file.close();
    log_file.close();
    cout << "Тестування завершено. Результати у TestResults.txt" << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string current_file = __FILE__;

    if (current_file.find("\\lab12\\prj") == string::npos && current_file.find("/lab12/prj") == string::npos) {
        for (int i = 0; i < 100; i++) {
            cout << '\a';
        }

        ofstream log_file("TestResults.txt");
        log_file << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << endl;
        log_file.close();

        cout << "Помилка шляху! Записано в лог." << endl;
    } else {
        run_unit_tests();
    }

    system("pause");
    return 0;
}
