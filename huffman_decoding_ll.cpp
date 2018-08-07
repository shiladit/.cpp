void decode_huff(node * root, string s) {
    
    
    node* temp = root;
    string t;
    
    for(int i=0 ; i<s.length() ; ){
        while(temp->left != NULL && temp->right != NULL){
            
            if(s[i] == '0'){
                temp= temp->left;
                 
            }
            else if(s[i] == '1'){
                temp= temp->right;
                     
            }
            i++;           
        }
        
        t = t + (temp->data); //append
        temp = root;
    }
    
    cout << t << endl;

}