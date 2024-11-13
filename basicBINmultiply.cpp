/* guidance:
	Thuat toan bao gom :		addition
								normal multiply
								bit string size: line 12
								signed or no sign" line 13
	author: tempura (48.01.104.135)
	built 07/03/2024
*/
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
const int sz = 8;
const bool isSigned=true; // previously implemented as fn parameter
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
string addition(string a, string b) { // a, b must be sz-bit strings
    reverse(all(a));
    reverse(all(b));
    string res = "";
    int mem = 0;
    int t;
    for (int i = 0; i < sz; ++i) {
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
int toInt(string a){
	int res=0;
	for(char i:a){
		res<<=1;
		res+=i-'0';
	}
	if(isSigned && a.size() &&a[0]=='1'){
		res-=pow(2,a.size());
	}
	return res;
}
bool isOut(string a, string b){
	int x=toInt(a);
	int y=toInt(b);
	if(isSigned){
		return abs(x*y)>=pow(2,sz-1)-1;
	}else{
		return abs(x*y)>=pow(2,sz)-1;
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
    cerr<<a<<"\n";
    cerr<<b<<"\n";
    string res=basicMultiply(a,b);
    cout<<res;
    cerr<<toInt(a)<<"\n"<<toInt(b)<<"\n"<<toInt(res)<<"\n";
    

}
