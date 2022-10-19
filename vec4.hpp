#ifndef VEC4_HPP
#define VEC4_HPP

#include <iostream>

namespace vec4 {
    template <typename T>
    struct vec4 {
        T V[4];
    };

    typedef vec4<double> dmat4;
    typedef vec4<float> fmat4;

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const vec4<T>& a) {
        for (auto i : a) {
            std::cout << i << ' ';
        }
    }

    
}

#endif