// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given a list of strictly positive integers, partition the list into 3 contiguous partitions which each sum up to the same value. If not possible, return null.

For example, given the following list:

[3, 5, 8, 0, 8]
Return the following 3 partitions:

[[3, 5],
 [8, 0],
 [8]]
Which each add up to 8.
*/
int GetSum(const std::vector<int>& i_array)
{
    int sum = 0;
    for (auto item : i_array)
    {
        sum+=item;
    }
    
    return sum;
}
std::vector<std::vector<int>> PartitionArray(const std::vector<int>& i_array)
{

    int sum = GetSum(i_array);
    std::vector<std::vector<int>> result;
    if ((sum % 3) != 0)
    {
        //unable to partition
        return result;
    }
    
    int target = (int) sum / 3;
    int idx = 0;
    
    std::vector<int> current;
    while (idx < i_array.size())
    {
        int currentSum = GetSum(current);
        int nextSum = currentSum + i_array[idx];
        if (nextSum < target)
        {
            //push to current
            current.push_back(i_array[idx]);
        }
        else if(nextSum == target)
        {
            current.push_back(i_array[idx]);
            result.push_back(current);
            current.clear();
        }
        else
        {
            result.clear();
            return result;
        }
        idx++;
    }
    
    return result;
}
int main() {
    // Write C++ code here
    const std::vector<int> array = {3, 5, 1, 6, 1, 6, 2};
    std::vector<std::vector<int>> result = PartitionArray(array);
    if (result.size() == 0)
    {
        std::cout << "NULL" << std::endl;
    }
    else
    {
        for (auto list : result)
        {
            for (auto item : list)
            {
                std::cout << item << " ";
            }
            std::cout <<std::endl;
        }
    }
    return 0;
}
