  #include<bits/stdc++>
  bool isPowerOfFour(int n) {
        while(n){
            if(n==1) return true;
            n>>=2; 
        }
        return false;
    }