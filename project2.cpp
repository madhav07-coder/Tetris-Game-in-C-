/* CODE EXPERTS */
/*PROJECT 2*/
/*TETRISS*/

#include<bits/stdc++.h>
 /* This is windows specific headers khali windows ma code chalto hashe tyare j aa badha headers chalse */
#ifdef _WIN32
    #include <conio.h>   // for For _kbhit() and _getch()    kbhit matlab keyboard hit thayu che and getch matlab charter input levano che
    #include <windows.h>  //  For Sleep() function and console control   
#else 
    #include <unistd.h>  // linux ane mac ma usleep() mate
    #include <termios.h>  // terminal controlll- keyboard input handeling
    #include <fcntl.h>   // file decriptor control
    
    // linux ane mac mate custom keyboard function banavava pade
    int _kbhit()   // _kbhit() checks if a key is pressed without blocking input.
    {
        struct termios oldt, newt;
        int ch, oldf;
        tcgetattr(STDIN_FILENO, &oldt);   // 
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
        ch = getchar();               // character read karva mate try kare
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);   // 
        fcntl(STDIN_FILENO, F_SETFL, oldf);
        if (ch != EOF) 
        {
            ungetc(ch, stdin);   // put chatracter back
            return 1;
        }
        return 0;
    }

    int _getch() //_getch() reads a character from the keyboard without echoing it to the console.
    {
        struct termios oldt, newt;
        int ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }
    
    void Sleep(int ms) {
        usleep(ms * 1000);  // mili second to micro second
    }
#endif

using namespace std;

// Game configuration structure to handle custom sizes
struct GameConfig {
    int WIDTH = 10;
    int HEIGHT = 20;
    const int BASE_SPEED = 800;
    const int SCORE_PER_LINE[4] = {100, 300, 500, 800};
};

// ANSI Color Codes
const string COLORS[7] = 
{
    "\033[31m", // Red
    "\033[32m", // Green
    "\033[33m", // Yellow
    "\033[34m", // Blue
    "\033[35m", // Magenta
    "\033[36m", // Cyan
    "\033[91m"  // Light Red
};
const string RESET = "\033[0m";  // text na colour ne pacho revert karva mate

// Use a simple ASCII block
const char BLOCK_CHAR = '#';   // tetris na block mate
const char EMPTY_CHAR = '.';   // tetris ni khali jagya
const char BORDER_CHAR = '+';  // border mate ASCII character

// Tetromino Shapes   aatla possible shapes che tetris ma
const int TETROMINOS[7][4][4] = 
{ 
    { {0,0,0,0}, {1,1,1,1}, {0,0,0,0}, {0,0,0,0} }, // I
    { {1,1,0,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0} }, // O
    { {0,1,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0} }, // T
    { {0,1,1,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0} }, // S
    { {1,1,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0} }, // Z
    { {1,0,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0} }, // J
    { {0,0,1,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0} }  // L
};

class Board;

class Tetromino 
{
private:
    int type;   // kya type no tetromino che te store kare (0-6) vacche total 
    GameConfig config;
public:
    int shape[4][4];  //  aa current shape of termomino ne store kare je change thai shake
    int x, y;   // position of tetromino on the game boaard

    Tetromino(int type, const GameConfig& cfg) : type(type), config(cfg) 
    {
        memcpy(shape, TETROMINOS[type], sizeof(shape));  // predefine shape copy kare
        x = config.WIDTH / 2 - 2;  // intially middle thi start kare 
        y = 0; // intially starts from front
    }

    void rotate() // shape ne 90 degree rotate kare
    {
        int temp[4][4] = {0};
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                temp[j][3 - i] = shape[i][j];  // transpose kare and reverse the rows logically vicharo  ke game ma joine vicharo aavu j thavu joine
            }
        }
        memcpy(shape, temp, sizeof(shape));  // rotate karelo shape copy kare
    }

    int getType() const { return type; }  
};

class Board 
{
private:
    vector<vector<int>> grid;   // tetris na board ne save kare (0== empty and 1-7 means filled)
    int score = 0;     // current score
    int level = 1;     // current level je 5 row clear thaya pachi vadshe
    int linesCleared = 0;
    int speed;  // decrease as level increase
    int highScore = 0;  // strore high score
    GameConfig config;

