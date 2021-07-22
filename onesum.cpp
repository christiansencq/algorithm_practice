#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <iostream>

//Find the two values in a vector of ints that equal the sum.

//Brute Force:
std::array<int, 2> addend_find(std::vector<int> vec, int sum)
{
    std::array<int, 2> addends;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            if (((vec[i] + vec[j]) == sum) && (i != j))
            {
                addends[0] = (vec[i]); 
                addends[1] = (vec[j]);
                return addends;
            }
        }
    }
    return addends;
}

//Could SORT, then can discontinue search if we have passed the value.
std::array<int, 2> addend_sort(std::vector<int> vec, int sum)
{
    std::array<int, 2> addends;
    std::vector<int> sort_vec = vec; 
    std::sort(sort_vec.begin(), sort_vec.end());

    for (int i = 0; i < sort_vec.size(); i++)
    {
        for (int j = 0; j < sort_vec.size(); j++)
        {
            if (((sort_vec[i] + sort_vec[j]) == sum) && (i != j))
            {
                addends[0] = (sort_vec[i]); 
                addends[1] = (sort_vec[j]);
                return addends;
            }
            else if ( (sort_vec[i] + sort_vec[j] > sum) )
            {
                break;
            }
        }
    }
}

// Add everything to set and look up the value.
std::array<int, 2> addend_sort_w_set(std::vector<int> vec, int sum)
{
    std::array<int, 2> addends;
    // std::vector<int> sort_vec = vec; 
    // std::sort(sort_vec.begin(), sort_vec.end());

    std::set<int> set2;
    for (int i = 0; i < vec.size(); i++)
    {
        int val_looking_for = sum - vec[i];
        if (set2.count(val_looking_for))
        {
            addends[0] = vec[i];
            addends[1] = val_looking_for;
        }
        else
        {
            set2.insert(vec[i]);
        }
    //     if (vec_set.count(val_looking_for))
    //     {
    //         addends[0] = sort_vec[i];
    //         addends[1] = val_looking_for;
    //     }
    }
    return addends;
}

int main()
{
std::vector<int> vec1 = {10, 5, 2, 3, -6, 9, 11};
int sum1 = 7;
std::array<int, 2> out1 = addend_sort_w_set(vec1, sum1);
std::cout << "Out1 " << out1[0] << " & " << out1[1] << std::endl;

return 0;
}
