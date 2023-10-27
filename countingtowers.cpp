#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int m=1e9+7;
const ll N = 1e6;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll dp[N][2];
    //memset(dp,0,sizeof(dp));
    //dp[i][j]-> no of ways of filling tower uptill i with j+1 block on the top
    //dp[i][0]=2*dp[i-1][0] +dp[i-1][1]
    //dp[i][1]=4*dp[i-1][1] + dp[i-1][0];
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<N;i++){
        dp[i][0]=(2*dp[i-1][0]+dp[i-1][1])%m;
        dp[i][1]=(4*dp[i-1][1]+dp[i-1][0])%m;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<(dp[n-1][0]+dp[n-1][1])%m<<endl;
    }
    return 0;
}