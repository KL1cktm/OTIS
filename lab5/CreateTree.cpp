#include "graph.h"
using namespace std;

void Graph::createTree()
{
	headRoot = nullptr;
	for (int i = 0; i < vert.size(); i++)
	{
		if (DegreeVertex(i) == 0)
		{
			cout << "It is impossible to create a tree" << endl;
			return;
		}
	}
	bufarc.clear();
	headRoot = fuelTree(headRoot);
	for (int i = 0; i < headRoot->child.size(); i++)
	{
		fuelNodeTree(headRoot->child[i]);
	}
	printTree();
	deleteTree(headRoot);
}

Tree* Graph::fuelTree(Tree* headRoot)
{
	if (headRoot == nullptr)
	{
		Tree* node = new Tree;
		node->name = vert[0].vertexName;
		for (int i = 0; i < arc.size(); i++)
		{
			if (arc[i].indexStart == 0)
			{
				Tree* children = new Tree;
				children->name = vert[arc[i].indexEnd].vertexName;
				bufarc.push_back(arc[i]);
				node->child.push_back(children);
			}
			if (arc[i].indexEnd == 0)
			{
				Tree* children = new Tree;
				children->name = vert[arc[i].indexStart].vertexName;
				bufarc.push_back(arc[i]);
				node->child.push_back(children);
			}
		}
		return node;
	}
}

void Graph::fuelNodeTree(Tree* root)
{
	int indexVert;
	for (int i = 0; i < vert.size(); i++)
	{
		if (vert[i].vertexName == root->name)
		{
			indexVert = i;
		}
	}
	for (int i = 0; i < arc.size(); i++)
	{
		if (arc[i].indexEnd == indexVert)
		{
			if (bufTree(arc[i]))
			{
				Tree* children = new Tree;
				children->name = vert[arc[i].indexStart].vertexName;
				bufarc.push_back(arc[i]);
				root->child.push_back(children);
			}
		}
		if (arc[i].indexStart == indexVert)
		{
			if (bufTree(arc[i]))
			{
				Tree* children = new Tree;
				children->name = vert[arc[i].indexEnd].vertexName;
				bufarc.push_back(arc[i]);
				root->child.push_back(children);
			}
		}
	}
	for (int i = 0; i < root->child.size(); i++)
	{
		fuelNodeTree(root->child[i]);
	}
}

bool Graph::bufTree(Arc ar)
{
	for (int i = 0; i < bufarc.size(); i++)
	{
		if (bufarc[i].indexStart == ar.indexStart && bufarc[i].indexEnd == ar.indexEnd)
		{
			return false;
		}
	}
	return true;
}

void Graph::printTree()
{
	cout << "Left tree traversal" << endl;
	for (int i = 0; i < headRoot->child.size(); i++)
	{
		printTree(headRoot->child[i]);
		cout << headRoot->child[i]->name << endl;
	}
	cout << "Root: " << headRoot->name << endl;
}

void Graph::printTree(Tree* root)
{
	for (int i = 0; i < root->child.size(); i++)
	{
		printTree(root->child[i]);
		cout << root->child[i]->name << endl;
	}
}

void Graph::deleteTree(Tree* root)
{
	for (int i = 0; i < root->child.size(); i++)
	{
		deleteTree(root->child[i]);
	}
	delete root;
}

void Graph::createBinaryTree()
{
	Root = nullptr;
	for (int i = 0; i < vert.size(); i++)
	{
		if (DegreeVertex(i) == 0)
		{
			cout << "It is impossible to create a tree" << endl;
			return;
		}
	}
	bufarc.clear();
	Root = fuelBinaryNode(Root);
	pushBinaryNode(Root);
	printBinaryTree(Root);
	deleteBinaryTree(Root);
}

BinaryTree* Graph::fuelBinaryNode(BinaryTree* node)
{
	if (node == nullptr)
	{
		BinaryTree* children = new BinaryTree;
		children->name = vert[0].vertexName;
		children->data = vert[0].getData();
		children->right = NULL;
		children->left = NULL;
		children->orien = 's';
		return children;
	}
}

void Graph::pushBinaryNode(BinaryTree* node)
{
	int index;
	for (int i = 0; i < vert.size(); i++)
	{
		if (vert[i].vertexName == node->name)
		{
			index = i;
		}
	}
	for (int i = 0; i < arc.size(); i++)
	{
		if (bufTree(arc[i]))
		{
			if (arc[i].oriented)
			{
				if (arc[i].indexEnd == index)
				{
					bufarc.push_back(arc[i]);
					BinaryTree* children = new BinaryTree;
					children->name = vert[arc[i].indexStart].vertexName;
					children->data = vert[arc[i].indexStart].getData();
					children->left = children->right = NULL;
					children->lastname = node->name;
					children->orien = 'o';
					node->left = children;
					BinaryTree* rightChildren = new BinaryTree;
					*rightChildren = *node;
					rightChildren->left = rightChildren->right = NULL;
					rightChildren->orien = 'r';
					node->right = rightChildren;
					pushBinaryNode(node->left);
					pushBinaryNode(node->right);
				}
				if (arc[i].indexStart == index)
				{
					bufarc.push_back(arc[i]);
					BinaryTree* children = new BinaryTree;
					children->name = vert[arc[i].indexEnd].vertexName;
					children->data = vert[arc[i].indexEnd].getData();
					children->left = children->right = NULL;
					children->lastname = node->name;
					children->orien = 'o';
					node->left = children;
					BinaryTree* rightChildren = new BinaryTree;
					*rightChildren = *node;
					rightChildren->left = rightChildren->right = NULL;
					rightChildren->orien = 'r';
					node->right = rightChildren;
					pushBinaryNode(node->left);
					pushBinaryNode(node->right);
				}
			}
			else
			{
				if (arc[i].indexStart == index)
				{
					bufarc.push_back(arc[i]);
					BinaryTree* children = new BinaryTree;
					children->name = vert[arc[i].indexEnd].vertexName;
					children->data = vert[arc[i].indexEnd].getData();
					children->left = children->right = NULL;
					children->lastname = node->name;
					children->orien = 'n';
					node->right = children;
					BinaryTree* leftChildren = new BinaryTree;
					*leftChildren = *node;
					leftChildren->left = leftChildren->right = NULL;
					leftChildren->orien = 'r';
					node->left = leftChildren;
					pushBinaryNode(node->left);
					pushBinaryNode(node->right);
				}
			}
		}
	}
}

void Graph::printBinaryTree(BinaryTree* node)
{
	if (node->left != NULL)
	{
		printBinaryTree(node->left);
	}
	if (node->right != NULL)
	{
		printBinaryTree(node->right);
	}
	switch (node->orien)
	{
	case 'o':
		cout << "Vertex \"" << node->name << "\" have orient connection with vertex \"" << node->lastname << "\"" << endl;
		break;
	case 'n':
		cout << "Vertex \"" << node->name << "\" have not orient connection with vertex \"" << node->lastname << "\"" << endl;
		break;
	case 'r':
		cout << "Node replay: \"" << node->name << "\"" << endl;
		break;
	case 's':
		cout << "Root: \"" << node->name << "\"" << endl;
		break;
	}
}

void Graph::deleteBinaryTree(BinaryTree* node)
{
	if (node->left != NULL)
	{
		deleteBinaryTree(node->left);
	}
	if (node->right != NULL)
	{
		deleteBinaryTree(node->right);
	}
	delete node;
}