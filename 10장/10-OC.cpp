#include<iostream>					//STL vector사용
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

class Word{
	string english;
	string korean;
	
	public:
	Word(string english, string korean){
		this->english = english;
		this->korean = korean;
	}
	string re_english(){
		return english;
	}
	string re_korean(){
		return korean;
	}
};

int main(){
	vector<Word> v;
	
	v.push_back(Word("human", "인간"));
	v.push_back(Word("society", "사회"));
	v.push_back(Word("dall", "인형"));
	v.push_back(Word("emotion", "감정"));
	v.push_back(Word("painting", "그림"));
	v.push_back(Word("trade", "거래"));
	v.push_back(Word("animal", "동물"));
	v.push_back(Word("photo", "사진"));
	v.push_back(Word("bear", "곰"));
	
	srand((unsigned)time(NULL));
	
	while(1){
		int n = rand()%9;
		int choice = 0;
		string wont[4];
		cout<<v[n].re_english()<<endl;
		int i = 1;
		while(i<=4){
			int a = rand()%9;
			bool k = true;
			for(int j=0;j<i-1;j++){
				if(wont[j] == v[a].re_korean())
					k = false;
			}
			if(i == (n%4+1)){
				wont[i-1] = v[n].re_korean();
				cout<<'('<<i<<") "<<v[n].re_korean()<<"  ";
				i++;
			}else if(k){
				wont[i-1] = v[a].re_korean();
				cout<<'('<<i<<") "<<v[a].re_korean()<<"  ";
				i++;
			}
		}
		cout<<":> ";
		cin>>choice;
		if(choice<1 || choice > 4)
			return 0;
		else if(wont[choice-1] == v[n].re_korean())
			cout<<"Excellent !!"<<endl<<endl;
		else
			cout<<"NO !!!"<<endl<<endl;
	}
}