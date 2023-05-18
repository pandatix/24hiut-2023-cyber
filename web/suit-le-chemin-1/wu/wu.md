# Suit le chemin : 1/2

## Trouver la vulnérabilité
On arrive sur la page `index.php` par défaut

En naviguant des les menus, on voit que quand on affiche une page, son nom est passé via une variable en `GET`.

On teste si l'application est vulnérable au path traversal en mettant une payload classique du style `?page=../../../../../../etc/passwd`

Le fichier /etc/passwd est affiché donc a priori on peut afficher n'importe quel fichier sur lequel l'utilisateur qui publie le site web a les droits de lecture (apache en l'occurrence).

## Trouver la destination du fichier avec le flag
### Trouver les indices sur le chemin du fichier

Maintenant que l'on sait comment afficher des fichiers du serveur, il faut savoir lequel afficher pour récupérer le flag.

La réponse se trouve dans la page joignable sur `/chemindelavictoire.html`
On trouve cette information grâce à un commentaire dans le code source de la page principale (`index.php`)

### Trouver le chemin

Les indices donnés sur la page "secrète" pour trouver le chemin du fichier avec le flag sont les suivants :
- Trouvez la technologie utilisée pour publier le site web -> On trouve cette info dans les entêtes des requêtes HTTP -> Réponse : Apache
- Trouvez quel est le nom de l'utilisateur par défaut créé pour ce service lorsqu'on l'installe sur la distribution Linux "Alpine" -> Après une rapide recherche sur internet, on trouve que l'utilisateur créé par défaut est `apache` -> Réponse : `apache`
- Rendez-vous dans son dossier personnel pour y récupérer le contenu de `drapeau.txt` -> On ne met pas `/home/www-data` car sinon ce serai trop simple :) Pour récupérer le bon chemin, il faut afficher à l'aide du Path Traversal le fichier `/etc/passwd`, repérer la ligne correspondant à l'utilisateur `apache` et récupérer le nom de son dossier personnel -> `/home/apache/dossier-personnel/chall/drapeau.txt`

## Récupérer le flag

On a maintenant toutes les informations pour pouvoir récupérer le flag : 
- Le moyen d'afficher n'importe quel fichier via son chemin
- Le chemin du fichier contenant le flag

Dans la variable "page" passée dans l'URL, il suffit alors de mettre le chemin du dossier personnel de `apache`, et y concaténer enfin `drapeau.txt"`

Payload finale : `?page=../../../../../home/www-data/dossier-perso/chall/drapeau.txt`

Flag : 24HIUT{Th1s_Is_P4th_Trav3r5al}