#include <bits/stdc++.h>
#define MAX 65537

using namespace std;

bitset<65537> primes;

void siev(){
    primes.set();
    primes[0] = 0;
    primes[1] = 0;

    set<long long> all_primes;

    for(long long i = 2; i < MAX; i++)
        if(primes[i]){
            for(long long j = i * i; j < MAX; j += i)
                primes[j] = 0;
            all_primes.insert(i);
        }
}

int main(){
    siev();
}
