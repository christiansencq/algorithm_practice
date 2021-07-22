#include <string>
#include <vector>
#include <iostream>

/* This is a simple algorithm to take an input of characters and
 * returning the number of deletions that need to be made so that no character consecutively repeats
 */
int alt(std::string a)
{
    //My algo
    std::string alt_str{""};
    for (int i = 0; i < a.size()-1; i++)
    {
        if(a[i] != a[i+1]) 
        {
            alt_str.push_back(a[i]);
        }
    }
    int deletions = a.size()-alt_str.size() - 1;
    return deletions;
}

int main()
{

    return 0;
}
