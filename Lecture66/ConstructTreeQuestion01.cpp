#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
// your code here
class Solution
{
public:
    void createMapping(int in[], map<int, int> &nodeToIndex, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[in[i]] = i;
             
        }
    }
    Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
    {
        // base case
        if (index >= n || inorderStart > inorderEnd)
        {
            return NULL;
        }
        // created a root node for element
        int element = pre[index++];
        Node *root = new Node(element);

        // find elements's index in
        int position = nodeToIndex[element];
        // recursive calls
        root->left = solve(in, pre, index, inorderStart, position - 1, n, nodeToIndex);
        root->right = solve(in, pre, index, inorderStart, position - 1, n, nodeToIndex);

        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;
        //  create nodes to index mapping
        createMapping(in, nodeToIndex, n);
        Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
        return ans;
    }
};
