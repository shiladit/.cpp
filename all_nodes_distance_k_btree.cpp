#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

TreeNode* root;

TreeNode* new_node(int val){
	struct TreeNode* temp = new TreeNode;
	temp->val = val;
	temp->left = temp->right = NULL;
	
	return temp;
}

map <int, vector <int> > adj_list;
vector <int> result;

void build_graph(TreeNode* root)
{
    if(root->left)
    {
        adj_list[root->val].push_back(root->left->val);
        adj_list[root->left->val].push_back(root->val);
        build_graph(root->left);
    }

    if(root->right)
    {
        adj_list[root->val].push_back(root->right->val);
        adj_list[root->right->val].push_back(root->val);
        build_graph(root->right);
    }

    return;
}

void dfs(int val, int k, vector <bool> visited)
{
    visited[val] = true;

    if(k==0)
    {
        result.push_back(val);
        return;
    }

    vector <int> arr = adj_list[val];
    for(int i=0;i<arr.size();i++)
        if(visited[arr[i]] == false)
            dfs(arr[i],k-1,visited);

    return;
}

vector <int> distance(TreeNode* root,TreeNode* target,int k)
{

    if(k <= 0)
    {
        result.push_back(target->val);
        return result;
    }

    TreeNode* temp = root;

    build_graph(temp);

    map <int, vector <int> > :: iterator it;

    /* DEBUG
    for(it = adj_list.begin(); it!=adj_list.end(); it++)
    {
        cout << it->first << " --> ";
        vector <int> temp = it->second;
        for(int i=0;i<temp.size();i++)
            cout << temp[i] <<  " ";
        cout << endl;
    }
    */

    it = adj_list.find(target->val);
    if(it == adj_list.end())
    {
        return result;
    }
    
    vector <int> arr = it->second;
    vector <bool> visited(1000, false);
    visited[it->first] = true;

    for(int i=0;i<arr.size();i++)
    {
        dfs(arr[i],k-1,visited);
    }

    return result;
}


int main() {

    root = new_node(3);
    root->left = new_node(5);
    root->right = new_node(1);
    root->left->left = new_node(6);
    root->left->right = new_node(2);
    root->left->right->left = new_node(7);
    root->left->right->right = new_node(4);
    root->right->left = new_node(0);
    root->right->right = new_node(8);

    TreeNode* target = root->left->right->right;
    int k;
    cin >> k;

    vector <int> result = distance(root,target,k);

    for(int i=0;i<result.size();i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}
