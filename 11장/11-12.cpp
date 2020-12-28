#include<iostream>

using namespace std;

ostream& fivestar(ostream& outs){
	return outs<<"*****";
}
ostream& rightarrow(ostream& outs){
	return outs<<"--->";
}
ostream& beep(ostream& outs){
	return outs<<"\a";
}

int main(){
	cout<<beep<<endl;
	cout<<rightarrow<<endl;
	cout<<fivestar<<endl;
}