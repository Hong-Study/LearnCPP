#include<iostream>
#include<string>

using namespace std;

istream& prompt(istream& stream){
	cout<<"암호는 ? ";
	return stream;
}
int main(){
	string password;
	
	cin>>prompt>>password;
	cout<<password;
}