#include "Matrix.h"
#include <cassert>

void GetRowColTest() {
    const size_t rows = 2;
    const size_t cols = 3;
    Matrix m(rows,cols);
    assert(m.getRows() == 2);
    assert(m.getColumns() == 3);
    m[1][1] = 10;
    int32_t x = m[1][1];
    assert(x == 10);
}

void GetElTest() {
    const size_t rows = 4;
    const size_t cols = 2;
    Matrix m(rows, cols);
    Matrix tmp_m(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m[i][j] = 5;           
        }
    }
    tmp_m = m;
    assert(tmp_m==m);
    m *= 10;
    assert(m[3][1] == 50);
    assert(tmp_m != m);
}

void MulTest()
{
    const size_t rows = 5;
    const size_t cols = 5;
    Matrix m(rows, cols);
    Matrix m1(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m[i][j] = 3;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m1[i][j] = 6;
        }
    }
    m *= 2;
    assert(m == m1);
}

void ShowTest() {
    const size_t rows = 9;
    const size_t cols = 7;
    Matrix m(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m[i][j] = 8;
        }
    }
    assert(m[8][6] == 8);
    std::cout<<m<<std::endl;
}

void PlusTest() {
    const size_t rows = 5;
    const size_t cols = 5;
    Matrix m(rows, cols);
    Matrix m1(rows, cols);
    Matrix m2(rows, cols);
    Matrix m3(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m[i][j] = 2;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m1[i][j] = 3;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m2[i][j] = 5;
        }
    }
    m3 = m1 + m;
    assert(m2 == m3);
}
void EqualTest()
{
    const size_t rows = 5;
    const size_t cols = 5;
    Matrix m(rows, cols);
    Matrix m1(rows, cols);
    Matrix m2(rows, cols);
    Matrix m3(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m[i][j] = 2;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m1[i][j] = 3;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m2[i][j] = 5;
        }
    }
    m3 = m1 + m;
    assert(m2 == m3);
    assert(m != m2);
    m3 = m2 = m;
    assert(m3 == m);
}

void OnexOneTest()
{
    const size_t rows = 1;
    const size_t cols = 1;
    Matrix m(rows, cols);
    
    m[0][0] = 5;
    assert( m[0][0] == 5);
}

void ExceptionTest() {
    const size_t rows = 4;
    const size_t cols = 7;
    Matrix m(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m[i][j] = (i+1)*10 + j+1;
        }
    }
    try
    {
        m[10][1] = 11; // должны выскочить ошибка
    } catch (const std::out_of_range& e)
    {
        std::cout<<"Out from range!"<<std::endl;
    } 
}

int main() {
    GetRowColTest();
    GetElTest();
    MulTest();
    ShowTest();
    PlusTest();
    EqualTest();
    OnexOneTest();
    std::cout<<"success!"<<std::endl;
    ExceptionTest();
    return 0;
}
