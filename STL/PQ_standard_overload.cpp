#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x, y;
    Point(int a = 0, int b = 0): x(a), y(b) {}
};


struct cmp {
    bool operator() (const Point& a, const Point& b) const {
        if(a.x != b.x) return a.x > b.x;
        return a.y > b.y;
    }
};

priority_queue<Point, vector<Point>, cmp> pq;
priority_queue<int, vector<int>, greater<int> > intpq;
int main() {
    pq.push(Point(1, 5));
    pq.push(Point(1, 2));
    pq.push(Point(2, 2));
    pq.push(Point(2, 1));
    while(!pq.empty()) {
        Point temp = pq.top();
      //  cout << temp.x << " " << temp.y << " " << endl;
        pq.pop();
    }
    for(int i = 0; i < 5; i++) {
        intpq.push(i);
    }
    while(!intpq.empty()) {
        cout << intpq.top() << endl;
        intpq.pop();
    }
}
