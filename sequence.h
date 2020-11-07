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
    }

    Sequence(const Sequence& other)
    {
        first = other.first;
    }

    Sequence(double _first)
    {
        if (_first != -8)
        {
            first = _first;
        } else
        {
            first = 0; 
        }
        
    }

    bool operator==(const Sequence& other) const
    {
        return (first==other.first);
    }

    double generateNext(double previous) const
    {
        return (2*previous*previous - 10*previous + 80)/(previous + 8);
    }

    void read()
    {
        cout << "Enter (lambda) first number of the sequence: " << endl; 
        double number;
        cin >> number;
        while (number == -8)
        {
            cout << "Value -8 is not in domain." << endl << "Enter again: ";
            cin >> number;
        }
        first = number; 
    }

    void convergency() const  
    {
        if (first < -8)
        {
            cout << "Not convergent, monotonously decreasing: n--->inf => {an}--->-inf" << endl << endl;
        }
        if (first > -8 && first < 0)
        {
            cout << "Not convergent, monotonously increasing: n--->inf => {an}--->+inf" << endl << endl;
        }
        if (first == 0) 
        {
            cout << "Convergent, monotonous: n--->inf => {an}--->l, l = 10" << endl << endl;
        }
        if (first > 0)
        {
            if (first < 1)
            {
                cout << "Convergent, monotonously decreasing: n--->inf => {an}--->l, l = 8" << endl << endl;
            }
            if (first == 1) 
            {
                cout << "Convergent, monotonous: n--->inf => {an}--->l, l = 8" << endl << endl;
            }
            if (first > 1 && first < 8)
            {
                cout << "Convergent, monotonously increasing: n--->inf => {an}--->l, l = 8" << endl << endl;
            }
            if (first == 8) 
            {
                cout << "Convergent, monotonous: n--->inf => {an}--->l, l = 8" << endl << endl;
            }
            if (first > 8 && first < 10)
            {
                cout << "Convergent, monotonously decreasing: n--->inf => {an}--->l, l = 8" << endl << endl;
            }
        }
        if (first == 10)
        {
            cout << "Convegent, monotonous: n--->inf => {an}--->l, l = 10" << endl << endl;
        }
        if (first > 10)
        {
            cout << "Not convergent, monotonously increasing: n--->inf => {an}--->+inf" << endl << endl;
        }
    }

    double getElementByIndex(int index) const
    {
        double result = first;
        if (index == 1)
        {
            return result;
        }
        result = generateNext(first);
        for (int i = 0; i < index - 2; i++)
        {
            double tmp = result;
            result = generateNext(tmp);
        }
        return result;
    }

    void print()
    {
        cout << endl;
        cout << "Sequence: lambda = " << first << ": " << endl; 
        convergency();
        cout << "Enter five indeces" << endl << endl; 
        int indeces[5];
        for (int i = 0; i < 5; i++)
        {
            cin >> indeces[i];
        }
        for (int i = 0; i < 5; i++)
        {
            cout << "a" << indeces[i] << " = " << getElementByIndex(indeces[i]) << endl; 
        } 
        cout << endl;
    } 
}; 
