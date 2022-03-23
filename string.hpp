#pragma once

#ifndef INCLUDE_STRING_HPP_
#define INCLUDE_STRING_HPP_

#include <cstddef>
#include <iostream>
#include <utility>

class String {
public:
    /// Деструктор
    ~String() {
        delete[] Data;
        Data = nullptr;
    }

    /// Конструктор по умолчанию
    String() : Data(nullptr) {}

    /// Конструктор копирования
    /// <param name="rhs">Объект, который копируем </param>
    String(const String& rhs) {
        size_t len = rhs.Size();
        Data = new char[len + 1];
        for (size_t i = 0; i < len; ++i) {
            Data[i] = rhs.Data[i];
        }
        Data[len] = '\0';
    }

    /// Пользовательский конструктор
    /// <param name="data">Данные, которые требуется поместить в создаваемый
    /// объект </param>
    explicit String(const char* data) {
        size_t len = 0;
        while (data[len] != '\0') {
            ++len;
        }
        Data = new char[len + 1];
        for (size_t i = 0; i < len; ++i) {
            Data[i] = data[i];
        }
        Data[len] = '\0';
    }

    /// Оператор присваивания
    /// <param name="data">Объект, который копируем </param>
    /// <returns>Возвращаем ссылку на себя</returns>
    String& operator=(const String& rhs) {
        if (this == &rhs) {
            return *this;
        }
        delete[] Data;

        size_t len = rhs.Size();
        Data = new char[len + 1];
        for (size_t i = 0; i <= len; ++i) {
            Data[i] = rhs[i];
        }
        return *this;
    }

    /// Оператор +=
    /// <param name="rhs">Объект, который стоит после знака '+=' </param>
    /// <returns>Возвращаем ссылку на себя</returns>
    String& operator+=(const String& rhs) {
        char* extended = new char[Size() + rhs.Size() + 1];
        size_t i = 0;
        for (size_t j = 0; j < Size(); ++j, ++i) {
            extended[i] = Data[j];
        }
        for (size_t j = 0; j < rhs.Size(); ++j, ++i) {
            extended[i] = rhs.Data[j];
        }
        extended[i] = '\0';
        delete[] Data;
        Data = extended;
        return *this;
    }

    String& operator+=(const char* str) {
        String rhs(str);
        *this += rhs;
        return *this;
    }

    /// Оператор *=
    /// <returns>Возвращаем ссылку на себя</returns>
    String& operator*=(unsigned int m) {
        String extended(*this);
        for (unsigned int i = 0; i < m; ++i) {
            extended += *this;
        }
        *this = extended;
        return *this;
    }

