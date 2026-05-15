#include<iostream>
#include<cmath>
using namespace std;
# define ll long long

template <typename T>
bool isbetween(T x,T xlow,T xhigh){
	return x>min(xlow,xhigh) && x<max(xlow,xhigh);
}

int main(){
	ll testcase;
	cin>>testcase;
	for(int i=0;i<testcase;i++){
		ll x1,y1,x2,y2,x3,y3,x4,y4, dir1,ref1,dir2,ref2,vvdir1,vvdir2,vvref1,vvref2;
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
/* slope comparison is the wrong approach as we amy divide by 0 hence not good instead just cross multiply*/
/*the following approach assumes ab is inifnte line segment and so does cd but it is not this is more subtle*/
/*how the fuck do we resolve this?? main question - by checking the other way also*/
/*till now it is all fine we had checks but we forgot about the collinear case many intersections*/
		/*AB reference and CD under onservation*/
		dir1 = (y3-y1)*(x2-x1);
		ref1 = (y2-y1)*(x3-x1);
		dir2 = (y4-y1)*(x2-x1);
		ref2 = (y2-y1)*(x4-x1);

		/*CD reference and AB under observation*/
		vvdir1 = (y1-y3)*(x4-x3);
		vvref1 = (y4-y3)*(x1-x3);
		vvdir2 = (y2-y3)*(x4-x3);
		vvref2 = (y4-y3)*(x2-x3);

		if((dir1>ref1 && dir2>ref2)||(vvdir1>vvref1 && vvdir2>vvref2)){
			cout<<"NO\n";
		}
		else if((dir1<ref1 && dir2<ref2)||(vvdir1<vvref1 && vvdir2<vvref2)){
			cout<<"NO\n";
		}
		else if(dir1==ref1 && dir2==ref2){
			if((isbetween(x3,x1,x2))||(isbetween(y3,y1,y2))){
				cout<<"YES\n";
			}
/*important previously only checked for x3 but it may happen that x4 is the point hence check that also*/
/*important dont add an if below otherwise it checkf or both and prints more than 1 output*/
/*add what if x1 and x2 inside x3 and x4*/
			else if((isbetween(x4,x1,x2))||(isbetween(y4,y1,y2))){
				cout<<"YES\n";
			}

                        else if((isbetween(x1,x3,x4))||(isbetween(y1,y3,y4))){
                                cout<<"YES\n";
                        }

                        else if((isbetween(x2,x3,x4))||(isbetween(y2,y3,y4))){
                                cout<<"YES\n";
                        }


			else if((x1==x3 && y1==y3) || (x2==x4 && y2==y4)){
				cout<<"YES\n";
			}
			else if((x1==x4 && y1==y4) || (x2==x3 && y2==y3)){
				cout<<"YES\n";
			}
			else{

				cout<<"NO\n";
			}
		}
		else{
			cout<<"YES\n";
		}
	}
}
