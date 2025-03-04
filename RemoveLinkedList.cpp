// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Given a linked list and an integer k, remove the k-th node from the end of the list and return the head of the list.

k is guaranteed to be smaller than the length of the list.

Do this in one pass.
*/

class LinkedList
{
  private:
  int m_value;
  LinkedList* next = nullptr;
  LinkedList* prev = nullptr;
  
  public:
  LinkedList(){}
  LinkedList(int value) : m_value(value){}
  LinkedList* Insert(LinkedList* root, int value)
  {
      if (root == nullptr)
      {
          return new LinkedList(value);
      }
      
      root->next = Insert(root->next, value);
      root->next->prev = root;
      
      return root;
  }
  
  void Print(LinkedList* root)
  {
      if (root == nullptr)
      {
          std::cout << std::endl;
          return ;
      }
      std::cout << root->m_value << " ";
      Print(root->next);
  }
  
  LinkedList* Remove(LinkedList* root, LinkedList* node)
  {
      if (node == root)
      {
          LinkedList* newRoot = root->next;
          newRoot->prev = nullptr;
          delete root;
          root = nullptr;
          return newRoot;
      }
      LinkedList* prev = node->prev;
      LinkedList* next = node->next;
      prev->next = next;
      next->prev = prev;
      
      delete node;
      node = nullptr;
      
      return root;
  }
  
  LinkedList* SearchK(LinkedList* root, int k)
  {
      LinkedList* it = root;
      int length = 0;
      while(it != nullptr){
          length++;
          it = it->next;
      }
      
      int removeIdx = length - 1 - k;
      
      it = root;
      for (int i=1; i<=removeIdx; i++)
      {
          it = it->next;
      }
      
      return it;
  }
  
  LinkedList* RemoveK(LinkedList* root, int k)
  {
      LinkedList* node = SearchK(root, k);
      root = Remove(root, node);
      return root;
  }
};


int main() {
    // Write C++ code here
    LinkedList list;
    LinkedList* root = nullptr;
    
    root = list.Insert(root, 1);
    root = list.Insert(root, 2);
    root = list.Insert(root, 3);
    root = list.Insert(root, 4);
    root = list.Insert(root, 5);
    root = list.Insert(root, 6);
    
    root = list.RemoveK(root, 2);
    list.Print(root);
    
    return 0;
}
