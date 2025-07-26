#include <iostream>
#include <iomanip>
#include <thread>     
#include <chrono>     
#include <cstdlib>
#include <limits>
#include <windows.h>

using namespace std;

#include <windows.h>
#include <iostream>
using namespace std;

const int SCREEN_WIDTH = 80;   
const int SCREEN_HEIGHT = 25;  

void CursorLocation(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawFullScreenBorder() {
    char borderChar = 219; 

    // Draw top and bottom borders
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        CursorLocation(x, 0); cout << borderChar;
        CursorLocation(x, SCREEN_HEIGHT - 1); cout << borderChar;
    }

    // Draw left and right borders
    for (int y = 1; y < SCREEN_HEIGHT - 1; y++) {
        CursorLocation(0, y); cout << borderChar;
        CursorLocation(SCREEN_WIDTH - 1, y); cout << borderChar;
    }
}


void printBoard(char spaces[]){
    
    cout << "\t\t\t+-----------------------+\n";
    cout << "\t\t\t|       TIC TAC TOE     |\n";
    cout << "\t\t\t+-----------------------+\n";
    cout << "\t\t\t|       |       |       |\n";
    cout << "\t\t\t|   " << spaces[0] << "   |   " << spaces[1] << "   |   " << spaces[2] << "   |\n";
    cout << "\t\t\t|_______|_______|_______|\n";
    cout << "\t\t\t|       |       |       |\n";
    cout << "\t\t\t|   " << spaces[3] << "   |   " << spaces[4] << "   |   " << spaces[5] << "   |\n";
    cout << "\t\t\t|_______|_______|_______|\n";
    cout << "\t\t\t|       |       |       |\n";
    cout << "\t\t\t|   " << spaces[6] << "   |   " << spaces[7] << "   |   " << spaces[8] << "   |\n";
    cout << "\t\t\t|_______|_______|_______|\n";
}



void showBoard(){
    
    cout << "\t\t\t+------------------------+\n";
    cout << "\t\t\t|       TIC TAC TOE      |\n";
    cout << "\t\t\t+------------------------+\n";
    cout << "\t\t\t|       |       |        |\n";
    cout << "\t\t\t|   1   |   2   |   3    |\n";
    cout << "\t\t\t|_______|_______|________|\n";
    cout << "\t\t\t|       |       |        |\n";
    cout << "\t\t\t|   4   |   5   |   6    |\n";
    cout << "\t\t\t|_______|_______|________|\n";
    cout << "\t\t\t|       |       |        |\n";
    cout << "\t\t\t|   7   |   8   |   9    |\n";
    cout << "\t\t\t|_______|_______|________|\n";
}


bool checkWin(char spaces[],char currentPlayer){
    return (
        (spaces[0]==currentPlayer && spaces[1]==currentPlayer && spaces[2]==currentPlayer) ||
        (spaces[3]==currentPlayer && spaces[4]==currentPlayer && spaces[5]==currentPlayer) ||
        (spaces[6]==currentPlayer && spaces[7]==currentPlayer && spaces[8]==currentPlayer) ||
        (spaces[0]==currentPlayer && spaces[3]==currentPlayer && spaces[6]==currentPlayer) ||
        (spaces[1]==currentPlayer && spaces[4]==currentPlayer && spaces[7]==currentPlayer) ||
        (spaces[2]==currentPlayer && spaces[5]==currentPlayer && spaces[8]==currentPlayer) ||
        (spaces[0]==currentPlayer && spaces[4]==currentPlayer && spaces[8]==currentPlayer) ||
        (spaces[2]==currentPlayer && spaces[4]==currentPlayer && spaces[6]==currentPlayer) 
    );
}

int getBestMove(char spaces[],char ai, char player){

    //check if AI can Win

    for (int i=0; i<9;i++){
        if (spaces[i]==' '){
            spaces[i]= ai;
            if (checkWin(spaces,ai)){
                spaces[i]=' ';
                return i;
            }
            spaces[i]=' ';
        }
    }
    //check if AI needs to block  players win

    for (int i=0;i<9;i++){
        if (spaces[i]==' '){
            spaces[i]=player;
            if(checkWin(spaces, player)){
                spaces[i]=' ';
                return i;
            }
            spaces[i]=' ';
        }
    }
    //choose random available space
    for(int i=0;i<9;i++){
        if (spaces[i]==' ') return i;
    }
    return -1;  //should not happen
}

