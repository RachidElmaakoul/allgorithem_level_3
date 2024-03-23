
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
const string ClientFileName = "Client.txt";

struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

vector <string> SplitString(string S1, string Delim) {
    vector<string> vString;
    short pos = 0;
    string sWord;// define a string variable  
    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word 
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "") {
        vString.push_back(S1); // it adds last word of the string.  
    }
    return vString;
}



sClient ConvertLinetoRecord(string Line, string Seperator = "#//#") { //this spererator should be same in the file if can't same the program get bug
    sClient Client;

    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double
    return Client;
}
string ConvertRecordToLine(sClient Client , string speretor = "#//#") {
    string stClientRecord = "";
     stClientRecord += Client.AccountNumber + speretor;
     stClientRecord += Client.PinCode + speretor;
     stClientRecord += Client.Name + speretor;
     stClientRecord += Client.Phone + speretor;
     stClientRecord  += to_string( Client.AccountBalance) ;

     return stClientRecord;
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
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}



void PrintClientRecord(sClient Client) {
    cout << "\nThe following are the client details:\n";
    cout << "\nAccount number  : " << Client.AccountNumber << endl;
    cout << "pin code        : " << Client.PinCode << endl;
    cout << "user name       : " << Client.Name << endl;
    cout << "phone           : " << Client.Phone << endl;
    cout << "Account balance : " << Client.AccountBalance;
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
bool MarkClientForDeletByAccountNumber(string AccountNumber , vector <sClient>& vClient) {
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

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClient) {
    sClient Client;
    char answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClient, Client)) {

        PrintClientRecord(Client);

        cout << "\n\nAre you sure want delete this Client? y/n ? ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {
            MarkClientForDeletByAccountNumber(AccountNumber, vClient);
            SaveDataClientToFile(ClientFileName, vClient);

            //refresh Clients;
            vClient = LoadCleintsDataFromFile(ClientFileName);

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


string ReadClientAccountNumber() {
    string AccountNumber = "";
    cout << "please enter Account Number you Looking for?\n";
    cin >> AccountNumber;
    return AccountNumber;
}


int main()
{
    vector <sClient> vClient = LoadCleintsDataFromFile(ClientFileName);
    string AccountNumber = ReadClientAccountNumber();
       
    DeleteClientByAccountNumber(AccountNumber, vClient);

    system("pause>0");
    return 0;
}
