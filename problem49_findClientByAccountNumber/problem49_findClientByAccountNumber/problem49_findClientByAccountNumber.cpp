
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std; 
const string ClientFileNAme = "Clients.txt";

struct sClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
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



sClient ConvertLinetoRecord(string Line, string Seperator = "#\\#") { //this spererator should be same in the file if can't same the program get bug
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

bool FindClientByAccountNumber(string AccountNumber , sClient & Client ) {
    vector <sClient> vClient = LoadCleintsDataFromFile(ClientFileNAme);

    for (sClient  C : vClient)
    {
       
        if (C.AccountNumber == AccountNumber) {
            Client = C;
            return true;
        }
            
    }
    return false;
}
string ReadClientAccountNumber() {
    string AccountNumber = "";
    cout << "please enter Account Number you Looking for?\n";
    cin >> AccountNumber;
    return AccountNumber;

}

int main()
{
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientRecord(Client);
    }
    else
    {
        cout << "Client with AccountNumber (" << AccountNumber << ") is not found?";
    }


	system("pause>0");
	return 0;
}
