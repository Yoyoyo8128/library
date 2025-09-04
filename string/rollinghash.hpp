template< unsigned mod >
struct RollingHash {
  vector< unsigned > hashed, power;

  inline unsigned mul(unsigned a, unsigned b) const {
    unsigned long long x = (unsigned long long) a * b;
    unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
    asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
    return m;
  }

  RollingHash(const string &s, unsigned base = 10007) {
    int sz = (int) s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for(int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = mul(hashed[i], base) + s[i];
      if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;
    }
  }

  unsigned get(int l, int r) const {
    unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
    if(ret >= mod) ret -= mod;
    return ret;
  }

  unsigned connect(unsigned h1, int h2, int h2len) const {
    unsigned ret = mul(h1, power[h2len]) + h2;
    if(ret >= mod) ret -= mod;
    return ret;
  }

  int LCP(const RollingHash< mod > &b, int l1, int r1, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = -1, high = len + 1;
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
      else high = mid;
    }
    return (low);
  }
};

using RH = RollingHash< 1000000007 >;


/*
int main(){
     string s = "abracadabra";
    RH rh(s);

    // 部分文字列 s[0:3] ("abr") のハッシュ値
    ll h1 = rh.get(0, 3);
    cout << "hash(\"abr\") = " << h1 << endl;

    // 部分文字列 s[7:11] ("abra") のハッシュ値
    ll h2 = rh.get(7, 11);
    cout << "hash(\"abra\") = " << h2 << endl;

    // ハッシュ値比較（部分文字列の一致判定）
    if (h1 == rh.get(7, 10)) {
        cout << "s[0:3] == s[7:10]" << endl;
    }

    // 別の文字列との LCP
    string t = "abracad";
    RH rh2(t);
    int lcp_len = rh.LCP(rh2, 0, s.size(), 0, t.size());
    cout << "LCP(s, t) length = " << lcp_len << endl;
    
}*/