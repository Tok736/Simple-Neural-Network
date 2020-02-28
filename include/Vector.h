#ifndef NEURAL_VECTOR_H
#define NEURAL_VECTOR_H


template <typename T>
class Vector {
private:
    T * buffer = nullptr;
    size_t _size = 0;
    void clear();
public:
    Vector(size_t _size, const T& filler);
    Vector(const T *const arr, int _size);
    Vector(const Vector<T>& other);
    Vector<T>& operator=(const Vector<T>& other);
    Vector(Vector<T>&& other);
    Vector<T>& operator=(Vector<T>&& other);
    ~Vector();
    void set(const Vector<T>& other);

    size_t size() const;
    T& operator[](const int i);
    const T& operator[](const int i) const;

};

template <typename T>
void Vector<T>::clear() {
    _size = 0;
    if (buffer != nullptr) delete[] buffer;;
}
template <typename T>
Vector<T>::Vector(size_t _size, const T& filler): _size(_size) {
    buffer = new T[_size];
    for (size_t i = 0; i < _size; i++) {
        buffer[i] = filler;
    }
}
template <typename T>
Vector<T>::Vector(const T *const arr, int _size): _size(_size) {
    buffer = new T[_size];
    for (size_t i = 0; i < _size; i++) {
        buffer[i] = arr[i];
    }
}
template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
    set(other);
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    set(other);
    return *this;
}
template <typename T>
Vector<T>::Vector(Vector<T>&& other) {
    _size = other._size;
    buffer = other.buffer;
    other.buffer = nullptr;
    other._size = 0;
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) {
    clear();
    _size = other._size;
    buffer = other.buffer;
    other.buffer = nullptr;
    other._size = 0;
    return *this;
}
template <typename T>
Vector<T>::~Vector() {
    clear();
}
template <typename T>
void Vector<T>::set(const Vector<T>& other) {
    clear();
    _size = other._size;
    buffer = new T[_size];
    for (size_t i = 0; i < _size; i++) {
        buffer[i] = other.buffer[i];
    }
}

template <typename T>
size_t Vector<T>::size() const {
    return _size;
}
template <typename T>
T& Vector<T>::operator[](const int i) {
    return buffer[i];
}
template <typename T>
const T& Vector<T>::Vector::operator[](const int i) const {
    return buffer[i];
}

template <typename T>
Vector<T> operator*(const Vector<T>& left, const T& c) {
    Vector<T> temp = left;
    for (size_t i = 0; i < left.size(); i++) {
        temp[i] = temp[i] * c;
    }
    return std::move(temp);
}

template <typename T>
Vector<T> operator*(const T& c, const Vector<T>& left) {
    Vector<T> temp = left;
    for (size_t i = 0; i < left.size(); i++) {
        temp[i] = c * temp[i];
    }
    return std::move(temp);
}

#endif //NEURAL_VECTOR_H
