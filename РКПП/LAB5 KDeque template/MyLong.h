#ifndef RGR3_MYLONG_H
#define RGR3_1MYLONG_H
#include <iostream>

class MyLong{
private:
    long _x;
public:
    MyLong() : _x(0){}
    MyLong(long x) : _x(x){}

    MyLong& operator= (const MyLong& oth)= default;
    bool operator==(const MyLong& oth) const{
        return oth._x == _x;
    }

    friend std::ostream& operator<<(std::ostream& out, const MyLong& a){
        out << a._x;
        return out;
    }

};

#endif //RGR3_MYLONG_H
