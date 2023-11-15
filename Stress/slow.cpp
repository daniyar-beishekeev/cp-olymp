#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
#define USING_ORDERED_SET 0
#if USING_ORDERED_SET
#include<bits/extc++.h>
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
#endif
template<class T>void umax(T &a,T b){if(a<b)a=b;}
template<class T>void umin(T &a,T b){if(b<a)a=b;}
#ifdef juggernaut
    #define printl(args...) printf(args)
#else
    #define printl(args...) 0
#endif
int n,k;
const int MX=16005;
int a[MX];
int mod=1e9+7;
vector<pair<int,ll>>NEUTRAL;
vector<pair<int,ll>>add(int v,vector<pair<int,ll>>&last){
	vector<pair<int,ll>>dp;
	dp=last;
	for(int i=0;i<MX;i++){
		if(!last[i].sc)continue;
		pair<int,ll>tmp={v+last[i].fr,(last[i].sc<<1)%mod};
		if(tmp.fr>dp[i^v].fr)dp[i^v]=tmp;
		else if(tmp.fr==dp[i^v].fr)dp[i^v].sc=(dp[i^v].sc+tmp.sc)%mod;
	}
	return dp;
}
int main(){
	NEUTRAL.assign(MX,make_pair(0,0));
	NEUTRAL[0].sc++;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	stack<vector<pair<int,ll>>>st1,st2;
	/*for(int i=k;i;i--){
		if(st1.empty())st1.push(add(a[i],NEUTRAL));
		else st1.push(add(a[i],st1.top()));
	}*/
	for(int i=k;i<=n;i++){
		stack<vector<pair<int,ll>>>tmp;
		tmp.push(add(a[i-k+1],NEUTRAL));
		for(int j=i-k+2;j<=i;j++)
			tmp.push(add(a[j],tmp.top()));
		printf("%d %d\n",tmp.top()[0].fr,(int)tmp.top()[0].sc);
	}
}
