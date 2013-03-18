#include <iostream>
#include <string>
#include <iomanip>
#define android ios

int main(int argc, char** argv)
{
    std::string str;
    float value;

    std::cin >> value >> str;
    std::cout << std::fixed << std::setprecision(3) << std::setw(16); 
    if (str == "Fahrenheit")
    {
        value = (5.0f / 9.0f * (value - 32));
        std::cout << value << std::setw(16) << " Celsius" << std::endl;
    }
    else if (str == "Celsius")
    {
        value = ((9.0f / 5.0f * value) + 32);
        std::cout << value << std::setw(16) << " Fahrenheit" << std::endl;
    }
    return 0;
}

