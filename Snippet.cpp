    #include <bits/stdc++.h>
    using namespace std;
     
    //BM
     
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    template <typename T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    template <typename T>
    using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
/*------------------------------HASH DEFINE MACROS-------------------------*/     
    #define pb push_back
    #define pob pop_back
    #define f first
    #define sec second
    #define fl(n) for (int i = 0; i < n; i++)
    #define fix(f,n) std::fixed<<std::setprecision(n)<<f
    #define all(x) x.begin(), x.end()
/*-----------------------------------MACROS--------------------------------*/
    typedef long long ll;
    typedef vector<long long> vll;
    typedef pair<long long, long long> pll;
    typedef vector<pair<long long, long long>> vpll;
    typedef vector<pair<int,int>> vpii;
    typedef vector<int> vii;
    #define eb emplace_back
    #define endl '\n'
    #define py cout << "YES\n";
    #define pn cout << "NO\n";
/*-----------------------------CONSTANT VARIABLES-------------------------*/
    const ll INFI = 1e18;
    const int INF = 1e9;
    const ll mod = 1000000007;
    const int mod_ = 998244353;
     
/*-------------------------------BASIC FUNCTIONS---------------------------*/

    ll binexp(ll a,ll b,ll m = LLONG_MAX){
        ll res = 1;
        while (b){
            if (b&1) res = (res*a)%m;
            a = (a*a)%m;
            b>>=1;
        }
        return res;
    }
     
    bool cols (vll& v1,vll& v2){
        return v1[1]<v2[1];    
    }
     
/*--------------------------------NUMBER THEORY---------------------------*/
     
    vll fac; //factorial of n 
    void fact(ll n){
        fac.clear();
        fac.resize(n+1);
        fac[0]=1;
        fac[1]=1;
        for (ll i=2;i<=n;i++) fac[i]=fac[i-1]*i;
        // fac[i] = i! 
    }

/*----------------------------------SIEVE ALGORITHM------------------------*/
    vector<bool> isprime; //true=prime
    void checkprime(ll n){ 
        isprime.clear();
        isprime.assign(n+1,true);   // resize and assign value at same time
        isprime[0]=false;
        isprime[1]=false;
        for (ll i=2;i*i<=n;i++){
            if (isprime[i]){
                for (ll j=i*i;j<=n;j+=i) isprime[j]=false;
            }
        }
//             isprime[i] return 1 if i is prime
    }   

    vll phi; //totient function of n
    void totient_sieve(ll n){
        // totient function = no. of integers upto n co-prime to n
        phi.clear();
        phi.resize(n+1);
        for (ll i=0;i<=n;i++) phi[i]=i;
        for (ll i=2;i<=n;i++) {
            if (phi[i]==i){
                for (ll j=i;i<=n;j+=i) phi[j]=phi[j]-phi[j]/i;
            }
        }
    }

    vll lpf; //largest prime factor of n
    void lpf_sieve(ll n){
        // largest prime factors of numbers upto n
        lpf.clear();
        lpf.assign(n+1,0);
        for (ll i=2;i<=n;i++) {
            if (lpf[i]==0){
                for (ll j=i;j<=n;j+=i) lpf[j]=i;
            }
        }
    }

    void pf(ll n){
        // prints prime factorization of n
        // requires lpf
        while (n>1){
            cout<<lpf[n]<<" ";
            n/=lpf[n];
        }    
        cout<<endl;
    }
/*----------------------------SHIT YET TO DISCOVER-----------------------*/

    ll extendedgcd(ll a,ll b,ll& x,ll& y){
        // returns gcd and changes x and y 
        // such that gcd = ax+by
        x=1,y=0;
        ll x1=0,y1=1,a1=a,b1=b;
        while (b1){
            ll q = a1/b1;
            tie(x,x1) = make_tuple(x1,x-q*x1);
            tie(y,y1) = make_tuple(y1,y-q*y1);
            tie(a1,b1)= make_tuple(b1,a1-q*b1);
        }
        return a1;
    }

    // DSU
     
    vll dsp;
    vll si;
    void make(ll v){
        // makes new node
        dsp[v]=v;
        si[v]=1;
    }
    ll find(ll v){
        // finds parent
        if(v==dsp[v]) return v;
        return dsp[v]=find(dsp[v]);
    }
    void unio(ll a,ll b){
        // merges two sets
        a=find(a);
        b=find(b);
        if(a!=b){
            if(si[a]<si[b]) swap(a,b);
            dsp[b]=a;
            si[a]+=si[b];
        }
    }
     
/*-------------------------------------TREES----------------------------*/
     
    vector<vll> children; //children of each node
    vll parent; //parent od each node
     
    void Traversal(ll node){
        // Traversing trees
        for (auto x: children[node]){
            if (x==parent[node]) continue;
            parent[x]=node;
            // add function here for Pre Order
            Traversal(x);
            // add function here for Post Order
        }
    }
     
     
