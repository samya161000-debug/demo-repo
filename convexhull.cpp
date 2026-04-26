#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

// Global reference point
Point p0;

// Function to find orientation
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;       // collinear
    return (val > 0) ? 1 : 2;     // 1 = clockwise, 2 = counterclockwise
}

// Distance squared
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) +
           (p1.y - p2.y)*(p1.y - p2.y);
}

// Comparator for sorting
bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);

    if (o == 0)
        return distSq(p0, p1) < distSq(p0, p2);

    return (o == 2);
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();

    // Step 1: Find bottom-most point
    int ymin = points[0].y, min_i = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < ymin) ||
           (points[i].y == ymin && points[i].x < points[min_i].x)) {
            ymin = points[i].y;
            min_i = i;
        }
    }

    swap(points[0], points[min_i]);
    p0 = points[0];

    // Step 2: Sort by polar angle
    sort(points.begin() + 1, points.end(), compare);

    // Step 3: Build hull using stack
    stack<Point> st;
    st.push(points[0]);
    st.push(points[1]);
    st.push(points[2]);

    for (int i = 3; i < n; i++) {
        while (st.size() > 1) {
            Point top = st.top(); st.pop();
            Point nextToTop = st.top();

            if (orientation(nextToTop, top, points[i]) != 2)
                continue;
            else {
                st.push(top);
                break;
            }
        }
        st.push(points[i]);
    }

    // Store result
    vector<Point> hull;
    while (!st.empty()) {
        hull.push_back(st.top());
        st.pop();
    }

    return hull;
}

int main() {
    vector<Point> points = {
        {0, 3}, {2, 2}, {1, 1},
        {2, 1}, {3, 0}, {0, 0},
        {3, 3}
    };

    vector<Point> hull = convexHull(points);

    cout << "Convex Hull points:\n";
    for (auto p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}