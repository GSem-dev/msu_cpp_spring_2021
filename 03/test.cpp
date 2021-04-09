#include "Matrix.h"
#include <cassert>

void InitTest() {
    const size_t rows = 2;
    const size_t cols = 2;

    Matrix m(cols,rows);

    assert(m.getRows() == 2);
    assert(m.getColumns() == 2);

    m[1][2] = 10;
    double x = m[1][2];
    assert(x == 10);
}

void FillTest() {
    const size_t rows = 4;
    const size_t cols = 2;
    Matrix m(cols,rows);
    Matrix tmp_m(cols, rows);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            m[i][j] = 5;
           
        }
    }
    std::cout<<m<<std::endl;
    tmp_m = m;
    assert(tmp_m==m);
    m *= 10;
    assert(m[0][1] == 50);
    assert(tmp_m != m);
}

void ShowTest() {
    const size_t rows = 9;
    const size_t cols = 7;
    Matrix m(cols, rows);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            m[i][j] = 8;
        }
    }
    std::cout<<m<<std::endl;
}

void ExceptionTest() {
    const size_t rows = 4;
    const size_t cols = 7;
    Matrix m(cols, rows);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            m[i][j] = 2;
        }
    }
    m[2][8] = 11; // должны выскочить ошибка

}

int main() {
    InitTest();
    FillTest();
    ShowTest();
    ExceptionTest();
    return 0;
}
