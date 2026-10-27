#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    char * nama1 = "baso";
    char * nama2 = "Bakso";

    if (argc < 2){
        printf("Argumen kurang");
        printf("Tambahkan argumen %s %s %s", argv[0], nama1, nama2);
        return -1;
    }

    printf("Halo %s", argv[1]);
    printf("Halo juga %s", argv[2]);

    return 0;
}
