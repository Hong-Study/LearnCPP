#include<iostream>

using namespace std;

template <class type>
type* remove(type src[], int sizeSrc, type minus[], int sizeMinus, int& retsize){
	retsize = 0;
	type *p = new type[sizeSrc];
	for(int i=0;i<sizeSrc;i++){
		bool count = true;
		for(int j=0;j<sizeMinus;j++){
			if(src[i] == minus[j])
				count = false;
		}
		if(count){
			p[retsize++] = src[i];
		}
	}
	return p;
}

int main(){
	int a[] = {1,2,3,4,5};
	int b[] = {3,5};
	int size;
	
	int *p = remove(a,5,b,2,size);
	for(int i=0;i<size;i++){
		cout<<p[i]<<" ";
	}
	cout<<endl;
}