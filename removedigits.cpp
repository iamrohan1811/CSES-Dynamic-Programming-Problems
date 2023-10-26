#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;
// int solve(int x,vector<int>dp){
//     if(x==0){
//         return 0;
//     }
//     else if(dp[x]!=1e9){
//         return dp[x];
//     }
//     for(char c:to_string(x)){
//         dp[x]=min(dp[x],solve(x-(c-'0'),dp)+1);
//     }
//     return dp[x];
// }

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int>dp(n+1,1e9);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(char c:to_string(i)){
            dp[i]=min(dp[i],dp[i-(c-'0')]+1);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}