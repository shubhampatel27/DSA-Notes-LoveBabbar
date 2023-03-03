//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/



class Solution
{
public:
    Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n,  map<int, queue<int>> &nodeToIndex)
    {
        // base case
        if (index >= n || inorderStart > inorderEnd)
        {
            return NULL;
        }
        // created a root node for element
        int element = pre[index++];
        Node* root = new Node(element);

        // find elements's index in
        int position = nodeToIndex[element].front();
        nodeToIndex[element].pop();
        // recursive calls
        root->left = solve(in, pre, index, inorderStart, position - 1, n, nodeToIndex);
        root->right = solve(in, pre, index, position +1, inorderEnd, n, nodeToIndex);

        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int, queue<int>> nodeToIndex;
        //  create nodes to index mapping
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[in[i]].push(i);
        }
        Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
        return ans;
    }
};
// 7
// 7 3 11 1 17 3 18 inorder 
// 1 3 7 11 3 17 18 preorder







//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends