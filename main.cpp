#include<iostream>
#include<fstream>
#include<vector>
#include<map>
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
        time_stop(2000);
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

    int string_to_int(string s) {
        int len = s.length();
        int res = 0;
        for (int i = 0;i < len;i++) {
            res = res * 10 + (s[i] - '0');
        }
        return res;
    }



};

class hotel_management_system : public running_func{
    public:
        map<string, vector<string>>customer_map,room_state;
        map<string, string>admin_map;
        string admin = "administrator", cus = "customer",nor = "normal",lux = "luxurious",sr = "single_room",dr = "double_room";
        running_func RF;
        string name;
        string password;
        string id;

        bool first_enter = false;
        int number_of_repeats = 0;

        void file_open_unsuccess() {
            cout << "Failed to open the file.\nPlease contact the administrator to solve the problem" << endl;
            time_stop(200);
            cout << "The program will exit.\nGoodbye";el;
            time_stop(2000);
            exit_operation();
        }
        
        void room_initialization() {
            string room_path = "./information/room_state.txt";
            ofstream room_info_file(room_path, ios::out);
            if (!room_info_file.is_open()) {
                cerr << "Functions : room_initialization !!!\n ERROR : Failed to open the file. \"room_state.txt\"." << endl;
                return;
            }
            for (int floor = 2;floor <= 30;floor++) {
                for (int num = 0;num <= 9;num++) {
                    string room_num = to_string(floor) + to_string(num), room_type = "normal",room_member_num = "single_room";
                    
                    int money = 0;
                    if (floor > 20) { room_type = "luxurious"; }
                    if (num > 5) { room_member_num = "double_room"; }
                    money = room_type == "normal" ? money + 50 : money + 150;
                    money = room_member_num == "single_room" ? money + 50 : money + 75;
                    room_info_file << room_num << " " << room_type << " " << room_member_num << " " << to_string(money) << " " << "0" << endl;
                }
            }
            cout << "Room initialization was successful";el;
            time_stop(300);
            clear_screen();
        }

        void initializes_the_hash_table() {
            //顾客
            string cus_path = "./information/customer.txt";
            fstream customer_file;
            customer_file.open(cus_path, ios::in);
            if (!customer_file.is_open()) { clear_screen();file_open_unsuccess(); }

            string stored_name, stored_password, store_money, store_room, store_room_level;
            while (customer_file >> stored_name >> stored_password >> store_money >> store_room >> store_room_level) {
                if (customer_map[stored_name].empty()) {
                    customer_map[stored_name] = vector<string>(4, "NULL");
                }
                customer_map[stored_name][0] = stored_password;
                customer_map[stored_name][1] = store_money;
                customer_map[stored_name][2] = store_room;
                customer_map[stored_name][3] = store_room_level;
            }
            customer_file.close();

            //管理员
            string admin_path = "./information/administrator.txt";
            fstream admin_file;
            admin_file.open(admin_path, ios::in);
            if (!admin_file.is_open()) { clear_screen();file_open_unsuccess(); }

            string stored_admin_name, stored_admin_password;
            while (admin_file >> stored_admin_name >> stored_admin_password) {
                if (admin_map[stored_admin_name].empty()) {
                    admin_map[stored_admin_name] = "NULL";
                }
                admin_map[stored_name] = stored_password;
            }
            admin_file.close();

            //房间
            string room_path = "./information/room_state.txt";
            fstream room_file;
            room_file.open(room_path, ios::in);
            if (!room_file.is_open()) { clear_screen();file_open_unsuccess(); }

            string room_num, room_type, room_menber_num, room_price, is_book;
            while (room_file >> room_num >> room_type >> room_menber_num >> room_price >> is_book) {
                if (room_state[room_num].empty()) {
                    room_state[room_num] = vector<string>(4, "NULL");
                }
                room_state[room_num][0] = room_type;
                room_state[room_num][1] = room_menber_num;
                room_state[room_num][2] = room_price;
                room_state[room_num][3] = is_book;
            }
            room_file.close();

        }

        //清理文件
        void clear_file() {
            string customer_path = "./information/customer.txt";
            string admin_path = "./information/administrator.txt";
            ofstream cus_file(customer_path, ios::trunc);
            if (!cus_file.is_open()) {
                cerr << "Functions : clear_file !!!\n ERROR : Failed to open the file. \"customer.txt\"." << endl;
                return;
            }
            cus_file.close();
            ofstream admin_file(admin_path, ios::trunc);
            if (!admin_file.is_open()) {
                cerr << "Functions : clear_file !!!\n ERROR : Failed to open the file \"administrator.txt\"." << endl;
                return;
            }
            admin_file.close();
        }

        //输入文件
        void save_information_to_file() {
            string customer_path = "./information/customer.txt";
            string admin_path = "./information/administrator.txt";
            ofstream customer_info_file(customer_path, ios::out);
            if (!customer_info_file.is_open()) {
                cerr << "Functions : save_information_to_file !!!\n ERROR : Failed to open the file. \"customer.txt\"." << endl;
                return;
            }
            for (const auto& inf : customer_map) {
                customer_info_file << inf.first << " " << inf.second[0] << " " << inf.second[1] << " " << inf.second[2] << " " << inf.second[3] << endl;
            }
            customer_info_file.close();
            ofstream admin_info_file(admin_path, ios::out);
            if (!admin_info_file.is_open()) {
                cerr << "Functions : save_information_to_file !!!\n ERROR : Failed to open the file \"administrator.txt\"." << endl;
                return;
            }
            for (const auto& inf : admin_map) {
                admin_info_file << inf.first << " " << inf.second << endl;
            }
            admin_info_file.close();
        }

