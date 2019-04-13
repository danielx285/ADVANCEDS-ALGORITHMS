#include <bits/stdc++.h>

//SEGMENTTREE DE PRODUTO

using namespace std;

int segtree[400000+1];

void build(int arr[] , int id,int L,int  R ){
    if ( L == R ){
        segtree[id] = arr[L];
    }

    else{ 
        int mid = (L+R)/2;
        build(arr ,2*id, L, mid);
        build(arr ,2*id + 1, mid + 1, R);

        segtree[id] = segtree[2*id] * segtree[2*id+1];
    } 
}

void update(int id, int L, int R, int  valor, int index){
    if(R == L){
        segtree[id] = valor;
    }
    
    
    else{
        int mid = (R  + L)/2 ;
        
        if (index <= mid){
            update(id * 2, L, mid, valor, index);
        }        

        else {
            update(id * 2 + 1, mid + 1, R, valor, index);
        }



        segtree[id] = segtree[2 * id] * segtree[2 * id +1];
    }
}

int query(int id, int L, int R, int x, int y){
    if (x <= L && R <= y){
        return segtree[id];
    }

    else if (  y < L || R < x){
        return 1; 
    }

    else{
        int mid = (L + R)/2;
        
        return query(id * 2, L, mid, x, y) * query(id * 2 + 1, mid + 1, R, x, y);
    }
}

int main(){
    int n, x, y, pos, value;
    
    cin >> n;
    int array[n];
    
    for(int k = 0; k < n; k++){
        cin >> array[k];
    }
    build(array, 1, 1, n);
    
    cin >> pos >> value;
    update(1, 1, n, value, pos);
    
    cin >> x >> y;
    query(1, 1, n, x, y);
    
    return 0;
}
