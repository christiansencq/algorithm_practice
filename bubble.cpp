#include <string>
#include <iostream>
#include <vector>

//Simple bubble sort algorithm 
int main()
{
    std::vector<int> num_array = { 3, 5, 2, 9, 62, 54, 51, 77 };

    int numSwaps = 0;
    int firstElement = 0;
    int lastElement = 0;

    for (size_t i = 0; i < num_array.size(); i++)
    {
        for (size_t j = 0; j < num_array.size()-1; j ++)
        {
            if (num_array[j] > num_array[j+1])
            {
                std::swap(num_array[j], num_array[j+1]);
                numSwaps++;
            }
        }
    }

    firstElement = num_array[0];
    lastElement = num_array[num_array.size()-1];

    std::cout << "Array is sorted in " << numSwaps << " swaps." << std::endl;
    std::cout << "First Element: " << firstElement << std::endl;
    std::cout << "Last Element: " << lastElement << std::endl;

    for (auto elem : num_array)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
