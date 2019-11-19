//****************************************************************************************************
//
//		File:					BST.h
//		
//		Student:				Manish Bhandari
//
//		Assignment:	 			Program  # 10
//
//		Course Name:			Data Structures   II 
//
//		Course Number:			COSC 3100 - 01
//
//		Due:					Nov 6, 2019
//
//
//		This program implements binary class to manipulate student data.
//		
//****************************************************************************************************

#ifndef BST_H
#define BST_H

//****************************************************************************************************

#include<new>
#include<cmath>
#include<algorithm>
#include "Node.h"

//****************************************************************************************************

template <typename TYPE>
class BST
{
private:
		Node<TYPE> * root;

		void _destruct(Node<TYPE> * pRoot);
		Node<TYPE> * _retrieve(Node<TYPE> * pRoot, const TYPE & dataOut) const;
		Node<TYPE> * _insert(Node<TYPE> * pRoot, const TYPE & dataIn);
		Node<TYPE> * _remove(Node<TYPE> * pRoot, TYPE & dataOut);
		void _inorderTraverse(Node<TYPE> * pRoot, void(*process)(TYPE d)) const;
		int _getCount(Node<TYPE> * pRoot) const;
		int _getHt(Node<TYPE> * pRoot) const;
		bool _isComplete(Node < TYPE> * pRoot) const;
		bool _isBalanced(Node<TYPE> * pRoot) const;

public:
		BST();
		~BST();
		bool retrieve(TYPE & dataOut) const;
		bool insert(const TYPE & dataIn);
		bool remove(TYPE & dataOut);
		bool update(const TYPE & dataIn) const;
		void inorderTraverse(void(*process)(TYPE d)) const;
		int getCount() const;
		int getHt() const;
		bool isEmpty() const;
		bool isFull() const;
		bool isComplete() const;
		bool isBalanced() const;
};

//****************************************************************************************************

template <typename TYPE>
BST<TYPE>::BST()
{
	root = nullptr;
}

//********************************************************************************************

template<typename TYPE>
void BST<TYPE>::_destruct(Node<TYPE> * pRoot)
{
	if (pRoot)
	{
		_destruct(pRoot->left);
		_destruct(pRoot->right);
		delete pRoot;
	}
	
}

//****************************************************************************************************

template <typename TYPE>
BST<TYPE>::~BST()
{
	_destruct(root);
}

//****************************************************************************************************

