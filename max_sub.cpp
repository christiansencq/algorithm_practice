#include <vector>
#include <string>
#include <iostream>

//Find the greatest value subarray within an array.
//
// 1. Could trim off negative numbers from edges, but this doesn't scale.
// 2. Perhaps find the highest value set of Positive numbers - then grow in each direction.  If it ends at a higher value after growing in one direction, go until it makes the highest.

//My algorithm
int max_subarray(std::vector<int> array)
{
    int sub_max = 0;
    std::vector<int> sub_array {array};

    //For each value, if it is the first positive number among consecutive positives, go forward and keep adding the rest of the list.
    for (int i = 0; i < array.size(); i++)
    {
        if ( array[i] < 0)
        {
            //Skip it, no sub_array will START with a negative value.
            continue;
        }
        else //We have a positive number.
        {
            bool next_i_found = false;
            //Reset the sum
            int sum_from_i = 0;
            //Count up until the end of the list.
            for (int j = i; j < array.size(); j++)
            {
                //Accumulate numbers to the end of the list.
                sum_from_i += array[j];
                //If all of the numbers from i to this point are a new maximum, recalculate.
                if (sum_from_i > sub_max)
                    sub_max = sum_from_i;
                
                if (array[j] < 0 && next_i_found == false)
                {
                    i = j;
                    next_i_found = true;
                }
                
            }
        }
    }

    return sub_max;
}

int main()
{
    std::vector<int> vec1 { -1, 2, 3, 4, -2, 6, -8, 3};
    int max1 = max_subarray(vec1);
    std::cout << "Max of vec1 " << max1 << "\n";
    return 0;
}
