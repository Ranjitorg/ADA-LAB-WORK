#include<iostream>
#include<cmath>
using namespace std;
const float g = 9.8;
const double baseCase = 1.0/(2*g);
int UE243116ball(double height){
 if(height < baseCase) return 0;
 return 1 + UE243116ball( pow(sqrt(height*g*2)*0.575,2)/(2*g));
}
int main(){
 int height;
 cout<<"Height: ";
 cin>>height;
 cout<<"Total number of bounces : "<<UE243116ball(height)<<endl;
 return 0;
}