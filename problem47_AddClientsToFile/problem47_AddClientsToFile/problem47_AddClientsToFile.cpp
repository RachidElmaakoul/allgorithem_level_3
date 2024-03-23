
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const string clientsFileName = "Clients.txt";

struct InfoClient {
    string AccountNumber;
    string PinCode;
    string UserName;
    string phone;
    double AccountBalance;
};
InfoClient ReadClient() {
    InfoClient Client;
cout << "\nplease enter acount number?  ";
// Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.AccountNumber); 
    cout << "please enter pinCode?  ";
    getline(cin, Client.PinCode);  
    cout << "please enter Username?  ";
    getline(cin, Client.UserName);  
    cout << "please enter Phone?  ";
    getline(cin, Client.phone); 
    cout << "please enter Account Balance?  ";
    cin >> Client.AccountBalance;
    
    return Client;
}

string ConvertoLine(InfoClient Client , string speretor = "#\\#") {
    string OneLine;

    OneLine += Client.AccountNumber + speretor;
    OneLine += Client.PinCode + speretor;
    OneLine += Client.UserName + speretor;
    OneLine += Client.phone + speretor;
    OneLine += to_string(Client.AccountBalance);
    return OneLine;
}
void addDataLineToFile(string FileName , string stDataLine) {
   
     fstream MyFile;
     MyFile.open(FileName, ios::app | ios::out);

    if (MyFile.is_open()){
         MyFile << stDataLine << endl;
         MyFile.close();
    }
}

void AddNewClient() {
    InfoClient Clients;
    Clients = ReadClient();
    addDataLineToFile(clientsFileName, ConvertoLine(Clients));
}

void AddClients() {
    char AddMore = 'y';
    do
    {
        system("cls");
        cout << "Adding More Clients? \n\n";
        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";   
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
}
int main()
{



    AddClients();



    system("pause>0");
    return 0;
}
