#include "String.h"
#include <iostream>

/**
 *
 * @return 2.      Лабораторная работа №3. Перегрузка операций
 * Создайте класс Строка с обязательными член–данными: длина строки, указатель на строку (строка хранится в динамически
 * выделенной памяти). Обязательные методы: конструктор по заданной длине строки, конструктор по заданной строке,
 * конструктор по другому объекту класса Строка, конструктор копирования, очистка строки, вывод строки.
 *
 * Перегрузить (переопределить) операции: + (сумма арифметическая ), ==(сравнение), <= (меньше либо равно), >= (больше либо равно).
 */
int main() {
    String s1("Hello");
    String s2("World");
    String s3("Hello");
    String s4(5);
    String s5(s1);

    std::cout << "s1: ";
    s1.print();
    std::cout << std::endl;
    std::cout << "s2: ";
    s2.print();
    std::cout << std::endl;
    std::cout << "s3: ";
    s3.print();
    std::cout << std::endl;
    std::cout << "s4: ";
    s4.print();
    std::cout << std::endl;
    std::cout << "s5 (копия s1): ";
    s5.print();
    std::cout << std::endl;

    String s6 = s1 + s2;
    std::cout << "s1 + s2: ";
    s6.print();
    std::cout << std::endl;

    std::cout << "s1 == s3: " << (s1 == s3 ? "true" : "false") << std::endl;
    std::cout << "s1 == s2: " << (s1 == s2 ? "true" : "false") << std::endl;

    std::cout << "s1 <= s2: " << (s1 <= s2 ? "true" : "false") << std::endl;
    std::cout << "s1 >= s3: " << (s1 >= s3 ? "true" : "false") << std::endl;

    s1.clear();
    std::cout << "После очистки s1: ";
    s1.print();
    std::cout << " (пустая)" << std::endl;

    return 0;
}
