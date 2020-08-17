#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cout << "여러줄의 문자열을 입력하세여. 입력의 끝은 &입니다."<<endl;
    getline(cin,s,'&');
    cin.ignore();                               //&뒤의 개행문자 제거 (왜필요함?)

    string f,r;
    cout<<endl<<"find : ";
    getline(cin,f);
    cout << "replace : ";
    getline(cin,r);

    int startIndex = 0;
    while(true){
        int fIndex = s.find(f,startIndex);      //검색
        if(fIndex == -1)
            break;
        s.replace(fIndex,f.length(),r);         //fIndex부터 문자열 f의 길이만큼 문자열 r로 변경
        startIndex = fIndex + r.length();
    }
    cout<<s<<endl;
}