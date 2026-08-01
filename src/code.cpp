#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

string who();
void adduser(string username, string password, string role);
char studentMenu();
char adminMenu();
void clearScreen();
void mainHeader();
void addstudent();
void subheader();
void addstudentIntoArry(string name, float matric, float fsc, float ecat, string p1,string p2, string p3);
void seatManagement();
int seatManagementMenu();
void viewStudents();
void printMeritOrder();
void generateMeritList();
void viewProfile();
void checkAdmissionStatus();
void changePassword();
string getFullDepartmentName(string dept);


const int TOTAL_USER = 10;
int count_user = 0;
string usernames[TOTAL_USER];
string passwords[TOTAL_USER];
string roles[TOTAL_USER];

const int TOTAL_STUDENT = 20;
int count_students = 0;
string students_nameA[TOTAL_STUDENT];
float matricA[TOTAL_STUDENT];
float fscA[TOTAL_STUDENT];
float ecatA[TOTAL_STUDENT];
string pref1A[TOTAL_STUDENT];
string pref2A[TOTAL_STUDENT];
string pref3A[TOTAL_STUDENT];

string department[] ={"CS", "CE", "EE"};
int seats[] = {0, 0, 0}; 
bool resultAnounce = false;

int main() {
    adduser("admin", "131","ADMIN");
    adduser("ali" , "123" , "STUDENT");

    while(true){
        string w = who();
        if(w == "ADMIN"){
            system("cls");
            char adminOption = ' ';
            while(true){
                adminOption = adminMenu();
                if(adminOption == '1'){
                    addstudent();
                }else if(adminOption == '2'){
                    viewStudents();
                }else if(adminOption == '3'){
                    printMeritOrder();
                }else if(adminOption == '4'){
                    generateMeritList();
                }else if(adminOption == '5'){
                    string username, password, role;
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;
                    cout << "Enter role(Capital): ";
                    cin >> role;
                    adduser(username, password, role);
                }else if(adminOption == '6'){
                    seatManagement();
                }else if(adminOption == '7'){
                    cout<<"Press 2 to Announce the result "<<endl;
                    char result;
                    cin>>result;
                    if(result == '2'){
                        resultAnounce = true;
                    }
                }else if(adminOption == '8'){
                    break;
                }else{
                    cout<<"Wrong input. Try Again!";
                    getch();
                }
                clearScreen();
            }
        }else if(w == "STUDENT"){
            char studentOption = ' ';
            while(true){
                studentOption = studentMenu();
                if(studentOption == '1'){
                    viewProfile();
                }else if(studentOption == '2'){
                    checkAdmissionStatus();
                }else if(studentOption == '3'){
                    changePassword();
                }else if(studentOption == '4'){
                    break;
                }else{
                    cout<<"You chose wrong option ";
                    getch();
                }
                clearScreen();
            }
        }else{
            cout<<"Wrong username or password ";
            getch();
        }
    }

    return 0;
}

string who(){
    mainHeader();
    string username;
    cout<<"Enter username: "<<endl;
    cin>>username;
    string password;
    cout<<"Enter password: "<<endl;
    cin>>password;

    for(int i=0; i<count_user; i++){
        if(usernames[i] == username && passwords[i] == password){
            return roles[i];
        }
    }

    return "wrong";
}

void adduser(string username, string password, string role){
    if(count_user < TOTAL_USER){
        usernames[count_user] = username;
        passwords[count_user] = password;
        roles[count_user] = role;
        count_user = count_user + 1;
    }else{
        cout<<"No more space to add new users "<<endl;
    }
}

char adminMenu(){
    mainHeader();
    cout<< "Admin Main Menu"<<endl;
    cout<< "1- Add New Student "<<endl;
    cout<< "2- View All Students "<<endl;
    cout<< "3- Print the record in merit order "<<endl;
    cout<< "4- Generate Merit "<<endl;
    cout<< "5- Add Users "<<endl;
    cout<< "6- Seat Management "<<endl;
    cout<< "7- Announce Result "<<endl;
    cout<< "8- logout "<<endl;
    cout<< " Choose Your Option"<<endl;
    char option;
    cin >> option;
    return option;
}


