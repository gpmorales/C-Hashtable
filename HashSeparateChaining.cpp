#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include "HashHeader.h"
using namespace std;

// Hash Tables/ Hash Maps are data structures that take the form of tables, mapping key value pairs utilizing a hash function
// -> A hash table uses a HASHING FUNCTION to compute the index	in an array of a key
// -> By applying a caluculation to our key, we can transform our key into a UNIQUE address we can store in Array
// -> Hash(key) = (ideally) unique Index
//
// NOTE: EXAMPLE: Lets say we want to store ELEVEN 3-Lettered Names in an Array 
// We will use a Hash Function to determine the index in which we will insert the Name (key) and any other corresponding data (value)
//
// HashFunction(Name/Key) = (Sum of each Char's Ascii val) % (Array Size) = index 
//
// Mia - M 77  i 105  a 97    Tot: 279   279%11 = 4  <- Array index we will store 'Mia'
// Tim - T 84  i 105  m 109   Tot: 298   298%11 = 1 
// Bea - B 66  e 101  a 97    Tot: 264   264%11 = 0 
// Zoe - Z 90  o 111  e 101   Tot: 302   302%11 = 5 
// Jan - J 74  a 97   n 110   Tot: 281   281%11 = 6 
// Ada - A 65  d 100  a 97    Tot: 262   262%11 = 9 
// Leo - L 76  e 101  o 111   Tot: 288   288%11 = 2 
// Sam - S 83  a 97   m 109   Tot: 289   289%11 = 3 
// Lou - L 76  o 111  u 117   Tot: 304   304%11 = 7 
// Max - M 77  a 97   x 120   Tot: 294   294%11 = 8
// Ted - T 84  e 101  d 100   Tot: 285   285%11 = 10
//
//  Our Hash Table/Array:
//  0 [ Bea ]  
//  1 [ Tim ]
//  2 [ Leo ]
//  3 [ Sam ]
//  4 [ Mia ]
//  5 [ Zoe ]
//  6 [ Jan ]
//  7 [ Lou ]
//  8 [ Max ]
//  9 [ Ada ]
// 10 [ Ted ]
//
// SEARCHING/INSERTION/DELETION: To find a Value it takes O(1) time, as we simply retrieve from the address our Hash Function outputs ********
//
//NOTE: COLLISIONS
// What if two distinct Key's produce the exact Hash value... As seen here:
//
// Mia - M 77  i 105  a 97    Tot: 279   279%11 = 4  
// Sue - S 83  u 117  e 101   Tot: 301   301%11 = 4 
//
// Both Key's, when using our Hashing Algorithm, produces the SAME address, causing a COLLISION
// ****There are two methods to deal with this ****
//
// 1) Linear Probing -> If two keys map to the same index insert new key at index i + 1, or later spots
// In our case, we insert Sue at Index 5 if empty, otherwise probe Array linearly (index 6,7,8,9...), until we find an empty spot and insert there
//
// 2) Seperate Chaining -> Array of Pointers to Linked Lists | Instead of inserting key at next empty index, link them sequentially
//
// Mia - M 77  i 105  a 97    Tot: 279   279%11 = 4  <- Array index we will store 'Mia'
// Tim - T 84  i 105  m 109   Tot: 298   298%11 = 1 
// Bea - B 66  e 101  a 97    Tot: 264   264%11 = 0 
// Sue - S 83  u 117  e 101   Tot: 301   301%11 = 4 
//
// 0 [ ] -> [ Bea | Value ]
// 1 [ ] -> [ Tim | Value ]
// 2 [ ] 
// 3 [ ]
// 4 [ ] -> [ Mia | Value ] -> [ Sue | Value ] *Use sequential search in a Collision, parsing thru a paritcular linked list


//NOTE - Here we will define all our related Hash Class functions and methods ->
	//Hash Tables have 3 main member functions:
	// int Hash() - maps key to integer i between 0 and M - 1, where M is the size or our Array
	// void Insert() - inserts Key-Value at front of ith chain (if not already there)
	// Value Search() - needs to search i-th chain/block only


