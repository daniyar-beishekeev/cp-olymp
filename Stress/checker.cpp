#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream slow,fast,test;
	slow.open("slow.txt");
	fast.open("fast.txt");
	int a,b;
	slow>>a;
	fast>>b;
	if(a!=b){
		slow.close();
		fast.close();
		return 1;
	}
	slow.close();
	fast.close();
	return 0;
}
