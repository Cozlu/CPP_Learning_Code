# Questionnaire

1. Citez 3 informations que vous pouvez retrouver dans l’en-tête de la documentation d’une classe.

Le nom de la classe, le header à inclure pour l'utiliser et une brève description de la classe.

2. Comment savoir s’il est nécessaire ou non de fournir un paramètre de template à une classe ?

On le sait grâce à la partie Template parameters de la documentation qui nous informe sur les paramètres à indiquer si besoin.

3. Citez 3 fonctions de vector qu’il ne faut pas appeler à l’intérieur d’une boucle foreach.

emplace_back(), pop_back(), insert() et toutes les fonctions qui ne sont pas en lecture seule ...

4. Dans quel cas l’instanciation d’une classe via (p1, p2, p3) n’a pas le même comportement que l’instanciation via { p1, p2, p3 } ?

Dans le cas où il est spécifié que le constructeur pour { p1, p2, p3 } prend en paramètre une initializer_list.

5. Quel section de la documentation faut-il regarder pour savoir rapidement comment utiliser une fonction ?

La section example.

6. Quelle est la fonction définie par vector qui permet d’accéder à un élément avec l’expression values[idx] ?

C'est la fonction operator[].

7. Quelles fonctions faut-il définir dans un conteneur pour pouvoir le parcourir au moyen d’une boucle foreach ?

begin() et end().

8. Pour pouvoir utiliser un std::set<Key>, quelle contrainte la classe Key doit-elle respecter ?

Les objets de type Key doivent êtres comparables.

9. Afin de respecter cette contrainte, quelle est la signature de la fonction à définir ?

bool operator<(const ComparableClass& other) const

10. Quelles fonctions doivent être définies dans MyOwnContainer pour utiliser un objet de type std::queue<float, MyOwnContainer> ? Indiquez leurs signatures.

const_reference front()
const_reference back()
void push_back( T&& value );
void pop_front();

11. Quelle fonction permet de connaître le nombre d’éléments d’un conteneur ?

size()

12. Quelle fonction permet de savoir si un conteneur est vide ?

empty()

13. Quelle fonction permet de récupérer le premier élément d’un conteneur séquentiel ?

front()

14. Citez deux fonctions permettant d’ajouter des éléments dans un dictionnaire.

insert(), try_emplace()

15. Quelle fonction permet de supprimer des éléments d’un conteneur séquentiel ?

erase()

16. Quelle fonction permet de vider entièrement un conteneur ?

clear()

17. Quelle classe permet de définir un tableau de taille fixe ?

std::array

18. Définissez une variable de ce type, contenant les valeurs ‘a’, ‘b’ et ‘c’.

std::array<char, 3> lettres {  'a', 'b', 'c' };

19. Quelles classes faut-il utiliser pour représenter une collections dans laquelle chaque valeur ne peut pas apparaître plus d’une fois ? Indiquez la complexité en temps des opérations d’insertions pour chacune d’entre elles.

On a deux classes : 
- std::set avec une complexité en O(log(n)) si n est la taille du conteneur pour l'insertion
- std::unordered_set avec une complexité en O(1) en moyenne et O(n) pire cas si n est la taille du conteneur pour l'insertion.

20. Quelle classe permet de retourner plusieurs valeurs d’une fonction facilement ?

std::tuple

21. Quel type doit-on utiliser pour un pointeur ownant? un pointeur observant? (le type pointé est A).

Pointeur ownant : std::unique_ptr<A>
Pointeur observant : *A

22. Une fonction my_func a pour prototype void my_func(std::shared_ptr<std::string>& arg); notez la &. Est-ce que la chaine de caractère *arg sera désinstanciée à la fin de la fonction my_func?

Non, cela dépend de si il y  a encore une référence vers la chaîne.

23. Comment récupérer l’itérateur de début d’un conteneur dans une variable it ?

auto it = conteneur.begin();

24. Comment incrémenter de 5 positions cet itérateur ?

On fait juste it += 5;

25. Comment récupérer la valeur pointé par cette itérateur dans une variable value ?

auto value = *it;

Combien de temps avez-vous mis à compléter ce chapitre ?

3h

Avez-vous des questions suite à sa lecture ?

J'ai compris quasiment tout le chapitre sauf la partie shared_ptr de la section Unique-pointeur. En fait, le cours ne parle que du passage d'un shared_ptr à une fonction sans vraiment expliquer ce que c'est.
De ce que je comprend, j'ai l'impression que c'est pour indiquer un objet pointé par plusieurs pointeurs mais je me trompe peut être.

Aussi pour être sûr, maintenant que l'on connait les unique_ptr pour les pointeurs ownants, on doit donc continuer à utiliser les pointeurs du C pour les pointeur observant ?

Avez-vous des commentaires concernant le chapitre et/ou le site ?

Quasiment tout était clair même si je trouve ce chapitre un peu plus long que les autres.
La seule remarque que j'ai à faire est que je trouve la partie sur shared_ptr de la section Unique_ptr étrange.
En fait, comme je l'ai dit dans ma question, le cours n'explique pas vraiment ce que c'est et j'ai l'impression qu'il manque une partie dans le cours à moins que je ne l'ai pas vue.
