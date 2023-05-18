#include <stdio.h>
#include <string.h>

//24HIUT{B35t_FunC_5tRncMp_r1ght?}
int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("Usage : ./guessmypass <MYPASS>\n");
        return 1;
    }
    char *user_input = argv[1];
    if(strlen(user_input) != 32)
        return 1;
    char *c_2 = "2433";
    char *c_raf = "n";
    if (!strncmp(&user_input[0],c_2, 2)) {
        char temp = *c_raf + 0x33;
        char *c_4 = "42";
        temp = *(c_4+1) + 0x42;
        char *c_H = "HI24";
        if(!strncmp(&user_input[2], c_H, 2)) {
            temp = temp + 0x55;
            temp = temp - 0x32;
            char *c_U = "UTC4";
            if(!strncmp(&user_input[4], c_U, 2)) {
                char *c_B = "{BAAAA";
                if(!strncmp(&user_input[6], c_B, 2)) {
                    char *c_3 = "35  ";
                    if(!strncmp(&user_input[8], c_3, 2)) {
                        char *c_t = "t_";
                        if(!strncmp(&user_input[10], c_t, 2)) {
                            char temp = *c_t - 46;   
                            char temp_1 = temp + 47;
                            char c_B[] = {temp, temp_1, temp, temp, '\0'}; 
                            if(!strncmp(&user_input[12], c_B, 2)) {
                                char *c_n = "nounCe";
                                if(!strncmp(&user_input[14], c_n + 3, 2)) {
                                    char c_5[] = {c_t[1], c_3[1], '\0'};
                                    if(!strncmp(&user_input[16], c_5, 2)) {
                                        char *c_t = "tRop";
                                        if(!strncmp(&user_input[18], c_t, 2)) {
                                            char *c_nc = "nci";
                                            if(!strncmp(&user_input[20], c_nc, 2)) {
                                                char *c_Mp = "Mppp"; 
                                                if(!strncmp(&user_input[22], c_Mp, 2)) {
                                                    char *c_r = "_r";
                                                    if(!strncmp(&user_input[24], c_r, 2)) {
                                                        char *c_1gh = "t1ght";
                                                        if(!strncmp(&user_input[26], c_1gh + 1, 4)) {
                                                            char *c_aoc = "?}";
                                                             if(!strncmp(&user_input[30], c_aoc, 2)) {       
                                                                printf("Wooaaa balaise, tiens ton flag %s\n", user_input);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
