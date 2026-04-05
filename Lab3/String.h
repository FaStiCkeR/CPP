#ifndef STRING_H
#define STRING_H

#include <cstddef>

class String {
private:
    size_t length;
    char *data;

public:
    explicit String(size_t n);

    String(const char *s);

    String(const String &other);

    ~String();

    String &operator=(const String &other);

    void clear();

    void print() const;

    String operator+(const String &other) const;

    bool operator==(const String &other) const;

    bool operator<=(const String &other) const;

    bool operator>=(const String &other) const;

    const char *c_str() const;
};

#endif