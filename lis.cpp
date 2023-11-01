#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int>x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    vector<int>lis;
    lis.push_back(x[0]);
    for(int i=1;i<n;i++){
        if(x[i]>lis.back()){
            lis.push_back(x[i]);
        }
        else{
            int it=lower_bound(lis.begin(),lis.end(),x[i])-lis.begin();
            lis[it]=x[i];
        }
    }
    cout<<lis.size();
    return 0;
}