    void loadHighScore()    // highscore.txt namni file mathi load kare highscore
    {
        ifstream file("highscore.txt");
        if (file) file >> highScore;
    }

public:
    Board(const GameConfig& cfg) : config(cfg), speed(cfg.BASE_SPEED) 
    { 
        grid.resize(config.HEIGHT, vector<int>(config.WIDTH, 0));
        loadHighScore(); 
    }  // Board constructor CHE TE intialize kare game ne  te  loadHighScore() ne call kare to read the high score from a file.

    void saveHighScore() 
    {
        if (score <= highScore) return;   // jo current score highsore thi ocho che to to kai karvani jaaruru j naathi direct return kare
        highScore = score;   // else highscore save kare
        ofstream file("highscore.txt");
        if (file) file << highScore;
    }

    void addScore(int points) 
    {
        score += points;  // score ma points add kare
    }

    bool isValidMove(const Tetromino& t, int dx, int dy) const   //check kare ke position valide che ke nahi
    {
        for (int i = 0; i < 4; i++) 
        {
            for (int j = 0; j < 4; j++) 
            {
                if (!t.shape[i][j]) continue;  // jo aa bhag filled na hoy to continue karo kai karvanu nathi
                int newX = t.x + j + dx;   // x posn
                int newY = t.y + i + dy;   // y posn
                if (newX < 0 || newX >= config.WIDTH || newY >= config.HEIGHT) return false;  // check kare ke out of bound to nathi jatu ne left,right or bottom
                if (newY >= 0 && grid[newY][newX]) return false;  // jo pahela j tya koi block hoy board par to return falsw
            }
        }
        return true;
    }

    void placeTetromino(const Tetromino& t) 
    {
        for (int i = 0; i < 4; i++) 
        {
            for (int j = 0; j < 4; j++) 
            {
                if (t.shape[i][j]) // jo tya shape no koi block hoy
                {
                    grid[t.y + i][t.x + j] = t.getType() + 1;  // store tetromino type(1-7)
                }
            }
        }
    }

    int clearLines() 
    {
        int lines = 0;
        for (int i = config.HEIGHT - 1; i >= 0; i--) // badhi row check kare
        {
            bool full = true;
            for (int j = 0; j < config.WIDTH; j++)  // badhi column
            {
                if (!grid[i][j]) // jo koi cell khali mali gayo to
                { 
                    full = false; 
                    break; 
                }
            }
            if (full) // jo aakhi row full che
            {
                // Shift rows down
                for (int k = i; k > 0; k--)
                    grid[k] = grid[k - 1];
                fill(grid[0].begin(), grid[0].end(), 0);  // top row ne clear kare
                lines++;
                i++; 
            }
        }
        if (lines > 0)  // level change
        {
            linesCleared += lines;
            score += config.SCORE_PER_LINE[lines - 1] * level;
            if (linesCleared >= level*5)  //If 5+ lines cleared, increase level
            {
                level++;
                speed = max(100, config.BASE_SPEED - (level - 1)*100);
            }
        }
        return lines;
    }

    bool isGameOver(const Tetromino& t) const // check kare game over thai ke nahi
    {
        return !isValidMove(t, 0, 0);
    }

    int getCell(int i, int j) const { return grid[i][j]; }
    int getScore() const { return score; }
    int getLevel() const { return level; }
    int getHighScore() const { return highScore; }
    int getSpeed() const { return speed; }
    const GameConfig& getConfig() const { return config; }
};

class Game 
{
private:
    Board* board;  // Changed to pointer to avoid assignment issues
    Tetromino* current = nullptr;
    Tetromino* next = nullptr;    // Next tetromino coming option
    Tetromino* hold = nullptr;    // Hold option variable
    bool holdUsed = false;        // Flag to check if hold was used in current turn
    bool paused = false;   
    GameConfig config;

