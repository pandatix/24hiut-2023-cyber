#include <stdio.h>

int main(int argc, char *argv[])
{
    char flag[19] = {0};
    flag[0] = 0x32;
    flag[1] = 0x34;
    flag[2] = 0x48;
    flag[3] = 0x49;
    flag[4] = 0x55;
    flag[5] = 0x54;
    flag[6] = '{';
    flag[7] = (117 ^ 'A');
    flag[8] = (5 + '0');
    flag[9] = (102 - 25);
    flag[10] = ('2' + '-');
    flag[11] = (28 * 2);
    flag[12] = 102 / 2;
    flag[14] = 't';
    flag[13] = flag[14];
    flag[15] = flag[12];
    flag[16] = flag[15] + 63;
    flag[17] = '}';
    printf("flag = %s\n", flag);


    return 0;
}
