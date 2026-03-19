#include "../Modules_Bureiko.h"
#include <cmath>

double s_calculation(double x, double y, double z) {
    return pow(3.0 * sin(sqrt(12.0 * x) + log10(x - 3.0)), y) + (z / x);
}
