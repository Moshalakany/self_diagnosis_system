#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

////////////////////////////////////////////AHMED INTEGRATED VERSION//////////////////////////////////////////////////////////
                                                //Global Variables...//
string username, password;
int DoctorCounter = 3;
int PatientCounter = 3;
int log_in_user_ID = 0;
string log_in_user_type = "0";
int diseaseSize = 0;
int his_count = 0;
int choise; //ayh dah
//int symptomSize = 3;
///////////////////////////////////////////////////////////////////////////////////////////////////////
                                            //Function decleration...//
string* mainGUI(); // taha
string* RegisterNewUser(string UserChoice);
string* LoginUser(string UserChoice);
void ahmed_check();

void displaymenu();// basel
void intialize_d();
void initialize_doctors();
void display_disease();
void add_disease();
void add_syp();
void view_p_with_disease();
void p();
void removeDisease();
void removeSyp();

void menu(); //yehia w 4lakany
void diagnose();
void display_symp();
void view_diagnose_history();
void Clear_diagnosis_history();
//////////////////////////////////////////////////////////////////////////////////////////////////////
                                            //define structures...//
struct disease
{
    string title;
    int ID;
    string general_info;
    string symptoms[10];
    int no_patients_dig;
    int symptomsize = 0;
};
struct account
{
    string username;
    string password;
};
struct patient {
    string name;
    int age;
    string gender;
    account acc;
    int dis_his[10]; // ayh dah
};
struct doctor
{
    string fullname;
    disease di[10];
    account acc;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                // intialization of struct instance... //
disease x[10];
patient y[10];
doctor d[10];

//////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                    // main () //
int main()
{
    initialize_doctors();
    p();
    intialize_d();
start:string* RegisterCheck;
    string* LoginCheck;
    string* UserChoice = mainGUI();
    //UserChoice[0]-->hwa el log in aw el register , userchoice[1]-->doctor aw patient
    //LoginCheck[0]-->hwa el id , logincheck[1]-->hwa el s7 aw el 8lt   
    if (UserChoice[0] == "1") {
        //login
        LoginCheck = LoginUser(UserChoice[1]);
        if (LoginCheck[1] == "1" && UserChoice[1] == "1") // doctor
        {
            log_in_user_ID = stoi(LoginCheck[0]);
            log_in_user_type = "doctor";
        }
        else if (LoginCheck[1] == "1" && UserChoice[1] == "2") // patient
        {
            log_in_user_ID = stoi(LoginCheck[0]);
            log_in_user_type = "patient";
        }
        else if (LoginCheck[1] == "e" || LoginCheck[1] == "E")
        {
            system("cls");
            goto start;
        }
        else
        {
            system("cls");
            goto start;
        }
    }
    else if (UserChoice[0] == "2")
    {
        //register
        RegisterCheck = RegisterNewUser(UserChoice[1]);
        if (RegisterCheck[5] == "e" || RegisterCheck[5] == "E")
        {
            system("cls");
            goto start;
        }
        else
        {
            if (UserChoice[1] == "1")
            {
                if (DoctorCounter < 10) //doctor
                {
                    d[DoctorCounter].fullname = RegisterCheck[0];
                    d[DoctorCounter].acc.username = RegisterCheck[1];
                    d[DoctorCounter].acc.password = RegisterCheck[2];
                    DoctorCounter++;
                    system("cls");
                    goto start;
                }
                else {
                    system("cls");
                    goto start;
                }
            }
            else if (UserChoice[1] == "2") // patient
            {

                if (PatientCounter < 10)
                {
                    y[PatientCounter].name = RegisterCheck[0];
                    y[PatientCounter].acc.username = RegisterCheck[1];
                    y[PatientCounter].acc.password = RegisterCheck[2];
                    int age_int = stoi(RegisterCheck[3]);
                    y[PatientCounter].age = age_int;
                    y[PatientCounter].gender = RegisterCheck[4];
                    PatientCounter++;
                    system("cls");
                    goto start;

                }
                else {
                    system("cls");
                    goto start;
                }
            }
            else if (UserChoice[1] == "e" || UserChoice[1] == "E")
            {
                system("cls");
                goto start;
            }
            else
            {
                system("cls");
                goto start;
            }
        }
    }
    else if (UserChoice[0] == "3") {
        cout << "THANKS FOR YOUR INTERSTS, \nGOOD BYE.. " << endl;
        return 0;
    }
    else if (UserChoice[0] == "e" || UserChoice[0] == "E")
    {
        system("cls");
        goto start;
    }
    else
    {
        system("cls");
        goto start;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        // authentication granted using 2 flags log_in_user_ID and log_in_user_Type... //
    int option = 70;
    if (log_in_user_type == "doctor") {
        system("cls");
        //  intialize_d(); p();
        do
        {
            //ahmed_check();
            displaymenu();
            cout << "Enter option: "; cin >> option;
            system("cls");
            switch (option)
            {
            case 1:add_disease(); break;
            case 5:display_disease(); break;
            case 3:add_syp(); break;
            case 6:view_p_with_disease(); break;
            case 2:removeDisease(); break;
            case 4:removeSyp(); break;
            default:
                break;
            }
        } while (option != 0);


    }
    else if (log_in_user_type == "patient") {
        system("cls");
        // intialize_d();
        // p();
        do {
            menu();
            cin >> choise;
            system("cls");
            if (choise > 5 || choise < 1) {
                cout << "invalid input\n";
            }
            switch (choise)
            {
            case 1:
                diagnose();
                break;
            case 2:
                display_symp();
                break;
            case 3:
                view_diagnose_history();
                break;
            case 4:
                Clear_diagnosis_history();
                break;
            }
        } while (choise != 5);
    }

    if (option == 0 || choise == 5) {

        log_in_user_ID = 0;
        log_in_user_type = "0";
        system("cls");
        cout << "log out is done, redirection in 3 sec ..";
        //sleep(3);
        system("cls");
        goto start;

    }
    return 0;
}
//////////////////////////////////////////////////////// sho8l ahmed taha //////////////////////////////////////////////////////////////////////
string* mainGUI() {
    static string UserChoice[2] = { "0","0" }; //[0] is register or log in //[1] is patient or doctor...
    while (true)
    {
        cout << "\t\t\t\t\t*WELCOME TO SELF DIAGNOSIS SYSTEM*\n";
        cout << "\t\t\t\t\t**********************************\n";
        cout << "Press 1 to Login: " << endl;
        cout << "Press 2 to Register: " << endl;
        cout << "Press 3 to Exit: " << endl;
        cout << "Your Choice: ";
        cin >> UserChoice[0];
        // 1,1--->login doctor , 1,2--->log in patient , 2,1---> register , doctor , 2,2--->register , patient
        if (UserChoice[0] == "1" || UserChoice[0] == "2") {
            system("cls");
            cout << "For Doctor press 1, for Patient press 2, to Exit press e or E. \nYour Choice: ";
            cin >> UserChoice[1];
            if (UserChoice[1] == "e" || UserChoice[1] == "E")
            {
                UserChoice[0] = "e"; // "e","e"
            }
            else if (UserChoice[1] != "1" && UserChoice[1] != "2") {
                UserChoice[0] = "0"; // "0" , "ay 7aga "
            }
            system("cls");
            return UserChoice;
        }

        else if (UserChoice[0] == "3") {
            system("cls");
            return UserChoice;

        }
        else {
            system("cls");
        }
    }
}
string* RegisterNewUser(string UserChoice) {
    static string NewUser[6] = { "0","0","0","0","0","0" };
    if (UserChoice == "1") // 1---->register as doctor
    {
        static string Question[3] = { "Please enter your FULLNAME, if you don't want to proceed press 'e' or 'E'.\nFULLNAME: ",
        "Please enter your USERNAME, if you don't want to proceed press 'e' or 'E'.\nUSERNAME: ",
        "Please enter your PASSWORD, if you don't want to proceed press 'e' or 'E'.\nPASSWORD: " };
        //[0] is fullname , [1] is username , [2] is password , [3],[4] are rubbish  , [5] is exit(flag)
        string temp;
        cout << Question[0];
        cin.ignore();
        getline(cin, temp);
        NewUser[0] = temp;
        for (int i = 1; i < 3; i++) {
            cout << Question[i];
            cin >> temp;
            if (temp == "e" || temp == "E") {
                NewUser[5] = temp;
                return NewUser;
            }
            else {
                NewUser[i] = temp;
                NewUser[5] = "0";
            }
        }
        return NewUser;
    }
    else if (UserChoice == "2") // 2----> register as patient
    {
        static string Question[5] = { "Please enter your FULLNAME, if you don't want to proceed press 'e' or 'E'.\nFULLNAME: ",
        "Please enter your USERNAME, if you don't want to proceed press 'e' or 'E'.\nUSERNAME: ",
        "Please enter your PASSWORD, if you don't want to proceed press 'e' or 'E'.\nPASSWORD: ",
        "Please enter your AGE, if you don't want to proceed press 'e' or 'E'.\nAGE: ",
        "Please enter your GENDER, if you don't want to proceed press 'e' or 'E'.\nGENDER: ", };
        //[0] is fullname , [1] is username , [2] is password , [3] is age , [4] is gender , [5] is exit(flag)
        string temp;
        cout << Question[0];
        cin.ignore();
        getline(cin, temp);
        NewUser[0] = temp;
        for (int i = 1; i < 5; i++) {
            cout << Question[i];
            cin >> temp;
            if (temp == "e" || temp == "E") {
                NewUser[5] = temp;
                return NewUser;
            }
            else {
                NewUser[i] = temp;
                NewUser[5] = "0";
            }
        }
        return NewUser;
    }
    else if (UserChoice == "e" || UserChoice == "E") // --->exit
    {
        // 0--->4 are rubbish , [5] is exit flag
        NewUser[5] = "e";
        return NewUser;
    }
}
string* LoginUser(string UserChoice)
{
    static string s7_8lt_info[2] = { "0","0" }; //[0] which doctor aw patient id   /\ [1] loged in wla laa
    cout << "Enter your username: "; cin >> username;
    cout << "Enter your password: "; cin >> password;
    if (UserChoice == "1") //doctor
    {
        for (int i = 0; i < DoctorCounter; i++)
        {
            if (username == d[i].acc.username)
            {

                if (password == d[i].acc.password)
                {
                    s7_8lt_info[0] = to_string(i);
                    s7_8lt_info[1] = "1";
                    return s7_8lt_info;
                }
            }
        }
    }
    else if (UserChoice == "2") //patient
    {
        for (int i = 0; i < PatientCounter; i++)
        {
            if (username == y[i].acc.username)
            {

                if (password == y[i].acc.password)
                {
                    s7_8lt_info[0] = to_string(i);
                    s7_8lt_info[1] = "1";
                    return s7_8lt_info;
                }
            }
        }
    }
    else if (UserChoice == "e" || UserChoice == "E")
    {
        s7_8lt_info[1] = "e";
        return s7_8lt_info;
    }
    s7_8lt_info[0] = "0";//awl t3dil
    s7_8lt_info[1] = "0";//tani t3dil
    return s7_8lt_info;
}
///////////////////////////////////////////////////////////// sho8l bassel & eslam /////////////////////////////////////////////////////////////////
void displaymenu() {
    cout << "---------------------------------------------- welcome in doctor page -------------------------------------------------\n\n\n";
    cout << "\t\t\t\t\t\tWELCOME DOCTOR: " << d[log_in_user_ID].fullname << endl;
    cout << "\t\t\t\t\t\t\t*******************\n";
    cout << "Press 1 to add a disease\n\n";
    cout << "Press 2 to remove a disease\n\n";
    cout << "Press 3 to add symptom to an existing disease\n\n";
    cout << "Press 4 to remove symptom from an existing disease\n\n";
    cout << "Press 5 to display all disease \n\n";
    cout << "Press 6 to view patients with a certain disease\n\n";
    cout << "Press 0 to logout\n\n";
}
void intialize_d() {
    fstream myfile;
    myfile.open("diseases.txt", ios::out);
    if (myfile.is_open()) {
        /// /////////////////
        //first disease
        x[diseaseSize].title = "covid-19"; x[diseaseSize].ID = 123; x[diseaseSize].general_info = "very dangerous specially for people above 50"; x[diseaseSize].symptoms[0] = "fever";
        x[diseaseSize].symptoms[1] = "coughing"; x[diseaseSize].symptoms[2] = "nasal congestion"; x[diseaseSize].no_patients_dig = 0;
        x[diseaseSize].symptomsize += 3;
        diseaseSize++;
        //second disease
        x[1].title = "diabetes"; x[1].ID = 456; x[1].general_info = "endemic"; x[1].symptoms[0] = "very tired"; x[1].symptoms[1] = "very thirsty";
        x[1].symptoms[2] = "very hungry"; x[1].no_patients_dig = 0;
        x[diseaseSize].symptomsize += 3;
        diseaseSize++;

        //third disease
        x[2].title = "heart disease"; x[2].ID = 789; x[2].general_info = "extremely dangerous"; x[2].symptoms[0] = "shortness of breath";
        x[2].symptoms[1] = "chest pain"; x[2].symptoms[2] = "weakness"; x[2].no_patients_dig = 0;
        x[diseaseSize].symptomsize += 3;
        diseaseSize++;
        /////////////
        myfile << x[0].title << "\n" << x[0].ID << "\n" << x[0].general_info << "\n" << x[0].symptoms[0] << ",\t" << x[0].symptoms[1] << ",\t" << x[0].symptoms[2] << "\n" << x[0].no_patients_dig << "\n";
        myfile << x[1].title << "\n" << x[1].ID << "\n" << x[1].general_info << "\n" << x[1].symptoms[0] << ",\t" << x[1].symptoms[1] << ",\t" << x[1].symptoms[2] << "\n" << x[1].no_patients_dig << "\n";
        myfile << x[2].title << "\n" << x[2].ID << "\n" << x[2].general_info << "\n" << x[2].symptoms[0] << ",\t" << x[2].symptoms[1] << ",\t" << x[2].symptoms[2] << "\n" << x[2].no_patients_dig << "\n";
        myfile.close();
    }
}
void initialize_doctors() {
    fstream docfile;
    docfile.open("doctors.txt", ios::out);
    if (docfile.is_open()) {
        d[0].fullname = "Ahmed Adbelaziz"; d[0].acc.username = "ahmed@gmail.com"; d[0].acc.password = "0000"; d[0].di[0].ID = 0;
        d[1].fullname = "Salem Eldossary"; d[1].acc.username = "salem@gmail.com"; d[1].acc.password = "1234"; d[1].di[1].ID = 1;
        d[2].fullname = "Tarek Mohamed"; d[2].acc.username = "tarek@gmail.com"; d[2].acc.password = "7890"; d[2].di[2].ID = 2;
        docfile << d[0].fullname << "\n" << d[0].acc.username << "\n" << d[0].acc.password << "\n" << d[0].di[0].ID << "\n";
        docfile << d[1].fullname << "\n" << d[1].acc.username << "\n" << d[1].acc.password << "\n" << d[1].di[1].ID << "\n";
        docfile << d[2].fullname << "\n" << d[2].acc.username << "\n" << d[2].acc.password << "\n" << d[2].di[2].ID << "\n";
        docfile.close();
    }
}
void p() {
    y[0].name = "Ahmed Shalakany"; y[0].age = 19; y[0].gender = "male"; y[0].acc.username = "ahmed_shalakany"; y[0].acc.password = "12345";
    y[1].name = "Ahmed Yehia"; y[1].age = 19; y[1].gender = "male"; y[1].acc.username = "ahmed_yehia"; y[1].acc.password = "123456";
    y[2].name = "Hazem Atrees"; y[2].age = 18;  y[2].gender = "male"; y[2].acc.username = "hazem_atrees"; y[2].acc.password = "1234567";
    fstream patients;
    patients.open("patients.txt", ios::out);

    if (patients.is_open()) {
        patients << y[0].name << endl << y[0].age << endl << y[0].acc.username << endl << y[0].acc.password << endl << y[0].gender << endl;
        patients << y[1].name << endl << y[1].age << endl << y[1].acc.username << endl << y[1].acc.password << endl << y[1].gender << endl;
        patients << y[2].name << endl << y[2].age << endl << y[2].acc.username << endl << y[2].acc.password << endl << y[2].gender << endl;
        patients.close();
    }
}


void display_disease() {
    for (int i = 0; i < diseaseSize; i++)
    {
        cout << "*" << x[i].title << " " << "its symptoms: ";
        for (int j = 0; j < x[i].symptomsize; j++)
        {
            cout << x[i].symptoms[j] << ",";
        }
        cout << endl;
    }
}
void add_disease() {
    string lower_str = "";
    cout << "Enter disease: " << endl;
    cin.ignore();
    getline(cin, x[diseaseSize].title);
    cout << "Enter ID of disease: " << endl;
    cin >> x[diseaseSize].ID;
    cout << "Enter general information: " << endl;
    cin.ignore();
    getline(cin, x[diseaseSize].general_info);
    /////////////////// to convert input capital text to small text (ahmed_change) //////////////////////////////
    for (int i = 0; i < x[diseaseSize].title.length(); i++) {
        char ch = tolower(x[diseaseSize].title[i]);
        lower_str += ch;
    }
    x[diseaseSize].title = lower_str;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Disease added succesfully!\n";
    diseaseSize++;
}
void  view_p_with_disease() {
    for (int i = 0; i < PatientCounter; i++)
    {
        for (int j = 0; j < his_count; j++)
            for (int k = 0; k < diseaseSize; k++)
            {
                if (y[i].dis_his[j] == x[k].ID)
                {
                    cout << y[i].name << " " << "has disease " << x[k].title << endl;
                }
            }
    }
}
void removeDisease() {
    string lower_str = "";
    string removeD;
    cout << "Enter disease to remove: ";
    cin.ignore();
    getline(cin, removeD);
    /////////////////// to convert input capital text to small text (ahmed_change) //////////////////////////////
    for (int i = 0; i < removeD.length(); i++) {
        char ch = tolower(removeD[i]);
        lower_str += ch;
    }
    removeD = lower_str;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool found = false;
    for (int i = 0; i < diseaseSize; i++)
    {
        if (removeD == x[i].title)
            found = true;
        if (found) {
            if (i != diseaseSize - 1) {
                x[i] = x[i + 1];
            }
            else {
                x[i].symptomsize = 0;
            }
        }
    }
    if (found) {
        diseaseSize--;
        cout << "Disease removed successfully!" << endl;

    }
    else
        cout << "Disease not exist!!" << endl;
}
void add_syp() {
    string lower_str = "";
    cout << "Enter name of disease to add symptom to it: ";
    string addSyp;
    cin.ignore();
    getline(cin, addSyp);
    /////////////////// to convert input capital text to small text (ahmed_change) //////////////////////////////
    for (int i = 0; i < addSyp.length(); i++) {
        char ch = tolower(addSyp[i]);
        lower_str += ch;
    }
    addSyp = lower_str;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (addSyp != x[0].title && addSyp != x[1].title && addSyp != x[2].title) {
        bool exist = false;
        for (int i = 0; i < diseaseSize; i++)//////kan 0
        {
            if (addSyp == x[i].title)
            {
                string lower_str = "";
                exist = true;
                cout << "Enter symptom: ";
                //cin.ignore();
                getline(cin, x[i].symptoms[x[i].symptomsize]);
                /////////////////// to convert input capital text to small text (ahmed_change) //////////////////////////////
                for (int j = 0; j < x[i].symptoms[x[i].symptomsize].length(); j++) {
                    char ch = tolower(x[i].symptoms[x[i].symptomsize][j]);
                    lower_str += ch;
                }
                x[i].symptoms[x[i].symptomsize] = lower_str;
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////
                x[i].symptomsize++;
                break;
            }
        }
        if (exist)
            cout << "Symptom added succesfully!" << endl;
        else
            cout << "Disease not exist!\n";
    }
    else
        cout << "You do not have access!";
}
void removeSyp() {
    string lower_str = "";
    cout << "Enter name of disease to remove symptom from it: ";
    string diseaseremoSyp;
    string sypToRemove;
    cin.ignore();
    getline(cin, diseaseremoSyp);
    /////////////////// to convert input capital text to small text (ahmed_change) //////////////////////////////
    for (int i = 0; i < diseaseremoSyp.length(); i++) {
        char ch = tolower(diseaseremoSyp[i]);
        lower_str += ch;
    }
    diseaseremoSyp = lower_str;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (diseaseremoSyp != x[0].title && diseaseremoSyp != x[1].title && diseaseremoSyp != x[2].title) {
        bool diseaseExist = false;
        bool sypRemoveExsist = false;
        for (int i = 0; i < diseaseSize; i++) {
            if (diseaseremoSyp == x[i].title) {
                string lower_str = "";
                diseaseExist = true;
                cout << "Enter symptom to remove: ";
                //cin.ignore();
                getline(cin, sypToRemove);
                /////////////////// to convert input capital text to small text (ahmed_change) //////////////////////////////
                for (int i = 0; i < sypToRemove.length(); i++) {
                    char ch = tolower(sypToRemove[i]);
                    lower_str += ch;
                }
                sypToRemove = lower_str;
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////
                for (int j = 0; j < x[i].symptomsize; j++)
                {
                    if (sypToRemove == x[i].symptoms[j]) {
                        sypRemoveExsist = true;
                    }
                    if (sypRemoveExsist)
                    {
                        if (j != x[i].symptomsize - 1) {

                            x[i].symptoms[j] = x[i].symptoms[j + 1];
                        }
                        else
                            x[i].symptomsize--;
                    }
                }
                break;
            }
        }
        if (diseaseExist) {
            if (sypRemoveExsist)
                cout << "Symptom successfully removed!\n";
            else
                cout << "Symptom do not exist!\n";
        }
        else {
            cout << "Disease not exsit!\n";
        }
    }
    else
        cout << "You do not have access!";
}
////////////////////////////////////////////////////////4o8l ahmed yehia wa 4alakny//////////////////////////////////////////////////
void menu()
{

    string dis;

    cout << "---------------------------------------------- welcome in patient page -------------------------------------------------\n\n\n";
    cout << "\t\t\t\t\twelcome: " << y[log_in_user_ID].name << endl;
    cout << "\t\t\t\t\t\t************\n";
    cout << "1. Find out your disease based on your symptoms\n\n"; // ayh dah
    cout << "2. Display symptoms for a certain Disease\n\n";
    cout << "3. View diagnosis history\n\n";
    cout << "4. Clear diagnosis history\n\n";
    cout << "5.to log out \n\n";
    cout << "Enter your choice: ";


}
void diagnose()


{
    int count1 = 0;
    int count2 = 0;
    int index = 0;
    int index2 = 0;
    int flag[10]{ 0,0,0,0,0,0,0,0,0,0 };
    string symptom[10];
    cout << "enter 3 symptoms \n";
    for (int l = 0; l < 4; l++) {
        getline(cin, symptom[l]);
    }
    for (int i = 0; i < diseaseSize; i++) {
        for (int k = 0; k < x[i].symptomsize; k++) {
            for (int l = 0; l < 4; l++) {
                if (symptom[l] == x[i].symptoms[k])
                {
                    flag[i] += 1;


                }
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (flag[i] >= 2)
        {
            count2++;
            index2 = i;
        }
        else if (flag[i] == 1)
        {
            count1++;
            index = i;
        }
    }
    if (count2 >= 1)
    {
        cout << "your disease is " << x[index2].title << " with ID " << x[index2].ID << " and it's general information is " << x[index2].general_info << endl;
        for (int i = 0; i < PatientCounter; i++)
        {
            if (username == y[i].acc.username)
            {
                y[i].dis_his[his_count] = x[index2].ID;
                his_count++;

            }

        }

    }
    else if (count1 >= 2)
    {
        cout << "there is many diseases have the same symptoms\n";

    }
    else if (count1 == 1 && count2 == 0)
    {
        cout << "there is no diseases has this symptoms but the nearest disease is " << x[index].title << "with precentage " << (1.0 / 3) * 100 << endl;
        cout << " with ID " << x[index2].ID << " and it's general information is " << x[index2].general_info << endl;
        for (int i = 0; i < PatientCounter; i++)
        {
            if (username == y[i].acc.username)
            {
                y[i].dis_his[his_count] = x[index2].ID;
                \


                his_count++;

            }

        }
    }
    else
    {
        cout << "no matches disease\n";
    }




}

void display_symp() {
    bool s = false;
    string dsymp;
    int index = 0;
    cout << "enter disease to show symptoms: ";
    cin.ignore();
    getline(cin, dsymp);
    for (int i = 0; i < diseaseSize; i++)
    {
        if (dsymp == x[i].title) {
            s = true;
            index = i;

            break;
        }


    }
    if (s) {
        for (int j = 0; j < x[index].symptomsize; j++)
        {
            cout << x[index].symptoms[j] << endl;

        }
    }
    else
        cout << "this disease not exist\n";
}

void view_diagnose_history()
{

    for (int i = 0; i < PatientCounter; i++)
    {
        for (int j = 0; j < his_count; j++)
            for (int k = 0; k < diseaseSize; k++)
            {
                if (username == y[i].acc.username)
                {
                    if (y[i].dis_his[j] == x[k].ID)
                    {
                        cout << x[k].title << endl;
                    }


                }
            }
    }

}
void Clear_diagnosis_history()
{
    for (int i = 0; i < PatientCounter; i++)
    {
        if (username == y[i].acc.username)
        {
            for (int j = 0; j < his_count; j++)
            {
                y[i].dis_his[j] = -1;
            }



            cout << "your history has been deleted  successfully\n";
        }
    }
}
