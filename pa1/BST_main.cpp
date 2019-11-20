#include <iostream>
#include "BST.hpp"

using namespace std;

int main()
{
  BSTNode<int> *aNode = new BSTNode<int>(10);
  cout << aNode->data;
  return 0;
}
