# Exercice déplacement (std::move)

On considère que MyClass est une classe avec un constructeur par défaut et des constructeurs de copies et de déplacements; Dans chacun des bouts de code ci-dessous: combien de fois le constructeur de copie de MyClass est-il appelé? (On ne demande pas le nombre de fois où le constructeur de déplacement est appelé à cause de l’élusion de déplacement que l’on verra plus bas.).

```cpp
/*1*/
MyClass a = MaClass{};
```
-> 0 fois, R-value ici

```cpp
/*2*/
void f(MyClass a) {/* ... */}
int main() 
{
    MyClass a;
    f(a);
}
```
-> 1 fois, appel à f()

```cpp
/*3*/
void f(MyClass a) {/* ... */}
int main() 
{
    MyClass a;
    f(std::move(a));
}
```
-> 0 fois, transformé en R-value

```cpp
/*4*/
void f(MyClass a) {/* ... */}
int main() 
{
    f(MyClass{});
}
```
-> 0 fois, R-value ici

Dans la suite, on considère le code suivant pour MyOtherClass
```cpp
MyOtherClass
{
public:
    MyClass _att;
    MyOtherClass() = default;
    MyOtherClass(MyClass arg) : _att{arg} {}
}
```

```cpp
/*5*/
int main {
    MyClass x;
    MyOtherClass y{x};
}   
```
-> 2 fois, 1 pour arg et 1 pour _att

```cpp
/*6*/
int main {
    MyOtherClass x;
    MyOtherClass y = x;
}
```
-> 1 fois

```cpp
/*7*/
int main {
    MyOtherClass x;
    MyOtherClass y{x._att}
}  
```
-> 2 fois, 1 pour arg et 1 pour _att

```cpp
/*8*/
int main {
    MyOtherClass x;
    MyOtherClass y = MyOtherClass{MyOtherClass{MyOtherClass{std::move(x)}}};
}   
```
-> 0 fois, R-value ici