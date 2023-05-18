# Dead drops  

## TL;DR

Ce challenge nécessite de créer 4 fichiers nommés :`dead_drop_00000`, `dead_drop_01337`, `dead_drop_00007` et `dead_drop_00001`. Il faut retenir cet ordre car c'est dans celui là 
qu'il faudra lire et écrire dans ces fichiers. Dans ces fichiers une questions nous est posée, pour savoir ce qu'il faut répondre il faut déchiffrer les strings avec lesquels les 
réponses sont comparées pour savoir si elle sont bonnes. Les réponses sont donc : `oui`, `1981`, `Paris` et `cats`. Il faudra donc écrire dans les fichiers ces réponses et ensuite 
supprimer le fichier tout juste écrit. S'il on fait ça cela nous déchiffrera le flag tout seul sinon on peut comprendre la logique et déchiffrer le flag car on connaît l'IV et la 
clé qui est une répétition des réponses de la manière suivante : `ouioui19811981ParisPariscatscats`

Avec le comportement normal on a l'output suivante : 
```
Bonjour agent, afin d'etre sur que c'est un bien a vous que nous avons a faire.
        nous avons depose dans des boites aux lettres mortes des questions que vous seul pouvez connaitre.
        repondez convenablement a ces questions et nous vous livrerons le flag.
        PS: N'oubliez pas de detruire les boites aux lettres après avoir repondu.
Reponse valide !
Reponse valide !
Reponse valide !
Reponse valide !
Vous pouvez valider avec le flag suivant : 24HIUT{8r4v0_4G3nt_V0tR3_1d3nT1te_35t_V4l1d3E}
```
