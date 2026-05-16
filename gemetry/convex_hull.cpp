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
};

ll crossproduct(vector<point> a, vector<point> b){
	return a.x*b.y - a*y*b.x
}

int main(){
	// initialize
	ll testcase;
	vector<point> coords;
	vector<point> convexhull_low;// finally we print this after all those common terms are done
	vector<point> convexhull_up;

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
	

}
