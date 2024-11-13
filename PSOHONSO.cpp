#include<bits/stdc++.h>
using namespace std;

struct PhanSo{
	int t,m;
	PhanSo(int t=0,int m=1){
		t=t;
		m=m;
	}
	friend istream& operator>>(istream& is, PhanSo &ps){
		is>>ps.t>>ps.m;
		if(ps.m==0){
			cerr<<" m=0 ";
		}
		return is;
	}
	friend ostream& operator<<(ostream& os,PhanSo ps){
		cout<<ps.t<<"/"<<ps.m;
		return os;
	}
	friend bool operator !=(PhanSo a, PhanSo b){
		return !(a.t==b.t &&a.m==b.m);
	}
	void opt(){
		int c=__gcd(abs(t),abs(m));
		t/=c;
		m/=c;
	}
	
};
struct HonSo{
	int a;
	PhanSo bc;
	HonSo(int a=0,PhanSo bc={}){}
	friend istream& operator>>(istream& is, HonSo& hs){
		is>>hs.a>>hs.bc;
		return is;
	}
	friend ostream& operator<<(ostream& os, HonSo hs){
		cout<<hs.a<<" "<<hs.bc;

		return os;
	}
	void optHS(){
		bc.opt();
		int c=floor(bc.t/bc.m);
		a+=c;
		bc.t-=c*bc.m;
	}
	void optPS(){
		bc.t+=a*bc.m;
		a=0;
		bc.opt();
	}
	friend bool operator !=(HonSo x, HonSo y){
		return !(y.a==x.a && !(x.bc!=y.bc));
	}
	int tongCacThanhPhan(){
		return a+bc.t+bc.m;
	}
	friend bool operator > (HonSo x, HonSo y){
		return x.tongCacThanhPhan()>y.tongCacThanhPhan();
	}
};
int main(){
	HonSo x,y;
	cin>>x>>y;
	string command;
	cin>>command;
	cout<<((x!=y)?"TRUE\n":"FALSE\n");
	cout<<((x>y)?"TRUE\n":"FALSE\n");
	
	if(command=="true"){
		x.optHS();
		y.optHS();
		cout<<x<<"\n"<<y;
	}else{
		x.optPS();
		y.optPS();
		cout<<x.bc<<"\n"<<y.bc;
	}










}