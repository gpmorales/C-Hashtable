#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//OPEN ADDRESSING IN HASHING (no linked lists)
class HashTable{
	//This Hash Table will be implemented WITHOUT Seperate Chaining and instead will utillize Open Addressing
	// Open addressing is another method for handling collisions when Hashing large sets of data
	// This requires our table size to be greater than or equal to the total number of keys
	static const int tableSize = 7;
	int hashTable[tableSize];

public:
	HashTable(){ //Constructor
		for(int i = 0; i < tableSize; i++){
			hashTable[i] = 0;
		}
	}

	int Hash(int Key){ //Our Hashing Algorithm
		int index = Key%tableSize; //Simple one for this ex -> index = Key Mod 7
		return index;
	}

	void Insert(int Key){
		int index = Hash(Key);
		if(hashTable[index] == 0){ //If this slot in our Array is empty
			hashTable[index] = Key;
		}

		else{ //If the slot is not empty, Collision occurs
			int i = 0;
			while(hashTable[index] != 0){//SEarch for next open spot using Linear Probing
				index = ( Hash(Key) + i ) % tableSize; //for i = 0, this is like our normal Hash function calculation : Hash(key) % tbleSize
				i++;
			}
			hashTable[index] = Key;
		}
	}

	bool Search(int Key){ 
		int index = Hash(Key); //our hash function outputs an index
		if(hashTable[index] == 0){
			cout << "Key was not found in directory" << endl;
			return false;
		}
		else{
			int i = 0;
			while(hashTable[index] != Key){
				index = ( Hash(Key) + i ) % tableSize;
				i++;
			}
			return true;
		}
	}

	void Delete(int Key){ //Function deletes given key
		int index = Hash(Key);
		if(hashTable[index] == 0){
			cout << "Key was not found in directory" << endl;
			return;
		}
		else{
			int i = 0;
			while(hashTable[index] != Key){
				index = ( Hash(Key) + i ) % tableSize;
				i++;
			}
			hashTable[index] = 0;
		}
	}

	void PrintItems(){
		for(int i = 0; i < tableSize; i++){
			cout << hashTable[i] << " " << endl;
		}
	}

};


int main(){
	HashTable OpAdTable; //Instantiation of new HashTable Object

	OpAdTable.Insert(50); //Gets placed in index 1
	OpAdTable.Insert(700);
	OpAdTable.Insert(76);
	//Linear Probing is the solution to the collision of 85 in index 1
	OpAdTable.Insert(85); //Collision occurs here, index should be 1 but is alr taken
	
	//Our insert function does linear probing which takes the following mathematical form:
	//F(key) = i
	//HTi[X] = (F(key) + i) mod TableSize
	//HT0[X] = (F(key) + 0) mod TableSize
	//HT1[X] = (F(key) + 1) mod TableSize
	//HT2[X] = (F(key) + 2) mod TableSize
	//
	//If F(85) mod TbleSize = 1, but  HT[1] != empty
	//we perform this operation : newIndex = (F(85) + i) mod TbleSize
	//F(85) = (F(85) + 1) % mod 7 = 2 {if F(nKey) == Empty index - break, else cont}
	//F(85) = (F(85) + 2) % mod 7 = 3
	//
	//NOTE: NOTICE that if the next slot is not Empty, our hash function outputs 1 higher than previous, LINEARLY PROBING the table 
	
	//Quadratic Probing squares the index , using this new Function to calculate the hash instead
	//HTi[X] = (F(key) + i ^ 2) mod TableSize
	//HT0[X] = (F(key) + 0 ^ 2) mod TableSize
	//HT1[X] = (F(key) + 1 ^ 2) mod TableSize
	//HT2[X] = (F(key) + 2 ^ 2) mod TableSize

	OpAdTable.Insert(73);
	OpAdTable.Insert(101);
	OpAdTable.Delete(50); //Deletes given key

	OpAdTable.PrintItems();


	//NOTE:
	//DOUBLE HASHING -> Aside from linear probing, quadratic probing, and even random probing
	// We can implement TWO HASH FUNCTIONS to generate an even more uniform and collision free distrubtion of Data
	//
	// Mathematical Model:
	//
	// (Hash1(key) + i * Hash2(key)) % TableSize 
	//
	// i is initially zero assuming the current index of the Array is empty
	// If not, we increase i in the case of collision

	// A popular first and second Hash function take the form
	// Hash1(key) = Key % tableSize
	// Hash2(key) = Prime - Key % Prime
}

