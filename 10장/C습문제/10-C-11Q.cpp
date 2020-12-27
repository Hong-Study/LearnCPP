#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Book{
	int Year;
	string book_name;
	string maker;
	
	public:
	Book(int Year, string book_name, string maker){ 
		this->Year = Year; 
		this->book_name = book_name; 
		this->maker = maker; 
	}
	
	string Re_maker(){
		return maker;
	}
	string Re_name(){
		return book_name;
	}
	int Re_Year(){
		return Year;
	}
};

int main(){
	vector<Book> v;
	
	cout<<"입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다."<<endl;
	int n = 0;
	string name;
	string maker;
	while(1){
		cout<<"년도 >> ";
		cin>>n;
		if(n == -1)
			break;
		cout<<"책이름 >> ";
		cin>>name;
		cout<<"저자 >> ";
		cin>>maker;
		v.push_back(Book(n,name,maker));
	}
	cout<<"총 입고된 책은 "<<v.size()<<"권 입니다."<<endl;
	cout<<"검색하고자 하는 저자 이름을 입력하세요 >> ";
	cin>>name;
	for(int i=0;i<v.size();i++){
		if(v[i].Re_maker() == name){
			cout<<v[i].Re_Year()<<"년도, "<<v[i].Re_name()<<", "<<v[i].Re_maker()<<endl;
			break;
		}
	}
	cout<<"검색하고자 하는 년도를 입력하세요 >> ";
	cin>>n;
	for(int i=0;i<v.size();i++){
		if(v[i].Re_Year() == n){
			cout<<v[i].Re_Year()<<"년도, "<<v[i].Re_name()<<", "<<v[i].Re_maker()<<endl;
			break;
		}
	}
}