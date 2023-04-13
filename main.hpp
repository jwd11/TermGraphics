#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Useful boundaries
#define BUF 20
#define MAXCOL 100000

// Useful macros
#define clr system("clear")

// Collision heap stack
int colheapx[MAXCOL];
int colheapy[MAXCOL];
long curx=0;
long cury=0;

// Create a board
void crtbrd(char board[BUF][BUF]) {
    for(int i=0;i<BUF;i++) {
        for(int j=0;j<BUF;j++) {
            board[i][j]='.';
        }
    }
}

// Print a board
void bprintf(char board[BUF][BUF]) {
    for(int i=0;i<BUF;i++) {
        for(int j=0;j<BUF;j++) {
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

// Clear a board/terminal
void clrbrd() {
    clr;
}

int gcd(int a, int b) // The function runs recursive in nature to return GCD  
{  
    if (b == 0) // if b becomes 0 return a   
        return a;  
    return gcd(b, a % b); // divide to a by b to make smaller number   
       
}  

int stoi(char s[]) {
    int ans=0;
    for(int i=0;s[i]!='\0';i++) {
        ans+=(s[i]-'0')*pow(10,i);
    }
    return ans;
}

template <class strtp> int cntplace(strtp s) {
    int i;
    for(i=0;s[i]!='\0';i++) {
        ;
    }
    return i;
}

// Extract the slope into a fraction for draw() and return in an int array.
int *extract(double m) {
    // Create a pointer to array[0] and allocate 2 free spaces in RAM for array.
    int *coord;
    coord=new int [3];

    string ms=to_string(m);
    string msd=to_string(m-floor(m));
    if(ms[0]=='-') {
        ms[0]='0';
    }

    coord[0]=floor(m);
    coord[1]=stoi(msd);
    coord[2]=pow(10,cntplace<string>(ms));
    
    return coord;
}

// Draw a line on board with the x and y positions given, along with the length of the line and the slope.
template <class T> void drawl(char board[BUF][BUF],int x=0, int y=0,int len=1,T m=1) {
    board[x][y]='@';
    int mx;
    int my;
    if(typeid(m).name()!=typeid(mx).name()) {
        mx=extract(m)[1];
        my=extract(m)[2];
        mx/=gcd(mx,my);
        my/=gcd(mx,my);
        mx+=extract(m)[0]*my;
    } else {
        mx=m;
        my=1;
    }
    for(int i=0;i<len;i++) {
        for(int j=1;j<=my;j++) {
            for(int k=1;k<=mx;k++) {
                board[x+k+i][y+((m<0)?-j-i:j+i)]='@';
            }
        }
    }
}

void drawp(char board[BUF][BUF],int x=0,int y=0) {
    board[x-1][y-1]='@';
}

void crtcol(void (*draw)(char [BUF][BUF],int,int,int,double),char colboard[BUF][BUF],int x,int y,int len=1,double m=1) {
    // Draw on the collision board.
    draw(colboard,x,y,len,m);
    
    // Scan the board for collion lines created and put them in static colheap stacks.
    for(int i=0;i<BUF;i++) {
        for(int j=0;j<BUF;j++) {
            if(colboard[i][j]=='@') {
                colheapx[curx++]=i;
                colheapy[cury++]=j;
            }
        }
    }
}

void delcol(char colboard[BUF][BUF],int x[MAXCOL], int y[MAXCOL]) {
    for(int i=0;i<MAXCOL;i++) {
        colboard[x[i]][y[i]]='.';
    }
}
