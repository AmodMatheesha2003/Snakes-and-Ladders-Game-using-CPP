#include <iostream>
#include <list>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;

class Player {
public:
    int position;
    string name;
    Player(string name);
    int getPosition();
};

Player::Player(string name) {
    this->name = name;
    this->position = 0;
}

int Player::getPosition() {
    return position;
}

class SnakesladdersLink {
public:
    int square;
    int endSquare;
    SnakesladdersLink* next;
    SnakesladdersLink* previous;
    SnakesladdersLink(int square,int endSquare);
    void displaySnakeLink();
};

SnakesladdersLink::SnakesladdersLink(int square,int endSquare) {
    this->square = square;
    this->endSquare = endSquare;
    next = NULL;
    previous = NULL;
}
class Board {
private:
    SnakesladdersLink* first;
    SnakesladdersLink* last;
public:
    Board();
    void insertSquare(int square,int endSquare);
    void displaySquare();
    void handleInsertSquare(int index);
    void displaybord();
    void rules();
    SnakesladdersLink* findSquare(int Squareid);
    int snakesarray[7][2] = {
        {30, 7},
        {47, 15},
        {56, 19},
        {73, 51},
        {82, 42},
        {92, 75},
        {98, 55}
    };
    int laddersarray[6][2] = {
        {4, 25},
        {21, 39},
        {29, 74},
        {43, 76},
        {63, 80},
        {71, 89}
    };

};

void SnakesladdersLink::displaySnakeLink() {
    cout << square <<" "<<endSquare<< endl;
}

SnakesladdersLink* Board::findSquare(int Squareid){
    SnakesladdersLink* findlink = first;
    while(findlink != NULL){
        if(findlink->square==Squareid){
            return findlink;
        } else{
            findlink=findlink->next;
        }
    }
    return NULL;
}

Board::Board() {
    first = NULL;
    last = NULL;
}

void Board::insertSquare(int Square,int endSquare) {
    SnakesladdersLink* newSquare = new SnakesladdersLink(Square,endSquare);
    if (first == NULL) {
        first = newSquare;
        last = newSquare;
    } else {
        last->next = newSquare;
        newSquare->previous = last;
        last = newSquare;
    }
}

void Board::displaySquare() {
    SnakesladdersLink* current = first;
    while (current != NULL) {
        current->displaySnakeLink();
        current = current->next;
    }
}

void Board::displaybord(){
    cout << endl << "---------------------------------------------------" << endl;
    cout << "                 Snakes and Ladders                " << endl;
    cout << "---------------------------------------------------" << endl << endl;
    cout << "+----+----+----+----+----+----+----+----+----+----+" << endl;
    cout << "| 100| 99 | 98 | 97 | 96 | 95 | 94 | 93 | 92 | 91 |" << endl;
    cout << "+----+----+----+----+----+----+----+----+----+----+" << endl;
    cout << "| 81 | 82 | 83 | 84 | 85 | 86 | 87 | 88 | 89 | 90 |" << endl;
    cout << "+----+----+----+----+----+----+----+----+----+----+" << endl;
    cout << "| 80 | 79 | 78 | 77 | 76 | 75 | 74 | 73 | 72 | 71 |" << endl;
    cout << "+----+----+----+----+----+----+----+----+----+----+" << endl;
    cout << "| 61 | 62 | 63 | 64 | 65 | 66 | 67 | 68 | 69 | 70 |" << endl;
    cout << "+----+----+----+----+----+----+----+----+----+----+" << endl;
    cout << "| 60 | 59 | 58 | 57 | 56 | 55 | 54 | 53 | 52 | 51 |" << endl;
    cout << "+----+----+----+----+----+----+----+----+----+----+" << endl;
    cout << "| 41 | 42 | 43 | 44 | 45 | 46 | 47 | 48 | 49 | 50 |" << endl;
    cout << "+----+----+----+----+----+----+----+----+----+----+" << endl;
    cout << "| 40 | 39 | 38 | 37 | 36 | 35 | 34 | 33 | 32 | 31 |" << endl;
    cout << "+----+----+----+----+----+----+----+----+----+----+" << endl;
    cout << "| 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 |" << endl;
    cout << "+----+----+----+----+----+----+----+----+----+----+" << endl;
    cout << "| 20 | 19 | 18 | 17 | 16 | 15 | 14 | 13 | 12 | 11 |" << endl;
    cout << "+----+----+----+----+----+----+----+----+----+----+" << endl;
    cout << "|  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 |" << endl;
    cout << "+----+----+----+----+----+----+----+----+----+----+" << endl;
    cout << endl << "Instructions: " << endl;
    cout << "1. Players take turns rolling the dice." << endl;
    cout << "2. Move your piece according to the number rolled." << endl;
    cout << "3. If you land at the base of a ladder, move up to the top." << endl;
    cout << "4. If you land on the head of a snake, slide down to its tail." << endl;
    cout << "5. The first player to reach square 100 wins!" << endl << endl;
}

