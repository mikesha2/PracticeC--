#ifndef VEC3_HPP
#define VEC3_HPP

#include <iostream>

namespace vec3 {
    template <typename T>
    struct vec3 {
        T V[3];
    };

    typedef vec3<double> dmat3;
    typedef vec3<float> fmat3;

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const vec3<T>& a) {
        for (auto i : a) {
            os << i << ' ';
        }
        return os;
    }

    template <typename T>
    vec3<T> operator+(const vec3<T>& a, const vec3<T>& b) {
        vec3<T> ret;
        for (uint16_t i = 0; i < 3; i++) {
            ret.V[i] = a.V[i] + b.V[i];
        }
        return ret;
    }
    
    template <typename T>
    vec3<T>& operator+=(vec3<T>& a, const vec3<T>& b) {
        for (uint16_t i = 0; i < 3; i++) {
            a.V[i] += b.V[i];
        }
        return a;
    }


    template <typename T>
    vec3<T> operator-(const vec3<T>& a, const vec3<T>& b) {
        vec3<T> ret;
        for (uint16_t i = 0; i < 3; i++) {
            ret.V[i] = a.V[i] - b.V[i];
        }
        return ret;
    }
    
    template <typename T>
    vec3<T>& operator-=(vec3<T>& a, const vec3<T>& b) {
        for (uint16_t i = 0; i < 3; i++) {
            a.V[i] -= b.V[i];
        }
        return a;
    }

    template <typename T>
    vec3<T> zero() {
        vec3<T> ret;
        for (uint16_t i = 0; i < 3; i++) {
            ret.V[i] = 0;
        }
        return ret;
    }

    template <typename T>
    vec3<T> x_hat() {
        vec3<T> ret;
        ret.V[0] = 1;
        ret.V[1] = 0;
        ret.V[2] = 0;
        return ret;
    }
    
    template <typename T>
    vec3<T> y_hat() {
        vec3<T> ret;
        ret.V[0] = 0;
        ret.V[1] = 1;
        ret.V[2] = 0;
        return ret;
    }

    template <typename T>
    vec3<T> z_hat() {
        vec3<T> ret;
        ret.V[0] = 0;
        ret.V[1] = 0;
        ret.V[2] = 1;
        return ret;
    }
}

#endif