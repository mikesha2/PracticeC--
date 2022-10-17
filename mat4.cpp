template <typename T>
struct mat4 {
    T M[4][4];
};

template <typename T>
mat4<T> operator+(const mat4<T>& a, const mat4<T>& b) {
    mat4 ret;
    for (uint16_t i = 0; i < 4; i++) {
        for (uint16_t j = 0; j < 4; j++) {
            ret.M[i][j] = a.M[i][j] + b.M[i][j];
        }
    }
    return ret;
}

template <typename T>
mat4<T>& operator+=(const mat4<T>& a, const mat4<T>& b) {
    for (uint16_t i = 0; i < 4; i++) {
        for (uint16_t j = 0; j < 4; j++) {
            a.M[i][j] = a.M[i][j] + b.M[i][j];
        }
    }
    return a;
}

template <typename T>
mat4<T> operator-(const mat4<T>& a, const mat4<T>& b) {
    mat4 ret;
    for (uint16_t i = 0; i < 4; i++) {
        for (uint16_t j = 0; j < 4; j++) {
            ret.M[i][j] = a.M[i][j] - b.M[i][j];
        }
    }
    return ret;
}

template <typename T>
mat4<T>& operator-=(const mat4<T>& a, const mat4<T>& b) {
    for (uint16_t i = 0; i < 4; i++) {
        for (uint16_t j = 0; j < 4; j++) {
            a.M[i][j] = a.M[i][j] - b.M[i][j];
        }
    }
    return a;
}

template <typename T>
mat4<T> operator*(const mat4<T>& a, const mat4<T>& b) {
    mat4 ret;

    for (uint16_t i = 0; i < 4; i++) {
        for (uint16_t j = 0; j < 4; j++) {
            ret.M[i][j] = 0;
            for (uint16_t k = 0; k < 4; k++) {
                ret.M[i][j] += a.M[i][k] * b.M[k][j];
            }
        }
    }
    return ret;
}

template <typename T>
mat4<T>& operator*=(const mat4<T>& a, const mat4<T>& b) {
    for (uint16_t i = 0; i < 4; i++) {
        for (uint16_t j = 0; j < 4; j++) {
            a.M[i][j] = a.M[i][0] * b.M[0][j];
            for (uint16_t k = 1; k < 4; k++) {
                a.M[i][j] += a.M[i][k] * b.M[k][j];
            }
        }
    }
    return a;
}

typedef mat4<double> dmat4;
typedef mat4<float> fmat4;