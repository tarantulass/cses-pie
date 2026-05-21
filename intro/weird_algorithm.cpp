#include<iostream>
using namespace std;
using ll=long long;
 
int main(){
	ll n;
	cin>>n;
	cout<<n<<" ";
	while(n!=1){
		if(n%2){
			n = 3*n+1;
		}
		else{
			n = n/2;
		}
		cout<<n<<" ";
	}
}
