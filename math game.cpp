// math game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int s = 0, c = 0;
enum level{easy = 1 , mideum=2 , hard=3};
enum operation{sum = 1 , sub = 2 , mul=3 , dif = 4};
int takegamerounds()
{

	int rounds;
	do
	{
		cout << "please etner round numbers that you would like to play from 1 to 10 " << endl;
		cin >> rounds;
		
	}while (rounds < 0 || rounds>10);
	return rounds;
}

int randomnumber1(int from, int to)
{
	int num = rand() % (to - from + 1) + from;
	return num;

	
}
int randnumber2(int from, int to)
{
	int num2 = rand() % (to - from + 1) + from;
	return num2;
}
int takeoperationlevel()
{
	int operl;
	do
	{
		cout << "please enter operation level : easy (1) , medium (2) , hard (3)" << endl;
		cin >> operl;
		
	} while (operl > 3 || operl < 1);
	return operl;
	cout << endl << endl;
}
int takeoperationtype()
{
	int operk;
	do {
		
		cout << "note this calculator make automaticilly round for example if you divide 10 / 3 the result = 5 and Fractions will removed " << endl << endl;
		cout << "please enter operation type : + (1) , - (2) , * (3) , / (4)" << endl;
		cin >> operk;
		
	} while (operk > 4 || operk < 1);
	return operk;

	cout << endl << endl;
}
void printoperationforplayingandcheck(int k , int v)
{
	int result;
	if (k == level::easy&&v==operation::sum)
	{
		int oper1 = randomnumber1(10, 20);
		int oper2 = randnumber2(10, 20);
		cout << "enter the result of this operation : " << oper1 << "+" << oper2<<endl;
		cin >> result;
		int x = oper1 + oper2;
		
		if (result == x)
		{
			cout << "your result is correct " << endl;
			system("color 2F");
			s++;
		}
		else
		{
			cout << "your result is wrong " << endl;
			system("color 4F");
			cout << "\a";
			cout << "correct answer is " << x << endl;
			c++;
		}
	}
	
	else if (k == level::easy && v == operation::sub)
	{
		int oper1 = randomnumber1(10, 20);
		int oper2 = randnumber2(10, 20);
		cout << "enter the result of this operation : " << oper1 << "-" << oper2<<endl;
		cin >> result;
		int x = oper1 - oper2;

		
		if (result == x)
		{
			cout << "your result is correct " << endl;
			system("color 2F");
			s++;
		}
		else
		{
			cout << "your result is wrong " << endl;
			system("color 4F");
			cout << "\a";
			cout << "correct answer is " << x << endl;
			c++;
		}
	}
	else if (k == level::easy && v == operation::mul)
	{
		int oper1 = randomnumber1(10, 20);
		int oper2 = randnumber2(1, 10);
		cout << "enter the result of this operation : " << oper1 << "*" << oper2<<endl;
		cin >> result;
		int x = oper1 * oper2;

		
		if (result == x)
		{
			cout << "your result is correct " << endl;
			system("color 2F");
			s++;
		}
		else
		{
			cout << "your result is wrong " << endl;
			system("color 4F");
			cout << "\a";
			cout << "correct answer is " << x << endl;
			c++;
		}
	}
	else if (k == level::easy && v == operation::dif)
	{
		int oper1 = randomnumber1(10, 20);
		int oper2 = randnumber2(10, 20);
		cout << "enter the result of this operation : " << oper1 << "/" << oper2<<endl;
		cin >> result;
		int x = oper1 /oper2;

		
		if (result == x)
		{
			cout << "your result is correct " << endl;
			system("color 2F");
			s++;
		}
		else
		{
			cout << "your result is wrong " << endl;
			system("color 4F");
			cout << "\a";
			cout << "correct answer is " << x << endl;
			c++;

		}
	}
	else if (k == level::mideum && v == operation::sum)
	{
		int oper1 = randomnumber1(50, 150);
		int oper2 = randnumber2(35, 90);
		cout << "enter the result of this operation : " << oper1 << "+" << oper2 << endl;
		cin >> result;
		int x = oper1 + oper2;

		
		if (result == x)
		{
			cout << "your result is correct " << endl;
			system("color 2F");
			s++;
		}
		else
		{
			cout << "your result is wrong " << endl;
			system("color 4F");
			cout << "\a";
			cout << "correct answer is " << x << endl;
			c++;
		}

	}
	else if (k == level::mideum && v == operation::sub)
	{
		int oper1 = randomnumber1(30, 180);
		int oper2 = randnumber2(10 , 65);
		cout << "enter the result of this operation : " << oper1 << "-" << oper2<<endl;
		cin >> result;
		int x = oper1 - oper2;
		if (result == x)
		{
			cout << "your result is correct " << endl;
			system("color 2F");
			s++;
		}
		else
		{
			cout << "your result is wrong " << endl;
			system("color 4F");
			cout << "\a";

			cout << "correct answer is " << x << endl;
			c++;
		}
	}
	else if (k == level::mideum && v == operation::mul)
	{
		int oper1 = randomnumber1(30, 180);
		int oper2 = randnumber2(1 , 10);
		cout << "enter the result of this operation : " << oper1 << "*" << oper2 << endl;
		cin >> result;
		int x = oper1 * oper2;
		if (result == x)
		{
			cout << "your result is correct " << endl;
			system("color 2F");
			s++;
		}
		else
		{
			cout << "your result is wrong " << endl;
			system("color 4F");
			cout << "\a";

			cout << "correct answer is " << x << endl;
			c++;
		}
		}
	else if (k == level::mideum && v == operation::dif)
	{
		int oper1 = randomnumber1(50, 100);
		int oper2 = randnumber2(1, 10);
		cout << "enter the result of this operation : " << oper1 << "/" << oper2 << endl;
		cin >> result;
		int x = oper1 / oper2;
		if (result == x)
		{
			cout << "your result is correct " << endl;
			system("color 2F");
			s++;
		}
		else
		{
			cout << "your result is wrong " << endl;
			system("color 4F");
			cout << "\a";

			cout << "correct answer is " << x << endl;
			c++;
		}
		}
	else if (k == level::hard && v == operation::sum)
	{
		int oper1 = randomnumber1(17, 97);
		int oper2 = randnumber2(7, 291);
		cout << "enter the result of this operation : " << oper1 << "+" << oper2 << endl;
		cin >> result;
		int x = oper1 + oper2;
		if (result == x)
		{
			cout << "your result is correct " << endl;
			system("color 2F");
			s++;
		}
		else
		{
			cout << "your result is wrong " << endl;
			system("color 4F");
			cout << "\a";

			cout << "correct answer is " << x << endl;
			c++;
		}
		}

	else if (k == level::hard && v == operation::sub)
	{
		int oper1 = randomnumber1(190 , 369);
		int oper2 = randnumber2(90 , 239);
		cout << "enter the result of this operation : " << oper1 << "-" << oper2 << endl;
		cin >> result;
		int x = oper1 - oper2;

		if (result == x)
		{
			cout << "your result is correct " << endl;
			system("color 2F");
			s++;
		}
		else
		{
			cout << "your result is wrong " << endl;
			system("color 4F");
			cout << "\a";

			cout << "correct answer is " << x << endl;
			c++;
		}
		}

	else if (k == level::hard && v == operation::mul)
	{
		int oper1 = randomnumber1(19, 39);
		int oper2 = randnumber2(1 , 39);
		cout << "enter the result of this operation : " << oper1 << "*" << oper2 << endl;
		cin >> result;
		int x = oper1 * oper2;
		if (result == x)
		{
			cout << "your result is correct " << endl;
			system("color 2F");
			s++;
		}
		else
		{
			cout << "your result is wrong " << endl;
			system("color 4F");
			cout << "\a";

			cout << "correct answer is " << x << endl;
			c++;
		}
		}

	else if (k == level::hard && v == operation::dif)
	{
		int oper1 = randomnumber1(198 , 565);
		int oper2 = randnumber2(1 , 110);
		cout << "enter the result of this operation : " << oper1 << "/" << oper2 << endl;
		cin >> result;
		int x = oper1 / oper2;
		if (result == x)
		{
			cout << "your result is correct " << endl;
			system("color 2F");
			s++;
		}
		else
		{
			cout << "your result is wrong " << endl;
			system("color 4F");
			cout << "\a";

			cout << "correct answer is " << x << endl;
			c++;
		}
		}
	else
		cout << "math error " << endl;








}
void printfrequencyround(int g)
{
	for (int a = 1; a <= g; a++)
	{
		int level = takeoperationlevel();
		int type = takeoperationtype();
		printoperationforplayingandcheck(level, type);
		cout << "------------------------------------------------------------------\n\n";
	}
}
void gameover(int o)
{
	cout << "\t\t-----------------------------------------------------------------\t\t\n\n";
	cout << "\t\t\t\t\t ++game over++\t\t\t\t\t\t " << endl << endl;;
	cout << "\t\t-----------------------------------------------------------------\t\t\n\n";
	cout << "\t\t---------------------------[ game result : ]--------------------------------------\t\t\n\n";
	cout << "\t\t\tgame round : \t" << o << endl << endl;
	cout << "\t\tyou answered correctly " << s << " times " << endl;
	cout << "\t\tyou answered wrong " << c << " times " << endl;
	if (s > c)
	{
		cout << "you won in this rond game " << endl;
	}
	else
	{
		cout << "you losed in this round game " << endl;
	}
	cout << endl << endl;


}
char playagain()
{
	char play;
	cout << "do you want to play again " << endl;
	cin >> play;
	return play;
}
void startgame()
{
	char again;
	do

	{

		s = 0, c = 0;
		system("cls");
		system("color 0F");

		int x = takegamerounds();
		printfrequencyround(x);
		gameover(x);

		again = playagain();
	} while (again == 'y' || again == 'Y');
}

int main()
{
	srand((unsigned)time(NULL));
	startgame();

	
  
}

