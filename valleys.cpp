#include <string>
#include <iostream>

//Count the number of valleys in a string solely composed of 'D' and 'U' characters.
//My implementation
int countingValleys(int steps, std::string path)
{
    int elevation_tracking = 0; //Start and end at Sea Level.
    int valley_tracker = 0;
    for (auto c : path)
    {
        if (c == 'D')
        {
            elevation_tracking -= 1;
        }
        else if (c == 'U')
        {
            elevation_tracking += 1;
            if (elevation_tracking == 0)
            {
                std::cout << "Leaving a valley" << std::endl;
                valley_tracker += 1;
            }
        }
    }
    return valley_tracker;
}

int main()
{

}
