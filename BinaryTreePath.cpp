#include <iostream>

/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Uber.

Given a binary tree and an integer k, return whether there exists a root-to-leaf path that sums up to k.

For example, given k = 18 and the following binary tree:

    8
   / \
  4   13
 / \   \
2   6   19
Return True since the path 8 -> 4 -> 6 sums to 18.
*/

class BinaryTree
{
	private: 
	
	int m_value;
	BinaryTree* m_root = nullptr;
	BinaryTree* m_left = nullptr;
	BinaryTree* m_right = nullptr;
	
	public:
		BinaryTree(){};
		BinaryTree(int i_value) : m_value(i_value){}
		
		BinaryTree* Insert(BinaryTree* root, int i_value)
		{
			if (root == nullptr)
			{
				return new BinaryTree(i_value);
			}
			
			if (i_value >= root->m_value)
			{
				root->m_right = Insert(root->m_right, i_value);
				root->m_right->m_root = root;
			}
			else
			{
				root->m_left = Insert(root->m_left, i_value);
				root->m_left->m_root = root;
			}
			
			return root;
		}
		
		/*
		BinaryTree* GetParent(BinaryTree* node)
		{
			return node->m_root;
		}
		*/
		
		void Print(BinaryTree* root)
		{
			if (root == nullptr)
			{
				return ;
			}
			
			std::cout << root->m_value << std::endl;
			Print(root->m_left);
			std::cout << "----";
			Print(root->m_right);
		}
		
		void PrintPathBackward(BinaryTree* end)
		{
			if (end == nullptr)
			{
				return;
			}
			PrintPathBackward(end->m_root);
			std::cout << "---> " << end->m_value;
		}
		
		void SearchPath(BinaryTree* root, int k)
		{
			if (root == nullptr)
			{
				return;
			}
			if (root->m_value == k)
			{
				//end case
				PrintPathBackward(root);
				return ;
			}
			
			if (root->m_value > k)
			{
				//std::cout << "--> " << root->m_value;
				return ;
			}
			
			
			
			//std::cout << "--> " << root->m_value; //root value smaller than k
			SearchPath(root->m_left, k-root->m_value);
			SearchPath(root->m_right, k-root->m_value);
		}
		
		BinaryTree* FindPath(BinaryTree* root, int k)
		{
			if (root == nullptr)
			{
				return root;
			}
			if (root->m_value == k)
			{
				//end case
				return root;
			}
			
			if (root->m_value > k)
			{
				//std::cout << "--> " << root->m_value;
				return nullptr;
			}
			
			
			
			//std::cout << "--> " << root->m_value; //root value smaller than k
			BinaryTree* leftSearch = FindPath(root->m_left, k-root->m_value);
			BinaryTree* rightSearch = FindPath(root->m_right, k-root->m_value);
			return (leftSearch != nullptr) ? leftSearch : rightSearch;
		}
};

int main()
{
	BinaryTree tree;
	BinaryTree* root = nullptr;
	
	root = tree.Insert(root, 8);
	root = tree.Insert(root, 4);
	root = tree.Insert(root, 13);
	root = tree.Insert(root, 2);
	root = tree.Insert(root, 6);
	root = tree.Insert(root, 19);
	root = tree.Insert(root, 5);
	
	const int k = 23;
	BinaryTree* leave = tree.FindPath(root, k);
	if (leave == nullptr)
	{
		std::cout << "No path found for k = "<< k << std::endl;
	}
	else
	{
		std::cout << "Path found for k = "<< k << std::endl;
		tree.PrintPathBackward(leave);
	}
}
