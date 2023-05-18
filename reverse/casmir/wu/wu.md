# Casmir 
Casmir est un challenge compilé avec les options `-S -fverbose-asm -masm=intel` ce qui génére l'assembleur avant l'opération d'assemblage. 

## TL;DR

On ouvre le ficheir casmir.s, on récupère toutes les lignes de code C pour aller plus vite. On comprends que chaque caractère du mot de passe
peut être retrouvé en inversant les opérations. Cela donne le flag : `24HIUT{45M_83tt3r}` 


## Solve 
On va parser tout le fichier afin de récupérer les lignes en `C` pour aller plus vite. 


```c
    if(strlen(flag) != 18)

    if(flag[0] != 0x32)
    if(flag[1] != 0x34)
    if(flag[2] != 0x48)
    if(flag[3] != 0x49)
    if(flag[4] != 0x55)
    if(flag[5] != 0x54)
    if(flag[6] != '{')
    if((flag[7] ^ 'A') != 117)
    if((flag[8] - '0') != 5)
    if((flag[9] + 25 != 102))
    if((flag[10] - '2') != '-')
    if((flag[11] / 2) != 28)
    if((flag[12] * 2)!= 102)
    if((flag[13] - flag[14]) != 0)
    if(flag[14] != 't')
    if(flag[15] != flag[12])
    if(flag[16] != (flag[15] + 63))
    if(flag[17] != '}')
```

On obtient les lignes suivantes il suffit de les inverser de la manière suivante : 

```
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
```

Ceci nous permets de récupérer le flag suivant : `24HIUT{45M_83tt3r}` 
