#include "../../../lab08/prj/Modules_Bureiko.h"
#include <cmath>

// Конструктор з валідацією початкових даних
ClassLab12_Bureiko::ClassLab12_Bureiko(double a) {
    if (a > 0) {
        edge_length = a;
    } else {
        edge_length = 0.0;
    }
}

// Метод для безпечної зміни атрибута (сетер)
bool ClassLab12_Bureiko::set_edge(double a) {
    if (a > 0) {
        edge_length = a;
        return true;
    }
    return false;
}

// Метод для отримання значення атрибута (гетер)
double ClassLab12_Bureiko::get_edge() {
    return edge_length;
}

// Метод обчислення площі поверхні куба
double ClassLab12_Bureiko::calculate_surface_area() {
    return 6.0 * pow(edge_length, 2);
}
