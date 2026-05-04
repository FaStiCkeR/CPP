#include "Vector.h"
#include <iostream>
#include <string>

/**
 * Разработать шаблонный класс Вектор. Предусмотреть вариант хранения в векторе строк символов. Перегрузить операции
 * +,-. *. В классе должен быть конструктор. Предусмотреть член-функцию для
 * печати элементов класса.
 */

int main() {
    // ---------- 1. Целые числа ----------
    Vector<int> a(3);
    a[0] = 1; a[1] = 2; a[2] = 3;
    Vector<int> b(3);
    b[0] = 4; b[1] = 5; b[2] = 6;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    std::cout << "a + b = " << a + b << "\n";
    std::cout << "a - b = " << a - b << "\n";
    std::cout << "a * b = " << a * b << "\n\n";

    // ---------- 2. Строки ----------
    Vector<std::string> sa(2);
    sa[0] = "Hello";
    sa[1] = "World";

    Vector<std::string> sb(2);
    sb[0] = " ";
    sb[1] = "!";

    std::cout << "sa = " << sa << "\n";
    std::cout << "sb = " << sb << "\n";
    std::cout << "sa + sb = " << sa + sb << "\n";   // конкатенация
    std::cout << "sa * sb = " << sa * sb << "\n\n"; // повтор + сумма

    // Тест «удаление подстроки»
    Vector<std::string> sc(2);
    sc[0] = "HelloHello";
    sc[1] = "WorldWorld";

    Vector<std::string> sd(2);
    sd[0] = "Hello";
    sd[1] = "World";

    std::cout << "sc = " << sc << "\n";
    std::cout << "sd = " << sd << "\n";
    std::cout << "sc - sd = " << sc - sd << "\n\n"; // удаление первого вхождения

    // ---------- 3. Ввод вектора ----------
    std::cout << "Enter 3 integers: ";
    Vector<int> userVec(3);
    std::cin >> userVec;
    std::cout << "You entered: " << userVec << "\n";

    return 0;
}