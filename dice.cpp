#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;


// f(n)+=f(n-x) for x in[1,6]

int m=1e9+7;
int n;
long long dice(int n){
    vector<long>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j>=0){
                dp[i]=((dp[i]%m)+(dp[i-j]%m))%m;
            }
        }
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    cout<<dice(n)<<endl;
    return 0;
}