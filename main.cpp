#include <iostream>
#include <string>
using namespace std;

class Array
{
public:
    Array(int N)
    {
        this->N = N;
        elements = new int[N];
    }
    void set(int i, int x)
    {
        elements[i] = x;
    }
    void print()
    {
        for (int i=0; i<N; i++)
            cout << elements[i] << " ";
        cout << "\n";
    }
private:
    int N;
    int* elements;
};

int main()
{
    int T; cin >> T; while (T--)
    {
        int N, Q; cin >> N >> Q;
        Array arr = Array(N);
        for (int i=0; i<N; i++)
        {
            int x; cin >> x;
            arr.set(i,x);
        }
        while (Q--)
        {
            int x, y; cin >> x >> y;
            if (x<0) arr.set(x+N, y);
            else arr.set(x-1, y);
        }
        arr.print();
    }
}