#define _GLIBCXX_DEBUG



#pragma region Yoyoyo

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using ld = long double;
using i128 = __int128_t;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const string Yes = "Yes";
const string No = "No";
const string YES = "YES";
const string NO = "NO";
const string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll MOD = 1000000007;
const ll mod = 998244353;
const long long inf = 1ll << 60;
const long double PI = 3.1415926535897932384626;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define faster ios::sync_with_stdio(false);cin.tie(nullptr);
const vector<int> dx = {0, 1, 0, -1, 1, -1, -1, 1};
const vector<int> dy = {1, 0, -1, 0, 1, 1, -1, -1};
using mint = modint998244353;
using Mint = modint1000000007;
using pint = modint;


#define YESNO(T)               \
    if (T)                     \
    {                          \
        cout << "YES" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "NO" << endl;  \
    }
#define yesno(T)               \
    if (T)                     \
    {                          \
        cout << "yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "no" << endl;  \
    }
#define YesNo(T)               \
    if (T)                     \
    {                          \
        cout << "Yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "No" << endl;  \
    }
#define inV(vec)                        \
    for (ll i = 0; i < vec.size(); i++) \
        cin >> vec[i];
#define outV(vec)                       \
    for (ll i = 0; i < vec.size(); i++) \
    {                                   \
        cout << vec[i] << " ";          \
    }                                   \
    cout << endl;
#define print(s) cout << s << endl;
#define updiv(n, x) (n + x - 1) / x
#define rounddiv(n, x) (ll)((double)(n) / (double)(x) + 0.5)
#define fix(n)                \
    fixed << setprecision(n)
template <typename T>
inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template <typename T>
inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template <class T>
ll sum(const T &a) { return accumulate(all(a), 0LL); }

// pair_out
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p)
{
    os << p.first << " " << p.second;
    return os;
}
// pair_in
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p)
{
    is >> p.first >> p.second;
    return is;
}
// vector_out
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    int s = (int)v.size();
    for (int i = 0; i < s; i++)
        os << (i ? " " : "") << v[i];
    return os;
}
// vector_in
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &x : v)
        is >> x;
    return is;
}
//__int128_t_in
istream &operator>>(istream &is, __int128_t &x)
{
    string S;
    is >> S;
    x = 0;
    int flag = 0;
    for (auto &c : S)
    {
        if (c == '-')
        {
            flag = true;
            continue;
        }
        x *= 10;
        x += c - '0';
    }
    if (flag)
        x = -x;
    return is;
}
//__uint128_t_in
istream &operator>>(istream &is, __uint128_t &x)
{
    string S;
    is >> S;
    x = 0;
    for (auto &c : S)
    {
        x *= 10;
        x += c - '0';
    }
    return is;
}
//__int128_t_out
ostream &operator<<(ostream &os, __int128_t x)
{
    if (x == 0)
        return os << 0;
    if (x < 0)
        os << '-', x = -x;
    string S;
    while (x)
        S.push_back('0' + x % 10), x /= 10;
    reverse(begin(S), end(S));
    return os << S;
}
//__uint128_t_out
ostream &operator<<(ostream &os, __uint128_t x)
{
    if (x == 0)
        return os << 0;
    string S;
    while (x)
        S.push_back('0' + x % 10), x /= 10;
    reverse(begin(S), end(S));
    return os << S;
}
// vector<vector>_out
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << endl;
    }
    return os;
}
// vector<vector<vector>>_out
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<vector<T>>> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << "i = " << i << endl;
        os << v[i];
    }
    return os;
}
// map_out
template <typename T, typename S>
ostream &operator<<(ostream &os, const map<T, S> &m)
{
    for (auto &[key, val] : m)
    {
        os << key << ":" << val << " ";
    }
    return os;
}
// set_out
template <typename T>
ostream &operator<<(ostream &os, const set<T> &st)
{
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++)
    {
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}
// multiset_out
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &st)
{
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++)
    {
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}
// queue_out
template <typename T>
ostream &operator<<(ostream &os, queue<T> q)
{
    while (q.size())
    {
        os << q.front() << " ";
        q.pop();
    }
    return os;
}
// deque_out
template <typename T>
ostream &operator<<(ostream &os, deque<T> q)
{
    while (q.size())
    {
        os << q.front() << " ";
        q.pop_front();
    }
    return os;
}
// stack_out
template <typename T>
ostream &operator<<(ostream &os, stack<T> st)
{
    while (st.size())
    {
        os << st.top() << " ";
        st.pop();
    }
    return os;
}
// priority_queue_out
template <class T, class Container, class Compare>
ostream &operator<<(ostream &os, priority_queue<T, Container, Compare> pq)
{
    while (pq.size())
    {
        os << pq.top() << " ";
        pq.pop();
    }
    return os;
}
#if __has_include(<atcoder/all>)
// 998244353_in
istream &operator>>(istream &a, mint &b)
{
    long long tmp;
    a >> tmp;
    b = tmp;
    return a;
}
// 998244353_out
ostream &operator<<(ostream &a, mint &b)
{
    a << b.val();
    return a;
}
// 1000000007_in
istream &operator>>(istream &a, Mint &b)
{
    long long tmp;
    a >> tmp;
    b = tmp;
    return a;
}
// 1000000007_out
ostream &operator<<(ostream &a, Mint &b)
{
    a << b.val();
    return a;
}
#endif

template<class... Args>
void debug_out(Args... args) {
    int _i = 0;
    ((cerr << ( _i++ ? ", " : " ") << args), ...);
    cerr << "\n";
}

#pragma endregion Yoyoyo



#define debug(...) do { \
    cerr << "[" << #__VA_ARGS__ << "]:"; \
    debug_out(__VA_ARGS__); \
} while(0)



int main(){
    faster;
    
}