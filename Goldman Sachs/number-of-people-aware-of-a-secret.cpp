class Solution {
public:
#define ll long long
    ll dp[1001];
    ll m=1e9+7;
    ll helper(int day,int &n,int &delay,int &forget){
        if(dp[day]!=-1)
            return dp[day];
        ll ans=1;
        if(day+forget<=n)
            ans--;
        for(int start=day+delay;start<(min(day+forget,n+1));start++){
            ans+=helper(start,n,delay,forget);
            ans%=m;
        }
        return dp[day]=ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp,-1,sizeof(dp));
        return helper(1,n,delay,forget);
    }
    
};
