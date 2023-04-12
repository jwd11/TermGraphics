# TermGraphics
Create graphics in the terminal via C++

WARNING: This library only creates terminal based 2d graphics and is very basic. Upon compilation you may see a warning and a note(These are not to be worried about as these don't actually produce errors in the code). You can only have at most 100,000 collision blocks or you will possibly get a segment fault(core dump).

REQUIREMENTS:
1. First you need to create a 2d array for your board that uses the Buffer size of 20 (#define BUF 20) is in test.cpp
2. Second you need to create a 2d array for you collision board that also uses the Buffer size of 20 (#define BUF 20) is in test.cpp

FUNCTIONS:
1. void crtbrd(char board[BUF][BUF])
    a. Input your desired board to create. Return board filled with '.' character.
2. void bprintf(char board[BUF][BUF])
    a. Input your desired board to print. Print board.
3. void clrbrd()
    a. Clear the terminal including past messages and boards
4. int gcd(int a, int b)
    a. Input two numbers. Return the greatest common factor(gcd) between them.
5. int stoi(char s[])
    a. Input a character that contains an integer. Return integer inside of string from before.
6. int cntplace(char s[])
    a. Input a character that contains an integer. Return count places of integer in string form.
7. int *extract(double m)
    a. Input a double. Return pointer to integer array. Array[0] is the whole number part. Array[1] is the numerator. Array[2] is the denominator.
8. void drawl(char board[BUF][BUF],int x=0, int y=0,int len=1,double m=1)
    a. Input a board, row start, column start, length, and slope. Return board with line drawn based on information. (If line goes past board, then you will recieve a segment fault(core dump), so be careful). 
9. void drawp(char board[BUF][BUF],int x=0,int y=0)
    a. Input row start, and column start. Return board with point drawn at row start and row column.
10. void crtcol(void (*draw)(char [BUF][BUF],int,int,int,double),char colboard[BUF][BUF],int x,int y,int len=1,double m=1)
    a. Input a draw function, collision board, row start, column start, length, and slope. Return collision board drawn with shape and keep local collision heap will keep track of collisions. The way that the function works makes it so that even if you delete a collision block the stack will still continue to use more space rather than go back to empty space.
11. int alloc(int foo[])
    a. Find next free space in a heap. (Mostly useless so don't worry about it)
12. void delcol(char colboard[BUF][BUF],int x[MAXCOL], int y[MAXCOL])
    a. Input collision board, list of rows, and the list of columns that correspond to the rows. Return collision board without those collision blocks specified by the list of points(the rows and corresponding columns).

UPDATES COMING VERY SOON(this is my current active project so expect updates constantly)!!!
