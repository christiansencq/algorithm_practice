#include <vector>
#include <string>
#include <iostream>

//My implementation of standard fizzbuzz algorithm.
std::vector<std::string> fizzbuzz(int n){
    std::vector<std::string> fizz;

    for (int i = 0; i < n; i++)
    {
        if (((i % 5) == 0) && ((i % 3) == 0))
        {
            fizz.push_back("FizzBuzz");
        }
        else if ((i % 5) == 0)
        {
            fizz.push_back("Buzz");
        }
        else if ((i % 3) == 0)
        {
            fizz.push_back("Fizz");
        }
        else
        {
            fizz.push_back(std::to_string(i));
        }
    }
    return fizz;
}

int main()
{
    int num = 16;

    std::vector<std::string> fbstr = fizzbuzz(num);

    for (int i = 0; i < fbstr.size(); i++)
    {
        std::cout << fbstr[i] << " , ";
    }
    std::cout << "\n";

    return 0;
}


