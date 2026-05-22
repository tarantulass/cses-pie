#include<iostream>
using namespace std;
using ll=long long;
// important as despite int stores 1e9 but x*x is also being calculated

void query(ll& y, ll& x){
	if(y==x){
		cout<<y*x-(y-1)<<"\n";
	}
	else if(y>x){
		cout<<y*y-(y-1) + (1-2*(y%2))*(y-x)<<"\n";
	}
	else{
		cout<<x*x-(x-1) + (2*(x%2)-1)*(x-y)<<"\n";
	}
}

int main(){
/*watching clearly we observe that only 1st and basically all odd numbered cols define the entire thing
following even numbered are bound to follow the first one*/

/*
NO nothing about odd even it was about
1. diagonal entires
2. using r>c and c>r cases
*/
	// initialize
	ll testcases, x, y;
	cin>> testcases;

	// process
	for(int i=0;i<testcases;i++){
		cin>>y>>x;
		query(y,x);// due to 0 based indexing add 1 no as it is already given
	}

}
