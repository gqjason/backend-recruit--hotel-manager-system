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



class running_func {
public:
    void clear_screen() {
        // 清空屏幕的实现
        system("CLS"); // Windows
        // 或者：system("clear"); // Unix/Linux
    }//清空屏幕

    void time_stop(int n) {
        this_thread::sleep_for(chrono::milliseconds(n));//改成1秒
    }//时间停止

    void file_open_unsuccess() {
        cout << "Failed to open the file.\nPlease contact the administrator to solve the problem" << endl;
        time_stop(200);
        cout << "The program will exit.\nGoodbye";el;
        time_stop(2000);
        clear_screen();
        exit(0);
    }

    void power_on() {
        cout << "Hello, welcome to the Hotel Management System.";el;//Hello, welcome to the Hotel Management System.
        time_stop(500);
        cout << "Please wait for a monent.....";//请等待
        time_stop(1000);
        clear_screen();


    }
    //主菜单
    void show_first_menu() {
        cout << "Hotel Management System"; el;//hms Hotel Management System
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "1. Login";el;//登录
        cout << "2. Register";el;//注册
        cout << "3. Exit";el;//退出
        cout << "Please enter options (1/2/3)";el;
    }
    //登录菜单
    void show_login_second_menu() {
        cout << setfill(' ') << setw(10) << " LOGIN " << setfill(' ') << endl;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "1. Customer login";el;
        cout << "2. Administrator login";el;
        cout << "3. Return to the upper-level menu";el;
        cout << "Please enter options (1/2/3)";el;
    }
    //注册菜单
    void show_register_second_menu() {
        cout << setfill(' ') << setw(10) << " REGISTER " << setfill(' ') << endl;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "1. Customer register";el;
        cout << "2. Administrator register";el;
        cout << "3. Return to the upper-level menu";el;
        cout << "Please enter options (1/2/3)";el;
    }
    //管理员界面
    void show_admin_first_menu(string admin_name) {
        cout << "Welcome back, Administrator " << admin_name << " .";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "1. ";cout << "Check customer information";el;
        cout << "2. ";cout << "Check room status";el;
        cout << "3. ";cout << "Management room is available";el;
        cout << "4. ";cout << "Delete customers";el;
        cout << "5. ";cout << "EXIT";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "Please enter options (1/2/3/4/5)";el;

    }
    //顾客界面
    void show_customer_first_menu(string customer_name) {
        cout << "Welcome back, Customer " << customer_name << " .";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "1. ";cout << "Top-up";el;
        cout << "2. ";cout << "Book a room";el;
        cout << "3. ";cout << "Check out";el;
        cout << "4. ";cout << "Check balance";el;
        cout << "5. ";cout << "Check room status";el;
        cout << "6. ";cout << "Check personal information";el;
        cout << "7. ";cout << "EXIT";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "Please enter options (1/2/3/4/5/6/7)";el;
    }
    //查询房间（类型）
    void show_the_query_room_status_menu_type() {
        cout << "Check room status";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "1. Single common room";el;
        cout << "2. Single deluxe room";el;
        cout << "3. Double common room";el;
        cout << "4. Double Deluxe Room";el;
        cout << "5. all";el;
        cout << "6. exit";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "Please enter options (1/2/3/4/5/6)";el;
    }
    //查询房间（状态）
    void show_the_query_room_book_status_menu() {
        cout << "Check room status";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "1. Booked";el;
        cout << "2. Not booked";el;
        cout << "3. all";el;
        cout << "4. exit";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "Please enter options (1/2/3/4)";el;
    }
    //管理房间类型
    void show_room_is_available_menu_type() {
        cout << "Manage rooms";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "1. Single common room";el;
        cout << "2. Single deluxe room";el;
        cout << "3. Double common room";el;
        cout << "4. Double Deluxe Room";el;
        cout << "5. all";el;
        cout << "6. Enter the specific room numbers";el;
        cout << "7. exit";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "Please enter options (1/2/3/4/5/6/7)";el;
    }
    //管理房间是否可用
    void show_room_is_available_room_book_status_menu() {
        cout << "What state do you want to convert these rooms into?";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "1. Booked";el;
        cout << "2. Not booked";el;
        cout << "3. exchange";el;
        cout << "4. exit";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "Please enter options (1/2/3/4)";el;
    }
    //订房一级目录
    void show_book_room_first_menu() {
        cout << "Book room";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "1. Single common room";el;
        cout << "2. Single deluxe room";el;
        cout << "3. Double common room";el;
        cout << "4. Double Deluxe Room";el;
        cout << "5. all";el;
        cout << "6. exit";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "Please enter options (1/2/3/4/5/6)";el;
    }
    //退房一级目录
    void show_customer_check_out_first_menu() {
        cout << "Checkout Menu";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "1. Confirm";el;
        cout << "2. Cancel";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "Please enter an option (1/2) :";
    }

