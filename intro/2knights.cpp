#include<iostream>
using namespace std;

int main(){
	// initialize
	int n,ans;
	cin>>n;

	// process
	for(int i=1;i<n+1;i++){// to include n otherwise truncates to n-1
		ans = (i*i)*(i*i-1)/2 - 2*((i-1)*2*(i-2));
		cout<<ans<<endl;
	}
}
