#ifndef QUATERNION_HPP
#define QUATERNION_HPP

template <typename T>
struct quaternion {
    T real, x, y, z;
};

typedef quaternion<double_t> dQuat;

template <typename T>
std::ostream& operator<<(std::ostream& os, const quaternion<T>& a);

template <typename T>
quaternion<T> operator+(const quaternion<T>& a, const quaternion<T>& b);

template <typename T>
quaternion<T> operator-(const quaternion<T>& a, const quaternion<T>& b);

template <typename T>
quaternion<T> operator*(const quaternion<T>& a, const quaternion<T>& b);

template <typename T>
quaternion<T> operator*(double a, const quaternion<T>& b);

template <typename T>
quaternion<T> operator*(const quaternion<T>& b, double a);

template <typename T>
quaternion<T> operator*(float a, const quaternion<T>& b);

template <typename T>
quaternion<T> operator*(const quaternion<T>& b, float a);

void testQuaternionBasis();


#endif /* QUATERNION_HPP */