void Board::rules(){
    cout << endl << "---------------------------------------------------" << endl;
    cout << "            Snakes and Ladders Game Rules          " << endl;
    cout << "---------------------------------------------------" << endl << endl;
    cout << "The snakes are positioned as follows:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << "   Snake " << i+1 << " : Head at " << snakesarray[i][0] << ", Tail at " << snakesarray[i][1] << endl;
    }
    cout << endl << "The ladders are positioned as follows:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "   Ladder " << i+1 << " : Bottom at " << laddersarray[i][0] << ", Top at " << laddersarray[i][1] << endl;
    }
    cout << endl << "Thank you, and good luck!" << endl << endl;
}

void Board::handleInsertSquare(int index){
    bool found = false;
    for(int i = 0; i < 7; i++) {
        if(index == snakesarray[i][0]) {
            insertSquare(index, snakesarray[i][1]);
            found = true;
            break;
        }
    }
    if (!found) {
        for(int i = 0; i < 6; i++) {
            if(index == laddersarray[i][0]) {
                insertSquare(index, laddersarray[i][1]);
                found = true;
                break;
            }
        }
    }
    if (!found) {
        insertSquare(index, index);
    }
}

class Game{
    private:
        string level;
        string answer;
        int mode;
        int position;
        Board& board;
        Player* player1;
        Player* player2;
        Player* player3;
        Player* player4;

    public:
        void play();
        void selectLevel();
        void selectMode();
        int rollDice();
        void movePlayer(Player* player, vector<Player*>& players, int diceResult, Game& game);
        void moveThroughSnakeOrLadder(vector<Player*>& players, Game& game);
        void handleRestratOrExit();
        void restartResetOrExitGame(vector<Player*>& players, Game& game);
        Game(Board& board)
            : board(board)
        {
            player1 = NULL;
            player2 = NULL;
            player3 = NULL;
            player4 = NULL;
            position = 0;
        }
};

