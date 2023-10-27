#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int m=1e9+7;
const ll N = 1e6;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b;
    cin>>a>>b;
    int dp[a+1][b+1];
    //dp[i][j]-> no of min cuts from a rect of i*j size 
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(i==j){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=INT_MAX;
                //horizontal cuts
                for(int k=1;k<i;k++){
                    dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
                }
                //vertical cuts
                for(int k=1;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
                }
            }
        }
    }
    cout<<dp[a][b];
    return 0;
}