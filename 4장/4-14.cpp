#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cout << "문자열 입력 > ";
    getline(cin,s,'\n');
    int sum=0;
    int startindex = 0;

    while(true){
        int fIndex = s.find('+',startindex);
        if(fIndex == -1){
            string part = s.substr(startindex);
            if(part == "")break;
            cout<<part<<endl;
            sum += stoi(part);
            break;
        }
        int count = fIndex - startindex;
        string part = s.substr(startindex,count);

        cout<<part<<endl;
        sum+=stoi(part);
        startindex = fIndex +1;
    }
    cout<<sum<<endl;

}