#include<iostream>

using namespace std;
class Converter{
	protected:
	double ratio;
	virtual double convert(double src)=0;		//src를 다른 단위로 변환;
	virtual string getSourceString()=0;			//src 단위 명칭
	virtual string getDestString()=0;			//dest 단위 명칭
	
	public:
	Converter(double ratio) { this->ratio = ratio; }
	void run(){
		double src;
		cout<< getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
		cout<< getSourceString() << "을 입력하세요>> ";
		cin>>src;
		cout<<"변환 결과 : "<<convert(src)<<getDestString() << endl;
	}
};
class WonToDollar : public Converter{
	
	public:
	WonToDollar(double a) : Converter(a){}
	double convert(double src){
		return src/ratio;
	}
	string getSourceString(){
		return "KM";
	}
	string getDestString(){
		return "Mile";
	}
};

int main(){
	WonToDollar wd(1.609344);
	wd.run();
}