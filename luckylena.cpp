#include <vector>
#include <algorithm>
#include <iostream>

//Find out how much luck Lena can get by losing games. She can't lose more than num of important games, though.
// Lena believes in a luck-balance, where her luck increases based on the number of games she loses.

//My implementation
int luckBalance(int allowed_imp_losses, std::vector<std::vector<int>> contests)
{
    int luck_balance = 0;

    //Stores the luck values for the important contests.
    std::vector<int> important_contest_luck;


    for (int i = 0; i < contests.size(); i++)
    {
        //If its an unimportant contest, go ahead and lose.
        if(contests[i][1] == 0)
        {
            luck_balance += contests[i][0];
        }
        else //Otherwise add it to the important lists to check later.
        {
            important_contest_luck.push_back(contests[i][0]);
        }
    }
    //Now cycle through the important contests and lose the highest valued ones.
    std::sort(important_contest_luck.begin(), important_contest_luck.end());
    int lost_importants = 0;
    for (int i = important_contest_luck.size()-1; i >= 0; i--)
    {
        if (lost_importants < allowed_imp_losses) //If we havent used up our losses, lose it!
        {
            luck_balance += important_contest_luck[i];
            lost_importants++;
        }
        else //Else, we have to win and lose some luck.
        {
            luck_balance -= important_contest_luck[i];
        }
    }

    return luck_balance;
}

int main()
{
    std::vector<std::vector<int>> vec = { {5, 1}, {2, 1}, {1, 1}, {8, 1}, {10, 0}, {5, 0}};
    int luck = luckBalance(3, vec); 
    std::cout << "Luck? " << luck << std::endl;
    return 0;
}
