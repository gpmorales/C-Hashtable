//This is our header file
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

#ifndef HASHHEADER_H //Header Guards
#define HASHHEADER_H
#endif


class Hash{
	public:
//private:
	using Value = double;
	static const int tableSize = 6; //Our hash table size should be const and static, meaning it belongs to the class rather than the function

	struct Node{ //Node is an object used to build a linked list , will contain
			string Key;
			Value Val;
			Node* next; //Next points to Node
			Node(string Key, Value Val){
				this->Key = Key;
				this->Val = Val;
				next = NULL;
			}
	};

	Node* HashTable[tableSize]; //This creates an Array of Pointers to a Node object (currently empty - we initialize it in our Constructor***)

//NOTE - Private var's can be called from direct member functions of the class BUT NOT in external methods such as in our main method
public:
	//Hash Tables have 3 main member functions & consists of a Hash Array
	// int Hash() - maps key to integer i between 0 and M - 1, where M is the size or our Array
	// void Insert() - inserts Key-Value at front of ith chain (if not already there)
	// Value Search() - needs to search i-th chain/block only

	Hash(); //Constructor Prototype (rmbr constructors cannot return vals)
	int HashF(string Key); //Function prototype for our Hash Algorithm/Function itself | returns int value for index 
	void Insert(string Key, Value value); //function prototype
	Value Search(string Key);

	//Helper Functions-
	void PrintItems();//Function prototype
	int NumberOfItemsInIndex(int index);
	void PrintItemsInIndex(int index);
	void RemoveItem(string key);

	//Excersize Problems-
	bool isSubArr(int* a1, int* a2);
	Node* findIntersection(Node* h1, Node* h2);
	void LLinsert(Node* h, Node* in);
	void PrintList(Node* h);


};
