#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
#include <set>

/* Given a vector of ints (socks), find how many pairs of socks we can make, assuming that unique ints
 *  are different varieties of socks to be paired.
 *
 */

int sockMerchant(int number_of_socks, const std::vector<int>& stray_socks)
{
    std::vector<int> sock_copy = stray_socks;
    std::set<int> sock_types {sock_copy.begin(), sock_copy.end()};
    std::vector<int> colors_vec {sock_types.begin(), sock_types.end()};
    std::vector<int>::iterator sock_i; 
    std::vector<int>::iterator color_i = colors_vec.begin();

    static int pairCount = 0;

    for ( color_i; color_i != colors_vec.end(); ++color_i )
    {
        int color_count = 0;
        for (sock_i = sock_copy.begin(); sock_i != sock_copy.end(); ++sock_i )
        {
            if (*sock_i == *color_i)
            {
                color_count += 1;
            }
        }
        pairCount += (color_count / 2);
    }
    return pairCount;
}


int main()
{
    int sock_num = 7;
    std::vector<int> sock_array = { 2, 2, 1, 3, 2, 1, 3 };

    sockMerchant(sock_num, sock_array);
    return 0;
}
