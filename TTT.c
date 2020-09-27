#include <fcntl.h>
#include <stdio.h>
#include <io.h>
#include <string.h>

int gameState[] = {0,0,0,0,0,0,0,0,0};
int gameOver = 0;
int aMove;
int bMove;
char newGame;
int replay ();

void boardDraw() {
    int i;
    for (i=0;i<9;i++) {
        if(i == 3 || i == 6) {
            wprintf(L"\n");
        }
        switch (gameState[i])
        {
            case 1:
                wprintf(L"X");
                break;
            case -1:
                wprintf(L"O");
                break;
            case 0:
                wprintf(L"-");
                break;
        }
        if (i == 8) {
            wprintf(L"\n");
        }
    }
}

void clearBoard() {
    int gameState[] = {0,0,0,0,0,0,0,0,0};
    gameOver = 0;
}

int winCheck() {
    if ((gameState[0] + gameState[1] + gameState[2] == 3)||(gameState[3] + gameState[4] + gameState[5] == 3)||(gameState[6] + gameState[7] + gameState[8] == 3)||(gameState[0] + gameState[3] + gameState[6] == 3)||(gameState[1] + gameState[4] + gameState[7] == 3)||(gameState[2] + gameState[5] + gameState[8] == 3)||(gameState[0] + gameState[4] + gameState[8] == 3)||(gameState[2] + gameState[4] + gameState[6] == 3)) {
        wprintf(L"Player A wins!");
        return 1;
    }else if ((gameState[0] + gameState[1] + gameState[2] == -3)||(gameState[3] + gameState[4] + gameState[5] == -3)||(gameState[6] + gameState[7] + gameState[8] == -3)||(gameState[0] + gameState[3] + gameState[6] == -3)||(gameState[1] + gameState[4] + gameState[7] == -3)||(gameState[2] + gameState[5] + gameState[8] == -3)||(gameState[0] + gameState[4] + gameState[8] == -3)||(gameState[2] + gameState[4] + gameState[6] == -3)) {
        wprintf(L"Player B wins!");
        return 1;
    }
    return 0;
}

void aPlayerTurn () {
    wprintf(L"Where will you place your X?  ");
    scanf("%d",&aMove);
    gameState[aMove] = 1;
    return;
}

void bPlayerTurn () {
    wprintf(L"Where will you place your O?  ");
    scanf("%d",&bMove);
    gameState[bMove] = -1;
    return;
}

void game() {
    clearBoard();
    while (gameOver != 1) {
        aPlayerTurn();
        boardDraw();
        if (winCheck()) {
            break;
        };
        bPlayerTurn();
        boardDraw();
        if (winCheck()) {
            break;
        };
    }
    if (replay()) {
      game();
    } else {
      printf("Goodbye, Thanks for playing.");
    }
}

int replay () {
    printf("Want to play again?\nUse y or n to confirm.\t");
    scanf("%c",&newGame);
    if (strcmp(newGame, "y") == 1) {  //Looked up how to check for string equality. Found strcmp, needed to import <string.h>, https://stackoverflow.com/questions/8372547/checking-contents-of-char-variable-c-programming
      return 1;
    } else {
      return 0;
    }
}

int main() {
    game();
}
