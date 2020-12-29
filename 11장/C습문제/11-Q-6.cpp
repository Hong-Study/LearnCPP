#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
	double n;
	cout.setf(ios::left);
	cout.width(15);
	cout<<"Number";
	cout.width(15);
	cout<<"Square";
	cout.width(15);
	cout<<"Square Root"<<endl;
	for(n = 0;n<=45;n+=5){
		cout<<setw(15)<<setfill('_')<<n;
		cout<<setw(15)<<setfill('_')<<n*n;
		cout<<setw(15)<<setfill('_')<<setprecision(3)<<sqrt(n);
		cout<<endl;
	}
}