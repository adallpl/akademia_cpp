#include <iostream>

template <typename T>
T max(T a, T b) { // zmieniamy z T na auto
    return a < b ? b : a;
}

// wskazniki
template<typename T>
T max(T*a, T* b){
    return *a < *b ? b : a;
}

// Overload
int max(int a, int b) {
    return 4;
}

// Specialization
// can also be max<>(..), or max<int>(..)
template <>
int max(int a, int b) { // specjalizacja dla typu int ( max<int> )
    return 17;
}

// Explicit instantiation
template double max(double, double);

// "Don't generate here, I promise it is elsewhere"
extern template float max(float, float);


// Non-type params
template <typename T, int N>
struct A {
    T f();
    void stuff() { }
};

template <typename T, int N>
T A<T, N>::f() { return T{}; }

// Specialization of a single method
template <>
void A<int, 5>::stuff() { std::cout << "A<int,5>::stuff()" << std::endl; }


// Full specialization
template <>
struct A<void, 0> {
    void g();
};

void A<void, 0>::g() { }

// Partial specialization
template <int N>
struct A<void, N> {
    void h();
};

template <int N>
void A<void, N>::h() { }


// Template methods
struct C {
    template <typename T> void f();
};

template <typename T>
void C::f() { };

// Specialization of template method
template <>
void C::f<int>() { };


// Template template methods
template <typename T>
struct D {
    template <typename U> void f();
};

template <typename T>
template <typename U>
void D<T>::f() { }

// interfejs wektora

template <typename T>
class Vector{
    T* buf;
public:
    Vector(int n): buf{new T[n]} { }
    T& operator[](int a) {return buf[a]; }

    const T& operator [](int a) const {return buf[a];}

    template<typename U>
    Vector(const Vector<U>& v) {
        //aloakcjabu
        for(int i = 0; i <v.size(); i ++)
        {
            buf[i] = v[i];
        }

    }

};
    void f(Vector<int>& v) {
        v[3];
    }

    void g(const Vector<int>& v) {
        v[3] = 9;
    }


int main() {
    max(1.3, 1.7); // max<double>
    max(2, 3);     // non-template max(int, int)
  //  max<>(2, 3);   // max<int> specialization
    std::cout << max(1, 1.2) << std::endl;
    std::cout << max<>(10, 6) << std::endl; // wymuszenei szabl specjaliz
    // max(1.2f, 5.0f); // linker error - max<float> not defined

    A<int, 5> a1;      // generic version
    int val = a1.f();
    a1.stuff();        // method specialization

    A<void, 3> a2;     // partial specialization
    a2.h();
    // a2.f();         // error - specialization doesn't have f()

    A<void, 0> a3;     // full specialization
    a3.g();
}
