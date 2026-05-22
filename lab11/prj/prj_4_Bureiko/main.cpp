#include <iostream>
#include <windows.h>

// підключаємо спільну структуру та всі три бібліотеки команди
#include "struct_type_project_4.h"
#include "Modules_Bureiko.h"
#include "Modules_Rudenko.h"
#include "Modules_Primak.h"

using namespace std;

int main() {
    // налаштування консолі для відображення кирилиці
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ініціалізуємо порожній список
    RouteNode* head = nullptr;

    // назва файлу бази даних
    const char* db_filename = "routes_db.dat";

    cout << "================ ІНІЦІАЛІЗАЦІЯ СИСТЕМИ ================\n";
    // функція 3: автоматичне завантаження БД при запуску
    load_from_binary(head, db_filename);
    cout << "=======================================================\n";

    char choice;
    while (true) {
        cout << "\n===== ГОЛОВНЕ МЕНЮ (ІС \"Розклад руху автобусів\") =====\n";
        cout << "1 - Пошук запису за назвою автостанції\n";
        cout << "2 - Виведення всього розкладу руху\n";
        cout << "3 - Додавання нового рейса\n";
        cout << "4 - Вилучення рейса за номером\n";
        cout << "0 - Завершення роботи та збереження бази даних\n";
        cout << "Оберіть дію: ";
        cin >> choice;

        if (choice == '0') {
            break; // вихід з нескінченного циклу
        }

        switch (choice) {
            case '1': {
                char station[100];
                cout << "Введіть назву автостанції (початкової або кінцевої): ";
                cin >> ws; // Очищення буфера
                cin.getline(station, 100);
                // функція 5
                search_route(head, station);
                break;
            }
            case '2': {
                // функція 6
                print_schedule(head);
                break;
            }
            case '3': {
                // функція 1
                add_route(head);
                break;
            }
            case '4': {
                char route_num[15];
                cout << "Введіть номер рейсу для вилучення: ";
                cin >> ws;
                cin.getline(route_num, 15);
                // функція 2
                delete_route(head, route_num);
                break;
            }
            default: {
                // звуковий сигнал при помилковому введенні
                cout << "\aПОМИЛКА: Невідома команда! Спробуйте ще раз.\n";
                break;
            }
        }
    }

    cout << "\n================ ЗАВЕРШЕННЯ РОБОТИ ================\n";
    // функція 4: автоматичне збереження та очищення пам'яті
    save_to_binary(head, db_filename);
    cout << "===================================================\n";

    return 0;
}
