#include <iostream>
#include "KDeque.h"
int main(){
    KDeque dq;
    std::cout << "dq empty deque: " << dq << '\n';
    std::cout << "dq empty deque size: " << dq.Size() << '\n';
    dq.Push_Back(1);
    dq.Push_Back(3);
    dq.Push_Back(4);
    std::cout << "dq push back 1, 3, 4: " << dq << '\n';
    dq.Push_Front(1);
    dq.Push_Front(3);
    dq.Push_Front(4);
    std::cout << "dq push front 1, 3, 4: " << dq << '\n';
    dq.Pop_Back();
    std::cout << "dq pop back: " << dq << '\n';
    dq.Pop_Front();
    std::cout << "dq pop front: " << dq << '\n';
    KDeque dq1 {dq};
    std::cout << "copy constructor dq1: " << dq1 << '\n';
    KDeque dq2 {{1, 2, 3, 4}};
    std::cout << "initializer list dq2: " << dq2 << '\n';
    std::cout << "copy assigment dq = dq2: " << (dq = dq2) << '\n';
    dq2 = KDeque(4, 0);
    std::cout << "repeat number constructor (4, 0) dq2: " << dq2 << '\n';
    std::cout << "front dq: " << dq.Front() << '\n';
    std::cout << "back dq: " << dq.Back() << '\n';
    std::cout << "size dq: " << dq.Size() << '\n';
    std::cout << "find 3 dq2: " << RangesFind(dq2, 3) << '\n';
    std::cout << "find 0 dq2: " << RangesFind(dq2, 0) << '\n';
}


