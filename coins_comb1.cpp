#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,x;
    int m=1e9+7;
    cin>>n>>x;
    vector<int>coin_values(n);
    for(int i=0;i<n;i++){
        cin>>coin_values[i];
    }
    vector<int>dp(x+1,0);
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-coin_values[j]>=0){
                (dp[i]+=dp[i-coin_values[j]])%=m;
            }
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}