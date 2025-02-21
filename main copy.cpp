

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#include<iomanip>
#include<time.h>
#include<thread>

#define el cout<<endl


using namespace std;

#include"running_func.h"

void clear_screen();
void time_stop(int n);

int number_of_repeats = 0;
int main(){
    cout<<"Hello, welcome to the Hotel Management System.";el;//Hello, welcome to the Hotel Management System.
    cout<<"Please wait for a monent.....";//请等待
    time_stop(500);
    clear_screen();
    
    cout <<"Hotel Management System"; el;//hms Hotel Management System
    time_stop(500);
    show_first_menu();
    char first_chioce;
    cout<<"Please enter options (1/2/3)";el;
    cin>>first_chioce;
    while (1)
    {
        if(first_chioce != '1' or first_chioce != '2' or first_chioce != '3'){
            if(number_of_repeats < 3){cout<<"Wrong type! Please re-enter";el;}
            else if(number_of_repeats >= 3 and number_of_repeats < 7){cout<<"Knock it off"<< setfill('!') << setw(number_of_repeats)<<"!";el;}
            else {cout<<"Well, I'm done playing with you. Bye";el;exit(0);}
            time_stop(200);
            clear_screen();
            number_of_repeats++;
            main();
            
        }else{
            number_of_repeats=0;
            clear_screen();
            break;
        }
    }

    if(first_chioce == '1'){

    }else if(first_chioce == '2'){

    }else{
        cout<<"Goodbye!";el;
        time_stop(200);clear_screen();exit(0);
    }



    

}

void clear_screen() {
    // 清空屏幕的实现
    system("CLS"); // Windows
    // 或者：system("clear"); // Unix/Linux
}//清空屏幕

void time_stop(int n){
    this_thread::sleep_for(chrono::milliseconds(n));//改成1秒
}//时间停止



// void show_login_second_menu(){
//     cout << setfill(' ') << setw(10) << " LOGIN " << setfill(' ') << endl;
//     cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
//     cout<<"1. Customer login";el;
//     cout<<"2. User login";el;
//     cout<<"3. Return to the upper-level menu";el;
// }

// void show_register_second_menu(){
//     cout << setfill(' ') << setw(10) << " REGISTER " << setfill(' ') << endl;
//     cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
//     cout<<"1. Customer register";el;
//     cout<<"2. User register";el;
//     cout<<"3. Return to the upper-level menu";el;
// }