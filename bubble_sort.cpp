#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int n; long temp;
    vector <long> arr;
    cin >> n;

    /*input */
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    long swaps = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
            /* do swap and increment counter */
                int a = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = a;

                swaps++;
            }
        }

    printf("Array is sorted in %ld swaps.\n", swaps);
    printf("First Element: %ld \n", arr[0]);
    printf("Last Element: %ld \n", arr[arr.size()-1]);
}
