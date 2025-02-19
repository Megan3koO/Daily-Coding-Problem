#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

const int SIZE = 10;
int ARRAY[SIZE] = {9, 6, 1, 3, 8, 8, 10, 12, 13, 11};

void SortArray(int* io_array, const int& i_size);
void Swap(int& first, int& second);
void PrintArray(int* io_array, const int& i_size);
void GetLongestConsecutive(int const * const i_array, const int& i_size);
int main()
{
	SortArray(ARRAY, SIZE);
	//PrintArray(ARRAY, SIZE);
	GetLongestConsecutive(ARRAY, SIZE);
}

void Swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

void PrintArray(int* io_array, const int& i_size)
{
	for (int i=0; i<i_size; i++)
	{
		std::cout << io_array[i] << " ";
	}
	std::cout << std::endl;
}
void SortArray(int* io_array, const int& i_size)
{
	for (int i=0; i < i_size; i++)
	{
		for (int j=i+1; j<i_size; j++)
		{
			if (io_array[i] > io_array[j])
			{
				Swap(io_array[i],  io_array[j]);
			}
		}
	}
}

void GetLongestConsecutive(int const * const i_array, const int& i_size)
{
	if (i_size == 0)
	{
		std::cout << "FUCK" << std::endl;
		return ;
	}
	
	std::vector<std::vector<int>> listOfConsecutives;
	listOfConsecutives.reserve(i_size); //max number of lists is the size of the input array
	
	std::queue<int> inputQueue;
	for (int i=0; i<i_size; i++)
	{
		inputQueue.push(i_array[i]);
	} 
	
	std::vector<int> currentList;
	currentList.reserve(i_size);
	
	bool shouldStop = false;
	
	do
	{
		int next = inputQueue.front();
		inputQueue.pop();
		
		if (!currentList.empty() && (next - currentList.back()) > 1)
		{
			//Start a new list
			//std::cout << "Current list size: " << currentList.size() << std::endl;
			listOfConsecutives.emplace_back(std::move(currentList));
			currentList.reserve(i_size);
		}
		
		//if duplicated
		
		if (currentList.empty() || std::find(currentList.begin(), currentList.end(), next) == currentList.end())
		{
			currentList.push_back(next);
		}
		
		
		if(inputQueue.empty())
		{
			//Push current list to the collection and stop
			//std::cout << "Current list size: " << currentList.size() << std::endl;
			listOfConsecutives.emplace_back(std::move(currentList));
			shouldStop = true;
		}
		
	} while (!shouldStop);
	
	//std::cout << "Current list size: " << currentList.size() << std::endl;
	
	int longest = 0;
	const std::vector<int>* idx = nullptr;
	for (const auto& list : listOfConsecutives)
	{
		if (list.size() > longest)
		{
			longest = list.size();
			idx = &list;
		}
	}
	
	std::cout << "Longest size: " << longest << std::endl;
	for (const auto& element : *idx)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
}
