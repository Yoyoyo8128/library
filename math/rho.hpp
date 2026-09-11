#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using ll = long long;
using i128 = __int128_t;

// 繰り返し二乗法 (a^b mod m)
ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (ll)((i128)res * base % mod);
        base = (ll)((i128)base * base % mod);
        exp /= 2;
    }
    return res;
}

// Miller-Rabin 素数判定 (2^64以下で確定)
bool is_prime(ll n) {
    if (n <= 1) return false; // 1以下は素数ではない
    if (n == 2 || n == 3 || n == 5 || n == 7) return true;
    if (n % 2 == 0) return false;

    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    // 2^64以下のすべての数に対して確定判定可能なベース
    static const ll bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (ll a : bases) {
        if (a % n == 0) continue;
        ll x = power(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (int r = 1; r < s; r++) {
            x = (ll)((i128)x * x % n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

// GCD (最大公約数)
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

// ポラードのロー法 (素因数を1つ見つける)
ll pollard_rho(ll n) {
    if (n % 2 == 0) return 2;
    if (is_prime(n)) return n;

    ll step = 0;
    while (true) {
        step++;
        ll x = step, y = step, d = 1;
        auto f = [&](ll x) {
            return (ll)(((i128)x * x + step) % n);
        };
        while (d == 1) {
            x = f(x);
            y = f(f(y));
            d = gcd(x > y ? x - y : y - x, n);
        }
        // d が n と等しくなってしまった場合は失敗なので、stepを増やして乱数(関数f)を変えてやり直し
        if (d < n) return d;
    }
}

// 素因数分解の本体
void factorize_impl(ll n, std::vector<ll>& res) {
    if (n <= 1) return;
    if (is_prime(n)) {
        res.push_back(n);
        return;
    }
    ll p = pollard_rho(n);
    factorize_impl(p, res);
    factorize_impl(n / p, res);
}

// 素因数分解 (昇順にソートして返す)
std::vector<ll> factorize(ll n) {
    std::vector<ll> res;
    factorize_impl(n, res);
    std::sort(res.begin(), res.end());
    return res;
}


// 使い方の一例
/*
int main() {
    ll n = 999999999989LL * 999999LL; // 1e18付近のテスト
    
    std::vector<ll> factors = factorize(n);
    
    std::cout << n << " = ";
    for (size_t i = 0; i < factors.size(); i++) {
        std::cout << factors[i] << (i + 1 == factors.size() ? "" : " * ");
    }
    std::cout << std::endl;
    
    return 0;
}
*/