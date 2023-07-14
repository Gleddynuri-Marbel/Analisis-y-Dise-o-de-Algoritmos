#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T;
    vector<int>output;
    cin >> T;
    while (T--)
    {
        int n, moneda, actual = 0, suma = 0, total = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> moneda;
            if (suma >= moneda)
                suma = suma - actual + moneda;
            else
            {
                suma += moneda;
                ++total;
            }

            actual = moneda;
        }
        output.push_back(total);
    }
    for(int num:output){
        cout<<num<<endl;
    }
    return 0;
}
