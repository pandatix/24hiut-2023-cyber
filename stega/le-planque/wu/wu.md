# Le Planqué

Le planqué a un objectif simple : faire découvrir la notion de stéganographie.
Pour ce faire, il faut retrouver un flag caché dans un pptx.

Problème : il est introuvable depuis PowerPoint...
Solution : regarder en profondeur dans le fichier, qui est en réalité une archive.

## Unzip

Première façon de solve : étant donné que c'est une archive, on peut `unzip` et retrouver le fichier `flag.txt`.
En en lisant le contenu, on trouve le flag `24HIUT{PpTX_ést_ùn_f0rma7_D'@rC#iv3}`.

## Text

Toujours en considérant que le format PPTX est un format d'archive, on peut `cat` le fichier et grep le flag : `cat -A Présentation.pptx | grep 24HIUT`.
On retrouve une ligne contenant un bout du flag : on sait donc qu'il est en clair dans l'archive.
En l'ouvrant avec un éditeur de texte (comme `code`) et en effectuant la recherche `24HIUT` on trouve le flag `24HIUT{PpTX_ést_ùn_f0rma7_D'@rC#iv3}`.

Il est à noter qu'un `strings` seul ne fonctionne pas car les caractères accentués coupent la string, mais avec un manque de seulement 3 caractères il est possible de brute-force la solution.
