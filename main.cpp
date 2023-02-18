#include <iostream>
#include <iomanip>
#include <math.h>
#include <queue>
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
	Node* FindNodePrivate(int key)
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
				else if(key < curr->key)
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

	void Delete_NodePrivate(Node* t)
	{
		if (t != nullptr)
		{
			Delete_NodePrivate(t->right);
			Delete_NodePrivate(t->left);
			delete t;
		}
	}


public:
	BST()
	{
		root = nullptr;
	}
	~BST()
	{
		Delete_Tree();
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
					//throw new runtime_error("This element has already added in the Tree!");
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
		Node* curr = FindNodePrivate(key);
		//A non existent element
		if (curr == nullptr)
		{
			cout << "This element is not in the tree!" << endl;
			return;
		}

		//Node without child
		if (curr->left == nullptr && curr->right == nullptr)
		{
			if (curr->parent == nullptr)
			{
				delete curr;
				root = nullptr;
				return;
			}
			else
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
			
		}
		//Node with single child
		if ((curr->left == nullptr && curr->right != nullptr) || (curr->left != nullptr && curr->right == nullptr))
		{
			/*if (curr->left == nullptr && curr->right != nullptr)
			{
				(curr->parent)->left = curr->right;
				delete curr;
			}
			else if (curr->left != nullptr && curr->right == nullptr)
			{
				(curr->parent)->right = curr->left;
				delete curr;
			}*/
			if (curr->left == nullptr && curr->right != nullptr)
			{
				if (curr->parent->left == curr)
				{
					curr->parent->left = curr->right;
					delete curr;
				}
				else if(curr->parent->right == curr)
				{
					curr->parent->right = curr->right;
					delete curr;
				}
			}
			else if (curr->left != nullptr && curr->right == nullptr)
			{
				if (curr->parent->left == curr)
				{
					curr->parent->left = curr->left;
					delete curr;
				}
				else if (curr->parent->right == curr)
				{
					curr->parent->right = curr->left;
					delete curr;
				}
			}
			
			return;
		}
		//Node with two child
		if (curr->left != nullptr && curr->right != nullptr)
		{
			Node* ch = curr->right;
			if ((ch->left == nullptr) && (ch->right == nullptr))
			{
				curr->key = ch->key;
				curr->right = nullptr;
				delete ch;
			}
			else
			{
				if ((curr->right)->left != nullptr)
				{
					Node* lcurr = (curr->right)->left;
					while (lcurr->left != nullptr)
					{
						lcurr->parent = curr->right;
						lcurr = lcurr->left;
					}
					curr->key = lcurr->key;
					(lcurr->parent)->left = nullptr;
					delete lcurr;
					
				}
				else
				{
					Node* tmp = curr->right;
					curr->key = tmp->key;
					curr->right = tmp->right;
					delete tmp;
				}
			}
			return;
		}
	}

	void Delete_Tree()
	{
		if (root != nullptr)
		{
			Node* t = root;
			Delete_NodePrivate(root);
			root = nullptr;
		}
		else
		{
			cout << "This Tree is empty!\n";
		}
	}

	void Min_Value()
	{
		Node* x = root;
		if (x == nullptr)
		{
			cout << "This list is empty!\n";
		}
		else
		{
			if (x->left != nullptr)
			{
				while (1)
				{
					if (x->left != nullptr)
					{
						//x->left->parent = x;
						x = x->left;
					}
					else
					{
						cout << "Min elem = [" << x->key << "].\n";
						return;
					}
				}
			}
			else
			{
				cout << "Min elem = [" << x->key << "].\n";
			}
		}
	}

	void Max_Value()
	{
		Node* x = root;
		if (x == nullptr)
		{
			cout << "This list is empty!\n";
		}
		else
		{
			if (x->right != nullptr)
			{
				while (1)
				{
					if (x->right != nullptr)
					{
						//x->right->parent = x;
						x = x->right;
					}
					else
					{
						cout << "Max elem = [" << x->key << "].\n";
						return;
					}
				}
			}
			else
			{
				cout << "Max elem = [" << x->key << "].\n";
			}
		}
	}

	void Print_Tree_In_0rder(Node* root, int indent = 5)
	{
		if (root != nullptr) 
		{
			if (root->right) 
			{
				Print_Tree_In_0rder(root->right, indent + 5);
			}
			if (indent) 
			{
				cout << setw(indent) << " ";
			}
			if (root->right)
			{
				cout << " /\n" << setw(indent) << " ";
			}
			cout << root->key << "\n ";
			if (root->left)
			{
				cout << setw(indent) << " " << " \\\n";
				
				Print_Tree_In_0rder(root->left, indent + 5);
			}
		}
	}

	void Print()
	{
		Print_Tree_In_0rder(root);
	}

};

void old() {

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
	t.Print();
	t.Delete_node(76);
	t.Find(50);
	t.Find(76);
	t.Add_elem(50);
	t.Min_Value();
	t.Max_Value();
	t.Delete_node(50);
	t.Delete_node(80);
	t.Delete_node(64);
	t.Delete_node(14);
	t.Delete_node(15);
	t.Delete_node(2);
	t.Add_elem(13);

	t.Find(50);
	t.Print();

}


void test_1() {
	BST tree;
	int iterator = 0;
	while (1) {

		tree.Add_elem(0);
		tree.Delete_node(0);
		tree.Add_elem(1);
		tree.Delete_node(1);
		tree.Add_elem(2);
		tree.Delete_node(2);
		std::cout << "итерация "  << iterator << " закончилась" << std::endl;
	}
}


void test_2() {
	BST tree;

	tree.Add_elem(0);
	tree.Delete_node(0);
	tree.Print();
}


// удаление несуществующего элемента
// удаление корня подветки
void test_2_1() {

	BST tree;
	tree.Add_elem(0);
	tree.Add_elem(1);
	tree.Add_elem(-2);
	tree.Add_elem(-4);
	tree.Add_elem(-1);
	tree.Add_elem(100);
	tree.Add_elem(97);
	tree.Add_elem(99);
	tree.Add_elem(95);
	tree.Add_elem(110);
	tree.Add_elem(101);
	tree.Add_elem(111);
	tree.Add_elem(-8);
	tree.Add_elem(-5);
	tree.Add_elem(-3);
	tree.Delete_node(111);
	tree.Delete_node(110);
	tree.Delete_node(1);
	tree.Delete_node(111111);
	tree.Print();
}

void test_3() {
	BST tree;
	tree.Add_elem(5);
	tree.Add_elem(-10);
	tree.Add_elem(20);
	tree.Add_elem(19);
	/*tree.Print();*/
}

void test_0() {
	BST tree;
	tree.Add_elem(0);
	tree.Add_elem(1);
	tree.Add_elem(-2);
	tree.Add_elem(-4);
	tree.Add_elem(-2);
	tree.Add_elem(100);
	tree.Add_elem(101);

}

int main()
{
	test_2_1();
}