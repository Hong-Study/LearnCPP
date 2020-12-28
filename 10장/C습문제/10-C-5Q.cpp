#include<iostream>

using namespace std;

template <class type>
type* concat(type a[], int sizea, type b[], int sizeb){			//제네릭 함수
	type *p = new type[sizea + sizeb];
	for(int i=0;i<sizea;i++){
		p[i] = a[i];
	}
	for(int i=0;i<sizeb;i++){
		p[i+sizea] = b[i];
	}
	return p;
}

int main(){
	int x[] = {1,2,3,4};
	int y[] = {5,6,7,8,9};
	
	int *p = concat(x,4,y,5);
	for(int i=0;i<9;i++){
		cout<<p[i]<<" ";
	}
	cout<<endl;
	
	char a[] = {'L','O','V','E',' '};
	char b[] = {'C','O','D','E'};
	char *p1 = concat(a,5,b,4);
	for(int i=0;i<9;i++){
		cout<<p1[i];
	}
	cout<<endl;
}