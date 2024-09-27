#include <iostream>

int main(){
    int w;
    std::cin >> w;
    if (w % 2 == 1 || w == 2) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }
}
