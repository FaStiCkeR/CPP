#include "String.h"
#include <iostream>
#include <cstring>
#include <stdexcept>

/**
 * Конструктор по умолчанию, генерирующий пустую строку при инициализации экземпляра класса.
 */

// Конструктор по умолчанию - создает пустую строку
String::String() {
    length = 0;
    data = new char[1];
    data[0] = '\0';
}

// Создает строку из n пробелов
String::String(size_t n) : length(n), data(new char[n + 1]) {
    for (size_t i = 0; i < n; ++i)
        data[i] = ' ';
    data[n] = '\0';
}
// Создает строку из C-строки
String::String(const char *s) : length(std::strlen(s)), data(new char[length + 1]) {
    std::strcpy(data, s);
}
// Конструктор копирования
String::String(const String &other) : length(other.length), data(new char[length + 1]) {
    std::strcpy(data, other.data);
}
// Деструктор
String::~String() {
    delete[] data;
}

// Присваивает содержимое одной существующей строки другой уже существующей строке.
String &String::operator=(const String &other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }
    return *this;
}

// очищает строку
void String::clear() {
    delete[] data;
    length = 0;
    data = new char[1];
    data[0] = '\0';
}

// выводит строку в консоль
void String::print() const {
    std::cout << data;
}
// возвращает C-строку
String String::operator+(const String &other) const {
    size_t newLen = length + other.length;
    char *buf = new char[newLen + 1];
    std::strcpy(buf, data);
    std::strcat(buf, other.data);
    String result(buf);
    delete[] buf;
    return result;
}

bool String::operator==(const String &other) const {
    if (length != other.length)
        return false;
    return std::strcmp(data, other.data) == 0;
}

bool String::operator<=(const String &other) const {
    return std::strcmp(data, other.data) <= 0;
}

bool String::operator>=(const String &other) const {
    return std::strcmp(data, other.data) >= 0;
}

char& String::operator[](size_t index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const char& String::operator[](size_t index) const {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const char *String::c_str() const {
    return data;
}