void mainHeader(){
    cout << "##############################################################" << endl;
    cout << "##          University Admission Management System          ##" << endl;
    cout << "##############################################################" << endl;
};

char studentMenu(){
    mainHeader();
    cout<<"Student Main Menu "<<endl;
    cout<<"1- View Your profile "<<endl;
    cout<<"2- Check Admission Status "<<endl;
    cout<<"3- Change Password "<<endl;
    cout<<"4- Logout "<<endl;
    char option;
    cin >> option;
    return option;
}

void clearScreen(){
    cout<<"Press anykey to continue "<<endl;
    getch();
    system("CLS");
}

void addstudent(){
    string name;
    float matric, fsc, ecat;
    string pref1, pref2, pref3;
    cout<<"Enter Student Name: ";
    cin>>name;
    cout<<"Enter Matric marks: ";
    cin>> matric;
    cout<<"Enter FSC Marks: ";
    cin>>fsc;
    cout<<"Enter Ecat Marks: ";
    cin>>ecat;
    subheader();
    cout<<endl;
    cout<<"Enter 1st Preference Name(In Capital): ";
    cin>> pref1;
    cout<<"Enter 2nd Preference Name(In Capital): ";
    cin>> pref2;
    cout<<"Enter 3rd Preference Name(In Capital): ";
    cin>> pref3;
    addstudentIntoArry(name,matric,fsc,ecat,pref1,pref2,pref3);
}

void addstudentIntoArry(string name, float matric, float fsc, float ecat, string p1,string p2, string p3){
    students_nameA[count_students] = name;
    matricA[count_students] = matric;
    fscA[count_students] = fsc;
    ecatA[count_students] = ecat;
    pref1A[count_students] = p1;
    pref2A[count_students] = p2;
    pref3A[count_students]= p3;
    count_students = count_students + 1;
}

void subheader(){
    cout<<" Enter the Name for Preferences "<<endl;
    cout<<"**************************************"<<endl;
    cout<<" Choose between these disciplines "<<endl;
    cout<<"1- CS for Computer Science "<<endl;
    cout<<"2- CE for Computer Engineering "<<endl;
    cout<<"3- EE for Electrical Engineering "<<endl;
    cout<<"**************************************"<<endl;
}

int seatManagementMenu(){
    mainHeader();
    cout<<" Seat Management Menu "<<endl;
    cout<<"1- Edit CS Capacity "<<endl;
    cout<<"2- Edit CE Capacity "<<endl;
    cout<<"3- Edit EE Capacity "<<endl;
    cout<<"4- View Seats Details "<<endl;
    cout<<"5- Back "<<endl;
    int option;
    cin>>option;
    return option;
}

void seatManagement(){
    int seatOption = 0;
    while(true){
        seatOption = seatManagementMenu();
        if(seatOption == 1){
            cout << "Enter new capacity for CS: ";
            cin >> seats[0];
        }else if(seatOption == 2){
            cout << "Enter new capacity for CE: ";
            cin >> seats[1];
        }else if(seatOption == 3){
            cout << "Enter new capacity for EE: ";
            cin >> seats[2];
        }else if(seatOption == 4){
            cout << "CS: " << seats[0] << endl;
            cout << "CE: " << seats[1] << endl;
            cout << "EE: " << seats[2] << endl;
        }else if(seatOption == 5){
            break;
        }else {
            cout<<"You Entered wrong option "<<endl;
        }
        clearScreen();
    }
}

void viewStudents(){
    for(int i = 0; i < count_students; i++){
        cout << "Name: " << students_nameA[i] << endl;
        cout << "Matric: " << matricA[i] << endl;
        cout << "FSC: " << fscA[i] << endl;
        cout << "ECAT: " << ecatA[i] << endl;
        cout << "Preferences: ";
        cout << getFullDepartmentName(pref1A[i]) << ", ";
        cout << getFullDepartmentName(pref2A[i]) << ", ";
        cout << getFullDepartmentName(pref3A[i]) << endl;
        cout << endl;
    }
    cout << "Press any key to continue...";
    cin.get();
    clearScreen();
}



