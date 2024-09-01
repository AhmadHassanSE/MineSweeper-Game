//#include <iostream>
//#include <ctime>
//#include <cstdlib>
//using namespace std;
//// initializing it as global so that it can be accessible in every function
//char** displaygrid;
////declairing functions
//void updateAdjacentCells(char** grid, int rows, int cols, int r, int c);
//void revealZeros(char**& grid, int rows, int cols, int r, int c);
////initializing grid values to 0
//void initializeGrid(char**& grid, int rows, int cols) 
//{
//    grid = new char* [rows];
//    for (int i = 0; i < rows; i++) 
//    {
//        grid[i] = new char[cols];
//        for (int j = 0; j < cols; j++) 
//        {
//            grid[i][j] = '0'; // Initially set all cells to '0'
//        }
//    }
//}
////placing mines randomly inside the grid
//void placeMines(char** grid, int rows, int cols, float minePercentage) 
//{
//    int totalMines = static_cast<int>(rows * cols * minePercentage);
//    // Seed for randomness
//    srand(static_cast<unsigned>(time(0))); 
//
//    while (totalMines > 0) 
//    {
//        int r = rand() % rows;
//        int c = rand() % cols;
//        if (grid[r][c] != 'M')
//        {
//            grid[r][c] = 'M';
//            totalMines--;
//            //updating adjacent cells according to number of mines in there adjacent cells
//            updateAdjacentCells(grid, rows, cols, r, c);
//        }
//    }
//}
////updating adjacent cells according to number of mines in there adjacent cells
//void updateAdjacentCells(char** grid, int rows, int cols, int r, int c) {
//    for (int i = -1; i <= 1; i++) 
//    {
//        for (int j = -1; j <= 1; j++) 
//        {
//            int nr = r + i;
//            int nc = c + j;
//            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] != 'M')
//            {
//                if (grid[nr][nc] >= '0' && grid[nr][nc] <= '8') 
//                {
//                    grid[nr][nc] = grid[nr][nc] + 1;  // Increment as a character
//                }
//            }
//        }
//    }
//}
////handling user click that the clicked index has mine , 0 or other value between 1 and 8
//void handleClick(char** grid, int rows, int cols, int r, int c, bool& gameOver) 
//{
//    if (grid[r][c] == 'M')
//    {
//        gameOver = true;
//        return;
//    }
//    if (grid[r][c] == '0') 
//    {
//        revealZeros(grid, rows, cols, r, c);
//    }
//    else if (grid[r][c] >= '1' && grid[r][c] <= '8') 
//    {
//        // Show the number of adjacent mines
//        displaygrid[r][c] = grid[r][c]; 
//        // Mark as revealed
//        grid[r][c] = 'R'; 
//    }
//}
//
//void revealZeros(char**& grid, int rows, int cols, int r, int c) 
//{
//    //if rows and columns are not valid or the given index is already revealed return nothing
//    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 'R' || grid[r][c] == 'M')
//        return;
//
//    if (grid[r][c] == '0') 
//    {
//        displaygrid[r][c] = '0';
//        // Mark as revealed
//        grid[r][c] = 'R'; 
//        for (int i = -1; i <= 1; i++) 
//        {
//            for (int j = -1; j <= 1; j++) 
//            {
//                revealZeros(grid, rows, cols, r + i, c + j);
//            }
//        }
//    }
//    else if (grid[r][c] >= '1' && grid[r][c] <= '8') 
//    {
//        // Show the number of adjacent mines
//        displaygrid[r][c] = grid[r][c]; 
//        // Mark as revealed
//        grid[r][c] = 'R'; 
//    }
//}
////mark the index as flagged
//void flagSquare(char**& grid, int r, int c) 
//{
//    if (displaygrid[r][c] == '*') {
//        displaygrid[r][c] = 'F';
//    }
//}
////mark the index as ?
//void markSquare(char**& grid, int r, int c) 
//{
//    if (displaygrid[r][c] == '*') 
//    {
//        displaygrid[r][c] = '?';
//    }
//}
////checking if the game is won or not
//bool checkWin(char** grid, int rows, int cols) 
//{
//    for (int i = 0; i < rows; i++) 
//    {
//        for (int j = 0; j < cols; j++) 
//        {
//            if (grid[i][j] != 'M' && grid[i][j] != 'R')
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}
////function to display grid
//void displayGrid(char** grid, int rows, int cols, bool gameOver) 
//{
//    cout << "  ";
//    //displaying column numbers
//    for (int j = 0; j < cols; j++) 
//    {
//        cout << j + 1 << " ";
//    }
//    cout << endl;
//
//    for (int i = 0; i < rows; i++) 
//    {
//        //displaying row numbers
//        cout << i + 1 << " ";
//        for (int j = 0; j < cols; j++) 
//        {
//            if (grid[i][j] == 'R') 
//            {
//                cout << " ";
//            }
//            else if (grid[i][j] == 'M' && gameOver) 
//            {
//                cout << "M";
//            }
//            else if (grid[i][j] == '0') 
//            {
//                cout << ".";
//            }
//            else 
//            {
//                cout << grid[i][j];
//            }
//            cout << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    int rows = 7, cols = 7;
//    float percentage = 0.3;
//    char** grid;
//
//    // Allow user to change grid size and mine percentage
//    cout << "Enter number of rows (default 7): ";
//    cin >> rows;
//    //validiting of rows
//    if (rows <= 0)
//    {
//        while (rows <= 0)
//        {
//            cout << "kindly enter valid row number!" << endl;
//            cin >> rows;
//        }
//    }
//    cout << "Enter number of columns (default 7): ";
//    cin >> cols;
//    //validiting of cols
//    if (cols <= 0)
//    {
//        while (cols <= 0)
//        {
//            cout << "kindly enter valid column number!" << endl;
//            cin >> cols;
//        }
//    }
//    cout << "Enter mine percentage (default 0.3): ";
//    cin >> percentage;
//    //validiting of percentage
//    if (percentage <= 0.0)
//    {
//        while (percentage <= 0.0)
//        {
//            cout << "kindly enter valid percentage number!" << endl;
//            cin >> percentage;
//        }
//    }
//    //initilizing grid and placing mines in it
//    initializeGrid(grid, rows, cols);
//    placeMines(grid, rows, cols,percentage);
//    //built-in function to calculate time from beginning to end
//    time_t start, end;
//    time(&start);
//    //allocating memory to display grid
//    displaygrid = new char* [rows];
//    for (int i = 0; i < rows; i++) 
//    {
//        displaygrid[i] = new char[cols];
//    }
//
//    // Initialize display grid to *
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            displaygrid[i][j] = '*'; // Unrevealed squares
//        }
//    }
//    //variable to flag the game over
//    bool gameOver = false;
//    while (!gameOver) 
//    {
//        displayGrid(displaygrid, rows, cols, gameOver);
//        int r, c;
//        char action;
//        //inputing action row and column 
//        cout << "Enter action (c = click, f = flag, m = mark) and row, col: ";
//        cin >> action >> r >> c;
//
//        // Adjust user input to zero-based indexing
//        r--;
//        c--;
//        // checking if rows and coulmn value are valid
//        if (r < 0 || r >= rows || c < 0 || c >= cols) 
//        {
//            cout << "Invalid input. Please enter a valid row and column." << endl;
//            continue;
//        }
//        // if action is c handle the click and display the grid
//        if (action == 'c') 
//        {
//
//            handleClick(grid, rows, cols, r, c, gameOver);
//            // if game is over simply display all values of grid and display game pver message
//            if (gameOver) 
//            {
//                displayGrid(grid, rows, cols, gameOver);
//                cout << "Game Over! You clicked on a Mine." << endl; 
//            }
//        }
//        // if action is flag simply flag that index 
//        else if (action == 'f') 
//        {
//            flagSquare(grid, r, c);
//        }
//        // if action is mark simply mark that index with ?
//        else if (action == 'm') 
//        {
//            markSquare(grid, r, c);
//        }
//        //if action is neither r, f or m
//        else 
//        {
//            cout << "Invalid action. Please enter 'c', 'f', or 'm'." << endl;
//        }
//        // checking if game is finished
//        if (!gameOver && checkWin(grid, rows, cols)) 
//        {
//            //displaying grid and victory message
//            displayGrid(displaygrid, rows, cols, true);
//            cout << "Congratulations! You've cleared the minefield!" << endl;
//            gameOver = true;
//        }
//    }
//    // ended the time here
//    time(&end);
//    double timeTaken = difftime(end, start);
//    //displaying time taken to finish the game
//    cout << "Time taken: " << timeTaken << " seconds" << endl;
//
//    // Free dynamically allocated memory
//    for (int i = 0; i < rows; i++) 
//    {
//        delete[] grid[i];
//    }
//    delete[] grid;
//
//    for (int i = 0; i < rows; i++)
//    {
//        delete[] displaygrid[i];
//    }
//    delete[] displaygrid;
//
//    return 0;
//}
//
//
