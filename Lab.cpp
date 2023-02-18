#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

bool Search(struct Node* root, int key){
	while (root != NULL) {
		if (key > root->data)
			root = root->right;

		else if (key < root->data)
			root = root->left;
		else
			return true; 
	}
	return false;
}

struct Node* newNode(int item){
	struct Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct Node* insert(struct Node* Node, int data){
	if (Node == NULL)
		return newNode(data);

	if (data < Node->data)
		Node->left = insert(Node->left, data);
	else if (data > Node->data)
		Node->right = insert(Node->right, data);

	return Node;
}

int main(){
	struct Node* root = NULL;
    int i, n;
    cout<<"Enter the number of elements you want to insert: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements: "<<endl;
    for(i=0; i<n; i++){
        cin>>a[i];
    }

    for(i=0; i<n; i++){
        root = insert(root, a[i]);
    }

    int s;
    cout<<"Enter the number you want to search: ";
    cin>>s;
    if (Search(root, s))
		cout << "The number is found!";
	else
		cout << "The number is not found!";
	return 0;
}
