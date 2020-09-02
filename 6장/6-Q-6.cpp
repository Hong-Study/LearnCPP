#include<iostream>

using namespace std;
class ArrayUtility2{
	private:
	
	public:
	static int* Concat(int s1[],int s2[], int size){
		int *tmp = new int [size];
		int half = size/2;
		for(int i=0;i<half;i++){
			tmp[i] = s1[i];
			tmp[i+half] = s2[i];
		}
		return tmp;
	}
	static int* remove(int s1[], int s2[], int size, int& retsize){
		int *tmp = new int [size];
		bool type = true;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				if(s1[i] == s2[j])
					type = false;
			}
			if(type)
				tmp[retsize++] = s1[i];
			type = true;
		}
		retsize-=1;
		return tmp;
	}
};

int main(){
	ArrayUtility2 Utility;
	int s1[5],s2[5];
	cout<<"정수를 5개 입력하라. 배열 x에 삽입한다>>";
	for(int i=0;i<5;i++){
		cin>>s1[i];
	}
	cout<<"정수를 5개 입력하라. 배열 y에 삽입한다>>";
	for(int i=0;i<5;i++){
		cin>>s2[i];
	}
	cout<<"합친 정수 배열을 출력한다."<<endl;
	int *array = Utility.Concat(s1,s2,10);
	for(int i=0;i<10;i++){
		cout<<array[i]<<' ';
	}
	cout<<endl;
	delete[] array;
	int retsize = 0;
	array = Utility.remove(s1,s2,10,retsize);
	cout<<"배열 x에서 배열y를 뺀 결과를 출력한다. 개수는 "<<retsize<<endl;
	for(int i=0;i<retsize;i++){
		cout<<array[i]<<' ';
	}
	cout<<endl;
}