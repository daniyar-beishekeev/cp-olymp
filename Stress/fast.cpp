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
	for(int i=k;i;i--){
		if(st1.empty())st1.push(add(a[i],NEUTRAL));
		else st1.push(add(a[i],st1.top()));
	}
	for(int i=k;i<=n;i++){
		vector<pair<int,ll>>v1;
		vector<pair<int,ll>>v2;
		if(st1.empty())v1=NEUTRAL;
		else v1=st1.top();
		if(st2.empty())v2=NEUTRAL;
		else v2=st2.top();
		pair<int,ll>ans={0,0};
		for(int j=0;j<MX;j++){
			pair<int,ll>tmp={v1[j].fr+v2[j].fr,(v1[j].sc*v2[j].sc)%mod};
			if(!tmp.sc)continue;
			if(tmp.fr>ans.fr)ans=tmp;
			else if(tmp.fr==ans.fr)ans.sc=(ans.sc+tmp.sc)%mod;
		}
		printf("%d %d\n",ans.fr,(int)ans.sc);
		if(i!=n){
			if(st1.empty()){
				for(int j=0;j<k;j++){
					st2.pop();
					int &value=a[i-j];
					if(st1.empty())st1.push(add(value,NEUTRAL));
					else st1.push(add(value,st1.top()));
				}
			}
			st1.pop();
			st2.push(add(a[i+1],v2));
		}
	}
}
