
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,x;
    cin>>n>>x;

    vector<int>price(n);
    vector<int>pages(n);

    for(int i=0;i<n;i++){
        cin>>price[i];
    }

    for(int i=0;i<n;i++){
        cin>>pages[i];
    }

    vector<vector<int>>dp(n+1,vector<int>(x+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
                continue;
            }
            if(j-price[i-1]>=0){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-price[i-1]]+pages[i-1]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    cout<<dp[n][x]<<endl;

    return 0;
}