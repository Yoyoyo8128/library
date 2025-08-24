#include<bits/stdc++.h>
using namespace std;

namespace PollardsRho {
// モンゴメリ乗算modint
struct MontgomeryModInt64 {
    using mint = MontgomeryModInt64;
    using u64 = uint64_t;
    using u128 = __uint128_t;

    // static変数
    // R = 2 ^ 64
    static inline u64 MOD;
    static inline u64 INV_MOD;  // INV_MOD * MOD ≡ 1 (mod 2 ^ 64)
    static inline u64 T128;     // 2 ^ 128 (mod MOD)

    u64 val;

    // コンストラクタ
    // MODを足す？
    MontgomeryModInt64(): val(0) {}
    MontgomeryModInt64(long long v): val(MR((u128(v) + MOD) * T128)) {}

    // 値を返す
    u64 get() const {
        u64 res = MR(val);
        return res >= MOD ? res - MOD : res;
    }

    // static関数
    static u64 get_mod() { return MOD; }
    static void set_mod(u64 mod) {
        MOD = mod;
        T128 = -u128(mod) % mod;
        INV_MOD = get_inv_mod();
    }
    // ニュートン法で逆元を求める
    static u64 get_inv_mod() {
        u64 res = MOD;
        for(int i = 0; i < 5; ++i) res *= 2 - MOD * res;
        return res;
    }
    // モンゴメリリダクション
    static u64 MR(const u128& v) {
        return (v + u128(u64(v) * u64(-INV_MOD)) * MOD) >> 64;
    }

    // 算術演算子
    mint operator - () const { return mint() - mint(*this); }

    mint operator + (const mint& r) const { return mint(*this) += r; }
    mint operator - (const mint& r) const { return mint(*this) -= r; }
    mint operator * (const mint& r) const { return mint(*this) *= r; }
    mint operator / (const mint& r) const { return mint(*this) /= r; }

    mint& operator += (const mint& r) {
        if((val += r.val) >= 2 * MOD) val -= 2 * MOD;
        return *this;
    }
    mint& operator -= (const mint& r) {
        if((val += 2 * MOD - r.val) >= 2 * MOD) val -= 2 * MOD;
        return *this;
    }
    mint& operator *= (const mint& r) {
        val = MR(u128(val) * r.val);
        return *this;
    }
    mint& operator /= (const mint& r) {
        *this *= r.inv();
        return *this;
    }

