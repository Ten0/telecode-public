## Problème : somme partielle des éléments d'un tableau
On donne un tableau t de n entiers (1 <= n <= 10^5)

Puis on effectue p requêtes de type (i,j) (i et j entiers, 0<=i<=n, 1<=p<=10^5),
et on souhaite calculer la somme des t[k] pour k allant de i à j (j non inclus) pour chacune des p requêtes

L'algorithme naïf calcule la somme pour chacun, ce qui aboutit à un parcours potentiel de
tout le tableau pour chacune des p requêtes, soit une complexité en O(n*p),
donc de l'ordre de 10^10 instructions.

Cela est trop long ! (dépasse la seconde, puisqu'une machine à 1Ghz effectue 10^9 instructions par seconde)

Il s'agit donc de trouver un algorithme plus intelligent pour résoudre ce problème.  
L'algorithme optimal atteint une complexité en O(n+p), donc de l'ordre de 10^5 instructions.  
Hint: Pensez aux formules que vous connaissez sur les sommes!

Exemple:
```
n = 4
t = [3, 7, 8, 2]
p = 2
Requête 0:
	i = 1
	j = 2
	On somme donc les éléments 1 à 2 non inclus, soit Sij = t[1] = 7
Requête 1:
	i = 0
	j = 3
	On somme les éléments 0, 1 et 2, Sij = t[0] + t[1] + t[2] = 3+7+8 = 18
```

Input:
```
4		<- n
3 7 8 2		<- t
2		<- p
1 2		<- i0 j0
0 3		<- i1 j1
```

Output:
```
7
18
```
