//---------------------------------------------------------------------------
#include <vector>
#include <fmx.h>
#pragma hdrstop
#include <fstream>
#include "Unit1.h"
#include <string>
#include <iostream>
#include "gui.cpp"
#include <queue>
#include <stack>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
class Snippet{
	public:
	String key;
	String snippet;
	vector<String> synonyms;
	Snippet *next;
	Snippet(String key, String snippet){
	this->key = key;
	this->snippet = snippet;
	this->next = NULL;
	}
	Snippet(Snippet &x){
		  this->key = x.key;
		  this->snippet = x.snippet;
		  vector<String>::iterator i;
		  for(i = x.synonyms.begin(); i != x.synonyms.end(); ++i){
			  this->synonyms.push_back(*i);
		  }
		  this->next = NULL;
	}
	Snippet(){
		this->key[1] = 0;
	}
};
String latest_key;
Snippet *Hash[26];
int is_filled[26];
bool first = true;
std::vector<Snippet> Store;
int ktr = 0;
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{


}
void ill(String key, String code, vector<String> x);
void insert_at_end(Snippet s){
	 String tag = s.key;
	 if(first){
		for(int i = 1; i <= 26; ++i){
			Hash[i] = NULL;
		}
		first = false;
	 }

	 if('a' <= tag[1] && tag[1] <= 'z'){
		Snippet *ptr = new Snippet(s);
		ptr->next = Hash[tag[1]-'a'+1];
		Hash[tag[1]-'a'+1] = ptr;
	 }
	 if('A' <= tag[1] && tag[1] <= 'Z'){
		Snippet *ptr = new Snippet(s);
		ptr->next = Hash[tag[1]-'A'+1];
		Hash[tag[1]-'A'+1] = ptr;
	 }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::sinp(TObject *Sender)
{
				   String key = Edit1->Text;
				   if(key == ""){
					  Memo1 ->Text =  "Please enter a key with alphabets as it's\n first characters with words seperated\n with underscores";
					  return ;
				   }
				   if((key[1] <= 'z' && key[1] >= 'a')||(key[1] <= 'Z' && key[1] >= 'A')) {
				   }
				   else{
					   Memo1->Text = "Please enter a key\n with alphabets as it's \nfirst characters with words seperated\n with underscores";
					   return ;
                   }
				   ListBox1->Items->Add(key);
				   String code = Memo1->Text;
				   ill(key,code,{"All"});
				   Edit1->Text = "";
				   Memo1->Text = "";
}
//---------------------------------------------------------------------------
void ill(String key, String code, vector<String> x){
	  Snippet s(key,code);
	  s.synonyms.push_back("all");
	  vector<String>::iterator i;
	  for(i = x.begin(); i != x.end(); ++i){
		  s.synonyms.push_back(*i);
	  }

	  insert_at_end(s);
	  ++ktr;
	  return ;
}
String search(String key){
	  latest_key = key;
	  Snippet *rnr;
	  if(key[1] >= 'a' && key[1] <= 'z'){
		 rnr = Hash[key[1]-'a' + 1];
		 if(Hash[key[1]-'a' + 1] == NULL){
			return  "No match found";
		 }
	  }
	  else if(key[1] >= 'A' && key[1] <= 'Z'){
		  rnr = Hash[key[1]-'A' + 1];
		  if(Hash[key[1]-'A' + 1] == NULL){
		  return  "No match found";
		  }
	  }
	  else{
		  return  "No match found";
	  }
	  if(rnr->key == key){
		 return rnr->snippet;
	  }
	  while(rnr->next != NULL){
		   rnr = rnr->next;
		   if(rnr->key == key){
			  return rnr->snippet;
		   }
	  }
	  return "No match found";
}
String editor(String key, String edit){
	  if(key == ""){
		 return "";
	  }
	  latest_key = key;
	  Snippet *rnr;
	  if(key[1] >= 'a' && key[1] <= 'z'){
		 rnr = Hash[key[1]-'a' + 1];
		 if(Hash[key[1]-'a' + 1] == NULL){
			return "";
		 }
	  }
	  else if(key[1] >= 'A' && key[1] <= 'Z'){
		  rnr = Hash[key[1]-'A' + 1];
		  if(Hash[key[1]-'A' + 1] == NULL){
			 return "";
		  }
	  }
	  else{
		  return "";
	  }
	  if(rnr->key == key){
		 rnr->snippet = edit;
		 return "Done";
	  }
	  while(rnr->next != NULL){
		   rnr = rnr->next;
		   if(rnr->key == key){
			  rnr->snippet = edit;
			  return "Done";
		   }
	  }
	  return "";

}

int latestindex = -1;
void __fastcall TForm1::Find(TCustomListBox * const Sender, TListBoxItem * const Item)

{
	  String key = Item->Text;
	  latest_key = key;
	  String code = search(key);
	  latestindex = Item->Index;
	  Memo2->Text = code;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender){
		 String str = Edit2->Text;
		 if(str == ""){
			Memo2->Text = "Not found";
            return ;
		 }
		 Memo2->Text = search(str);
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
		 ListBox1->Items->Add("tree_left_view_");
		 ill("tree_left_view_", "if(root == NULL) {\n    return ;\n}\nqueue <tree*> q1;\nq1.push(root);\nwhile(!q1.empty()) {\n    int n = q1.size();\n    for(int i = 1; i <= n; i++) {\n        tree* temp = q1.front();\n        q1.pop();\n        if(i == n) {\n            cout << temp->val << endl;\n        }\n        if(temp->left != NULL) {\n            q1.push(temp->left);\n        }\n        if(temp->right != NULL) {\n            q1.push(temp->right);\n        }\n    }\n}}", {"trees", "Trees"});
		 ListBox1->Items->Add("tree_sub_tree_k_");
		 ill("tree_sub_tree_k_", "void sub_tree_k(tree* root , int k){\n    if(k < 0 || root == NULL){\n        return ;\n    }\n    else if(k == 0){\n        cout<<root->val<<\" \";\n        return;\n    }\n    else {\n        sub_tree_k(root->left,k-1);\n        sub_tree_k(root->right,k-1);\n        return;\n    }\n}",{"trees","Trees"});
		 ListBox1->Items->Add("tree_print_nodes_at_k_");
		 ill("tree_print_nodes_at_k_", "int tree_print_nodes_at_k(tree* root, tree* target, int k){\n    if(root == NULL){\n        return -1;\n    }\n    if(root == target){\n        sub_tree_k(root, k);\n        return 0;\n    }\n    int dl;\n    dl = tree_print_nodes_at_k(root->left, target, k);\n    if(dl != -1){\n        if(dl + 1 == k){\n            cout << root->val << \" \";\n        }\n        else{\n            sub_tree_k(root, k - dl - 2);\n        }\n        return 1 + dl;\n    }\n    int dr;\n    dr = tree_print_nodes_at_k(root->right, target, k);\n    if(dr != -1){\n        if(dr + 1 == k){\n            cout << root->val << \" \";\n        }\n        else{\n            sub_tree_k(root, k - dr - 2);\n        }\n        return 1 + dr;\n    }\n    return -1;\n}",{"Trees","trees"});
		 ListBox1->Items->Add("tree_max_path_");
		 ill("tree_max_path_", "int tree_max_path(tree* root, int maximum) {\n    int l_max = INT16_MIN;\n    int r_max = INT16_MIN;\n    if(root->left != NULL){\n        l_max = tree_max_path(root->left, maximum);\n    }\n    if(root->right != NULL){\n        r_max = tree_max_path(root->right, maximum);\n    }\n    maximum = max(max(maximum, root->val), max(max(l_max + root->val, r_max + root->val), r_max + l_max + root->val));\n    return maximum;\n}",{"Trees","trees"});
		 ListBox1->Items->Add("tree_Add_Node_BST_");
		 ill("tree_Add_Node_BST_", "void tree_Add_Node_BST(tree* root, int n) {\n    if(root == NULL){\n        root = new tree(n);\n    }\n    if(n > root->val){\n        if(root->right == NULL){\n            root->right = new tree(n);\n        }\n        else{\n            tree_Add_Node_BST(root->right, n);\n        }\n    }\n    else{\n        if(root->left == NULL){\n            root->left = new tree(n);\n        }\n        else{\n            tree_Add_Node_BST(root->left, n);\n        }\n    }\n    return;\n}",{"Trees","trees"});
		 ListBox1->Items->Add("tree_formpreoandino_");
		 ill("tree_formpreoandino_", "tree* add_nodes(int preo[], int ino[], int end, int strt) {\n    static int itr = 6;\n    if(strt > end){\n        return NULL;\n    }\n    int curr = preo[itr];\n    tree* root = new tree(curr);\n    itr--;\n    if(strt == end){\n        return root;\n    }\n    int pos = search(ino, strt, end, curr);\n    root->right = add_nodes(preo, ino, end, pos + 1);\n    root->left = add_nodes(preo, ino, pos - 1, strt);\n}\n\nint search(int ino[], int strt, int end, int curr) {\n    for(int i = strt; i < end; i++){\n        if(ino[i] == curr){\n            return i;\n        }\n    }\n    return -1;\n}",{"Trees","trees"});
		 ListBox1->Items->Add("tree_search_");
		 ill("tree_search_", "int search(int ino[], int strt, int end, int curr) {\n    for(int i = strt; i < end; i++){\n        if(ino[i] == curr){\n            return i;\n        }\n    }\n    return -1;\n}",{"Trees","trees","search"});
		 ListBox1->Items->Add("tree_inorder_");
		 ill("tree_inorder_", "void tree_inorder(tree* root) {\n    if(root == NULL) {\n        return;\n    }\n    tree_inorder(root->left);\n    cout << root->val << \"\\n\";\n    tree_inorder(root->right);\n    return;\n}",{"trees","Trees"});
		 ListBox1->Items->Add("tree_node_count_");
		 ill("tree_node_count_", "int tree_nodecount(tree* root) {\n    if(root == NULL) {\n        return 0;\n    }\n    int count;\n    count = tree_nodecount(root->left) + tree_nodecount(root->right) + 1;\n    return count;\n}",{"trees","Trees"});
		 ListBox1->Items->Add("tree_level_");
		 ill("tree_level_", "void tree_level(tree* root) {\n    queue<tree*> q1;\n    q1.push(root);\n    q1.push(NULL);\n    while(!q1.empty()) {\n        tree* branch = q1.front();\n        q1.pop();\n        if(branch != NULL) {\n            cout << branch->val;\n            if(branch->left != NULL) {\n                q1.push(branch->left);\n            }\n            if(branch->right != NULL) {\n                q1.push(branch->right);\n            }\n        }\n        else if(!q1.empty()) {\n            q1.push(NULL);\n        }\n    }\n}",{"trees","Trees"});
		 ListBox1->Items->Add("tree_add_nodes_");
		 ill("tree_add_nodes_", "int tree_add_nodes(tree* root, int k) {\n    queue<tree*> q1;\n    q1.push(root);\n    q1.push(NULL);\n    int sum = 0, itr = 1;\n    while(!q1.empty()) {\n        tree* branch = q1.front();\n        q1.pop();\n        if(itr == k && branch != NULL) {\n            sum += branch->val;\n        }\n        if(branch != NULL) {\n            if(branch->left != NULL) {\n                q1.push(branch->left);\n            }\n            if(branch->right != NULL) {\n                q1.push(branch->right);\n            }\n        }\n        else if(!q1.empty()) {\n            q1.push(NULL);\n            itr++;\n        }\n    }\n    return sum;\n}",{"trees","Trees","add"});
		 ListBox1->Items->Add("tree_height_");
		 ill("tree_height_", "int tree_height(tree* root, int maxi, int itr) {\n    if(root != NULL) {\n        itr++;\n        maxi = max(itr, maxi);\n    }\n    else {\n        return maxi;\n    }\n    maxi = max(height(root->right, maxi, itr), maxi);\n    maxi = max(height(root->left, maxi, itr), maxi);\n    return maxi;\n}",{"trees","Trees"});
		 ListBox1->Items->Add("tree_diameter_");
		 ill("tree_diameter_", "int tree_diameter(tree* root) {\n    int lefty = 0, righty = 0;\n    lefty = left(root->left, 0);\n    righty = right(root->right, 0);\n    return lefty + righty + 1;\n}",{"trees","Trees"});
		 ListBox1->Items->Add("tree_count_left_");
		 ill("tree_count_left_", "int tree_count_left(tree* root, int count) {\n    if(root != NULL) {\n        count = tree_count_left(root->left, count);\n        count++;\n    }\n    return count;\n}",{"Trees","trees","counting","count","counts"});
		 ListBox1->Items->Add("tree_count_right_");
		 ill("tree_count_right_", "int tree_count_right(tree* root, int countr) {\n    if(root != NULL) {\n        countr = right(root->right, countr);\n        countr++;\n    }\n    return countr;\n}",{"Trees","trees","counting","count","counts"});
		 ListBox1->Items->Add("tree_checkBST_");
		 ill("tree_checkBST", "bool tree_checkBST(tree* root, int minimum, int maximum) {\n    if(root == NULL) {\n        return true;\n    }\n    if(root->val >= maximum || root->val <= minimum) {\n        return false;\n    }\n    return tree_checkBST(root->left, minimum, root->val) && tree_checkBST(root->right, root->val, maximum);\n}",{"Trees","trees","Binary","binary","Search","search"});
		 ill("Stack_Linked_List", "class Stack_Linked_List {\n    Node* top;\n\npublic:\n    Stack_Linked_List() { top = NULL; }\n\n    void push(int data) {\n\n        Node* temp = new Node(data);\n        if (!temp) {\n            cout << \"Stack Overflow\";\n            exit(1);\n        }\n        temp->data = data;\n\n        temp->link = top;\n\n        top = temp;\n    }\n\n    bool isEmpty() {\n        return top == NULL;\n    }\n\n    int peek() {\n        if (!isEmpty())\n            return top->data;\n        else\n            exit(1);\n    }\n\n    void pop() {\n        Node* temp;\n\n        if (top == NULL) {\n            cout << \"Stack Underflow\" << endl;\n            exit(1);\n        }\n        else {\n            temp = top;\n\n            top = top->link;\n\n            free(temp);\n        }\n    }\n\n    void display() {\n        Node* temp;\n\n        if (top == NULL) {\n            cout << \"Stack Underflow\";\n            exit(1);\n        }\n        else {\n            temp = top;\n            while (temp != NULL) {\n\n                cout << temp->data;\n\n                temp = temp->link;\n                if (temp != NULL)\n                    cout << \" -> \";\n            }\n        }\n    }\n};",{"stacks","Stacks","Linkedlist","LinkedList","linkedlist"});
		 ill("Stack_array", "#include <iostream>\nusing namespace std;\n\nclass stack_array {\n\npublic:\n    int top;\n    int top1;\n    int size;\n    int *arr;\n\n    stack_array(int size) {\n        this->size = size;\n        top = -1;\n        arr = new int[size];\n\n    }\n\n    void push(int element) {\n        if (top1 - top > 1) {\n            top++;\n            arr[top] = element;\n        }\n        else {\n            cout << \"Stack Overflow\" << endl;\n        }\n    }\n\n    void pop() {\n        if (top >= 0) {\n            top--;\n        }\n        else {\n            cout << \"Stack Underflow\" << endl;\n        }\n    }\n\n    void peek() {\n        if (top >= 0) {\n            cout << arr[top] << endl;\n        }\n        else {\n            cout << \"Stack is empty\" << endl;\n        }\n    }\n\n    void empty() {\n        if (top == -1) {\n            cout << \"Stack is empty\" << endl;\n        }\n        else {\n            cout << \"Stack is not empty\" << endl;\n        }\n    }\n};",{"Stacks","stacks","arrays","Arrays"});
		 ListBox1->Items->Add("Stack_Linked_List");
		 ListBox1->Items->Add("Stack_array");
		 ListBox1->Items->Add("linked_list_Traversal");
		 ill("linked_list_Traversal", "\n    while (node != NULL) {\n        cout << \"Elements: \" << node->data << endl;\n        node = node->next;\n    \n}",{"Linkedlist","LinkedList","linkedlist","traversing","travel","travelling","Travel","Travelling","traversals","Traversals"});
		 ListBox1->Items->Add("linked_list_insert_at_end");
		 ill("linked_list_insert_at_end", "LinkedList *p = node;\nLinkedList *ptr;\nptr = (class LinkedList*)malloc(sizeof(struct LinkedList));\nwhile((p->next)!=NULL){\n    p = p->next;\n}\np->next = ptr;\nptr->data = num;\nptr->next = NULL;\nreturn node;\n",{"Linkedlist","LinkedList","linkedlist","insertion","Inserts","inserts"});
         ListBox1->Items->Add("linked_list_insert_after_node");
		 ill("linked_list_insert_after_node", "LinkedList *ptr;\nptr = (class LinkedList *)malloc(sizeof(class LinkedList));\nptr -> data = num;\nptr -> next = PrevNode->next;\nPrevNode->next = ptr;\nreturn node;",{"Linkedlist","LinkedList","linkedlist","insertion","Inserts","inserts"});
		 ListBox1->Items->Add("linked_list_doubly_traversal");
		 ill("doubly_linked_list_traversal", "while(node != NULL) {\n    cout << \"Elements: \" << node->data << endl;\n    node = node->prev;\n}",{"double","Double","Linkedlist","LinkedList","linkedlist","travel","travelling","Travel","Travelling","traversals","Traversals"});
         ListBox1->Items->Add("linked_list_doubly_reverse_traversal");
		 ill("doubly_linked_list_reverse_traversal", "while(node != NULL) {\n    cout << \"Elements: \" << node->data << endl;\n    node = node->prev;\n}",{"double","Double","Linkedlist","LinkedList","linkedlist","travel","travelling","Travel","Travelling","traversals","Traversals"});
		 ListBox1->Items->Add("linked_list_delete_front");
		 ill("linked_list_delete_from_front", "LinkedList *ptr = node;\nnode = node->next;\nfree(ptr);\nreturn node;",{"Linkedlist","LinkedList","linkedlist","Deletion","deletes","Deletes","deletion","Deletions","deletions"});
		 ListBox1->Items->Add("linked_list_delete_back");
		 ill("linked_list_delete_back", "LinkedList *p = node;\nLinkedList *q = node->next;\nwhile(q->next != NULL) {\n    p = p->next;\n    q = q->next;\n}\np->next = NULL;\nfree(q);\nreturn node;",{"Linkedlist","LinkedList","linkedlist","Deletion","deletes","Deletes","deletion","Deletions","deletions","end"});
		 ListBox1->Items->Add("linked_list_delete_index");
		 ill("linked_list_delete_index", "LinkedList *p = node;\nLinkedList *q = node->next;\nint i = 0;\nwhile(i != (index - 1)) {\n    p = p->next;\n    q = q->next;\n    i++;\n}\np->next = q->next;\nfree(q);\nreturn node;",{"Linkedlist","LinkedList","linkedlist","Deletion","deletes","Deletes","deletion","Deletions","deletions"});
         ListBox1->Items->Add("doubly_linked_list_search_delete");
		 ill("doubly_linked_list_search_delete", "if (node == NULL) {\n    cout << \"List is empty\" << endl;\n    return node;\n}\nDoublyLinkedList *p = node;\nwhile (p != NULL && p->data != value) {\n    p = p->next;\n}\nif (p == NULL) {\n    cout << \"Value not found\" << endl;\n    return node;\n}\nif (p->prev != NULL) {\n    p->prev->next = p->next;\n}\nelse {\n    node = p->next;\n}\nif (p->next != NULL) {\n    p->next->prev = p->prev;\n}\nfree(p);\nreturn node;",{"Linkedlist","LinkedList","linkedlist","Deletion","deletes","Deletes","Searching","searching","deletion","Searches","searches","double"});
		 ListBox1->Items->Add("doubly_linked_list_index_delete");
		 ill("doubly_linked_list_index_delete", "if (index < 0) {\n    cout << \"Invalid index\" << endl;\n    return node;\n}\nif (node == NULL) {\n    cout << \"List is empty\" << endl;\n    return node;\n}\nif (index == 0) {\n    DoublyLinkedList *q = node;\n    node = node->next;\n    if (node != NULL) {\n        node->prev = NULL;\n    }\n    delete q;\n    return node;\n}\nDoublyLinkedList *p = node;\nint i = 0;\nwhile (p != NULL && i < (index-1)) {\n    p = p->next;\n    i++;\n}\nif (p == NULL || p->next == NULL) {\n    cout << \"Index out of range\" << endl;\n    return node;\n}\nDoublyLinkedList *q = p->next;\np->next = q->next;\nif (q->next != nullptr) {\n    q->next->prev = p;\n}\ndelete q;\nreturn node;",{"Linkedlist","LinkedList","linkedlist","Deletion","deletes","Deletes","deletion","double"});
		  ListBox1->Items->Add("doubly_linked_list_delete_last");
		  ill("doubly_linked_list_delete_last", "DoublyLinkedList *p = node;\nwhile (p->next != NULL) {\n    p = p->next;\n}\np->prev->next = NULL;\ndelete p;\nreturn node;",{"Linkedlist","LinkedList","linkedlist","Deletion","deletes","Deletes","deletion","double","end"});
		  ListBox1->Items->Add("doubly_linked_list_delete_first");
		  ill("doubly_linked_list_delete_first", "DoublyLinkedList *q = node->next;\nq->prev = NULL;\ndelete node;\nreturn q;",{"Linkedlist","LinkedList","linkedlist","Deletion","deletes","Deletes","deletion","double","front"});
          ListBox1->Items->Add("doubly_linked_list_insert_index");
		  ill("doubly_linked_list_insert_index", "int i = 0;\nDoublyLinkedList *p = (class DoublyLinkedList *)malloc(sizeof(class DoublyLinkedList));\nDoublyLinkedList *q = node;\nwhile (i != (index - 1)) {\n    q = q->next;\n    i++;\n}\np->data = value;\np->prev = q;\np->next = q->next;\nif (q->next != NULL) {\n    q->next->prev = p;\n}\nq->next = p;\nreturn node;",{"Linkedlist","LinkedList","linkedlist","Insertion","inserts","Inserts","insertion","double"});
          ListBox1->Items->Add("doubly_linked_list_insert_first");
		  ill("doubly_linked_list_insert_first", "DoublyLinkedList *p = (class DoublyLinkedList *)malloc(sizeof(class DoublyLinkedList));\np->data = value;\np->next = node;\np->prev = NULL;\nif (node != NULL) {\n    node->prev = p;\n}\nreturn p;",{"Linkedlist","LinkedList","linkedlist","Insertion","inserts","Inserts","insertion","double","start","Start"});
          ListBox1->Items->Add("doubly_linked_list_insert_last");
		  ill("doubly_linked_list_insert_last", "DoublyLinkedList *p = (class DoublyLinkedList *)malloc(sizeof(class DoublyLinkedList));\nDoublyLinkedList *q = node;\np->data = value;\np->next = NULL;\nwhile (q->next != NULL) {\n    q = q->next;\n}\nq->next = p;\np->prev = q;\nreturn node;",{"Linkedlist","LinkedList","linkedlist","Insertion","inserts","Inserts","insertion","double","end","End"});
		  ListBox1->Items->Add("circular_linked_list_traversal");
		  ill("circular_linked_list_traversal", "CircularLinkedList *p = node;\ndo {\n    cout << \"Elements: \" << node->data << endl;\n    node = node->next;\n} while (node != p);",{"Linkedlist","LinkedList","linkedlist","Travel","travel","Traversing","traversing"});
          ListBox1->Items->Add("circular_linked_list_insert_head");
		  ill("circular_linked_list_insert_head", "CircularLinkedList *q = node;\nCircularLinkedList *p;\np = (class CircularLinkedList*)malloc(sizeof(class CircularLinkedList));\np->data = value;\np->next = node;\ndo {\n    node = node->next;\n} while (node->next != q);\nnode->next = p;\nreturn p;",{"Linkedlist","LinkedList","linkedlist","Insertion","inserts","Inserts","insertion","double","end","End"});
		  ListBox1->Items->Add("vector_input");
		  ill("vector_input", "int n;\ncout << \"Enter the Number of Elements in the Vector: \";\ncin >> n;\nvector<int> v(n);\nvector<int>::iterator i;\nfor (i = v.begin(); i != v.end(); ++i) {\n    cout << \"Enter Element at index \" << i << \": \";\n    cin >> (*i);\n}",{"Vectors","vectors","insertion","insert","Inputs","inputs","insertions","inserts"});
		  ListBox1->Items->Add("vector_output");
		  ill("vector_output", "for (int i = 0; i < v.size(); ++i) {\n    cout << v[i] << \" \";\n}\n\n// Adding newline after outputting all elements\n// This newline is added after the loop to maintain consistent formatting\ncout << endl;",{"Vectors","vectors","outputs","Outputs"});
          ListBox1->Items->Add("vector_get_minimum");
		  ill("vector_get_minimum", "int minEle = INT_MIN;\nfor (int i = 0; i < v.size(); ++i) {\n    minEle = min(minEle, v[i]);\n}\n\n// Returning the minimum element\nreturn minEle;",{"Vectors","vectors","least","lowest","min","Least","Lowest","Min"});
		  ListBox1->Items->Add("vector_get_maximum");
		  ill("vector_get_maximum", "    int maxEle = INT_MAX;\nfor (int i = 0; i < v.size(); ++i) {\n    maxEle = min(maxEle, v[i]);\n}\n\n// Returning the maximum element\nreturn maxEle;",{"Vectors","vectors","max","Max","Highest","highest","Greatest","greatest"});
		  ListBox1->Items->Add("vector_get_total");
		  ill("vector_get_total", "long long int sum = 0;\nfor (int i = 0; i < v.size(); ++i) {\n    sum += v[i];\n}\n\n// Returning the total sum\nreturn sum;",{"Vectors","vectors","Sum","sum","Totals","totals","sums","Sums"});
		  ListBox1->Items->Add("vector_get_average");
		  ill("vector_get_average", "double sum = 0;\nfor (int i = 0; i < v.size(); ++i) {\n    sum += v[i];\n}\n\n// Calculating the average\nreturn (sum / v.size());",{"Vectors","vectors","Averaging","averaging","Averages","averages"});
		  ListBox1->Items->Add("vector_reverse");
		  ill("vector_reverse", "int right = 0;\nint left = v.size() - 1;\nwhile (right < left) {\n    swap(v[right], v[left]);\n    right++;\n    left--;\n}",{"vectors","Vectors","reversing","Reversing"});
		  ListBox1->Items->Add("vector_sort_bubble");
		  ill("vector_sort_bubble", "int n = v.size();\nfor (int i = 0; i < n - 1; i++) {\n    bool isSorted = false;\n    for (int j = 0; j < n - i - 1; ++j) {\n        if (v[j] > v[j + 1]) {\n            swap(v[j], v[j + 1]);\n            isSorted = true;\n        }\n    }\n    if (isSorted == false) {\n        return;\n    }\n}\nreturn;",{"Vectors","vectors","sorting","Sorting","sorts","Sorts"});
		  ListBox1->Items->Add("vector_search_linear");
		  ill("vector_search_linear", "for (int i = 0; i < v.size(); ++i)\n{\n    if (v[i] == target)\n    {\n        return i;\n    }\n}\n\nreturn -1;",{"Vectors","vectors","searches","Searches"});
		  ListBox1->Items->Add("vector_search_linear_recursive");
		  ill("vector_search_linear_recursive", "if (index == arr.size()) {\n    return -1;\n}\nif (arr[index] == target) {\n    return index;\n}\nreturn linearSearchRecursive(arr, target, index + 1);",{"Vectors","vectors","searches","Searches","Recursion","recursion"});
		  ListBox1->Items->Add("vector_sort_quick");
		  ill("vector_sort_quick", "if (first < last) {\n    int partitionIdx = partition(v, first, last);\n    quickSort(v, first, partitionIdx - 1);\n    quickSort(v, partitionIdx + 1, last);\n}",{"Vectors","vectors","sorts","Sorts","Sorting","sorting"});
		  ListBox1->Items->Add("vector_sort_count");
		  ill("vector_sort_count", "int arraySize = inputArray.size();\nif (arraySize <= 1) {\n    return;\n}\nint maxElement = INT_MIN;\nfor (int i = 0; i < arraySize; ++i) {\n    if (maxElement < inputArray[i])\n        maxElement = inputArray[i];\n}\nvector<int> elementCount(maxElement + 1, 0);\nfor (int i = 0; i < arraySize; ++i) {\n    elementCount[inputArray[i]] += 1;\n}\nfor (int i = 1; i <= maxElement; ++i) {\n    elementCount[i] += elementCount[i - 1];\n}\nvector<int> sortedArray(arraySize);\nfor (int i = arraySize - 1; i >= 0; --i) {\n    sortedArray[--elementCount[inputArray[i]]] = inputArray[i];\n}\nfor (int i = 0; i < arraySize; ++i) {\n    inputArray[i] = sortedArray[i];\n}",{"Vectors","vectors","sorts","Sorts","Sorting","sorting"});
		  ListBox1->Items->Add("vector_sort_bucket");
		  ill("vector_sort_bucket", "int arraySize = inputArray.size();\nvector<vector<float>> buckets(arraySize, vector<float>());\nfloat maxValue = INT_MIN;\nfloat minValue = INT_MAX;\nfor (int i = 0; i < arraySize; ++i) {\n    if (maxValue < inputArray[i])\n        maxValue = inputArray[i];\n    if (minValue > inputArray[i])\n        minValue = inputArray[i];\n}\nfloat range = (maxValue - minValue) / arraySize;\nfor (int i = 0; i < arraySize; ++i) {\n    int bucketIndex = (inputArray[i] - minValue) / range;\n    float fractionalPart = (inputArray[i] - minValue) / range - bucketIndex;\n    if (fractionalPart == 0 && inputArray[i] != minValue)\n        bucketIndex -= 1;\n    buckets[bucketIndex].push_back(inputArray[i]);\n}\nfor (int i = 0; i < arraySize; ++i) {\n    sort(buckets[i].begin(), buckets[i].end());\n}\nint currentIndex = 0;\nfor (int i = 0; i < arraySize; ++i) {\n    for (int j = 0; j < buckets[i].size(); ++j) {\n        inputArray[currentIndex++] = buckets[i][j];\n    }\n}",{"Vectors","vectors","sorts","Sorts","Sorting","sorting"});
		  ListBox1->Items->Add("vector_sort_radix");
		  ill("vector_sort_radix", "int arraySize = inputArray.size();\nif (arraySize == 0) {\n    return;\n}\nint maxElement = INT_MIN;\nfor (int i = 0; i < arraySize; ++i) {\n    maxElement = max(maxElement, inputArray[i]);\n}\nfor (int position = 1; position <= maxElement; position *= 10) {\n    int digitFrequency[10] = {0};\n    for (int i = 0; i < arraySize; i++) {\n        digitFrequency[(inputArray[i] / position) % 10]++;\n    }\n    for (int i = 1; i < 10; ++i) {\n        digitFrequency[i] += digitFrequency[i - 1];\n    }\n    vector<int> sortedArray(arraySize, 0);\n    for (int i = arraySize - 1; i >= 0; --i) {\n        sortedArray[--digitFrequency[(inputArray[i] / position) % 10]] = inputArray[i];\n    }\n    for (int i = 0; i < arraySize; ++i) {\n        inputArray[i] = sortedArray[i];\n    }\n}",{"Vectors","vectors","sorts","Sorts","Sorting","sorting"});
		  ListBox1->Items->Add("vector_rotate_k");
		  ill("vector_rotate_k", "int n = v.size();\nk = k % n;\nint low = 0;\nint high = n - 1;\nwhile (low < high) {\n    swap(v[low], v[high]);\n    low++;\n    high--;\n}\nlow = 0;\nhigh = k - 1;\nwhile (low < high) {\n    swap(v[low], v[high]);\n    low++;\n    high--;\n}\nlow = k;\nhigh = n - 1;\nwhile (low < high) {\n    swap(v[low], v[high]);\n    low++;\n    high--;\n}",{"Vectors","vectors","Rotates","rotates","Rotation","rotation"});
		  ListBox1->Items->Add("vector_count_occurence");
		  ill("vector_count_occurence", "int count = 0;\nfor (int i = 0; i < v.size(); ++i) {\n    if (v[i] == target) {\n        count++;\n    }\n}\nreturn count;",{"Vectors","vectors","counting","Counting","counts","Counts","occurences","Occurences"});
		  ListBox1->Items->Add("vector_matrix_input");
		  ill("vector_matrix_input", "int rows, cols;\ncout << \"Enter the number of rows: \";\ncin >> rows;\ncout << \"Enter the number of columns: \";\ncin >> cols;\nvector<vector<int>> matrix(rows, vector<int>(cols));\nfor (int i = 0; i < rows; ++i) {\n    for (int j = 0; j < cols; ++j) {\n        cout << \"Enter the element at position (\" << i << \", \" << j << \"): \";\ncin >> matrix[i][j];\n    }\n}",{"Vectors","vectors","Matrices","matrices","Inputs","inputs"});
		  ListBox1->Items->Add("check_Palindrome");
		  ill("check_Palindrome", "for (int right = 0, left = v.size() - 1; right < left; right++, left--)\n{\n    if (v[right] != v[left])\n    {\n        return false;\n    }\n}\nreturn true;",{"Checks","checks","Palindromes","palindromes"});
		  ListBox1->Items->Add("array_shuffle");
		  ill("array_shuffle", "int n = arr.size();\n\nfor (int i = n - 1; i > 0; --i)\n{\n    int j = rand() % (i + 1);\n    swap(arr[i], arr[j]);\n}",{"shuffles","Shuffling","Shuffles","shuffling","arrays","Arrays"});

}

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	vector <pair<int,String>> sorter;
	vector <String> words;
	ListBox2->Clear();
	UnicodeString str = Edit3->Text;
	int itr = 1;
	UnicodeString word;
	while (itr <= str.Length()) {
		if(('a' <= str[itr] && str[itr] <= 'z')||('A' <=str[itr] && str[itr] <= 'Z')|| str[itr] == ' ') {

		}
		else{
			if(itr ==  str.Length()){
			   words.push_back(word);
			   break;
			}
			++itr;
			continue;
        }
		if (itr == str.Length() || str[itr] == ' ') {
			if(itr == str.Length() && str[itr] == ' '){
               words.push_back(word);
			   word = "";
			   break;
			}
			if(itr == str.Length()){
			   word += str[itr];
			}
			words.push_back(word);
			word = "";
		}
		else {
			word += str[itr];
		}
		++itr;
	}
	for(char trav = 'a'; trav <= 'z'; ++trav){
		if(Hash[trav-'a' + 1] == NULL){
		   continue;
		}
		Snippet *rnr = Hash[trav - 'a' + 1];
		while(rnr != NULL){
			  int points = 0;
			  String x = rnr->key;
			  vector<String> cut;
			  String temp = "";
			  for(int i = 1; i <= x.Length(); ++i){
				  if(x[i] == '_'){
					 cut.push_back(temp);
					 temp = "";
					 continue;
				  }
				  if(i == x.Length() && x[i] != '_'){
					 temp += x[i];
					 cut.push_back(temp);
					 temp = "";
					 break;
				  }
				  temp += x[i];
			  }
			  vector<String>::iterator word_search,synsearch,ksearch = cut.begin();
			  for(synsearch = rnr->synonyms.begin(); synsearch != rnr->synonyms.end(); ++synsearch){
				  for(word_search = words.begin(); word_search != words.end(); ++word_search){
					  if(*word_search == *synsearch){
						  ++points;
					  }
				  }
			  }
			  for(ksearch = cut.begin(); ksearch != cut.end(); ++ksearch){
				  for(word_search = words.begin(); word_search != words.end(); ++word_search){
					  if(*word_search == *ksearch){
						  ++points;
					  }
				  }
			  }
			  if(points > 0){
				 sorter.push_back({points,rnr->key});
			  }
			  rnr = rnr->next;
		}
	}
	sort(sorter.begin(),sorter.end());
	vector <pair<int,String>>::iterator paste;
	stack <String> rev;
	for(paste = sorter.begin(); paste != sorter.end(); ++paste){
		if(paste->second == ""){
		   continue;
		}
		rev.push(paste->second);
	}
	while(!rev.empty()){
		 ListBox2->Items->Add(rev.top());
		 rev.pop();
	}
}
void __fastcall TForm1::Find2(TCustomListBox * const Sender, TListBoxItem * const Item)

