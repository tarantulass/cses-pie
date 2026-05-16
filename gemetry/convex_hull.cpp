/*
template i will follow
1. libraries n micros
2. struct or any class
3. in main initialize, testcase and store finally algo
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct point{
	ll x,y;
	point operator-(const point& other) const{
		return {x-other.x, y-other.y};
	}
};

ll crossproduct(point a, point b){
	return a.x*b.y - a.y*b.x;
}

int main(){
	// initialize
	ll testcase, x,y;
	vector<point> coords;
	vector<point> convexhull_low;// finally we print this after all those common terms are done
	vector<point> convexhull_up;
	point A,B,C;
	// take input and store
	cin>>testcase;
	for(auto i=0;i<testcase;i++){
		cin>>x>>y;
		coords.push_back({x,y});
	}
	// again sort by x then y similar to minimum euclidean distance-> no not required!!
	// obviously convex hull obeys triangle inequality!!
	// solve this by taking 3 points in condiration A,B,C s.t cross product of (B-A) and (C-A) decides the point in convex hull
	// algorithms starts
	sort(coords.begin(), coords.end(), [](point a, point b)
		{return a.x<b.x;}
	);
	for(auto& p: coords){
		while(convexhull_low.size()>=2 && crossproduct(convexhull_low.back()-convexhull_low[convexhull_low.size()-2], p-convexhull_low[convexhull_low.size()-2]) <=0 ){
			convexhull_low.pop_back();
		}
		convexhull_low.push_back(p);
	}

	for(int i=testcase-1; i>=0; i--){
    		auto& p = coords[i];
    		while(convexhull_up.size()>=2 &&
          crossproduct(convexhull_up.back()-convexhull_up[convexhull_up.size()-2],
                       	p-convexhull_up[convexhull_up.size()-2]) <= 0)
        		convexhull_up.pop_back();
    		convexhull_up.push_back(p);
	}
	// now just merge em

	for(int i=1; i<convexhull_up.size()-1; i++)
    		convexhull_low.push_back(convexhull_up[i]);

	for(auto& p: convexhull_low)
    		cout << p.x << " " << p.y << "\n";

}
