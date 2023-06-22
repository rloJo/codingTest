#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int A, B;
    cin >> A >> B;
    if((A!=1 && A>B) || (A==1 && B ==3))
        cout << "A" ;
    else
        cout << "B" ; 
	return 0;
}
