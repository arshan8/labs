#include <iostream>
using namespace std;

int isleap(int n) {
    if (n % 4 == 0) {
        return 1;
    } else {
        return 0;
    }
}

class date {
    int d, m, y;
    int monthdays1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
    date() {
        d = 0;
        m = 0;
        y = 0;
    }
    void getdata();
    void show();
    date operator+(int n);
    int operator-(date d1);
    int dayscalculator();
};

void date::getdata() {
    cout << "enter day" << endl;
    cin >> d;
    cout << "enter month" << endl;
    cin >> m;
    cout << "enter year" << endl;
    cin >> y;
    if (d > 31 || m > 12) {
        cout << "CAUTION: INVALID DATE ";
    }
}

void date::show() {
    if (d > 31 || m > 12) {
        cout << "INVALID DATE";
    } else {
        cout << "date: " << d << "/" << m << "/" << y << endl;
    }
}

date date::operator+(int n) {
    date newdate;
    newdate.y = this->y;
    newdate.d = this->d;
    newdate.m = this->m;
    int monthday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    while (n > 0) {
        if (isleap(newdate.y)) {
            monthday[1] = 29;
        } else {
            monthday[1] = 28;
        }
        if (newdate.d + n > monthday[newdate.m - 1]) {
            int daysadded = monthday[newdate.m - 1] - newdate.d + 1;
            newdate.d = 1;
            newdate.m++;
            if (newdate.m > 12) {
                newdate.m = 1;
                newdate.y++;
            }
            n -= daysadded;
        } else {
            newdate.d += n;
            n = 0;
        }
    }
    return newdate;
}

int date::dayscalculator() {
    int daysmonths = 0;
    for (int i = 0; i < m-1 ; i++) {
        daysmonths += monthdays1[i];
    }
    int daysyear = 0;
    for (int i = 1; i < y; i++) {
        if (isleap(i)) {
            daysyear += 366;
        } else {
            daysyear += 365;
        }
    }
    return d + daysyear + daysmonths;
}

int date::operator-(date d2) {
    int total;
    total = this->dayscalculator() - d2.dayscalculator();
    return total;
}

int main() {
    date d1;
    date d2;
    cout<<"date_1 :"<<endl;
    d1.getdata();
    d1.show();
    cout<<"date_2 :"<<endl;
    d2.getdata();
    d2.show();
    int num;
    cout << "How many days do you want to add: " << endl;
    cin >> num;
    d1 = d1 + num;
    d1.show();
    cout<<"difference between date_1 and date_2"<<d2-d1;
    return 0;
}