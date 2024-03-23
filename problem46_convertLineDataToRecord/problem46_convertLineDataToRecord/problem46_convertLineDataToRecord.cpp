

#include <iostream>
#include <string>
#include <vector>
using namespace std;
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
    getline(cin, Client.AccountNumber);

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

string ConvertRecordToLine(stClient Client, string sperator = "#//#") {
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + sperator;
    stClientRecord += Client.pinCode + sperator;
    stClientRecord += Client.Username + sperator;
    stClientRecord += Client.Phone + sperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}


vector <string> splitString(string s1, string delim) {
    vector <string> SplitString;
    string word; // defind a string variable 
    short pos = 0;
    // use find() function to get the position of the delimiters
    while ((pos = s1.find(delim)) != std::string::npos)
    {
        word = s1.substr(0, pos);
        if (word != "")
        {
            SplitString.push_back(word);
        }
        s1.erase(0, pos + delim.length()); // erase() until positon and move to next word.
    }
    if (s1 != "")
    {
        //cout << s1 << endl; //it print last word of the string
        SplitString.push_back(s1);
    }
    return SplitString;
}

//method abu-hadhoud
struct sClient {
    string AccountNumber;
    string pinCode;
    string Username;
    string Phone;
    double AccountBalance;
};

sClient ConvertLinetoRecord(string Line, string sperator = "#//#") {
    sClient Client;
    vector <string> vClientData;
    vClientData = splitString(Line, sperator);

    Client.AccountNumber = vClientData[0];
    Client.pinCode = vClientData[1];
    Client.Username = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

void  PrintClientRecord(sClient Client) {
    cout << "\n\nThe following is the extracted client record:\n";  
    cout << "\nAccout Number  : " << Client.AccountNumber;  
    cout << "\nPin Code       : " << Client.pinCode;   
    cout << "\nName           : " << Client.Username;    
    cout << "\nPhone          : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}
int main()
{
    // if wanna get info static
    string line = "A123#//#5468#//#rachid el maakoul#//#0655226018#//#5000";
    cout << line << "\n\n";

 // if wanna get info from user
 //stClient Client;
 //Client = GetInfoClient();
 //string s1 = ConvertRecordToLine(Client);
 //cout << endl <<  s1 << "\n\n\n";


    vector <string> vstring;
    vstring = splitString(line, "#//#");
        cout << " Acount number  : " << vstring.at(0) << endl;
        cout << " pin Code       : " << vstring.at(1) << endl;
        cout << " user name      : " << vstring.at(2) << endl;
        cout << " phone          : " << vstring.at(3) << endl;
        cout << " Acount balanec : " << vstring.at(4) << endl;
    
//method abu-hadhoud

   sClient client = ConvertLinetoRecord(line);
   PrintClientRecord(client);

   system("pause>0");
        return 0;
}

