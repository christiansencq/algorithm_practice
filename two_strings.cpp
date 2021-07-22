#include <string>
#include <iostream>

/*  Given two strings, return a "YES" or "NO" string
 *   Indicating whether or not any of the characters are shared by either string
 */

//My implementation
std::string twoStrings(std::string str1, std::string str2)
{
    std::string long_str = (str1.size() >= str2.size()) ? str1 : str2;
    std::string short_str = (str1.size() >= str2.size()) ? str2 : str1;
    std::cout << "Long " << long_str << std::endl;
    std::cout << "Short " << short_str << std::endl;

    for (char letter : long_str)
    {
        size_t letter_pos = short_str.find(letter);
        if (short_str[letter_pos])
        {
            std::cout << "Position " << short_str[letter_pos] << std::endl;
            std::cout << "Position1 " << letter_pos << std::endl;
            std::cout << "Letter within short_str " << short_str[letter_pos] << std::endl;
            std::cout << "Letter char from long_str " << letter << " . ";
            return std::string("YES");
        }
    }
    return std::string("NO");
}


int main()
{
    std::string str1("hello");
    std::string str2("lime");
    std::string result = twoStrings(str1, str2);
    std::cout << std::endl << "Results " << result << std::endl;
    
    std::string str3("timepiece");
    std::string str4("jojo");
    std::string result2 = twoStrings(str3, str4);
    std::cout << std::endl << "Results " << result2 << std::endl;

    return 0;
}
