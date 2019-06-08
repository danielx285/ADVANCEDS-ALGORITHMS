#include <bits/stdc++.h>
#define indef 54556543
#define null -1256.1548

using namespace std ;

struct point{
    double x, y;
    point(){}
    point(double x, double y){
        this->x = x;
        this->y = y;
    }
    double cofA(point scd){
        double dx, dy;
        dx = (scd.x - this->x);
        dy = (scd.y - this->y);
        if(dx == 0)
            return indef;
        else if (dy == 0)
            return 0;
        else
            return dy/dx;
    }
    point ptMedio(point scd){
        point ptMedio = point((this->x + scd.x)/2,(this->y + scd.y)/2);
        return ptMedio;
    }
};

double sistema(double a1, double b1, double a2, double b2){
    if( a1 > a2){
        return  (b1 - b2)/- (a1 - a2) ;
    }
    else{
        return (b2 - b1) / - (a2 - a1) ;
    }
}

struct reta{
    double a;
    double b;
    double x;
    reta(){}
    reta(double coef, point A){
        this->a = coef;
        this->b = A.y - coef * A.x;
        this->x = null;
        if(coef == indef){
            this->x = A.x;
        }
    }
    point comunPoint(reta concorrente){
        if(concorrente.x != null){
            return point( concorrente.x, yValue(concorrente.x)  );
        }
        if(this->x != null){
            return point(this->x, concorrente.yValue(this->x) );
        }
        double x = sistema(this->a, this->b, concorrente.a, concorrente.b);

        return point(x, yValue(x));
    }
    double yValue(double x){
        return this->a * x + this->b;
    }
};

int main(){
    double a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    point A = point(a, b);
    point B = point(c, d);
    point C = point(e, f);
    point D = point(g, h);

    reta r = reta(A.cofA(B), A);
    reta s = reta(C.cofA(D), C);
    point pComun =  r.comunPoint(s) ;

    cout << pComun.x << " " << pComun.y ;
}
