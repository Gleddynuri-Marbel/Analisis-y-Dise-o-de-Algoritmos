#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair
{
    int start, end;
    
    bool operator<(const Pair & other) const
    {
        return start < other.start;
    }
};

Pair Pares[100008];
Pair Solucion[100008];

int main()
{
    string sep = "";
    int N, M;
    
    cin >> N;
    
    while (N--)
    {
        cout << sep;
        sep = "\n";
        cin >> M;
        
        int numPares = 0;
        while (cin >> Pares[numPares].start >> Pares[numPares].end,
            Pares[numPares].start || Pares[numPares].end)
        {
            if (Pares[numPares].end > 0 && Pares[numPares].start < M)
                ++numPares;
        }
        
        sort(Pares, Pares + numPares);
        
        // Asegúrese de que esto nunca se seleccione
        Pares[numPares].start = M + 1;
        
        int count = 0;
        int actualX = 0;
        int currentPair = 0;
        
        // Elija el mejor extremo de todos los pares posibles
        while (actualX < M && currentPair < numPares)
        {
            Solucion[count].end = 0;
            for (; Pares[currentPair].start <= actualX; ++currentPair)
                if (Pares[currentPair].end > Solucion[count].end)
                    Solucion[count] = Pares[currentPair];
            
            if (Solucion[count].end == actualX)
            {
                break;
            }
            actualX = Solucion[count].end;
            ++count;
        }
        
        if (actualX >= M)
        {
            cout << count << '\n';
            
            for (int i = 0; i < count; ++i)
            {
                cout << Solucion[i].start << ' ' << Solucion[i].end << '\n';
            }
        }
        else
            cout << endl<<"0\n";
    }
}