#include <fstream>
#include <stack>
#include <iostream>

using namespace std;

bool isLetter(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}


string toLowercase(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            word[i] = word[i] + 32; 
        }
    }
    return word;
}

bool isPalindrome(string word)
{
    if (word.empty()) return false;

    stack<char> charStack;

    for (char ch : word)
    {
        charStack.push(ch);
    }

    for (char ch : word)
    {
        if (charStack.top() != ch)
        {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() 
{
    int palindromeCount = 0;
    int totalWords = 0;
    string word;

    ifstream file("file.txt");
    if (!file) 
    {
        cout << "Error! File not found\n";
        return 1;
    }

    while (file >> word)
    {
        word = toLowercase(word);

        string validWord = "";
        for (char ch : word)
        {
            if (isLetter(ch))
                validWord += ch;
        }

        if (!validWord.empty()) 
        {
            totalWords++;
            if (isPalindrome(validWord)) {
                palindromeCount++;
            }
        }
    }

    file.close();

    cout << "Total valid words processed: " << totalWords << endl;
    cout << "Palindrome words found: " << palindromeCount << endl;

    return 0;
}
