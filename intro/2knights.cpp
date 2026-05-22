#include<iostream>
using namespace std;
using ll=long long;
/*
Answers the puzzle how many mxn rectangle are there in a kxk grid?
answer is (k-m-1)*(k-n-1)
as we only need to have those number of startign indices just thatand there are so many possiblities
*/

int main(){
	// initialize
	ll n,ans;
	cin>>n;

	// process
	for(ll i=1;i<n+1;i++){// to include n otherwise truncates to n-1
		ans = (i*i)*(i*i-1)/2 - 2*((i-1)*2*(i-2));
		cout<<ans<<endl;
	}
}
