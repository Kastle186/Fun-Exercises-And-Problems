// Name: 211. Design Add and Search Words Data Structure
// Topics: String, Depth-First Search, Design, Trie
// Companies:
// - Rubrik
// - DoorDash
// - LinkedIn

#include <iostream>
#include <string>

#define ENGLISH_ALPHABET 26

// TRIE IMPLEMENTATION PROBLEM WITH A TWIST DONE ENTIRELY BY MYSELF WOOOOOO!!!!!

class LetterNode
{
public:
    LetterNode *letters[ENGLISH_ALPHABET];
    bool isLeaf;

    LetterNode()
    {
        isLeaf = false;

        for (int i = 0; i < ENGLISH_ALPHABET; i++)
            letters[i] = nullptr;
    }

    ~LetterNode()
    {
        for (int i = 0; i < ENGLISH_ALPHABET; i++)
            delete letters[i];
    }
};

class WordDictionary
{
private:
    LetterNode *root;

public:
    WordDictionary() { root = new LetterNode(); }
    ~WordDictionary() { delete root; }

    void add(std::string word)
    {
        LetterNode *current = root;

        for (char c : word)
        {
            int index = c - 'a';

            if (current->letters[index] == nullptr)
            {
                LetterNode *newNode = new LetterNode();
                current->letters[index] = newNode;
            }

            current = current->letters[index];
        }

        current->isLeaf = true;
    }

    bool search(std::string word)
    {
        LetterNode *start = root;
        return searchHelper(start, word, 0);
    }

private:
    bool searchHelper(LetterNode *current, std::string word, int index)
    {
        if (index == word.length())
            return current->isLeaf;

        char c = word[index];

        if (c == '.')
        {
            for (int i = 0; i < ENGLISH_ALPHABET; i++)
            {
                if (current->letters[i] != nullptr
                    && searchHelper(current->letters[i], word, index + 1))
                    return true;
            }
        }
        else if (current->letters[c - 'a'] == nullptr)
            return false;
        else
            return searchHelper(current->letters[c - 'a'], word, index + 1);

        return false;
    }
};

int main(void)
{
    std::cout << "211. Design Add and Search Words Data Structure" << std::endl;

    WordDictionary *wdict = new WordDictionary();
    wdict->add("bad");
    wdict->add("dad");
    wdict->add("mad");

    std::cout << (wdict->search("pad") ? "True" : "False") << std::endl;
    std::cout << (wdict->search("bad") ? "True" : "False") << std::endl;
    std::cout << (wdict->search(".ad") ? "True" : "False") << std::endl;
    std::cout << (wdict->search("b..") ? "True" : "False") << std::endl;

    delete wdict;
    return 0;
}
