#include <iostream>
#include <windows.h>

#include "struct_type_project_4.h"
#include "Modules_Bureiko.h"

using namespace std;

int main() {
    // налаштування консолі для відображення кирилиці
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ініціалізуємо порожній список
    RouteNode* head = nullptr;

    cout << "================ ІНІЦІАЛІЗАЦІЯ СИСТЕМИ ================\n";
    cout << ">>> Тестовий режим \n";
    cout << "=======================================================\n";

    char choice;
    while (true) {
        cout << "\n===== МЕНЮ ТЕСТУВАННЯ =====\n";
        cout << "1 - Додавання нового рейса (Функція 1)\n";
        cout << "2 - Вилучення рейса за номером (Функція 2)\n";
        cout << "3 - [DEBUG] Показати поточні рейси у пам'яті\n";
        cout << "0 - Завершення роботи\n";
        cout << "Оберіть дію: ";
        cin >> choice;

        if (choice == '0') {
            break; // вихід з нескінченного циклу
        }

        switch (choice) {
            case '1': {
                // функція 1: додавання
                add_route(head);
                break;
            }
            case '2': {
                char route_num[15];
                cout << "Введіть номер рейсу для вилучення: ";
                cin >> ws;
                cin.getline(route_num, 15);
                // функція 2: вилучення
                delete_route(head, route_num);
                break;
            }
            case '3': {
                // тимчасовий локальний вивід для перевірки
                cout << "\n--- ПОТОЧНИЙ СПИСОК РЕЙСІВ ---\n";
                RouteNode* temp = head;
                if (temp == nullptr) {
                    cout << "Список порожній.\n";
                }
                while (temp != nullptr) {
                    cout << "Рейс №" << temp->route_number << " (" << temp->route_name << ")\n";
                    temp = temp->next;
                }
                cout << "------------------------------\n";
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
    cout << ">>> Збереження у файл відключено.\n";

    // ручне очищення динамічної пам'яті перед виходом
    while (head != nullptr) {
        RouteNode* temp = head;
        head = head->next;
        delete temp;
    }
    cout << ">>> Динамічну пам'ять успішно очищено.\n";
    cout << "===================================================\n";

    return 0;
}
