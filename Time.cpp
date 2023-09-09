//Đề bài: Xây dựng lớp Thời gian (Time):
//Thuộc tính:
//-	Giờ (hour): một số nguyên từ 0 đến 23 (24 giờ).
//-	Phút (minute): một số nguyên từ 0 đến 59.
//-	Giây (second): một số nguyên từ 0 đến 59.
//Phương thức:
//- Hàm khởi tạo (constructor) để tạo một đối tượng Thời gian với các giá trị mặc định là 00:00:00
// (00 giờ, 00 phút, 00 giây) hoặc với các giá trị tùy chỉnh được cung cấp.
//-	Hàm hiển thị thời gian dưới dạng chuỗi có định dạng "HH:MM:SS" (ví dụ: "09:30:45").
//-	Hàm cập nhật thời gian bằng cách cộng thêm một số giờ, phút, và giây được cung cấp.
//-	Hàm kiểm tra xem một đối tượng Thời gian có phải là thời gian hợp lệ hay không (ví dụ: 25:70:15 không hợp lệ).


#include<iostream>
#include<cstdio>

class Time{
private:
    int hour;
    int minute;
    int second;
public:
    Time(int inputHour, int inputMinute, int inputSecond){
        hour = inputHour;
        minute = inputMinute;
        second = inputSecond;
    }
    void Display() const {
        std::string strhour,strminute,strsecond;
        if(hour<10){
            strhour = "0"+ std::to_string(hour);
        }
        else strhour = std::to_string(hour);
        if(minute<10){
            strminute = "0"+ std::to_string(minute);
        }
        else strminute = std::to_string(minute);
        if(second<10){
            strsecond = "0"+ std::to_string(second);
        }
        else strsecond = std::to_string(second);
        std::cout << strhour << ":" << strminute << ":" << strsecond;
    }
    void UpdateTime(Time &anotherTime) {
        int hint = 0;
        hour += anotherTime.hour;
        minute += anotherTime.minute;
        second += anotherTime.second;
        if(second>=60){
            hint = second/60;
            second %= 60;
            minute += hint;
        }
        if(minute>=60){
            hint = minute/60;
            minute %= 60;
            hour += hint;
        }
        if(hour>=24){
            hour %= 24;
        }
    }
    std::string TimeAvablabel() const{
        if(hour>24||minute>60||second>60||hour<0||minute<0||second<0) return "false";
        return "true";
    }
};

signed main(){
    int h,m,s;

    std::cout << "\nNhap vao gia tri thoi gian gio theo dinh dang gio:phut:giay = ";
    scanf("%d:%d:%d",&h,&m,&s);
    Time firstTime(h,m,s);
    std::cout << "\nThoi gian ban dau: ";
    firstTime.Display();

    std::cout << "\nNhap vao gia tri thoi gian da troi qua theo dinh dang gio:phut:giay = ";
    scanf("%d:%d:%d",&h,&m,&s);
    Time secondTime(h,m,s);
    firstTime.UpdateTime(secondTime);
    std::cout << "\nThoi gian hien tai: ";
    firstTime.Display();

    Time exampleCheckTime(25,14,14);
    std::cout << "\nKiem tra dung dinh dang : " << exampleCheckTime.TimeAvablabel();
}