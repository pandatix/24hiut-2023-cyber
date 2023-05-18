#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage : ./casmir <FLAG>\n");
        return 1;
    }
    char *flag = argv[1];
    
// 24HIUT{45M_83tt3r}
    if(strlen(flag) != 18)
        return 1;

    if(flag[0] != 0x32)
        return 1;
    if(flag[1] != 0x34)
        return 1;
    if(flag[2] != 0x48)
        return 1;
    if(flag[3] != 0x49)
        return 1;
    if(flag[4] != 0x55)
        return 1;
    if(flag[5] != 0x54)
        return 1;
    if(flag[6] != '{')
        return 1;
    if((flag[7] ^ 'A') != 117)
        return 1;
    if((flag[8] - '0') != 5)
        return 1;
    if((flag[9] + 25 != 102))
        return 1;
    if((flag[10] - '2') != '-')
        return 1;
    if((flag[11] / 2) != 28)
        return 1;
    if((flag[12] * 2)!= 102)
        return 1;
    if((flag[13] - flag[14]) != 0)
        return 1;
    if(flag[14] != 't')
        return 1;
    if(flag[15] != flag[12])
        return 1;
    if(flag[16] != (flag[15] + 63))
        return 1;
    if(flag[17] != '}')
        return 1;

    printf("Bien joue vous pouvez validez avec le flag %s\n", flag);

    return 0;
}
