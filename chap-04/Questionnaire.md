a : L-value
b : L-value
c : L-value
d : R-value
e : L-value
*e : L-value
a+b+c+d+*e : R-value
new int{a+b+c+d+*e} : R-value
*(new int{a+b+c+d+*e}) : R-value

SomeClass(const SomeClass& other);

SomeClass(const SomeClass& other)
    : _id { other._id }
    , _data { other._data }
    , _ptr { other._ptr } }
{}

Ici, this._ptr va pointer sur la même case mémoire que other._ptr. Ainsi dans le cas où on libère la mémoire de other._prt, on va aussi libérer la mémoire  de this._ptr.

SomeClass(SomeClass&& other);

C'est la même question que la question 9 donc j'ai supposé qu'on devait écrire un constructeur de copie correct.
SomeClass(const SomeClass& other)
    : _id { other._id }
    , _data { other._data }
    , _ptr { new std::string { *(other._ptr) } } }
{}

SomeClass(SomeClass&& other)
    : _id { other._id }
    , _data { other._data }
    , _ptr { other._ptr  }
{}

Ici, other.ptr pointe toujours sur la même case mémoire après déplacement vers this._ptr, on a donc le même problème qu'à la question 4 avec en plus le fait que la ressource n'est pas tout à fait déplacée.

SomeClass(SomeClass&& other)
    : _id { std::move(other._id) }
    , _data { std::move(other._data) }
    , _ptr { new std::string { std::move(*(other._ptr)) } }
{}

SomeClass& operator=(const SomeClass& other); // affectation par copie
SomeClass& operator=(SomeClass&& other); // affectation par déplacement

Oui, il faut les implémenter car ici, on aura les même problèmes de fuites mémoire sur _ptr qu'avec les constructeurs par défaut pour les implémentations par défaut.

SomeClass(int id, std::vector<int> data, std::string* ptr)
    : _id { id }
    , _data { std::move(data) }
    , _ptr { ptr }
{}

Pour le 1er main :
On va appeler ici, l'opérateur d'affectation par copie car ici, on a déjà construit b et de plus a est une L-value d'où la copie.

Pour le 2ème main :
On va appeler le constructeur de copie car ici on construit b à partir de a et de plus a est une L-value d'où la copie.

Non tout était plutôt clair et bien expliqué.

Oui, dans le questionnaire, les question 6 et 9 sont les mêmes : 
"6. Ecrire un constructeur de déplacement correct pour SomeClass."
"9. Ecrire un constructeur de déplacement correct pour SomeClass."

Vu le modèle et l'enchaînement des questions je pense que vous vouliez plutôt écrire pour la question 6 : 6. Ecrire un constructeur de copie correct pour SomeClass." C'est ce que j'ai supposé pour faire la 6.
Aussi, comme la question 5 est "5. Donner le prototype du constructeur de déplacement de SomeClass." , je pense qu'il faudrait intervertir les questions 6 et 5 si vous changez la question 6 pour écrire un constructeur de copie.
Comme ça on aurait une 1ère partie sur le constructeur de copie et une 2ème sur le constructeur de déplacement.

En tout cas j'ai l'impression que c'était votre intention initiale.

Aussi, comme le chapitre a été écrit cette année, les exercices du cours dans le dépôt git du chapitre 4 ne correspondent plus.