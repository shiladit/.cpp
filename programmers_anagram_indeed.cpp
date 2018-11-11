/* This question came in Indeed Coding Test IIT MADRAS */

#include <bits/stdc++.h>
using namespace std;

bool valid(map <char,int> umap){
	map <char,int> :: iterator it;

	for(it=umap.begin();it!=umap.end();it++){
		if(it->second > 0)
			return false;
	}

	return true;
}

void print_map(map <char,int> umap){

	map <char,int> :: iterator it;

	for(it=umap.begin();it!=umap.end();it++)
		cout << it->first << " --> " << it->second << endl;

}

int find_index(string t){
	string s="programmers";

	// cout << t << endl;

	map <char,int> umap;
	for(int i=0;i<s.length();i++)
		umap[s[i]]++;

	int count = s.length();

	int count1 = 0;

	for(int i=0;i<t.length();i++){
		if(umap.find(t[i]) != umap.end()){
			if(umap[t[i]] > 0){
				umap[t[i]]--;
				count1++;
			}
		}

		if((count == count1) && (valid(umap)))
			return i;
	}

	return -1;
}

string reverse(string s){
	int i=0;
	int j = s.length();

	while(i<j){
		swap(s[i],s[j]);
		i++;
		j--;
	}

	return s;
}

int main() {
	string s;
	s = "pprogrammerxprogrammers";

	int index1= find_index(s);
	cout << index1 << endl;
	s = reverse(s);
	int index2= find_index(s);
	cout << index2 << endl;

	cout << (index2 - index1) << endl;

	
}