    /// Оператор ==
    /// <param name="rhs">Объект, который стоит после знака '==' </param>
    /// <returns>Возвращаем значения равенства двух строк</returns>
    bool operator==(const String& rhs) const {
        for (size_t i = 0; Data[i] != '\0' || rhs[i] != '\0'; ++i) {
            if (Data[i] != rhs[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator==(const char* rhs) const {
        for (size_t i = 0; Data[i] != '\0' || rhs[i] != '\0'; ++i) {
            if (Data[i] != rhs[i]) {
                return false;
            }
        }
        return true;
    }
    /// Оператор &lt;
    /// <param name="rhs">Объект, который стоит после знака "&lt;" </param>
    /// <returns>Возвращаем значения сравнения двух строк</returns>
    bool operator<(const String& rhs) const {
        for (size_t i = 0; Data[i] != '\0' || rhs[i] != '\0'; ++i) {
            if (Data[i] >= rhs[i]) {
                return false;
            }
        }
        return true;
    }

    /// Функция поиска подстроки
    /// <param name="substr">Подстрока, которую необходимо найти </param>
    /// <returns>Возвращаем позицию substr. Если подстрока не найдена, то
    /// возвратить -1</returns>
    [[nodiscard]] size_t Find(const String& substr) const {
        for (size_t i = 0; i < Size(); ++i) {
            for (size_t j = i; j < substr.Size() + i; ++j) {
                if (Data[j] != substr.Data[j - i]) {
                    break;
                }
                if (substr[j - i + 1] == '\0') {
                    return i;
                }
            }
        }
        return -1;
    }

    [[nodiscard]] size_t Find(const char* str) const {
        String substr(str);
        return Find(substr);
    }

    /// Функция замены символов, заменяет все символы oldSymbol на newSymbol.
    /// <param name="oldSymbol">Символ, который требуется заменить </param>
    /// <param name="newSymbol">Символ, на который требуется заменить </param>
    void Replace(char oldSymbol, char newSymbol) {
        for (size_t i = 0; i < Size(); ++i) {
            if (Data[i] == oldSymbol) {
                Data[i] = newSymbol;
            }
        }
    }

    /// Функция возвращает длину строки
    /// <returns>Возвращаем длину строки</returns>
    [[nodiscard]] size_t Size() const {
        size_t len = 0;
        if (Data == nullptr) {
            return 0;
        }
        while (Data[len] != '\0') {
            ++len;
        }
        return len;
    }

    /// Функция для определения пуста ли строка
    [[nodiscard]] bool Empty() const { return Data == nullptr; }

    /// Оператор []
    /// <example>
    /// <code>
    /// String str = "some string";
    /// char symbol = str[2]; // symbol == 'm'
    /// </code>
    /// </example>
    /// <param name="index"> Индекс символа </param>
    /// <returns> Значение символа в строке с индексом index</returns>
    char operator[](size_t index) const {
        if (index >= Size()) {
            return '\0';
        }
        return Data[index];
    }

    /// Оператор []
    /// <example>
    /// <code>
    /// String str = "some string";
    /// str[0] = 'S'; // теперь переменная str равна "Some string"
    /// </code>
    /// </example>
    /// <param name="index"> Индекс символа </param>
    /// <returns> Ссылка на символ в строке с индексом index</returns>
    char& operator[](size_t index) {
        if (index > Size()) {
            return Data[Size()];
        }
        return Data[index];
    }

    /// Смотри пример
    /// <example>
    /// <code>
    /// String str = "___some string___";
    /// str.RTrim('_'); // теперь переменная str равна "___some string"
    /// </code>
    /// </example>
    /// <param name="symbol"> Значение символов, которе отрезаем </param>
    void RTrim(char symbol) {
        size_t i = Size() - 1;
        if (Data[i] != symbol) {
            return;
        }
        while (Data[i] == symbol) {
            --i;
        }
        char* temp = new char[i + 2];
        for (size_t j = 0; j <= i; ++j) {
            temp[j] = Data[j];
        }
        temp[i + 1] = '\0';
        delete[] Data;
        Data = temp;
    }

    /// Смотри пример
    /// <example>
    /// <code>
    /// String str = "___some string___";
    /// str.LTrim('_'); // теперь переменная str равна "some string___"
    /// </code>
    /// </example>
    /// <param name="symbol"> Значение символов, которе отрезаем </param>
    void LTrim(char symbol) {
        size_t i = 0;
        if (Data[i] != symbol) {
            return;
        }
        while (Data[i] == symbol) {
            ++i;
        }
        char* temp = new char[Size() - i + 1];
        for (size_t j = i; j < Size(); ++j) {
            temp[j - i] = Data[j];
        }
        temp[Size() - i] = '\0';
        delete[] Data;
        Data = temp;
    }

    void swap(String& oth) {
        char* temp = oth.Data;
        oth.Data = Data;
        Data = temp;
    }

    friend std::ostream& operator<<(std::ostream&, const String&);
    friend String operator+(const String& a, const String& b);

private:
    char* Data;
};

/// Оператор +
/// <example>
/// <code>
/// String a = "Hello";
/// String b = "World";
/// String c = a + b; // c равна "HelloWorld"
/// </code>
/// </example>
/// <returns>Возвращаем строку равную a + b</returns>
String operator+(const String& a, const String& b) {
    String extended(a);
    extended += b;
    return extended;
}

/// Оператор *
/// <example>
/// <code>
/// String a = "A";
/// String c = a * 5; // c равна "AAAAA"
/// </code>
/// </example>
String operator*(const String& a, unsigned int b) {
    String extended(a);
    for (unsigned int i = 1; i < b; ++i) {
        extended += a;
    }
    return extended;
}

/// Оператор !=
bool operator!=(const String& a, const String& b) { return !(a == b); }

/// Оператор &gt;
bool operator>(const String& a, const String& b) { return b < a; }

bool operator==(const char* lhs, const String& rhs) {
    for (size_t i = 0; lhs[i] != '\0' || rhs[i] != '\0'; ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

/// Оператор вывода
/// <param name="out">Поток куда выводим строку </param>
/// <param name="str">Строка, которую выводим </param>
/// <returns>Возвращаем ссылку на поток</returns>
std::ostream& operator<<(std::ostream& out, const String& str) {
    out << str.Data;
    return out;
}



#endif  // INCLUDE_STRING_HPP_
