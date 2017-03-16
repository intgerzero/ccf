#include <iostream>

using namespace std;

const int INF=1<<30;

int getminval(int n,int *sum){
    int dp[n][n];
    for(int i=0;i<n;i++){
        dp[i][i]=0;
    }
    for(int v=1;v<n;v++){
        for(int i=0;i<n-v;i++){
            int j=v+i;
            dp[i][j]=INF;
            int temp=sum[j]-(i>0?sum[i-1]:0);
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+temp);
            }
        }
    }
    return dp[0][n-1];
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    //int dp[n][n];
    int sum[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    sum[0]=a[0];
    for(int i=1;i<n;i++)
        sum[i]=sum[i-1]+a[i];

    cout<<getminval(n,sum)<<endl;
    return 0;
}
