#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
#include<time.h>
#include<thread>
#include<chrono>
#include<io.h>
#include<direct.h> 
#define el cout<<endl

using namespace std;



class running_func{
public:
    void clear_screen() {
        // 清空屏幕的实现
        system("CLS"); // Windows
        // 或者：system("clear"); // Unix/Linux
    }//清空屏幕

    void time_stop(int n){
        this_thread::sleep_for(chrono::milliseconds(n));//改成1秒
    }//时间停止

    void file_open_unsuccess(){
        cout << "Failed to open the file.\nPlease contact the administrator to solve the problem" << endl;
        time_stop(200);
        cout<<"The program will exit.\nGoodbye";el;
        time_stop(20000);
        clear_screen();
        exit(0);
    }

    void power_on(){
        cout<<"Hello, welcome to the Hotel Management System.";el;//Hello, welcome to the Hotel Management System.
        time_stop(500);
        cout<<"Please wait for a monent.....";//请等待
        time_stop(1000);
        clear_screen();

        
    }
    //主菜单
    void show_first_menu(){
        cout <<"Hotel Management System"; el;//hms Hotel Management System
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout<<"1. Login";el;//登录
        cout<<"2. Register";el;//注册
        cout<<"3. Exit";el;//退出
        cout<<"Please enter options (1/2/3)";el;
    }
    //登录菜单
    void show_login_second_menu(){
        cout << setfill(' ') << setw(10) << " LOGIN " << setfill(' ') << endl;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout<<"1. Customer login";el;
        cout<<"2. Administrator login";el;
        cout<<"3. Return to the upper-level menu";el;
        cout<<"Please enter options (1/2/3)";el;
    }
    //注册菜单
    void show_register_second_menu(){
        cout << setfill(' ') << setw(10) << " REGISTER " << setfill(' ') << endl;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout<<"1. Customer register";el;
        cout<<"2. Administrator register";el;
        cout<<"3. Return to the upper-level menu";el;
        cout<<"Please enter options (1/2/3)";el;
    }
    //管理员界面
    void show_admin_first_menu(string admin_name){
        cout<<"Welcome back, Administrator "<<admin_name<<" .";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout<<"1. ";cout<<"";el;
        cout<<"2. ";cout<<"";el;
        cout<<"3. ";cout<<"";el;
    }

    void show_customer_first_menu(string customer_name){
        cout<<"Welcome back, Administrator "<<customer_name<<" .";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout<<"1. ";cout<<"";el;
        cout<<"2. ";cout<<"";el;
        cout<<"3. ";cout<<"";el;
        cout<<"4. ";cout<<"";el;
    }

    string cut_str(string s){
        string res = "";
        for(int i=0;i < s.length() and s[i] != ' ';i++){res += s[i];}
        return res;
    }

};

class hotel_management_system : public running_func{
    public:
        running_func RF;
        string name;
        string password;
        string id;

        bool first_enter = false;
        int number_of_repeats = 0;

        
        //主菜单
        void main_menu(){
            if(first_enter == false){
                power_on();
                first_enter = true;
            }
            show_first_menu();
            char first_chioce;
            cin>>first_chioce;
            while (1)
            {
                if(first_chioce != '1' and first_chioce != '2' and first_chioce != '3'){
                    if(number_of_repeats < 3){cout<<"Wrong type! Please re-enter";el;}
                    else if(number_of_repeats >= 3 and number_of_repeats < 7){cout<<"Knock it off"<< setfill('!') << setw(number_of_repeats)<<"!";el;}
                    else {cout<<"Well, I'm done playing with you. Bye";el;exit(0);}
                    time_stop(200);
                    clear_screen();
                    number_of_repeats++;
                    main_menu();
                }else{
                    number_of_repeats=0;
                    clear_screen();
                    break;
                }
            }
            if(first_chioce == '1'){
                login_menu();
            }else if(first_chioce == '2'){
                register_menu();
            }else{
                cout<<"Goodbye!";el;
                time_stop(200);clear_screen();exit(0);
            }
        }


        //登录菜单
        void login_menu(){
            RF.show_login_second_menu();
            char login_choice;
            cin>>login_choice;

            if(login_choice == '1'){
                number_of_repeats=0;
                entry_of_login_information("customer");
            }else if(login_choice == '2'){
                number_of_repeats=0;
                entry_of_login_information("administrator");
            }else if(login_choice == '3'){
                number_of_repeats=0;
                clear_screen();
                main_menu();
            }else{
                if(number_of_repeats < 3){cout<<"Wrong type! Please re-enter";el;}
                    else if(number_of_repeats >= 3 and number_of_repeats < 7){cout<<"Knock it off"<< setfill('!') << setw(number_of_repeats)<<"!";el;}
                    else {cout<<"Well, I'm done playing with you. Bye";el;exit(0);}
                    time_stop(200);
                    clear_screen();
                    number_of_repeats++;
                    login_menu();
            }
        }

        //登录信息输入菜单
        void entry_of_login_information(string login_standing){
            cout<<login_standing<<" login";el;
            cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
            cout<<"Please enter your name: ";cin>>name;el;
            cout<<"Please enter your password: ";cin>>password;el;
            cout<<"Confirm or Re-enter? (C/R)";el;
            char reenter_choice;
            cin>>reenter_choice;
            
            bool confirm_success = false;
            if(reenter_choice == 'R' or reenter_choice == 'r'){
                clear_screen();
                entry_of_login_information(login_standing);
            }else if (reenter_choice == 'C' or reenter_choice == 'c'){
                clear_screen();
                cout<<"Please wait for a moment.....";el;
                confirm_success = confirm_login_information(login_standing);
            }else{
                clear_screen();
                cout<<"Wrong type!\nWill return to the login interface.";el;
                time_stop(200);
                login_menu();
            }

            if(confirm_success){
                cout<<"Login successful!";el;
                time_stop(200);
                clear_screen();
            }else{
                time_stop(200);
                clear_screen();
                entry_of_login_information(login_standing);
            }
        }

