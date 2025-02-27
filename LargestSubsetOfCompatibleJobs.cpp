// Online C++ compiler to run C++ program online
#include <iostream>
#include <utility>
#include <vector>

template <typename T, typename V>
void PrintPair(std::pair<T, V> i_pair)
{
    std::cout << "(" << std::get<0>(i_pair) << ", " << std::get<1>(i_pair) << ") ";
}

bool HasPrevCompatible(std::vector<std::vector<std::pair<int, int>>*>& i_map, std::pair<int, int>& i_job)
{
    int count = 0;
    for (auto item : i_map)
    {
        if (std::get<1>(item->back()) <= std::get<0>(i_job))
        {
            item->push_back(i_job);
            count++;
        }
    }
    return count > 0;
}
void GetCompatibleJobs(std::vector<std::pair<int, int>>& i_jobs)
{
    std::vector<std::vector<std::pair<int, int>>*> map;
    for (auto& job : i_jobs)
    {
        if (!HasPrevCompatible(map, job)) //if none of the list has previous compatible item
        {
            map.push_back(new std::vector<std::pair<int, int>>({job}));
        }
    }
    
    for (const auto& m : map)
    {
        for (auto it = m->begin(); it != m->end(); it++)
        {
            PrintPair<int, int>(*it);
        }
        std::cout << std::endl;
    }
    
}
int main() {
    // Write C++ code here
    std::vector<std::pair<int, int>> jobs;
    jobs.reserve(10);
    
    jobs.push_back(std::make_pair<int, int>(0,6));
    jobs.push_back(std::make_pair<int, int>(1,4));
    jobs.push_back(std::make_pair<int, int>(3,5));
    jobs.push_back(std::make_pair<int, int>(3,8));
    jobs.push_back(std::make_pair<int, int>(4,7));
    jobs.push_back(std::make_pair<int, int>(5,9));
    jobs.push_back(std::make_pair<int, int>(6,10));
    jobs.push_back(std::make_pair<int, int>(8,11));
    
    GetCompatibleJobs(jobs);
    std::cout << "Done" << std::endl;          

    return 0;
}
