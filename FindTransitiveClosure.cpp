// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>


std::vector<std::vector<int>> ConstructGraphMatrix(const std::vector<std::vector<int>>& graph)
{
    std::vector<std::vector<int>> matrix;
    int size = graph.size();
    for (int i=0; i<size; i++)
    {
        std::vector<int> row(size);
        matrix.push_back(row);
    }
  
    for (int i = 0; i<size; i++)
    {
        for (auto item : graph[i])
        {
            matrix[i][item] = 1;
        }
    }
  
    return matrix;
}

void PrintMatrix(const std::vector<std::vector<int>>& matrix)
{
    for (int i=0; i<matrix.size(); i++)
    {
        for (int j=0; j<matrix[i].size(); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void ComputeTransitiveClosure(std::vector<std::vector<int>> graph)
{
    //construct graph matrix
    std::vector<std::vector<int>> matrix = ConstructGraphMatrix(graph);
    int size = matrix.size();
    //loops over "bridge"
    for (int k=0; k<size; k++) 
    {
        //loops over each item
        for (int i = 0; i<size; i++)
        {
            for (int j=0; j<size; j++)
            {
                if (matrix[i][k] && matrix[k][j])
                {
                    matrix[i][j] = 1;
                }
            }
        }
    }
    
    PrintMatrix(matrix);
}
int main() {
    std::vector<std::vector<int>> graph = {
    {0, 1, 3},
    {1, 2},
    {2},
    {3}
    };

    ComputeTransitiveClosure(graph);
    return 0;
}