template<typename TYPE>
Node<TYPE> * BST<TYPE>::_retrieve(Node<TYPE> * pRoot, const TYPE & dataOut) const 
{
	if (pRoot)
	{
		if (pRoot->data > dataOut)
			pRoot = _retrieve(pRoot->left, dataOut);
		else if(pRoot->data < dataOut)
			pRoot = _retrieve(pRoot->right, dataOut);
	}

	return pRoot;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::retrieve(TYPE & dataOut) const
{
	bool success = false;
	Node<TYPE> * pFound;

	pFound = _retrieve(root, dataOut);

	if (pFound)
	{
		dataOut = pFound->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************


template<typename TYPE>
Node<TYPE> * BST<TYPE>::_insert(Node<TYPE> * pRoot, const TYPE & dataIn)
{
	if (pRoot)
	{
		if (pRoot->data > dataIn)
			pRoot->left = _insert(pRoot->left, dataIn);
		else
			pRoot->right = _insert(pRoot->right, dataIn);
	}
	else
		pRoot = new Node<TYPE>(dataIn);

	return pRoot;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::insert(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE> * pFound;

	pFound = _retrieve(root, dataIn);

	if (!pFound)
	{
		root = _insert(root, dataIn);
		success = true;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
Node<TYPE> * BST<TYPE>::_remove(Node<TYPE> * pRoot, TYPE &  dataOut)
{
	Node<TYPE> * pDel;
	Node<TYPE> * pMax;

	if (pRoot)
	{
		if (pRoot->data > dataOut)
			pRoot->left = _remove(pRoot->left, dataOut);
		else if (pRoot->data < dataOut)
			pRoot->right = _remove(pRoot->right, dataOut);
		else
		{
			if ((pRoot->left) && (pRoot->right))
			{
				pMax = pRoot->left;

				while ((pMax) && (pMax->right))
					pMax = pMax->right;

				pRoot->data = pMax->data;
				pRoot->left = _remove(pRoot->left, pMax->data);
			}
			else
			{
				pDel = pRoot;
				
				if (pRoot->left)
					pRoot = pRoot->left;
				else
					pRoot = pRoot->right;

				delete pDel;
			}
		}

	}

	return pRoot;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::remove(TYPE & dataOut)
{
	bool success = false;
	Node<TYPE> * pFound;

	pFound = _retrieve(root, dataOut);

	if (pFound)
	{
		dataOut = pFound->data;
		root = _remove(root, dataOut);
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::update(const TYPE & dataIn) const
{
	bool success = false;
	Node<TYPE> * pFound;

	pFound = _retrieve(root, dataIn);

	if (pFound)
	{
		pFound->data = dataIn;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
void BST<TYPE>::_inorderTraverse(Node<TYPE> * pRoot, void(*process)(TYPE d)) 
				const
{
	if (pRoot)
	{
		_inorderTraverse(pRoot->left, process);
		process(pRoot->data);
		_inorderTraverse(pRoot->right, process);
	}
	
}

//****************************************************************************************************

template <typename TYPE>
void BST<TYPE> ::inorderTraverse(void(*process)(TYPE d)) const
{
	_inorderTraverse(root, process);
}

//****************************************************************************************************


template<typename TYPE>
int BST<TYPE>::_getCount(Node<TYPE> * pRoot) const
{
	
	int result;

	if (pRoot)
	{
		result = 1 + _getCount(pRoot->left) + _getCount(pRoot->right);
	}
	else
		result = 0;

	return result;
}

//****************************************************************************************************

template <typename TYPE>
int BST<TYPE>::getCount() const
{
	return _getCount(root);
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::isEmpty() const
{
	return(root == nullptr);
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::isFull() const
{
	bool full = true;
	Node <TYPE> * pNew;

	pNew = new (nothrow) Node<TYPE> ;

	if (pNew)
	{
		full = false;
	}

	delete pNew;
	return full;
}

//****************************************************************************************************

template<typename TYPE>
int BST<TYPE>::_getHt(Node<TYPE> * pRoot) const
{
	int height = 0;
													
	if (pRoot)											
	{
		height  = 1+ max(_getHt(pRoot->left), _getHt(pRoot->right));
		
	}

	return height;
}

//****************************************************************************************************

template <typename TYPE>
int BST<TYPE>::getHt() const
{
	return _getHt(root) - 1;
}

//****************************************************************************************************

template<typename TYPE>
bool BST<TYPE>::_isComplete(Node < TYPE> * pRoot) const
{
	bool success = true;

	if (pRoot)
	{
		if ((success) && ((_getHt(pRoot->left) - _getHt(pRoot->right)) == 0))
			success = _isComplete(pRoot->left) && _isComplete(pRoot->right);
		else
			success = false;
	}
	
	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::isComplete() const
{
	return _isComplete(root);
}

//****************************************************************************************************

template<typename TYPE>
bool BST<TYPE>::_isBalanced(Node<TYPE> * pRoot) const
{

	bool result = true;

	if (pRoot)
	{
		if ((result) && (abs(_getHt(pRoot->left) - _getHt(pRoot->right)) < 2))
			result = _isBalanced(pRoot->left) && _isBalanced(pRoot->right);
		else
			result = false;
	}
	
	return result;

}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::isBalanced() const
{
	return isBalanced(root);
}

//****************************************************************************************************

#endif 
