#include <vector>
#include <iostream>

/* Given a vector of bool ints (0, 1), determine how many steps it takes to get from begin to end
 * Rules are that : Each step can jump over a max of 2 steps and you can only end a step on a 0.
 */
//My implementation of algorithm
int jumpingOnClouds(std::vector<int> c)
{
    int jump_count = 0;

    for (int i = 0; i != c.size()-1; i++)
    {
        if(c.size() > 2 && c[i+2] != 1)
        {
            i++;
        }
        else if (c[i+1] == 1)
        {
            i++;
        }
        jump_count++;
    }

    return jump_count;
}

int main()
{
    std::vector<int> vec = { 0, 1, 0, 0, 0, 1, 0};

    int count = jumpingOnClouds(vec);

    std::cout << "Jump Count " << count << std::endl;

    return 0;
}
