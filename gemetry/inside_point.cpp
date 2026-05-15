 // the question once asked at an interview comes again
#include<iostream>
#include<cmath>
#include<vector>
using ll = long long;

using namespace std;

struct point{
	ll x,y;
};

// y1 in between y2 and y3 can also be checked using if (y1<y2) != (y1<y3)
int main(){
	//int n,m; less readable hence map n to sides and m to points
	int sides, points, intersects;
	//  lets assume a ray horizontal then we have 2 points such that x,y and max x-> from sides,y no lets go more general
	// here in the process of ray casting we check against each edge we dont check for one and if odd we proceed thats wrong
	ll x,y;
	vector<point> sidecoords;
	vector<point> checkpoints;

	cin>>sides>>points;
	for(int i=0;i<sides;i++){
		cin>>x>>y;
		sidecoords.push_back({x,y})
	}
	for(int i=0;i<points;i++){
		cin>>x>>y;
		checkpoints.push_back({x,y});
	}
	// how do i check for edges since i only have vertices do i have to make edges??
	for(auto &check: checkpoints){
		for(auto& p: sidecoords){
			if((check.y<)~=(check.y<p.)) && ())
				intersects+=1;
		}
		cout<<;
	}
}
