#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define EPS 1e-8

// https://github.com/rhs0266/PS_library/blob/master/geometry/convexhull.rhs
typedef struct Point {
    ll x, y;
    double angle;
    ll dis;
    
    Point(ll _x, ll _y): x(_x), y(_y) {}
    
    bool operator<(const Point &p) {
        // if angle is identical, use closer point first
        if ( -EPS < angle - p.angle && angle - p.angle < EPS ) return dis < p.dis;
        return angle < p.angle;
    }
    
} Point;

bool cmpy(Point a, Point b) {
    if (a.y == b.y) return a.x > b.x;
    return a.y < b.y;
}

typedef struct ConvexHull {
    
    vector<Point> points;
    int size;
    
    ConvexHull() {}
    ConvexHull(vector<Point> p) {
        points = p;
        size = points.size();
    }
    
    int ccw(Point a, Point b, Point c) {
        // outer product
        ll op = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        if (op > 0) return 1;
        else if (op < 0) return -1;
        else return 0;
    }
    
    vector<Point> gscan() {
        // start with the point with smallest y coord
        sort(points.begin(), points.end(), cmpy);
        points[0].angle = -10000;
        
        for(int i = 1; i < size; i++) {
			points[i].angle = atan2(points[i].y - points[0].y, points[i].x - points[0].x);
			points[i].dis = (points[i].y - points[0].y) * (points[i].y - points[0].y) +
                            (points[i].x - points[0].x) * (points[i].x - points[0].x);
        }
        
        // sort again with angle
        sort(points.begin(), points.end());
        
        vector<Point> stk;
        stk.push_back(points[0]);
        stk.push_back(points[1]);
        for (int i = 2; i < size; i++) {
            while (stk.size() > 1) {
                int sz = stk.size();
                int angle = ccw(stk[sz - 2], stk[sz - 1], points[i]);
                
                // pop until angle is negative
                if (angle <= 0) {
                    stk.pop_back();
                } else {
                    break;
                }
            }
            stk.push_back(points[i]);
        }
        
        return stk; 
    }
    
} ConvexHull;

// https://www.acmicpc.net/problem/1708
int main(){
    int n;
    cin >> n;
    
    vector<Point> v;
    for(int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        Point p = Point(a, b);
        v.push_back(p);
    }
    
    ConvexHull ch(v);
    
    vector<Point> points = ch.gscan();
//    for(int i = 0; i < points.size(); i++) {
//        cout << points[i].x << ' ' << points[i].y << endl;
//    }
    cout << points.size() << endl;
}
