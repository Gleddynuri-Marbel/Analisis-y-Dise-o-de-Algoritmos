#include <vector>
#include <list>
#include <iostream>

template <typename Container>
void Write(Container &ds, std::ostream &os)
{
    typename Container::iterator iter = ds.begin();
    for (; iter != ds.end(); iter++)
    {
        os << *iter << "\n";
    }
}

/*toma un contenedor genérico Container por referencia y una referencia a ostream 
para la salida. La función itera a través de los elementos del contenedor utilizando
 un iterador y los imprime en la consola.
*/


int main(int argc, char *argv[])
{
    std::list<float> mylist;
    std::vector<float> myvector;

    /* crean una lista (mylist) y un vector (myvector) de tipo float.
     Se realiza un bucle for para agregar valores a los contenedores.
    */

    for (int i = 0; i < 10; ++i)
    {
        mylist.push_back(i);
        myvector.push_back(i + 50);
    }

    Write(mylist, std::cout);
    Write(myvector, std::cout);

    return 0;
}
