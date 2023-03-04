// 1. Initialize current as root 
// 2.  While current is not NULL
//     If the current does not have left child
//       a) Print current’s data
//       b) Go to the right, i.e., current = current->right
//          Else
//       a) Find rightmost node in current left subtree OR
//               node whose right child == current.
//          If we found right child == current
//              a) Update the right child as NULL of that node whose right child is current
//              b) Print current’s data
//              c) Go to the right, i.e. current = current->right
//               Else
//              a) Make current as the right child of that rightmost 
//                 node we found; and 
//              b) Go to this left child, i.e., current = current->left


                       //  Morris Traversal                


    void MorrisTraversal(struct tNode* root){
        struct tNode* current , * pre;

        if(root==NULL){
            return ;
        }
        current = root;

        while(current !=NULL){
            if(current ->left ==NULL){
                cout<< current->data<< " ";
                current = current->right;
            }
            else{
                pre = current->left;
                while(pre->right !=NULl && pre->right !=current) 
                pre = pre->right;


                if(pre->right == NULL){
                    pre->right = current;
                    current = current->left;
                }
                else{
                    pre->right = NULL;
                    count<<current->data<< " ";
                    current = current->right;
                }
            }
        }
    }                      


