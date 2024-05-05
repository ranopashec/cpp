#include <iostream>
#include "Matrix.h"
#include <bits/stdc++.h>
using namespace std;


int main() {
    std::vector<std::vector<int>> v1{
            {1, 2, 3},
            {4, 5, 6},
            {7, 0, 9}
    };
    Matrix<3, 3, Rational> m1{v1};
    std::cout << "m1 from vector<int>:\n" << m1 << '\n';

    SquareMatrix<3> m2;
    std::cout << "SquareMatirx<3> m2:\n" << m2 << '\n';

    m2 = m1;
    std::cout << "m2 = m1:\n" << m2 << '\n';

    m1 += m2;
    std::cout << "m1 += m2:\n" << m1 << '\n';

    m1 *= Rational(1, 2);
    std::cout << "m1 *= 1/2:\n" << m1 << '\n';

    m1[2][1] = 10;
    std::cout << "m1[2][1] = 10:\n" << m1 << '\n';

    std::cout << "m1.det():\n" << m1.det() << "\n\n";

    std::cout << "m1.inverted():\n" << m1.inverted() << '\n';

    std::cout << "m1.trace():\n" << m1.trace() << "\n\n";

    std::cout << "m1.rank():\n" << m1.rank() << "\n\n";


    std::cout << "m1.getColumn(1):\n";
    for (auto e : m1.getColumn(1)){
        std::cout << e << ' ';
    }
    std::cout << "\n\nm1.getRow(1):\n";
    for (auto e : m1.getRow(1)){
        std::cout << e << ' ';
    }

    return 0;
}
