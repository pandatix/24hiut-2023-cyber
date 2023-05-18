#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage : ./do_not_strings_me <FLAG>\n");
        return 1;
    }
    char *flag = argv[1];
    
    if (!strncmp(argv[1], "24HIUT{D1d_Y0u_r34lly_5tr1nG_M3}", 32))
        printf("Bien joue, vous pouvez validez le flag suivant %s \n", flag);

    return 0;
}
