#include "String.h"
#include <iostream>
#include <cstring>

String::String(size_t n) : length(n), data(new char[n + 1]) {
    for (size_t i = 0; i < n; ++i)
        data[i] = ' ';
    data[n] = '\0';
}

String::String(const char *s) : length(std::strlen(s)), data(new char[length + 1]) {
    std::strcpy(data, s);
}

String::String(const String &other) : length(other.length), data(new char[length + 1]) {
    std::strcpy(data, other.data);
}

String::~String() {
    delete[] data;
}

String &String::operator=(const String &other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }
    return *this;
}

void String::clear() {
    delete[] data;
    length = 0;
    data = new char[1];
    data[0] = '\0';
}

void String::print() const {
    std::cout << data;
}

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

const char *String::c_str() const {
    return data;
}