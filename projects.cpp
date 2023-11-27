#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;

typedef long long ll;

struct project{
    int start;
    int end;
    int reward;
};

bool comparator(const project &p1,const project &p2){
    return p1.end<p2.end;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<project>p(n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i].start>>p[i].end>>p[i].reward;
    }
    sort(p.begin()+1,p.end(),comparator);
    vector<int>lastDates(n+1);
    for(int i=1;i<=n;i++){
        lastDates[i]=p[i].end;
    }
    vector<ll>dp(n+1,0);
    
    for(int i=1;i<=n;i++){
        int j=lower_bound(lastDates.begin(),lastDates.end(),p[i].start)-lastDates.begin()-1;
        dp[i]=max(dp[i-1],dp[j]+p[i].reward);
    }

    cout<<dp[n];

    return 0;
}