    string cut_str(string s) {
        string res = "";
        for (int i = 0;i < s.length() and s[i] != ' ';i++) { res += s[i]; }
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

class hotel_management_system : public running_func {
public:
    map<string, vector<string>>customer_map, room_state;
    map<string, string>admin_map;
    string admin = "administrator", cus = "customer", nor = "normal", lux = "luxurious", sr = "single_room", dr = "double_room";
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
            for (int num = 0;num <= 20;num++) {
                string room_num = (floor < 10 ? "0" : "") + to_string(floor) + "0" + (num < 10 ? "0" : "") + to_string(num), room_type = "normal", room_member_num = "single_room";
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

    //map初始化
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
            admin_map[stored_admin_name] = stored_admin_password;
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
        string room_path = "./information/room_state.txt";

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

        ofstream room_info_file(room_path, ios::trunc);
        if (!room_info_file.is_open()) {
            cerr << "Functions : save_information_to_file !!!\n ERROR : Failed to open the file. \"room_state.txt\"." << endl;
            return;
        }
        room_info_file.close();

    }

    //保存文件
    void save_information_to_file() {
        string customer_path = "./information/customer.txt";
        string admin_path = "./information/administrator.txt";
        string room_path = "./information/room_state.txt";

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

        ofstream room_info_file(room_path, ios::out);
        if (!room_info_file.is_open()) {
            cerr << "Functions : save_information_to_file !!!\n ERROR : Failed to open the file. \"room_state.txt\"." << endl;
            return;
        }
        for (const auto& inf : room_state) {
            room_info_file << inf.first << " " << inf.second[0] << " " << inf.second[1] << " " << inf.second[2] << " " << inf.second[3] << endl;
        }
        room_info_file.close();
    }

    //退出程序
    void exit_operation() {
        clear_file();
        save_information_to_file();
        time_stop(100);
        clear_screen();
        exit(0);
    }

    void save_all_file() {
        clear_file();
        save_information_to_file();
    }

    //主菜单
    void main_menu() {
        if (first_enter == false) {
            power_on();
            initializes_the_hash_table();
            first_enter = true;
        }
        save_all_file();
        show_first_menu();
        char first_chioce;
        cin >> first_chioce;
        while (1)
        {
            if (first_chioce != '1' and first_chioce != '2' and first_chioce != '3') {
                if (number_of_repeats < 3) { cout << "Wrong type! Please re-enter";el; }
                else if (number_of_repeats >= 3 and number_of_repeats < 7) { cout << "Knock it off" << setfill('!') << setw(number_of_repeats) << "!";el; }
                else { cout << "Well, I'm done playing with you. Bye";el;break; }
                time_stop(200);
                clear_screen();
                number_of_repeats++;
                main_menu();
            }
            else {
                number_of_repeats = 0;
                clear_screen();
                break;
            }
        }
        if (first_chioce == '1') {
            login_menu();
        }
        else if (first_chioce == '2') {
            register_menu();
        }
        else if (first_chioce == '3') {
            cout << "Goodbye!";el;
        }
        exit_operation();
    }


    //登录菜单
    void login_menu() {
        save_all_file();
        clear_screen();
        RF.show_login_second_menu();
        char login_choice;
        cin >> login_choice;

        if (login_choice == '1') {
            number_of_repeats = 0;
            entry_of_login_information(cus);
        }
        else if (login_choice == '2') {
            number_of_repeats = 0;
            entry_of_login_information(admin);
        }
        else if (login_choice == '3') {
            number_of_repeats = 0;
            clear_screen();
            main_menu();
        }
        else {
            cout << "Wrong type! Please re-enter";el;

            time_stop(200);
            clear_screen();
            number_of_repeats++;
            login_menu();
        }
    }

    //登录信息输入菜单
    void entry_of_login_information(string login_standing) {
        save_all_file();
        clear_screen();
        cout << login_standing << " login";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "Please enter your name: ";cin >> name;el;
        cout << "Please enter your password: ";cin >> password;el;
        cout << "Confirm or Re-enter? (C/R)";el;
        char reenter_choice;
        cin >> reenter_choice;

        bool confirm_success = false;
        if (reenter_choice == 'R' or reenter_choice == 'r') {
            clear_screen();
            entry_of_login_information(login_standing);
        }
        else if (reenter_choice == 'C' or reenter_choice == 'c') {
            clear_screen();
            cout << "Please wait for a moment.....";el;
            confirm_success = confirm_login_information(login_standing);
        }
        else {
            clear_screen();
            cout << "Wrong type!\nWill return to the login interface.";el;
            time_stop(200);
            login_menu();
        }

        if (confirm_success) {
            cout << "Login successful!";el;
            time_stop(200);
            clear_screen();
            if (login_standing == admin) { admin_operation(); }
            else { customer_operation(); }
        }
        else {
            time_stop(200);
            clear_screen();
            main_menu();
        }
    }

    //登录核对信息
    bool confirm_login_information(string standing) {
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
        }
        else {
            cout << "Invalid name or password. Please try again." << endl;
            return false;
        }
    }






    //注册菜单
    void register_menu() {
        save_all_file();
        clear_screen();
        RF.show_register_second_menu();
        char register_choice;
        cin >> register_choice;

        if (register_choice == '1') {
            number_of_repeats = 0;
            entry_of_register_information(cus);
        }
        else if (register_choice == '2') {
            number_of_repeats = 0;
            entry_of_register_information(admin);
        }
        else if (register_choice == '3') {
            number_of_repeats = 0;
            clear_screen();
            main_menu();
        }
        else {
            if (number_of_repeats < 3) { cout << "Wrong type! Please re-enter";el; }
            else if (number_of_repeats >= 3 and number_of_repeats < 7) { cout << "Knock it off" << setfill('!') << setw(number_of_repeats) << "!";el; }
            else { cout << "Well, I'm done playing with you. Bye";el;exit(0); }
            time_stop(200);
            clear_screen();
            number_of_repeats++;
            register_menu();
        }

    }

    //注册信息输入菜单
    void entry_of_register_information(string register_standing) {
        save_all_file();
        clear_screen();
        cout << register_standing << " register";el;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        cout << "Please enter your name: ";cin >> name;el;
        cout << "Please enter your password: ";cin >> password;el;
        cout << "Confirm or Re-enter? (C/R)";el;
        char reenter_choice;
        cin >> reenter_choice;

        //输入判断
        bool register_success = false;
        if (reenter_choice == 'R' or reenter_choice == 'r') {
            clear_screen();
            time_stop(100);
            main_menu();
        }
        else if (reenter_choice == 'C' or reenter_choice == 'c') {
            clear_screen();
            cout << "Please wait for a moment.....";el;
            register_success = confirm_register_information(register_standing);
        }
        else {
            cout << "Wrong type!\nWill return to the main menu.";el;
            time_stop(200);
            clear_screen();
            main_menu();
        }

        //注册是否成功
        if (register_success == false) { entry_of_register_information(register_standing); }
        else {
            cout << "Return to the corresponding main menu after 2 seconds......";el;
            time_stop(2000);
            save_all_file();
            clear_screen();
            main_menu();
        }
    }

    //注册信息核对
    bool confirm_register_information(string standing) {

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
            save_all_file();
            return false;
        }
        else {
            if (standing == cus) {
                customer_map[name] = vector<string>(4, "NULL");
                customer_map[name][0] = password;
                customer_map[name][1] = "0";
            }
            else if (standing == admin) {
                admin_map[name] = password;
            }
            save_all_file();
            return true;
        }
    }



