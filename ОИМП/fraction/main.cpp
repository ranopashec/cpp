#include "Fraction.h"
#include <iostream>
#include <string>

// Разработать пользовательский тип (класс) "ОБЫКНОВЕННЫЕ ДРОБИ".
// Дробь хранить в "канонической форме":
// если n – числитель, а d – знаменатель, то знак хранится в числителе
// (знаменатель всегда больше 0)
// n и d – взаимно простые.



// Для демонстрации возможностей класса написать головную программу, в которой
// продемонстрировать работу с этим классом. Меню делать не надо. В комментариях
// указать, что тестируете.



int main() {

    try {
        std::string tmp;

        std::cout << "default constructor test:\n";
        Fraction f;
        std::cout << "success!\n\n\n\n";

        std::cout << "operator<< test:\n";
        std::cout << "f: " << f << '\n';
        std::cout << "success!\n\n\n\n";


        std::cout << "operator>> test:\n";
        std::cout << "Enter f (n/d):\n";
        std::cin >> f;
        std::cout << "f: " << f << '\n';
        std::cout << "success!\n\n\n\n";

        std::cout << "constructor (long long n, long long d) test:\n";
        long long n, d;
        std::cout << "Enter n, d\n";
        std::cin >> n >> d;
        Fraction f1 (n, d);
        std::cout << "f1: " << f1 << '\n';
        std::cout << "success!\n\n\n\n";

        std::getline(std::cin, tmp);

        std::cout << "arithmetics operators test:\n";
        std::cout << "f + f1 = " << f + f1 << '\n';
        std::cout << "f - f1 = " << f - f1 << '\n';
        std::cout << "f * f1 = " << f * f1 << '\n';
        std::cout << "f / f1 = " << f / f1 << '\n';
        std::cout << "success!\n\n\n\n";

        std::cout << "arithmetics assigment and assigment(copy) operators test:\n";
        Fraction tmpf;
        tmpf = f;
        std::cout << "{\n    Fraction tmpf;\n    tmpf = f;\n}\n";
        std::cout << "tmpf = " << tmpf << '\n';
        std::cout << "f += f1 = " << (f += f1) << '\n';
        f = tmpf;
        std::cout << "f -= f1 = " << (f -= f1) << '\n';
        f = tmpf;
        std::cout << "f *= f1 = " << (f *= f1) << '\n';
        f = tmpf;
        std::cout << "f /= f1 = " << (f /= f1) << '\n';
        f = tmpf;
        std::cout << "success!\n\n\n\n";

        std::cout << "comparation operators test:\n";
        std::cout << std::boolalpha;
        std::cout << f << " < " << f1 << ": " << (f < f1) << '\n';
        std::cout << f << " > " << f1 << ": " << (f > f1) << '\n';
        std::cout << f << " <= " << f1 << ": " << (f <= f1) << '\n';
        std::cout << f << " >= " << f1 << ": " << (f >= f1) << '\n';
        std::cout << f << " == " << f1 << ": " << (f == f1) << '\n';
        std::cout << f << " != " << f1 << ": " << (f != f1) << '\n';
        std::cout << "success!\n\n\n\n";

        std::cout << "operator != test:\n";
        std::cout << "f: " << f << '\n';
        std::cout << "!f: " << !f << '\n';
        !f;
        std::cout << "success!\n\n\n\n";

        std::cout << "operator ++/-- test:\n";
        std::cout << "++f = " << ++f << '\n';
        std::cout << "--f = " << --f << '\n';
        std::cout << "f++ = " << f++ << '\n';
        std::cout << "f = " << f << '\n';
        std::cout << "f-- = " << f-- << '\n';
        std::cout << "f = " << f << '\n';
        std::cout << "success!\n\n\n\n";


    }

    catch (MyException &ex) {
        std::cerr <<"ERROR"<< '\n' << ex.what() << '\n';
    }

    return 0;
}
