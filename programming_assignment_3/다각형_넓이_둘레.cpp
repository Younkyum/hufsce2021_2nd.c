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
    void setXY(int x, int y) { // ���� ��ǥ ����
        this->x = x;
        this->y = y;
    }
};

int ccw(Point p, Point q, Point r); // �� ������ �̷���� �ﰢ�� ���� ���ϴ� �Լ�

class Polygon {
private:
    int n;
    Point *points; // �����Ҵ�
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
        delete[] points; // �Ҹ��ڸ� �̿��� ���� �Ҵ� delete
    }
    void addPoint(Point p, int index) {
        points[index] = p;
    }
    int round() {
        float sum = 0;
        int sumx = 0, sumy = 0;
        for (int i = 0; i < n; i++) {
            sumx = (points[i%(n)].getX() - points[(i+1)%(n)].getX()) * (points[i%(n)].getX() - points[(i+1)%(n)].getX()); // ���� �� ������ �Ÿ� �̿�
            sumy = (points[i%(n)].getY() - points[(i+1)%(n)].getY()) * (points[i%(n)].getY() - points[(i+1)%(n)].getY());
            sum += pow(sumx + sumy, 0.5); // sum�� ����
        }
        return sum + 0.5;
    }
    int area() {
        float sum = 0;
        for (int i = 1; i < n-1; i++) {
            sum = sum + ccw(points[0], points[i], points[i+1]); // �ٰ����� �������� �ﰢ������ ����� ����
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
    sumy = (qx * py) + (rx * qy) + (px * ry); // �Ź߲� ������ ����Ͽ� ���̸� ����
    return sumx - sumy;
}

int main() {
    int n;
    int x, y;
    Point p;
    cin >> n;
    Polygon plz(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y; // �� �Է�
        p.setXY(x, y);
        plz.addPoint(p, i);
    }
    cout << plz.round() << "\n" << plz.area() << endl; // ���
}

