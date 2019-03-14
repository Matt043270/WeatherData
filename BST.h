#ifndef BST_H
#define BST_H

#include <vector>

using namespace std;

template <class K, class V>
using func_pointer = void(*)(K&, V&);



	/**
	* @class	BST
	* @brief	A templated Binary Search Tree class.
	*
	* @author	Matt Smooker
	* @version	01
	*/
template <class K, class V>
class BST
{

		/**
		* @brief	A struct containing Node data.
		*/
	struct Node
	{
			/// The key value that nodes are compared against.
		K key;
			/// The data values for the node. 
		vector<V> value;
			/// The left child node.
		Node *leftNode = nullptr;
			/// The right chld node.
		Node *rightNode = nullptr;


			/**
			* @brief	A constructor for the node struct.
			*
			* @param	k - the key for the node.
			* @param	v - the value for the node.
			*/
		Node(K k, V v)
		{
			key = k;
			value.push_back(v);
			leftNode = nullptr;
			rightNode = nullptr;
		}
	};


public:


	/**
	* @brief	The default constructor for the BST class.
	*/
	BST();


	/**
	* @brief	The destructor for the BST class.
	*/
	//~BST();


	/**
	* @brief	Inserts data into the BST.
	*
	* @param	k - the key for the node. 
	* @param	v - the value for the node.
	* @return	void
	*/
	void Insert(const K &k, const V &v);


	/**
	* @brief	Checks if the BST is empty.
	*
	* @return	bool
	*/
	bool Empty() const;


	/**
	* @brief	Removes a node from the BST based on the key value.
	*
	* @param	key - the key of the node that is to be removed. 
	* @return	void
	*/
	void Remove(const K &key);


	/**
	* @brief	Searches the tree for a value.
	*
	* @param	key - the value to find in the BST.
	* @return	bool
	*/
	bool Search(const K &key) const;


	/**
	* @brief	Traverse the BST in order sequence.
	*
	*	In order: Left node, current node, right node.
	*
	* @param	fptr - the function pointer to process the nodes. 
	* @return	void
	*/
	void InOrder(func_pointer<K, V> fptr);

	/**
	* @brief	Traverse the BST in pre order sequence.
	*
	*	Pre Order: Current node, Left node, Right node.
	*
	* @param	fptr - the function pointer to process the nodes.
	* @return	void
	*/
	void PreOrder(func_pointer<K, V> fptr);

	/**
	* @brief	Traverse the BST in post order sequence.
	*
	*	Post Order: Left node, Right node, Current node.
	*
	* @param	fptr - the function pointer to process the nodes.
	* @return	void
	*/
	void PostOrder(func_pointer<K, V> fptr);

	/**
	* @brief	Find the maximum value in the BST.
	*
	* @return	void
	*/
	void Max();

	/**
	* @brief	Retrieves the total value of the nodes in the BST.
	*
	* @return	K - key value.
	*/
	K& GetTotal();

	/**
	* @brief	Retrieves the count of the number of nodes in the BST.
	*
	* @return	int
	*/
	int GetCount();

private:
		/// The root node of the BST
	Node *root;
		/// The sum of the node values.
	K total = 0;
		/// The number of nodes in the BST.
	int count = 0;

	/**
	* @brief	A recursive function that insert data into the BST.
	*
	*	If the node is nullptr, a new Node is created. Otherwise if the key value already exists
	*	in the BST, the value is pushed to the Node's vector. 
	*
	* @param	key - the key data
	* @param	v - the value data
	* @return	void
	*/
	void InsertHelper(Node *&node, const K &key, const V &v);


	/**
	* @brief	A recursuve function that removes a node from the BST.
	*
	* @param	node - the node to compare the key with.
	* @param	key - the value of the Node to be removed.
	*/
	bool RemoveHelper(Node *&node, const K &key);

	/**
	* @brief	Clears a single Node from the BST
	*
	* @param	node - the temporary Node to be compared against.
	* @param	parent - the parent node to be cleared.
	* @return	void
	*/
	void ClearNode(Node *&tempNode, Node *&parent);

	/**
	* @brief	Reassigns a Node in the BST
	*
	* @param	tempNode - the Node to compare against.
	* @param	node - the Node to be processed.
	* @return	void
	*/
	void Reassign(Node *&tempNode, Node *&node);

	/**
	* @brief	Reassigns the root node of the BST
	*
	* @return	void
	*/
	void ReassignRoot();

