#include <string>
#include <iostream>

#include <vector>
#include <map>

/*  Determine if a 'note' vector of strings can be made from a 'magazine' vector of strings
 *  (like a ransom note)
 *  Essentially, that magazine has at least the words that are in the note.
 */

//My implementation
void checkMagazine(std::vector<std::string> magazine, std::vector<std::string> note)
{
    std::map<std::string, int> note_words; 
    std::map<std::string, int> mag_words;

    for (std::string mag_word : magazine)
    {
        if (mag_words.count(mag_word) == 0)
        {
            mag_words.insert(std::make_pair(mag_word, 1));
        }
        else
        {
            mag_words[mag_word]++;
        }
    }
    for (std::string note_word : note)
    {
        if (note_words.count(note_word) == 0)
        {
            note_words.insert(std::make_pair(note_word, 1));
        }
        else
        {
            note_words[note_word]++;
        }
    }

    for (std::string note_word : note)
    {
        bool word_matches = false;
        //Does next line check both existence AND quantity?
        if ((note_words[note_word] <= mag_words[note_word]))
        {
            word_matches = true;
        }
        else
        {
            std::cout << "No \n";
            return;
        }
    }
    std::cout << "Yes \n";
    return;
}

int main()
{
    std::vector<std::string> mag_vec = { "hello", "fun", "world", "dance", "party" };
    std::vector<std::string> note_vec = { "hellog", "world" };

    checkMagazine(mag_vec, note_vec);

    return 0;
}
