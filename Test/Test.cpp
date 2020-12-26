#include<iostream>

using namespace std;

template <class T>
T add(T data[], int n){
	T sum = 0;
	for(int i=0;i<n;i++){
		sum+=data[i];
	}
	return sum;
}
class Test{
	public:
	int add(int data[], int n){
		int sum = 0;
		for(int i=0;i<n;i++){
			sum+=data[i];
		}
		return sum;
	}
};
int main (){
	int data[] = {1,2,3,4,5};
	int n = 5;
	Test test;
	
	cout<<"Add 함수 : "<<add(data,n)<<endl;
	cout<<"Test클래스 : "<<test.add(data,n)<<endl;
}