#include <bits/stdc++.h>

using namespace std;


bool check_monotonic(vector <int> arr){
    int len= arr.size();
    
    for(int i=0;i<len-1;i++)
        if(arr[i]>arr[i+1]){
           return false;
        }
    
    return true;
}

void check_swap(vector <int> arr) {
    int len = arr.size();
    int count_arr[len-1];
    
    int count_0 = 0;
    int count_1 = 0;
    
    //Creating Auxilliary array
    for(int i=0;i<len-1;i++){
        if(arr[i]<arr[i+1]){
            count_arr[i] = 1;
            count_1++;
        }
        else{
            count_arr[i] = 0;   
            count_0++;
        }
    }

    if(count_0 == 1){
        int index1 = -1;
        int index2 = -1;
        for(int i=0;i<len-1;i++){  // 1 5 7 4 | 1 1 0. 3 5 4 8 9   | 1 0 1 1
            if(count_arr[i] == 0)
                index1=i;
        }

        index2 = index1+1;

        int temp = arr[index2];
        arr[index2]=arr[index1];
        arr[index1]= temp;

        bool flag =check_monotonic(arr);
        if(flag == true){
            cout << "yes\n" << "swap" << " " << index1+1 << " " << index2+1 << endl;
        }
        else
            cout << "no" << endl;

        return;
    }
    
    if(count_0 == 2){
        int i=0;
        int index1 = -1;
        int index2 = -1;
        while(i != len-1){
            if(count_arr[i] == 0 && index1 == -1){
                index1 = i;
                i++;
            }
            else if(count_arr[i] == 0 && index1 != -1){
                index2 = i+1;
                i++;
            }
            else
                i++;
        }

        // cout << index1 <<" "<< index2 << endl;
        
        int temp = arr[index2];
        arr[index2]= arr[index1];
        arr[index1] = temp;

        // cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
        
        bool flag =check_monotonic(arr);
        if(flag == true){
            cout << "yes\n" << "swap" << " " << index1+1 << " " << index2+1 << endl;
        }
        else
            cout << "no" << endl;

        return;
        
    }

    if(count_0 > 2){
        int index1 = -1;
        int index2 = -1;
        for(int i=0;i<len-1;i++){
            if(count_arr[i] == 0 && index1 == -1){
                index1 = i;
                for(int j=i+1;j<len-1;j++){
                    if(count_arr[j] == 1 && index2 == -1)
                        index2 = j;
                }
            }
        }

    int a= index1+1;
    int b= index2+1;

    while(index1 < index2){
        int temp = arr[index2];
        arr[index2]= arr[index1];
        arr[index1] = temp;
        index1++;
        index2--;
    }

    bool flag =check_monotonic(arr);
        if(flag == true){
            cout << "yes\n" << "reverse" << " " << a << " " << b << endl;
        }
        else
            cout << "no" << endl;

        return;

    }
}


// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
 bool flag= false;
 
 flag= check_monotonic(arr);
    if(flag ==true){
        cout << "yes\n" ; 
        return ;
    }

    check_swap(arr);

}

int main()
{
    int n;
    int temp;
    cin >> n;
    
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> temp;

        arr[i] = temp;
    }

    almostSorted(arr);

    return 0;
}
