#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
struct query{int l,r,id;};
int n,a[N],q,bit[N],last[N],ans[N];query qry[N];

bool cmp(const query  &a, const query &b){return a.r==b.r?a.l>b.l:a.r<b.r;}
void update(int idx,int val){for(;idx<N;idx+=idx&-idx)bit[idx]+=val;}
int sm(int idx){int res=0;for(;idx;idx-=idx&-idx)res+=bit[idx];return res;}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    
    cin>>n;for(int i=1;i<=n;i++)cin>>a[i];
    cin>>q;for(int i=1;i<=q;i++)cin>>qry[i].l>>qry[i].r,qry[i].id=i;
    
    sort(qry+1,qry+q+1,cmp);
    
    for(int i=1,j=1;i<=q;i++){
    	int ll=qry[i].l,rr=qry[i].r;
    	while(j<=rr){
    		if(last[a[j]]){update(last[a[j]],-1);}
    		update(j,1);last[a[j]]=j;j++;
    	}
    	ans[qry[i].id]=sm(rr)-sm(ll-1);
    }
    
    for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";         		
}