void Game::play(){
    int diceResult = 0;
    char letterEntered;

    selectLevel();
    selectMode();

    if(mode == 1){
        string name;
        cout << endl << "Enter player name: ";
        cin >> name;
        player1 = new Player(name);
        vector<Player*> players = {player1};
        vector<Player*> emptyPlayersArray = {};

        while(true){

            while (true) {
                cout << player1->name << "'s turn: Roll the dice [enter R]" << endl;
                cin >> letterEntered;

                if (letterEntered == 'R' || letterEntered == 'r') {
                    diceResult = rollDice();
                    cout << "You rolled " << diceResult << endl;

                    movePlayer(player1, players, diceResult, *this);

                    if(diceResult != 6){
                        break;
                    }
                }else{
                    handleRestratOrExit();
                }
            }
            cout << endl;
            while(true){
                cout << "Computer's turn: "<< endl;
                diceResult = rollDice();
                cout << "Computer rolled " << diceResult << endl;

                movePlayer(NULL, emptyPlayersArray, diceResult, *this);

                if(diceResult != 6 ){
                    break;
                }
            }
            cout << endl;
        }
    }

    if (mode == 2){
        string name1,name2;
        cout << endl << "Enter player 1 name: ";
        cin >> name1;
        player1 = new Player(name1);
        cout << "Enter player 2 name: ";
        cin >> name2;
        player2= new Player(name2);
        vector<Player*> players = {player1, player2};

        while(true){
            while (true) {
                cout << endl << player1->name << "'s turn: Roll the dice [enter R]" << endl;
                cin >> letterEntered;
                if (letterEntered == 'R' || letterEntered == 'r') {
                    diceResult = rollDice();
                    cout << "You rolled " << diceResult << endl;

                    movePlayer(player1, players, diceResult, *this);

                    if(diceResult != 6){
                        break;
                    }
                }else{
                    handleRestratOrExit();
                }
            }
            cout << endl;
            while (true) {
                cout << endl << player2->name << "'s turn: Roll the dice [enter R]" << endl;
                cin >> letterEntered;
                if (letterEntered == 'R' || letterEntered == 'r') {
                    diceResult = rollDice();
                    cout << "You rolled " << diceResult << endl;

                    movePlayer(player2, players, diceResult, *this);

                    if(diceResult != 6){
                        break;
                    }
                }else{
                    handleRestratOrExit();
                }
            }
        }
    }

    if (mode == 3){
        string name,name2,name3;
        cout << endl << "Enter player 1 name: ";
        cin >> name;
        player1 = new Player(name);
        cout << "Enter player 2 name: ";
        cin >> name2;
        player2= new Player(name2);
        cout << "Enter player 3 name: ";
        cin >> name3;
        player3= new Player(name3);
        vector<Player*> players = {player1, player2, player3};

            while(true){
                while (true) {
                    cout << endl << player1->name << "'s turn: Roll the dice [enter R]" << endl;
                    cin >> letterEntered;
                    if (letterEntered == 'R' || letterEntered == 'r') {
                        diceResult = rollDice();
                        cout << "You rolled " << diceResult << endl;

                        movePlayer(player1, players, diceResult, *this);

                        if(diceResult != 6){
                            break;
                        }
                    }else{
                        handleRestratOrExit();
                    }
                }
            cout << endl;
            while (true) {
                cout << endl << player2->name << "'s turn: Roll the dice [enter R]" << endl;
                cin >> letterEntered;
                if (letterEntered == 'R' || letterEntered == 'r') {
                    diceResult = rollDice();
                    cout << "You rolled " << diceResult << endl;

                    movePlayer(player2, players, diceResult, *this);

                    if(diceResult != 6){
                        break;
                    }
                }else{
                    handleRestratOrExit();
                }
            }
            cout << endl;
            while (true) {
                cout << endl << player3->name << "'s turn: Roll the dice [enter R]" << endl;
                cin >> letterEntered;
                if (letterEntered == 'R' || letterEntered == 'r') {
                    diceResult = rollDice();
                    cout << "You rolled " << diceResult << endl;

                    movePlayer(player3, players, diceResult, *this);

                    if(diceResult != 6){
                        break;
                    }
                }else{
                    handleRestratOrExit();
                }
            }
            cout << endl;
        }
    }

    if (mode == 4){
        string name1,name2,name3,name4;
        cout << endl << "Enter player 1 name: ";
        cin >> name1;
        player1 = new Player(name1);
        cout << "Enter player 2 name: ";
        cin >> name2;
        player2= new Player(name2);
        cout << "Enter player 3 name: ";
        cin >> name3;
        player3= new Player(name3);
        cout << "Enter player 4 name: ";
        cin >> name4;
        player4= new Player(name4);
        vector<Player*> players = {player1, player2, player3, player4};

        while(true){
            while (true) {
            cout << endl << player1->name << "'s turn: Roll the dice [enter R]" << endl;
            cin >> letterEntered;
            if (letterEntered == 'R' || letterEntered == 'r') {
                diceResult = rollDice();
                cout << "You rolled " << diceResult << endl;

                movePlayer(player1, players, diceResult, *this);

                if(diceResult != 6){
                    break;
                }
                }else{
                    handleRestratOrExit();
                }
            }

            while (true) {
                cout << endl << player2->name << "'s turn: Roll the dice [enter R]" << endl;
                cin >> letterEntered;
                if (letterEntered == 'R' || letterEntered == 'r') {
                    diceResult = rollDice();
                    cout << "You rolled " << diceResult << endl;

                    movePlayer(player2, players, diceResult, *this);

                    if(diceResult != 6){
                        break;
                    }
                }else{
                    handleRestratOrExit();
                }
            }

            while (true) {
                cout << endl << player3->name << "'s turn: Roll the dice [enter R]" << endl;
                cin >> letterEntered;
                if (letterEntered == 'R' || letterEntered == 'r') {
                    diceResult = rollDice();
                    cout << "You rolled " << diceResult << endl;

                    movePlayer(player3, players, diceResult, *this);

                    if(diceResult != 6){
                        break;
                    }
                }else{
                    handleRestratOrExit();
                }
            }

            while (true) {
                cout << endl << player4->name << "'s turn: Roll the dice [enter R]" << endl;
                cin >> letterEntered;
                if (letterEntered == 'R' || letterEntered == 'r') {
                    diceResult = rollDice();
                    cout << "You rolled " << diceResult << endl;

                    movePlayer(player4, players, diceResult, *this);

                    if(diceResult != 6){
                        break;
                    }
                }else{
                    handleRestratOrExit();
                }
            }
        }
    }
}

