#include <string>
#include <iterator>

//Mask a string, so that all values except the last 4 are replaced with a '#'

// My implementation
std::string maskify(std::string str)
{
    std::string newString;
    std::string::reverse_iterator r_it;
    int i;

    for (i = 0, r_it = str.rbegin(); r_it != str.rend(); ++r_it, i++)
    {
        if (i > 3)
        {
            newString.push_back('#');
        }
        else
        {
            newString.push_back(*r_it);
        }
    }

    return newString;
}


int main()
{

    return 0;
}
