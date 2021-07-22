#include <vector>
#include <iostream>
#include <algorithm>

/* Given a vector of ints, determine how much rain would be collected
 * If rain collects in each 'valley' in the vector.  (i.e. space between high values/mountains)
 *
 */

//My implementation
int rains(std::vector<int> elevation_map)
{
    int water = 0;

    std::vector<int> left_peak;
    std::vector<int> right_peak;

    int current_max = 0;
    
    for (int i = 0; i < elevation_map.size(); i++)
    {
        if (elevation_map[i] > current_max)
        {
            current_max = elevation_map[i];
        }
        left_peak.push_back(current_max);
    }
    
    current_max = 0;

    for (int i = elevation_map.size()-1; i >= 0; i--)
    {
        if (elevation_map[i] > current_max)
        {
            current_max = elevation_map[i];
        }
        right_peak.push_back(current_max);
    }
    std::reverse(right_peak.begin(), right_peak.end());
    
    std::vector<int> min_peaks;
    for (int i = 0; i < elevation_map.size(); i++)
    {
        min_peaks.push_back(std::min(left_peak[i], right_peak[i]));
    }
    
    for (int i = 0; i < elevation_map.size(); i++)
    {
        int column_water = 0;
        water += (min_peaks[i] - elevation_map[i]);
    }

    
    std::cout << "Right Peak" << std::endl;
    for (auto val : right_peak)
    {
        std::cout << val << " \n";
    }

    std::cout << "Left Peak" << std::endl;
    for (auto val : left_peak)
    {
        std::cout << val << " \n";
    }

    return water;
}

int trappedWater(std::vector<int> heights)
{
    int n = heights.size();
    if (n <= 2)
    {
        //A tiny vector with only two elements cant hold any water.:
        return 0;
    }

    std::vector<int> left{n}, right{n};
    //Initialize these values because we are going to need to reference a prior value
    // The for loop only starts at the second element, because we are just assigning values for the first element, which is the basis for the for loop..
    left[0] = heights[0];
    right[n-1] = heights[n-1];

    for( int i = 1; i < n; i++)
    {
        left[i] = std::max(left[i-1], heights[i]);//Set the value to the tallest we have found so far (which will be the previous value or the height at this position, whichever is higher).
        right[n-i-1] = std::max(right[n-i], heights[n-i-1]);// Same.
    }

    int water = 0;
    for (int i = 0; i < n; i++)
    {
        water += (std::min(left[i], right[i]) - heights[i]);
    }
    return water;
}

int main()
{
    int water_amt = 0;
    std::vector<int> map = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

    int output = trappedWater(map);
    std::cout << "Out put " << output << std::endl;

    return 0;
}


























