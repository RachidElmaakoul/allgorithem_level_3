
#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
using namespace std;

struct stMyInfo {
    string AccountNumber;
    int pinCode;
    string Username;
    string Phone;
    double AccountBalance;
};

stMyInfo GetInfo() {
    stMyInfo Info;
    cout << "please enter client data : \n\n";
    cout << "\nEnter Account Number? : ";
    cin >> Info.AccountNumber;

    cout << "\nEnter PinCode ? : ";
    cin >> Info.pinCode;

    cout << "\nEnter Name? : ";
    cin.ignore(1, '\n');
    getline(cin,Info.Username);

    cout << "\nEnter Phone? : ";
    cin >> Info.Phone;

    cout << "\nEnter Acount balance? : ";
    cin >> Info.AccountBalance;
    return Info;
}

void PrintInfo(stMyInfo Info) {
    string hash = "#//#";
    cout << "\n\n\n Client Record for Saving is : \n ";
    cout << Info.AccountNumber << hash << Info.pinCode << hash
        << Info.Username << hash << Info.Phone << hash  ;
    printf("%.4f", Info.AccountBalance);
}
//method abo-hadhoud

struct stClient {
    string AccountNumber;
    string pinCode;
    string Username;
    string Phone;
    double AccountBalance;
};

stClient GetInfoClient() {
    stClient Client;
    cout << "\n\nplease enter client data : \n\n";
    cout << "\nEnter Account Number? : ";
    getline(cin,Client.AccountNumber);

    cout << "\nEnter PinCode ? : ";
    getline(cin, Client.pinCode);

    cout << "\nEnter Name? : ";
    getline(cin, Client.Username);

    cout << "\nEnter Phone? : ";
    getline(cin, Client.Phone);

    cout << "\nEnter Acount balance? : ";
    cin >> Client.AccountBalance;
    return Client;
}

string ConvertRecordToLine( stClient Client,string sperator = "#//#") {
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + sperator;
    stClientRecord += Client.pinCode + sperator;
    stClientRecord += Client.Username + sperator;
    stClientRecord += Client.Phone + sperator;
    stClientRecord += to_string(Client.AccountBalance) ;

    return stClientRecord;
}


int main()
{
    PrintInfo(GetInfo());

    stClient Client;
    Client = GetInfoClient();

    cout << "\n\n\n Client Record for Saving is : \n ";
    cout <<  ConvertRecordToLine(Client);
    system("\n\npause>0");
}
