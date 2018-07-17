#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    
//     for(int i=0;i<w.size();i++)
//         cout << w[i] << " ";
// cout << endl;
    
    int pivot=-1;
    
    for(int i=1;i<w.size();i++){
        if(w[i-1]<w[i])
            pivot=i-1;
    }
    
    int val_piv = w[pivot];
    int swap_ind;
    
    if(pivot == -1) {
        return "no answer";
        
    }
    else {
        for(int j=pivot+1;j<w.size();j++)
            if(w[j]>val_piv)
                swap_ind = j;
            
    }
    
    int temp = w[pivot];
    w[pivot] = w[swap_ind];
    w[swap_ind]= temp;
    
    int i=pivot+1;
    
    int j= w.size()-1;
    while(i<j){
        int temp = w[i];
        w[i]= w[j];
        w[j] = temp;
        i++;
        j--;
    }
    
    return w;

}

int main()
{

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);
        
        cout << result << endl; 
    }
    
    return 0;
}
