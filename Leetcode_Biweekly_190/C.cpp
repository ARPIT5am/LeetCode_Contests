/////////----author---->>>5am__ARPIT.....
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
#define loop(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, a, b) for(int i = (a); i <= (b); ++i) 
#define input(a) cin>>a; 
#define nl std::cout<<endl; 
#define print(a) std::cout<<a;
#define yes   std::cout<<"YES";
#define no std::cout<<"NO";
#define alice std::cout<<"ALICE";
#define bob std::cout<<"BOB";
#define vt vector
#define bit(x) __builtin_clz(x);
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;
///////////////////////////////////////////////////////////
// Multiset-like PBDS (duplicates allowed)
struct OrderedMultiset {
    using T = pair<int,int>;   // (value, unique_id)
    using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    ost s;
    int id = 0;  // unique index generator
    
    // insert value
    void insert(int x) {
        s.insert({x, id++});
    }
    
    // erase one occurrence of value (if present)
    bool erase(int x) {
        auto it = s.lower_bound({x, -1});
        if (it != s.end() && it->first == x) {
            s.erase(it);
            return true;
        }
        return false;
    }

    // size of set
    int size() { return (int)s.size(); }
    
    // k-th smallest (0-indexed)
    int kth(int k) {
        return s.find_by_order(k)->first;
    }

    // number of elements < x
    int order_of_key(int x) {
        return s.order_of_key({x, -1});
    }

    // number of elements <= x
    int order_of_key_leq(int x) {
        return s.order_of_key({x+1, -1});
    }

    // number of elements > x
    int greaterCount(int x) {
        return size() - order_of_key_leq(x);
    }
    
     //remove  all the element..... 
     void clear() {
        s.clear();
        id = 0;
    }
};
//////////////////////////////////////////////////////////////////////
using arpit = int;
using dabla = double;
using ld = long  double; 
using chr = char;
using vi = vector<int>;
using ump = std::unordered_map<int , int>;
using vv = vector<vector<int>>;
using vb = vector<bool>;
using ll = long long;
using vbb = vector<vector<bool>>;
using vll = vector<ll>;
using lli = long long int;
using vs= vector<string>;
using tf = bool;
using vp = vector<pair<int,int>>;
using sn = string;
using ull = unsigned long long;
using pp = pair<int, int>;
 /////////////////////////////////////////////////////////// 
bool alleq(vector<int>arr) {
     int n=arr.size();
    for(int i =1; i<n; i++) {
        if(arr[i] != arr[i-1]) {
           return false;
        }
    }
    return true;
 }
  int mod = 1e9+7;

 ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
 
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
 
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
 
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b + mod) % mod) + mod) % mod;}
  
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
 
ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}

////////////////////////////////////////////////////////////////////////////
//=======================================================================

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        uint64_t h1 = splitmix64(p.first + FIXED_RANDOM);
        uint64_t h2 = splitmix64(p.second + FIXED_RANDOM);
        // Combine the two hashes securely
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};
//====================================================================

  template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}
/////////////////////////////////////////////////////////////////////////  

  
//////////////////////////////////////////////////////////////////

    std::vector<int> parent;
    std::vector<int> Rank;
    int find(int x) {
        if (x == parent[x]) 
            return x;
        return parent[x] = find(parent[x]);
    }
void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(Rank[x_parent] > Rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(Rank[x_parent] < Rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            Rank[y_parent]++;
        }
    }
     bool isprime(int N){
    if(N<2 || (!(N&1) && N!=2))
        return 0;
    for(int i=3; i*i<=N; i+=2){
        if(!(N%i))
            return 0;
    }
    return 1;
} 
   //i will Reach EXPERT soon:
 const int N_MAX = 15;
////////////////////////////////////////////////////////////////////////
const long long MOD = 1e9 + 7;
/////////////////////////////////////////////////////////////////////
vector<long long> fact(N_MAX);
vector<long long> invFact(N_MAX);
////////////////////////////////////////////////////////////////
long long modpow(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
/////////////////////////////////////////////////////////////////////////
long long modInverse(long long n) {
    return modpow(n, MOD - 2);
}
///////////////////////////////////////////////////////////////////////
void pcmfac() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < N_MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
   
    invFact[N_MAX - 1] = modInverse(fact[N_MAX - 1]);
    for (int i = N_MAX - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}
/////////////////////////////////////////////////////////////////////
long long nCr(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    return (((fact[n] * invFact[k]) % MOD) * invFact[n - k]) % MOD;
}
//////////////////////////////////////////////////////////////////////
 //--------------------DIRECTIONALITY----------------------------------
vp dir = {{-1,0}, {0, -1}, {1, 0}, {0, 1}};

vp d4 = {{1, 0}, {0,1}, {-1, 0}, {0, -1}, {-1, -1}, {1, 1}, {-1 ,1}, {1, -1}};  //queen: 

vp d8 = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};  //knight tour problem; 

//////////////////////////////////////////////////////////////////////

 bool ispalin(const string& s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
      if (s[i] != s[j])
        return false;
      ++i;
      --j;
    }
    return true;
  }
//////////////////////////////////////////////////////////////////
 
 ll btd(string s) { return bitset<64>(s).to_ullong(); }

  string dtb(long long a) {
    if (a == 0) return "0";
    string s = bitset<64>(a).to_string();
    return s.substr(s.find('1'));
}

////////////////////////////////////////////////////////////////////////
const int MAXN = 10;  
int spf[MAXN + 1];  
vector<int> primes;
void sieve() {
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || 1LL * p * i > MAXN) break;
            spf[p * i] = p;
        }
    }
}
vector<int>factorize(int x) {
    vector<int> f;
    while (x > 1) {
        f.push_back(spf[x]);
        x /= spf[x];
    }
    return f;
}
/////////////////////////////////////////////////////////////////////////// 

  //WRITTEN BY---5am__Arpit
       //approach: ------------------------------------------------------
/* 
     
     
       
*/
//................................................................
//-----------------------------------------------------------------------

void solve() {     
    
    

}

class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
    int n = nums.size(); 
      vs r; 
        int opn=1<<25; 
        for(auto ele : nums) {
            sn ans=""; 
            int cnt=ele/opn ;
            int rem=ele%opn ; 
            ans.append(cnt,'z');
            for(int i = 29; i >= 0; --i) {
                if((1<<i)&rem) {
                     ans.push_back(char('a' + i)); 
                }
            }
            r.push_back(ans); 
        }
        return r; 
    }
};