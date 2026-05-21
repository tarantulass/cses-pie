#include<iostream>
using namespace std;
using ll=long long;

int main(){
	ll sum,n,x;
	sum =0;
	cin>>n;
	for(int i=0;i<n-1;i++){ // important only n-1 numbers 
		cin>>x;
		sum+=x;
	}
	cout<<((n*(n+1))/2)-sum;
}
