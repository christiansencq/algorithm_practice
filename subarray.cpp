#include <iostream>
#include <vector>
#include <algorithm>

/* Given an array of at least size two
 * find the smallest subarray that needs to be sorted in place
 * so that the entire input array is sorted.
 * If the input array is already sorted, the function should retrn [-1, -1]
 * Else, it should return the start and end index of the subarray.
 */

//My implementation
std::vector<int> sub_find(std::vector<int> arr)
{
    std::vector<int> sub_pos_arr;
    int sub_hi = *std::max(arr.begin(), arr.end());
    int sub_lo = 0;
    //Set the initial positions for the left/right most indicators to their opposite sides.
    int left_most = arr.size();
    int right_most = 0;
    
    for (int i = 0; i < arr.size()-1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            if (i < left_most) //If this is further left than our previous left, move that indicator
            {
                left_most = i; //Left-most position
            }
            if (i+1 > right_most)
            {
                right_most = i+1;
            }
            //Now, what about elements that previously were considered to be 'in order', but must be considered as possible need of incorporation into sub-array.
            sub_hi = arr[i]; 
            sub_lo = arr[i+1];
            //Iterate backwards from i, check for a lower value than our current one.
            for (int j = right_most; j >= 0; j--)
            {
                if (arr[j] < sub_lo)
                    break;
                left_most = j;
            }
            //Iterate forwards and check for a higher value than our current one.
            //Could check from the 'rightmost', rather than i+1?
            for (int k = i+1; k < arr.size(); k++)
            {
                if (arr[k] > sub_hi)
                    break;
                right_most = k;
            }

            //Set i to the right most value now, will be at least equal to i+1. Test if this is gets incremented afterward (the i++ above.)
            i = right_most;
        }
    }
    sub_pos_arr.push_back(left_most);
    sub_pos_arr.push_back(right_most);
    return sub_pos_arr;
}

int main()
{
    std::vector<int> test1 = { 1, 5, 6, 12, 7, 8, 13, 14, 15, 16 };
    std::vector<int> sub_pos1 = sub_find(test1);
    std::cout << "Test 1 Subpos " << sub_pos1[0] << "  " << sub_pos1[1] << std::endl;
    //Could assert that [3, 5] (values 12, 7, 8)

    std::vector<int> test2 = { 1, 2, 4, 7, 8, 13, 10, 11, 16 };
    std::vector<int> sub_pos2 = sub_find(test2);
    std::cout << "Test 2 Subpos " << sub_pos2[0] << "  " << sub_pos2[1] << std::endl;
    // Answer [5, 7] (values, 13, 10, 11)

    std::vector<int> test3 = { 1, 5, 8, 2, 13, 14, 15, 16 };
    std::vector<int> sub_pos3 = sub_find(test3);
    std::cout << "Test 3 Subpos " << sub_pos3[0] << "  " << sub_pos3[1] << std::endl;
    // Answer [1, 3]  values 5, 8, 2

    std::vector<int> test4 = { 21, 5, 8, 2, 13, 14, 15, 16 };
    std::vector<int> sub_pos4 = sub_find(test4);
    std::cout << "Test 4 Subpos " << sub_pos4[0] << "  " << sub_pos4[1] << std::endl;
    // Answer [0, 7]  values 5, 8, 2

    std::vector<int> test5 = { 1, 5, 8, 12, 13, 14, 15, 16, 11 };
    std::vector<int> sub_pos5 = sub_find(test5);
    std::cout << "Test 5 Subpos " << sub_pos5[0] << "  " << sub_pos5[1] << std::endl;
    // Answer [1, 3]  values 5, 8, 2
    return 0;
}
