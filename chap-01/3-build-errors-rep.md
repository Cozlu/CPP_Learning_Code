# Exercice 3

## 1. expected ‘;’ after class definition

1. Essayez de compiler le fichier 1-structs.cpp (et seulement de le compiler, pas de générer un exécutable). Celui-ci ne devrait pas compiler.

-> g++ -std=c++17 -c 1-structs.cpp

2. Il manque le ; après les déclarations des struct d'où l'erreur : 1-structs.cpp:4:2: error: expected ';' after struct definition

Il faut donc les ajouter.

## 2. bla’ is private within this context

1. Essayez maintenant de compiler le fichier 2-class.cpp.
Que signifie l’erreur de compilation ? Pourquoi ne l’avez vous pas rencontrée dans le fichier 1-structs.cpp ?

-> 2-class.cpp:8:14: error: 'int A::a' is private within this context

Ici, le champ a est défini comme privé dans la classe. En effet, si on ne présice pas les sections private et public de la classe, les champs sont par défaut private. Cependant dans le cas des struct les champs sont par défaut public, c'est la seule différence entre class et struct.

## 3. ‘bla’ is not a member of ‘std’

1. Essayez de compiler le fichier 3-hello.cpp.
Quelles sont les différentes erreurs obtenues ? Expliquez la cause de chacune d’entre elles.

3-hello.cpp: In function 'int main()':
3-hello.cpp:3:10: error: 'string' is not a member of 'std'
    3 |     std::string name;
      |          ^~~~~~
3-hello.cpp:1:1: note: 'std::string' is defined in header '<string>'; this is probably fixable by adding '#include <string>'
  +++ |+#include <string>
    1 | int main()

Ici, il manque le include de la classe string pour utiliser std::string.


3-hello.cpp:4:10: error: 'cin' is not a member of 'std'
    4 |     std::cin >> name;
      |          ^~~
3-hello.cpp:1:1: note: 'std::cin' is defined in header '<iostream>'; this is probably fixable by adding '#include <iostream>'
  +++ |+#include <iostream>
    1 | int main()

Ici, il manque le include de la classe iostream pour utiliser std::cin.


3-hello.cpp:4:17: error: 'name' was not declared in this scope
    4 |     std::cin >> name;
      |                 ^~~~

La ligne qui initialise la variable name n'a pas été compilée et donc la variable n'est pas ajouté dans la table des symboles d'où l'erreur. Le compilateur ne la trouve pâs dans la table donc il émet cette erreur.


3-hello.cpp:6:10: error: 'cout' is not a member of 'std'
    6 |     std::cout << "Hello " << name << std::endl;
      |          ^~~~
3-hello.cpp:6:10: note: 'std::cout' is defined in header '<iostream>'; this is probably fixable by adding '#include <iostream>'

Ici, il manque le include de la classe iostream pour utiliser std::cout.

3-hello.cpp:6:43: error: 'endl' is not a member of 'std'
    6 |     std::cout << "Hello " << name << std::endl;
      |                                           ^~~~
3-hello.cpp:1:1: note: 'std::endl' is defined in header '<ostream>'; this is probably fixable by adding '#include <ostream>'
  +++ |+#include <ostream>
    1 | int main()

Ici, il manque le include de la classe iostream pour utiliser std::endl.

Pour toutes les erreurs où il manque le include, le compilateur n'a pas trouvé dans la table des symboles std::cout string cin et endl d'où l'erreur.

## 4. redefinition of ‘bla’

1. Lancez la compilation de 4-main.cpp.
Quelle est l’erreur ? Essayez de l’expliquer en imaginant le contenu du fichier après le passage du préprocesseur.

In file included from 4-driver.hpp:1,
                 from 4-main.cpp:2:
4-car.hpp:3:8: error: redefinition of 'struct Car'
    3 | struct Car
      |        ^~~
In file included from 4-main.cpp:1:
4-car.hpp:3:8: note: previous definition of 'struct Car'
    3 | struct Car
      |        ^~~

L'erreur indique que la struct Car a été redéfinie dans le fichier.
La struct Car se trouve dans car.hpp qui est inclus à la fois dans driver.hpp et dans main.cpp. Cependant, la 1ère étape de la compilation est le remplacement des #include et #define  par le préprocesseur. En effet les #include sont remplacé par le code du fichier qu'ils désignent. Dans notre cas, le code de car.hpp est recopié dans driver.hpp et dans main.cpp mais main.cpp inclus aussi driver.hpp et son code est aussi recopié.
On a alors dans main.cpp, le code de car.hpp et le code de driver.hpp contenant aussi le code de car.hpp.
Au final, on a deux définitions de la struct Car.

## 5. ‘bla’ has not been declared

2. Vous devriez obtenir l’erreur : 5-tac.hpp:8:15: error: 'Tic' has not been declared.
Pourtant, le header 5-tic.hpp est bien inclus dans 5-tac.hpp.
Pourquoi le compilateur n’arrive pas à reconnaître le symbole Tic ?

Comme on l'a vu en C en L2, nous sommes ici dans un ca d'inclusion cyclique des fichiers.
En effet, on essaye d'inclure tic.hpp dans tac.hpp et tac.hpp dans tic.hpp, or le compilateur ne sait pas par quel fichier commencer dans ce cas d'où l'erreur.