	/**
	* @brief	A recursive function that searches the BST for a ey value.
	*
	* @param	node - the Node to compare against.
	* @param	key - the value that is being searched for.
	* @return	bool
	*/
	bool SearchHelper(Node* const &node, const K &key) const;

	/**
	* @brief	A recursive function that processes the BST in order.
	*
	* @param	node - the Node to be processed
	* @param	fptr - the pointer function to process the Node.
	* @return	void
	*/
	void InOrderHelper(Node *&node, func_pointer<K, V> fptr);

	/**
	* @brief	A recursive function that processes the BST in pre order sequence.
	*
	* @param	node - the Node to be processed.
	* @param	fptr - the pointer funtion to process the Node.
	* @returm	void
	*/
	void PreOrderHelper(Node *&node, func_pointer<K, V> fptr);

	/**
	* @brief	A recursive function that processes the BST in post order sequence.
	*
	* @param	node - the Node to be processed.
	* @param	fptr - the pointer function to process the Node.
	* @return	void
	*/
	void PostOrderHelper(Node *&node, func_pointer<K, V> fptr);

	/**
	* @brief	A recursive function that deletes the BST.
	*
	* @param	node - the node to be processed.
	* @return	void
	*/
	//void DestroyTree(Node *&node);

	/**
	* @brief	A recursive function that finds the Node with the highest value in the BST.
	*
	* @param	node - the Node to be processed.
	* @return	void
	*/
	void MaxHelper(Node *&node);

	/**
	* @brief	A function that outputs the max Node to the screen.
	*
	* @param	node - the Node to be printed.
	* @return	void
	*/
	void PrintMax(Node *&node);

};


template<class K, class V>
BST<K, V>::BST()
{
	root = nullptr;
}


//template<class K, class V>
//BST<K, V>::~BST()
//{
//	DestroyTree(root);
//	root = nullptr;
//}
//
//
//template<class K, class V>
//void BST<K, V>::DestroyTree(Node *& node)
//{
//	if (node != NULL)
//	{
//		DestroyTree(node->leftNode);
//		DestroyTree(node->rightNode);
//
//		delete node;
//		node = nullptr;
//	}
//}


template<class K, class V>
bool BST<K, V>::Empty() const
{
	if (root == nullptr)
	{
		return true;
	}

	return false;
}


template<class K, class V>
void BST<K, V>::Insert(const K &k, const V &v)
{
	InsertHelper(root, k, v);
}


template<class K, class V>
void BST<K, V>::InsertHelper(Node *& node, const K &k, const V &v)
{
	if (node == nullptr)
	{
		node = new Node(k, v);
		total += node->key;
		count++;
	}

	else if (node->key == k)
	{
		node->value.push_back(v);
	}

	else if (node->key > k)
	{
		InsertHelper(node->leftNode, k, v);
	}

	else
	{
		InsertHelper(node->rightNode, k, v);
	}
}



template<class K, class V>
void BST<K, V>::Remove(const K &key)
{
	RemoveHelper(root, key);
}


template<class K, class V>
bool BST<K, V>::RemoveHelper(Node *&node, const K &key)
{
	Node *tempNode;

	if (node == nullptr)
	{
		return false;
	}

	else if (node->key == key)
	{
		if (node == root)
		{
			ReassignRoot();
		}

		return true;
	}

	else if (node->key > key)
	{
		tempNode = node->leftNode;
	}

	else
	{
		tempNode = node->rightNode;
	}


	if (Remove(tempNode, key))
	{
		Reassign(tempNode, key);
	}

	return false;
}



template<class K, class V>
void BST<K, V>::Reassign(Node *&tempNode, Node *&node)
{
	if (tempNode->leftNode == nullptr && tempNode->rightNode == nullptr)
	{
		ClearNode(tempNode, node);
	}

	else if (tempNode->leftNode == nullptr)
	{
		Node *child;
		child = tempNode->rightNode;

		if (node->leftNode == tempNode)
		{
			node->leftNode = child;
		}

		else
		{
			node->rightNode = child;
		}

		Clear(tempNode, node);
	}

	else if (tempNode->rightNode == nullptr)
	{
		Node *child;
		child = tempNode->leftNode;

		if (node->leftNode == tempNode)
		{
			node->leftNode = child;
		}

		else
		{
			node->rightNode = child;
		}

		Clear(tempNode, node);
	}

	else
	{
		Node *leftChild;
		Node *rightChild;

		leftChild = tempNode->leftNode;
		rightChild = tempNode->rightNode;
		Clear(tempNode, node);

		node->rightNode = rightChild;
		Node *tempChild;
		tempChild = rightChild;
		while (tempChild->leftNode != nullptr)
		{
			tempChild = rightChild->leftNode;
		}

		tempChild->leftNode = leftChild;
	}

}


