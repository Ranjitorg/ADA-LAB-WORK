#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;
};

int calculateArea(const Point& a, const Point& b, const Point& c) {
    return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

bool pointLiesInsideTriangle(const Point& a, const Point& b, const Point& c, const Point& p) {
    int areaABC = calculateArea(a, b, c);
    int areaPAB = calculateArea(a, b, p);
    int areaPBC = calculateArea(b, c, p);
    int areaPCA = calculateArea(c, a, p);
    
    return (areaABC == (areaPAB + areaPBC + areaPCA));
}

void findConvexHull(const vector<Point>& points, vector<bool>& isInsideHull) {
    int n = points.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                
                if (calculateArea(points[i], points[j], points[k]) == 0)
                    continue;
                    
                for (int p = 0; p < n; p++) {
                    if (p == i || p == j || p == k)
                        continue;

                    if (pointLiesInsideTriangle(points[i], points[j], points[k], points[p])) {
                        isInsideHull[p] = true;
                    }
                }
            }
        }
    }
}

void displayConvexHull(const vector<Point>& points, const vector<bool>& isInsideHull) {
    cout << "Convex hull points:" << endl;
    for (int i = 0; i < points.size(); i++) {
        if (!isInsideHull[i]) {
            cout << "(" << points[i].x << "," << points[i].y << ") ";
        }
    }
    cout << endl;
}

int main() {
    vector<Point> points = {
        {1, 4}, {4, 2}, {2, 1}, {5, 1}, {6, 0}, {0, 0}, {5, 5}
    };
    
    int n = points.size();
    vector<bool> isInsideHull(n, false);
    
    findConvexHull(points, isInsideHull);
    displayConvexHull(points, isInsideHull);
    
    return 0;
}
