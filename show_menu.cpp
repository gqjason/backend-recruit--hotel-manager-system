#include <iostream>
#include <iomanip>
using namespace std;
#define el cout<<endl
using namespace std;

void show_first_menu(){
    //cout << setw(10) << left << "选项" << setw(20) << left << "描述" << endl;
    cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
    cout<<"1. Login";el;//登录
    cout<<"2. Register";el;//注册
    cout<<"3. Exit";el;//退出
    cout<<"4. Return to the upper-level menu";el;//返回上一级

}

void show_login_second_menu(){
    cout << setfill(' ') << setw(10) << " LOGIN " << setfill(' ') << endl;
    cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
    cout<<"1. Customer login";el;
    cout<<"2. User login";el;
    cout<<"3. Return to the upper-level menu";el;
    cout<<"Please enter options (1/2/3)";el;
}

void show_register_second_menu(){
    cout << setfill(' ') << setw(10) << " REGISTER " << setfill(' ') << endl;
    cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
    cout<<"1. Customer register";el;
    cout<<"2. User register";el;
    cout<<"3. Return to the upper-level menu";el;
    cout<<"Please enter options (1/2/3)";el;
}