#include "../Modules_Bureiko.h"
#include <cmath>
#include <algorithm>
#include <fstream>
#include <string>
#include <ctime>

// ЛР№8
double s_calculation(double x, double y, double z) {
    return pow(3.0 * sin(sqrt(12.0 * x) + log10(x - 3.0)), y) + (z / x);
}

// ЛР№9
// Задача 9.1: Тарифи на електроенергію
double calc_electricity_cost(double kwh) {
    if (kwh < 0) return 0.0; // перевірка коректності вводу

    if (kwh <= 150) {
        return kwh * 0.3084;
    }
    else if (kwh <= 800) {
        return (150 * 0.3084) + ((kwh - 150) * 0.4194);
    }
    else {
        return (150 * 0.3084) + (650 * 0.4194) + ((kwh - 800) * 1.3404);
    }
}

// Задача 9.2: Мінімальна швидкість вітру та шкала Бофорта
int get_min_beaufort(double v1, double v2, double v3, double v4, double v5, double v6) {
    // знаходимо мінімальне значення з 6 параметрів
    double min_v = std::min({v1, v2, v3, v4, v5, v6});

    if (min_v < 0) min_v = 0; // захист

    // умови за таблицею шкали Бофорта
    if (min_v < 0.3) return 0;
    else if (min_v <= 1.5) return 1;
    else if (min_v <= 3.4) return 2;
    else if (min_v <= 5.4) return 3;
    else if (min_v <= 7.9) return 4;
    else if (min_v <= 10.7) return 5;
    else if (min_v <= 13.8) return 6;
    else if (min_v <= 17.1) return 7;
    else if (min_v <= 20.7) return 8;
    else if (min_v <= 24.4) return 9;
    else if (min_v <= 28.4) return 10;
    else if (min_v <= 32.6) return 11;
    else return 12; // >= 32.7
}

// Задача 9.3: Аналіз бітів з тернарним оператором
int count_bits_by_condition(unsigned int N) {
    if (N == 0) return 0;

    // отримуємо 9-й біт (зсуваємо вправо на 9 позицій і робимо логічне І з 1)
    bool bit_9 = (N >> 9) & 1;
    int count = 0;

    // проходимо по всіх бітах числа, поки воно більше нуля
    while (N > 0) {
        int current_bit = N & 1; // отримуємо молодший біт

        // використання тернарного оператора за вимогою задачі
        // якщо bit_9 == 1, перевіряємо чи current_bit == 0 (якщо так - додаємо 1, інакше 0)
        // інакше перевіряємо чи current_bit == 1
        count += (bit_9 == 1) ? (current_bit == 0 ? 1 : 0) : (current_bit == 1 ? 1 : 0);

        N >>= 1; // зсуваємо число вправо для перевірки наступного біта
    }

    return count;
}

// ЛР№10

// Задача 10.1: Запис авторської інформації, підрахунок знаків та видалення голосних
void process_10_1(const char* input_filename, const char* output_filename) {
    std::ifstream fin(input_filename);
    if (!fin.is_open()) return; // перевірка відкриття потоку

    std::string sentence, line;
    while (std::getline(fin, line)) {
        sentence += line + "\n";
    }
    fin.close();

    int exclamation_count = 0;
    int question_count = 0;
    std::string no_vowels_sentence = "";

    // рядок голосних літер (українських)
    std::string vowels = "аеєиіїоуюяАЕЄИІЇОУЮЯ";

    for (char c : sentence) {
        if (c == '!') exclamation_count++;
        else if (c == '?') question_count++;

        // якщо символ не знайдено у списку голосних - додаємо його до нового рядка
        if (vowels.find(c) == std::string::npos) {
            no_vowels_sentence += c;
        }
    }

    std::ofstream fout(output_filename);
    if (!fout.is_open()) return; // перевірка відкриття потоку

    fout << "Автор: Олександр Бурейко, ЦНТУ, Кропивницький, Україна, 2026\n";
    fout << "Кількість знаків '!': " << exclamation_count << "\n";
    fout << "Кількість знаків '?': " << question_count << "\n";
    fout << "Текст без голосних: " << no_vowels_sentence;

    fout.close(); // закриття потоку
}

// допоміжна функція для базової транслітерації (постанова КМУ №55)
std::string transliterate_ua_to_lat(const std::string& text) {
    std::string res = "";
    // спрощена логіка заміни для базових символів
    for (size_t i = 0; i < text.length(); ++i) {
        unsigned char c = text[i];
        switch (c) {
            case 224: res += "a"; break; // а
            case 225: res += "b"; break; // б
            case 226: res += "v"; break; // в
            case 227: res += "h"; break; // г
            case 228: res += "d"; break; // д
            case 229: res += "e"; break; // е
            case 230: res += "zh"; break; // ж
            case 231: res += "z"; break; // з
            case 232: res += "y"; break; // и
            case 233: res += "y"; break; // й
            case 234: res += "k"; break; // к
            case 235: res += "l"; break; // л
            case 236: res += "m"; break; // м
            case 237: res += "n"; break; // н
            case 238: res += "o"; break; // о
            case 239: res += "p"; break; // п
            case 240: res += "r"; break; // р
            case 241: res += "s"; break; // с
            case 242: res += "t"; break; // т
            case 243: res += "u"; break; // у
            case 244: res += "f"; break; // ф
            case 245: res += "kh"; break; // х
            case 246: res += "ts"; break; // ц
            case 247: res += "ch"; break; // ч
            case 248: res += "sh"; break; // ш
            case 249: res += "shch"; break; // щ
            case 252: res += "ь"; break; // ь (пропускаємо або залишаємо)
            case 254: res += "yu"; break; // ю
            case 255: res += "ya"; break; // я
            case 179: res += "i"; break; // і
            case 191: res += "yi"; break; // ї
            case 186: res += "ye"; break; // є
            // для великих літер та інших кодувань логіка аналогічна,
            // тут залишено базовий скелет для 1251. якщо символ не розпізнано:
            default: res += text[i]; break;
        }
    }
    return res;
}

// Задача 10.2: Дозапис транслітерації та дати/часу
void append_10_2(const char* input_filename) {
    std::ifstream fin(input_filename);
    if (!fin.is_open()) return;

    std::string content((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());
    fin.close();

    std::string transliterated = transliterate_ua_to_lat(content);

    // отримання локального часу
    time_t now = time(0);
    char* dt = ctime(&now);

    // відкриваємо файл для дозапису (app)
    std::ofstream fout(input_filename, std::ios_base::app);
    if (!fout.is_open()) return;

    fout << "\n" << transliterated << "\n";
    fout << dt; // ctime вже містить '\n' в кінці
    fout.close();
}

// Задача 10.3: Дозапис результатів математичної функції та двійкового коду
void append_10_3(const char* output_filename, double x, double y, double z, unsigned int b) {
    // виклик функції з 8-ї лабораторної
    double s_res = s_calculation(x, y, z);

    // переведення числа b у двійковий рядок
    std::string binary_b = "";
    if (b == 0) {
        binary_b = "0";
    } else {
        unsigned int temp = b;
        while (temp > 0) {
            binary_b = (temp % 2 == 0 ? "0" : "1") + binary_b;
            temp /= 2;
        }
    }

    // відкриваємо файл для дозапису (app)
    std::ofstream fout(output_filename, std::ios_base::app);
    if (!fout.is_open()) return;

    fout << "S = " << s_res << "\n";
    fout << "Binary b: " << binary_b << "\n";
    fout.close();
}
