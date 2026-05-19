#ifndef MODULES_BUREIKO_H
#define MODULES_BUREIKO_H

// підключаємо наш спільний файл зі структурою
#include "struct_type_project_4.h"

// функція 1: додавання нового рейсу до списку
// передаємо вказівник на початок списку за посиланням (*&), щоб мати змогу його змінити
void add_route(RouteNode*& head);

// функція 2: вилучення рейсу зі списку за його номером
void delete_route(RouteNode*& head, const char* route_num_to_delete);

#endif // MODULES_BUREIKO_H
