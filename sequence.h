#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Sequence
{
    private:
    double first;
    double next;

    public:
    Sequence()
    {
        first = 0;
        next = (2*first*first - 10*first + 80)/(first + 8);
    }

    Sequence(const Sequence& other)
    {
        first = other.first;
        next = other.next;
    }

    Sequence(double _first)
    {
        first = _first;
        next = (2*first*first - 10*first + 80)/(first + 8);
    }

    bool operator==(const Sequence& other)
    {
        return (first==other.first);
    }

    void read()
    {
        cout << "Enter first (lambda) number of the sequnce: " << endl;
        cin >> first;
    }

    void print()
    {
        cout << "Sequence: " << endl << first << " " << next << endl; 
    }

};