    //充值
    void recharge_balance_operation(int money) {
        cout << "Processing, please wait......";el;
        string temp = customer_map[name][1];
        int current_money = string_to_int(temp);
        int new_money = current_money + money;
        customer_map[name][1] = to_string(new_money);
        time_stop(500);
        cout << "Recharge successfully!";el;
        return;
    }

    void recharge_balance() {
        save_all_file();
        clear_screen();
        cout << "Please enter the recharge amount:";
        int money;cin >> money;
        recharge_balance_operation(money);
        save_all_file();
        customer_operation();
    }

    //查余额
    void check_balance(string choice_name) {
        save_all_file();
        string show_name = choice_name;
        string show_balance = customer_map[show_name][1];
        cout << "+-----------------------";el;
        cout << "| customer : " << show_name;el;
        cout << "| balance : " << show_balance;el;
        cout << "+-----------------------";el;
        cout << "Enter any letter to return";el;
        string cin1;cin >> cin1;
        clear_screen();
        customer_operation();
    }


    //显示个人信息
    void show_customer_personal_information(string choice_name) {
        string show_name = choice_name;
        string show_password = customer_map[show_name][0],
            show_money = customer_map[show_name][1],
            show_room = customer_map[show_name][2],
            show_room_level = customer_map[show_name][3];
        cout << "+-------------------------------";el;
        cout << "| customer : " << show_name;el;
        cout << "| password : " << show_password;el;
        cout << "| balance : " << show_money;el;
        cout << "| room : " << show_room;el;
        cout << "| room level : " << show_room_level;el;
        cout << "+-------------------------------";el;
    }

