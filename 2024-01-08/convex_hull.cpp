#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

bool comparePoints(const Point& a, const Point& b) {
    return (a.y != b.y) ? (a.y < b.y) : (a.x < b.x);
}

long long ccw(const Point& a, const Point& b, const Point& c) {
    return 1LL * ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}

bool leftTurn(const Point& a, const Point& b, const Point& c) {
    return ccw(a, b, c) > 0;
}

void quickSortByAngle(vector<Point>& points) {
    sort(points.begin() + 1, points.end(), comparePoints);
}

int convexHull(vector<Point>& points) {
    int n = points.size();
    if (n <= 2) return n;

    int minIdx = min_element(points.begin(), points.end(), comparePoints) - points.begin();
    swap(points[0], points[minIdx]);

    quickSortByAngle(points);

    vector<int> hull;
    hull.push_back(0);
    hull.push_back(1);

    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2) {
            int second = hull.back();
            int first = hull[hull.size() - 2];

            if (leftTurn(points[first], points[second], points[i])) {
                break;
            }

            hull.pop_back();
        }

        hull.push_back(i);
    }

    return hull.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    int result = convexHull(points);
    cout << result << '\n';

    return 0;
}
