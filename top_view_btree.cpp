/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {
        
        queue <pair <Node *,long> > q;
        map <int,int> umap;
        
        if(root)
            q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            
            if(umap.find(temp.second) == umap.end())
                umap[temp.second] = temp.first->data;
            // cout << temp.first->data << endl;
            
            q.pop();
            
            if(temp.first->left)
                q.push(make_pair(temp.first->left,temp.second-1));
            if(temp.first->right)
                q.push(make_pair(temp.first->right,temp.second+1));
        }
        
        map <int,int> :: iterator it;
        
        for(it= umap.begin();it != umap.end(); it++){
            cout << it->second << " ";
        }

    }