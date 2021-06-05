#include <bits/stdc++.h>

using namespace std;

struct tree{

tree* left_child;
tree* right_child;
int nodeval;

};

int main() {


ifstream inputfile; 
inputfile.open("values.dat");

vector <string> val_array;

if(inputfile.is_open()) {
    string temp;
    while(getline(inputfile, temp)){
          val_array.push_back(temp);
    }
}

tree* root = NULL;

root = construct_tree(root); //function returns the root of the binary tree

return 0;
}
