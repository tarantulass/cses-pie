#include<iostream>
using namespace std;
using ll=long long;

int main(){
	// initialize
	ll n, ans=0,i=0;
	cin>>n;

	// process
	/*
	clearly this is about math simply do the number n diivded by 5
	formula goes like n/5 pow etc...
	*/
	while(n>0){
		ans+=n/5;// anyways will be truncated
		i+=1;
		n/=5;
	}
	cout<<ans;
}




