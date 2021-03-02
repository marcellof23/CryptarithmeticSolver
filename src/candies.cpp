#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector <int> arr,dp;
    for(int i=0;i<n;i++)
    {
    	int x;
    	cin>>x;
        arr.push_back(x);
        dp.push_back(0);
    }
    int ans = 0;
    dp[0] = 1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            dp[i] = dp[i-1] + 1 ;
        }
        else if(arr[i] == arr[i-1])
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = 1;
            int j = 0;
            while(dp[i-j] == dp[i-(j+1)] && arr[i-(j+1)] > arr[i-j])
            {
                dp[i-(j+1)]++;
                j++;
            }

        }
    }
    for(int i=0;i<dp.size();i++)
    {
        ans += dp[i];
    }
    cout<<ans<<endl;
    
}