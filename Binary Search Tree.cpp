#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

class BST{
        public:
			Node* insert(int x, Node* root);	//Insert a new node at the beginning
			Node* dltNode(int d, Node* root);	//Delete a given node from the tree
			void printPreOrder(Node* root);		//Print pre-order traversal
			void printInorder(Node* root);		//Print in-order traversal
			void printPostorder(Node* root);	//Print post-order traversal
			Node*searchVal(Node*root, int f);	//function to search a value
			unsigned int numOfNodes( Node* root); //Count the number of nodes
			int bstHeight(Node* root);		//Get the height of the tree
			int searchMin(Node* root);		//Search the smallest element
			int searchMax(Node* root);		//Search the largest element
			void dltall(Node* root);		//Delete entire tree
			Node* findmin( Node* root);		//Find the min value
    };

Node* BST::insert(int x, Node* root)
	{
		if (root == NULL)
		{
			root = new Node;
			root->data = x;
			root->left = root->right = NULL;
		}
		else if (x < root->data)
			root->left = insert(x, root->left);
		else if (x > root->data)
			root->right = insert(x, root->right);
		return root;
	}


struct Node* BST::dltNode(int d, Node* root) {
	if (root == NULL)
		printf("Tree is Empty\n");
	else if (d < root->data)
		root->left = dltNode(d, root->left);
	else if (d > root->data)
		root->right = dltNode( d, root->right);
	else {
		// No child
		if (root->left == NULL && root->right == NULL) {
			free(root);
			root = NULL;
		}
		// One child
		else if (root->left == NULL) {
			Node* temp = root;
			root = root->right;
			free(temp);
		}
		else if (root->right == NULL) {
			Node* temp = root;
			root = root->left;
			free(temp);
		}
		// 2 children
		else {
			Node* temp = findmin(root->right);
			root->data = temp->data;
			root->right = dltNode(temp->data, root->right);
		}
	}
	return root;
}

void BST::printPreOrder(Node* root) {
	Node* temp = root;
	if (root != NULL)
	{
		cout << temp->data << " ";
		printPreOrder(temp->left);
		printPreOrder(temp->right);
	}
}

//printing in-order traversal
void BST::printInorder(Node* root) {
	if (root != NULL)
	{
		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);
	}
}

//printing post-order traversal
void BST::printPostorder(Node* root) {
	if (root == NULL)
	{
		return;
	}
	if (root)
	{
		printPostorder(root->left);
		printPostorder(root->right);
		cout << root->data << " ";
	}
}

//function to search a value
Node* BST::searchVal(Node*root, int f)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (root -> data == f)
	{
		return root;
	}
	else
	{
		if (f < root->data)
		{
			return searchVal(root->left, f);
		}
		else
		{
			return searchVal(root->right, f);
		}
	}
}

//function to count number of nodes
unsigned BST::numOfNodes(Node* root) {
	unsigned int count = 1;
	if (root->left != NULL) {
		count += numOfNodes(root->left);
	}
	if (root->right != NULL) {
		count += numOfNodes(root->right);
	}
	return count;
}

//function to get height of the tree
int BST::bstHeight(Node* root) {
	if (root == NULL)
		return 0;
	else {
		int lHeight = bstHeight(root->left);
		int rHeight = bstHeight(root->right);
		if (lHeight >= rHeight)
			return lHeight + 1;
		else
			return rHeight + 1;
	}
}

//function to get minimum value
int BST::searchMin(Node* root) {
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root->data;
}

//function to get maximum value
int BST::searchMax(Node* root) {
	while (root->right != NULL)
	{
		root = root->right;
	}
	return root->data;
}

//function to delete the tree
void BST::dltall(Node* root) {
	struct Node* temp = root;
	if (temp == NULL)
		return;
	dltall(temp->left);
	dltall(temp->right);
	free(temp);
}


Node* BST::findmin(Node* root) {
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

int main() {

	BST tree;
	Node* root = NULL;
	int n,val;
	cout << "Enter the Number of nodes in the Tree : ";
	cin >> n;

	cout << "Enter Elements : ";
	for (int i = 0; i <n; i++)
	{
		cin >> val;		//getting user input values
		root = tree.insert(val, root);	//add those values to the tree
	}


	while (1) {

		cout << endl;
		cout << " 1 - Insert Node\n";
		cout << " 2 - Delete Node\n";
		cout << " 3 - Print Pre-order\n";
		cout << " 4 - Print In-Order\n";
		cout << " 5 - Print Post-Order\n";
		cout << " 6 - Search a value\n";
		cout << " 7 - Count no.of Nodes\n";
		cout << " 8 - BST Height\n";
		cout << " 9 - Search Min Value\n";
		cout << " 10 - Search Max Value\n";
		cout << " 11 - Delete tree\n";
		cout << " 0 - Exit\n";

		int choice;
		cout << "Enter Your Choice : ";
		cin >> choice;
		cout << endl;

		switch (choice) {
			case 1: {
			//cout << "******Insert Node******\n";
			int data;
			cout << "Enter the Element to Insert : ";
			cin >> data;
			tree.insert(data, root);
			cout << endl;
			break;
			}
			case 2: {
				int x;
				cout << "Enter Element to Delete : ";
				cin >> x;
				tree.dltNode(x, root);
				cout << endl;
				break;
			}

			case 3: {
				cout << "\tPrint Pre-order : ";
				tree.printPreOrder(root);
				cout << endl;
				break;
			}
			case 4: {
				cout << "\tPrint In-order : ";
				tree.printInorder(root);
				cout << endl;
				break;
			}
			case 5: {
				cout << "\tPrint Post-Order : ";
				tree.printPostorder(root);
				cout << endl;
				break;
			}
			case 6: {
				int val;
				cout << "\tEnter the value to search : ";
				cin >> val;
				cout << "\nSearched value address : "<<tree.searchVal(root,val);
				cout << endl;
				break;
			}

			case 7: {
				cout << "\tNo. of Nodes = ";
				cout << tree.numOfNodes(root);
				cout << endl;
				break;
			}
			case 8: {
				cout << "\tBST Height is  ";
				cout << tree.bstHeight(root);
				cout << endl;
				break;
			}
			case 9: {
				cout << "\tMin Value is  ";
				cout << tree.searchMin(root);
				cout << endl;
				break;
			}
			case 10: {
				cout << "\tMax Value is   ";
				cout << tree.searchMax(root);
				cout << endl;
				break;
			}
			case 11: {
				tree.dltall(root);
				cout << "The tree was deleted\n\n";
				root = NULL;
				break;
			}

			default: {
				cout << endl;
				system("pause");
				return 0;
			}
		}
	}

	system("pause");
	
}




	