/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Twitter.

A permutation can be specified by an array P, where P[i] represents the location of the element at i in the permutation. For example, [2, 1, 0] represents the permutation where elements at the index 0 and 2 are swapped.

Given an array and a permutation, apply the permutation to the array. For example, given the array ["a", "b", "c"] and the permutation [2, 1, 0], return ["c", "b", "a"].
*/

#include <bits/stdc++.h>

std::vector<std::string> ApplyPermutation(std::vector<std::string> array, std::vector<int>& permutation)
{
    std::vector<std::string> result;
    result.resize((int) array.size());
    for (auto index : permutation)
    {
        result.push_back(array[index]);
    }
    return result;
}
int main()
{
    std::vector<int> permutation = {2,1,0};
    std::vector<std::string> array = {"a", "b", "c"};
    std::vector<std::string> result = ApplyPermutation(array, permutation);
    for (auto item : result)
    {
        std::cout << item << " ";
    }
    return 0;
}
