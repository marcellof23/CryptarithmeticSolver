#include <bits/stdc++.h>
using namespace std;

int dp[100069];
int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	dp[0] = arr[0] > 0 ? arr[0] : 0;
	if(n==1)
	{
		cout<<arr[0]<<endl;
		return 0;
	}
	dp[1] = max(dp[0],dp[0]+arr[1]);
	for(int i=2;i<=n;i++)
	{
		dp[i] = max(dp[i-1],dp[i-2] + arr[i]);
		dp[i] = max(dp[i],dp[i-2]);
		if(i==n)
		{
			dp[n] = max(dp[i-1],dp[i-2]);
		}
	}
	cout<<dp[n]<<endl;
}