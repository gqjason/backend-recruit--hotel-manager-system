#include<bits/stdc++.h>
#define int long long
#define dd double
#define str string
#define el cout << endl
#define re return
#define ff first
#define ss second
#define pll pair<int,int>
#define pdd pair<dd,dd>
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define sz(x) (int) x.size()
using namespace std;

void file_open_unsuccess(){
    cout << "Failed to open the file.\nPlease contact the administrator to solve the problem" << endl;
    cout<<"The program will exit.\nGoodbye";el;

    exit(0);
}

bool confirm_register_information(string standing){
    //打开文件夹
    string filename = "information\/" + standing + ".txt";
    cout<<filename;el;
    ifstream file(filename);
    if (!file.is_open()) {file_open_unsuccess();}

    str name = "asd",password = "qwe";
    //查找信息
    string stored_name, stored_password;
    bool found = true;
    while (file >> stored_name) {
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

void go(){
    str s;cin>>s;
   confirm_register_information(s);


}

signed main() {
       ios::sync_with_stdio(false);
       cin.tie(nullptr);cout.tie(nullptr);
       int t=1;
       while(t--){
               go();
       }
       return 0;
}