#include<iostream>
#include<string>

using namespace std;
class Histogram{
    string word;
    int num[26] = {0,};
    int count;

    public:
    Histogram(string word){ this->word = word; }
    void put(string s);
    void putc(string s);
    void print();
    
};
void Histogram::put(string s){
    word+=s;
    count = 0;
}
void Histogram::putc(string s){
    word.append(s);
}
void Histogram::print(){
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
    Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
    elvisHisto.put("falling in love with you");
    elvisHisto.putc("-");
    elvisHisto.put("Elvis Presely");
    elvisHisto.print();
}