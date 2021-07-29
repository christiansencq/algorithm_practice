#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <cmath>

/*  -   Minimum Difference   - 
 *  Function is given 2 int arrays (n>=1)
 *  Find the pair with the closest values, with 
 *  each array providing 1 item in the pair.
 *
 */

std::pair <int, int> min_Difference(std::vector<int> va, std::vector<int> vb)
{
    std::pair <int, int> the_pair;
    //int largest_diff = 0;
    int smallest_diff = INT_MAX; 
    //Going to have to compare each item in each array to each other. - > n log n time? 
    for (int i = 0; i < va.size(); i++)
    {
        for (int j = 0; j < vb.size(); j++)
        {
            int diff = std::abs(va[i] - vb[j]);
            //largest_diff = diff > largest_diff ? diff : largest_diff;
            if ( diff < smallest_diff)
            {
                smallest_diff = diff;
                the_pair.first = va[i];
                the_pair.second = vb[j];
            }
            else
            {
                continue;
            }
        }
    }

    return the_pair;
}

int main()
{
    return 0;
}

