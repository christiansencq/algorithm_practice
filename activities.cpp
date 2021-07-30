#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

/*   - Activity - 
 *  Given an array of int pairs which indicate the start and stop times of activities.
 *  Determine the maximum number of activities you can participate in without overlap.
 *  Times are guaranteed to be sensical (i.e. second comes after first)
 */

bool first_comp(std::pair<int, int> i, std::pair<int, int> j) { return i.first < j.first; }
bool second_comp(std::pair<int, int> i, std::pair<int, int> j) { return i.second < j.second; }

//My algorithm
int countActivities(std::vector<std::pair<int, int>> activities)
{
    int count = 0;
    // Heuristics:  
    //    If a pair can contain another pair, the bigger pair can not be eligible for inclusion
    //    Sorting by the first value will give us a basic schedule, where we can trim ineligible activities.
    //Find the next END-POINT among all of the rest of the items. If we always look for this, then test if the start point is possible, we should be OK.
    std::sort(activities.begin(), activities.end(), second_comp);

    for (int i = 0; i < activities.size(); i++)
    {
        std::cout << i << " :  ( " << activities[i].first << ", " << activities[i].second << " )\n"; 
    }

    int max_end_time = activities.end()->second;
    int prev_end_time = 0;
    
    //We are starting from the SECOND value in the first element - set to current_time.
    // THen look for the item where the FIRST element is >= 
    for (int i = 0; i < activities.size(); i++)
    //while (last_end_time < end_time)
    {
        if (activities[i].first >= prev_end_time)
        {
            prev_end_time = activities[i].second;
            std::cout << "Prev end time for " << i << " is " << prev_end_time << "\n";
            count++;
        }
        //Among the items with a start time >= last_end_time, find the one with the LOWEST end time
    }

    return count;
}

int main()
{
    std::vector<std::pair<int, int> > vec1 = { {7, 9}, {0, 10}, {4, 5}, {8, 9}, {4, 10}, {5, 7}, {5, 6}, {0, 2} };
    
    int out1 = countActivities(vec1);
    std::cout << "vec1 output " << out1 << "\n";
}
