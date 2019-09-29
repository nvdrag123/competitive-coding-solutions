#include<bits/stdc++.h>
using namespace std;
#define dbg(var) cout<<#var<<"="<<var<<"\n"
#define ll long long 
#define nl cout<<"\n"
#define fr(i,n) for(int i=0;i<n;i++)
#define rep(i,a,n) for(int i=a;i<n;i++)
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define fa(v) for(auto &i:v)
#define all(v) v.begin(),v.end()

ll cil(ll a,ll b){return a/b+(a%b!=0);}
inline ll min(ll a,ll b){return a<b?a:b;}
const int N = 1000000;
ll lp[N+1];
vector<ll>pr;
void sieve(){
	for (int i=2; i<=N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
   }	
}
bool is_prime[N+10];
int main()
{
	sieve();
	int tst;cin>>tst;while(tst--){
		ll a,b;scanf("%lld %lld",&a,&b);
		while(a<=min(N,b)){
			if(lp[a]==a)printf("%lld\n",a);a++;
		}
		if(a>b){nl;continue;}
		int sz=b-a+1;
		memset(is_prime,1,sizeof is_prime);
		for(ll p:pr){
			int start=cil(a,p);//dbg(p);dbg(start);nl;
			for(int fm=start*p-a;fm<=sz+2 and fm>=0;fm+=p)
			is_prime[fm]=0;
		}
		for(int i=0;i<sz;i++)if(is_prime[i])printf("%lld\n",i+a);
        nl;
		
	}     		

}