    mint inv() const { return pow(MOD - 2); }
    mint pow(u128 n) const {
        mint res(1), mul(*this);
        while(n > 0) {
            if(n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }

    // その他演算子
    bool operator == (const mint& r) const {
        return (val >= MOD ? val - MOD : val) == (r.val >= MOD ? r.val - MOD : r.val);
    }
    bool operator != (const mint& r) const {
        return (val >= MOD ? val - MOD : val) != (r.val >= MOD ? r.val - MOD : r.val);
    }

    // 入力
    friend istream& operator >> (istream& is, mint& x) {
        long long t;
        is >> t;
        x = mint(t);
        return is;
    }
    // 出力
    friend ostream& operator << (ostream& os, const mint& x) {
        return os << x.get();
    }
    friend mint modpow(const mint& r, long long n) {
        return r.pow(n);
    } 
    friend mint modinv(const mint& r) {
        return r.inv();
    }
};


using mint = MontgomeryModInt64;
// ミラーラビン素数判定法で素数判定を行う
// isPrime(N): O(logN)で素数判定を行える

// ミラーラビン素数判定法を行う
// 判定する数Nと基の列Aを入力，素数かどうか判定

// 奇数Nに対し，N = 2 ^ s * d + 1と分解する．
// a ^ d ≡ 1 (mod N) と a ^ ((2 ^ r) * d) ≡ -1 (mod N) のどちらも満たさないaがあるとき，
// Nは合成数である.
bool millerRabin(long long N, vector<long long> A) {
    mint::set_mod(N);
    long long s = 0, d = N - 1;
    while(d % 2 == 0) {
        s++;
        d >>= 1;
    }

    for(long long a : A) {
        if(N <= a) return true;
        mint x = mint(a).pow(d);

        if(x == 1) continue;
        long long t;
        for(t = 0; t < s; t++) {
            if(x == N - 1) break;
            x *= x;
        }

        // a ^ d ≡ 1 でも a ^ ((2 ^ r) * d) ≡ -1 でもないならば合成数
        if(t == s) return false;
    }

    // 全ての底で合成数でなければ素数
    return true;
}

bool isPrime(long long N) {
    if(N <= 1) return false;
    if(N == 2) return true;
    if(N % 2 == 0) return false;

    // 4759123141以内なら{2, 7, 61}を試せば十分
    if(N < 4759123141LL) return millerRabin(N, {2, 7, 61});

    // 64bit以内なら{2, 325, 9375, 28178, 450775, 9780504, 1795265022}を試せば十分
    return millerRabin(N, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

long long gcd(long long a, long long b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

long long find_prime_factor(long long N) {
    if(!(N & 1)) return 2;

    // GCDをまとめる数の上限
    long long m = pow(N, 0.125) + 1;

    for(int c = 1; c < N; c++) {
        // 疑似乱数
        auto f = [&](long long a) { return (__uint128_t(a) * a + c) % N; };
        long long y = 0;
        long long g = 1, q = 1; // g : GCD，q : GCDまとめ 
        long long k = 0, r = 1; // k :  
        long long ys;   // バックトラック用変数
        long long x;

        while(g == 1) {
            x = y;

            // k < 3r / 4の間はGCD計算を飛ばす
            while(k < 3 * r / 4) {
                y = f(y);
                k++;
            }

            while(k < r && g == 1) {
                // バックトラック用保存
                ys = y;
                for(int i = 0; i < min(m, r - k); i++) {
                    y = f(y);
                    q = __uint128_t(q) * abs(x - y) % N;
                }
                g = gcd(q, N);
                k += m;
            }

            k = r;
            r *= 2;
        }

        // まとめたgcdがNとなったら
        if(g == N) {
            g = 1;
            y = ys;
            while(g == 1) {
                y = f(y);
                g = gcd(abs(x - y), N);
            }
        }


        // 失敗したら次のcへ
        if(g == N) continue;
        if(isPrime(g)) return g;
        else if(isPrime(N / g)) return N / g;
        else return find_prime_factor(g);
    } // for(int c = 1; c < N; c++)
    return -1;
}

vector<pair<long long, int>> factorize(long long N) {
    vector<pair<long long, int>> ret;
    while(!isPrime(N) && N > 1) {
        long long p = find_prime_factor(N);
        int e = 0;
        while(N % p == 0) {
            e++;
            N /= p;
        }
        ret.push_back({p, e});
    }
    if(N != 1) ret.push_back({N, 1});
    sort(ret.begin(), ret.end());
    return ret;
}

} // namespace PollardsRho
using ll = long long;
int main() {
    ll N;
    cin>>N;
    vector<ll>A(N);
    map<ll,ll>m;
    
    vector<ll>heiho(N);
    for(int i=0;i<N;i++) {
        long long a;
        cin >> a;
        auto v = PollardsRho::factorize(a);

        // int k = 0;
        // for(auto [p, e] : v) {
        //     k += e;
        // }

        // cout << k << " ";
        ll tmp=1;
        ll tmp2=1;
        for(auto [p, e] : v) {
            for(int i = 0; i < e%3; i++) {
                tmp*=p;
            }
            for(int i = 0; i < (1145141919810ll-e)%3; i++) {
                tmp2*=p;
            }
        }
        A[i]=tmp;
        heiho[i]=tmp2;
        m[tmp]++;
    }
    ll ans=0;
    for(int i=0;i<N;i++){
        ans+=max(m[A[i]],m[heiho[i]]);
        m[A[i]]=0;
        m[heiho[i]]=0;
    }
    cout<<ans<<endl;
}