void playPvp(){
        char spaces[9]= {' ',' ',' ',' ',' ',' ',' ',' ',' '};
        char currentPlayer = 'X';
        int moveCount = 0;
        bool gameOver = false;
        string playerXname, playerOname;
        while(true){
            cout<<"\n";
            system("CLS");
            drawFullScreenBorder();      // Draw full screen border
            CursorLocation(5, 2);        // Print inside the border
           
            cout<<"\t\t\t";
            for(int i=0;i<3;i++){
                this_thread::sleep_for(chrono::milliseconds(400));
                 cout<<".."<<flush;
            }
            this_thread::sleep_for(chrono::milliseconds(400));
            drawFullScreenBorder();      // Draw full screen border
            CursorLocation(5, 2);        // Print inside the border
            cout<<" PvP Mode ......"<<flush;
           
            cout<<"\n\n ";
            
            cout<< "\t\t   Enter name for Player X : ";
            cin>>ws;
            getline(cin,playerXname);

        if (!playerXname.empty()){
            break;
        }else{
            cout<<"\t\t\t Name Cannot be Empty. Please Enter Again. ";
        }
        }
        
        
        cout<<endl;

        while(true){
            cout<<"\t\t   Enter name for Player O : ";
            cin>>ws;
            getline(cin,playerOname);

            if (!playerOname.empty()){
            break;
        }else{
            cout<<"\t\t\t Name Cannot be Empty. Please Enter Again. ";
        }
        }
        
             for (int i=0;i<9;i++){
                spaces[i]=' '; 

            }
                moveCount = 0;
                gameOver = false;
                currentPlayer = 'X';


        
        
         cout<<endl;
         system("CLS");
         drawFullScreenBorder();      // Draw full screen border
         CursorLocation(5, 2);        // Print inside the border
         cout<<"\t\t\t  "<<playerXname<<" vs "<<playerOname;
         for(int i=0;i<5;i++){
             this_thread::sleep_for(chrono::milliseconds(400));
         cout<<"."<<flush;
         }
         cout<<"\n\n";
         drawFullScreenBorder();      // Draw full screen border
         CursorLocation(5, 2);        // Print inside the border
         cout<<"\t\t This shows How the Game Board \n";
         cout<<"\t\t Loading ";
         for(int i=0;i<5;i++){
             this_thread::sleep_for(chrono::milliseconds(400));
         cout<<"."<<flush;
         }

         cout<<"."<<flush;
         cout<<"\n\n\n";
         showBoard();
         this_thread::sleep_for(chrono::seconds(3));
             while(!gameOver){
                system("CLS");
                drawFullScreenBorder();      // Draw full screen border
                CursorLocation(5, 2);        // Print inside the border
                cout<<'\n'<<'\n';
                cout<<"\t\t\t  "<<playerXname<<" vs "<<playerOname;
                cout<<"\n\n\n";
                printBoard(spaces);
        
        //int move;
            cout<<endl;
            if(currentPlayer=='X'){
                cout<<"\n";
                cout<<"\t\t"<<playerXname<<" (X) Enter your move (1-9) :";
            }
            else{
                cout<<"\n";
                
                cout<<"\t\t"<<playerOname<<" (O) Enter your move (1-9) :";
            }
           
            
            string input;
            getline(cin, input);

            if (input.empty()) {
            cout << "\n\t\t Input cannot be empty! Please enter a number (1-9).\n";
            this_thread::sleep_for(chrono::seconds(2));
            continue;
    }

            bool validNumber = true;
            for (char c : input) {
            if (!isdigit(c)) {
            validNumber = false;
            break;
    }
}

            if (!validNumber) {
            cout << "\n\t\t Invalid input! Please enter digits only (1-9).\n";
            this_thread::sleep_for(chrono::seconds(2));
            continue;

            
}

            int move = stoi(input) - 1;

            if (move < 0 || move > 8) {
            cout<<"\n";
            cout << "\n\t\t Move out of range! Enter a number between 1 and 9.\n";
            this_thread::sleep_for(chrono::seconds(2));
            continue;

            } else if(spaces[move]!=' '){
                cout<<"\n";
                cout<<"\t\t That Spot is taken. TRY AGAIN!";
                this_thread::sleep_for(chrono::seconds(2));  // Optional, to let user see the message
                continue;
                
}

           
        if (spaces[move]==' '){
            spaces[move]=currentPlayer;
            moveCount++;

            // here, check for win 

           if(checkWin(spaces,currentPlayer)){
            system("CLS");
            drawFullScreenBorder();      // Draw full screen border
            CursorLocation(5, 2);        // Print inside the border
            printBoard(spaces);
           if (currentPlayer=='X'){
                cout<<"\n\n\n";
                cout<<"\t\t\t"<<playerXname<<"(X) WINS !";
           }
           else{
              cout<<"\n\n\n";
              cout<<"\t\t\t"<<playerOname<<"(O) WINS !";
           }
           //cout<<"\t\t\t Player "<< currentPlayer<<" WINS ! \n";
            gameOver= true;
            break;
           }

            if (moveCount==9){
            system("CLS");
            drawFullScreenBorder();      // Draw full screen border
            CursorLocation(5, 2);        // Print inside the border
            printBoard(spaces);
            cout<<"\n";
            
            cout<<"\t\t\t It's a draw! "<<'\n';
            gameOver=true;
        }
         //switch Player

        currentPlayer= (currentPlayer=='X')? 'O':'X';   

        }

    }

}

