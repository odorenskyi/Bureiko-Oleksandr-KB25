#ifndef STRUCT_TYPE_PROJECT_4_H
#define STRUCT_TYPE_PROJECT_4_H

// Елемент динамічної структури даних - однозв'язний список
// Інформаційна система "Розклад руху автобусів, АС Кропивницький" (Варіант 4)
struct RouteNode {
    char route_number[15];                // номер рейсу
    char route_name[100];                 // маршрут ("Кропивницький - Київ", тощо)
    char periodicity[50];                 // періодичність (щоденно, парні, непарні, тощо)
    char time_arrival[6];                 // час прибуття (у форматі гд:хв)
    char time_departure[6];               // час відправлення (у форматі гд:хв)
    char time_start_station_departure[6]; // час відправлення з початкової станції (у форматі гд:хв)
    char time_end_station_arrival[6];     // час прибуття до кінцевої станції (у форматі гд:хв)

    // Вказівник для організації динамічної структури
    RouteNode* next;
};

#endif // STRUCT_TYPE_PROJECT_4_H
