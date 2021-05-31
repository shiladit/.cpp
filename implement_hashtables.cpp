// compile using g++
#include <iostream>
#include "ctype.h"
#include <vector>
using namespace std;

#define MAX_HASH_LEN 100

struct element
{
	string key;
	int value;
};

int get_hash_value(string key_p)
{
	int ascii_sum = 0;

	/* Simple hash function that calculates
	sum of ascii values, mods it with capacity
	of hash table and returns */
	for(int i=0;i<key_p.length();i++)
	{
		ascii_sum += int(key_p[i]);
	}

	return (ascii_sum % MAX_HASH_LEN);
}

vector < vector <element *> > insert_into_hashtable(vector < vector <element *> > hash_table,string key_p,int val_p)
{
	int hash_val = get_hash_value(key_p);

	assert(hash_val >= 0);

	struct element * temp = (element *)malloc(sizeof(element));
	temp->key = key_p;
	temp->value = val_p;
	hash_table[hash_val].push_back(temp);

	return hash_table;
}

vector < vector <element *> > delete_element_hashtable(vector < vector <element *> > hash_table,string key_p)
{
	int hash_val = get_hash_value(key_p);

	assert(hash_val >= 0);

	bool found = false;

	for(int i = 0; i < hash_table[hash_val].size(); i++)
	{
		if(hash_table[hash_val][i]->key == key_p)
		{
			cout << "Deleting (key,value) pair: " << hash_table[hash_val][i]->key
			<< " ----- " << hash_table[hash_val][i]->value << endl;
			hash_table[hash_val].erase(hash_table[hash_val].begin() + i);
			found = true;
			break;
		}
	}

	if(found == false)
		cout << "Element is not present\n";

	return hash_table;
}


int main()
{
	vector < vector <element *> > hash_table(MAX_HASH_LEN);

	string key_i;
	int value_i,choice;

	while(1)
	{
		cout << "Enter 1 to INSERT\nEnter 2 to DELETE\nAnything else to EXIT()\n\n";
		cin >> choice;

		switch(choice)
		{

			/* Insert */
			case 1:
				cout << "Enter string and number (string = key, number = value)\n";
				cin >> key_i >> value_i;
				hash_table = insert_into_hashtable(hash_table,to_lower(key_i),value_i);
				break;

			/* Delete */
			case 2:
				cout << "Enter string to delete\n";
				cin >> key_i;
				hash_table = delete_element_hashtable(hash_table,to_lower(key_i));
				break;
			default:
				goto exit;
		}
	}

exit:
	return 0;
}
