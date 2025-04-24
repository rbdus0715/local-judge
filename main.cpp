#include <iostream>
#include <string>
using namespace std;

class Array
{
public:
    Array(int capacity)
    {
        this->capacity = capacity;
        elements = new int[capacity];
        for (int i=0; i<capacity; i++) elements[i] = 0;
    }
    void at(int i)
    {
        cout << elements[i] << "\n";
    }
    void set(int i, int x)
    {
        elements[i] = x;
    }
    void insert(int idx, int x)
    {
        for (int i=capacity-1; i>idx; i--)
            elements[i] = elements[i-1];
        elements[idx] = x;
    }
    void erase(int idx)
    {
        for (int i=idx; i<capacity-1; i++)
            elements[i] = elements[i+1];
        elements[capacity-1] = 0;
    }
    void print()
    {
        for (int i=0; i<capacity; i++)
            cout << elements[i] << " ";
        cout << "\n";
    }
    void change_min(int x)
    {
        int max_idx = 0;
        for (int i=1; i<capacity; i++)
            if (elements[max_idx] > elements[i])
                max_idx = i;
        elements[max_idx] = x;
    }

private:
    int* elements;
    int N;
    int capacity;
};

int main()
{
    int T; cin >> T; while (T--)
    {
        int N, Q; cin >> N >> Q;
        Array arr(N);
        while (Q--)
        {
            string s; cin >> s;
            if (s == "at")
            {
                int i; cin >> i;
                arr.at(i);
            }
            else if (s=="set")
            {
                int i, x; cin >> i >> x;
                arr.set(i, x);
            }
            else if (s=="insert")
            {
                int i, x; cin >> i >> x;
                arr.insert(i, x);
            }
            else if (s=="erase")
            {
                int i; cin >> i;
                arr.erase(i);
            }
            else if (s=="print")
            {
                arr.print();
            }
            else if (s=="change_min")
            {
                int x; cin >> x;
                arr.change_min(x);
            }
        }
    }
}