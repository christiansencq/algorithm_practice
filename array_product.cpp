#include <vector>

/*  - Product Array -  
 *  Function that takes an array of ints and returns an equal-length array of ints.
 *  Each item in the output is the multiplication of all other numbers in the array.
 *  Do not use division.
 */

std::vector<int> sample1 = { 1, 2, 3, 4, 5 };
 //  ==  120, 60, 40, 30, 24
std::vector<int> sample2 = { 3, 2, 2, 4, 5 };


std::vector<int> productArray(std::vector<int> arr)
{
    int n = arr.size();
    std::vector<int> output (n, 1);

    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                product *= arr[j];
            }
        }
        output.push_back(product);
    }

    return output;
}

int main()
{

    return 0;
}
