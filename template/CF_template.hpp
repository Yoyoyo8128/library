#pragma region Yoyoyo

#ifndef LOCAL
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using i128t = __int128_t;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const string Yes = "Yes";
const string No = "No";
const string YES = "YES";
const string NO = "NO";
const ll MOD = 1000000007;
const ll mod = 998244353;
const long long inf = 1ll << 60;
const int inft = 1e9;
const long double PI = 3.1415926535897932384626;
const vector<int> dx = {0, 1, 0, -1, 1, -1, -1, 1};
const vector<int> dy = {1, 0, -1, 0, 1, 1, -1, -1};
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define faster ios::sync_with_stdio(false);cin.tie(nullptr);
#define print(s) cout << s << "\n";

#define YESNO(T){              \
    if (T){                    \
        cout << "YES" << "\n"; \
    }else{                     \
        cout << "NO" << "\n";  \
    }                          \
}
#define yesno(T){              \
    if (T){                    \
        cout << "yes" << "\n"; \
    }else{                     \
        cout << "no" << "\n";  \
    }                          \
}
#define YesNo(T){              \
    if (T){                    \
        cout << "Yes" << "\n"; \
    }else{                     \
        cout << "No" << "\n";  \
    }                          \
}

template <typename T>
inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template <typename T>
inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template <class T>
auto sum(const vector<T> &a){
    T ans = 0;
    for(auto e : a)ans += e;
    return ans;
}

// pair_out
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p){
    os << p.first << " " << p.second;
    return os;
}
// pair_in
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p){
    is >> p.first >> p.second;
    return is;
}
// vector_out
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v){
    int s = (int)v.size();
    for (int i = 0; i < s; i++){
        os << (i ? " " : "") << v[i];
    }
    return os;
}
// vector_in
template <typename T>
istream &operator>>(istream &is, vector<T> &v){
    for (auto &x : v)is >> x;
    return is;
}
//__int128_t_in
istream &operator>>(istream &is, __int128_t &x){
    string S;
    is >> S;
    x = 0;
    int flag = 0;
    for (auto &c : S){
        if (c == '-'){
            flag = true;
            continue;
        }
        x *= 10;
        x += c - '0';
    }
    if (flag)x = -x;
    return is;
}
//__uint128_t_in
istream &operator>>(istream &is, __uint128_t &x){
    string S;
    is >> S;
    x = 0;
    for (auto &c : S){
        x *= 10;
        x += c - '0';
    }
    return is;
}
//__int128_t_out
ostream &operator<<(ostream &os, __int128_t x){
    if (x == 0)return os << 0;
    if (x < 0)os << '-', x = -x;
    string S;
    while (x){
        S.push_back('0' + x % 10), x /= 10;
    }
    reverse(begin(S), end(S));
    return os << S;
}
//__uint128_t_out
ostream &operator<<(ostream &os, __uint128_t x)
{
    if (x == 0)return os << 0;
    string S;
    while (x){
        S.push_back('0' + x % 10), x /= 10;
    }
    reverse(begin(S), end(S));
    return os << S;
}
// vector<vector>_out
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v){
    for (int i = 0; i < (int)v.size(); i++){
        os << v[i] << "\n";
    }
    return os;
}
// vector<vector<vector>>_out
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<vector<T>>> &v){
    for (int i = 0; i < (int)v.size(); i++){
        os << "i = " << i << "\n";
        os << v[i];
    }
    return os;
}
// map_out
template <typename T, typename S>
ostream &operator<<(ostream &os, const map<T, S> &m){
    for (auto &[key, val] : m){
        os << key << ":" << val << " ";
    }
    return os;
}
// set_out
template <typename T>
ostream &operator<<(ostream &os, const set<T> &st){
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++){
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}
// multiset_out
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &st){
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++){
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}
// queue_out
template <typename T>
ostream &operator<<(ostream &os, queue<T> q){
    while (q.size()){
        os << q.front() << " ";
        q.pop();
    }
    return os;
}
// deque_out
template <typename T>
ostream &operator<<(ostream &os, deque<T> q){
    while (q.size()){
        os << q.front() << " ";
        q.pop_front();
    }
    return os;
}
// stack_out
template <typename T>
ostream &operator<<(ostream &os, stack<T> st){
    while (st.size()){
        os << st.top() << " ";
        st.pop();
    }
    return os;
}
// priority_queue_out
template <class T, class Container, class Compare>
ostream &operator<<(ostream &os, priority_queue<T, Container, Compare> pq){
    while (pq.size()){
        os << pq.top() << " ";
        pq.pop();
    }
    return os;
}

#ifdef LOCAL
template <class... Args>
void debug_out(Args... args){
    int _i = 0;
    ((cerr << (_i++ ? ", " : " ") << args), ...);
    cerr << "\n";
}
#define debug(...){                      \
    cerr << "[" << #__VA_ARGS__ << "]:"; \
    debug_out(__VA_ARGS__);              \
}
#else
#define debug(...)
#endif

#pragma endregion Yoyoyo

