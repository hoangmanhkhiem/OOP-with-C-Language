//Đề bài: Xây dựng lớp Điểm (Point), với:
//Thuộc tính:
//-	Tọa độ x (x-coordinate) của điểm.
//-	Tọa độ y (y-coordinate) của điểm.
//Phương thức:
//-	Hàm khởi tạo (constructor) để tạo một điểm với tọa độ x và y.
//-	Hàm tính khoảng cách từ điểm này đến một điểm khác trong mặt phẳng (có thể là một đối tượng Point khác).
//-	Hàm hiển thị tọa độ của điểm.

#include <iostream>
#include <cmath>
#include<time.h>

class Point {
private:
    double x;
    double y;

public:
    Point(double xCoordinate, double yCoordinate) {
        x = xCoordinate;
        y = yCoordinate;
    }

    void Distance(const Point& otherPoint) {
        double dx = x - otherPoint.x;
        double dy = y - otherPoint.y;
        double dis =  sqrt(dx * dx + dy * dy);
        std::cout << "Khoang cach giua 2 diem (" << x << ", " << y << ") va "
        "(" << otherPoint.x << ", " << otherPoint.y << ") la: " << dis << std::endl;
    }

    void Display() {
        std::cout << "Toa do cua diem : (" << x << ", " << y << ")" << std::endl;
    }
};

signed main(){
    double X,Y;
    std::cout << "Nhap toa do x va y cua diem thu 1: ";
    std::cin >> X >> Y;
    Point Point1(X,Y);
    Point1.Display();
    std::cout << "Nhap toa do x va y cua diem thu 2: ";
    std::cin >> X >> Y;
    Point Point2(X,Y);
    Point2.Display();
    Point1.Distance(Point2);
}