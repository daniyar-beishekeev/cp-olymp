#include<bits/stdc++.h>
using namespace std;
int gen(int l,int r){
	return l+(rand()%(r-l+1));
}
int main(){
    srand(time(NULL));
    int n=gen(1,10);
    int k=gen(1,n);
    printf("%d %d\n",n,k);
    for(int i=1;i<=n;i++)printf("%d ",gen(1,5000));
}
