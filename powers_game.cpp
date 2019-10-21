//shiladitya
#include <iostream>

using namespace std;

int main(){

int t;
scanf("%d",&t);

for(int i=0;i<t;i++){
    int x;
    scanf("%d",&x);
    if(x%8)
        printf("First\n");
    else
        printf("Second\n");
}

}
