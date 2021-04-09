#include "Matrix.h"
#include <cassert>

void test1() {
    const size_t rows = 5;
    const size_t cols = 3;

    Matrix m(cols,rows);

    assert(m.getRows() == 5);
    assert(m.getColumns() == 3);

    m[1][2] = 10;
    double x = m[1][2];
    assert(x == 10);
}
void test2() {
    const size_t rows = 5;
    const size_t cols = 3;
    Matrix m1(cols,rows);
    Matrix m(cols, rows);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            m1[i][j] = i+j;
           
        }
    }
    m = m1;
    assert(m1 == m);
    m *= 3;
    assert(m[0][1] == 3);

}
void test3() {
    const size_t rows = 5;
    const size_t cols = 3;
    Matrix m1(cols, rows);
    Matrix m(cols, rows);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            m1[i][j] = i + j+1;
        }
    }
    m = m1;
    m *= 5;
    std::cout<<"m1 == m:"<< (m1 == m)<<std::endl;
    std::cout << "m1 != m:" << (m1 != m) << std::endl;
    
    //std::cout <<"for test 3:"<<std::endl<<m;

}

int main() {
    test1();
    test2();
    test3();
    return 0;
}
