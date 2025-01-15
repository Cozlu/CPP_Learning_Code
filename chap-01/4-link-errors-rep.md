# Exercice 4

## 1. undefined reference to `main’

1. Compilez le fichier 1-hello_wordl.cpp pour en faire un fichier-objet, puis essayez de créer un programme à partir de ce fichier-objet.
Quel est le message d’erreur ? Pouvez-vous identifier dans la sortie complète le nom du programme effectuant l’édition des liens ?

g++ -std=c++17 -c 1-hello_wordl.cpp
g++ -o hello_wordl.exe 1-hello_wordl.o

On a : undefined reference to `WinMain' et error: ld returned 1 exit status

ld est ici le programme d'édition des liens.

2. Corrigez le programme afin que le linker puisse trouver son point d’entrée.

Il y a une typo dans le nom de la fonction main : "mani".

## 2. undefined reference to `bla(…)’ #1

1. Que fait la commande g++ -std=c++17 -o program 2-main.cpp ?

Ici, on compile le fichier 2-main.cpp en un .o et on fait l'édition des liens pour créer un exécutable "program".

2. Exécutez-la.
Quelle est la sortie du programme ? La compilation du fichier 2-main.cpp en fichier-objet s’est-elle bien passée ?

On a : undefined reference to `add(int, int)'
error: ld returned 1 exit status

La compilation s'est bien passé mais l'édition des liens a rencontré un problème.

3. Quels sont les symboles présents dans le ou les fichiers-objet passés à l’édition des liens ?

main.o ne contient que les instructions du main. le code de add.hpp inclus dans le fichier main.cpp n'est qu'une déclaration de fonction et pas les instructions de la fonction add.

4. Que manque-t-il dans la ligne de commande pour que le programme compile ?

g++ -std=c++17 -o program 2-main.cpp 2-add.cpp

Les intructions de la fonction add sont dans 2-add.cpp donc il faut juste ajouter ce fichier à la commande.

## 3. undefined reference to `bla(…)’ #2

1. Exécutez maintenant g++ -std=c++17 -o program 3-main.cpp 3-sub.cpp.
Quelle est l’erreur ? Que contient le fichier-objet 3-sub.o ?

undefined reference to `sub(int, int)'
error: ld returned 1 exit status

3-sub.o ne contient que les instructions de la fonction sub(float, float). En effet, la fonction définie dans 3-sub.cpp est de signature différente que dans 3-sub.cpp donc le compilateur les traite comme deux fonctions différentes et le lien n'est pas établi.

2. Pourquoi la phase de compilation des fichiers 3-main.cpp et 3-sub.cpp ne produit pas d’erreur ?

Dans main.cpp, la déclaration de la fonction incluse par sub.hpp est de la bonne signature par rapport à son utilisation dans le main.
Dans sub.cpp, le compilateur voit les deux fonctions comme deux fonctions différentes car ils considère que la fonction sub a été surchargée à cause de la signature différente.

3. Comment pourriez-vous modifier le programme pour que celui-ci compile ?

On pourrait modifier la signature de la fonction sub dans 3-sub.cpp pour accepter des int.

## 4. multiple definition of `bla’

1. Exécutez la commande g++ -std=c++17 -o prog 4-main.cpp 4-sub.cpp 4-add.cpp.
Quelle est l’erreur ?

4-add.cpp:(.text+0x0): multiple definition of `debug(char const*, int, int)';
4-sub.cpp:(.text+0x0): first defined here

2. Quels sont les symboles présents dans les fichiers-objet 4-add.o et 4-sub.o ?

Dans add.o on a debug(const char*, int, int) et add(int, int) via l'inclusion de debug.hpp.
Dans sub.o on a debug(const char*, int, int) et sub(int, int) via l'inclusion de debug.hpp.

3. Proposez une solution qui pourrait régler le problème, mais ne l’appliquez pas tout de suite.

Le problème vient du fait que debug.hpp contient les instructions de debug(const char*, int, int), il faudrai donc déplacer ces instructions dans un fichier debug.cpp et ne garder que la déclaration de la fonction dans debug.hpp pour que sub.o et add.o ne contiennet plus le symbole debug(const char*, int, int).