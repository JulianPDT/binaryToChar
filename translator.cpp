#include <iostream>
#include <sstream> 
#include <cmath>


char binToInt( int l_binarna)
{
    int l_decymalna = 0;
    for(int i=0;i<8;i++)
    {
        int potega = pow(10,i);
        if(potega%9 == 0)
        {
            potega += 1;
        }

        if((l_binarna/potega)%2 == 1)
        {
            int potega2 = pow(2,i);
            l_decymalna += potega2;
        }
    }

    return l_decymalna;
}


main()
{
    std::string seq = "";
    int length = 0, num_of_elem = 0;

    std::cout << "Podaj sekwencje liczb binarnych: ";
    std::getline(std::cin, seq);

    length = seq.length();

    if(length>7)
    {
        if((length + 1)%9 != 0)
        {
            return 1;
        }

        num_of_elem = (length + 1)/9;
    }
    else
    {
        std::cout << "Niepoprawna sekwencja!";
        return 1;
    }

    std::istringstream iss (seq);
    for (int n=0; n<num_of_elem; n++)
    {
        int val;
        iss >> val;
        std::cout << binToInt(val);
    }

    return 0;
}
