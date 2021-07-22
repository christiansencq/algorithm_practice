#include <vector>
#include <iostream>

//Rotate a vector left # of spaces.

//My implementation
std::vector<int> rotLeft(std::vector<int> a, int d)
{
    //Rotate the vector 'a' a 'd' # of positions.

    int size = a.size();
    std::vector<int> shift;
    for (int i = 0; i < size; i++)
    {
        shift.push_back(a[((d) + i)%size]);
    }
    return shift;
}

int main()
{

    std::vector<int> array = { 1, 2, 3, 4, 5 };
    int shift = 4;

    std::vector<int> shifted_array = rotLeft(array, shift);

    for (int i : shifted_array)
    {
        std::cout << i << std::endl;
    }
    return 0;
}
