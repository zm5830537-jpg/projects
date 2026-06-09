// project 1 stone _ paper - scissor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int c = 0;
int s = 0;
enum equipments { stone = 1, paper = 2, scissor = 3 };
int roundgame()
{
    int takeround;
    cout << "please etner game rounds that you want to play with computer " << endl;
    cin >> takeround;
    return takeround;
}
int TakeTypeOfEquipmentThatUserWouldToLikeToPlay()
{

    int e;
    do {
        equipments Equipment;
        cout << "please etner the equipment that you would like to play stone [1] , paper [2] , scissor [3] " << endl;
        cin >> e;
        if (e == equipments::stone || e == equipments::paper || e == equipments::scissor)
            return e;
    } while (e <= 3);

}
int makethecomputerplay()
{

    int l;

    l = rand() % (3 - 1 + 1) + 1;
    return l;


}
void printcomputerchoice(int k)
{
    cout << "the computer chose " << k << endl;
    cout << endl << endl;
}

void checkwhoisthewinner(int user, int computer)
{
    if (user == equipments::paper && computer == equipments::stone)
    {
        cout << "you are the winner " << endl << endl;
        system("color 2F");
        s++;
    }
    else if (user == equipments::paper && computer == equipments::scissor)
    {
        cout << "computer is the winner " << endl << endl;;
        system("color 4F");
        cout << "\a";
        c++;
    }
    else if (user == equipments::stone && computer == equipments::scissor)
    {
        cout << "you are the winner " << endl << endl;
        system("color 2F");
        s++;
    }
    else if (user == equipments::scissor && computer == equipments::stone)
    {
        cout << "computer is the winner " << endl << endl;
        system("color 4F");
        cout << "\a";
        c++;
    }
    else if (user == equipments::scissor && computer == equipments::paper)
    {
        cout << "you are the winner " << endl << endl;
        system("color 2F");
        s++;

    }
    else
    {
        cout << "there isn,t any winner the result is draw " << endl << endl;
        system("color 1F");
    }



}


void gameplay(int x)
{
    for (int a = 1; a <= x; a++)
    {

        int x = TakeTypeOfEquipmentThatUserWouldToLikeToPlay();
        int y = makethecomputerplay();
        printcomputerchoice(y);
        checkwhoisthewinner(x, y);
        cout << "-------------------------------------------------------\n";
        cout << endl << endl;


    }

}
void gameover(int h)
{
    char f;
    cout << "\t\t-----------------------------------------------------------------\t\t\n\n";
    cout << "\t\t\t\t\t ++game over++\t\t\t\t\t\t " << endl << endl;;
    cout << "\t\t-----------------------------------------------------------------\t\t\n\n";
    cout << "\t\t---------------------------[ game result : ]--------------------------------------\t\t\n\n";
    cout << "\t\t\tgame round : \t" << h << endl << endl;
    cout << "\t\t\tyou won " << s << " time\s" << endl;
    cout << "\t\t\tcomputer won " << c << " time\s" << endl << endl;
    if (s > c)
        cout << "\t\tthe winner in this game is you " << endl << endl;

    else if (s < c)
        cout << "\t\tthe winner in this game is computer " << endl << endl;


}
char playagain()
{
    cout << endl;
    char f;
    cout << "do you want to play again if yes enter y if no enter n " << endl << endl;
    cin >> f;
    return f;
}

int main()
{

    srand((unsigned)time(NULL));
    int z = roundgame();
    gameplay(z);
    gameover(z);
    char t = playagain();

    while (t == 'y' || t == 'Y')
    {
        s = 0;
        c = 0;
        int z = roundgame();
        gameplay(z);
        gameover(z);
        t = playagain();
    }




}
