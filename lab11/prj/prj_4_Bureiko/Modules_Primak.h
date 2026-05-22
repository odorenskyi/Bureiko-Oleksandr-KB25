#ifndef MODULES_PRIMAK_H
#define MODULES_PRIMAK_H

#include "struct_type_project_4.h"

// функція 5: пошук запису за назвою автостанції (без розрізнення регістра)
void search_route(RouteNode* head, const char* station_name);

// функція 6: виведення всього розкладу руху на екран у вигляді таблиці
void print_schedule(RouteNode* head);

#endif // MODULES_PRIMAK_H