/*-------------------------------GRAPHS-----------------------------------*/
     
    vector<vll> adj; //adjacent nodes of each node
    vector<vpll> adjw; //adjacent nodes of each node with weight of edge
    vector<bool> visited; //visited nodes check
     
    void bfs(ll s,vll& d,vll& p){
        // Breadth First Search
        ll n = adj.size();
        d.assign(n,0);
        p.assign(n,-1);
        queue<ll> q;
        vector<bool> used(n);
        q.push(s);
        used[s]=true;
        p[s]=-1;
        while (!q.empty()){
            ll v = q.front();
            q.pop();
            for (ll u:adj[v]){
                if (!used[u]){
                    used[u]=true;
                    q.push(u);
                    d[u]=d[v]+1; 
                    p[u]=v;
                }
            }
        }
    }
     /*-------------------------DFS--------------------------*/
    vii dfsarr; //dfs traversal array
    void dfs(ll v){
        // Depth First Search
        visited[v]=true;
        for (auto u: adj[v]){
            if (!visited[u]){
                // enter pre function
                dfs(u);
                // enter post function
            }
        }
        dfsarr.pb(v);
    }
     
    void dijkstra(ll s,vll& d,vll& p) {
        // Dijkstra: shortest distance from source
        ll n = adjw.size();
        d.assign(n, INF);
        p.assign(n, -1);
        vector<bool> u(n, false);
        d[s] = 0;
        for (ll i = 0; i < n; i++) {
            ll v = -1;
            for (ll j = 0; j < n; j++) {
                if (!u[j] && (v == -1 || d[j] < d[v]))
                    v = j;
            }
     
            if (d[v] == INF)
                break;
     
            u[v] = true;
            for (auto edge : adjw[v]) {
                ll to = edge.f;
                ll len = edge.sec;
     
                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                }
            }
        }
    }
     
    vector<vll> edges (0,vll(3)); //weight,node1,node2
    vpii minedges;
    ll kruskal(ll n){
        //Kruskal: minimum spanning tree
        ll minwt = 0;
        minedges.clear();
        sort(all(edges));
        dsp.assign(n,0);
        si.assign(n,0);
        for (ll i=0;i<n;i++) dsp[i]=i;
        for (auto x:edges){
            ll u = find(x[1]);
            ll v = find(x[2]);
            if (u!=v){
                minwt+=x[0];
                minedges.pb({x[1],x[2]});
                unio(u,v);
            }
        }
        return minwt;
    }
     
/*--------------------------------RANGE QUERIES----------------------------*/
     
    vector<vll> st; 
    void constst(vll& v){
        //Constructing Sparse Table 
        ll n = v.size();
        ll k = log2(n) + 1;
        st.assign(n,vll (k,0));
        for (ll i=0;i<n;i++) st[i][0]=v[i];
        for (ll j=1;j<=k;j++){
            for (ll i=0;i+(1<<j)<=n;i++){
                st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]); // change function here
            }
        }
    }
     
    ll queryst(ll l,ll r){
        // Query for [l,r] 0-indexed
        ll j = log2(r-l+1);
        return min(st[l][j],st[r-(1<<j)+1][j]); //change function here
    }
     
    vll seg;
    void buildseg(vll& a,ll v,ll tl,ll tr) {
        // First resize seg to 4*n and assign 0
        // seg[v] gives ans for [tl,tr] 0-indexed
        // Start : v=1,tl=0,tr=n-1
        if (tl == tr) seg[v] = a[tl];
        else {
            ll tm = (tl + tr) / 2;
            buildseg(a, v*2, tl, tm);
            buildseg(a, v*2+1, tm+1, tr);
            seg[v] = seg[v*2] + seg[v*2+1]; // change function here
        }
    }
     
    ll queryseg(ll v,ll tl,ll tr,ll l,ll r) {
        // Query for [l,r] 0-indexed
        // seg[v] gives ans for [tl,tr]
        // Start : v=1,tl=0,tr=n-1
        if (l > r) return 0; //change identity here
        if (l == tl && r == tr) return seg[v];
        ll tm = (tl + tr) / 2;
        return queryseg(v*2, tl, tm, l, min(r, tm)) + queryseg(v*2+1, tm+1, tr, max(l, tm+1), r); //change function here
    }
     
    void updateseg(ll v,ll tl,ll tr,ll pos,ll new_val) {
        // Update at index pos (0-indexed)
        // seg[v] gives ans for [tl,tr]
        // Start : v=1,tl=0,tr=n-1
        if (tl == tr) seg[v] = new_val;
        else {
            ll tm = (tl + tr) / 2;
            if (pos <= tm) updateseg(v*2, tl, tm, pos, new_val);
            else updateseg(v*2+1, tm+1, tr, pos, new_val);
            seg[v] = seg[v*2] + seg[v*2+1]; // change function here
        }
    }
     
/*--------------------------------THE BEGINNING----------------------------*/
     
    void solve() {


    }



/*-----------------------------------THE END-------------------------------*/

/*---------------------------------LAST CALL--------------------------------*/
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t = 1;
        // cin>>t;
        for (int i=1;i<=t;i++){
            //cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;
    }