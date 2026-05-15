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
	bool bdry=false;
	//  lets assume a ray horizontal then we have 2 points such that x,y and max x-> from sides,y no lets go more general
	// here in the process of ray casting we check against each edge we dont check for one and if odd we proceed thats wrong
	ll x,y;
	vector<point> sidecoords;
	vector<point> checkpoints;

	cin>>sides>>points;
	for(int i=0;i<sides;i++){
		cin>>x>>y;
		sidecoords.push_back({x,y});
	}
	for(int i=0;i<points;i++){
		cin>>x>>y;
		checkpoints.push_back({x,y});
	}
	// how do i check for edges since i only have vertices do i have to make edges??
	// reading the question it clearly mentions that we have adjacent point for edges hence use of % again
	for(auto &check: checkpoints){
		for(int i=0;i<sides;i++){
			// check for collinearity and inside
			if(((check.y - sidecoords[i].y)*(sidecoords[(i+1)%sides].x - sidecoords[i].x)==(check.x-sidecoords[i].x)*(sidecoords[(i+1)%sides].y - sidecoords[i].y)) && (check.x<sidecoords[i].x)!=(check.x<sidecoords[(i+1)%sides].x)){
				bdry = true;
				cout<<"BOUNDARY";
				break;
			}

			if((check.y<sidecoords[i].y)!=(check.y<sidecoords[(i+1)%sides].y)) && (check.x<sidecoords[i].x + ((check.y - sidecoords[i].y)/(sidecoords[(i+1)%sides].y - sidecoords[i].y))*(sidecoords[(i+1)%sides].x - sidecoords[i].x)))
				intersects+=1;


	// y inside and the x between the linear comibination
		}
		if(!bdry){
			if(intersects%2){
				cout<<"INSIDE";
			}
			else{
				cout<<"OUTSIDE";
			}

		}
	}
}
