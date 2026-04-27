#include "Vector.h"


/**
 * Разработать шаблонный класс Вектор. Предусмотреть вариант хранения в векторе строк символов. Перегрузить операции
 * +, -. *. В классе должен быть конструктор. Предусмотреть член-функцию для
 * печати элементов класса.
 */
int main() {
    // ----- Работа с целыми числами -----
    Vector<int> a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    Vector<int> b(3);
    b[0] = 4;
    b[1] = 5;
    b[2] = 6;

    std::cout << "a = ";
    a.print();
    std::cout << "b = ";
    b.print();

    Vector<int> sum = a + b;
    std::cout << "a + b = ";
    sum.print();

    Vector<int> diff = a - b;
    std::cout << "a - b = ";
    diff.print();

    int dot = a * b;
    std::cout << "a * b (скалярное) = " << dot << std::endl;

    // ----- Работа со строками -----
    Vector<std::string> sa(2);
    sa[0] = "Hello";
    sa[1] = "World";

    Vector<std::string> sb(2);
    sb[0] = " ";
    sb[1] = "!";

    std::cout << "\nsa = ";
    sa.print();
    std::cout << "sb = ";
    sb.print();

    Vector<std::string> s_sum = sa + sb; // конкатенация
    std::cout << "sa + sb = ";
    s_sum.print();

    Vector<std::string> sc(2);
    sc[0] = "HelloHello";
    sc[1] = "WorldWorld";
    Vector<std::string> sd(2);
    sd[0] = "Hello";
    sd[1] = "World";

    std::cout << "sc = ";
    sc.print();
    std::cout << "sd = ";
    sd.print();

    Vector<std::string> s_diff = sc - sd; // удаление подстроки
    std::cout << "sc - sd = ";
    s_diff.print();

    std::string s_dot = sa * sb; // повторение строки
    std::cout << "sa * sb = " << s_dot << std::endl;

    return 0;
}
