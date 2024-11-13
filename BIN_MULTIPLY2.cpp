#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

const int sz = 8;

bool checkFormat(string s) {
    return true;
}

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
string addition(string a, string b) { // a, b must be 8-bit strings/sz-bit strings
    reverse(all(a));
    reverse(all(b));
    string res = "";
    int mem = 0;
    int t;
    for (int i = 0; i < 7; ++i) {
        t = (a[i] - '0') + (b[i] - '0') + mem;
        if (t > 1) {
            mem = 1;
            res += char(t % 2 + '0');
        } else {
            res += char(t + '0');
            mem = 0;
        }
    }
    if (mem)
        res += '1';
    reverse(all(res));
    extension(res);
    return res;
}
int toInt(string a,bool isSigned=false){
	int res=0;
	for(char i:a){
		res<<=1;
		res+=i-'0';
	}
	if(isSigned && a.size()){
		res-=(a[a.size()-1])*pow(2,a.size());
	}
	return res;
}
bool isOut(string a, string b, bool isSigned=false){
	int x=toInt(a);
	int y=toInt(b);
	if(isSigned){
		return abs(x*y)>=127;
	}else{
		return abs(x*y)>=255;
	}
}
string basicMultiply(string a, string b){

	if(isOut(a,b)){
		return "Out of limit";
	}
	string res;
	extension(res);
	reverse(all(b));
	for(char i:b){
		if(i=='1'){
			res=addition(res,a);
		}
		cerr<<a<<" ";
		a+='0';
		extension(a);
	}
	return res;
}


int main() {
    string a, b;
    cin >> a >> b;

    extension(a);	
    extension(b);
    cout<<basicMultiply(a,b);
    return 0;
}