    void handleInput()   // Input handeling
    {
        if (!_kbhit()) return;  // jo keyboard hit thayu j nathi to return
        int key = _getch();   // elese key read kare

#ifdef _WIN32
        if (key == 224) {  // arrow keys on Windows
            key = _getch();
            switch (key) 
            {
                case 75: moveLeft(); break;    // Left arrow
                case 77: moveRight(); break;   // Right arrow
                case 72: rotate(); break;      // Up arrow
                case 80: softDrop(); break;    // Down arrow
            }
        } else 
#else
        // For Unix-like systems, ESC [ <code> is typical
        if (key == 27 && _getch() == 91) 
        {
            key = _getch();
            switch (key) 
            {
                case 68: moveLeft(); break;
                case 67: moveRight(); break;
                case 65: rotate(); break;
                case 66: softDrop(); break;
            }
        } else 
#endif
        {
            switch (key) 
            {
                case ' ': hardDrop(); break; // space key
                case 27: togglePause(); break; // escape key
                case 'c': holdCurrent(); break; // 'c' for hold option
            }
        }
    }

    void moveLeft() 
    { 
        if (board->isValidMove(*current, -1, 0))
            current->x--; 
    }
    void moveRight() 
    { 
        if (board->isValidMove(*current, 1, 0))
            current->x++; 
    }
    void rotate() 
    {
        current->rotate();
        // If invalid, rotate back (3 more times)  // ultu 
        if (!board->isValidMove(*current, 0, 0)) 
        {
            for (int i = 0; i < 3; i++)
                current->rotate();
        }
    }
    void softDrop()    // thodu jaldi niche jashe
    { 
        if (board->isValidMove(*current, 0, 1))
            current->y++; 
    }
    void hardDrop()   // ekdam niche
    {
        while (board->isValidMove(*current, 0, 1)) 
        {
            current->y++;
            board->addScore(2);
        }
    }
    void togglePause() { paused = !paused; }

    // New: Hold current tetromino option without changing game logic
    void holdCurrent() 
    {
        if (holdUsed) return; // allow only one hold per turn
        holdUsed = true;
        if (!hold) 
        {
            hold = current;
            current = next;
            next = new Tetromino(rand() % 7, config);
        } 
        else 
        {
            swap(current, hold);
            // Reset position for held tetromino
            current->x = config.WIDTH / 2 - 2;
            current->y = 0;
        }
    }

    void drawBorder() const   // UI UX Improvement
    {
        // Top border
        cout << "  +";
        for (int j = 0; j < board->getConfig().WIDTH; j++)
            cout << "--";
        cout << "+\n";

        // Side borders
        for (int i = 0; i < board->getConfig().HEIGHT; i++)
        {
            cout << "  |";
            for (int j = 0; j < board->getConfig().WIDTH; j++)
            {
                bool printed = false;
                if (current) 
                {
                    for (int r = 0; r < 4; r++) 
                    {
                        for (int c = 0; c < 4; c++) 
                        {
                            if (current->shape[r][c]) 
                            {
                                if (i == current->y + r && j == current->x + c) 
                                {
                                    cout << COLORS[current->getType()] << BLOCK_CHAR << RESET << " ";
                                    printed = true;
                                    break;
                                }
                            }
                        }
                        if (printed) break;
                    }
                }
                if (!printed) 
                {
                    int cell = board->getCell(i, j);
                    if (cell) 
                    {
                        cout << COLORS[cell - 1] << BLOCK_CHAR << RESET << " ";
                    } 
                    else 
                    {
                        cout << EMPTY_CHAR << " ";
                    }
                }
            }
            cout << "|\n";
        }

        // Bottom border
        cout << "  +";
        for (int j = 0; j < board->getConfig().WIDTH; j++)
            cout << "--";
        cout << "+\n";
    }

    void draw() const 
    {
#ifdef _WIN32
        system("cls");  // clear terminal
#else
        system("clear");
#endif
        cout << "\n  TETRIS GAME\n";
        cout << "  Player: " << playerName << "\n"; // Display player name
        cout << "  Score: " << board->getScore() 
             << "  High Score: " << board->getHighScore()
             << "  Level: " << board->getLevel() << "\n\n";

        drawBorder();

        //  Display Next tetromino preview
        cout << "\n  NEXT:\n";
        if (next) 
        {
            for (int i = 0; i < 4; i++) 
            {
                cout << "    ";
                for (int j = 0; j < 4; j++) 
                {
                    if (next->shape[i][j])
                        cout << COLORS[next->getType()] << BLOCK_CHAR << RESET << " ";
                    else
                        cout << "  ";
                }
                cout << "\n";
            }
        }

        //  Display Hold tetromino preview
        cout << "\n  HOLD:\n";
        if (hold) 
        {
            for (int i = 0; i < 4; i++) 
            {
                cout << "    ";
                for (int j = 0; j < 4; j++) 
                {
                    if (hold->shape[i][j])
                        cout << COLORS[hold->getType()] << BLOCK_CHAR << RESET << " ";
                    else
                        cout << "  ";
                }
                cout << "\n";
            }
        } 
        else 
        {
            cout << "    (Empty)\n";
        }

        if (paused) 
        {
            cout << "\n  PAUSED (Press ESC to resume)\n";
        }
    }

