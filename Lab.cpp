#include <iostream>
using namespace std;
/*
this is a multi Line 
comment
*/
// single linee
void Search(int toSearch,int array[]){
    bool flag = false;
    for (int i = 0; i < 6; i++)
    {
        if (toSearch == array[i])
        {
            flag = true;
            cout << "Value Exists at index " << i ;
            break;
        }
    }
    if (flag==false)
    {
        cout << "Value Does not exist";
    }
}
int main(){
    int array [] = {14,52,24,88,98,34};
    int toSearch;
    cout << "Enter value you want to search : " ;
    cin >> toSearch ;
    Search(toSearch,array);
    return 0;
}