#include <iostream>
#include <unordered_map>
using namespace std;

/*
	Trie Node:
	 ___________________
	| map <char,trie *> |
	|-------------------|
	| is_endof_word = F |
	|___________________|

*/

struct trie
{
	unordered_map <char, trie *> trie_map;
	bool is_endof_word;
};

trie * allocmem()
{
	trie * node = new trie;
	node->is_endof_word = false;
	return node;
}

trie * insert_into_trie(trie* root, string s, int index)
{
	if(index == (s.length()))
	{
		root->is_endof_word = true;
		return root;
	}

	/* present in map */
	else if(root->trie_map.find(s[index]) != root->trie_map.end())
	{
		root->trie_map[s[index]] = insert_into_trie(root->trie_map[s[index]],s,index+1);
	}
	/* not present in map */
	else
	{
		struct trie * new_temp = allocmem();
		root->trie_map[s[index]] = new_temp;
		root->trie_map[s[index]] = insert_into_trie(root->trie_map[s[index]],s,index+1);
	}

	return root;
}

bool search_in_trie(trie * root, string s, int index)
{
	if(index == s.length() && root->is_endof_word == true)
	{
		return true;
	}
	/* Found character match, continue searching */
	else if(root->trie_map.find(s[index]) != root->trie_map.end())
	{
		return search_in_trie(root->trie_map[s[index]],s,index+1);
	}
	else
	{
		return false;
	}
}

trie * delete_words_in_trie(trie * root, string s, int index)
{
	if(index == s.length() && root->is_endof_word == true)
	{
		cout << "Deleting word: " << s << endl;
		root->is_endof_word = false;
		return root;
	}
	else if (root->trie_map.find(s[index]) != root->trie_map.end())
	{
		root->trie_map[s[index]] = delete_words_in_trie(root->trie_map[s[index]],s,index+1);
		return root;
	}
	else
	{
		return root;
	}
}

int main()
{
	struct trie * root = allocmem();
	string s;

	while(1)
	{
		cout << "Enter 1 to Insert into Trie\nEnter 2 to Search\nEnter 3 to Delete\n\n";
		int choice;
		cin >> choice;

		switch(choice)
		{
			/* Insert */
			case 1:
				cin >> s;
				root = insert_into_trie(root,s,0);
				break;

			/* Search */
			case 2:
				cin >> s;
				if(search_in_trie(root,s,0))
				{
					cout << "Present in Trie\n\n";
				}
				else
				{
					cout << "Absent in Trie\n\n";
				}

				break;

			/* Delete entire words */
			case 3:
				cin >> s;
				root = delete_words_in_trie(root,s,0);
				break;

			default:
				goto exit;
		}
	}
exit:
	return 0;
}
