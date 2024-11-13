#include<bits/stdc++.h>
/*
 idea: với biểu thức kiểu ...a+b, nhận thấy không có
 cách thêm ngoặc nào làm thay đổi a+b thành a-b hay b-a
 do đó có thể chủ động gom nhóm để đưa biểu thức về dạng
 a-b-c-d..... với số lượng dấu trừ được giữ nguyên ban đầu,
 sau đó thực hiện đánh giá 
*/ 
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int> v(n);
	vector<char> vc(n-1);
	cin>>v[0];
	for(int i=1;i<n;++i){
		cin>>v[i]>>vc[i-1];
	}





}