#include<iostream>

using namespace std;

class Phone{
	string name;
	string telnum;
	string address;
	
	public:
	Phone(string name="", string telnum = "", string address = ""){
		this->name = name;
		this->telnum = telnum;
		this->address = address;
	}
	friend istream& operator >>(istream& stream, Phone& phone);
	friend ostream& operator <<(ostream& stream, Phone& phone);
};

istream& operator >>(istream& stream, Phone& phone){
	cout<<"이름 : ";
	stream>>phone.name;
	cout<<"전화번호 : ";
	stream>>phone.telnum;
	cout<<"주소 : ";
	stream>>phone.address;
	
	return stream;
}

ostream& operator <<(ostream& stream, Phone& phone){
	stream<<"( "<<phone.name<<", "<<phone.telnum<<", "<<phone.address<<" )"<<endl;
	
	return stream;
}

int main(){
	Phone girl, boy;
	cin>>girl>>boy;
	cout<<girl<<boy;
}