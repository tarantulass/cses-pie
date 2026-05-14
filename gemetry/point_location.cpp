#include<iostream>
using namespace std;
# define ll long long

int main(){
	ll testcase;
	cin>>testcase;
	for(int i=0;i<testcase;i++){
		ll x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
/* slope comparison is the wrong approach as we amy divide by 0 hence not good instead just cross multiply*/
		if((y3-y1)*(x2-x1)==(y2-y1)*(x3-x1)){
			cout<<"TOUCH\n";
		}
		else if((y3-y1)*(x2-x1)>(y2-y1)*(x3-x1)){
			cout<<"LEFT\n";
		}
		else{
			cout<<"RIGHT\n";
		}
	}
}
