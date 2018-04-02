#include <bits/stdc++.h>
using namespace std;

template <class t>
class searcher{
private:
	int numberComp;
	int size;
	vector <t> v;
	map <char,int>mp;
public:
	void loadData (){
		fstream fs;
		fs.open("tata.txt");
		fs>>size;
		for (int i=0;i<size;i++){
			t tmp;
			fs>>tmp;
			v.push_back(tmp);
			if (i>0&&v[i-1][0]<v[i][0]){
				mp[v[i][0]]=i;
			}
		}
		sort(v.begin(),v.end());
	}
	int getStart(char c){
		return mp[c];
	}
	int getEnd(char c){
		return mp[c];
	}
	int Size(){
		return size;
	}
	int binarySearch (t value,int l,int h){
		t pos=v[(l+h)/2];
		if (l==h||l==h-1){
			numberComp+=(l==h)?1:2;
			return-1;
		}
		numberComp+=2;
		if (pos<value){
			return binarySearch(value,(l+h)/2,h);
		}
		else if (pos>value){
			numberComp++;
			return binarySearch(value,l,(l+h)/2);
		}
		else {
			numberComp++;
			return (l+h)/2;
		}
	}
	t operator[](int i){
		return v[i];
	}
	int numberOfComp(){
		return numberComp;
	}
	searcher(){
		numberComp=0;
		size=0;
	}
};

int main() {
	for (int i=0;i<100;i++){
	searcher <string> s;
	s.loadData();
	int random = rand() % 109558;
	clock_t start=clock();
	s.binarySearch(s[random],s.getStart(s[random][0]),s.getEnd(s[random][0]+1));
	clock_t end=clock();
	cout<<fixed<<setprecision(7)<<(double)(end-start)/CLOCKS_PER_SEC<<" "<<s.numberOfComp()<<endl;
	}
	cout<<endl<<endl<<endl;
	for (int i=0;i<100;i++){
		int range= rand()%26;
		range+=97;
		string ma;
		for (int i=0;i<6;i++)
			ma+=range;
		searcher <string> s;
		s.loadData();
		clock_t start=clock();
		s.binarySearch(ma,s.getStart(ma[0]),s.getEnd(ma[0]+1));
		clock_t end=clock();
		cout<<fixed<<setprecision(10)<<(double)(end-start)/CLOCKS_PER_SEC<<"\t"<<s.numberOfComp()<<endl;
	}

}