{
	  String key = Item->Text;
	  latest_key = key;
	  String code = search(key);
	  latestindex = Item->Index;
	  Memo2->Text = code;
}
void search_delete(String key){
	  latest_key = key;
	  Snippet *rnr, *prev;
	  if(key[1] <= 'z' && key[1] >= 'a'){
		 rnr = Hash[key[1]-'a' + 1];
		 prev = Hash[key[1]-'a' + 1];
         if(rnr->key == key){
			Hash[key[1]-'a' + 1] = Hash[key[1]-'a' + 1]->next;
			delete(rnr);
			return ;
		 }
	  }
	  else if(key[1]>= 'A' && key[1] <= 'Z'){
		 rnr = Hash[key[1]-'A' + 1];
		 prev = Hash[key[1]-'A' + 1];
		 if(rnr->key == key){
			Hash[key[1]-'A' + 1] = Hash[key[1]-'A' + 1]->next;
			delete(rnr);
			return ;
		 }
	  }
	  while(rnr->next != NULL){
		   prev = rnr;
		   rnr = rnr->next;
		   if(rnr->key == key){
			  prev->next = rnr->next;
			  delete(rnr);
			  break;
		   }
	  }
}

void __fastcall TForm1::Button5Click(TObject *Sender)
{
		if(latest_key == ""){
		   Memo2->Text = "Please select an item from thhe item list to delete";
		   return;
		}
		search_delete(latest_key);
		ListBox1->Items->Delete(latestindex);
		Memo2->Text = "";
		latest_key = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
		String x = editor(latest_key,Memo2->Text);
		if(x != "Done"){
		   Memo2->Text = "You must select an item from the list boxes to edit";
		}

}
//---------------------------------------------------------------------------



