#include <stdio.h>

char board[9];

void resetBoard(void) {
    for (int i = 0; i < 9; i++) {
        board[i] = '1' + i;   // 
    }
}
//garis biar rapi dan membentuk tic tac toe sekaligus input nilai
void printBoard(void) {
    printf("\n");
    for (int baris = 0; baris < 3; baris++) {
        printf(" %c | %c | %c \n", board[baris * 3], board[baris * 3 + 1], board[baris * 3 + 2]);
        if (baris < 2) printf("---+---+---\n");
    }
    printf("\n");
}

// ni kondisi menang nya
int menang(char p) {
    int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},   // horizontal
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},   // vertical
        {0, 4, 8}, {2, 4, 6}               // diagonal
    };
    for (int i = 0; i < 8; i++) {
        if (board[wins[i][0]] == p &&
            board[wins[i][1]] == p &&
            board[wins[i][2]] == p) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    char player = 'X';
    int moves = 0;

    resetBoard();

    while (1) {
        printBoard();
        printf("Player %c, masukkan angka (1-9): ", player);

        int choice;
        if (scanf("%d", &choice) != 1) {
            
            //jika input bukan angka tapi ada 1 angka, maka angka akan diambil angkanya dan sisanya akan di buang
            while (getchar() != '\n');
            printf("pake angka 1 - 9.\n");
            continue;
        }
        //untuk cek over atau kurang angkanya
        if (choice < 1 || choice > 9) {
            printf("gabisa, pake angka 1 - 9.\n");
            continue;
        }
        //untuk cek apakah sudah ada isinya 
        int index = choice - 1;
        if (board[index] == 'X' || board[index] == 'O') {
            printf("Dah ada, yang laen.\n");
            continue;
        }

        board[index] = player;
        moves++;

        if (menang(player)) {
            printBoard();
            printf("Player %c menang tawwa\n", player);
            break;
        }

        if (moves == 9) {
            printBoard();
            printf("Seri pak\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
****
