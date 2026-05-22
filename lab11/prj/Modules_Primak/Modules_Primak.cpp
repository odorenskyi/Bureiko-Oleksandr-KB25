#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "Modules_Primak.h"

using namespace std;

// допоміжна функція для переведення рядка в нижній регістр (підтримує кирилицю Windows-1251)
string to_lower_ua(const char* str) {
    string lower_str = "";
    for (int i = 0; i < strlen(str); i++) {
        unsigned char c = str[i];
        // Англійські літери
        if (c >= 'A' && c <= 'Z') {
            lower_str += c + 32;
        }
        // Кириличні літери (Windows-1251): 'А'-'Я' (192-223) -> 'а'-'я' (224-255)
        else if (c >= 192 && c <= 223) {
            lower_str += c + 32;
        }
        // Специфічні українські літери (І, Ї, Є)
        else if (c == 178) lower_str += 179; // І -> і
        else if (c == 175) lower_str += 191; // Ї -> ї
        else if (c == 170) lower_str += 186; // Є -> є
        else {
            lower_str += c;
        }
    }
    return lower_str;
}

// функція 5: пошук запису за назвою автостанції (без розрізнення регістра)
void search_route(RouteNode* head, const char* station_name) {
    cout << "\n--- РЕЗУЛЬТАТИ ПОШУКУ ЗА ЗАПИТОМ: \"" << station_name << "\" ---\n";

    if (head == nullptr) {
        cout << ">>> База даних порожня.\n";
        return;
    }

    // переводимо пошуковий запит у нижній регістр
    string query_lower = to_lower_ua(station_name);
    bool found = false;
    RouteNode* temp = head;

    while (temp != nullptr) {
        // переводимо маршрут зі списку у нижній регістр
        string route_lower = to_lower_ua(temp->route_name);

        // шукаємо підрядок (query_lower) у рядку (route_lower)
        if (route_lower.find(query_lower) != string::npos) {
            if (!found) {
                // друкуємо шапку таблиці, якщо знайдено хоча б один збіг
                cout << setfill('-') << setw(100) << "-" << setfill(' ') << "\n";
                cout << left << setw(10) << "Номер"
                     << setw(30) << "Маршрут"
                     << setw(15) << "Періодичність"
                     << setw(10) << "Відпр(Поч)"
                     << setw(10) << "Приб(Кін)"
                     << setw(10) << "Приб(Пот)"
                     << setw(10) << "Відпр(Пот)" << "\n";
                cout << setfill('-') << setw(100) << "-" << setfill(' ') << "\n";
                found = true;
            }
            // виводимо знайдений рейс
            cout << left << setw(10) << temp->route_number
                 << setw(30) << temp->route_name
                 << setw(15) << temp->periodicity
                 << setw(10) << temp->time_start_station_departure
                 << setw(10) << temp->time_end_station_arrival
                 << setw(10) << temp->time_arrival
                 << setw(10) << temp->time_departure << "\n";
        }
        temp = temp->next;
    }

    if (!found) {
        cout << ">>> Рейсів із вказаною станцією не знайдено.\n";
    } else {
        cout << setfill('-') << setw(100) << "-" << setfill(' ') << "\n";
    }
}

// функція 6: виведення всього розкладу руху на екран
void print_schedule(RouteNode* head) {
    cout << "\n================= РОЗКЛАД РУХУ АВТОБУСІВ (АС КРОПИВНИЦЬКИЙ) =================\n";

    if (head == nullptr) {
        cout << ">>> База даних порожня. Додайте рейси для відображення.\n";
        return;
    }

    cout << setfill('-') << setw(100) << "-" << setfill(' ') << "\n";
    cout << left << setw(10) << "Номер"
         << setw(30) << "Маршрут"
         << setw(15) << "Періодичність"
         << setw(10) << "Відпр(Поч)"
         << setw(10) << "Приб(Кін)"
         << setw(10) << "Приб(Пот)"
         << setw(10) << "Відпр(Пот)" << "\n";
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << "\n";

    RouteNode* temp = head;
    while (temp != nullptr) {
        cout << left << setw(10) << temp->route_number
             << setw(30) << temp->route_name
             << setw(15) << temp->periodicity
             << setw(10) << temp->time_start_station_departure
             << setw(10) << temp->time_end_station_arrival
             << setw(10) << temp->time_arrival
             << setw(10) << temp->time_departure << "\n";

        temp = temp->next;
    }
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << "\n";
}
