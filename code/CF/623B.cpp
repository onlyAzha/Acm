/*
ID: onlyazh1
LANG: C++
TASK: Array GCD
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
ll a[maxn];
ll A,B;
int n;
ll ans = 1e16;
vector<ll> p;
ll g1[maxn];
ll g2[maxn];
ll g3[maxn];
void Fun(ll x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            p.push_back(i);
            while(x%i==0)
                x/=i;
        }
    }
    if(x!=1) p.push_back(x);
}

void solve(ll x){
    memset(g1,0,sizeof(g1));
    memset(g2,0,sizeof(g2));
    memset(g3,0,sizeof(g3));

    for(int i=1;i<=n;i++){
        if(a[i]%x==0) g1[i]=g1[i-1];
        else if((a[i]+1)%x==0||(a[i]-1)%x==0)
            g1[i]=g1[i-1]+B;
        else g1[i]=1e16;
    }

    for(int i=n;i>=1;i--){
        if(a[i]%x==0) g2[i]=g2[i+1];
        else if((a[i]+1)%x==0||(a[i]-1)%x==0)
            g2[i]=g2[i+1]+B;
        else g2[i]=1e16;
    }
    g3[0]=1e16;
    for(int i=1;i<=n;i++){
        g3[i]=g1[i]-(i+1)*A;
        g3[i]=min(g3[i],g3[i-1]);
    }

    for(int i=1;i<=n;i++)
    {
        ans=min(ans,g2[i]+(i-1)*A);
        ans=min(ans,g1[i]+(n-i)*A);
    }
    for(int i=1;i<=n+1;i++)
        ans=min(ans,g3[i-1]+g2[i]+A*i);
}
int main(){
    scanf("%d%lld%lld",&n,&A,&B);
    //cin>>n>>A>>B;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
        //cin>>a[i];
    for(int i=-1;i<=1;i++)
        Fun(a[1]+i),Fun(a[n]+i);
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    for(int i=0;i<p.size();i++)
        solve(p[i]);
    cout<<ans<<endl;
    return 0;
}
