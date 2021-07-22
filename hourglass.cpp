#include <numeric>
#include <algorithm>
#include <vector>
#include <iostream>


//Add up all the 'hourglass'es in a vector of vectors of ints.
//My implementation
int hourglassSum(std::vector<std::vector<int>> arr)
{
    std::vector<int> hourglass_sums; //stores the sum of the values in each square.
    
    for (int x = 0; x < arr.size()-2; x++)
    {
        for (int y = 0; y < arr[0].size()-2; y++)
        {
            std::vector<int> hourglass_values;
            
            hourglass_values.push_back(arr[x+0][y+0]);
            hourglass_values.push_back(arr[x+0][y+1]);
            hourglass_values.push_back(arr[x+0][y+2]);
            hourglass_values.push_back(arr[x+1][y+1]);
            hourglass_values.push_back(arr[x+2][y+0]);
            hourglass_values.push_back(arr[x+2][y+1]);
            hourglass_values.push_back(arr[x+2][y+2]);

            int sum = std::accumulate(hourglass_values.begin(), hourglass_values.end(), 0);
            hourglass_sums.push_back(sum);
        }
    }
    std::sort(hourglass_sums.begin(), hourglass_sums.end());

    int end = hourglass_sums.size();
    return hourglass_sums[end-1];
}

int main()
{
    std::vector<std::vector<int>> testCase1 = { 
                            { 1, 1, 1, 0, 0, 0 },
                            { 0, 1, 0, 0, 0, 0 },
                            { 1, 1, 1, 0, 0, 0 },
                            { 0, 0, 2, 4, 4, 0 },
                            { 0, 0, 0, 2, 0, 0 },
                            { 0, 0, 1, 2, 4, 0 } };

    int sum_val = hourglassSum(testCase1);

    std::cout << "Value : " << sum_val << std::endl;

    return 0;
}
