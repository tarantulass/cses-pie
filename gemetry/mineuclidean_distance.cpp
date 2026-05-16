// idea is very very important in nearest neighbour search
// collison detection
// for higher dimension the complexity is 0(n*k*logn) interestingly for 2d we only stick to 2 sorts
// clustering and spatial database (vector database)
#include<bits/stdc++.h>

using namespace std;
using ll=long long;

struct point{
	ll x,y;
};

/*
The algorithm
1. define the distance function
2. define the basecase funciton for the recursion we use
3. use the divide and conquer algorithm for left and right parts and maintain different array for x and y
*/

ll dist(point a, point b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

ll bruteforce_basecase(vector<point>& pt, int l, int r){
	ll mindist = LLONG_MAX;
	for(int i=l;i<r;i++){
		for(int j=i+1;j<r;j++){
		 mindist = min(mindist, dist(pt[i],pt[j]));
		}
	}
	return mindist;
}

ll closeststrip(vector<point>& strip, ll d){
	ll mindist = d;
	int n = strip.size();

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n && (strip[j].y - strip[i].y)<mindist;j++){
			mindist = min(mindist, dist(strip[i],strip[j]));
		}
	}
	return mindist;
}

// x sort helps in refining the search space and y sort boosts in the strip!!
ll bestpair(vector<point>& px, vector<point>& py){
	int n = px.size();
	if(n<=3){
		return bruteforce_basecase(px,0,n);
	}
	int mid = n/2;
	point midpoint = px[mid];

	vector<point> pxl(px.begin(), px.begin()+mid);
	vector<point> pxr(px.begin()+mid, px.end());

	vector<point> pyl,pyr;
	for(auto& p:py){
		if(p.x<midpoint.x)
			pyl.push_back(p);
		else
			pyr.push_back(p);
	}

	ll dl = bestpair(pxl,pyl);
	ll dr = bestpair(pxr,pyr);

	ll d = min(dl,dr);

	vector<point> strip;
	for(auto& p:py){
		if(pow(p.x-midpoint.x,2)<d)
			strip.push_back(p);
	}
	return min(d, closeststrip(strip,d));
}

int main(){
	int n;
	cin>>n;
	ll x,y;
	vector<point> px,py;
// this way we have actual set and left and right total 4 vector -> wrong we only declare 2
// in the later part of recursion we have left and right declared there

	for(int i=0;i<n;i++){
		cin>>x>>y;
		point p;
		p.x = x;
		p.y = y;
		px.push_back(p);
		py.push_back(p);
	}
	sort(px.begin(), px.end(), [](point a, point b)
		{return a.x<b.x;}
	);
	sort(py.begin(),py.end(), [](point a, point b)
		{return a.y<b.y;}
	);
	cout<<bestpair(px,py);
}
