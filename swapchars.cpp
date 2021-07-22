#include <string>

//Go through a string and swap all instances of char 'a' with char 'b'

//My implementation
std::string doubleSwap(std::string orig_str, char a, char b)
{
    std::string newString;
    std::string::iterator str_it;

    for (str_it = orig_str.begin(); str_it < orig_str.end(); ++str_it)
    {
        if (*str_it == a)
        {
            newString.push_back(b);
        }
        else if (*str_it == b)
        {
            newString.push_back(a);
        }
        else
        {
            newString.push_back(*str_it);
        }
    }
    return newString;
}

int main()
{
    return 0;
}
