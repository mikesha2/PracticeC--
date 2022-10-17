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
            ret.M[i][j] = a.M[i][j] + b.M[i][j];
        }
    }
    return a;
}

typedef mat4<double> dmat4;
typedef mat4<float> fmat4;