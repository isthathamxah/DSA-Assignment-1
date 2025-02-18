#include <fstream>
#include <iostream>

using namespace std;

template <typename T>
class FixedSizeStack
{
private:
    T* arr;
    int capacity;
    int topIndex;

public:
    FixedSizeStack(int cap = 100);
    ~FixedSizeStack();
    void push(const T& value);
    void pop();
    T top() const;
    bool isEmpty() const;
};

// Constructor
template <typename T>
FixedSizeStack<T>::FixedSizeStack(int cap) : capacity(cap), topIndex(-1)
{
    arr = new T[capacity];
}

// Destructor
template <typename T>
FixedSizeStack<T>::~FixedSizeStack()
{
    delete[] arr;
}

// Push method
template <typename T>
void FixedSizeStack<T>::push(const T& value)
{
    if (topIndex == capacity - 1)
    {
        cout << "Stack Overflow" << endl;
        exit(1);
    }
    arr[++topIndex] = value;
}

// Pop method
template <typename T>
void FixedSizeStack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
        exit(1);
    }
    topIndex--;
}

// Top method
template <typename T>
T FixedSizeStack<T>::top() const
{
    if (isEmpty())
    {
        cout << "Stack is empty. No top element." << endl;
        exit(1);
    }
    return arr[topIndex];
}

// Check if empty
template <typename T>
bool FixedSizeStack<T>::isEmpty() const
{
    return topIndex == -1;
}

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

    FixedSizeStack<char> charStack(word.length());

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

