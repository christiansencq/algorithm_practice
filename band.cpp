#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

//Find the length of the longest band in a substring
// Band is a subsequence that can be reordered to be contiguous.

//My implementation
int longest_band(std::vector<int> vec)
{
    int longest = 0;
    int count = 1;//Start at 1 to include 'i'
    std::sort(vec.begin(), vec.end());

    // std::cout << "vec ";
    // for (auto i : vec)
    // { std::cout << i << " "; }
    // std::cout << "\n";

    //Band finding starts
    for (int i = 0; i < vec.size()-1; i++)
    {
        if (abs(vec[i]-vec[i+1]) > 1)
        {
            count = 0;
        }
        else
        {
            count++;
            longest = std::max(count, longest);
        }
    }
    return longest;
}

//Implementation from example, not my code.
int largest_band(std::vector<int> arr)
{
    int largest = 0;
    int n = arr.size();
    std::unordered_set<int> set; 
    
    for (int x : arr)
    {
        set.insert(x);
    }

    for (auto element : set)
    {
        //For each value in the set, look for the left-adj value..
        int parent = element -1;
        
        //If parent does not exist, go forward: So set returns end() if it doesnt find?
        if (set.find(parent) == set.end())
        {
            //Find entire band/chain starting from element.
            int next_no = element + 1;
            int cnt = 1;
            while (set.find(next_no)!=set.end())
            {
                next_no++;
                cnt++;
            }
            largest = std::max(largest, cnt);
        }
    }
    return largest;
}

int main()
{
    std::vector<int> test1 = { 2, 4, 3, 1, 7, 6, 9, 5 }; //Believe this should be 4  (1,2,3,4)
    int lng = longest_band(test1);
    std::cout << "longest " << lng << "\n"; 
    int lrg = largest_band(test1);
    std::cout << "lrgest " << lrg << "\n";

    return 0;
}
