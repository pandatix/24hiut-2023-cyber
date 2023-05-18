# GuessMyPass 

## TL;DR 
On ouvre le binaire dans IDA free, on remarque qu'il y a une suite de strncmp on récupérer les strings et cela donne le flag : `24HIUT{B35t_FunC_5tRncMp_r1ght?}`.

## Solve 

On ouvre le binaire avec IDA free, cela nous donne le résultat suivant :

```c 
flag = argv[1];
if ( j_strlen_ifunc(flag, argv, envp) == 32 )
{
  if ( !(unsigned int)j_strncmp_ifunc(flag, "2433", 2LL)
    && !(unsigned int)j_strncmp_ifunc(flag + 2, "HI24", 2LL)
    && !(unsigned int)j_strncmp_ifunc(flag + 4, "UTC4", 2LL)
    && !(unsigned int)j_strncmp_ifunc(flag + 6, "{BAAAA", 2LL)
    && !(unsigned int)j_strncmp_ifunc(flag + 8, "35  ", 2LL)
    && !(unsigned int)j_strncmp_ifunc(flag + 10, "t_", 2LL) )
  {
    v9[3] = aT[0] - 46;
    v9[4] = aT[0] - 46 + 47;
    v9[5] = aT[0] - 46;
    v9[6] = aT[0] - 46;
    v9[7] = 0;
    if ( !(unsigned int)j_strncmp_ifunc(flag + 12, &v9[3], 2LL)
      && !(unsigned int)j_strncmp_ifunc(flag + 14, "nCe", 2LL) )
    {
      strcpy(v9, "_5");
      if ( !(unsigned int)j_strncmp_ifunc(flag + 16, v9, 2LL)
        && !(unsigned int)j_strncmp_ifunc(flag + 18, "tRop", 2LL)
        && !(unsigned int)j_strncmp_ifunc(flag + 20, "nci", 2LL)
        && !(unsigned int)j_strncmp_ifunc(flag + 22, "Mppp", 2LL)
        && !(unsigned int)j_strncmp_ifunc(flag + 24, "_r", 2LL)
        && !(unsigned int)j_strncmp_ifunc(flag + 26, "1ght", 4LL)
        && !(unsigned int)j_strncmp_ifunc(flag + 30, "?}", 2LL) )
      {
        printf((unsigned int)"Wooaaa balaise, tiens ton flag %s\n", (_DWORD)flag, v4, v5, v6, v7, (char)argv);
      }
    }
  }
}
```

Il nous suffit d'assembler les strings en ne mettant pas celle qui ne sont pas utiles. 
Il faut juste à un moment faire un calcul du style : 
```
flag[12] = 't' - 46 => 'F';
flag[13] = 't' + 1 => 'u'
```

Cela donne : `24HIUT{B35t_FunC_5tRncMp_r1ght?}`
