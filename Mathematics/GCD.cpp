#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    int aux = b;
    if (!(a % b)) return b;
    b = a% b;
    return gcd(aux, b);
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << gcd(a ,b)  <<  '\n';
}
