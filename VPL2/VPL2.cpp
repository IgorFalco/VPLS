#include <iostream>
#include <string>

int main()
{
    int A = 0 ,E = 0,I = 0,O = 0,U = 0;

    std::string str;
    std::cout << "Digite uma palavra\n";
    std::cin >> str;
    
    for(int i =0; i<str.length(); i++)
    {
        if(str[i] == 'a')
            A++;
        if(str[i] == 'e')
            E++;
        if(str[i] == 'i')
            I++;
        if(str[i] == 'o')
            O++;
        if(str[i] == 'u')
            U++;
    }
    if( A > 0 )
        std::cout << "a " << A << std::endl;
    if( E > 0 )
        std::cout << "e " << E << std::endl;
    if( I > 0 )
        std::cout << "i " << I << std::endl;
    if( O > 0 )
        std::cout << "o " << O << std::endl;
    if( U > 0 ) 
        std::cout << "u " << U << std::endl;

    return 0;
}