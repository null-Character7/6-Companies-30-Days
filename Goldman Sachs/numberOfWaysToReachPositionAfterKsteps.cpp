class Solution {
public:
    #define MOD 1000000007
    #define N 2000
    #define ll long long
    ll mod_add(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}
    ll mod_mul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
    ll mod_sub(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a - b) % MOD) + MOD) % MOD;}
    ll inv(ll i) {
        if (i == 1) return 1; 
        return (MOD - ((MOD / i) * inv(MOD % i)) % MOD) % MOD;
    }
    ll *fact;
    void calFact() {
        fact=new ll[N];
        fact[0] = 1;
        fact[1] = 1;
        for(int i=2; i<N; i++) fact[i] = mod_mul(fact[i-1], i);
    }
    int numberOfWays(int start, int end, int k) {
        calFact();
        int dif=abs(end-start); // mandatory movements
        int l=0,r=0;
        // l = total left movement 
        // r = total right movement
        // find permutation of l and r, thats it!
        (dif < 0) ? l = dif : r = dif;
        int extra=k-dif; // extra movements, half towards left, half towards right, net movement 0
        if((extra & 1) || (extra<0)){
            return 0;
        }
        l += (extra/2);
        r += (extra/2);
        ll x=fact[l+r];
        ll y=fact[l];
        ll z=fact[r];
        ll p=mod_mul(y,z);
        ll ans=mod_mul(x,inv(p));
        return ans;
    }
};
