#include <iostream>
#include <particleLife/core/temp.hpp>

float addition(float a, float b) {
    std::cout << "Addition from core\n";
    return a + b;
}

int branchedFunction(int val) {
    if (val == 1) {
        std::cout << "val: " << val << std::endl;
        return 1;
    }
    else if (val == 2) {
        std::cout << "val: " << val << std::endl;
        return 2;
    }
    else if (val == 3) {
        std::cout << "val: " << val << std::endl;
        return 3;
    }
    else {
        std::cout << "val: " << val << std::endl;
        return val;
    }
}
