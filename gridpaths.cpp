#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;
int m=1e9+7;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    if(grid[n-1][n-1]=='*'){
        cout<<0<<endl;
        return 0;
    }
    //dp[i][j] -> no of paths from (i,j) to (n-1,n-1)
    //dp[i][j]=dp[i+1][j] + dp[i][j+1]
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    dp[n-1][n-1]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==n-1 && j==n-1){
                continue;
            }
            if(grid[i][j]!='*'){
                if(i+1<n && grid[i+1][j]!='*'){
                    (dp[i][j]+=dp[i+1][j])%=m;
                }
                if(j+1<n && grid[i][j+1]!='*'){
                   (dp[i][j]+=dp[i][j+1])%=m;
                }
            }
            
        }
    }

    cout<<dp[0][0]<<endl;

    return 0;
}