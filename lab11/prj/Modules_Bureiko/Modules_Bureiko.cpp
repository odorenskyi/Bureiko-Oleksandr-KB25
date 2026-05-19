#include <iostream>
#include <cstring>
#include "Modules_Bureiko.h"

using namespace std;

// функція додавання нового рейсу (додає в кінець списку)
void add_route(RouteNode*& head) {
    // виділяємо динамічну пам'ять для нового елемента
    RouteNode* newNode = new RouteNode;

    cout << "\n--- ДОДАВАННЯ НОВОГО РЕЙСУ ---\n";
    cout << "Введіть номер рейсу: ";
    cin >> ws; // очищення буфера вводу перед зчитуванням рядка
    cin.getline(newNode->route_number, 15);

    cout << "Введіть маршрут (наприклад, Кропивницький - Дніпро): ";
    cin.getline(newNode->route_name, 100);

    cout << "Введіть періодичність (наприклад, щоденно): ";
    cin.getline(newNode->periodicity, 50);

    cout << "Введіть час відправлення з поч. станції (гг:хх): ";
    cin.getline(newNode->time_start_station_departure, 6);

    cout << "Введіть час прибуття на кінц. станцію (гг:хх): ";
    cin.getline(newNode->time_end_station_arrival, 6);

    cout << "Введіть час прибуття на поточну АС (гг:хх, якщо транзит, інакше -): ";
    cin.getline(newNode->time_arrival, 6);

    cout << "Введіть час відправлення з поточної АС (гг:хх, якщо транзит, інакше -): ";
    cin.getline(newNode->time_departure, 6);

    // новий елемент буде останнім, тому його next вказує на порожнечу
    newNode->next = nullptr;

    // якщо список порожній, новий елемент стає першим (head)
    if (head == nullptr) {
        head = newNode;
    } else {
        // інакше шукаємо останній елемент списку
        RouteNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // приєднуємо новий елемент до кінця
        temp->next = newNode;
    }
    cout << ">>> Рейс успішно додано до ІС!\n";
}

// функція вилучення заданого рейсу за номером
void delete_route(RouteNode*& head, const char* route_num) {
    // якщо список порожній
    if (head == nullptr) {
        cout << ">>> База даних порожня. Немає що видаляти.\n";
        return;
    }

    // якщо видалити потрібно перший елемент списку
    if (strcmp(head->route_number, route_num) == 0) {
        RouteNode* temp = head;     // запам'ятовуємо старий початок
        head = head->next;          // зсуваємо початок на другий елемент
        delete temp;                // звільняємо пам'ять
        cout << ">>> Рейс " << route_num << " успішно вилучено з ІС.\n";
        return;
    }

    // шукаємо елемент всередині або в кінці списку
    RouteNode* current = head;
    // йдемо по списку, поки не дійдемо до кінця АБО поки наступний елемент не буде шуканим
    while (current->next != nullptr && strcmp(current->next->route_number, route_num) != 0) {
        current = current->next;
    }

    // якщо дійшли до кінця і не знайшли
    if (current->next == nullptr) {
        cout << ">>> Рейс з номером " << route_num << " не знайдено в ІС.\n";
    } else {
        // елемент знайдено. Переприв'язуємо вказівники в обхід елемента, що видаляється
        RouteNode* temp = current->next;
        current->next = current->next->next;
        delete temp; // звільняємо пам'ять
        cout << ">>> Рейс " << route_num << " успішно вилучено з ІС.\n";
    }
}
