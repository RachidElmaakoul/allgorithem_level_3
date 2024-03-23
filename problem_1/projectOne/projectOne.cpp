
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
const string clientsFileName = "Clients.txt";
void ShowMainMenue();

// show Client List
struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

vector <string> SpliteString(string str , string Delim){
    vector <string> vString;

    short pos = 0;
    string Word;

    while ((pos = str.find(Delim))  != std::string::npos) {
        
        Word = str.substr(0, pos);
        if (Word != "")
        {
            vString.push_back(Word);
        }
        str.erase(0, pos + Delim.length());
    }
        if (str != "") {
            vString.push_back(str);
        }
        return vString;
}

sClient ConvertLineToRecord(string Line , string speretor = "#//#") {
    vector <string> vString;
    sClient Client;

    vString = SpliteString(Line, speretor);

    Client.AccountNumber = vString[0];
    Client.PinCode = vString[1];
    Client.Name = vString[2];
    Client.Phone = vString[3];
    Client.AccountBalance = stod( vString[4]);

    return Client;
}

string ConvertRecordToLine(sClient Client, string speretor = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + speretor;
    stClientRecord += Client.PinCode + speretor;
    stClientRecord += Client.Name + speretor;
    stClientRecord += Client.Phone + speretor;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

bool ClientExistByAccountNumber(string AccountNumber, string FileName) {
    vector <sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;
        while (getline(MyFile,Line))
        {
            Client = ConvertLineToRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return false;
}

sClient ReadNewClient() {
    sClient Client;
    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistByAccountNumber(Client.AccountNumber, clientsFileName))
    {
        cout << "\n Client with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "Please enter PinCode?  ";
    getline(cin, Client.PinCode);
    cout << "Please enter Name?  ";
    getline(cin, Client.Name);
    cout << "Please enter Phone?  ";
    getline(cin, Client.Phone);
    cout << "please enter Account Balance?  ";
    cin >> Client.AccountBalance;

    return Client;
}

vector <sClient> LoadCleintsDataFromFile(string FileName) {
    vector <sClient> vClients;
    fstream MyFile;

    MyFile.open(FileName, ios::in);//read Mode
    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintClientRecordLine(sClient Client) {
    cout << "|" << setw(15) << left << Client.AccountNumber;
    cout << "|" << setw(10) << left << Client.PinCode;
    cout << "|" << setw(40) << left << Client.Name;
    cout << "|" << setw(12) << left << Client.Phone;
    cout << "|" << setw(12) << left << Client.AccountBalance;
}
void ShowAllClientScreen() {

    vector < sClient > vClients =
    LoadCleintsDataFromFile(clientsFileName);

    cout << "\n\t\t\t\t\t\t Client List(" << vClients.size() << ") Client(s)";

    cout << "\n___________________________________________________";
    cout <<"___________________________________________________\n";
    cout << "|" << setw(15) << left << "AccountNumber";
    cout << "|" << setw(10) << left << "PinCode";
    cout << "|" << setw(40) << left << "UesrName";
    cout << "|" << setw(12) << left << "Phone";
    cout << "|" << setw(12) << left << "AccountBalance";
    cout << "\n______________________________________________________________________________________________________\n";
    
    if (vClients.size() == 0)
    {
        cout << "\t\t\t\t No Clients Available in the system!";
    }
    else
    {
 for (sClient & Client : vClients)
    {
        PrintClientRecordLine(Client);
        cout << endl;
    }
    }
   
    cout << "\n______________________________________________________________________________________________________\n";
    cout << "______________________________________________________________________________________________________\n";

}

void PrintClientCard(sClient Client) {
    cout << "\nThe following are The Client details: \n";
    cout << "------------------------------------";
    cout << "\nAccount number  : " << Client.AccountNumber << endl;
    cout << "pin code        : " << Client.PinCode << endl;
    cout << "user name       : " << Client.Name << endl;
    cout << "phone           : " << Client.Phone << endl;
    cout << "Account balance : " << Client.AccountBalance;
    cout << "\n------------------------------------\n";

}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClient, sClient& Client) {
    for (sClient C : vClient)
    {
        if (C.AccountNumber == AccountNumber) {
            Client = C;
            return true;
        }
    }
    return false;
}

sClient ChangeClientRecord(string AccountNumber) {
    sClient Client;
    Client.AccountNumber = AccountNumber;
    cout << "\n\nplease enter pinCode?  ";
    getline(cin >> ws, Client.PinCode);
    cout << "please enter Username?  ";
    getline(cin, Client.Name);
    cout << "please enter Phone?  ";
    getline(cin, Client.Phone);
    cout << "please enter Account Balance?  ";
    cin >> Client.AccountBalance;

    return Client;
}

bool MarkClientForDeletByAccountNumber(string AccountNumber, vector <sClient>& vClient) {
    for (sClient& C : vClient) {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}
vector <sClient> SaveDataClientToFile(string FileName, vector <sClient> vClient) {
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string DataLine;

    if (MyFile.is_open()) {
        for (sClient C : vClient) {
            if (C.MarkForDelete == false) {
                //we only write records that are not marked for delete.
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClient;
}

void AddDataLineToFile(string FileName , string stDataLine) {

    fstream MyFile;
    MyFile.open(FileName, ios::app | ios::in);
    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;
    }
    MyFile.close();
}

void AddNewClient() {
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(clientsFileName, ConvertRecordToLine(Client));
}

void AddNewClients() {
    char AddMore = 'Y';
    do
    {
        cout << "Adding new Client: \n\n";
        AddNewClient();
        cout << "\n Client Added Successfully, do you want to add more Clients? Y/N? ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClient) {
    sClient Client;
    char answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClient, Client)) {

        PrintClientCard(Client);

        cout << "\n\nAre you sure want delete this Client? y/n ? ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {
            MarkClientForDeletByAccountNumber(AccountNumber, vClient);
            SaveDataClientToFile(clientsFileName, vClient);

            //refresh Clients;
            vClient = LoadCleintsDataFromFile(clientsFileName);

            cout << "\n\nClient Delete Successfully. ";
            return true;
        }
    }
    else
    {
        cout << "\nClient with account Number ( " << AccountNumber << ") is not found!";
        return false;
    }
}

bool UpDateClientByAccountNumbers(string AccountNumber, vector <sClient>& vClient) {
    sClient Client;
    char answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClient, Client)) {

        PrintClientCard(Client);

        cout << "\n\nAre you sure want to Update this Client? y/n ? ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {
            for (sClient& c : vClient)
            {
                if (c.AccountNumber == AccountNumber) {
                    c = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            SaveDataClientToFile(clientsFileName, vClient);
            cout << "\n\nClient UpDate Successfully. ";
            return true;
        }
    }
    else
    {
        cout << "\nClient with account Number ( " << AccountNumber << ") is not found!";
        return false;
    }
}

string ReadClientAccountNumber() {
    string AccountNumber;
    cout << "please enter accountNumber ?  ";
    cin >> AccountNumber;
    return AccountNumber;
}

void ShowDeletClientScreen() {
    cout << "\n-----------------------------\n";
    cout << "\t Delete Client Screen";
    cout << "\n-----------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(clientsFileName);

    string AccountNumber = ReadClientAccountNumber();
    UpDateClientByAccountNumbers(AccountNumber, vClients);
}

void ShowUpDateClientScreen() {
    cout << "\n-----------------------------\n";
    cout << "\t UpDate Client info Screen";
    cout << "\n-----------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(clientsFileName);

    string AccountNumber = ReadClientAccountNumber();
    UpDateClientByAccountNumbers(AccountNumber, vClients);
}

void ShowAddNewClientScreen() {
    cout << "\n-----------------------------\n";
    cout << "\t Add New Client Screen";
    cout << "\n-----------------------------\n";
  
    AddNewClients();
}

void ShowFindClientScreen() {
    cout << "\n-----------------------------\n";
    cout << "\t Find Client Screen";
    cout << "\n-----------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(clientsFileName);
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();

    if (FindClientByAccountNumber(AccountNumber,vClients,Client)) 
        PrintClientCard(Client);
    else
        cout << "\n Client with Account Number [" << AccountNumber << "] is Not Found!";
}

void ShowEndScreen() {
    cout << "\n-----------------------------\n";
    cout << "\t Porgam Ends :-)";
    cout << "\n-----------------------------\n";
}
enum enMainMenueOptions {
    eListClients = 1, eAddNewClient = 2,
    eDeleteClient = 3, eUpDateClient= 4,
    eFindClient = 5, Exit = 6
};

void GoBackToMainMenue() {
    cout << "\n\n Press any key to go back to Main Menue . . .";
    system("pause>0");
    ShowMainMenue();
}

short ReadMainMenueOptions() {
    cout << "Choose what do you want to do? [1 to 6]? ";
    short Choice = 0;
    cin >> Choice;
    return Choice;
}

void PerformMainMenueOptions(enMainMenueOptions MainMenueOption) {

    switch (MainMenueOption)
    {
    case enMainMenueOptions::eListClients:
        system("cls");
        ShowAllClientScreen();
        GoBackToMainMenue();
        break;
    case enMainMenueOptions::eAddNewClient:
        system("cls");
        ShowAddNewClientScreen();
        GoBackToMainMenue();
        break;
    case enMainMenueOptions::eDeleteClient:
        system("cls");
        ShowDeletClientScreen();
        GoBackToMainMenue();
        break;
    case enMainMenueOptions::eUpDateClient:
        system("cls");
        ShowUpDateClientScreen();
        GoBackToMainMenue();
        break;
    case enMainMenueOptions::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;
    case enMainMenueOptions::Exit:
        system("cls");
        ShowEndScreen();
        break;
    }
}

void ShowMainMenue(){
    system("cls");
    cout << "=======================================================\n";
    cout << "\t\t Main Menue Screen\n";
    cout << "=======================================================\n"; 
    cout << "\t [1] Show Client List. \n";
    cout << "\t [2] Add New client. \n";
    cout << "\t [3] UpDate Client. \n";
    cout << "\t [4] Delet Client. \n";
    cout << "\t [5] Find Client. \n";
    cout << "\t [6] Exit. \n";
 
    cout << "=======================================================\n";
    PerformMainMenueOptions((enMainMenueOptions)ReadMainMenueOptions());
}

int main()
{
    ShowMainMenue();

    system("pause>0");
    return 0;
}
