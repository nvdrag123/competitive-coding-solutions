//// https://www.codechef.com/viewsolution/26571827
#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout<<#x<<"="<<x<<" "
#define nl  cout<<"\n"
#define ll long long 

const int mxN=2e5+10;
int n, m, nxt[mxN+1];
int arr[mxN][25],mxH=0,dp[mxN];
vector<int> adj[mxN], grp;
set<int>fa;
vector<vector<int>> grps;
vector<pair<int,int>>edges;
bool vis[mxN];
struct DSU
{
	int connected;
	int par[mxN], sz[mxN];

	DSU() {} 

	DSU(int n) 
	{
		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
		}
		connected=n;
	}

	int getPar(int k)
	{
		while(k!=par[k])
		{
			par[k]=par[par[k]];
			k=par[k];
		}
		return k;
	}

	int getSize(int k)
	{
		return sz[getPar(k)];
	}

	void unite(int u, int v)
	{
		int par1=getPar(u), par2=getPar(v);

		if(par1==par2)
			return;

		connected--;

		if(sz[par1]>sz[par2])
			swap(par1, par2);

		sz[par2]+=sz[par1];
		sz[par1]=0;
		par[par1]=par[par2];
	}
};

void dfs(int u) {
	vis[u]=1;
	grp.push_back(u);
	vector<int> tv;
	for(int i=0, i2=0; nxt[i]<=n; ) {
		while(i2<adj[u].size()&&adj[u][i2]<nxt[i]-1)
			++i2;
		if(i2>=adj[u].size()||adj[u][i2]!=nxt[i]-1) {
			tv.push_back(nxt[i]-1);
			nxt[i]=nxt[nxt[i]];
		} else
			i=nxt[i];
	}
	for(int v : tv)
		dfs(v);
}
 
void divide(int l,int r,int h){
	if(l<r){
	int mid=(l+r)/2;
	arr[l][h]++;arr[mid+1][h]--;
	divide(l,mid,h+1);
	divide(mid+1,r,h+1);
    }
	return;
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=2;i<mxN;i++)dp[i]=max(dp[i/2],dp[i-i/2])+1;   
	for(int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back({u+1,v+1});
	}
	for(int i=0; i<n; ++i)sort(adj[i].begin(), adj[i].end());
	for(int i=0; i<=n; ++i)nxt[i]=i+1;
	while(nxt[0]<=n) {
		grp.clear();
		int u=nxt[0]-1;
		nxt[0]=nxt[nxt[0]];
		dfs(u);
		grps.push_back(grp);
	}
   	DSU dsu(n);
	for(vector<int> &grp : grps) {
		int sz = grp.size();
		for(int i=0;i<sz-1;i++){
			dsu.unite(grp[i]+1,grp[i+1]+1);
		}
		// for(auto &x:grp)cout<<x+1<<" ";nl;
	}
	divide(1,dsu.connected,0);
	unordered_map<int,int>mp;
	for(pair<int,int>&pr : edges){
		if(dsu.getPar(pr.first)==dsu.getPar(pr.second))return cout<<"-1",0;
	}
	if(dp[dsu.connected]*n>=1000000)return cout<<"-1",0;
    for(int i=1;i<=n;i++)fa.insert(dsu.getPar(i));int cnt=1;
    for(int i:fa)mp[i]=cnt++;
    int total=dp[dsu.connected];
    cout<<total<<"\n";
    for(int i=0;i<total;i++)
    {
    	for(int j=1;j<mxN;j++)arr[j][i]+=arr[j-1][i];
    	string s="";
    	for(int j=1;j<=n;j++)
    		s+=('0'+arr[mp[dsu.getPar(j)]][i]);
    	cout<<s<<"\n";
    }
}