Hash :: Hash(){ //External Constructor Definition
//We alr defined tableSize in our Class scope - Since this is a method/constructor belonging to our class, it inherits the alr pre defined variable
	for(int i = 0; i < tableSize; i++){
		HashTable[i] = new Node("Empty",0); 
	}
		//Alt (if our Node struct did NOT utilize a Constructor)
		//We would need to initialize each Field our or Node class as such:
		//HTable[i] = new NodeObj;
		//HTable[i]->Key = "Tim";
		//HTable[i]->Val = 124.3;
		//Hatble[i]->next = NULL;
//NOTE: We are dereferencing our Node ptr in the Array and calling on a member from the Node class, HENCE why we use -> the arrow operator

}


int Hash::HashF(string Key){ //Function definition (we must define the functions scope - which is hash class we defined in our header file)
	// This function will recieve an input String
	// Calculate its 'total' ASCII value and then Mods this value by the size of our Array
	// This final value will be the index we store the Key and its Corresponding Value in!!!!
	int Sum = 0;
	int index; //Index in our array where our Key string will be stored in
	for(int i = 0; i < Key.length(); i++){
		//cout << int(Key[i]) << endl;
		Sum += int(Key[i]);
	}

	index = Sum % tableSize;
	return index;

}


void Hash::Insert(string Key, Value value){ //Function definition
	//This function will insert a Key-Value pair in a particular Node determined by our Hash Function & 
	//check the linked list bucket in that Array index
	int index = HashF(Key);

	if(HashTable[index]->Key == "Empty"){ //checks Whether the current index is empty
		HashTable[index] = new Node(Key,value);
		return;
	}

	else{
		Node* temp = HashTable[index]; //our ptr to traveres a linked list
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new Node(Key,value);
	}
}


double Hash::Search(string Key){ //Function searches for a given Key and returns corresponding data / Value
	int index = HashF(Key); //Outputs the index we need to search in our Hash Table
	Node* temp = HashTable[index];
	if(temp->Key == "Empty"){ //If str leads to an empty Bucket, or a bucket containing another name
		cout << "Key is not in directory" << endl;
	}

	else{ //Otherwise parse thru Linked List
		while(temp->next != NULL && temp->Key != Key){
			temp = temp->next;
		}
		return temp->Val;
	}
}



void Hash::PrintItems(){ //Prints our Array of Linked Lists
	for(int i = 0; i < tableSize; i++){
		if(HashTable[i]->Key == "Empty"){ //If our Current Node is empty
			cout << HashTable[i]->Key << " | " << HashTable[i]->Val << endl; //print Empty contents
		}
		else{
			//Otherwise print the current Node and then the next one until we reach End of
			Node* temp = HashTable[i];
			while(temp != NULL){ //While loop prints every non NULL element
				cout << temp->Key << " | " << temp->Val << " | ";
				temp = temp -> next;
			}
			cout << endl;
		}
	}
}


int Hash::NumberOfItemsInIndex(int Index){ //Returns number of items in a bucket/Linked List
	int count = 0; //Our item counter
	if(Index >= tableSize || Index < 0){
		cout << "Invalid Index" << endl;
		return -1;
	}

	else{
		if(HashTable[Index]->Key == "Empty"){
			return 0;
		}
		else{
			count++; //We assume that their is an el in our bucket, increment
			Node* temp = HashTable[Index];
			while(temp->next != NULL){
				count++;
				temp = temp -> next;
			}
			return count;
		}
	}
}


void Hash::PrintItemsInIndex(int index){ //Prints Items in Particular Bucket/Linked List
	if(HashTable[index]->Key == "Empty"){
		cout << "Empty Bucket" << endl;
		return;
	}

	else{
			Node* temp = HashTable[index];
			while(temp != NULL){ //While loop prints every non NULL element
				cout << temp->Key << " | " << temp->Val << " | ";
				temp = temp -> next;
			}
			cout << endl;
	}
}


