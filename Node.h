//****************************************************************************************************
//
//		File:					Node.h
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

#ifndef  NODE_H
#define  NODE_H

//*****************************************************************************************************

template<typename TYPE>
struct Node
{
	TYPE data;
	
	union
	{
		Node<TYPE> * next;
		Node<TYPE> * left;

	};
	
	union
	{
		Node<TYPE> * prev;
		Node<TYPE> * right;
	};
	

	Node();
	Node(const TYPE  & d, Node<TYPE> * n = nullptr, Node<TYPE> * p = nullptr);
};

//*****************************************************************************************************

template<typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = nullptr;
	prev = nullptr;
}

//*****************************************************************************************************

template<typename TYPE>
Node<TYPE>::Node(const TYPE  & d, Node<TYPE> * n, Node<TYPE> * p)
{
	data = d;
	next = n;
	prev = p;
}

//*****************************************************************************************************

#endif

