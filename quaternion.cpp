#include "quaternion.hpp"

template <typename T>
std::ostream& operator<<(std::ostream& os, const quaternion<T>& a) {
    return os << a.real << " + " << a.x << "i + " << a.y << "j + " << a.z << "k";
}

template <typename T>
quaternion<T> operator+(const quaternion<T>& a, const quaternion<T>& b) {
    return {a.real + b.real, a.x + b.x, a.y + b.y, a.z + b.z};
}

template <typename T>
quaternion<T> operator-(const quaternion<T>& a, const quaternion<T>& b) {
    return {a.real - b.real, a.x - b.x, a.y - b.y, a.z - b.z};
}

template <typename T>
quaternion<T> operator*(const quaternion<T>& a, const quaternion<T>& b) {
    return {
        a.real * b.real - a.x * b.x - a.y * b.y - a.z * b.z,
        a.real * b.x + a.x * b.real + a.y * b.z - a.z * b.y,
        a.real * b.y - a.x * b.z + a.y * b.real + a.z * b.x,
        a.real * b.z + a.x * b.y - a.y * b.x + a.z * b.real
    };
}

template <typename T>
quaternion<T> operator*(double a, const quaternion<T>& b) {
    return {
        a * b.real,  a * b.x, a * b.y, a * b.z
    }
}

template <typename T>
quaternion<T> operator*(const quaternion<T>& b, double a) {
    return {
        a * b.real,  a * b.x, a * b.y, a * b.z
    }
}

template <typename T>
quaternion<T> operator*(float a, const quaternion<T>& b) {
    return {
        a * b.real,  a * b.x, a * b.y, a * b.z
    }
}

template <typename T>
quaternion<T> operator*(const quaternion<T>& b, float a) {
    return {
        a * b.real,  a * b.x, a * b.y, a * b.z
    }
}



void testQuaternionBasis() {
    std::cout << "Running quaternion basis multiplication..." << std::endl;
    dQuat basis[4];

    basis[0] = {1, 0, 0, 0};
    basis[1] = {0, 1, 0, 0};
    basis[2] = {0, 0, 1, 0};
    basis[3] = {0, 0, 0, 1};

    char names[4] = {'r', 'i', 'j', 'k'};

    for (uint16_t i = 0; i < 4; i++) {
        for (uint16_t j = 0; j < 4; j++) {
            std::cout << names[i] << "*" << names[j] << " = " << basis[i] * basis[j] << std::endl;
        }
    }
}