        //退出程序
        void exit_operation() {
            clear_file();
            save_information_to_file();
            time_stop(100);
            clear_screen();
            exit(0);
        }

        //主菜单
        void main_menu(){
            if(first_enter == false){
                power_on();
                initializes_the_hash_table();
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
                    else {cout<<"Well, I'm done playing with you. Bye";el;break;}
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
            }else if(first_chioce == '3'){
                cout<<"Goodbye!";el;
            }
            exit_operation();
        }


        //登录菜单
        void login_menu(){
            RF.show_login_second_menu();
            char login_choice;
            cin>>login_choice;

            if(login_choice == '1'){
                number_of_repeats=0;
                entry_of_login_information(cus);
            }else if(login_choice == '2'){
                number_of_repeats=0;
                entry_of_login_information(admin);
            }else if(login_choice == '3'){
                number_of_repeats=0;
                clear_screen();
                main_menu();
            }else{
                cout<<"Wrong type! Please re-enter";el;
                    
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
            bool found = false;
            if (standing == cus) {
                for (const auto& inf : customer_map) {
                    if (inf.first == name and inf.second[0] == password) {
                        found = true;
                        break;
                    }
                }
            }
            else if (standing == admin) {
                for (const auto& inf : admin_map) {
                    if (inf.first == name and inf.second == password) {
                        found = true;
                        break;
                    }
                }
            }
            
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
                entry_of_register_information(cus);
            }else if(register_choice == '2'){
                number_of_repeats=0;
                entry_of_register_information(admin);
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
                    register_menu();
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
            
            bool found = true;
            if (standing == cus) {
                for (const auto& inf : customer_map) {
                    if (inf.first == name) {
                        found = false;
                        break;
                    }
                }
            }
            else if (standing == admin) {
                for (const auto& inf : admin_map) {
                    if (inf.first == name) {
                        found = false;
                        break;
                    }
                }
            }

            if (!found) {
                cout << "The name already exists. Please try a different name." << endl;
                return false;
            } else {
                if (standing == cus) {
                    customer_map[name] = vector<string>(4, "NULL");
                    customer_map[name][0] = password;
                    customer_map[name][1] = "0";
                }
                else if (standing == admin) {
                    
                    admin_map[name] = password;
                }
                return true;
            }
        }

        //使用界面
            //管理者
        void admin_operation(){
            show_admin_first_menu(name);

        }

            //用户
        void customer_operation(){
            show_customer_first_menu(name);
        }

        //充值
        void recharge_balance(int money) {
            bool found = true;
            string temp = customer_map[name][1];
            int current_money = string_to_int(temp);
            int new_money = current_money + money;
            customer_map[name][1] = to_string(new_money);
            cout << "Recharge successfully!";el;
            return;
        }

        //扣钱
        bool deduction_balance(int money) {
            bool found = true;
            string temp = customer_map[name][1];
            int current_money = string_to_int(temp);
            if (current_money < money) {
                cout << "Insufficient balance, please recharge!";el;
                return false;
            }
            int new_money = current_money - money;
            customer_map[name][1] = to_string(new_money);
            cout << "Recharge successfully!";el;
            return true;
        }

        //显示个人信息
        void show_customer_personal_information(string choice_name) {
            string show_name = name;
            string show_password = customer_map[show_name][0],
                show_money = customer_map[show_name][1],
                show_room = customer_map[show_name][2],
                show_room_level = customer_map[show_name][3];
            cout << "+-------------------------------";el;
            cout << "| customer : "<<show_name;el;
            cout << "| password : "<<show_password;el;
            cout << "| balance : "<<show_money;el;
            cout << "| room : "<<show_room;el;
            cout << "| room level : "<<show_room_level;el;
            cout << "+-------------------------------";el;
        }

        void admin_or_customer_show(string user, int controls) {
            if (controls == 1 and user == admin) {
                for (const auto& all_inf : customer_map) {
                    show_customer_personal_information(all_inf.first);
                }
            }
            else if (user == cus and controls == 0) {
                show_customer_personal_information(name);
            }
            else if (user == admin and controls == 0) {
                cout << "Enter the user you want to find : ";
                string cin_name;cin >> name;
                if (customer_map[cin_name].empty()) {
                    cout << "The user cannot be found, please re-enter!";el;
                    time_stop(500);
                    clear_screen();
                    admin_or_customer_show(user, controls);
                }
                else
                {
                    show_customer_personal_information(cin_name);
                }
            }
            else {
                cout << "Wrong operation, please contact the author of https://github.com/gqjason The program will be closed after a while.";el;
                time_stop(500);
                exit_operation();
            }
            cout << "Enter any letter to return";el;
            string cin1;cin >> cin1;
            clear_screen();
            if (user == admin) { admin_operation(); }
            else { customer_operation(); }
        }


    };



    int main() {
        hotel_management_system hms;
        //检测文件是否存在
        if(_access("information", 0) == -1)  
        {  _mkdir("information");}  

        if(_access("./information/customer.txt", 0) == -1)  
        {   
            ofstream ouf("./information/customer.txt");
        }  

        if(_access("./information/administrator.txt", 0) == -1)  
        {  
            ofstream ouf("./information/administrator.txt"); 
        }  

        if (_access("./information/room_state.txt", 0) == -1)
        {
            ofstream ouf("./information/room_state.txt");
            hms.room_initialization();
        }

        hms.main_menu();
        return 0;
    }