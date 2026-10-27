#include <stdio.h>
#include <stdlib.h>

char C[3][3] = {{'X','O','X'},{'O','X','O'},{'X','O','X'}};

int main (int argc, char *argv[]) {

    for(int baris=0; baris <3; baris++)

    {
         for(int kolom=0; kolom <3; kolom++)
        printf("%c",C[baris] [kolom]);
    printf("\n");
    }
}
