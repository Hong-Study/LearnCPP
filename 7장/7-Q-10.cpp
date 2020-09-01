#include<iostream>
using namespace std;
class Statistics{
	private:
	int *array;
	int i;
	
	public:
	Statistics(){ i = 0;}
	bool operator !();								//empty 확인
	Statistics& operator <<(int a[]);				//복사
	Statistics& operator <<(int a);					//복사
	Statistics& operator >>(int &a);				//평균 보내기
	void operator ~();								//모두 출력
	
};

bool Statistics::operator !(){
	if(i==0)
		return true;
	else
		return false;
}
Statistics& Statistics::operator <<(int a[]){
	int len = 5;
	if(!*this){										// 비어있는지 자기자신을 확인
		array = new int [len];
		for(i;i<len;i++){
			array[i] = a[i];
		}
	}
	else{											//새로운 tmp 배열에 복사후 다시 array배열에 복사
		int *tmp = new int [i+len];
		for(int j=0;j<i;j++){
			tmp[j] = array[j];
		}
		for(int j=0;j<len;j++){
			tmp[i++] = a[j];
		}
		delete[] array;
		array = new int [i];
		
		for(int j=0;j<i;j++){
			array[j] = tmp[j];
		}
		delete[] tmp;
	}
	return *this;
}

Statistics& Statistics::operator <<(int a){
	if(!*this){
		array = new int [1];
		array[i++] = a;
	}
	else{
		int *tmp = new int [i+1];
		for(int j=0;j<i;j++){
			tmp[j] = array[j];
		}
		tmp[i++] = a;
		delete[] array;
		array = new int [i];
		for(int j=0;j<i;j++){
			array[j] = tmp[j];
		}
		delete[] tmp;
	}
	
	
	return *this;
}
Statistics& Statistics::operator >>(int &a){
	int result= 0;
	for(int j=0;j<i;j++){
		result += array[j];
	}
	a = result/i;
	
	return *this;
}
void Statistics::operator ~(){
	for(int j=0;j<i;j++){
		cout<<array[j]<<' ';
	}
	cout<<endl;
}

int main(){
	Statistics stat;
	int x[5];
	for(int i=0;i<5;i++) cin >> x[i];
	stat << x;
	stat << 100 << 200;
	~stat;
	
	int avg;
	stat >> avg;
	cout<< "avg = "<<avg<<endl;
}