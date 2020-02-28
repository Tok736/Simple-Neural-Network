#ifndef NEURAL_MATRIX_H
#define NEURAL_MATRIX_H



template <typename T>
class Matrix {
private:
    T ** buffer = nullptr;
    size_t _rows = 0;
    size_t _cols = 0;
    void selfDelete() {
        if (buffer == nullptr) return;
        for (size_t i = 0; i < _rows; i++) {
            delete[] buffer[i];
        }
        delete[] buffer;
    }
public:
    Matrix(size_t _rows, size_t _cols, const T& filler): _rows(_rows), _cols(_cols) {
        buffer = new T*[_rows];
        for (size_t i = 0; i < _rows; i++) {
            buffer[i] = new T[_cols];
            for (size_t j = 0; j < _cols; j++) {
                buffer[i][j] = filler;
            }
        }
    }
    Matrix(size_t _rows, size_t _cols, const T **const temp): _rows(_rows), _cols(_cols) {
        buffer = new T*[_rows];
        for (size_t i = 0; i < _rows; i++) {
            buffer[i] = new T[_cols];
            for (size_t j = 0; j < _cols; j++) {
                buffer[i][j] = temp[i][j];
            }
        }
    }
    ~Matrix() {
        selfDelete();
    }
    const T*const operator[](const int i) const {
        return buffer[i];
    }
    T* operator[](const int i) {
        return buffer[i];
    }

};

#endif //NEURAL_MATRIX_H
