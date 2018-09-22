#include<iostream>

using namespace std;

void normal_print(int* arr,int m,int n){
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << *arr++ << " ";
        }
        cout << endl;
    }
    
}

void spiral_print(int arr[4][3],int m,int n){
    
    int k = 0 ;
    int l = 0 ;
    
    while(k<m && l<n){
        
        //Printing first row
        for(int i=l;i<n;i++)
            cout << arr[k][i] << " ";
        k++;
        
        //Print last column
        for(int i=k;i<m;i++)
            cout << arr[i][n-1] << " ";
        n--;
        
        //Print last row
        for(int i=n-1;i>=l;i--)
            cout << arr[m-1][i] << " ";
        m--;
        
        //Print first column
        for(int i=m-1;i>=k;i--)
            cout << arr[i][l] << " ";
        l++;
        
        // break;
    }
}

int main() {
    int arr[4][3] = {{1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12}};
    
    int dim1=4;
    int dim2=3;
    
    normal_print(&arr[0][0],dim1,dim2);
    
    cout << "\n-------------------------\n";
    
    spiral_print(arr,dim1,dim2);
    
}
