#ifndef MODULES_RUDENKO_H
#define MODULES_RUDENKO_H

#include "struct_type_project_4.h"

// функція 3: автоматичне завантаження списку з бінарного файлу при запуску
void load_from_binary(RouteNode*& head, const char* filename);

// функція 4: автоматичне збереження списку в бінарний файл при виході
void save_to_binary(RouteNode* head, const char* filename);

#endif // MODULES_RUDENKO_H
