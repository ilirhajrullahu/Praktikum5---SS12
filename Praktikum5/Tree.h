#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <new>
#include <string>
#include "TreeNode.h"


using namespace std;

// Tree class-template definition
template< typename NODETYPE > class Tree
{
public:
	Tree(); // constructor
	~Tree(); // destructor
	Tree(const Tree&) = delete; // no copies of Tree-objects allowed               
	const Tree& operator=(const Tree&) = delete; // no assignment allowed               

	void insertNode(const NODETYPE &);
	std::string preOrderTraversal() const;
	std::string inOrderTraversal() const;
	std::string postOrderTraversal() const;
	TreeNode< NODETYPE > * binaryTreeSearch(const NODETYPE &) const;
	std::string toString() const;
	void deleteNode(const NODETYPE &);

	int size(TreeNode<NODETYPE>* node)
	{
		if (node == nullptr)
			return 0;
		else
			return(size(node->leftPtr) + 1 + size(node->rightPtr));
	}
	int sum(TreeNode<NODETYPE>* root)
	{
		if (root == nullptr)
			return 0;
		return (root->frequency + sum(root->leftPtr) + sum(root->rightPtr));
	}

	TreeNode<NODETYPE>* getRoot() {
		return rootPtr;
	}
	void writeToFile() {
		ofstream ziel;
		ziel.open("Results.txt", ios::out);
		if (!ziel) {
			cerr << " teams.txt konnte nicht gefunden werden" << endl;
		}

		ziel << inOrderTraversal() << endl;
	}
private:
	TreeNode< NODETYPE > * rootPtr;

	// utility functions
	void insertNodeHelper(TreeNode< NODETYPE > *&, const NODETYPE &);
	void preOrderHelper(TreeNode< NODETYPE > *, std::stringstream &) const;
	void inOrderHelper(TreeNode< NODETYPE > *, std::stringstream &) const;
	void postOrderHelper(TreeNode< NODETYPE > *, std::stringstream &) const;
	TreeNode< NODETYPE > * binarySearchHelper(TreeNode< NODETYPE > *,
		const NODETYPE &) const;
	void toStringHelper(TreeNode< NODETYPE > *, int, std::stringstream &) const;
	bool deleteNodeHelper(TreeNode< NODETYPE > *&, const NODETYPE &);
	void replaceNodeHelper(TreeNode< NODETYPE > *&, TreeNode< NODETYPE > *&);
	void destructorHelper(TreeNode< NODETYPE > *);
	int n = 1;
}; // end class Tree

