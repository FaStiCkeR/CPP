#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <string>   // для работы со строками

// Операторы для std::string, необходимые для работы Vector<std::string>
// Определены до шаблона, чтобы быть видимыми при инстанцировании.
inline std::string operator-(const std::string &a, const std::string &b) {
    std::string result = a;
    size_t pos = 0;
    while ((pos = result.find(b, pos)) != std::string::npos) {
        result.erase(pos, b.length());
    }
    return result;
}

inline std::string operator*(const std::string &a, const std::string &b) {
    std::string result;
    size_t repeat = b.length();
    for (size_t i = 0; i < repeat; ++i)
        result += a;
    return result;
}

// Шаблонный класс Vector
template<typename T>
class Vector {
private:
    T *data;
    size_t size;

public:
    // Конструкторы
    Vector() : Vector(0) {
    }

    explicit Vector(size_t n) : data(new T[n]()), size(n) {
    }

    Vector(const Vector &other) : data(new T[other.size]), size(other.size) {
        for (size_t i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    ~Vector() { delete[] data; }

    // Оператор присваивания
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

    // Доступ по индексу
    T &operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T &operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t getSize() const { return size; }

    // Перегруженные операции
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

    // Скалярное произведение (для чисел) или соответствующая операция для строк
    T operator*(const Vector &other) const {
        if (size != other.size) throw std::invalid_argument("Sizes differ");
        T sum = T(); // значение по умолчанию (0 для чисел, "" для строк)
        for (size_t i = 0; i < size; ++i)
            sum = sum + data[i] * other.data[i];
        return sum;
    }

    void print() const {
        std::cout << "[ ";
        for (size_t i = 0; i < size; ++i)
            std::cout << data[i] << " ";
        std::cout << "]" << std::endl;
    }
};

#endif