void Game::handleRestratOrExit(){
    while(true){
        cout << endl << "Do you want to Restart ? Yes-(Y) No-(N) "<< endl <<"Rule-(R)"<< endl <<"Display Board-(B)" << endl <<"exit-(E)"<< endl;
        cin >> answer;
        if(answer == "Y" || answer == "y"){
            delete player1;
            position = 0;
            cout << endl <<"Game has been reset!" << endl;
            play();
        }else if(answer == "N" || answer == "n"){
                break;
        }
        else if(answer == "E" || answer == "e"){
                exit(0);
        }
        else if(answer == "R" || answer == "r"){
               board.rules();
               break;
        }
        else if(answer == "B" || answer == "b"){
               board.displaybord(); 
               break;
        }
    }
}

void Game::movePlayer(Player* player, vector<Player*>& players, int diceResult, Game& game){
    vector<Player*> emptyPlayersArray = {};
    if(player != NULL){
        if (player->position == 0 && diceResult == 6) {
            player->position = 1;
            moveThroughSnakeOrLadder(players, *this);
            cout << player->name << "'s position: " << player->position << endl;
        }
        else if(player->position >= 1){
            if(level == "M" || level == "m"){
                if(player->position + diceResult == 100){
                    player->position = 100;
                    moveThroughSnakeOrLadder(players, *this);
                }else if(player->position + diceResult < 100){
                    player->position += diceResult;
                    moveThroughSnakeOrLadder(players, *this);
                    cout << player->name << "'s position: " << player->position << endl;
                }
            }else if(level == "H" || level == "h"){
                if(player->position + diceResult == 100){
                    player->position = 100;
                    moveThroughSnakeOrLadder(players, *this);
                }
                else if(player->position + diceResult > 100){
                    int overflowCount = (player->position + diceResult) - 100;
                    player->position = 100 - overflowCount;
                    moveThroughSnakeOrLadder(players, *this);
                    cout << player->name << "'s position: " << player->position << endl;
                }else{
                    player->position += diceResult;
                    moveThroughSnakeOrLadder(players, *this);
                    cout << player->name << "'s position: " << player->position << endl;
                }
            }else if(level == "E" || level == "e"){
                if(player->position + diceResult >= 100){
                    player->position = 100;
                    moveThroughSnakeOrLadder(players, *this);
                }else{
                    player->position += diceResult;
                    if(player->position != 100){
                        moveThroughSnakeOrLadder(players, *this);
                        cout << player->name << "'s position: " << player->position << endl;
                    }
                }
            }
        }else{
            cout << player->name << "'s position: 0 " << endl;
        }
    }else{
        if (game.position == 0 && diceResult == 6) {
            game.position = 1;
            moveThroughSnakeOrLadder(emptyPlayersArray, *this);
            cout << "computer's position: " << game.position << endl;
        }
        else if(game.position >= 1){

            if(level == "M" || level == "m"){
                if(game.position + diceResult == 100){
                    game.position = 100;
                    moveThroughSnakeOrLadder(emptyPlayersArray, *this);
                }else if(game.position + diceResult < 100){
                    game.position += diceResult;
                    moveThroughSnakeOrLadder(emptyPlayersArray, *this);
                    cout << "computer's position: " << game.position << endl;
                }
            }else if(level == "H" || level == "h"){
                if(game.position + diceResult == 100){
                    game.position = 100;
                    moveThroughSnakeOrLadder(emptyPlayersArray, *this);
                }
                else if(game.position + diceResult > 100){
                    int overflowCount = (game.position + diceResult) - 100;
                    game.position = 100 - overflowCount;
                    moveThroughSnakeOrLadder(emptyPlayersArray, *this);
                    cout << "computer's position: " << game.position << endl;
                }else{
                    game.position += diceResult;
                    moveThroughSnakeOrLadder(emptyPlayersArray, *this);
                    cout << "computer's position: " << game.position << endl;
                }
            }else  if(level == "E" || level == "e"){
                if(game.position + diceResult >= 100){
                    game.position = 100;
                    moveThroughSnakeOrLadder(emptyPlayersArray, *this);
                }else{
                    game.position += diceResult;
                    if(game.position != 100){
                        moveThroughSnakeOrLadder(emptyPlayersArray, *this);
                        cout << "computer's position: " << game.position << endl;
                    }
                }
            }
        }else{
            cout << "computer's position: 0 " << endl;
        }
    }
}

