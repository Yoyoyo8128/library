// 繰り返し二乗法
ll modpow(ll a, ll n, ll mod)
{
    if (a == 0)
    {
        return 0;
    }
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// 割り算
ll Div(ll a, ll b, ll m)
{
    return (a * modpow(b, m - 2, m)) % m;
}

// 階乗
vector<ll> fact(1);
void fac(ll N, ll m)
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        ll ppp = i;
        while (ppp % m == 0)
        {
            ppp /= m;
        }
        fact.pb(fact[i - 1] * (ppp));
        fact[i] %= m;
    }
}

ll v(ll n, ll p)
{
    ll aaans = 0;
    ll nppp = n;
    while (nppp > 0)
    {
        aaans += nppp / p;
        nppp /= p;
    }
    return aaans;
}
// 組み合わせ
ll comb(ll n, ll r, ll m)
{
    if (n < r)
    {
        return 0;
    }

    if (r < 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return 0;
    }
    return Div(fact[n], fact[r] * fact[n - r] % m, m);
}