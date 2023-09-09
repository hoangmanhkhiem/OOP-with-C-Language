//Đề bài: Xây dựng lớp biểu diễn Ngày Tháng (Date):
//Thuộc tính:
//-	Ngày (day): một số nguyên từ 1 đến 31 (tuỳ thuộc vào tháng).
//-	Tháng (month): một số nguyên từ 1 đến 12.
//-	Năm (year): một số nguyên (ví dụ: 2023).
//Phương thức:
//-	Hàm khởi tạo (constructor) để tạo một đối tượng Ngày Tháng với các giá trị mặc định là 01/01/1900
// hoặc với các giá trị tùy chỉnh được cung cấp.
//-	Hàm hiển thị ngày tháng dưới dạng chuỗi có định dạng "DD/MM/YYYY" (ví dụ: "06/09/2023").
//-	Hàm kiểm tra xem một đối tượng Ngày Tháng có phải là ngày tháng hợp lệ hay không (ví dụ: 30/02/2023 không hợp lệ).
//-	Hàm cập nhật ngày tháng bằng cách cộng thêm một số ngày, tháng, và năm được cung cấp.
//-	Hàm tính khoảng cách giữa hai đối tượng Ngày Tháng và trả về số ngày giứa 2 ngày đó.
//-	Hàm kiểm tra xem một năm có phải là năm nhuận hay không (tuỳ theo quy tắc năm nhuận).


#include<iostream>
#include<cstdio>

class Date{
private:
    int day;
    int month;
    int year;
public:
    explicit Date(int dayInput = 1,int monthInput = 1,int yearInput = 1900) {
        day = dayInput;
        month = monthInput;
        year = yearInput;
    }
    void Display() const {
        std::string strday,strmonth,stryear;
        if(day<10){
            strday = "0"+ std::to_string(day);
        }
        else strday = std::to_string(day);
        if(month<10){
            strmonth = "0"+ std::to_string(month);
        }
        else strmonth = std::to_string(month);
        if(year<1000){
            stryear = "0"+ std::to_string(year);
        }
        else stryear = std::to_string(year);
        std::cout << strday << ":" << strmonth << ":" << stryear;
    }
    bool checkDateinLeapyear() {
        if (year % 100 == 0){
            if (year % 400 == 0) return true;
            else return false;
        }
        else if (year % 4 == 0) return true;
        else return false;
    }
    bool checkDateAvalabel(){
        if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(day>31||day<=0)) return false;
        if((month==4||month==6||month==9||month==11)
        &&(day>30||day<=0)) return false;
        if(checkDateinLeapyear()){
            if(month==2&&(day<=0||day>29)) return false;
        }
        else  if(month==2&&(day<=0||day>28)) return false;
        return true;
    }
    int CaculateDays(){
        int totalDays = 0;
        totalDays += day;
        totalDays += year*365 + year/4;
        switch (month) {
            case 1:
                return totalDays;
            case 2:
                totalDays += 31;
                return totalDays;
            case 3:
                if(checkDateinLeapyear()) totalDays += 29+31;
                else totalDays += 28+31;
                return totalDays;
            case 4:
                if(checkDateinLeapyear()) totalDays += 29+31+31;
                else totalDays += 28+31+31;
                return totalDays;
            case 5:
                if(checkDateinLeapyear()) totalDays += 29+31+31+30;
                else totalDays += 28+31+31+30;
                return totalDays;
            case 6:
                if(checkDateinLeapyear()) totalDays += 29+31+31+30+31;
                else totalDays += 28+31+31+30+31;
                return totalDays;
            case 7:
                if(checkDateinLeapyear()) totalDays += 29+31+31+30+31+30;
                else totalDays += 28+31+31+30+31+30;
                return totalDays;
            case 8:
                if(checkDateinLeapyear()) totalDays += 29+31+31+30+31+30+31;
                else totalDays += 28+31+31+30+31+30+31;
                return totalDays;
            case 9:
                if(checkDateinLeapyear()) totalDays += 29+31+31+30+31+30+31+31;
                else totalDays += 28+31+31+30+31+30+31+31;
                return totalDays;
            case 10:
                if(checkDateinLeapyear()) totalDays += 29+31+31+30+31+30+31+31+30;
                else totalDays += 28+31+31+30+31+30+31+31+30;
                return totalDays;
            case 11:
                if(checkDateinLeapyear()) totalDays += 29+31+31+30+31+30+31+31+30+31;
                else totalDays += 28+31+31+30+31+30+31+31+30+31;
                return totalDays;
            case 12:
                if(checkDateinLeapyear()) totalDays += 29+31+31+30+31+30+31+31+30+31+30;
                else totalDays += 28+31+31+30+31+30+31+31+30+31+30;
                return totalDays;
        }
    }
    void UpdateDate(Date &anotherDate){

    }
    int Difference(Date &anotherDate){
        return abs(CaculateDays()-anotherDate.CaculateDays());
    }
};

signed main(){
    int d,m,y;
    std::cout << "Nhap vao ngay theo dinh dang DD/MM/YYYY: ";
    scanf("%d/%d/%d",&d,&m,&y);
    Date FirstDate;
    FirstDate.Display();
}
