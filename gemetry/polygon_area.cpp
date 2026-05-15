// the question asks to return 2a hence it clearly points out to this shoelace formula
// formula is 1/2(sumofxiyi+1 - yixi+1)-> use modulo for wrap around
#include<iostream>
#include<vector>
// now not recommended #define ll long long
using ll = long long; //more widely accepted not needed here as we only have 1 single polygon
using namespace std;

int main(){
	int sides;
	vector<pair<ll,ll>> coords;
 	cin>>sides;
	ll area = 0;// min 4 points needed hence adding them
	ll x1,y1;
	for(int i=0;i<sides;i++){
		cin>>x1>>y1;
		coords.push_back({x1,y1}); //make a pair in curly
	}
	for(int i=0;i<sides;i++){
		// instead also use auto& [x1,y1] =  similar to python
		auto& p1 = coords[i]; // this is elegante papasito
		auto& p2 = coords[(i+1)%sides];
		area += (p1.first*p2.second) - (p1.second*p2.first);
	}
	cout<<abs(area); // no need of 1-2*(area<0) less readable and we dont want that
}