template<class K, class V>
void BST<K, V>::ReassignRoot()
{
	if (root->leftNode == nullptr && root->rightNode == nullptr)
	{
		delete root;
		root = nullptr;
	}

	else if (root->leftNode == nullptr)
	{
		Node *deleteRoot = root;
		root = root->rightNode;
		delete deleteRoot;
	}

	else if (root->rightNode == nullptr)
	{
		Node *deleteRoot = root;
		root = root->leftNode;
		delete deleteRoot;
	}

	else
	{
		Node *deleteRoot = root;
		Node *leftChild;
		Node *rightChild;

		leftChild = root->leftNode;
		rightChild = root->rightNode;

		delete deleteRoot;

		root = rightChild;

		Node *tempChild;
		tempChild = root;

		while (tempChild->leftNode != nullptr)
		{
			tempChild = tempChild->leftNode;
		}

		tempChild->leftNode = leftChild;
	}
}


template<class K, class V>
void BST<K, V>::ClearNode(Node *&tempNode, Node *&parent)
{
	if (tempNode == nullptr)
	{
		return;
	}

	if (parent->leftNode == tempNode)
	{
		parent->leftNode = nullptr;
	}

	else if (parent->rightNode == tempNode)
	{
		parent->rightNode = nullptr;
	}

	delete tempNode;
	tempNode = nullptr;
}



template<class K, class V>
bool BST<K, V>::Search(const K &key) const
{
	return search(root, key);
}


template<class K, class V>
bool BST<K, V>::SearchHelper(Node* const &node, const K &key) const
{
	if (node == nullptr)
	{
		return false;
	}

	else if (node->key == key)
	{
		return true;
	}

	else if (node->key > key)
	{
		return SearchHelper(node->leftNode, key);
	}

	else
	{
		return SearchHelper(node->rightNode, key);
	}
}


template<class K, class V>
void BST<K, V>::InOrder(func_pointer<K, V> fptr)
{
	inOrderProcess(root, fptr);
}


template<class K, class V>
void BST<K, V>::InOrderHelper(Node *&node, func_pointer<K, V> fptr)
{
	if (node == nullptr)
	{
		return;
	}

	InOrderHelper(node->leftNode, fptr);
	fptr(node->key, node->value);
	InOrderHelper(node->rightNode, fptr);
}


template<class K, class V>
void BST<K, V>::PreOrder(func_pointer<K, V> fptr)
{
	PreOrderHelper(root, fptr);
}


template<class K, class V>
void BST<K, V>::PreOrderHelper(Node *&node, func_pointer<K, V> fptr)
{
	if (node == nullptr)
	{
		return;
	}

	fptr(node->key, node->value);
	PreOrderHelper(node->leftNode, fptr);
	PreOrderHelper(node->rightNode, fptr);
}


template<class K, class V>
void BST<K, V>::PostOrder(func_pointer<K, V> fptr)
{
	PostOrderHelper(root, fptr);
}


template<class K, class V>
void BST<K, V>::PostOrderHelper(Node *&node, func_pointer<K, V> fptr)
{
	if (node == nullptr)
	{
		return;
	}

	PostOrderHelper(node->leftNode, fptr);
	PostOrderHelper(node->rightNode, fptr);
	fptr(node->key, node->value);
}


template <class K, class V>
void BST<K, V>::Max()
{
	MaxHelper(root);
}


template<class K, class V>
K& BST<K, V>::GetTotal()
{
	return total;
}


template<class K, class V>
int BST<K, V>::GetCount()
{
	return count;
}


template <class K, class V>
void BST<K, V>::MaxHelper(Node *&node)
{
	if (node->rightNode == nullptr)
	{
		PrintMax(node);
	}
	else
	{
		MaxHelper(node->rightNode);
	}

}


template <class K, class V>
void BST<K, V>::PrintMax(Node *&node)
{
	cout << "High solar radiation for the day: " << node->key << "W/m^2" << endl;
	cout << "\nTime:" << endl;

	for (int i = 0; i < node->value.size(); i++)
	{
		cout << node->value[i].GetHour() << ":" << node->value[i].GetMinute() << endl;
	}

	cout << endl;
}


#endif // BST_H!