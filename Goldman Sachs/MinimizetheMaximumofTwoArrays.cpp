class Solution {
public:
    #define ll long long
    ll lcm(ll a,ll b){
        ll x=__gcd(a,b);
        return ((a*b)/x);
    }
    bool isVal(ll mid,ll div1,ll div2,ll cnt1,ll cnt2){
        ll occ1=(mid/div1); // divisible by div1
        ll occ2=(mid/div2); // divisible by div2
        ll both=(mid/lcm(div1,div2)); // divisible by both div1 and div2
        ll onlydiv1=occ1-both; // only divisible by div1
        ll onlydiv2=occ2-both; // only divisible by div2
        ll nonediv=mid-onlydiv1-onlydiv2-both; // divisible by none
        // partition the nonediv greedily in two parts such that both count is more than required
        return ((nonediv-max((ll)0,cnt1-onlydiv2) + onlydiv1 >= cnt2) 
                && (nonediv-max((ll)0,cnt2-onlydiv1) + onlydiv2 >= cnt1) );
    }
    int minimizeSet(int div1, int div2, int cnt1, int cnt2) {
        ll lo=2,hi=1e18;
        ll mid=-1,ans=1e18;
        while(lo<=hi){
            mid=lo+((hi-lo)>>1);
            if(isVal(mid,div1,div2,cnt1,cnt2)){
                hi=mid-1;
                ans=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};
