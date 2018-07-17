#include <bits/stdc++.h>

using namespace std;


bool sortbyfirst(const pair<long,int> &a,const pair<long,int> &b){
        
    return (a.first < b.first);
    
    }

// Complete the minimumLoss function below.
void minimumLoss(vector<pair <long,int> > price) {

    sort(price.begin(),price.end(),sortbyfirst);

    // for(int i=0;i<price.size();i++) {
    //     cout << price[i].first << " --  " << price[i].second << endl;
    // }    

    int i=0;int j=1;
    int diff = INT_MAX;

    while(j != price.size()) {
        if((((price[j].first)-(price[i].first )) < diff) && ((price[j].second) < (price[i].second)))
            diff = (price[j].first-price[i].first);

        i++;j++;

    }

    cout << diff << endl;

}

int main()
{

    int n;
    cin >> n;

    long price_item ;
    vector <pair <long,int> > price(n);

    for (int i = 0; i < n; i++) {
        cin >> price_item;

        price[i] = make_pair(price_item,i);
    }

    minimumLoss(price);

 
    return 0;
}
