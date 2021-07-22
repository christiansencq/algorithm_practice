#include <iostream>
#include <map>
#include <ranges>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

/* When given two strings, find the number of characters that must be deleted
 * for the two strings to be anagrams of each other
 */

//My implementation
int ana_make(std::string a, std::string b)
{
    std::vector<int> frequencies_of_char1(26, 0);
    std::vector<int> frequencies_of_char2(26, 0);
    for (auto c : a)
    {
        // -97 converts the char to the position in the vector
        frequencies_of_char1[c-97]++;
    }
    for (auto c : b)
    {
        frequencies_of_char2[c-97]++;
    }

    int diff_count = 0;
    std::vector<int> freqs(26, 0);
    for (int i = 0; i < 26; i++)
    {
        freqs[i] = abs(frequencies_of_char1[i]-frequencies_of_char2[i]);
    }
    for (auto val: frequencies_of_char1)
    {
        std::cout << val << "\n";
    }

    diff_count = std::accumulate(freqs.begin(), freqs.end(), 0);
    return diff_count;
}

// int makeAnagram(std::string a, std::string b)
// {
//     std::string ana_string1, ana_string2;
//     std::map<char, int> instances1_of_char, instances2_of_char;
//
//     //For each character in Each
//     for (auto c1 : a)
//     {
//         //If char is in instances_of_char, increment its value.
//         if (instances1_of_char.count(c1))
//         {
//             instances1_of_char[c1]++;
//         }
//         else  //Otherwise, add it as a key.
//         {
//             instances1_of_char.insert({c1, 1});
//         }
//     }
//
//     for (int i = 0; i < ana_string2.size(); i++)
//     {
//     if (instances2_of_char.count(ana_string2[i]))
//     {
//         instances2_of_char[ana_string2[i]]++;
//     }
//     else
//     {
//         instances2_of_char.insert({ana_string2[i], 1});
//     }
// }
//
    // std::string anagram;
//     for (auto key : instances1_of_char)
//     {
//
//         if (instances1_of_char[key] == instances2_of_char[key])
//         {
//
//         }
//     }
//
//     return count;
// }

int main()
{
    std::string string1("fcrxzwscanmligyxyvym");//Repeats xx, yyy, mm
    std::string string2("jxwtrhvujlmrpdoqbisbwhmgpmeoke");// Repeats ee, mmm, pp, jj, oo, bb, hh, ww

    int ana_size = ana_make(string1, string2);

    std::cout << "Ana size " << ana_size << std::endl;
    return 0;
}
