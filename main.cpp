#include <iostream>
#include <iomanip>
using namespace std;

class BST
{
private:
	struct Node
	{
		int key;
		Node* left;
		Node* right;
		Node* parent;
	};
	Node* root;

	Node* FindNode(int key)
	{
		Node* curr = root;
		if (root != nullptr)
		{
			while (curr != nullptr)
			{
				if (key == curr->key)
				{
					break;
				}
				else if (key > curr->key)
				{
					if (curr->right != nullptr)
					{
						curr = curr->right;
					}
					else
					{
						curr = nullptr;
						break;
					}
				}
				else
				{
					if (curr->left != nullptr)
					{
						curr = curr->left;
					}
					else
					{
						curr = nullptr;
						break;
					}
				}
			}
		}
		return curr;
	}
public:
	BST()
	{
		root = nullptr;
	}
	~BST()
	{

	}

	void Add_elem(int key)
	{
		Node* t = new Node;
		t->key = key;
		if (root == nullptr)
		{
			root = t;
			t->right = nullptr;
			t->left = nullptr;
			t->parent = nullptr;
		}
		else
		{
			Node* curr = root;
			while (curr)
			{
				if (t->key < curr->key)
				{
					if (curr->left != nullptr)
					{
						curr = curr->left;
					}
					else
					{
						curr->left = t;
						t->right = nullptr;
						t->left = nullptr;
						t->parent = curr;
						break;
					}
				}
				else if(t->key > curr->key)
				{
					if (curr->right != nullptr)
					{
						curr = curr->right;
					}
					else
					{
						curr->right = t;
						t->right = nullptr;
						t->left = nullptr;
						t->parent = curr;
						break;
					}
				}
				else
				{
					cout << "This element [" << t->key << "] has already added in the Tree!\n";
					break;
				}
			}
		}
	}

	void Find(int key)
	{
		Node* t = root;
		if (root == nullptr)
		{
			cout << "This Tree is empty!\n";
		}
		else
		{
			while (t)
			{
				if (t->key == key)
				{
					cout << "Element [" << key << "] find\n";
					break;
				}
				else if (key < t->key)
				{
					if (t->left != nullptr)
					{
						t = t->left;
					}
					else
					{
						cout << "Element [" << key << "] not find!\n";
						break;
					}
				}
				else
				{
					if (t->right != nullptr)
					{
						t = t->right;
					}
					else
					{
						cout << "Element [" << key << "] not find!\n";
						break;
					}
				}

			}
		}
	}

	void Delete_node(int key)
	{
		Node* curr = FindNode(key);
		//Node without child
		if (curr->left == nullptr && curr->right == nullptr)
		{
			if ((curr->parent)->left == curr)
			{
				(curr->parent)->left = nullptr;
			}
			else
			{
				(curr->parent)->right = nullptr;
			}
			delete curr;
			return;
		}
		//Node with single child
		if ((curr->left == nullptr && curr->right != nullptr) || (curr->left != nullptr && curr->right == nullptr))
		{
			if (curr->left == nullptr && curr->right != nullptr)
			{
				(curr->parent)->left = curr->right;
				delete curr;
			}
			else if (curr->left != nullptr && curr->right == nullptr)
			{
				(curr->parent)->right = curr->left;
				delete curr;
			}
			return;
		}
	}

};

int main()
{
	BST t;

	t.Add_elem(50);
	t.Add_elem(76);
	t.Add_elem(21);
	t.Add_elem(4);
	t.Add_elem(32);
	t.Add_elem(64);
	t.Add_elem(15);
	t.Add_elem(52);
	t.Add_elem(14);
	t.Add_elem(100);
	t.Add_elem(83);
	t.Add_elem(2);
	t.Add_elem(3);
	t.Add_elem(70);
	t.Add_elem(87);
	t.Add_elem(80);

	t.Delete_node(2);
	t.Delete_node(15);

}