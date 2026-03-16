/*
Objectif : Prouver que l'objet vit en mémoire et conserve son état.
1. C++ : Classe  Chrono  avec une méthode  tick()  qui incrémente un compteur.
2. JS : On instancie  const monChrono = new Module.Chrono() .
3. Le piège : Que se passe-t-il si on met le  new  à l'intérieur d'une boucle  for  de 100 000
itérations sans utiliser  .delete()  ?
Boom !
*/

#include <emscripten/bind.h>

class Chrono
{
public:
    Chrono() : counter(0) {}
    void tick() { counter++; }
    int getCounter() const { return counter; }

private:
    int counter;
};

EMSCRIPTEN_BINDINGS(chrono_module)
{
    emscripten::class_<Chrono>("Chrono")
        .constructor<>()
        .function("tick", &Chrono::tick)
        .function("getCounter", &Chrono::getCounter);
}