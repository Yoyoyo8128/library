
ll modpow(ll a,ll n,ll mod){
    if(a==0){
        return 0;
    }
    ll res=1;
    while (n>0){
        if (n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    while(res<0)res+=mod;
    return res;
}

ll Div(ll a,ll b,ll m){
    ll res=(a*modpow(b,m-2,m))%m;
    while(res<0)res+=m;
    return res;
}

struct Comb{
    int _n;
    ll mod;
    vector<ll> fact, inv, finv;

    Comb(int n, ll mod) : _n(n), mod(mod), fact(n+1), inv(n+1), finv(n+1) {
        fact[0] = fact[1] = 1;
        inv[1] = 1;
        finv[0] = finv[1] = 1;
        for (int i = 2; i <= n; i++) {
            fact[i] = fact[i-1] * i % mod;
            inv[i] = mod - mod / i * inv[mod % i] % mod; // ←ここ重要
            finv[i] = finv[i-1] * inv[i] % mod;
        }
    }

    ll comb(int n, int r) {
        if (n < r || r < 0) return 0;
        assert(n<=_n);
        return fact[n] * finv[r] % mod * finv[n-r] % mod;
    }
};
