#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <string>

// ------------------- операторы для строк -------------------
// Вычитание: удаление ПЕРВОГО вхождения
inline std::string operator-(const std::string &a, const std::string &b) {
    std::string result = a;
    size_t pos = result.find(b);
    if (pos != std::string::npos)
        result.erase(pos, b.length());
    return result;
}

// Умножение: повторение строки a столько раз, какова длина b
inline std::string operator*(const std::string &a, const std::string &b) {
    std::string result;
    size_t repeat = b.length();
    for (size_t i = 0; i < repeat; ++i)
        result += a;
    return result;
}

// ------------------- шаблонный класс Vector -------------------
template<typename T>
class Vector {
private:
    T *data;
    size_t size;

public:
    Vector() : Vector(0) {}
    explicit Vector(size_t n) : data(new T[n]()), size(n) {}
    Vector(const Vector &other) : data(new T[other.size]), size(other.size) {
        for (size_t i = 0; i < size; ++i)
            data[i] = other.data[i];
    }
    ~Vector() { delete[] data; }

    Vector &operator=(const Vector &other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (size_t i = 0; i < size; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    T &operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }
    const T &operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t getSize() const { return size; }

    // Арифметические операции
    Vector operator+(const Vector &other) const {
        if (size != other.size) throw std::invalid_argument("Sizes differ");
        Vector result(size);
        for (size_t i = 0; i < size; ++i)
            result.data[i] = data[i] + other.data[i];
        return result;
    }

    Vector operator-(const Vector &other) const {
        if (size != other.size) throw std::invalid_argument("Sizes differ");
        Vector result(size);
        for (size_t i = 0; i < size; ++i)
            result.data[i] = data[i] - other.data[i];
        return result;
    }

    T operator*(const Vector &other) const {
        if (size != other.size) throw std::invalid_argument("Sizes differ");
        T sum = T();
        for (size_t i = 0; i < size; ++i)
            sum = sum + data[i] * other.data[i];
        return sum;
    }

    // Печать (можно удалить, оставив только operator<<)
    void print() const {
        std::cout << "[ ";
        for (size_t i = 0; i < size; ++i)
            std::cout << data[i] << " ";
        std::cout << "]" << std::endl;
    }

    // Дружественные функции ввода/вывода
    template<typename U>
    friend std::ostream &operator<<(std::ostream &os, const Vector<U> &vec);

    template<typename U>
    friend std::istream &operator>>(std::istream &is, Vector<U> &vec);
};

// ------------------- реализация ввода/вывода -------------------
template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &vec) {
    os << "[ ";
    for (size_t i = 0; i < vec.size; ++i)
        os << vec.data[i] << " ";
    os << "]";
    return os;
}

template<typename T>
std::istream &operator>>(std::istream &is, Vector<T> &vec) {
    for (size_t i = 0; i < vec.size; ++i) {
        is >> vec.data[i];
    }
    return is;
}

#endif // VECTOR_H