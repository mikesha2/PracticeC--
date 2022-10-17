#ifndef MAT4_HPP
#define MAT4_HPP

#include <iostream>

namespace mat4 {
    template <typename T>
    struct mat4 {
        T M[3][4];
    };
    
    typedef mat4<double> dmat4;
    typedef mat4<float> fmat4;

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const mat4<T>& a) {
        os << 'R:\n';
        for (uint16_t i = 0; i < 3; i++) {
            for (uint16_t j = 0; j < 3; j++) {
                os << a.M[i][j] << ' ';
            }
            os << '\n';
        }
        os << 'T:\n';
        for (uint16_t i = 0; i < 3; i++) {
            os << a.M[3][i] << ' ';
        }
        return os;
    }

    template <typename T>
    mat4<T> operator+(const mat4<T>& a, const mat4<T>& b) {
        mat4<T> ret;
        for (uint16_t i = 0; i < 3; i++) {
            for (uint16_t j = 0; j < 4; j++) {
                ret.M[i][j] = a.M[i][j] + b.M[i][j];
            }
        }
        return ret;
    }

    template <typename T>
    mat4<T>& operator+=(const mat4<T>& a, const mat4<T>& b) {
        for (uint16_t i = 0; i < 3; i++) {
            for (uint16_t j = 0; j < 4; j++) {
                a.M[i][j] = a.M[i][j] + b.M[i][j];
            }
        }
        return a;
    }

    template <typename T>
    mat4<T> operator-(const mat4<T>& a, const mat4<T>& b) {
        mat4<T> ret;
        for (uint16_t i = 0; i < 3; i++) {
            for (uint16_t j = 0; j < 4; j++) {
                ret.M[i][j] = a.M[i][j] - b.M[i][j];
            }
        }
        return ret;
    }

    template <typename T>
    mat4<T>& operator-=(const mat4<T>& a, const mat4<T>& b) {
        for (uint16_t i = 0; i < 3; i++) {
            for (uint16_t j = 0; j < 4; j++) {
                a.M[i][j] = a.M[i][j] - b.M[i][j];
            }
        }
        return a;
    }

    template <typename T>
    mat4<T> operator*(const mat4<T>& a, const mat4<T>& b) {
        mat4<T> ret;

        for (uint16_t i = 0; i < 3; i++) {
            for (uint16_t j = 0; j < 3; j++) {
                ret.M[i][j] = 0;
                for (uint16_t k = 0; k < 3; k++) {
                    ret.M[i][j] += a.M[i][k] * b.M[k][j];
                }
            }
        }
        return ret;
    }

    template <typename T>
    mat4<T>& operator*=(const mat4<T>& a, const mat4<T>& b) {
        for (uint16_t i = 0; i < 3; i++) {
            for (uint16_t j = 0; j < 3; j++) {
                a.M[i][j] = a.M[i][0] * b.M[0][j];
                for (uint16_t k = 1; k < 3; k++) {
                    a.M[i][j] += a.M[i][k] * b.M[k][j];
                }
            }
        }
        return a;
    }

    template <typename T>
    void translate(const mat4<T>& a, const mat4<T>& b) {
        for (uint16_t i = 0; i < 3; i++) {
            a.M[3][i] += b.M[3][i];
        }
    }

    template <typename T>
    void zero(mat4<T>& a) {
        for (uint16_t i = 0; i < 3; i++) {
            for (uint16_t j = 0; j < 4; j++) {
                a.M[i][j] = 0;
            }
        }
    }

    template <typename T>
    void zero(mat4<T>& ret) {
        for (uint16_t i = 0; i < 3; i++) {
            for (uint16_t j = 0; j < 4; j++) {
                ret.M[i][j] = 0;
            }
        }
        return ret;
    }

    template <typename T>
    mat4<T>& e_ij(int I, int J) {
        mat4<T> ret;
        for (uint16_t i = 0; i < 3; i++) {
            for (uint16_t j = 0; j < 4; j++) {
                ret.M[i][j] = 0;
            }
        }
        ret[I][J] = 1;
        return ret;
    }

    template <typename T>
    mat4<T>& x_hat() {
        return e_ij(3, 0);
    }

    template <typename T>
    mat4<T>& y_hat() {
        return e_ij(3, 1);
    }

    template <typename T>
    mat4<T>& z_hat() {
        return e_ij(3, 2);
    }

    template <typename T>
    void id(mat4<T>& ret) {
        mat4<T> ret;
        for (uint16_t i = 0; i < 3; i++) {
            for (uint16_t j = 0; j < 3; j++) {
                ret.M[i][j] = 0;
            }
            ret.M[i][i] = 1;
            ret.M[3][i] = 0;
        }
        return ret;
    }

    void testMat4Add() {
        std::cout << "Running matrix multiplication..." << std::endl;
        dmat4 A, B;

        zero<double>(A);
        id<double>(B);
        std::cout << A + B;
    }
}

#endif /* MAT4_HPP */