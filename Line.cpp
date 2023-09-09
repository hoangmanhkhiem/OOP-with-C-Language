//Đề bài: Xây dựng lớp Đoạn thẳng (Line):
//Thuộc tính:
//-	Điểm bắt đầu (start point) của đoạn thẳng (có thể là một đối tượng Point).
//-	Điểm kết thúc (end point) của đoạn thẳng (có thể là một đối tượng Point).
//Phương thức:
//-	Hàm khởi tạo để tạo một đoạn thẳng bằng cách chỉ định điểm bắt đầu và điểm kết thúc.
//-	Hàm tính độ dài của đoạn thẳng.
//-	Hàm kiểm tra xem một điểm có thuộc đoạn thẳng hay không.
//-	Hàm hiển thị thông tin về đoạn thẳng, bao gồm điểm bắt đầu và điểm kết thúc.


#include<iostream>
#include<cmath>

class Point {
private:
    double x;
    double y;

public:
    Point(double x, double y) : x(x), y(y) {}
    double getX() const { return x; }
    double getY() const { return y; }
};

class Line{
private:
    Point start;
    Point end;
public:
    Line(const Point& startPoint,const Point& endPoint) : start(startPoint), end(endPoint){}
    double LenghtLine(){
        double dis = sqrt(std::pow(start.getX()-end.getX(),2)+std::pow(start.getY()-end.getY(),2));
        return dis;
    }
    double Distance(Point num1, Point num2){
        double dis = sqrt(std::pow(num1.getX()-num2.getX(),2)+std::pow(num1.getY()-num2.getY(),2));
        return dis;
    }
    std::string CheckotherPointinLine(const Point &otherPoint){
        double line1, line2;
        line1 = Distance(start,otherPoint);
        line2 = Distance(end, otherPoint);
        if(line1+line2==LenghtLine()) return "true";
        else return "false";
    }
    void Display(){
        std::cout << "\nThong tin ve doan thang nhu sau :";
        std::cout << "\nDiem bat dau doan thang (x,y) = (" << start.getX() << "," << start.getY() << ")";
        std::cout << "\nDiem ket thuc doan thang (x,y) = (" << end.getX() << "," << end.getY() << ")";
        std::cout << "\nDo dai cua doan thang S = " << LenghtLine()<< "\n";
    }
};

signed main(){
    double X,Y;
    std::cout << "Nhap toa do x va y cua diem bat dau: ";
    std::cin >> X >> Y;
    Point start(X,Y);
    std::cout << "\nNhap toa do x va y cua diem ket thuc: ";
    std::cin >> X >> Y;
    Point end(X,Y);
    Line LineEx(start, end);
    std::cout << "\nNhap toa do x va y cua diem can kiem tra: ";
    std::cin >> X >> Y;
    Point check(X,Y);
    std::cout << "\nKet qua kiem tra : " << LineEx.CheckotherPointinLine(check);
    LineEx.Display();
}
