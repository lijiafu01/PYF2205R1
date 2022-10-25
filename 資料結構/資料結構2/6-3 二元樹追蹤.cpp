#include <iostream>
#include <iomanip>
#include <queue>
#include <math.h>
using namespace std;

class TreeNode
{
public:
	friend class BinTree;
	TreeNode(int a) {data = a; leftChild = rightChild = 0;};
private:
	int data;
	TreeNode *leftChild;
	TreeNode *rightChild;
};
class BinTree
{
    public:
    BinTree() :root(0) {};
	void BuildTree(int data[], int n);
	void Inorder(TreeNode*);
	void Preorder(TreeNode*);
	void Postorder(TreeNode*);
	void Plot();
	
    private:
    TreeNode *root;
    
};
void BinTree::BuildTree(int data[], int n)
{
	TreeNode* current = 0;
	TreeNode* parent = 0;
	for (int i = 0; i < n; i++)
	{
		if (root == NULL) {
			TreeNode* newNode = new TreeNode(data[i]);
			root = newNode;
		}
		else {
			TreeNode* newNode = new TreeNode(data[i]);
			current = root;
			while (current != 0) {
				parent = current;
				if (current->data > data[i])
					current = current->leftChild;
				else
					current = current->rightChild;
			}
			if (parent->data > data[i])
				parent->leftChild = newNode;

			else
				parent->rightChild = newNode;
		}

	}
}
void BinTree::Inorder(TreeNode* a)
{
	
		if (a != 0)
		{
    		Inorder(a->leftChild);
    		cout << a->data << " ";
    		Inorder(a->rightChild);
		}
	
}
void BinTree::Preorder(TreeNode* a)
{
	if (a != 0)
	{
    	cout << a->data << " ";
    	Preorder(a->leftChild);
    	Preorder(a->rightChild);
	}
}
void BinTree::Postorder(TreeNode* a)
{
    if (a != 0)
    {
    	Postorder(a->leftChild);
    	Postorder(a->rightChild);
    	cout << a->data << " ";
    }
}
void BinTree::Plot() {
	Inorder(root);
		cout << '\n';
		Preorder(root);
		cout << '\n';
		Postorder(root);
}


int main(int argc, char *argv[])
{   
    BinTree tree1;
    int n;
    cin >> n;
    int *data = new int[n];
    for (int i = 0; i < n; i++) cin >> data[i];
    
    tree1.BuildTree(data, n);
	tree1.Plot();
	
}
