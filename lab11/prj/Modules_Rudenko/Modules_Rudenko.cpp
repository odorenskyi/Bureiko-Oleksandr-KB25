#include <iostream>
#include <fstream>
#include <cstring>
#include "Modules_Rudenko.h"

using namespace std;

// автоматичне завантаження з бінарного файлу
void load_from_binary(RouteNode*& head, const char* filename) {
    // відкриваємо файл для читання в бінарному режимі
    ifstream fin(filename, ios::binary);

    // якщо файлу ще немає (перший запуск програми) — просто робимо список порожнім
    if (!fin.is_open()) {
        head = nullptr;
        return;
    }

    RouteNode tempBlock;
    RouteNode* tail = nullptr;

    // зчитуємо файл поблочно (розміром з екземпляр RouteNode)
    while (fin.read((char*)&tempBlock, sizeof(RouteNode))) {
        // виділяємо пам'ять під новий вузол списку
        RouteNode* newNode = new RouteNode;

        // копіюємо зчитані статичні дані (поля char)
        strcpy(newNode->route_number, tempBlock.route_number);
        strcpy(newNode->route_name, tempBlock.route_name);
        strcpy(newNode->periodicity, tempBlock.periodicity);
        strcpy(newNode->time_arrival, tempBlock.time_arrival);
        strcpy(newNode->time_departure, tempBlock.time_departure);
        strcpy(newNode->time_start_station_departure, tempBlock.time_start_station_departure);
        strcpy(newNode->time_end_station_arrival, tempBlock.time_end_station_arrival);

        // занулюємо вказівник, тому що адреса з файлу більше не дійсна
        newNode->next = nullptr;

        // відновлюємо зв'язки в однозв'язному списку
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    fin.close();
    cout << ">>> Базу даних успішно завантажено з файлу: " << filename << "\n";
}

// автоматичне збереження у бінарний файл з очищенням пам'яті
void save_to_binary(RouteNode* head, const char* filename) {
    // відкриваємо файл у режимі запису, бінарному, із зачищенням старого вмісту (trunc)
    ofstream fout(filename, ios::binary | ios::trunc);
    if (!fout.is_open()) {
        cout << ">>> Помилка запису в бінарний файл!\n";
        return;
    }

    RouteNode* temp = head;
    int count = 0;

    // проходимо по всьому списку до кінця
    while (temp != nullptr) {
        // записуємо поточний вузол як сирий набір байтів
        fout.write((char*)temp, sizeof(RouteNode));

        // паралельно виконуємо важливу інженерну дію - звільняємо пам'ять при виході
        RouteNode* toDelete = temp;
        temp = temp->next;
        delete toDelete;

        count++;
    }

    fout.close();
    cout << ">>> ІС автоматично збережено у файл (" << count << " записів).\n";
    cout << ">>> Динамічну пам'ять успішно очищено.\n";
}