string getFullDepartmentName(string dept){
    if(dept == "CS"){
        return "Computer Science";
    }else if(dept == "CE"){
        return "Computer Engineering";
    }else if(dept == "EE"){
        return "Electrical Engineering";
    }
    return dept;
}



void printMeritOrder(){
    for(int i = 0; i < count_students; i++){
        float merit = ((matricA[i] * 25)/100) + ((fscA[i] * 45)/100) + ((ecatA[i] * 30)/100);
        cout << "Name: " << students_nameA[i] << endl;
        cout << "Merit: " << merit << endl;
        cout << endl;
    }
    clearScreen();
}

void generateMeritList() {
    float merits[TOTAL_STUDENT];
    string names[TOTAL_STUDENT];
    float matrics[TOTAL_STUDENT];
    float fscs[TOTAL_STUDENT];
    float ecats[TOTAL_STUDENT];
    string prefs1[TOTAL_STUDENT], prefs2[TOTAL_STUDENT], prefs3[TOTAL_STUDENT];
    for (int i = 0; i < count_students; i++) {
        merits[i] = ((matricA[i] / 1100.0) * 25.0) + ((fscA[i] / 1200.0) * 45.0) + ((ecatA[i] / 400.0) * 30.0);
        names[i] = students_nameA[i];
        matrics[i] = matricA[i];
        fscs[i] = fscA[i];
        ecats[i] = ecatA[i];
        prefs1[i] = pref1A[i];
        prefs2[i] = pref2A[i];
        prefs3[i] = pref3A[i];
    }


    for(int i = 0; i < count_students; i++){
        cout << "Name: " << students_nameA[i] << endl;
        cout << "Merit: " << merits[i] << endl;
        cout << endl;
    }
    clearScreen();
}

void viewProfile(){
    string username;
    cout << "Enter your username: ";
    cin >> username;

    for(int i = 0; i < count_user; i++){
        if(usernames[i] == username){
            for(int j = 0; j < count_students; j++){
                if(students_nameA[j] == username){
                    cout << "Name: " << students_nameA[j] << endl;
                    cout << "Matric: " << matricA[j] << endl;
                    cout << "FSC: " << fscA[j] << endl;
                    cout << "ECAT: " << ecatA[j] << endl;
                    cout << "Preferences: " << pref1A[j] << ", " << pref2A[j] << ", " << pref3A[j] << endl;
                    cout << endl;
                }
            }
        }
    }
    clearScreen();
}

void checkAdmissionStatus(){
    string username;
    cout << "Enter your username: ";
    cin >> username;

    if(resultAnounce){
        for(int i = 0; i < count_students; i++){
            if(students_nameA[i] == username){
                cout << "Admission Status: ";
                if(i < seats[0]){
                    cout << "Admitted in CS" << endl;
                }else if(i < seats[0] + seats[1]){
                    cout << "Admitted in CE" << endl;
                }else if(i < seats[0] + seats[1] + seats[2]){
                    cout << "Admitted in EE" << endl;
                }else{
                    cout << "Not Admitted" << endl;
                }
            }
        }
    }else{
        cout << "Result not announced yet!" << endl;
    }
    clearScreen();
}

void changePassword(){
    string username;
    cout << "Enter your username: ";
    cin >> username;

    string oldPassword;
    cout << "Enter your old password: ";
    cin >> oldPassword;

    string newPassword;
    cout << "Enter your new password: ";
    cin >> newPassword;

    for(int i = 0; i < count_user; i++){
        if(usernames[i] == username && passwords[i] == oldPassword){
            passwords[i] = newPassword;
            cout << "Password changed successfully!" << endl;
            return;
        }
    }

    cout << "Invalid username or password!" << endl;
    clearScreen();
}



