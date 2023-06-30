    /*
    Author - Vishwas Kapoor
    जय श्री गणेश
    */
    #include <bits/stdc++.h>
    using namespace std;
    /*------------------------------HASH DEFINE MACROS-------------------------*/
    #define fl(n) for (int i = 0; i < n; i++)
    #define f(n, i) for (int i = 0; i < n; i++)
    #define IOS                      \
        ios::sync_with_stdio(false); \
        cin.tie(0);                  \
        cout.tie(0);
    #define PB push_back
    #define eb emplace_back
    #define all(x) x.begin(), x.end()
    #define endl "\n"
    #define py cout << "YES" << endl;
    #define pn cout << "NO" << endl;
    /*-----------------------------------MACROS--------------------------------*/
    typedef long long ll;
    typedef vector<long long> vll;
    typedef pair<long long, long long> pll;
    typedef vector<pair<long long, long long>> vpll;
    typedef vector<pair<int, int>> vpii;
    typedef vector<int> vii;
    /*-----------------------------CONSTANT VARIABLES-------------------------*/
    const long long INFI = 1e18;
    const int INF = 1e9;
    const int mod = 1e9 + 7;
    const int mod_ = 998244353;
    /*--------------------------------BASIC FUNCTIONS----------------------------*/
    ll binexp(ll a, ll b, ll m = LLONG_MAX)
    {
        ll res = 1;
        while (b)
        {
            if (b & 1)
                res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }
     
    bool cols(vll &v1, vll &v2)
    {
        return v1[1] < v2[1];
    }
    /*--------------------------------NUMBER THEORY---------------------------*/
    vll fac;
    void fact(ll n)
    {
        fac.clear();
        fac.resize(n + 1);
        fac[0] = fac[1] = 1;
        for (ll i = 2; i <= n; i++)
            fac[i] = fac[i - 1] * i;
        // fac[i] = i!
    }
    /*----------------------------------SIEVE ALGORITHM------------------------*/
    vector<bool> isprime; // true=prime
     
    void checkprime(ll n)
    {
        isprime.clear();
        isprime.assign(n + 1, true); // resize and assign value at same time
        isprime[0] = false;
        isprime[1] = false;
        for (ll i = 2; i * i <= n; i++)
        {
            if (isprime[i])
            {
                for (ll j = i * i; j <= n; j += i)
                    isprime[j] = false;
            }
        }
        //             isprime[i] return 1 if i is prime
    }
    vll phi; // totient function of n
    void totient_sieve(ll n)
    {
        // totient function = no. of integers upto n co-prime to n
        phi.clear();
        phi.resize(n + 1);
        for (ll i = 0; i <= n; i++)
            phi[i] = i;
        for (ll i = 2; i <= n; i++)
        {
            if (phi[i] == i)
            {
                for (ll j = i; i <= n; j += i)
                    phi[j] = phi[j] - phi[j] / i;
            }
        }
    }
    vll lpf; // largest prime factor of n
    void lpf_sieve(ll n)
    {
        // largest prime factors of numbers upto n
        lpf.clear();
        lpf.assign(n + 1, 0);
        for (ll i = 2; i <= n; i++)
        {
            if (lpf[i] == 0)
            {
                for (ll j = i; j <= n; j += i)
                    lpf[j] = i;
            }
        }
    }
    void pf_sieve(ll n)
    {
        // prints prime factorization of n
        // requires lpf
        while (n > 1)
        {
            // lpf[n] -> prime factor of n
            //  modify before using
            n /= lpf[n];
        }
    }
    /*--------------------------------THE BEGINNING----------------------------*/
     void solve(){
      
       
       
     }
    int main()
    {
     
        IOS int t = 1;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
            // cout<<"Case #"<<i<<": ";
            solve();
        }
     
        return 0;
    }