    void showConfigScreen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        cout << "\n  TETRIS CONFIGURATION\n";
        cout << "  -------------------\n";
        
        do {
            cout << "  Enter board width (8-20): ";
            cin >> config.WIDTH;
        } while(config.WIDTH < 8 || config.WIDTH > 20);

        do {
            cout << "  Enter board height (12-30): ";
            cin >> config.HEIGHT;
        } while(config.HEIGHT < 12 || config.HEIGHT > 30);
    }

    // New: Player name input option
    string playerName;
    void getPlayerName() {
        cout << "\n  Enter player name: ";
        cin.ignore(); // clear any leftover newline
        getline(cin, playerName);
    }

public:
    Game() 
    {
        showConfigScreen();
        getPlayerName();  // prompt for player name
#ifdef _WIN32
        // Enable ANSI escape codes
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);

        SetConsoleOutputCP(CP_UTF8);
#endif
        srand(static_cast<unsigned int>(time(0)));   // srand
        board = new Board(config);  // new board
        current = new Tetromino(rand() % 7, config);   // generate current tetromino
        next = new Tetromino(rand() % 7, config); // generate next tetromino
    }

    ~Game()         // game end kare tyare badhu delete kari nakho
    { 
        delete board;        // aakhu board delete
        delete current;        // current tetris delete
        delete next;          // delete next tetris
        if(hold) delete hold;     // jo koi tetris ne hold par mukyu hoy tene pan null kari nakhop
    }

    void run() 
    {
        while (true)   
        {
            if (!paused)       // pause nathi te jova
            {
                handleInput();  // input le
                if (board->isValidMove(*current, 0, 1))  //
                {
                    current->y++;
                } 
                else 
                {
                    board->placeTetromino(*current);    /// place current
                    board->clearLines();            // clear line if avilable
                    delete current;         // delete current
                    current = next;             //    have next ne current banavi lo
                    next = new Tetromino(rand() % 7, config);         // next ne defien karo
                    holdUsed = false; // reset hold usage for new tetromino
                    if (board->isGameOver(*current)) 
                    {
                        board->saveHighScore();
                        draw();
                        cout << "\n  GAME OVER!\n";
                        cout << "  Press R to restart or any other key to quit: ";
                        int ch = _getch();
                        if(ch == 'r' || ch == 'R') 
                        {
                            // Restart from starting option
                            resetGame();
                            continue;
                        }
                        break;
                    }
                }
                draw();
                Sleep(board->getSpeed());
            } 
            else 
            {
                handleInput();
                Sleep(100);
            }
        }
    }

    //  Reset game state for restart option
    void resetGame() 
    {
        delete board;        // aakhu board delete
        delete current;        // current tetris delete
        delete next;           // delete next tetris
        if(hold)             // jo koi tetris ne hold par mukyu hoy tene pan null kari nakhop
        { delete hold; hold = nullptr; }
        board = new Board(config);        // navu board banavo
        current = new Tetromino(rand() % 7, config);       // navu current tetris /banavo
        next = new Tetromino(rand() % 7, config);               // navu next tetris     
        holdUsed = false;        // hold ne intally false
    }
};

int main() 
{
    while (true) {  // loop to support restart option  infinite looop jevu
        Game game;
        game.run();
        cout << "\n  Thank you for playing!\n";
        cout << "  Press R to play again or any other key to exit: ";
        int ch = _getch();
        if(ch != 'r' && ch != 'R')
            break;   // terminate game
#ifdef _WIN32
        system("cls");   // clear the console screen
#else
        system("clear");
#endif
    }
    return 0;
}
