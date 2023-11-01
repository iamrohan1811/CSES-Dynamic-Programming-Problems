#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int>x(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>x[i];
        sum+=x[i];
    }
    //dp[i][j]=max(x[i]-dp[i+1][j],x[j]+\-dp[i][j-1])
    // maximization of differences of scores in the range [i,j]
    vector<vector<ll>>dp(n,vector<ll>(n));
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j){
                dp[i][j]=x[i];
            }
            else{
                dp[i][j]=max(x[i]-dp[i+1][j],x[j]-dp[i][j-1]);
            }
        }
    }
    cout<<(sum+dp[0][n-1])/2;
    return 0;
}