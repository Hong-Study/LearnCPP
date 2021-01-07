#include<iostream>
#include<fstream>

using namespace std;

int main(){
	const char* srcFile = "./Deskrt.jpg";
	const char* copyFile = "./copyDeskrt.jpg";
	
	ifstream fsrc(srcFile, ios::in | ios::binary);
	if(!fsrc){
		cout<<srcFile<<" 열기 오류"<<endl;
		return 0;
	}
	ofstream fdest(copyFile, ios::out | ios::binary);
	if(!fdest){
		cout<<copyFile<<" 열기 오류"<<endl;
		return 0;
	}
	int c;
	while((c = fsrc.get()) != EOF){
		fdest.put(c);
	}
	cout<<srcFile<<" 을"<<copyFile<<"로 복사 완료"<<endl;
	
	fsrc.close();
	fdest.close();
}