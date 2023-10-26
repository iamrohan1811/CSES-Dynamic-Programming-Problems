#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;

int n,x;
long long solve(vector<int>coin_values){
    vector<long long>dp(x+1,1e7);
    dp[0]=0;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-coin_values[j]>=0){
                dp[i]=min(dp[i],1+dp[i-coin_values[j]]);
            }
        }
    }
    return dp[x];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>x;
    vector<int>coin_values(n);
    for(int i=0;i<n;i++){
        cin>>coin_values[i];
    }
    long long res=solve(coin_values);
    if(res>=1e7){
        cout<<-1<<endl;
    }
    else{
        cout<<res<<endl;
    }
    return 0;
}