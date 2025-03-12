#include <iostream>
#define N 10

using namespace std;

int main() 
{
    int v[N]; 
    int* ptr = v;  
    int max = *ptr;

     for (int i = 0; i < N; ++i) 
    {
        ptr++;  
        if (*ptr > max) 
        {
            max = *ptr;  
        }
    }

    cout << "il massimo e:" << max << endl;

    return 0;
}
