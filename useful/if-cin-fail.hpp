#include <iostream>

int EnterInt() {  
    int x;  
    while (true) {  
        std::cin >> x;  
        if (std::cin.fail()) {
            std::cin.clear();  
            std::cin.ignore(999999, '\n');  
        } else break;  
    }  
    return x;  
}