void playPvc(){
            char spaces[9]= {' ',' ',' ',' ',' ',' ',' ',' ',' '};
            char currentPlayer = 'X';
            int moveCount = 0;
            bool gameOver = false;
            char aiPlayer = 'O';
            char humanPlayer = 'X';

         cout<<endl;
         system("CLS");
         cout<<"\t\t\t";
                drawFullScreenBorder();      // Draw full screen border
                CursorLocation(5, 2);        // Print inside the border

                for(int i=0;i<3;i++){
                this_thread::sleep_for(chrono::milliseconds(400));
                cout<<".."<<flush;
            }
            this_thread::sleep_for(chrono::milliseconds(400));
            drawFullScreenBorder();      // Draw full screen border
            CursorLocation(5, 2);        // Print inside the border

            cout<<" PvC Mode ......"<<flush;
            cout<<"\n\n";

         cout<<"\t\t This shows How the Game Board \n";
         cout<<"\t\t Loading ";
         for(int i=0;i<5;i++){
            this_thread::sleep_for(chrono::milliseconds(400));
            cout<<"."<<flush;
         }
         
         
         cout<<"\n\n\n";
         showBoard();
         this_thread::sleep_for(chrono::seconds(3));

            while (!gameOver)
            {
                system("CLS");
                drawFullScreenBorder();      // Draw full screen border
                CursorLocation(5, 2);        // Print inside the border

                cout<<'\n'<<'\n';
                printBoard(spaces);
            
            int move;

            if (currentPlayer==humanPlayer){
                //Human Turn
                cout<<"\n";
                cout<<"\t\t\t Your Move (1-9): ";
                cin>>move;

                move-=1;
                if (cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "\n\t\t\t Invalid input! Please enter a number (1-9).\n";
                this_thread::sleep_for(chrono::seconds(2));
                continue; // Go back and ask again
            }
                else if(
                move>9 || move<0 ){
                cout<<"\n";
                cout<<"\t\t\t Move Not Valid.Please Enter a number (1-9)  \n";
                this_thread::sleep_for(chrono::seconds(2));
                continue;
            }
            else if(spaces[move]!= ' '){
                cout<<"\n";
                cout<<"\t\t\t That spot is Taken, TRY AGAIN ! "<<endl;
                this_thread::sleep_for(chrono::seconds(2));
                continue;
            }
          
        }
        else{
            // Smart AI turn with "Thinking..."
            cout<<"\n";
            cout << "\t\t\t Computer is thinking";
            this_thread::sleep_for(chrono::milliseconds(400));
            cout << "." << flush;
            this_thread::sleep_for(chrono::milliseconds(400));
            cout << "." << flush;
            this_thread::sleep_for(chrono::milliseconds(400));
            cout << "." << flush;
            this_thread::sleep_for(chrono::milliseconds(300));
            cout << endl;

            move = getBestMove(spaces, aiPlayer, humanPlayer);
            system("CLS");
            cout<<"\n";
            cout << "\t\t\t Computer chooses " << (move + 1) << endl;

        }   
                   
            spaces[move]=currentPlayer;
            moveCount++;

            if (checkWin(spaces,currentPlayer)){
                system("CLS");
                drawFullScreenBorder();      // Draw full screen border
                CursorLocation(5, 2);        // Print inside the border
                cout<<"\n";
                
                printBoard(spaces);
                if(currentPlayer==humanPlayer){
                    cout<<"\n\n";
                    cout<<"\t\t\t You Win! \n";
                }
                
                else {
                cout<<"\n\n";
                cout<<"\t\t\t Computer Wins! \n";
                }
                
                gameOver = true;
                break;
            }
            if(moveCount==9){
                system("CLS");
                drawFullScreenBorder();      // Draw full screen border
                CursorLocation(5, 2);        // Print inside the border
                printBoard(spaces);
                cout<<endl;
                cout<<"\t\t\t It's a Draw! \n";
                gameOver=true;
            }
            if (currentPlayer=='X'){
                currentPlayer='O';

            }else {
                currentPlayer='X';
            }
        }  
}

