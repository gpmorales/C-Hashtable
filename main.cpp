// Our main method is found here; Driver code for rest of files
#include <cstdlib>
#include <iostream>
#include <string>
#include "HashHeader.h"

using namespace std;

int main(){ //Driver Code

	/*
	Hash Table1;

	int i = Table1.HashF("Tim"); //Test of our Hash Algorithm

	cout << "Our index for this Key is " << i << endl;
	cout << Table1.HashTable[0]->Key<< endl; //'Empty'
	cout << Table1.HashTable[0]->Val<< endl; //0
	cout << Table1.HashTable[0]->next << endl; //NULL bt default points to 0

	cout << endl;

	Table1.Insert("Mia", 24.8);
	Table1.Insert("Tim", 11.9);
	Table1.Insert("Bea", 7.5);
	Table1.Insert("Zoe", 99.2);
	Table1.Insert("Sue", 34.2);
	Table1.Insert("Len", 76.3);
	Table1.Insert("Moe", 89.1);
	Table1.Insert("Lou", 92.5);
	Table1.Insert("Rae", 5.6);
	Table1.Insert("Max", 43.5);
	Table1.Insert("Tod", 45.5);
	Table1.HashTable[4]->next->next = new Hash::Node("Jim", 4.5);

  //Table1.RemoveItem("Sue");
  Table1.RemoveItem("Mia");
	cout << endl;

	Table1.PrintItems();

	cout<< Table1.HashTable[0]->Key << endl;
	cout<< Table1.HashTable[0]->Val << endl;

	cout<< Table1.HashTable[4]->Key << endl;
	cout<< Table1.HashTable[4]->Val << endl;

	Hash::Node* temp = Table1.HashTable[4]->next;
	cout<< temp->Key << endl;
	cout<< temp->Val << endl;

	cout << endl;

	//cout << Table1.NumberOfItemsInIndex(4) << endl;
	//cout << Table1.NumberOfItemsInIndex(0) << endl;

	Table1.PrintItemsInIndex(5);

	cout << endl;

	cout << Table1.Search("Sue") << endl;

	cout << endl;

	//EXCERCISE PROBLEMS
	// 1) USe hashing to determine whether array2[] is a SUBSET of array1[]
	Hash Table2;
	int array1[] = {11,1,13,21,3,7};
	int array2[] = {11,3,7,1};
	
	int array3[] = {1,2,3,4,5,6};
	int array4[] = {1,2,4};

	int array5[] = {10,5,2,23,19};
	int array6[] = {19,5,20};

	cout << Table2.isSubArr(array1, array2) << endl;
	//cout << Table2.isSubArr(array3, array4) << endl;
	//cout << Table2.isSubArr(array5, array6) << endl;

	cout << endl;

	Table2.PrintItems();
	*/


	//2) Intersection and Union of 2 Linked Lists:
	Hash Table3;

	Hash::Node* head = new Hash::Node("0", 0); //We must specify that Node is an object belonging to the Hash class
	Hash::Node* in = new Hash::Node("9", 0);
	Hash::Node* in2 = new Hash::Node("6", 0);
	Hash::Node* in3 = new Hash::Node("4", 0);
	Hash::Node* in4 = new Hash::Node("2", 0);
	Hash::Node* in5 = new Hash::Node("3", 0);
	Hash::Node* in6 = new Hash::Node("8", 0);
	Table3.LLinsert(head, in); //Creates a linkedlist
	Table3.LLinsert(head, in2);
	Table3.LLinsert(head, in3);
	Table3.LLinsert(head, in4);
	Table3.LLinsert(head, in5);
	Table3.LLinsert(head, in6);

	cout << endl;

	Hash::Node* head2 = new Hash::Node("0", 0); //We must specify that Node is an object belonging to the Hash class
	Hash::Node* i = new Hash::Node("1", 0);
	Hash::Node* i2 = new Hash::Node("2", 0);
	Hash::Node* i3 = new Hash::Node("8", 0);
	Hash::Node* i4 = new Hash::Node("6", 0);
	Table3.LLinsert(head2, i); //Creates a second linkedlist
	Table3.LLinsert(head2, i2);
	Table3.LLinsert(head2, i3);
	Table3.LLinsert(head2, i4);

	//head - 9->6->4->2->3->8
	//head2  1->2->8->6
	
	Hash::Node* interSection = Table3.findIntersection(head, head2);
	Table3.PrintList(interSection);
	//Table3.PrintItems();





}

