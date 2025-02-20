/*
ood morning! Here's your coding interview problem for today.

This problem was asked by Robinhood.

Given an array of strings, group anagrams together.

For example, given the following array:

['eat', 'ate', 'apt', 'pat', 'tea', 'now']
Return:

[['eat', 'ate', 'tea'],
 ['apt', 'pat'],
 ['now']]
 
 */
 
 #include <bits/stdc++.h>
 
 void RecurrentPermutation(int index, std::string& s, std::vector<std::string>& ans)
 {
 	if (index == s.size())
 	{
 		//base case
 		//std::cout<< s<<std::endl;
 		ans.push_back(s);
 		return;
	}
	
	//swap the index with all other position
	//increase the index
	//recur for the next index
	
	for (int i=index; i<s.size(); i++)
	{
		std::swap(s[index], s[i]); //swap the index with ith-position
		RecurrentPermutation(index+1, s, ans); //after swap the index with the i-th position, find the permutation for the new index
		std::swap(s[index], s[i]); //return the original for the i+1-th position
	}
 }
 
 std::vector<std::string> findPermutation(std::string &s) {

    // Stores the final answer
    std::vector<std::string> ans;

    RecurrentPermutation(0, s, ans);

    // sort the resultant vector
    //std::sort(ans.begin(), ans.end());

    return ans;
}

int main() {
	std::vector<std::string> items = {"eat", "ate", "apt", "pat", "tea", "now"};
	std::vector<std::vector<std::string>> collection;
	collection.reserve(items.size());
	
	while (!items.empty())
	{
		std::string first = items[0];
		std::vector<std::string> currentGroup{};
		currentGroup.reserve(items.size());
		//std::cout<< "Group : ";
		std::vector<std::string> perms = findPermutation(first);
		for (const auto& perm : perms)
		{
			auto it = std::find(items.begin(), items.end(), perm);
			if (it != items.end())
			{
				//std::cout<< perm << " ";
				currentGroup.push_back(perm);
				items.erase(it);
			}
		}
		
		collection.push_back(currentGroup);
		//std::cout<<std::endl;
	}
	
    for (const auto list : collection)
    {
    	for (const auto item : list)
    	{
    		std::cout << item << " ";
		}
		std::cout << std::endl;
	}
    return 0;
}
