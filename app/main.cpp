#include <iostream>
#include <particleLife/core/temp.hpp>
#include <particleLife/render/temp1.hpp>
#include <particleLife/ui/temp2.hpp>

int main() {
    std::cout << "Main file\n";
    std::cout << addition(3, 5) << std::endl;
    std::cout << sub(3, 5) << std::endl;
    std::cout << prod(3, 5) << std::endl;
    std::cout << branchedFunction(2) << std::endl;
    std::cout << branchedFunction(3) << std::endl;
    std::cout << branchedFunction(4) << std::endl;

    return 0;
}

