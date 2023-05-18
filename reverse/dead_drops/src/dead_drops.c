#include "dead_drops.h"


int check_for_answer(struct AES_ctx *aes_ctx_3, char *answer, uint8_t *encrypted_answer, int answer_size) {
    char temp_answer[ANSWER_MAX_SIZE] = {0};
    AES_CBC_decrypt_buffer(aes_ctx_3, encrypted_answer, 16);
    memcpy(temp_answer, encrypted_answer, answer_size);
    if(!strncmp(answer, temp_answer, answer_size)) {
        return 1;
    }
    return 0;
}


int main(void)
{
    printf("Bonjour agent, afin d'etre sur que c'est un bien a vous que nous avons a faire.\n\
        nous avons depose dans des boites aux lettres mortes des questions que vous seul pouvez connaitre.\n\
        repondez convenablement a ces questions et nous vous livrerons le flag.\n\
        PS: N'oubliez pas de detruire les boites aux lettres après avoir repondu.\n");

    if(ptrace(PTRACE_TRACEME, 0, 0, 0) == -1) {
        exit(EXIT_FAILURE);
    } 

    char file_path[FILE_PATH_SIZE] = {0};
    char answer[ANSWER_MAX_SIZE] = {0};
    char message[MESSAGE_SIZE] = {0}; 
    uint8_t filename[FILENAME_SIZE] = {0};
    uint8_t question[QUESTION_ENCRYPTED_SIZE] = {0};
    uint8_t encrypted_answer[16] = {0};
    uint8_t flag_key[32] = {0};
    int question_size = 0;
    int answer_size = 0;

    FILE* dead_drop;
   

    // loop
    // dead_drop_00000
    
    for (int i = 0; i < 4; i++) {
        struct AES_ctx aes_ctx_2; 
        AES_init_ctx_iv(&aes_ctx_2, KEY_2, IV_2);
        struct AES_ctx aes_ctx_1; 
        AES_init_ctx_iv(&aes_ctx_1, KEY_1, IV_1);
        struct AES_ctx aes_ctx_3;
        AES_init_ctx_iv(&aes_ctx_3, KEY_3, IV_3);

        if (i == 0) {
            memcpy(filename,"\x42\x2b\x43\x15\x55\xc9\x97\x48\x7a\x8e\xab\x73\x80\xb0\xdc\x82", FILENAME_SIZE);
            memcpy(question, "\x03\xd9\xc4\x31\x2f\x03\x34\x39\xbb\x5b\xd0\xae\x59\xe3\xfa\x96\xd8\x4e\x9d\xcb\x3e\x04\xde\x95\x4e\x08\x11\x66\x4f\x43\x17\xb7\x84\xa8\xa1\xb3\x35\xc5\x83\xff\x49\x8c\xe7\x42\xd7\x7d\x25\xbf\xe2\x3a\xb9\x56\xd3\x50\x08\x3d\x12\x49\x7c\x06\x33\x71\x50\x23", 64);
            question_size = 54;
            memcpy(encrypted_answer, "\x22\x2b\x5b\x2c\x91\x93\xdc\xad\xdc\xec\x3f\xc3\x19\x41\xca\x6c", 16);
            answer_size = 3;
        } else if(i == 1) {
            memcpy(filename,"\xb4\xe6\x45\x7b\x57\x50\xb7\xca\x62\x39\x9e\xae\xb6\xa4\x52\xb5", FILENAME_SIZE);
            memcpy(question, "\xa4\x15\x95\x36\x7c\xdb\xbb\x8b\x53\xad\x46\x8c\x0d\xc7\xc3\xe8\xac\x92\x15\x39\xce\x87\x77\xaa\x7a\x4f\x7e\xc0\x6f\x95\x5a\xf4\xbc\x8c\xe1\xf5\xb5\x49\x94\xfb\xed\x3d\x6b\xa8\xc7\xe2\x44\xce\x3f\xb3\x04\x96\xdc\x76\xad\x08\x06\xac\xc8\x08\x31\x8d\x71\x44", 64);
            question_size = 49;
            memcpy(encrypted_answer, "\x6f\x21\x50\xff\xc3\x25\x44\xd6\x45\x0e\x25\x2f\x53\xb1\x05\xf6", 16);
            answer_size = 4;
        }
        else if (i == 2) {
            memcpy(filename,"\xbb\x5d\xed\x6d\x10\x18\x31\xfb\x32\xc7\x3b\x3b\x53\x37\x53\x7c", FILENAME_SIZE);
            memcpy(question, "\x67\xc2\x82\x4c\x89\x30\x81\xcf\x88\x96\xb5\x54\x8e\x3a\x18\x5b\x7d\xce\xf7\x46\x26\x2b\xa9\xf0\x5e\xcb\xa3\x1b\x72\x45\x7b\x7f\xfe\x41\x7c\xb5\xd1\xdc\x18\x1c\xaf\x3a\x7b\x9e\xb8\x71\x18\xd7\xd9\x87\xdf\x9b\xb2\x5e\x5f\xf5\x88\x35\xd0\x26\x75\x5e\x8e\x55", 64);
            question_size = 50;
            memcpy(encrypted_answer, "\x3e\x6b\xf0\x30\x7f\x6a\xff\x72\x55\x10\x81\xa1\x6d\x04\xb5\xef", 16);
            answer_size = 5;
        }
        else {
            memcpy(filename,"\xfd\x13\x4b\x0e\x42\xb8\x96\x9f\xae\x55\x25\xb9\xe5\x55\x31\x82", FILENAME_SIZE);
            memcpy(question, "\xa4\x15\x95\x36\x7c\xdb\xbb\x8b\x53\xad\x46\x8c\x0d\xc7\xc3\xe8\x78\xe8\x7d\xb7\x17\x81\xdb\x74\xf4\xe7\x93\xb1\x02\xf1\xab\x9c\x44\x59\xd6\xf0\xe6\x01\x6b\x9b\x69\x82\x22\x11\xc2\xaa\x2c\x16\xb2\x60\x36\xf5\x18\x55\xe0\xca\x47\x8a\xe5\xcd\xae\x64\xac\x74", 64);
            question_size = 54;
            memcpy(encrypted_answer, "\xf0\x57\xc0\x09\x4f\xf9\x94\xda\x82\x50\x8d\x93\x40\x71\x40\x47", 16);
            answer_size = 4;
        }

        AES_CBC_decrypt_buffer(&aes_ctx_2, filename, 16);
        filename[15] = 0;

                snprintf(file_path, FILE_PATH_SIZE, 
                       "%s%s", "/tmp/", filename);

        //printf("pwd %s\n", file_path);
        dead_drop = fopen(file_path, "r+");
        if(!dead_drop) {
            exit(EXIT_FAILURE);
        }
        AES_CBC_decrypt_buffer(&aes_ctx_1, question, 64);
        memcpy(message, question, question_size);

        fwrite(message, 1, question_size, dead_drop);  
        rewind(dead_drop);

        sleep(10);

        int ino_fd = inotify_init();
        if (ino_fd < 0) {
            //perror("inotify failed\n");
            exit(EXIT_FAILURE);
        }
        int ino_wd = inotify_add_watch(ino_fd, "/tmp/", IN_CLOSE_WRITE | IN_DELETE);
        if (ino_wd < 0) {
            //perror("add watch failed \n");
            close(ino_fd);
            exit(EXIT_FAILURE);
        }

        char buf[BUF_LEN];
        ssize_t num_read;

        while (1) {
            num_read = read(ino_fd, buf, BUF_LEN);
                struct inotify_event* event = (struct inotify_event*)&buf[0];
                if (event->len) {
                    if (event->mask & IN_DELETE) {
                        break;
                    }
                    if (event->mask & IN_CLOSE_WRITE) {
                        fread(answer, 1, ANSWER_MAX_SIZE, dead_drop); 
                        answer[5] = 0;
                    }
                }
        }
        
        if(check_for_answer(&aes_ctx_3, answer, encrypted_answer, answer_size)) {
            printf("Reponse valide !\n");
            strncat((char *) flag_key, answer, answer_size);
            strncat((char *) flag_key, answer, answer_size);
        }
        memset(answer, 0, ANSWER_MAX_SIZE);
        memset(message, 0, question_size);
        memset(filename, 0, FILENAME_SIZE);
        fclose(dead_drop);
        

        inotify_rm_watch(ino_fd, ino_wd);
        close(ino_fd);
    }
    uint8_t encrypted_flag[48] = {0};
    //memcpy(flag_key, "ouioui19811981ParisPariscatscats", 32);
    //decrypt_flag
    struct AES_ctx aes_ctx_flag;
    AES_init_ctx_iv(&aes_ctx_flag, flag_key, IV_FLAG);

    memcpy(encrypted_flag, ENCRYPTED_FLAG, 48);
    AES_CBC_decrypt_buffer(&aes_ctx_flag, encrypted_flag, 48);
    
    printf("Vous pouvez valider avec le flag suivant : %s\n", encrypted_flag);

    return 0;
}
