#include<iostream>
#include<string>

using namespace std;

class Book{
	string title;
	string press;
	string author;
	
	public:
	Book(string title="", string press="",string author=""){
		this->title = title;
		this->press = press;
		this->author = author;
	}
	friend istream& operator >> (istream& stream, Book &b);
	friend ostream& operator << (ostream& stream, Book b);
};

ostream& operator << (ostream& stream, Book b){
	stream<<b.title<<", "<<b.press<< ", "<<b.author<<endl;
	return stream;
}

istream& operator >> (istream& stream, Book &b){
	getline(stream, b.title);
	getline(stream, b.press);
	getline(stream, b.author);
	//stream>>b.title>>b.press>>b.author;
	return stream;
}

int main(){
	Book book;
	cin>>book;
	cout<<book;
}