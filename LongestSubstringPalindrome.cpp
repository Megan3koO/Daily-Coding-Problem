/*Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given a string, return the length of the longest palindromic subsequence in the string.

For example, given the following string:

MAPTPTMTPA
Return 7, since the longest palindromic subsequence in the string is APTMTPA. Recall that a subsequence of a string does not have to be contiguous!

Your algorithm should run in O(n^2) time and space.
*/
#include <iostream>
#include <string>

std::string str = "MAPTPTMTPA";
std::string FindPalindrome(std::string& i_string, int startIndex, int endIndex)
{
    if (startIndex == endIndex)
    {
        std::string s;
        s.push_back(i_string[startIndex]);
        return s;
    }
    
    
    for (int j=endIndex; j > startIndex; j--)
    {
        if (i_string[startIndex] == i_string[j])
        {
            //found
            return i_string[startIndex] + FindPalindrome(i_string, startIndex+1, j-1) + i_string[j];
        }
    }
    
    //no 
    std::string s;
    s.push_back(i_string[startIndex]);
    return s;
}

int main() {
    // Write C++ code here
    /*char* left = &str.data()[0];
    char* right = &str.data()[str.size() - 1];
     
    while (left < right)
    {
        std::cout <<  *left << *right << std::endl;
        left++;
        right--;
    }*/
    int currentLength = 0;
    std::string currentString = "";
    for (int i=0; i<str.size(); i++)
    {
            //start finding the right most equal
        std::string result = FindPalindrome(str, i, str.size() - 1);
        if (result.size() > currentLength)
        {
            currentLength = result.size();
            currentString = result;
        }
    }
    
    std::cout << currentString << std::endl;
    std::cout << currentLength << std::endl;

    return 0;
}
