#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;

typedef long long ll;
int m=1e9+7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll sum=(n*(n+1))/2;
    if(sum%2!=0){
        cout<<0<<endl;
    }
    else{
        sum/=2;
        //dp[i][j]=dp[i-1][j-x[i]]+dp[i-1][j]
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j==0){
                    dp[i][j]=1; 
                }
                else{
                    if(j-i>=0){
                        dp[i][j]=((dp[i-1][j-i])%m+(dp[i-1][j])%m)%m;
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        cout<<dp[n][sum];
    }

    return 0;
}