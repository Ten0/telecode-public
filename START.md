## Dossier "start"

Retaper tout le temps le même code de base avec les `#include stuff...`, le `using namespace std`, etc... c'est pénible. 
Partant de ce constat, l'idée est de proposer un dossier de base que l'on réutilise à chaque fois
que l'on commence une contest codeforces, ou un groupe de problèmes sur France-IOI, ou autres.

### Principe de fonctionnement

Lorsque vous commencez à résoudre une contest, vous commencez par copier le dossier de base dans un dossier qui correspond
à la contest.  
Cela se fait avec la commande `cp -r start <nom de dossier pour la contest>`.

Le code de base est inscrit dans `s.cpp` et dans `11.cpp`.  
Lorsque vous commencez à résoudre une contest, vous commencez par utiliser `11.cpp`.  
Vous placez l'un des inputs de test dans `11.txt`.  

Lorsque vous lancez la commande `make r1`, le programme compile, et se lance en envoyant le contenu du fichier 11.txt
dans l'entrée standard du programme. (ce qui se lit avec `cin`)

Lorsque vous passez au second problème, vous pouvez créer le fichier `21.cpp` grâce à la commande `cp s.cpp 21.cpp`.  
On place ensuite l'input de test dans le fichier `21.txt`, et on lance le programme grâce à la commande `make r2`

### Les macros du fichier de départ

Vous l'avez noté, le fichier de départ est constitué de plein d'élements, dont vous vous demandez probablement l'utilité.  
Voici donc l'intérêt de chacune des lignes de fichier de base.


```
#include <bits/stdc++.h>
```
Au lieu d'avoir à inclure `iostream`, `vector`, `map`, `set`, `pair`, `algorithm`...
on se contente d'inclure `bits/stdc++.h` qui concentre toute la bibliothèque standard c++.  
Du coup, pas besoin de se poser des questions sur quoi inclure lorsqu'on code.

```
#ifndef DEBUG
#define DEBUG 0
#endif
```
Grâce au Makefile, le programme est compilé avec l'option -DDEBUG. Du coup, quand c'est vous qui compilez le programme,
cette variable DEBUG vaut 1.  
Dans le cas où ce n'est pas vous qui compilez, par exemple l'online judge de codeforces ou
France-IOI, cette variable n'est pas définie par l'option de compilation, et est donc définie à 0 par ce header.  
Cela permet d'utiliser ensuite `if(DEBUG)` dans votre code pour afficher par exemple des messages de debug chez vous,
mais qui ne rendront pas votre solution fausse lorsque vous la soumettrez en ligne, puisque ces messages ne s'afficheront
pas sur l'online judge.

```
#define pb push_back
```
Avec v un `vector`, ça va plus vite de taper `v.pb(x)` que `v.push_back(x)`.

```
#define endl "\n"
```
Accélère la sortie des retours à la ligne.

```
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
```
`for(int i = 3; i < n; i++)` devient `FOR(i, 3, n)`

```
#define REP(i, n) FOR(i, 0, n)
```
`FOR(i, 0, n)` devient `REP(i,n)`

```
#define IN(v,n) REP(i,n) cin >> v[i];
```
`REP(i,n) cin >> t[i];` devient `IN(t,n);`

```
#define TRACE(x) if(DEBUG) cout << #x << " = " << (x) << endl
```
`TRACE(valeur1)` affichera `valeur1 = <valeur1>` sur la sortie standard, uniquement si le programme est compilé chez vous.  
Le message ne s'affichera pas lors de la soumission de votre code pour vérification.

```
#define _ << " " <<
```
`cout << x << ' ' << y << ' ' << z << endl` devient `cout << x _ y _ z << endl`

```
typedef int int_32;
#define int long long
```
Plus de débordements d'int qui conduisent à des bugs bien trop longs à corriger.

```
using namespace std;
```
Pas besoin de mettre `std::` devant tous les éléments de la bibliothèque standard utilisés.

`typedef long long ll;` : `ll` va plus vite à écrire que `long long`. Avec la modification du dessus, cela est équivalent à `int`

`typedef pair<int,int> pii;` : `pii` va plus vite à écrire que `pair<int,int>`.

`ios_base::sync_with_stdio(0);` : Accélère les entrées/sorties.
