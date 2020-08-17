#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void Q1(){
    for(int i=1;i<=100;i++){
        cout<<i<<"\t";
        if(i%10 == 0)
            cout<<"\n";        
    }
}

void Q2(){
    for(int i=2;i<=9;i++){
        for(int j=1;j<10;j++){
            cout<<i<<"x"<<j<<"="<<i*j<<"\t";
        }    
        cout<<std::endl;
    }
}

void Q3(){
    int a,b;
    cin>>a>>b;
    if(a>b)
        cout<<a<<std::endl;
    else
        cout<<b<<std::endl;
}

void Q4(){
    double a;
    double max = 0;
    for(int i=0;i<5;i++){
        cin>>a;
        if(max<a)
            max = a;
    }
    cout<<max<<std::endl;
}

void Q5(){
    char line[100];
    int i=0;
    int count = 0;
    cin.getline(line,100);
    while(line[i]){
        if(line[i] == 'x')
            count++;
        i++;
    }
    cout<<count<<std::endl;
}

void Q6(){
    string a,b;
    getline(cin, a);
    getline(cin, b);
    if(a == b)
        cout<<"same"<<std::endl;
    else
        cout<<"diffrent"<<std::endl;
}
void Q7(){
    char line[100];
    while(1){
        cin.getline(line,100);
        if(!strcmp(line,"yes"))
            break;
    }
}
void Q8(){
    int a,b;
    while(1){
        cout<<"짬뽕:1 짜장:2 군만두:3 종료:4 >>";
        cin>>a;
        switch(a){
            case 1:
            cout<<"몇인분?";
            cin>>b;
            cout<<"짬봉 "<<b<<"인분 나왔습니다."<<std::endl;
            break;
            case 2:
            cout<<"몇인분?";
            cin>>b;
            cout<<"짜장면 "<<b<<"인분 나왔습니다."<<std::endl;
            break;
            case 3:
            cout<<"몇인분?";
            cin>>b;
            cout<<"아이스군만도 "<<b<<"인분 나왔습니다."<<std::endl;
            break;
            case 4:
            cout<<"오늘 영업은 끝났습니다."<<std::endl;
            return;
            default:
            cout<<"다시 주문하세요!!"<<std::endl;
        }
    }
}
int main(){
    Q8();
}