        //登录核对信息
        bool confirm_login_information(string standing){
            string filename =  "./information/" + standing + ".txt.txt";//"E:\\PCJ database\\my repository\\Back-end assessment\\hotel manager system\\information\\" +
            fstream file;
            file.open(filename, ios::in);
            if (!file.is_open()) {clear_screen();file_open_unsuccess();}

            string stored_name, stored_password;
            bool found = false;
            while (file >> stored_name >> stored_password) {
                if (stored_name == name && stored_password == password) {
                    found = true;
                    break;
                }
            }
            file.close();

            if (found) {
                return true;
            } else {
                cout << "Invalid name or password. Please try again." << endl;
                return false;
            }
        }






        //注册菜单
        void register_menu(){
            RF.show_register_second_menu();
            char register_choice;
            cin>>register_choice;

            if(register_choice == '1'){
                number_of_repeats=0;
                entry_of_register_information("customer");
            }else if(register_choice == '2'){
                number_of_repeats=0;
                entry_of_register_information("administrator");
            }else if(register_choice == '3'){
                number_of_repeats=0;
                clear_screen();
                main_menu();
            }else{
                if(number_of_repeats < 3){cout<<"Wrong type! Please re-enter";el;}
                    else if(number_of_repeats >= 3 and number_of_repeats < 7){cout<<"Knock it off"<< setfill('!') << setw(number_of_repeats)<<"!";el;}
                    else {cout<<"Well, I'm done playing with you. Bye";el;exit(0);}
                    time_stop(200);
                    clear_screen();
                    number_of_repeats++;
                    login_menu();
            }
           
        }

        //注册信息输入菜单
        void entry_of_register_information(string register_standing){
            cout<<register_standing<<" register";el;
            cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
            cout<<"Please enter your name: ";cin>>name;el;
            cout<<"Please enter your password: ";cin>>password;el;
            cout<<"Confirm or Re-enter? (C/R)";el;
            char reenter_choice;
            cin>>reenter_choice;

            //输入判断
            bool register_success = false;
            if(reenter_choice == 'R' or reenter_choice == 'r'){
                clear_screen();
                time_stop(100);
                entry_of_login_information(register_standing);
            }else if (reenter_choice == 'C' or reenter_choice == 'c'){
                clear_screen();
                cout<<"Please wait for a moment.....";el;
                register_success = confirm_register_information(register_standing);
            }else{
                cout<<"Wrong type!\nWill return to the register interface.";el;
                time_stop(200);
                clear_screen();
                register_menu();
            }

            //注册是否成功
            if(register_success == false){entry_of_register_information(register_standing);}
            else{
                cout<<"Return to the corresponding login interface after 2 seconds......";el;
                time_stop(2000);
                clear_screen();
                entry_of_login_information(register_standing);
            }
        }

        //注册信息核对
        bool confirm_register_information(string standing){
            //打开文件夹
            string filename = "./information/"+ standing + ".txt.txt";//"E:\\PCJ database\\my repository\\Back-end assessment\\hotel manager system\\information\\" + 
            //administrator.txt
            //E:\PCJ database\my repository\Back-end assessment\hotel manager system\administrator.txt
            fstream file;
            file.open(filename, ios::in);
            if (!file.is_open()) {clear_screen();file_open_unsuccess();}

            //查找信息
            string stored_name, stored_password;
            bool found = true;
            while (file >> stored_name >> stored_password) {
                if (stored_name == name) {
                    found = false;
                    break;
                }
            }
            file.close();

            if (!found) {
                cout << "The name already exists. Please try a different name." << endl;
                return false;
            } else {
                //录入信息
                ofstream outfile(filename, ios::app);
                if (!outfile.is_open()) {file_open_unsuccess();}
                outfile << name << " " << password << endl;
                outfile.close();
                cout << "Registration successful!" << endl;
                return true;
            }
        }

        //使用界面
        void admin_operation(){
            show_admin_first_menu(name);
        }

        void customer_operation(){
            show_customer_first_menu(name);
        }


    };


    int main() {
        hotel_management_system hms;
        //检测文件是否存在
        if(_access("information", 0) == -1)  
        {  _mkdir("information");}  

        if(_access("./information/customer.txt.txt", 0) == -1)  
        {   ofstream ouf("./information/customer.txt.txt");}  

        if(_access("./information/administrator.txt.txt", 0) == -1)  
        {  ofstream ouf("./information/administrator.txt.txt"); }  

        if(_access("./information/room_state.txt.txt", 0) == -1)  
        {  ofstream ouf("./information/room_state.txt.txt"); } 

        if(_access("./information/customer_room.txt.txt", 0) == -1)  
        {  
            ofstream ouf("./information/customer_room.txt.txt"); 
            ifstream read_file("./information/administrator.txt.txt");
            ofstream write_file("./information/customer_room.txt.txt");
            string line;
            while (getline(read_file, line)) {
                string find_name = hms.cut_str(line);
                write_file << "0000" <<' '<< line << endl;
            }
            read_file.close();
            write_file.close();
        } 

        
        hms.main_menu();
        return 0;
    }