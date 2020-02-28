#include <iostream>
#include <Vector.h>
#include <Matrix.h>


template <typename T>
void print(const Vector<T> &temp);




template <typename T>
void print(const Vector<T> &temp) {
    std::cout << "{";
    for (size_t i = 0; i < temp.size(); i++) {
        if (i != 0) std::cout << ", ";
        std::cout << temp[i];
    }
    std::cout << "}" << std::endl;
}


int main() {

    std::cout << "Hello" << std::endl;


    double * arr = new double[4];
    for (size_t i = 0; i < 4; i++) {
        arr[i] = i;
    }

    Vector<double> vec(arr, 4);




//    Vector<double> v2( new Vector<double>(1,3));


    return 0;
}

