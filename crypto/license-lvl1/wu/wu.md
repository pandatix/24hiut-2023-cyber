# License lvl-1

L'objectif de ce challenge est de comprendre par quel mécanisme un système de license faible peut fonctionner.
Pour ce faire, nous opérerons sur un exemple malheureusement basé sur des audits réels ayant utilisé du Reverse Engineering.
Dans cet exercice, l'idée est de casser un chiffrement par clé XOR.

On veut générer une license avec un mode standard.
Pour ce faire, nous devrons procéder comme s'en suit :
 1. trouver un chemin d'appels faisant valider la license
 2. examiner la façon dont une license est validée
 3. proposer une action symétrique nous permettant d'émettre une license valide
 4. émettre une license valide pour un mode `standard`

## Chemin d'appel

En observant le code source, on note la présence d'un seul endpoint dans ce service : `/license`.
On note que l'on doit envoyer un contenu JSON de la forme suivante.
```json
{
    "raw": "my_license"
}
```

Nous devrons donc effectuer des appels à cet endpoint, par exemple via la commande curl suivante.
```bash
curl http://license-lvl1:8080/license -d '{"raw":"my_license"}'
```

## Fonctionnement d'une validation de license

On observe que la validation de la license se fait dans le fichier `cryptageapi/cryptapi.go`.
En déroulant le processus de déchiffrement, on note les étapes :
 1. Décodage base 64
 2. XOR de chaque byte modulo une clé écrite en dur
S'en suit un décodage du contenu JSON dans l'objet `Proprietes` (voir `proprietes.go`).

## Symétrique de la validation de license

Ce mécanisme est symétrique, nous pouvons donc créer un objet, l'encoder en JSON, puis effectuer son XOR avec la clé, et enfin l'encoder en base 64.

Pour ce faire, on peut écrire le code suivant.
```go
func CryptageAPIEncrypt(b []byte) ([]byte, error) {
	b = double(b)

	for i := 0; i < len(b); i++ {
		b[i] = b[i] ^ cryptageapi.Key[i%len(cryptageapi.Key)]
	}

	out := make([]byte, base64.StdEncoding.EncodedLen(len(b)))
	base64.StdEncoding.Encode(out, b)

	return out, nil
}

func double(b []byte) []byte {
	lb := len(b)
	out := make([]byte, lb*2)
	for i := 0; i < lb*2; i += 2 {
		out[i] = b[i/2]
		out[i+1] = '\x00'
	}
	return out
}
```

En fournissant notre JSON, on récupère une clé de license.

## Émission d'une license en mode standard

On commence par écrire les propriétés de la license désirée, comme par exemple ce qui suit.
```json
{
    "ModeApplication": 2,
    "InitDay": "2023-04-13T02:00:00",
    "NombreSatellites": 5,
    "NombreBases": 32,
    "NombreUtilisateurs": 12,
    "NombreBatteries": 8
}
```

En utilisant le code précédent, on obtient la license `NWVUMz8gKDAKblEgBjEGZVBZA8PQIDZwQToETgx2XHJORxJuVDQCR0J2ESA4b625RFURIEhwKmVUM14gZTAnblogLjECZWRZDsPAIHdwGjpSTld2A3ISRwNuQzQQRwV2SCBob/C5dFVAIAhwdGVGM0IgfTBebgQgZTFaZQJZIcPWIDhwQjoCTgB2YHJBR0RuCzRMR112DCAtb6a5U1VSIABwe2VaM1AgCTABblkgJTEEZUVZLcPYICZwRToDTkd2CXITRwJuQjQCR392CiA0b6G5UlUVIG9wOmUfMx4gLjAdblUgMzETZVVZHcPKIHdwGjpBTld2H3ICR35uATRNR1N2FyA8b4G5QVUEIE5wK2UEMxsgIjAdbhYgfTFOZV1Z`.

On peut donc émettre l'appel API comme s'en suit.
```bash
curl -s http://license-lvl1:8080/license -d '{"raw":"NWVUMz8gKDAKblEgBjEGZVBZA8PQIDZwQToETgx2XHJORxJuVDQCR0J2ESA4b625RFURIEhwKmVUM14gZTAnblogLjECZWRZDsPAIHdwGjpSTld2A3ISRwNuQzQQRwV2SCBob/C5dFVAIAhwdGVGM0IgfTBebgQgZTFaZQJZIcPWIDhwQjoCTgB2YHJBR0RuCzRMR112DCAtb6a5U1VSIABwe2VaM1AgCTABblkgJTEEZUVZLcPYICZwRToDTkd2CXITRwJuQjQCR392CiA0b6G5UlUVIG9wOmUfMx4gLjAdblUgMzETZVVZHcPKIHdwGjpBTld2H3ICR35uATRNR1N2FyA8b4G5QVUEIE5wK2UEMxsgIjAdbhYgfTFOZV1Z"}' | jq .flag
```

On obtient le flag `24HIUT{To0_W3ak_c#yp7o}`.
