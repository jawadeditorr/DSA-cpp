#include <iostream>
using namespace std;
int main(){
    //static numbers square
    cout << "static numbers square" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            cout << j;
        }
        cout << "\n";
    }

    //variable number square
    cout << "variable number square"<< endl;
    int count = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << count;
            count++;
        }
        cout << "\n";
    }

    //triangle
    cout << "Triangle" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    // upside down triangle
    cout << "upside down triangle" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= 3-i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    //number triangle
    cout << "number Triangle" << endl;
    for (int i = 1; i < 4; i++)
    {
        int c = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << c;
            c++;
        }
        cout << "\n";
    }
    //reverse number triangle
    cout << "reverse number triangle" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j > 0; j--)
        {
            cout << j;
        }
        cout << "\n";
    }
    //inverted number triangle
    cout << "inverted number triangle" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 5-i; j++)
        {
            cout << j+1;
        }
        cout << "\n";
    }
    //pyramid
    cout << "pyramid" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5-i-1; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i+1; j++)
        {
            cout << j;
        }
        for (int j = i; j>0; j--)
        {
            cout << j;
        }
        cout << endl;
    }
    //hollow diamond
    cout << "Hollow Diamond" << endl;
    //top --->part
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5-i-1; j++)
        {
            cout << " ";
        }
        cout << "*";
        if (i!=0)
        {    
            for (int j = 0; j < 2*i-1; j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
    //bottom--> part
    for (int i = 0; i < 5-1; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout << " ";
        }
        cout << "*";
        if (i!=5-2)
        {
            for (int j = 0; j < 2*(5-i)-5; j++)
            {
                cout << " ";
            }
            cout << "*";
        }        
        cout << endl;
    }
    //butterfly
    cout << "Butterfly" << endl;
    int n=3;
    //top--> part    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2*(n-i); j++)
        {
            cout << " ";
        }

        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        
        cout << "\n";
    }
    //bottom -->part
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n-i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2*i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j <= n-i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}