int main(){
    
     char spaces[9]= {' ',' ',' ',' ',' ',' ',' ',' ',' '};
     int menuChoice;
     main_menu:
        while(true){

        system("CLS");
        drawFullScreenBorder();      // Draw full screen border
        CursorLocation(5, 2);        // Print inside the border
        
        int mode;
        cout<<"\n\n\n";
        cout << "\t\t ==============================\n";
        cout << "\t\t        TIC TAC TOE GAME      \n";
        cout << "\t\t ==============================\n";
        cout<<"\n\n\n";
        cout<<"\t\t   Welcome to Tic Tac Toe ! \n\n";
        cout<<"\t\t   Choose Game Mode \n\n";
        cout<<"\t\t   1. Player vs Player (PvP)\n";
        cout<<"\t\t   2. Player vs Computer (Random) \n";
        cout<<"\t\t   3. Exit Game \n";
        cout<<"\t\t   Enter Your Choice : ";
        cin>>mode;

    

     if (cin.fail() || mode < 1 || mode > 3) {
        cin.clear();                      // Clear error state
        cin.ignore(1000, '\n');           // Ignore leftover input
        cout << "\n\t\t Invalid input! Please enter 1, 2, or 3.\n";
        this_thread::sleep_for(chrono::seconds(2));
        continue; // Ask again
    }

        else if (mode==1){
            bool playAgain=true;
            while (playAgain){
                playPvp();
                this_thread::sleep_for(chrono::seconds(3));
               // printBoard(spaces);
                 system("CLS");
        
                while(true){
                int menuChoice;
                cout<<"\n\n";
                drawFullScreenBorder();      // Draw full screen border
                CursorLocation(5, 2);        // Print inside the border

                cout<<"\t\t\t Game OVER!! \n\n";
                cout<<"\t\t\t Do you want to \n\n";
                cout<<"\t\t\t 1.Play the game again \n";
                cout<<"\t\t\t 2.Go to Main Menu \n";
                cout<<"\t\t\t 3.Exit Game \n\n";
                cout<<"\t\t\t Enter your choice : ";
        
               
                cin >> menuChoice;
                system("CLS");
                
                 if (menuChoice == 1) break;
                    else if (menuChoice == 2) {playAgain=false;
                    goto main_menu;
                    break;}
                    else if (menuChoice==3)
                 {
                    cout<<"\t\t Exiting Game.... GOOD BYE! ";
                    exit(0);
                 }
                  else{
                    if (cin.fail() || menuChoice < 1 || menuChoice > 3) {
                    cin.clear();                    
                    cin.ignore(1000, '\n');
                    drawFullScreenBorder();      // Draw full screen border
                    CursorLocation(5, 2);        // Print inside the border         
                    cout << "\n\t\t Invalid input! Please enter 1, 2, or 3.\n";
                    this_thread::sleep_for(chrono::seconds(2));
                    system("CLS");
                    continue;
                  }
                }
                
            }
            }
        }

        else if (mode==2){
            bool playAgain=true;
            while (playAgain){
                playPvc();
                //printBoard(spaces);
                this_thread::sleep_for(chrono::seconds(3));
                system("CLS");
                while(true){

                int menuChoice;
                
                drawFullScreenBorder();      // Draw full screen border
                CursorLocation(5, 2);        // Print inside the border
                cout<<"\t\t\t Game OVER!! \n\n";
                cout<<"\t\t\t Do you want to \n\n";
                cout<<"\t\t\t 1.Play the game again \n";
                cout<<"\t\t\t 2.Go to Main Menu \n";
                cout<<"\t\t\t 3.Exit Game \n\n";
                cout<<"\t\t\t Enter your choice : ";
        
                
                cin >> menuChoice;
                system("CLS");

                if (menuChoice == 1) break;
                    else if (menuChoice == 2) {
                    playAgain=false;
                    goto main_menu;
                    break;
                }

                else if (menuChoice==3)
                 {
                    cout<<"\t\t Exiting Game.... GOOD BYE! ";
                    exit(0);
                 }
                  else{
                    if (cin.fail() || menuChoice < 1 || menuChoice > 3) {
                    cin.clear();                    
                    cin.ignore(1000, '\n');
                    drawFullScreenBorder();      // Draw full screen border
                    CursorLocation(5, 2);        // Print inside the border          
                    cout << "\n\t\t Invalid input! Please enter 1, 2, or 3.\n";
                    this_thread::sleep_for(chrono::seconds(2));
                    system("CLS");
                    continue;
                  }
                }     
        }
    } 
}
        else{
            if(mode==3){
                cout<<"\n\n ";
                cout<<"\t\t Exiting Game.... GOOD BYE! ";
                break;
            }
        }

        char spaces[9]= {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    
         cout<<"\n\n";
        printBoard(spaces);
        this_thread::sleep_for(chrono::seconds(5));
        system("CLS");
        
   
        

       return 0; 
     
  

}
}

   
  
    
    
    

   