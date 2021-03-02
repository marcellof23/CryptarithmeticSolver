#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100069;
int dp[MAXN];
int dpp[MAXN];
int arr[MAXN];
int main()
{
	long long n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	dp[0] = 1;
	dpp[n-1] = 1;
	for(int i=1;i<n;i++)
	{
		if(arr[i] > arr[i-1])
		{
			dp[i] = dp[i-1] + 1;
		}
		else
		{
			dp[i] = 1;
		}
	}
	for(int i=n-2;i>=0;i--)
	{
		if(arr[i] > arr[i+1])
		{
			dpp[i] = dpp[i+1] + 1;
		}
		else
		{
			dpp[i] = 1;
		}
	}

	for(int i=0;i<n;i++)
	{
		if(dp[i]>dpp[i])
			ans+=dp[i];
		else
			ans+=dpp[i];
	}
	cout<<ans<<endl;
}