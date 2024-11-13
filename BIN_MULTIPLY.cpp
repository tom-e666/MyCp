/* this implementation was manifested by tempura according to
Computer Science and Assembly Language orchestrated by Master Huy Tr. 

the implementation includes basic BIN multiply and BOOTH multiply, no interacting implementation
the author suggest using struct of bit and byte to build-up, but due to dedicated requirement,
basic container is used.
*BIN string size
*extension string
*signed or unsigned
*/
#include<bits/stdc++.h>
using namespace std;

struct bit{
	bool b;
	bit(bool b =0): b(b){}
	friend bit operator +(bit x, bit y){
		return bit(x.b^y.b);
	}
	friend bool isMemorised(bit x, bit y){
		return (x.b &x.b);
	}
	friend istream& operator >>(istream& is, bit& a){
		char c;
		is>>c;
		a.b=(bool)c;
		return is;
	}
	friend ostream& operator<<(ostream& os, bit a){
		os<<a.b;
		return os;
	}
	operator bool() const {
		return b;
	}
	operator int() const{
		if(b) return 1;
		return 0;
	}

};
struct bbyte{
	const int Sz=8;		//8-bit string
	vector<bit> v;
	bbyte(){
		v.resize(Sz);
	}
	friend istream& operator>>(istream & is, bbyte &b){
		for(auto&i : b.v) cin>>i; 		//implicit convert : 0-> false non-zero-> true
		return is;
	}
	friend ostream& operator<<(ostream & os, bbyte b){
		for(auto i:b.v) cout<<i;
		return os;
	}
	int toDEC(bool isSigned=false){
		int res=0;	
		for(auto i: v){
			res<<=1;
			res+=i;
		}
		if(isSigned && v[0]==1){
			res-= pow(2,8);
		}
		return res;
	}
	void extension(int i,bool isSigned=false){//i for lacks
		vector<bit> t;
		if(isSigned){
			t=vector<bit>(i,bit(1));
		}else{
			t=vector<bit>(i,0);
		}
		for(int p=0;p<Sz-p;++p){
			t.emplace_back(v[i]);
		}
		v=t;
	}
	void fromStr(string s,bool isSigned=false){
		stringstream ss(s);
		ss>>*this;
		extension(Sz-s.size(),isSigned);
	}
	


};

	void calAdd(){
		string s;
		bbyte b1,b2;
		getline(cin, s);
		b1.fromStr(s,0);
		getline(cin,s);
		b2.fromStr(s,0);

		cout<<b1<<"\n"<<"+\n"<<b2<<"\n=\n"<<b1+b2; 
	}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	bbyte b;
	cin>>b;
	cout<<b;
	cout<<b.toDEC(1);
}
