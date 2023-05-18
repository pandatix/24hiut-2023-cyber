# Suit le chemin : 2/2

## Découverte de la vuln
### Compréhension du fonctionnement de l'inclusion du fichier
On voit que l'URL fonctionne de la même manière que pour l'étape 1. Cependant, si on met la même payload que pour l'étape 1, ça ne fonctionne pas. On en déduit donc qu'il y a autre chose que simplement le nom du fichier à passer en GET.

Il faut donc regarder comment sont fait les liens de redirection en fonction des différentes pages.

On voit que ce sont en fait des formulaires qui renvoient vers la page principale avec le nom du fichier en `GET` mais surtout avec un champ transmis en `POST` en plus qui contient une checksum si on se fit à son nom.

Il faut donc trouver comment est calculée cette checksum pour pouvoir de nouveau tenter d'exploiter le path traversal.

### Exploitation de l'inclusion
Si on regarde directement l'input du formulaire, on peut récupérer la checksum et ensuite essayer de trouver à quoi elle correspond.

On voit aussi qu'elle est différente en fonction de si on va sur l'article 1 ou sur l'article 2, sur la page de login...

On peut tester alors différentes valeurs pour l'algorithme de hachage et pour la valeur d'entrée.

Pour l'algorithme de hachage, on le voit dans un commentaire présent dans le CSS de la page principale -> `SHA256`.

Pour trouver la bonne combinaison, on peut s'aider du message d'erreur affiché quand la checksum ne matche pas. Il indique que le fichier inclus et le hash sont lié. Comme on ne connait pas le contenu du fichier, on peut essayer de voir si c'est peut-être le nom du fichier qui est haché -> effectivement c'est ça.

On sait donc à partir de maintenant comment forger nos requêtes :
- `page` : chemin du fichier que l'on veut inclure dans la page web
- `checksum` : hash SHA256 de la chaine de caractères contenue dans "page"

## Trouver la destination du fichier avec le flag
### Trouver les indices sur le chemin du fichier
Maintenant que l'on sait comment afficher des fichiers du serveur, il faut savoir lequel afficher pour récupérer le flag.

De la même manière que pour l'étape 1, il faut trouver une page qui permet de récupérer des indices qui mèneront au chemin du flag.

On trouve l'URL grâce à un cookie qui est stocké dans le navigateur dès le chargement de la page principale. La valeur y est encodée en base64.

Pour le savoir, on peut donner la valeur au filtre "Magic" de CyberChef ou juste repenser au commentaire présent sur la page principale. On obtient alors la chaine en clair : `Rendez-vous sur /lapetiteenigmequifaitplaisir.html`.

### Trouver le chemin
On trouve les indices suivants sur la page "secrète" :
- Quel est le nom de l'organisme qui publie régulièrement un classement des vulnérabilités web les plus présentes sur internet ? (Utiliser la réponse en mettant toutes les lettres en majuscule)
	-  Réponse : `OWASP`
- A quelle position se trouve la catégorie correspondant à la vulnérabilité que vous exploitez pour ce challenge (dans le classement le plus récent) ?
	- Réponse : `Injection -> 3`
- Quel est le nom de la fonction PHP qui permet de faire du rechercher/remplacer grâce à une expression régulière ? (Utiliser la réponse en mettant toutes les lettres en majuscule et en conservant l'underscore si besoin)
	- Réponse : `PREG_REPLACE`
- Concaténer toutes les réponses obtenues aux questions précédentes et calculer le hash SHA256 de la chaine obtenue.
	- Réponse : SHA256(OWASP3PREG_REPLACE) -> `3d0e88213ad0fee9f4dfcfa03c249728c2f96f1ee3c6bae393e097d95617d805`
- Le flag se trouve toujours dans le dossier personnel de l'utilisateur qui lance le serveur web puis dans un dossier nommé avec la réponse obtenue au point précédent et s'appelle toujours drapeau.txt
	- Réponse : `/home/apache/nouveau-dossier-perso/3d0e88213ad0fee9f4dfcfa03c249728c2f96f1ee3c6bae393e097d95617d805/drapeau.txt`

## Protections en plus par rapport à l'étape 1
### Désactivation du chemin absolu
La première protection en plus est le fait qu'un chemin absolu ne marchera plus. 

Pour afficher le fichier que l'on veut, il faut d'abord `remonter` à la racine pour ensuite `redescendre` sur le fichier souhaité.

### Blocage du "../"
Les `../` sont remplacés par des caractères vides donc il faut trouver un autre moyen de remonter la hiérarchie.

On sait que c'est précisément ce motif qui est supprimé avant l'inclusion à l'aide du message d'erreur qui s'affiche quand le fichier qu'on souhaite inclure n'existe pas.

Pour savoir comment contourner cette mesure, on peut aller sur [le site `hacktricks`](https://book.hacktricks.xyz/pentesting-web/file-inclusion). On y trouve différentes payloads permettant de contourner certaines des mesures les plus connues. 
En faisant des tests et en s'aidant du message d'erreur qui indique que le fichier n'existe pas.

La bonne payload à utiliser est "....//". On le sait en faisant des tests avec les différentes payloads issues du site donné ci-dessus mais on peut aussi repenser aux indices pour le chemin du fichier. Une des questions était sur la fonction qui permet de faire du rechercher/remplacer. C'est typiquement le cas ici avec un remplacement de `../` par ` `. 
Une fois que le preg_replace est passé, il reste seulement `../`. Comme la fonction ne passe qu'une fois au même endroit, il suffit simplement de doubler la remontée de dossier.
Exemple avec la partie entre crochets qui est supprimée par le preg_replace : `..[../]/`.

### Checksum en plus du nom de fichier
Il faut que la checksum SHA256 de la string passée dans la variable `page` soit passée en POST dans la variable `checksum`.

Comme il ne s'agit pas de la checksum du contenu du fichier mais bien du nom du fichier, il n'y aucune réelle sécurité apportée par ce point.

## Récupérer le flag
Dans la variable `page` passée dans l'URL, il faut mettre un chemin qui pointe vers le flag tout en utilisant les techniques vues à l'étape 3.

Avec le message d'erreur lors de l'inclusion des fichiers, on sait que la base du chemin est de 1 dossier (/challenge).
On peut donc remonter de 1 dossier avant de commencer à descendre sur le flag.

Une des payloads possibles (il peut y avoir autant de `....//` qu'on veut (ici 1) avec au minimum le nombre pour remonter à la racine (ici 1)). Une fois à la racine, il peut y en avoir en plus ça ne pose pas de problèmes.

Payload finale : 
En `GET` : ?page=....//home/apache/nouveau-dossier-perso/3d0e88213ad0fee9f4dfcfa03c249728c2f96f1ee3c6bae393e097d95617d805/drapeau.txt
En `POST` : checksum=a4637549cd1fe39949bc092973b890cd79dd3911ea69f203054ea0da58585608

Flag : 24HIUT{A_Pr0p3r_User_1nput_S4nit1zing_Is_Th3_K3y}
