# Réponses aux questions du chapitre 5

## Documentation

1. Quelle est la complexité d’insertion dans une std::map ?

O(log(n)) si n est la taille

2. Quelles différences y a-t-il entre les fonctions push_back() et emplace_back() de la classe std::vector ?

push_back() -> ajoute l'élem à la fin en copiant la valeur et en la déplaçant

emplace_back() -> ajoute l'élem à la fin en le construisant avec std::allocator_traits::construct

3. Quelle fonction permet de savoir si un conteneur est vide ?

empty()

4. Quelle est la différence entre std::vector::size() et std::vector::capacity() ?

size() renvoie le nombre d'éléments du conteneur et capacity() renvoie le nombre d'élem max qui peuvent être ajoutés dans le vector.

5. A quoi sert la classe std::stack ?

std::stack sert à représenter une pile.

6. Quelle fonction permet de retirer le dernier élément d’un objet de type std::queue ?

on n'a que pop() qui retire le 1er élément.

## Vectors

Qu’en est-il si vous souhaitez insérer des éléments en plein milieu de ce tableau ?
Essayez de trouver dans la documentation les deux fonctions permettant d’ajouter des éléments n’importe où dans un vector. Quelle est la différence entre ces deux fonctions ?

On a insert où il faut donner l'élément à insérer et emplace où il est possible de fournir les param de construction de l'élément.

## Pile / File

Sur l’image ci-dessus, on vous précise quel conteneur est utilisé par défaut si vous n’en spécifier aucun (c’est-à-dire si vous écrivez juste std::stack<int>, au lieu de std::stack<int, smtg>). De quelle classe s’agit-il ?

std::deque

Essayez maintenant de parcourir la stack via une boucle for pour l’afficher (pas foreach). Qu’est-ce qui pose problème ?

La boucle for demande un accès à tous les éléments or on ne peut accèder qu'au premier.
La boucle for each demande une fonction begin ce qui n'est pas le cas ici.

## Set etc ...

Dans la librairie standard, vous pouvez trouver std::set et std::unordered_set qui permettent de manipuler des sets. En analysant leur documentation, pouvez-vous identifier les différences principales entre ces deux classes ?

std::set contient les éléments tiré en fonction des clés, std::unordered_set contient les éléments non triés.

Essayez à nouveau de compiler. Vos yeux devraient désormais commencer à saigner, ce qui est normal. Je vous rassure, avec un peu d’entraînement, cela n’arrivera plus.
Du coup, essuyez vos larmes et enfilez vos lunettes si vous en avez, et tentez d’identifier ce que le compilateur essaye de vous communiquer.

Le compilateur n'arive pas à trouver une fonction de comparaison pour la classe.