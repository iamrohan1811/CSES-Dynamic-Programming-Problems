#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int m=1e9+7;
const ll N = 1e6;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int>x(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>x[i];
        sum+=x[i];
    }
    int dp[n+1][sum+1];
    //dp[i][j]-> a subset from (0,i-1) in x sum up to j or not (boolean)

    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j==0){
                dp[i][j]=1;
            }
            else if(i==0){
                dp[i][j]=0;
            }
            else if(j-x[i-1]>=0){
                dp[i][j]=dp[i-1][j-x[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int ans=0;
    vector<int>res;
    for(int j=1;j<=sum;j++){
        if(dp[n][j]){
            ans++;
            res.push_back(j);
        }
    }
    cout<<ans<<endl;
    for(int k:res){
        cout<<k<<" ";
    }
    return 0;
}