#include<bits/stdc++.h>

using namespace std;
 

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    vector <int> sum;
    int carry=0;

    while(l1->next != NULL || l2->next != NULL){
    	
    	if((l1->val+l2->val + carry) > 9){
    		
    		int a = (l1->val+l2->val+carry)%10;
    		carry =1;
    		sum.push_back(a);
    	}
    	else{
    		sum.push_back(carry + l1->val+l2->val);
    		carry =0;
    	}


    	l1=l1->next;
    	l2=l2->next;
    }


        
    }
};


