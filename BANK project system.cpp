#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;
enum { show = 1 , add = 2 , Delete = 3 , update = 4 , find = 5  , Exit = 6};
struct client
{
	string accountnumber;
	int pincode;
	string name;
	
	
	string phone;
	double accountbalance;
};
int mainmenuscreen();
void putallfilewordsinvector(vector<string>&, string);
void putallstringvectorelementsinstructvector(vector<string>&, vector<client>&);
void showclientlist(vector<client>& myvec3);
void addnewclient(vector<client>&);
void putwveryvectorelementsinfile(string, vector <client>&);
void deleteclient(vector<client>&, vector<client>&);
void updateclientinfo(vector<client>& , vector<client>&);
void findclientdetails(vector<client>& );
void dowhatuserwant(vector<client>&, string);

int main()
{
	
	vector<client>myvec3;
	dowhatuserwant(myvec3, "BANK.txt");

	
	return 0;
}
int mainmenuscreen()
{
	cout << "==========================================================\n";
	cout << setw(35) << "main menu screen \n";
	cout << "============================================================\n";
	cout << setw(15) << " [1] show client list \n";
	cout << setw(10) << " [2] add new client \n";
	cout << setw(15) << " [3] delete client \n";
	cout << setw(15) << " [4] update client info \n";
	cout << setw(17) << "[5] find client\n";
	cout << setw(11) << "[6] exit \n";
	cout << "============================================================\n";
	cout << endl << endl;
	int operators;
	cout << "what do you want to do in this program please choose from 1 to 6 " << endl;
	cin >> operators;
	return operators;

}
void putallfilewordsinvector(vector<string>& myvec , string filename)
{
	fstream file;
	file.open(filename, ios::in);
	string x;
	string t;
	if (file.is_open())
	{
		while (getline(file, x))
		{
			for (int a = 0; a < x.size(); a++)
			{
				if (x[a] != '/')
				{
					t = t + x[a];
				}
				else
				{
					myvec.push_back(t);
					t = "";
				}
			}
			if (t != "")
			{
				myvec.push_back(t);
				t = "";
			}
			
		}
	}
}
void putallstringvectorelementsinstructvector(vector<string>& myvec1, vector<client>&myvec3)
{
	client myclient;
	for (int a = 0; a < myvec1.size(); a += 5)
	{
		if (a + 4 >= myvec1.size())
		{
			break;
		}
		myclient.accountnumber = myvec1[a];
		myclient.name = myvec1[a + 2];
		myclient.phone = myvec1[a + 3];
		try
		{
			myclient.pincode = stoi(myvec1[a + 1]);

			myclient.accountbalance = stod(myvec1[a + 4]);
		}
		catch (...)
		{
			continue;
		}
		myvec3.push_back(myclient);
	}

}
void showclientlist(vector<client>& myvec3)
{
	cout << setw(25)<<"client number : " << myvec3.size() << endl<<endl;
	for (client d : myvec3)
	{
		cout << "client account number  : " << d.accountnumber << endl;

		cout << "client pin code: " << d.pincode << endl;

		cout << "client name: " << d.name << endl;

		cout << "client phone: " << d.phone<< endl;

		cout << "client account balance : " << d.accountbalance << endl;
		cout << endl << endl;
	}
}
void addnewclient(vector<client>& myvec3)
{
	client addnew;
	char Opinion;
	cout << "do you want to add more client if yes please enter y " << endl;
	cin >> Opinion;
	
	if (Opinion == 'y' || Opinion == 'Y')
	{
		
		string nam, phon, accountnum;
		int pin;
		double balance;
		cout << "please enter client account number " << endl;
		
		cin >> accountnum;
		if (cin.fail())
		{
			cin.ignore();
			cin.clear();
		}
		cout << endl << endl;
	
		cout << "please enter client pin code " << endl;
		cin >> pin;
		if (cin.fail())
		{
			cin.ignore();
			cin.clear();
		}
		

		cout << endl << endl;
		cout << "please enter cliant name" << endl;
		cin.ignore();
		getline(cin, nam);
		if (cin.fail())
		{
			cin.ignore();
			cin.clear();
		}

		cout << endl << endl;
		cout << "please enter client phone " << endl;
		cin >> phon;
		if (cin.fail())
		{
			cin.ignore();
			cin.clear();
		}

		cout << endl << endl;
		cout << "please enter client account balance  " << endl;
		cin >> balance;
		if (cin.fail())
		{
			cin.ignore();
			cin.clear();
		}
		cin.ignore();
		addnew.name = nam;
		addnew.accountnumber = accountnum;
		addnew.phone = phon;
		addnew.pincode = pin;
		addnew.accountbalance = balance;
		cout << "new client was added" << endl << endl;
		myvec3.push_back(addnew);

	}

	

}
void putwveryvectorelementsinfile( vector<client>& myvec3 , string filename)
{
	fstream file;
	file.open(filename, ios::out);
	if (file.is_open())
	{
		for (client a : myvec3)
		{
			file << a.accountnumber << '/' << a.pincode << '/' << a.name << '/' << a.phone << '/' << a.accountbalance;
			file << endl << endl;
		}
	}
}
void deleteclient(vector<client>& myvec3 , vector<client>&myvec4)
{
	string number;
	cout << "please enter client account number that you want to delete from file " << endl;
	cin >> number;
	for (client e : myvec3)
	{
		if (e.accountnumber == number)
		{
			continue;
		}
		else
		{
			myvec4.push_back(e);
		}
	}
	myvec3 = myvec4;
	cout << "client deleted succsesfully " << endl << endl;
}
void updateclientinfo(vector<client>& myvec3, vector<client>& myvec5)
{
	string number;
	cout << "please enter client account number that you want to update his details " << endl;
	cin >> number;
	for (client u : myvec3)
	{
		if (u.accountnumber == number)
		{
			
			
			
				string nam, phon;
				int pin;
				double balance;
		

				cout << "please enter client pin code " << endl;
				cin >> pin;
				if (cin.fail())
				{
					cin.ignore();
					cin.clear();
				}
				cin.ignore();
				u.pincode = pin;
				cout << endl << endl;
				cout << "please enter cliant name";
				getline(cin, nam);
				
				if (cin.fail())
				{
					cin.ignore();
					cin.clear();
				}
				u.name = nam;

				cout << endl << endl;
				cout << "please enter client phone " << endl;
				cin >> phon;
				if (cin.fail())
				{
					cin.ignore();
					cin.clear();
				}
				u.phone = phon;

				cout << endl << endl;
				cout << "please enter client account balance  " << endl;
				cin >> balance;
				if (cin.fail())
				{
					cin.ignore();
					cin.clear();
				}
				u.accountbalance = balance;
				myvec5.push_back(u);
				cout << "client data was updated " << endl << endl;
		}
		else
		{
			myvec5.push_back(u);
			cout << "account number doesn,t exist " << endl;
		}
		
	}
	myvec3 = myvec5;
	
}
void findclientdetails(vector<client>& myvec3)
{
	string accountnum;
	cout << "please enter client account number that you search for " << endl;
	cin >> accountnum;
	for (client y : myvec3)
	{
		if (y.accountnumber == accountnum)
		{
			cout << "client name : " << y.name << endl;

			cout << "client pin code : " << y.pincode << endl;

			cout << "client phone: " << y.phone << endl;

			cout << "client account balance : " << y.accountbalance << endl;
		}
	}
}
void dowhatuserwant(vector<client>&myvec3, string filename)
{
	int x = mainmenuscreen();

	vector<string>myvec1;
	putallfilewordsinvector(myvec1, filename);
	putallstringvectorelementsinstructvector(myvec1, myvec3);

	do
	{

		vector<client>myvec4;
		vector<client>myvec5;
	
		switch (x)
		{
		case ::show:
		{
			char opi;
			showclientlist(myvec3);
			cout << "do you want to go back to main screen if yes please enter y " << endl;
			cin >> opi;
			if (opi == 'y' || opi == 'Y')
			{
				system("cls");
				x = mainmenuscreen();
			}
			else
			{
				x = 6;
			}
			break;
		}

		case::add:
		{
			addnewclient(myvec3);
			putwveryvectorelementsinfile(myvec3, filename);
			char opi;
			cout << "do you want to go back to main screen if yes please enter y " << endl;
			cin >> opi;
			if (opi == 'y' || opi == 'Y')
			{
				system("cls");
				x = mainmenuscreen();
			}
			else
			{
				x = 6;
			}
			break;
		}
		case::Delete:
		{
			deleteclient(myvec3, myvec4);
			putwveryvectorelementsinfile(myvec3, filename);
			char opi;
			cout << "do you want to go back to main screen if yes please enter y " << endl;
			cin >> opi;
			if (opi == 'y' || opi == 'Y')
			{
				system("cls");
				x = mainmenuscreen();
			}
			else
			{
				x = 6;
			}
			break;
		}
		case::update:
		{
			updateclientinfo(myvec3, myvec5);
			putwveryvectorelementsinfile(myvec3, filename);
			char opi;
			cout << "do you want to go back to main screen if yes please enter y " << endl;
			cin >> opi;
			if (opi == 'y' || opi == 'Y')
			{
				system("cls");
				x = mainmenuscreen();
			}
			else
			{
				x = 6;
			}
			break;
		}
		case::find:
		{
			findclientdetails(myvec3);
			char opi;
			cout << "do you want to go back to main screen if yes please enter y " << endl;
			cin >> opi;
			if (opi == 'y' || opi == 'Y')
			{
				system("cls");
				x = mainmenuscreen();
			}
			else
			{
				x = 6;
			}
			break;
		}
		}

	} while (x != ::Exit);
	
}



