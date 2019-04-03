#include <bits/stdc++.h>

using namespace std;

int BIT[100002];

void update(int id,int valor){
    for(int i = id; i < 100002; i += (i & -i)){
        BIT[i] += valor;
    }
}

int query(int id){
    int ret = 0;
    for(int i = id; i > 0; i -= (i & -i)){
        ret += BIT[i];
    }

    return ret;
}

int main(){
    memset(BIT, 0, sizeof(BIT));
    return 0;
}
