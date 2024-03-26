# include<bits/stdc++.h>
using namespace std;
vector<int>path;
class tree{
    public:
    int val;
    tree * left;
    tree * right;
    tree(int p){
        val = p;
        left = NULL;
        right= NULL;
    }
};
void left_view(tree*root);//Prints the left view of trees that is only the leftmost elements
int sum_up(tree*root);//Adds the toatal sum of trees through recursion
int height(tree*root, int maxi, int itr);//Gets the height of the tree;
void level(tree*root);//Prints the tree in a ascending level manner (root first) using queue & recursion
int add_nodes(tree* root, int k);//Adding the first k nodes in level order traversal
int search(int ino[], int strt, int end, int curr);//searches between the indices in an inorderr array
tree*  buildtree( int preo[], int ino[], int start, int end);//Builds A tree using a combination of inorder and preorder traversals
void inorder(tree*root);//Prints inorder traversal
int nodecount(tree* root);//Returns the number of nodes
int diameter(tree* root);//Returns the number of leftmost nodes + number of rightmost nodes + 1 for the root node  
int left(tree* root,int count);//Returns the number of leftmost nodes
int right(tree* root,int countr);//Returns the number of rightmost nodes
void sub_tree_k(tree * , int );//Prints the nodes at the kth level
int print_nodes_at_k(tree* root,tree* target,int k);//Print nodes at k distance from target node
int max_path(tree*root,int maximum);//Gives the maximum path for a weighted tree
void BST(tree* root,int n);//Adds value n in a Binary Search tree
tree* search_BST(tree* root, int n);//Binary Search in Binary Search Tree
tree* balanced_BST_from_sorted_arr(tree* root, int arr[], int n, int strt, int end);//Creating a Binaary Search Tree from a sorted array
bool checkBST(tree* root, int minimum, int maximum);//Check if the tree is a Binary Search tree or not 
int* inorder_array(tree* root);//Returns inorder array
int main(){
    return 0;
}
tree *  buildtree( int preo[], int ino[], int end, int strt){
    static int itr = 6;
    if(strt > end){
        return NULL;
    }
    int curr = preo[itr];
    tree* root = new tree(curr);
    itr--;
    if(strt == end){
        return root;
    }
    int pos = search(ino,strt,end,curr);
    root->right = buildtree(preo,ino,end,pos+1);
    root->left = buildtree(preo,ino,pos-1,strt);
}
int search(int ino[], int strt, int end, int curr){
    for(int i = strt; i<end ;i++){
        if(ino[i] == curr){
            return i;
        }
    }
    return -1;
}
void inorder(tree*root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<"\n";
    inorder(root->right);
    return;
}
int nodecount(tree* root){
    if(root == NULL){
        return 0;
    }
    int count;
    count = nodecount(root->left) + nodecount(root->right) + 1;
    return count;
}
void level(tree*root){

    queue <tree*> q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty()){
        tree* branch = q1.front();
        q1.pop();

        if(branch != NULL){
            cout<<branch->val;
            if(branch -> left != NULL){
                q1.push(branch->left);
            }
            if(branch->right != NULL){
                q1.push(branch->right);
            }
        }
        else if(!q1.empty()){
            q1.push(NULL);
        }
    }
}
int add_nodes(tree* root, int k){
    queue <tree*> q1;
    q1.push(root);
    q1.push(NULL);
    int sum = 0, itr = 1;
    while(!q1.empty()){
        tree* branch = q1.front();
        q1.pop();
        if(itr == k && branch != NULL){
            sum += branch->val;
        }

        if(branch != NULL){
            if(branch -> left != NULL){
                q1.push(branch->left);
            }
            if(branch->right != NULL){
                q1.push(branch->right);
            }
        }
        else if(!q1.empty()){
            q1.push(NULL);
            itr++;
        }
    }
    return sum;
}
int height(tree*root,int maxi,int itr){
    if(root != NULL){
        itr++;
        maxi = max(itr,maxi);
    }
    else{
        
        return maxi;
    }
    maxi = max(height(root->right,maxi,itr),maxi);
    maxi = max(height(root->left,maxi,itr),maxi);
    return maxi;
}
int diameter(tree* root){
    int lefty = 0, righty = 0;
    lefty = left(root->left,0);
    righty = right(root->right,0);
    return lefty + righty + 1;
}
int left(tree* root,int count){
    if(root != NULL){
        count = left(root->left,count);
        count++;
    }
    return count;
}
int right(tree* root,int countr){
    if(root != NULL){
        countr = right(root->right,countr);
        countr++;
    }
    return countr;
}
int sum_up(tree*root){
    if(root->left == NULL && root->right == NULL){
        return root->val;
    }
    else if(root->left == NULL){
        root->val = sum_up(root->right) + root->val;
        return root->val;
    }
    else if(root->right == NULL){
        root->val = sum_up(root->left) + root->val;
        return root->val;
    }    
    root->val = root->val + sum_up(root->left) + sum_up(root->right);
    return root->val;
}
void left_view(tree*root){


    if(root == NULL){
        return ;
    }
    queue <tree*> q1;
    q1.push(root);
    while(!q1.empty()){
        int n = q1.size();
        for(int i = 1; i <= n; i++){
            tree* temp = q1.front();
            q1.pop();
            if(i == n){
                cout<<temp->val<<"\n";
            }
            if(temp->left != NULL){
                q1.push(temp->left);
            }
            if(temp->right != NULL){
                q1.push(temp->right);
            }
        }
    }
}
void sub_tree_k(tree* root , int k){
    if(k < 0 || root == NULL){
        return ;
    }
    else if(k == 0){
        cout<<root->val<<" ";
        return;
    }
    else {
        sub_tree_k(root->left,k-1);
        sub_tree_k(root->right,k-1);
        return;
    }
}
int print_nodes_at_k(tree* root,tree* target,int k){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        sub_tree_k(root,k);
        return 0;
    }
    int dl;
    dl = print_nodes_at_k(root->left,target,k);
    if(dl != -1){
        if(dl+1 == k){
            cout<<root->val<<" ";
        }
        else{
            sub_tree_k(root,k-dl-2);

        }
        return 1+dl;
    }
    int dr;
    dr = print_nodes_at_k(root->right,target,k);
    if(dr != -1){
        if(dr+1 == k){
            cout<<root->val<<" ";
        }
        else{
            sub_tree_k(root,k-dr-2);

        }
        return 1+dr;
    }
    return -1;
}
int max_path(tree*root,int maximum) {
    int l_max = INT16_MIN;
    int r_max = INT16_MIN;
    if(root->left != NULL){
        l_max = max_path(root->left,maximum);
    }
    if(root->right != NULL){
        r_max = max_path(root->right,maximum);
    }
    maximum = max(max(maximum,root->val),max(max(l_max+root->val,r_max + root->val),r_max + l_max + root->val));
    return maximum;
}
void BST(tree* root, int n){
    if(root == NULL){

        root = new tree(n);
    }
    if( n > root -> val){

        if(root->right == NULL){

            root -> right = new tree(n);
        }
        else{

            BST(root->right,n);
        }
    }
    else{


        if(root->left == NULL){
            
            root->left = new tree(n);
        }
        else{

            BST(root->left, n);
        }
    }
    return;
}
tree* search_BST(tree* root, int n){
    if(root == NULL){
        return NULL;
    }
    if(n == root->val){
        return root;
    }
    else if(n > root->val){
        return search_BST(root->right,n);
    }
    else if(n < root->val){
        return search_BST(root->left,n);
    }
}
tree* search_prece_BST(tree*root, int n){
    if(root == NULL){
        return NULL;
    }
    if(root->left->val == n || root->right->val == n){
        return root;
    }
}
bool checkBST(tree* root, int minimum, int maximum){
    if(root == NULL){
        return true;
    }
    if(root->val >= maximum || root->val <= minimum){
        return false;
    }
    return checkBST(root->left, minimum, root->val) && checkBST(root->right, root->val, maximum);
}
tree* balanced_BST_from_sorted_arr(tree* root, int arr[], int n, int strt, int end){
    if(strt == end){
        root = new tree(arr[strt]);

        return root; 
    }
    int mid = (strt + end)/2;
    root = new tree(arr[mid]);
    root->left = balanced_BST_from_sorted_arr(root->left,arr,n,strt,mid-1);
    root->right = balanced_BST_from_sorted_arr(root->right,arr,n,mid+1,end);
    return root;
}
int* inorder_array(tree* root){
    
}