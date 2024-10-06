#include "../include/five.hpp"


bool isFiveDigit(unsigned char t) {
    return t == '0' || t == '1' || t == '2' || t == '3' || t == '4';
}

Five::Five() {
    array = new unsigned char[1] {'0'};
    size = 1;
}

Five::Five(const size_t &n, unsigned char t) {
    if (!isFiveDigit(t))
        throw std::invalid_argument("char must be digit from 0 to 4");
    else if (t == '0') {
        array = new unsigned char[1] {'0'};
        size = 1;
    }
    else {
        array = new unsigned char[n];
        size = n;

        for (int i = 0; i < n; ++i) {
            array[i] = t;
        }
    }
}

Five::Five(const std::initializer_list<unsigned char> &t) {
    size_t zeros = 0;
    bool countringZeros = true;

    for (auto c : t) {
        if (!isFiveDigit(c))
            throw std::invalid_argument("char must be digit from 0 to 4");
        else if (countringZeros && c == '0')
            zeros++;
        else
            countringZeros = false;
    }

    size = t.size() - zeros;

    if (size == 0) {
        array = new unsigned char[1] {'0'};
        size = 1;
    }
    else {
        array = new unsigned char[size];
        int i = 0;

        for (auto iter = t.begin() + zeros; iter < t.end(); iter++) {
            array[i] = *iter;
            i++;
        }
    }
}

Five::Five(const std::string &t) {
    size_t zeros = 0;
    bool countringZeros = true;

    for (int i = 0; i < t.size(); ++i) {
        if (!isFiveDigit(t[i])) 
            throw std::invalid_argument("char must be digit from 0 to 4");
        else if (countringZeros && t[i] == '0') 
            zeros++;
        else 
            countringZeros = false;
    }

    size = t.size() - zeros;

    if (size == 0) {
        array = new unsigned char[1] {'0'};
        size = 1;
    }
    else {
        array = new unsigned char[size];
        int i = 0;

        for (int i = 0; i < size; ++i) {
            array[i] = t[zeros + i];
        }
    }
}

Five::Five(const Five &other) {
    size = other.size;

    array = new unsigned char[size];

    for (int i = 0; i < size; ++i)
        array[i] = other.array[i];
}

Five::Five(Five&& other) noexcept {
    array = other.array;
    size = other.size;
    
    other.size = 0;
    other.array = nullptr;
}

const bool Five::operator==(const Five& other) {
    if (size != other.size) return false;

    for (int i = 0; i < size; ++i) {
        if (array[i] != other.array[i]) return false;
    }

    return true;
}

const bool Five::operator!=(const Five& other) {
    return !(*this == other);
}

const bool Five::operator>(const Five& other) {
    if (size > other.size) return true;
    
    if (size < other.size) return false;

    for (int i = 0; i < size; ++i) {
        if ((array[i] - '0') <= (other.array[i] - '0')) return false;
    }

    return true;
}

const bool Five::operator<(const Five& other) {
    if (size < other.size) return true;
    
    if (size > other.size) return false;

    for (int i = 0; i < size; ++i) {
        if ((array[i] - '0') >= (other.array[i] - '0')) return false;
    }

    return true;
}

const bool Five::operator>=(const Five& other) {
    return !(*this < other);
}

const bool Five::operator<=(const Five& other) {
    return !(*this > other);
}

Five Five::operator+(const Five& other) {
    std::string str = "";

    int carry = 0;
    int sum;
    for (int i = 0; i < std::max(size, other.size); ++i) {
        int d1 = i < size ? array[size - 1- i] - '0' : 0;
        int d2 = i < other.size ? other.array[other.size - 1- i] - '0': 0;
        sum = d1 + d2 + carry;

        str += ((sum % 5) + '0');
        carry = sum / 5;
    }

    std::reverse(str.begin(), str.end());

    Five res = Five(str);

    return res;
}

Five Five::operator-(const Five& other) {
    if (other.size > size || *this < other) throw std::logic_error("result can not be negative");

    std::string str = "";

    int borrow = 0;
    int sub;

    for (int i = 0; i < std::max(size, other.size); ++i) {
        int num1 = i < size ? array[size - 1 - i] - '0' : 0;
        int num2 = i < other.size ? other.array[other.size - 1 - i] - '0' : 0;
        sub = num1 - num2 - borrow;

        if (sub < 0) {
            sub += 5;
            borrow = 1;
        }
        else
            borrow = 0;
        
        str += (sub + '0');
    }

    std::reverse(str.begin(), str.end());

    Five res = Five(str);

    return res;
}

Five& Five::operator=(const Five& other) {
    if (*this != other) {
        delete[] array;

        size = other.size;
        array = new unsigned char[size];

        for (int i = 0; i < size; ++i) 
            array[i] = other.array[i];
    }

    return *this;
}

Five& Five::operator+=(const Five& other) {
    Five res = *this + other;

    delete[] array;

    size = res.size;
    array = new unsigned char[size];

    for (int i = 0; i < size; ++i) 
        array[i] = other.array[i];

    return *this;
}

Five& Five::operator-=(const Five& other) {
    Five res = *this - other;

    delete[] array;

    size = res.size;
    array = new unsigned char[size];

    for (int i = 0; i < size; ++i) 
        array[i] = other.array[i];

    return *this;
}

std::ostream& operator<<(std::ostream& out, Five& f) {
    for (int i = 0; i < f.size; ++i) 
        out << f.array[i];

    return out;
}

Five::~Five() {
    if (size > 0) {
        size = 0;
        delete[] array;
        array = nullptr;
    }
}