#pragma region Yoyoyo

#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include<bits/stdc++.h>
#ifndef LOCAL
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif
using namespace std;
using ll=long long;
using ld=long double;
using i128t=__int128_t;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const string Yes="Yes";
const string No="No";
const long long inf=1ll<<60;
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define faster ios::sync_with_stdio(false);cin.tie(nullptr);
#define print(s) cout<<s<<"\n";

template<typename T>
inline bool chmax(T&a,T b){return ((a<b)?(a=b,true):(false));}
template<typename T>
inline bool chmin(T&a,T b){return ((a>b)?(a=b,true):(false));}
template<typename T>
ll sum(T&a){return accumulate(all(a),0LL);}

template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U>&p){
    os<<p.first<<" "<<p.second;
    return os;
}

template<typename T,typename U>
istream &operator>>(istream &is,pair<T,U>&p){
    is>>p.first>>p.second;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os,const vector<T>&v){
    int s=(int)v.size();
    for(int i=0;i<s;i++){
        os<<(i?" ":"")<<v[i];
    }
    return os;
}

template<typename T>
istream &operator>>(istream &is,vector<T>&v){
    for(auto &x:v){
        is>>x;
    }
    return is;
}

template<typename T>
ostream &operator<<(ostream &os,const vector<vector<T>>&v){
    int s=(int)v.size();
    for(int i=0;i<s;i++){
        os<<v[i]<<endl;
    }
    return os;
}

template<typename T>
ostream &operator<<(ostream &os,const vector<vector<vector<T>>>&v){
    int s=(int)v.size();
    for(int i=0;i<s;i++){
        os<<"i = "<<i<<endl;
        os<<v[i];
    }
    return os;
}

#ifdef LOCAL
template<class... Args>
void debug_out(Args... args){
    int _i=0;
    ((cerr<<(_i++?", ":" ")<<args),...);
    cerr<<"\n";
}
#define debug(...){\
    cerr<<"["<<#__VA_ARGS__<<"]:";\
    debug_out(__VA_ARGS__);\
}
#else
#define debug(...)
#endif


