#include <iostream>
#include <string>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
const string FileName = "Ali.txt";
//**********************Structs**************************************
struct sClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

//**********************Read Parametrs*******************************
sClient ReadsClient() {
	sClient Client1;

	cout << "Pleas Enter Client data : \n";


	cout << "\nPlease ,Enter Your AccountNumber :\n";
	getline(cin>>ws, Client1.AccountNumber);

	cout << "\nPlease ,Enter Your PinCode :\n";
	getline(cin, Client1.PinCode);

	cout << "\nPlease ,Enter Your Name :\n";
	getline(cin, Client1.Name);

	cout << "\nPlease ,Enter Your Phone:\n";
	getline(cin, Client1.phone);

	cout << "\nPlease ,Enter Your AccountBalance :\n";
    cin>> Client1.AccountBalance;

	cout << "\n\n";
	return Client1;
}
string ReadString() {
	string S1;
	cout << "\nPlease inter your string : \n";
	getline(cin, S1);
	return S1;
}
char ReadChar() {
	char Ch1;
	cout << "\nPleas enter a character :\n";
	cin >> Ch1;
	return Ch1;
}

//**********************Print Functions******************************
void PrintRecordData(sClient Client) {
	cout << "|" << setw(15) << Client.AccountNumber;
	cout << "|" << setw(15) << Client.PinCode;
	cout << "|" << setw(15) << Client.Name;
	cout << "|" << setw(15) << Client.phone;
	cout << "|" << setw(15) << Client.AccountBalance;
	cout << "\n------------------------------------------------------------------------------\n";
}
void PrintAllClientData(vector<sClient> vClient) {
	cout << "\n------------------------------------------------------------------------------\n";
	cout << "\n\t\t\tclient list (" << vClient.size() << ") client(s)\n";
	cout << "\n------------------------------------------------------------------------------\n";
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(15) << "Pin Code";
	cout << "| " << left << setw(15) << "Client Name";
	cout << "| " << left << setw(15) << "Phone";
	cout << "| " << left << setw(15) << "Balance";
	cout <<		"\n______________________________________________________________________________\n";
	for (int i = 0; i < vClient.size(); i++) {
		PrintRecordData(vClient[i]);
		cout << endl;
	}

}
void PrintClient(sClient Client) {


	cout << "\n\nThe following is the extracted client record:\n";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nName : " << Client.Name;
	cout << "\nPhone : " << Client.phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;

}

//**********************Functions***********************************
char InvertLetterCase(char ch) {
	return isupper(ch) ? tolower(ch) : toupper(ch);
}
int Counter(string S1, char Ch1, bool MatchCase = true) {
	int Counter = 0;
	for (int  i = 0; i < S1.length(); i++) {
	if (MatchCase) {
		if (S1[i] == Ch1)
			Counter++;
	}
	else {
		if (tolower(S1[i]) == tolower(Ch1))
			Counter++;
	}
	}
	return Counter;
}
bool IsVowel(char Ch1) {
	Ch1 = tolower(Ch1);
	return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'i' || Ch1 == 'o' || Ch1 == 'u');
}
short  CountVowels(string S1) {
	short Count = 0;
	for (int  i = 0; i < S1.length(); i++) {
		if ( IsVowel(S1[i]))
			Count++;
	}
	return Count;
}
void  WriteVowels(string S1) {
	for (int i = 0; i < S1.length(); i++) {
		if(IsVowel(S1[i])) cout<<S1[i]<<"\t";
	}
}
void WordString(string S1) {
	string delim = " ";
	string S2;
	short pos;
		while ((pos = S1.find(delim)) != std::string::npos) {
			S2 = S1.substr(0, pos);
			if (S2 != "") {
				cout << S2 << "\n";
			}
			S1.erase(0, pos + delim.length());
	}
		if (S1 != "") {
			cout << S1 << "\n";
		}
}
short NumberWordString(string S1) {
	string delim =" ";
	short count = 0;
	short pos=0;
	string S2;
	while ((pos = S1.find(delim)) != std::string::npos) {
		S2 = S1.substr(0, pos);
		if (S2 != "")
		count++;
		S1.erase(0, pos + delim.length());
	}
	if (S1 != "")
		count++;

		return count;
}
vector<string> SplitTokenInVector(string S1,string delim="#\\#") {
	string S2;
	vector<string> V1;
	short pos = 0;
	while ((pos = S1.find(delim)) != std::string::npos) {
		S2 = S1.substr(0, pos);
		if (S2 != "")
			V1.push_back(S2);
		S1.erase(0, pos + delim.length());
	}
	if (S1 != "")
		V1.push_back(S1);
	return V1;
}
void PrintTokens(vector<string>V1) {
	for (string &	a : V1) {
		cout << a << endl;
	}
}
string TirmLeft(string S1) {
	for (int i = 0; i < S1.length(); i++){

		if (S1[i] != ' ')
			return S1.substr(i, S1.length() - i);
	}
	return "";
}
string TirmRight(string S1) {
	for (int i = S1.length()-1; i >=0; i--) {

		if (S1[i] != ' ')
			return S1.substr(0,i+1);
	}
	return "";
}
string Tirm(string S1) {
	string S2 = TirmLeft(TirmRight(S1));

	return S2;
}
string joinString(vector<string>V1, string delim) {
	string S1;
	for (string& s : V1) {
		S1+=s+ delim;
	}
	return S1.substr(0,S1.length()-delim.length());

}

