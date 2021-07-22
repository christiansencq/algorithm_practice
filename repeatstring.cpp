#include <iostream>
#include <string>
#include <algorithm>

// Return how many 'a' characters will be found in a string of n length
//  Repeat the string until it is n length long.


int repeatedString(std::string s, int n)
{
    const int str_size = s.size();
    int a_counter = 0;

    for (int j = 0; j != n; j++)
    {
        if (s[((j+str_size)%str_size)] == 'a')
        {
            a_counter++;
        }
    }
    return a_counter;
}

int repeatedString2(std::string s, int n)
{
    //Find out how many a's are in the s.
    long a_count = std::count(s.begin(), s.end(), 'a');
    long str_size = s.size();
    
    int strs_in_n = n / str_size;
    int leftover_str = n % str_size;

    //Count all the 'a's in the full strings we have.
    a_count *= strs_in_n;

    for (int i = 0; i != leftover_str; i++)
    {
        if (s[i] == 'a')
        {
            a_count++;
        }
    }
    return a_count;
}



int main()
{
    int count;

    std::string newString("aba");
    int string_size = 10;
    count = repeatedString2(newString, string_size);

    std::cout << "Count " << count << std::endl;
    return 0;
}
