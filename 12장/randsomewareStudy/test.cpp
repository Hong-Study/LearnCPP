//랜섬웨어 공부용
#include<iostream>
#include<fstream>

using namespace std;

int main(){
	const char* srcFile = "../Deskrt.jpg";
	const char* copyFile = "./copy2.jpg";
	fstream fsrc(srcFile, ios::in | ios::binary | ios::out);
	fstream dsrc(copyFile,ios::binary | ios::out);
	if(!fsrc){
		cout<<srcFile<<" 열기 오류"<<endl;
		return 0;
	}
	if(!dsrc){
		cout<<copyFile<<" 열기 오류"<<endl;
		return 0;
	}
	
	int n;
	while((n = fsrc.get()) != EOF){
		cout<<hex<<n<<endl;
		n -= 1;
		fsrc.seekg(-1,ios::cur);
		fsrc.put(n);
	}
	/*
	int c;
	while((c = fsrc.get()) != EOF){
		cout<<hex<<c<<endl;
		fsrc.put(c);
	}*/
	
	fsrc.close();
	dsrc.close();
}