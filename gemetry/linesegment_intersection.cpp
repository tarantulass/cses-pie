#include<iostream>
using namespace std;
# define ll long long

int main(){
	ll testcase;
	cin>>testcase;
	for(int i=0;i<testcase;i++){
		ll x1,y1,x2,y2,x3,y3,x4,y4, dir1,ref1,dir2,ref2;
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
/* slope comparison is the wrong approach as we amy divide by 0 hence not good instead just cross multiply*/
/*the following approach assumes ab is inifnte line segment and so does cd but it is not this is more subtle*/
		dir1 = (y3-y1)*(x2-x1);
		ref1 = (y2-y1)*(x3-x1);
		dir2 = (y4-y1)*(x2-x1);
		ref2 = (y2-y1)*(x4-x1);

		if(dir1>ref1 && dir2>ref2){
			cout<<"NO\n";
		}
		else if(dir1<ref1 && dir2<ref2){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
		}
	}
}
