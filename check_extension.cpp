#include<bits/stdc++.h>
using namespace std;
bool isSigned=true;
int sz=8;
void extension(string &s) {
	char msb='0';
	if(s.size()) msb=s[0];
	int ad =  sz - s.size();
    if(ad==0){
    	return;
    } else if(ad<0){
    	s=string(s.begin()-ad,s.end());
    	return;
    }else{
    if (isSigned) {
        s = string(ad,msb) + s; 
    } else {
        s = string(ad, '0') + s; 
    }
	}
}
string c(int n){
	string res;
	while(n){
		res+= to_string(n%2);
		n/=2;
	}
	if(res.size())
	return res;
	return "0";
}
int main(){
	for(int i=0;i<(1<<4);++i) {
		string s=c(i);
		extension(s);
		cout<<c(i)<<" - "<< s<<"\n";
	}
}