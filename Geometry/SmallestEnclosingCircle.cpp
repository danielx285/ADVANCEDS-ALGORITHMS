#include <bits/stdc++.h>
#define EPS 1e-9
#define pi 3.14

using namespace std;

struct pt{
    double x, y;
    pt(){}
    pt(double _x, double _y) : x(_x), y(_y) {}

    pt operator +(const pt& p){return pt(x + p.x, y + p.y);}
    pt operator -(const pt& p){return pt(x - p.x, y -p.y);}
    pt operator *(const double c){return pt(x * c, y * c);}
    //Dist
    double operator %(const pt& p){return hypot(x - p.x, y - p.y);}
    //Cross product
    double operator ^(const pt& p){return x*p.y - y*p.x;}
};

struct circle{
    pt c; // center
    double r; //radius
    circle(){c = pt(), r = 0;}
    circle(pt _c, double _r) : c(_c), r(_r){}
    double area(){return pi*r*r;} // default is acos(-1.0) for pi
    bool contains(pt p){return c%p <= r + EPS;}
};

circle circumcircle(pt a, pt b, pt c){
    circle ans;
    pt u = pt((b-a).y, -(b-a).x);
    pt v = pt((c-a).y, -(c-a).x);
    pt n = (c-b)*0.5;
    double t = (u^n)/(v^u);
    ans.c = ((a+c)*0.5) + (v*t);
    ans.r = ans.c%a;
    return ans;
}

circle minimunCircle(vector<pt> pts){
    random_shuffle(pts.begin(), pts.end());
   
    circle C = circle(pts[0], 0);

    for(int i = 0; i < pts.size(); i++){
        if(C.contains(pts[i])) 
            continue ;
        
        C = circle(pts[i], 0);

        for(int j = 0; j < i; j++){
            if(C.contains(pts[j])) 
                continue;
        
            C = circle((pts[j] + pts[i])*0.5, 0.5*(pts[j]%pts[i]));
            
            for(int k = 0; k < j; k++){
                if(C.contains(pts[k])) 
                    continue ;

                C = circumcircle(pts[j], pts[i], pts[k]);
            }
        }

    }

    return C;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(2);

    int n;
    cin >> n;
    vector<pt> pts;
    for(int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        pts.push_back(pt(x, y));
    }

    circle C = minimunCircle(pts);
    cout << C.c.x << " " << C.c.y << " " << C.r << " " << C.r*8*pi << endl;
}