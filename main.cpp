//** Created on May 12, 2022, 5:31 PM
//** Purpose :
//    */

    //System Libraries  
#include <iostream> //Input/Output Library
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void welcome();
void newGame();

int dicesum(int a, int b=0, int c=0){
    return(a + b + c);
}

int main(int argc, char** argv) {

    fstream score;
    const int SIZE = 10;
    char file1[SIZE] = "score.dat";
    int dice1;
    int dice2;
    int dice3;
    int dice4;
    int roll;
    int roll2;
    int win;
    int lose;
    char repeat = 'y';
        

    score.open(file1, ios::out);                                            //Records score by utilizing file input/output
    srand(static_cast<unsigned int>(time(0)));                              //Srand to generate random number for dice roll
    dice1 = dice2 = roll2 = roll = 0;

    welcome();

    do {
        newGame();                                                          //Shows start of new game

        dice1 = rand() % 6 + 1;                                             //1st Dice for first rolls
        dice2 = rand() % 6 + 1;                                             //2nd Dice for first rolls
        roll = dicesum(dice1, dice2);                                       //Roll amount for first roll
        cout << "You rolled " << roll << "." << endl;

        if (roll == 7 || roll == 11) {                                      //1st roll Win conditions
            cout << "Winner !" << endl;
            win++;
        }

        else if (roll == 2 || roll == 3 || roll == 12) {                    //1st roll Lose conditions
            cout << "Craps! You lose!" << endl;
            lose++;
        }

        else {
            bool reRoll;                                                    //Boolean statement for while condition
            do {                                                            //Do while loop for reroll loop
                cout << "Starting 'Point' Roll..." << endl;                 //Point roll
                dice3 = rand() % 6 + 1;                                     //1st dice for second rolls
                dice4 = rand() % 6 + 1;                                     //2nd dice for second rolls
                roll2 = dicesum(dice3, dice4);                              //Roll amount for second roll
                if (roll2 == 7) {                                           //Second roll Lose conditions
                    cout << "Re-rolling..." << endl;
                    cout << "You re-rolled a " << roll2 << endl;
                    cout << "Craps! You Lose!" << endl;
                    lose++;
                    reRoll = false;                                         //Exits reroll loop
                }

                else if (roll2 == roll) {                                   //If 1st and second roll are the same, winner condition
                    cout << "Winner !" << " You re-rolled a " << roll2 << " to match your point " << roll << endl;
                    win++;
                    reRoll = false;
                }

                else {                                                      //Else statement if roll is neither a win or lose, otherwise known as point roll
                    cout << "Re-rolling..." << endl;
                    cout << "You re-rolled a " << roll2 << ". You need a "; //Informs player of current roll and needed roll to win
                    cout << roll << " to win." << endl;
                    reRoll = true;                                          //Re-enters point reroll loop
                    cout << "Press enter to continue." << endl;             //Press Enter to continue reroll
                    cin.ignore();
                }
            } while (reRoll);                                               //Reroll while statement is true
        }

        cout << "Would you like to play again? (Y/N)" << endl;              //Statement asking if player would like to play again
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');                               //While loop for repeat of a new game

    if (repeat == 'n' || repeat == 'N'){
    cout << "Thank you for playing." << endl;                               //Exit statement
    score << "Wins: " << win << endl;                                       //Records score of player in a file
    score << "Losses: " << lose << endl;
    score.close();                                                          //Closes file after writing.
    return 0;
    }
    
    else{
        cout << "ERROR! Invalid Input." << endl;
        cout << "The program will now terminate." << endl;
        exit(0);
    }
}

void welcome(){
    cout << "**********************************************************" << endl;
    cout << "************** Welcome to the Craps Table ****************" << endl;
    cout << "***************** Come place your bets! ******************" << endl;
    cout << "**********************************************************" << endl;
}

void newGame(){
    static int count;
    count++;
    string newmsg = "************************ NEW GAME ************************";
    cout << newmsg << endl;
    cout << "Game: " << count << endl << endl;
}
