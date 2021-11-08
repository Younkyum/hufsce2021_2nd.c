#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    void setX() {
        this->x = x;
    }
    void setY() {
        this->y = y;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    void setXY(int x, int y) { // 점의 좌표 설정
        this->x = x;
        this->y = y;
    }
};

int ccw(Point p, Point q, Point r); // 세 점으로 이루어진 삼각형 넓이 구하는 함수

class Polygon {
private:
    int n;
    Point *points; // 동적할당
public:
    Polygon() {
        n = 3;
        Point *points = new Point[3];
    }
    Polygon(int n) {
        this -> n = n;
				points = new Point[n];
    }
    ~Polygon() {
        delete[] points; // 소멸자를 이용한 동적 할당 delete
    }
    void addPoint(Point p, int index) {
        points[index] = p;
    }
    int round() {
        float sum = 0;
        int sumx = 0, sumy = 0;
        for (int i = 0; i < n; i++) {
            sumx = (points[i%(n)].getX() - points[(i+1)%(n)].getX()) * (points[i%(n)].getX() - points[(i+1)%(n)].getX()); // 점과 점 사이의 거리 이용
            sumy = (points[i%(n)].getY() - points[(i+1)%(n)].getY()) * (points[i%(n)].getY() - points[(i+1)%(n)].getY());
            sum += pow(sumx + sumy, 0.5); // sum에 더함
        }
        return sum + 0.5;
    }
    int area() {
        float sum = 0;
        for (int i = 1; i < n-1; i++) {
            sum = sum + ccw(points[0], points[i], points[i+1]); // 다각형을 여러개의 삼각형으로 만들어 더함
        }
        if (sum < 0) sum = sum * (-1);
				sum = sum * 0.5 + 0.5;
        return sum;
    }
};

int ccw(Point p, Point q, Point r) {
    int px, py, qx, qy, rx, ry;
    int sumx, sumy;
    px = p.getX();
    py = p.getY();
    qx = q.getX();
    qy = q.getY();
    rx = r.getX();
    ry = r.getY();
    sumx = (px * qy) + (qx * ry) + (rx * py);
    sumy = (qx * py) + (rx * qy) + (px * ry); // 신발끈 공식을 사용하여 넓이를 구함
    return sumx - sumy;
}

int main() {
    int n;
    int x, y;
    Point p;
    cin >> n;
    Polygon plz(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y; // 점 입력
        p.setXY(x, y);
        plz.addPoint(p, i);
    }
    cout << plz.round() << "\n" << plz.area() << endl; // 출력
}

