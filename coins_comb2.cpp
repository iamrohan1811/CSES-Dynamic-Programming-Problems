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
    //dp[n][x]
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(j==0){
                dp[i][j]=1;
            }
            else if(i==0){
                dp[i][j]=0;
            }        
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(j-coin_values[i-1]>=0){
                dp[i][j]=((dp[i-1][j])%m+(dp[i][j-coin_values[i-1]])%m)%m;
            }
            else{
                (dp[i][j]+=dp[i-1][j])%=m;
            }
        }
    }

    cout<<dp[n][x]<<endl;
    return 0;
}