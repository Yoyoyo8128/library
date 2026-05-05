struct RollingHash {
    using ull = unsigned long long;
    static const ull mod = (1ULL << 61) - 1;

    static const ull base = 20090926; //My Birthday.

    vector<ull> power;
    vector<ull> hash;

    static ull mul(ull a, ull b) {
        __uint128_t t = (__uint128_t)a * b;
        t = (t >> 61) + (t & mod);
        if (t >= mod) t -= mod;
        return (ull)t;
    }

    static ull add(ull a, ull b) {
        a += b;
        if (a >= mod) a -= mod;
        return a;
    }

    static ull sub(ull a, ull b) {
        a += mod - b;
        if (a >= mod) a -= mod;
        return a;
    }

    RollingHash(const string &s) {
        int n = s.size();
        power.resize(n + 1);
        hash.resize(n + 1);

        power[0] = 1;
        for (int i = 0; i < n; i++) {
            power[i + 1] = mul(power[i], base);
        }

        hash[0] = 0;
        for (int i = 0; i < n; i++) {
            hash[i + 1] = add(mul(hash[i], base), s[i]+1);
        }
    }

    //[l, r)
    ull get(int l, int r) const {
        return sub(hash[r], mul(hash[l], power[r - l]));
    }

    // s[i..] と s[j..] のLCP
    int lcp(int i, int j) const {
        int n = hash.size() - 1;
        int low = 0;
        int high = min(n - i, n - j) + 1;

        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (get(i, i + mid) == get(j, j + mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }
};