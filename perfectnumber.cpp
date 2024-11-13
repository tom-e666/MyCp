#include <iostream>
#include <cmath>
using namespace std;
bool is_perfect_number_advanced(int num) {
    if (num <= 1 || num % 2 != 0) {
        return false;
    }

    int p = 2;
    while ((pow(2, p) - 1) *pow(2, p - 1) <= num) {
        int temp=((pow(2, p) - 1) * pow(2, p - 1));
        if (num % temp == 0) {
            return true;
        }
        p++;
    }

    return false;
}

int main() {
    int number = ;
    cout<<is_perfect_number_advanced(number);

   
}
