#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <iostream>

// Given an array of N integers.  Find all sets of 3 distinct ints that can make a target sum.
// Brute Force
std::vector<std::array<int, 3>> triplet_find(std::vector<int> vec, int target_sum)
{
    std::vector<std::array<int, 3>> triplets;//Output
    std::sort(vec.begin(), vec.end());
    std::set<int> trip_set (vec.begin(), vec.end());

    //Cycle through each value.

    for (int i = 0; i < vec.size()-2; i++)
    {
        for (int j = i+1; j < vec.size()-1; j++)
        {
            int two_sum = vec[i] + vec[j];
            int looking_for = target_sum - two_sum;
            if (trip_set.count(looking_for))
            {
                for (int k = j+1; k < vec.size(); k++)
                {
                    if (two_sum + vec[k] == target_sum)
                    {
                        triplets.push_back({vec[i], vec[j], vec[k]});
                    }
                }
            }
        }
    }
    return triplets;
}
// Example's implementation
//Using a dual-pointer method to count down/up until value matches target_sum
std::vector<std::array<int, 3>> triplet_find_2(std::vector<int> vec, int target_sum)
{
    std::vector<std::array<int, 3>> triplets;//Output
    std::sort(vec.begin(), vec.end());

    int n = vec.size();

    //Cycle through each value and solve pair-sum for remaining items
    for (int i = 0; i <= n-3; i++)
    {
        int j = i + 1;//Start at the next value
        int k = n - 1;//Start at the last value
        
        //j moves forward, k moves backward. (if they meet, stop)
        while (j < k)
        {
            int current_sum = vec[i];
            current_sum += vec[j];
            current_sum += vec[k];

            if (current_sum == target_sum)
            {
                triplets.push_back({vec[i], vec[j], vec[k]});
                j++;
                k--;
            }
            else if (current_sum > target_sum)
            {
                k--;            
            }
            else
            {
                j++;
            }
        }
    }
    return triplets;
}

int main()
{
std::vector<int> vec1 = {10, 5, 2, 3, 6, 8, 11, 1, 4};
int sum1 = 15;
std::vector<std::array<int, 3>> out1 = triplet_find_2(vec1, sum1);
for (auto vector : out1)
{
    for (auto val : vector)
    {
        std::cout << val << "  ";
    }
    std::cout << "\n";
}

return 0;
}
