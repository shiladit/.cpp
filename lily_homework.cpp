#include <bits/stdc++.h>

using namespace std;


void print_umap(map <long,long> umap){
    map <long,long> :: iterator it;

    for(it = umap.begin();it != umap.end();it ++){
        cout << it->first << " --> " << it->second << endl; 
    }
}

int main() {
    long size,temp;
    cin >> size;
    
    vector <long> arr;
    vector <long> arr_new; //Creating copy of input array
    vector <long> sorted_arr;

    map <long,long> umap;
    map <long,long> umap1; //Creating copy of map

    int i=0;
    
    while(size--){
        cin >> temp;
        arr.push_back(temp);
        arr_new.push_back(temp);
        sorted_arr.push_back(temp);
        umap[temp] = i;
        umap1[temp] = i;
        i++;
    }
    
    sort(sorted_arr.begin(),sorted_arr.end());
    
    //Checking for Ascending Sequence

    map <long,long> :: iterator it;

    int swap_f = 0;

    // print_umap(umap);

    for(int i=0;i<arr.size();i++){
        if(arr[i] != sorted_arr[i]){
            swap_f++;
            it = umap.find(sorted_arr[i]);
            int pos = it->second;
            swap(arr[i],arr[it->second]);
            umap[arr[it->second]] = pos;
            // print_umap(umap);

        }
    }

    //Checking for Descending Sequence

    sort(sorted_arr.begin(),sorted_arr.end(),greater <long> ());

    int swap_d = 0;

    // print_umap(umap);

    for(int i=0;i<arr_new.size();i++){
        if(arr_new[i] != sorted_arr[i]){
            swap_d++;
            it = umap1.find(sorted_arr[i]);
            int pos1 = it->second;
            swap(arr_new[i],arr_new[it->second]);
            umap1[arr_new[it->second]] = pos1;
            // print_umap(umap1);

        }
    }


    cout << min(swap_d,swap_f) << endl;

}