void Game::restartResetOrExitGame(vector<Player*>& players, Game& game){
    while(true){
        cout << endl << "Do you want to play again? Yes-(Y) No-(N)" << endl;
        cin >> answer;
        if(answer == "Y" || answer == "y"){
            for (Player* player : players) {
                delete player;
            }
            game.position = 0;
            cout << endl <<"Game has been reset!" << endl;
            play();
            break;
        }else if(answer == "N" || answer == "n"){
            exit(0);
        }
    }
}

void Game::moveThroughSnakeOrLadder(vector<Player*>& players, Game& game){

    if (!players.empty()){

        for (Player* player : players) {
            SnakesladdersLink* currentPositionNode = board.findSquare(player->position);
            SnakesladdersLink* current = currentPositionNode;

            if(current != NULL){
                if(currentPositionNode->endSquare == 100){
                    cout << endl << player->name << " won the game!" << endl;
                     switch (mode)
                     {
                        case 1:
                            cout << "Computer loose the game!" << endl;
                            restartResetOrExitGame(players, *this);
                            break;
                        
                        default:
                            for (Player* player : players){
                                if(player->position != 100){
                                    cout << player->name << " loose the game!" << endl;
                                }
                            }
                            restartResetOrExitGame(players, *this);
                            break;
                     }

                     return;
                }
                else if(currentPositionNode->endSquare < currentPositionNode->square){
                    cout << "Oh no! " << player->name << " got bitten by a snake!" << endl;
                    while(true){
                        if(current->square == currentPositionNode->endSquare){
                            player->position = current->square;
                            break;
                        }
                        current = current->previous;
                    }
                }else if(currentPositionNode->endSquare > currentPositionNode->square){
                    cout << "Yay! " << player->name << " climbed a ladder!" << endl;
                    while(true){
                        if(current->square == currentPositionNode->endSquare){
                            player->position = current->square;
                            break;
                        }
                        current = current->next;
                    }
                } 
            }
        }
    }else{
        SnakesladdersLink* currentPositionNode = board.findSquare(game.position);
        SnakesladdersLink* current = currentPositionNode;
        if(current != NULL){
            if(currentPositionNode->endSquare == 100){
                cout << endl << "Computer won the game!" << endl;
                cout << "Player loose the game!" << endl;

                restartResetOrExitGame(players, *this);
            }
            else if(currentPositionNode->endSquare < currentPositionNode->square){
                cout << "Oh no! Computer got bitten by a snake!" << endl;
                while(true){
                    if(current->square == currentPositionNode->endSquare){
                        game.position = current->square;
                        break;
                    }
                    current = current->previous;
                }
            }else if(currentPositionNode->endSquare > currentPositionNode->square){
                cout << "Yay! Computer climbed a ladder!" << endl;
                while(true){
                    if(current->square == currentPositionNode->endSquare){
                        game.position = current->square;
                        break;
                    }
                    current = current->next;
                }
            }
        }
    }
}

int Game::rollDice(){
    static std::mt19937 generator(static_cast<unsigned int>(std::time(0)));
    std::uniform_int_distribution<int> distribution(1, 6);
    return distribution(generator);
}

void Game::selectLevel(){
    while(true){
        cout << endl << "Enter the level you wish to play: Hard-(H), Medium-(M), Easy-(E): "<< endl;;
        cin >> level;
        if(level == "H" || level == "h" || level == "M" || level == "m" || level == "E" || level == "e"){
            return;
        }
    }   
}

void Game::selectMode(){
    while(true){
        cout << endl << "Enter the mode you wish to play: " << endl;
        cout << "1 - me vs computer" << endl;
        cout << "2 - multiplayer(2 players)" << endl;
        cout << "3 - multiplayer(3 players)" << endl;
        cout << "4 - multiplayer(4 players)" << endl;
        cin >> mode;
        if(mode == 1 || mode == 2 || mode == 3 || mode == 4 ){
            return;
        }
    }
}

int main(){
    Board board;

    for(int i=1; i<=100; i++){
        board.handleInsertSquare(i);
    }

    Game game(board);
    board.displaybord();
    board.rules();
    game.play();
}
