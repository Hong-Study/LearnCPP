#include<iostream>
#include<string>

using namespace std;

class Histogram{
    string word;
    int num[26] = {0,};
    int count;

    public:
    Histogram(string word){ this->word = word; }
    Histogram& operator <<(string s);
    Histogram& operator <<(char s);
    void operator !();
    
};
Histogram& Histogram::operator<<(string s){
    word+=s;
    count = 0;
	return *this;
}
Histogram& Histogram::operator <<(char s){
    word+=s;
	return *this;
}
void Histogram::operator !(){
	cout<<word<<endl;
    for(int i=0;i<word.size();i++){
        int a = word[i];
        if(a>=65 && a<=90){
            num[a-65]++;
            count++;
        }else if(a>=97 && a<=122){
            num[a-97]++;
            count++;
        }
    }
    char a = 'a';
    for(int i=0;i<26;i++){
        cout<<a<<"("<<num[i]<<")"<<"\t: ";
        for(int j=0;j<num[i];j++)
            cout<<"*";
        cout<<endl;
        a++;
    }
}
int main(){
    Histogram elvisHisto("Wise men say, \nonly fools rush in But I can't help, \n");
    elvisHisto<<"falling"<< " in love with you"<< "- by ";
    elvisHisto<<'k'<<'i'<<'t';
    !elvisHisto;
}