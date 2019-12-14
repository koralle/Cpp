#include <iostream>

int main(void){

    int a, b;
    std::cin >> a >> b;

    int result = a - 2 * b;

    if (result >= 0)
        std::cout << result << std::endl;
    else
        std::cout << 0 << std::endl;
    return 0;
}