    void admin_or_customer_show(string user, int controls) {
        save_all_file();
        clear_screen();
        if (controls == 1 and user == admin) {//管理员查看所有人
            for (const auto& all_inf : customer_map) {
                show_customer_personal_information(all_inf.first);
            }
        }
        else if (user == cus and controls == 0) {//顾客查看自己
            show_customer_personal_information(name);
        }
        else if (user == admin and controls == 0) {//管理员选择查看某人
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
        cout<<"If it shows empty, there are no rooms that meet the criteria.";el;
        cout << "Enter any letter to return";el;
        string cin1;cin >> cin1;
        clear_screen();
        if (user == admin) { admin_operation(); }
        else { customer_operation(); }
    }

    //管理员查看
    void admin_check() {
        save_all_file();
        clear_screen();
        cout << "Select group";el;
        cout << "-------------------";el;
        cout << "1. Select (enter name)";el;
        cout << "2. Everyone";el;
        cout << "3. EXIT";el;
        cout << "-------------------";el;
        cout << "Please enter an option (1/2)";el;
        char choice_option;cin >> choice_option;
        int control = stoi(string(1, choice_option)) - 1;
        if (control == 2) { admin_operation(); }
        if (control != 0 and control != 1) {
            cout << "Incorrect input, please re-enter";el;
            time_stop(1000);clear_screen();
            admin_check();
        }
        admin_or_customer_show(admin, control);
    }


    //查房
    void check_room_state(string choice_room_num) {
        string crn = choice_room_num;
        string c_room_type = room_state[crn][0],
            c_room_menber_num = room_state[crn][1],
            c_room_price = room_state[crn][2],
            c_room_is_book = room_state[crn][3] == "0" ? "NO" : "YES";
        cout << "+-------------------------------";el;
        cout << "| Room number : " << crn;el;
        cout << "| Room type : " << c_room_type;el;
        cout << "| Number of people in room : " << c_room_menber_num;el;
        cout << "| Room price : " << c_room_price;el;
        cout << "| Is the room booked : " << c_room_is_book;el;
        cout << "+-------------------------------";el;
    }

    //选择房间类型
    void view_room_type_options(string types, string member, int book_state) {
        save_all_file();
        if (book_state == 0) {
            for (const auto& inf : room_state) {
                if (inf.second[0] == types and inf.second[1] == member and inf.second[3] == "0") {
                    check_room_state(inf.first);
                }
            }
        }
        else if (book_state == 1) {
            for (const auto& inf : room_state) {
                if (inf.second[0] == types and inf.second[1] == member and inf.second[3] == "1") {
                    check_room_state(inf.first);
                }
            }
        }
        else {
            for (const auto& inf : room_state) {
                if (inf.second[0] == types and inf.second[1] == member) {
                    check_room_state(inf.first);
                }
            }
        }
    }
    //不选择房间类型
    void view_room_options(int book_state) {
        save_all_file();
        if (book_state == 0) {
            for (const auto& inf : room_state) {
                if (inf.second[3] == "0") {
                    check_room_state(inf.first);
                }
            }
        }
        else if (book_state == 1) {
            for (const auto& inf : room_state) {
                if (inf.second[3] == "1") {
                    check_room_state(inf.first);
                }
            }
        }
        else {
            for (const auto& inf : room_state) {
                check_room_state(inf.first);
            }
        }
    }

    //选择房间类型
    void check_room_frist_menu(string standing) {
        save_all_file();
        show_the_query_room_status_menu_type();
        string type = nor, cnt = sr;
        char choice_type;cin >> choice_type;
        if (choice_type == '1') { type = nor, cnt = sr; }
        else if (choice_type == '2') { type = nor, cnt = dr; }
        else if (choice_type == '3') { type = lux, cnt = sr; }
        else if (choice_type == '4') { type = lux, cnt = sr; }
        else if (choice_type == '5') { type = "NULL", cnt = "NULL"; }
        else if (choice_type == '6') {
            if (standing == admin) { admin_operation(); }
            else if (standing == cus) { customer_operation(); }
        }
        else {
            cout << "Error input! ! !";el;
            time_stop(500);clear_screen();
            check_room_frist_menu(standing);
        }
        check_room_second_menu(standing, type, cnt);
        cout << "Enter any letter to return";el;
        string cin1;cin >> cin1;
        clear_screen();
        if (standing == admin) { admin_operation(); }
        else { customer_operation(); }
    }

    //选择房间状态
    void check_room_second_menu(string standing, string type, string cnt) {
        save_all_file();
        show_the_query_room_book_status_menu();
        int choice_state = 2;cin >> choice_state;
        if (choice_state == 1) { choice_state = 0; }
        else if (choice_state == 2) { choice_state = 1; }
        else if (choice_state == 3) { choice_state = 2; }
        else if (choice_state == 4) {
            if (standing == admin) { admin_operation(); }
            else if (standing == cus) { customer_operation(); }
        }
        else {
            cout << "Error input! ! !";el;
            time_stop(500);clear_screen();
            check_room_second_menu(standing, type, cnt);
        }
        if (type == "NULL" and cnt == "NULL") { view_room_options(choice_state); }
        else { view_room_type_options(type, cnt, choice_state); }
    }


    //删除顾客
    void delete_customers() {
        save_all_file();
        clear_screen();
        cout << "Please customer name : ";el;
        string choice_name;cin >> choice_name;
        if (customer_map[choice_name].empty()) {
            cout << "Sorry, the customer was not found.";el;
            time_stop(1000);
            clear_screen();
            admin_operation();
        }
        else {
            string room_number = customer_map[choice_name][2];
            if (room_number != "NULL") { room_state[room_number][3] = "0"; }
            customer_map.erase(choice_name);
            cout << "Customer has been successfully deleted";el;
        }
        save_all_file();
        cout << "Continue deleting customers?(Y/N)";el;
        char is_continue;cin >> is_continue;
        if (is_continue == 'Y' or is_continue == 'y') {
            clear_screen();
            delete_customers();
        }
        else {
            admin_operation();
        }
    }


    //管理房间是否可用
    void management_room_is_available_frist_menu() {
        save_all_file();
        show_room_is_available_menu_type();
        string type = nor, cnt = sr;
        char choice_type;cin >> choice_type;
        if (choice_type == '1') { type = nor, cnt = sr; }
        else if (choice_type == '2') { type = nor, cnt = dr; }
        else if (choice_type == '3') { type = lux, cnt = sr; }
        else if (choice_type == '4') { type = lux, cnt = sr; }
        else if (choice_type == '5') { type = "NULL", cnt = "NULL"; }
        else if (choice_type == '6') {
            type = "choice", cnt = "choice";
        }
        else if (choice_type == '7') { admin_operation(); }
        else {
            cout << "Error input! ! !";el;
            time_stop(500);clear_screen();
            management_room_is_available_frist_menu();
        }
        management_room_is_available_second_menu(type, cnt);
    }

    void management_room_is_available_second_menu(string type, string cnt) {
        save_all_file();
        vector<string>room_numbers;
        if (type == "NULL" and type == "NULL") {
            for (const auto& inf : room_state) { room_numbers.emplace_back(inf.first); }
        }
        else if (type == "choice" and type == "choice") {
            cout << "Please enter the room number and enter y or y to end :";el;
            string room_num_input = "NO";
            while (room_num_input != "y" or room_num_input != "Y")
            {
                cin >> room_num_input;
                room_numbers.emplace_back(room_num_input);
            }
            if (room_numbers.back() == "y" or room_numbers.back() == "Y") { room_numbers.pop_back(); }
        }
        else {
            for (const auto& inf : room_state) {
                if (inf.second[0] == type and inf.second[1] == cnt) { room_numbers.emplace_back(inf.first); }
            }
        }
        show_room_is_available_room_book_status_menu();
        int choice_state = 2;cin >> choice_state;
        if (choice_state == 1) { choice_state = 0; }
        else if (choice_state == 2) { choice_state = 1; }
        else if (choice_state == 3) { choice_state = 2; }
        else if (choice_state == 4) { management_room_is_available_frist_menu(); }
        else {
            cout << "Error input! ! !";el;
            time_stop(500);clear_screen();
            management_room_is_available_second_menu(type, cnt);
        }
        change_room_state(room_numbers, choice_state);

        cout << "Continue to change?(Y/N)";el;
        char is_continue;cin >> is_continue;
        if (is_continue == 'Y' or is_continue == 'y') {
            clear_screen();
            management_room_is_available_frist_menu();
        }
        else {
            admin_operation();
        }
    }
    //改变房间状态
    void change_room_state(const vector<string>& room_nums, const int operation) {
        for (const auto& rn : room_nums) {
            if (!room_state[rn].empty()) {
                if (operation == 2) {
                    room_state[rn][3] = room_state[rn][3] == "0" ? "1" : "0";
                }
                else {
                    room_state[rn][3] = to_string(operation);
                }
            }
        }
        save_all_file();
        cout << "Change successful";el;
    }


    //订房
    void booking_room_first_menu() {
        save_all_file();
        cout << "Please select the room type you want to book.";el;
        cout << "your balance : " << customer_map[name][1];el;
        show_book_room_first_menu();
        string type = nor, cnt = sr;
        char choice_type;cin >> choice_type;
        if (choice_type == '1') { type = nor, cnt = sr; }
        else if (choice_type == '2') { type = nor, cnt = dr; }
        else if (choice_type == '3') { type = lux, cnt = sr; }
        else if (choice_type == '4') { type = lux, cnt = sr; }
        else if (choice_type == '5') { type = "NULL", cnt = "NULL"; }
        else if (choice_type == '6') { customer_operation(); }
        else {
            cout << "Error input! ! !";el;
            time_stop(500);clear_screen();
            booking_room_first_menu();
        }
        clear_screen();
        show_available_rooms(type, cnt);
        input_room_number_processing();



    }
    //展示可预订的房间
    void show_available_rooms(string type, string cnt) {
        if (type == "NULL" and cnt == "NULL") {
            for (const auto& inf : room_state) {
                if (room_state[inf.first][3] == "0") {
                    check_room_state(inf.first);
                }
            }
        }
        else {
            for (const auto& inf : room_state) {
                if (inf.second[0] == type and inf.second[1] == cnt and room_state[inf.first][3] == "0") {
                    check_room_state(inf.first);
                }
            }
        }
    }

    void input_room_number_processing() {
        save_all_file();
        string room_num;
        cout << "Enter the room number to book(Enter 1 to exit) : ";
        cin >> room_num;
        if (room_num == "1") { booking_room_first_menu(); }
        if (room_state[room_num].empty()) {
            cout << "The room does not exist.";el;
            time_stop(500);
            input_room_number_processing();
        }
        else if (room_state[room_num][3] == "1") {
            cout << "The room has been booked.";el;
        }
        else {
            int room_charge = string_to_int(room_state[room_num][2]);
            string type = room_state[room_num][0], cnt = room_state[room_num][1];
            if (!deduction_balance(room_charge)) {
                time_stop(500);clear_screen();
                booking_room_first_menu();
            }
            else {
                string origin_room_num = customer_map[name][2];
                string room_level = type + "_" + cnt;
                room_state[room_num][3] = "1";
                customer_map[name][3] = room_level;
                customer_map[name][2] = room_num;
                if (!room_state[origin_room_num].empty()) { room_state[origin_room_num][3] = "0"; }
                cout << "Booking successful!";el;
            }
        }
        save_all_file();
        customer_operation();
    }

    //扣钱
    bool deduction_balance(int money) {
        string temp = customer_map[name][1];
        int current_money = string_to_int(temp);
        if (current_money < money) {
            cout << "The balance is insufficient, please top up!";el;
            return false;
        }
        int new_money = current_money - money;
        customer_map[name][1] = to_string(new_money);
        return true;
    }


    //退房
    void user_check_out() {
        save_all_file();
        if (customer_map[name][2] == "NULL" and customer_map[name][3] == "NULL") {
            cout << "You have no room to return.\nReturning to the customer menu in 1 second.";el;
            time_stop(1000);
            clear_screen();
            customer_operation();
        }
        char choice_option;
        show_customer_check_out_first_menu();
        cin >> choice_option;
        if (choice_option == '1') {
            string room_number = customer_map[name][2];
            customer_map[name][2] = "NULL", customer_map[name][3] = "NULL";
            room_state[room_number][3] = "0";
            cout << "Check-out successful!";el;
            time_stop(1000);
            clear_screen();
            save_all_file();
            customer_operation();
        }
        else {
            save_all_file();
            clear_screen();
            customer_operation();
        }
    }


    //使用界面
        //管理者
    void admin_operation() {
        clear_screen();
        char choice_option;
        show_admin_first_menu(name);
        save_all_file();
        cin >> choice_option;
        if (choice_option == '1') { clear_screen();admin_check(); }
        else if (choice_option == '2') { clear_screen();check_room_frist_menu(admin); }
        else if (choice_option == '3') { clear_screen();management_room_is_available_frist_menu(); }
        else if (choice_option == '4') { clear_screen();delete_customers(); }
        else if (choice_option == '5') { clear_screen();clear_screen();main_menu(); }
        else {
            cout << "Error input! ! !";el;
            save_all_file();
            time_stop(500);clear_screen();
            admin_operation();
        }

    }

    //用户
    void customer_operation() {
        clear_screen();
        char choice_option;
        save_all_file();
        show_customer_first_menu(name);
        cin >> choice_option;
        if (choice_option == '1') { clear_screen();recharge_balance(); }
        else if (choice_option == '2') { clear_screen();booking_room_first_menu(); }
        else if (choice_option == '3') { clear_screen();user_check_out(); }
        else if (choice_option == '4') { clear_screen();check_balance(name); }
        else if (choice_option == '5') { clear_screen();check_room_frist_menu(cus); }
        else if (choice_option == '6') { clear_screen();admin_or_customer_show(cus, 0); }
        else if (choice_option == '7') { clear_screen();clear_screen();main_menu(); }
        else {
            cout << "Error input! ! !";el;
            save_all_file();
            time_stop(500);clear_screen();
            customer_operation();
        }
    }



};



int main() {
    hotel_management_system hms;
    //检测文件是否存在
    if (_access("information", 0) == -1)
    {
        _mkdir("information");
    }

    if (_access("./information/customer.txt", 0) == -1)
    {
        ofstream ouf("./information/customer.txt");
    }

    if (_access("./information/administrator.txt", 0) == -1)
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