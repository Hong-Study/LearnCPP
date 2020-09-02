#include<iostream>
#include<string>

using namespace std;

class Trace{
	private:
	static string *tag;
	static string *info;
	static int i;
	
	public:
	static void put(string a, string b){
		tag[i] = a;
		info[i] = b;
		i++;
	}
	static void print(string name="모든"){
		if(name == "모든"){
			cout<<"---------------모든 Trace정보를 출력합니다."<<endl;
			for(int a=0;a<i;a++){
				cout<<tag[a]<<":"<<info[a]<<endl;
			}
		}
		else{
			cout<<"---------------"<<name<<"태그의 Trace정보를 출력합니다."<<endl;
			for(int a=0;a<i;a++){
				if(tag[a] == name)
					cout<<tag[a]<<":"<<info[a]<<endl;
			}
		}
	}
	
};
string *Trace::tag = new string [100];
string *Trace::info = new string [100];
int Trace::i = 0;

void f(){
	int a,b,c;
	cout<<"두 개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()","정수를 입력받았음");
	c = a + b;
	Trace::put("f()","합 계산");
	cout<<"합은 "<<c<<endl;
}

int main(){
	Trace::put("main()","프로그램 시작합니다.");
	f();
	Trace::put("main()","종료.");
	
	Trace::print("f()");
	Trace::print();
	
}