string joinString(string arr[], int length, string delim) {
	string S1;
	for (int i = 0; i < length; i++) {
		S1 += arr[i] + delim;
	}
	return S1.substr(0, S1.length() - delim.length());
}
string ReversString(string S1) {
	vector<string> V1;
	V1 = SplitTokenInVector(S1, " ");
	vector<string>::iterator iter = V1.end();
	string S2;
	while (iter != V1.begin()) {
		--iter;
		S2 += *iter + " ";

	}
	return S2.substr(0,S2.length()-1);
}
string ReplaceWordWithReplaceFunction(string S1, string From, string To) {
	short pos=0;
	while ((pos = S1.find(From)) != std::string::npos) {
		S1=S1.replace(pos, To.length(), To);
	}
	return S1;
}
string TolowerString(string S1) {
	for (int i = 0; i < S1.length(); i++) {
		S1[i] = tolower(S1[i]);
	}
	return S1;
}
string ReplaceWithMatchCase(string S1, string From, string To,bool MatchCase=true) {
	vector<string>V1 = SplitTokenInVector(S1, " ");
	for (string& S : V1) {
		if (MatchCase) {
		if (S == From) {
			S = To;
		}

		}
		else {
			if (TolowerString(S) == TolowerString(From))
				S = To;
		}
	}
	return joinString(V1, " ");
}
string RemoveThePanctuationFromTheString(string S1) {
	string S2 = "";
	for (int i = 0; i < S1.length(); i++) {
		if (!ispunct(S1[i]))
			S2 += S1[i];
	}
	return S2;
}
string StructToString(sClient Client1,string delim="#\\#") {
	string S1;
	S1 += Client1.AccountNumber + delim;
	S1 += Client1.PinCode + delim;
	S1 += Client1.Name + delim;
	S1 += Client1.phone + delim;
	S1 += to_string(Client1.AccountBalance);
	return S1;
}
sClient StringTOStruct(string S1, string delim="#\\#") {

	sClient Client1;
	vector<string> V1=SplitTokenInVector(S1,delim);
	Client1.AccountNumber = V1[0];
	Client1.PinCode = V1[1];
	Client1.Name = V1[2];
	Client1.phone = V1[3];
	Client1.AccountBalance = stod(V1[4]);

	return Client1;


}
void AddDataLineInFile(string FileName,string S1) {
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open()) {
		MyFile << S1 << endl;
		MyFile.close();
	}
}
void AddNewClient() {
	sClient Client = ReadsClient();
	string S1 = StructToString(Client);
	AddDataLineInFile("Ali.txt", S1);
}
vector<sClient>  ReadClientFromFile(string FileName) {
	vector<sClient> vClient;
	string S1;
	fstream MyFile;
	sClient Client;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		while (getline(MyFile, S1)) {
			Client = StringTOStruct(S1);
			vClient.push_back(Client);
		}
		MyFile.close();
	}
	return vClient;
}
bool SearchWithAccountNumber( string S1,vector<sClient>&vClient,sClient &Client) {
	
	for (sClient& S : vClient) {
		if (S.AccountNumber == S1) {
			Client = S;
			return true;
		}
	}
	return false;
}

bool MarkForDeleteWithAccountNumber(vector<sClient> &vClient,string S1) {
	for (sClient& Client : vClient) {
		if (Client.AccountNumber == S1) {
			Client.MarkForDelete = true;
			return true;
		}
	}
	return false;
}
vector <sClient> SaveClientsDataToFile(vector<sClient> vClient, string AccountNumber) {
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	string DataLine;
	if (MyFile.is_open()) {
		for (sClient& S: vClient) {
			if (S.MarkForDelete == false) {
				DataLine = StructToString(S);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vClient;
}
void DeletClientByAccounNumber(string AccountNumber,vector<sClient> vClient) {
	sClient Client;
	char Answer = 'n';
	if (SearchWithAccountNumber(AccountNumber,vClient,Client)) {
		PrintClient(Client);
		cout << "\n\nDo you want to delet the account : \n";
		cin >> Answer;
		if (towlower(Answer)=='y') {
			MarkForDeleteWithAccountNumber(vClient, AccountNumber);
			vClient =SaveClientsDataToFile(vClient, AccountNumber);
			cout << "\n\nClient Deleted Successfully.";
	
		}
		else {
			cout << "to my foot :) \n";
		}

	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber<< ") is Not Found!";
	}
}
int main() {

	sClient Client;
	string AccountNumber = ReadString();
	vector<sClient> vClient = ReadClientFromFile(FileName);
	
	DeletClientByAccounNumber(AccountNumber, vClient);

	
}

