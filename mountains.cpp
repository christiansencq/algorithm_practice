#include <vector>
#include <iostream>

//Takes array of distinct integers, returns length of highest 'mountain'
// Mountain is a series of at least 3 numbers that increase to a peak, then decrease
// A mountain is guaranteed.  Count the decreasing numbers for the length.

//This is my implementation.
int high_mountain(std::vector<int> vec)
{
    int highest_mountain = 0;
    int current_mountain = 1;

    bool was_ascending = vec[0] < vec[1];
    bool reset = false;

    //Keep a 'current' mountain, which is set when we find increasing adjacent numbers. 
    
    for (int i = 0; i < vec.size() - 1; i++)
    {
        //Track our mountain.
        int j = i + 1;
        if ((vec[i] < vec[j]) && (was_ascending == true)) //: we are continuing up.
        {
            was_ascending = true;
        }
        else if ((vec[i] < vec[j]) && (was_ascending == false))
        {
            //Restart the mountain count.
            reset = true;
            was_ascending = true;
        }
        else 
        {
            was_ascending = false;
        }

        current_mountain ++;
        highest_mountain = (current_mountain > highest_mountain) ? current_mountain : highest_mountain;

        if (reset == true)
        {
            current_mountain = 1;
            reset = false;
        }
    }
    return highest_mountain;
}

//This is based on an example from Udemy.
int peak_find_mountain(std::vector<int> vec)
{
    int highest_mountain = 0;
    int n = vec.size();

    //First and last positions cannot be peak.
    for (int i = 1; i < n-1;)
    {
        //check if vec[i] is peak
        if(vec[i]>vec[i-1] && vec[i]>vec[i+1])
        {
            int cnt = 1;
            int j = 1;

            //Count backwards
            while (j>=1 && vec[j]>vec[j-1])
            {
                j--;
                cnt++;
            }
            //Count forwards
            while (i < n-1 && vec[i]>vec[i+1])
            {
                i++;
                cnt++;
            }
            highest_mountain=std::max(cnt, highest_mountain);
        }
        else
        {
            i++;
        }
    }


    return highest_mountain;
}


int main()
{
    std::vector<int> mountain_vec { 5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4 };
    int mtn = peak_find_mountain(mountain_vec);
    std::cout << "highest " << mtn << "\n";
    
    return 0;
}