void Hash::RemoveItem(string Key){ //REmoves a Given Key
	//int index = HashF(Key);
	int index = 4;
	if(HashTable[index]->Key == "Empty"){ //Case 0 - Bucket is empty
		cout << "Key not in Directory" << endl;
	}

	else{
		Node* temp = HashTable[index]; //Rmbr our HashTable is an array of Node ptrs , hence we can set these 2 types equal

		if(temp->Key == Key && temp->next == NULL){//Case 1 - Only 1 item in Bucket and it matches our search Key
			temp->Key = "Empty"; //Dereference ptr and call on member to modify values
			temp->Val = 0;
			return;
		}
		else if(temp->Key == Key && temp->next != NULL){//Case 2 - More than 1 item in Bucket and match is the first Item
			temp = temp->next;//We traverse to the second item, setting our first Item = Second item directly in our table
			return;
		}
		else{ //Case 3 - More than 1 item in Bucket but item is NOT the first Key
			Node* tempTr = HashTable[index]->next;
			while(tempTr->Key != Key && temp != NULL){
				temp = tempTr; //Move Lagging pointer right one
				tempTr = tempTr->next; //Move Leading ptr one forward
			}
			//This allows us to keep TRACK of NODE PRECEDING our Key Node, so we can maintain linked list struct
				if(tempTr->next == NULL){ //If the el we want to delete is the last el of the list
					temp->next = NULL; //[temp]->[tempTr]->NULL
					delete tempTr; //deletes our pointer not contents of the referenced Object
					return;
				}
				else{ //if el is NOT end of list
					temp->next = tempTr->next;//[temp] -> [tempTr|Key] -> [tempTr->next]
					delete tempTr;
					return;
				}
		}
	}

}



bool Hash::isSubArr(int arr1[], int arr2[]){
	for(int i = 0; i < tableSize; i++){ //for loop inserts each el of Arr into our Hash Table
		ostringstream str1;
		str1 << arr1[i];
		string Key = str1.str();
		Insert(Key, 0); 
	}

	for(int i = 0; i < 4; i++){//This for loop will check each element in our sub arr to see if it exists in our Hash Table
		ostringstream str2;
		str2 << arr2[i];
		string Key = str2.str();

		Node* temp = HashTable[HashF(Key)]; //Parse thru specified index for given el of Subarray to see if it is present in arr1
		while(temp != NULL){
			if(temp->Key == Key){ //If element in linked list matches our arr el, we can break from while loop and continue the outer for loop
				break;
			}
			else if(temp->Key != Key && temp->next != NULL){//If our linked list contains more than 1 item, and first item is not the el in our sub arr, continue parsing
				temp = temp->next;
			}
			else{ //Otherwise our key does not exist in given linked list hence it CAN NOT form a subset
				return false;
			}
		}

	}

	return true; //If for loop terminates, this means that each el in the Subarry was found in the HashTable of Array el, so TRUE
}



//Return a Linked List that contains the Intersection of two other Lists
Hash::Node* Hash::findIntersection(Node* head1, Node* head2){
	Node* temp = head2;
	while(temp != NULL){ //This creates a Hash Table w values from linked list 2
		Insert(temp->Key, 0.0);
		temp = temp->next; //Now our HashTable is complete
	}

	Node* headli = new Node("0", 0.0); //IC of our linked list
	for(Node* hasht = head1; hasht != NULL; hasht = hasht->next){//Outer loop to parse thru linked List1
		Node* li = HashTable[HashF(hasht->Key)]; //Each node's Key will be hashed to prod an index -> we will CHECK the index in our HASH TABLE
		if(li->Key == hasht->Key){
			Node* in = new Node(li->Key, li->Val);
			LLinsert(headli,in);
		}
		else{
			while(li->next != NULL && li->Key != hasht->Key){
				li = li->next;
			}
			if(li->Key == hasht->Key){
				Node* in = new Node(li->Key, li->Val);
				LLinsert(headli,in);
			}
		}
	}

	return headli; //return head of our new list
}


//Linked List methods 
void Hash::LLinsert(Node* head, Node* in){
	if(head->Key == "0"){ //This allows us to initialize a linked list 
		head->Key = in->Key;
		head->Val = in->Val;
		return;
	}
	else{
		Node* temp = head; //Insertion at end of linked list for every other element
		while(temp -> next != NULL){
			temp = temp -> next;
		}
		temp->next = in;
	}
}


void Hash::PrintList(Node* head){ //Prints linked list
	Node* temp = head;
	while(temp != NULL){
		cout << temp->Key << endl;
		temp = temp->next;
	}
}


