/* guidance:
    Thuat toan bao gom :        
                                no sign BOOTH_MULTIPLY 
                                signed BOOTH_MULTIPLY 
    author: tempura (48.01.104.135)
    built 07/03/2024
*/
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

string addition(string a, string b) {
    int i = a.size(), j = b.size();
    string res = "";
    int mem = 0;
    while (i && j) {
        int t = (a[i - 1] - '0') + (b[j - 1] - '0') + mem;
        res = char(t % 2 + '0') + res;
        mem = t >= 2 ? 1 : 0;
        i--;
        j--;
    }
    while (i) {
        int t = (a[i - 1] - '0') + mem;
        res = char(t % 2 + '0') + res;
        mem = t >= 2 ? 1 : 0;
        i--;
    }
    while (j) {
        int t = (b[j - 1] - '0') + mem;
        res = char(t % 2 + '0') + res;
        mem = t >= 2 ? 1 : 0;
        j--;
    }
    if (mem) {
        res = '1' + res;
    }
    return res;
}

string boothMultiplication(string M, string Q) {
    if (M.size() < Q.size())
        swap(M, Q);
    string C = "0";
    string A = string(M.size(), '0');
    int Count = Q.size();

    auto shiftRCAQ = [&]() {
        Q = A[A.size() - 1] + string(begin(Q), Q.end() - 1);
        A = C + string(begin(A), A.end() - 1);
        C = "0";
    };

    auto assignCAAM = [&]() {
        string res = addition(A, M);
        if (res.size() > A.size()) {
            C = res[0];
            A = string(res.begin() + 1, res.end());
        } else {
            A = res;
        }
    };

    while (Count) {
        if (Q[Q.size() - 1] == '1')
            assignCAAM();
        shiftRCAQ();
        Count--;
    }

    return A + Q;
}   
string boothMultiplication_signed(string M, string Q){
    if (M.size() < Q.size())
        swap(M, Q);
    string oM="";
    for(auto i: M){
        if(i=='0'){
            oM+='1';
        }else{
            oM+='0';
        }
    }
    oM=addition(oM,"1");
    string C = "0";
    string A = string(M.size(), '0');
    string Q0="0";
    string Q_1="0"; 
    int Count = Q.size();



     auto shiftRAQQ= [&]() {
        Q_1 =Q[Q.size()-1];
        Q=A[A.size()-1]+string (begin(Q),end(Q)-1);
        if(A[0]=='0'){
            A="0"+string(A.begin(),A.end()-1);
        }else{
            A="1"+string(A.begin(),A.end()-1);
        }
     
    };

    auto assignAAM = [&]() {

        // Q0 = Q[Q.size() - 1];
        if (Q0 != Q_1) {
            if (Q0 == "1") {
                A = addition(A, oM);

            } else {
                A = addition(A, M);
            }


            // Keep only the least significant bits of A
            int p = A.size() - M.size();
            A = A.substr(p, M.size());
            
        }


    };
    

    while (Count) {
    Q0 = Q[Q.size() - 1];
    if (Q0 !=Q_1 ) assignAAM();
    shiftRAQQ();
    Count--;
    }
    return A + Q;
}
int toInt(string a,bool isSigned=false){
    int res=0;

    for(char i:a){
    res <<= 1;
    res+=i-'0';
    }
    if(isSigned && a.size() &&a[0]=='1'){
        res-=pow(2,a.size());
    }
    return res;
}

int main() {
    string a="10000001", b="11111011"; //input here
    string res;
    // res=boothMultiplication(a, b);
    // cout <<a<<"\n"<<b<<"\n"<<res <<"\n";
    // cout<<toInt(a)<<" * " << toInt(b)<<" = "<<toInt(res)<<"\n";
    res=boothMultiplication_signed(a,b);
    cout <<a<<"\n"<<b<<"\n"<<res <<"\n";
    cout<<toInt(a,true)<<" * " << toInt(b,true)<<" = "<<toInt(res,true)<<"\n";

}
