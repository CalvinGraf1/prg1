/*
Auteur:   Changanaqui Yoann
Date:     15.11.2022
Desc:     Binary
          École:    HEIG-VD
          Fichier:  labo16_Changanaqui_Yoann.cpp
*/
#include <iostream>
#include <random>
#include <functional>
using namespace std;

size_t GetFibo(size_t fn)
{
    size_t fnM1 = 0, fn1 = 0, fnR;

    for (size_t i = 1; i <= fn; i++)
    {
        fnR = fnM1 + fn1;
        fnM1 = fn1;
        fn1 == 0 ? fn1++ : fn1 = fnR;
    }

    return fnR;
}

string NbToBin(size_t nb)
{
    string bin = "";
    while (nb > 0)
    {
        if (nb % 2 == 0)
            bin.insert(bin.begin(), '0');
        else
            bin.insert(bin.begin(), '1');
        nb /= 2;
    }
    return bin;
}

string SumBin(string bin1, string bin2)
{
    string sum = "";
    int SIZE1 = bin1.size(), SIZE2 = bin2.size();
    bool retenue = false;

    if (SIZE2 < SIZE1)
        for (size_t i = 0; i < SIZE1 - SIZE2; i++)
            bin2.insert(bin2.begin(), '0');

    if (SIZE1 < SIZE2)
        for (size_t i = 0; i < SIZE2 - SIZE1; i++)
            bin1.insert(bin1.begin(), '0');

    SIZE1 = bin1.size() - 1, SIZE2 = bin2.size() - 1;
    // 0 + 0 = 0; 0 + 1 = 1; 1 + 1 = 1 0
    for (int i = SIZE1; i >= 0; i--)
    {
        if (retenue)
        {
            if (bin1[i] == '1')
            {
                // 1 + 1 + 0
                if (bin2[i] == '0')
                    sum.insert(sum.begin(), '0');
                // 1 + 1 + 1
                if (bin2[i] == '1')
                    sum.insert(sum.begin(), '1');

                retenue = true;
            }
            else if (bin1[i] == '0')
            {
                // 1 + 0 + 0
                if (bin2[i] == '0')
                {
                    sum.insert(sum.begin(), '1');
                    retenue = false;
                }

                // 1 + 0 + 1
                if (bin2[i] == '1')
                {
                    sum.insert(sum.begin(), '0');
                    retenue = true;
                }
            }
        }
        else
        {
            if (bin1[i] == '1')
            {
                // 0 + 1 + 0
                if (bin2[i] == '0')
                {
                    sum.insert(sum.begin(), '1');
                    retenue = false;
                }

                // 0 + 1 + 1
                if (bin2[i] == '1')
                {
                    sum.insert(sum.begin(), '0');
                    retenue = true;
                }
            }
            else if (bin1[i] == '0')
            {
                // 0 + 0 + 0
                if (bin2[i] == '0')
                    sum.insert(sum.begin(), '0');
                // 0 + 0 + 1
                if (bin2[i] == '1')
                    sum.insert(sum.begin(), '1');

                retenue = false;
            }
        }
    }

    return sum;
}

string SubBin(string bin1, string bin2)
{
    const char ZERO = '0', ONE = '1';
    int pos = bin2.size() - 1;

    // Complément à deux
    for (char l : bin2)
    {
        if (bin2[pos] == ZERO)
            bin2[pos] = ONE;
        else
            bin2[pos] = ZERO;
        pos--;
    }
    cout << bin2 << "HELP" << endl;
    bin2 = SumBin(bin2, "0001");

    // Addition du nombre négatif
    return SumBin(bin1, bin2);
}

/*
     100101
    X 10011
    --------
     100101
    100101/
 100101////
 ----------
 1010111111
*/
string MultBin(string bin1, string bin2)
{
    string result, tmp = bin1;
    int nbOfZero = 0, SIZE1 = result.size(), SIZE2 = bin2.size();

    if (empty(bin2))
        bin2 = "1";
    if (SIZE2 < SIZE1)
        for (size_t i = 0; i < SIZE1 - SIZE2; i++)
            bin1.insert(bin1.begin(), '0');
    for (size_t i = 0; i < SIZE2; i++)
        result.insert(result.begin(), '0');
    SIZE1 = result.size() - 1, SIZE2 = bin2.size() - 1;

    for (int i = SIZE2; i >= 0; i--)
    {
        if (bin2[i] == '1')
        {
            result = SumBin(tmp, result);
        }
        tmp.insert(tmp.end(), '0');
    }

    return result;
}

string DivBin(string dividende, string div)
{
    string quotient, reste, tmp = div, divO = div;
    const string ZERO = "0000";
    if (dividende == ZERO)
        return "Error - Division par 0";
    if (div < dividende)
        return "Q:" + ZERO + "\tR:" + dividende;

    while (SumBin(MultBin(div, quotient), reste) != dividende || quotient.size() == 0)
    {
        // Add 0 jusqu'à avoir le PLUS GRAND dans Dividende
        // Add 1 au quotient
        // Sub PLUS GRAND au dividende
        // Si div PLUS GRAND que dividende --> reste = dividende
        // Reset tmp et div puis recommencer

        // Ajoute '0' jusqu'à avoir le nombre le PLUS GRAND qui rentre dans divididende
        for (int i = div.size(); i < dividende.size(); i++)
        {
            tmp.insert(tmp.end(), '0');
            if ((tmp.size() != dividende.size() && tmp > dividende) || tmp < dividende)
                div.insert(div.end(), '0');
        }

        // Compare les résultats
        if (div > dividende)
        {
            quotient.insert(quotient.begin(), '1');
            dividende = SubBin(dividende, div);
            if (dividende.size() > 5)
                dividende = dividende.substr(2, dividende.size() - 2);
            else if (dividende.size() == 5)
                dividende = dividende.substr(1, dividende.size() - 1);
            tmp = divO;
            div = divO;
        }
        else
        {
            quotient.insert(quotient.end(), '0');
            reste = dividende;
            break;
        }
    }

    return "Q:" + quotient + "\tR:" + reste;
}

int main()
{
    const size_t nb1 = 13, nb2 = 5;
    const string bin1 = NbToBin(nb1),
        bin2 = NbToBin(nb2);

    cout << "Suite de Fibonacci: " << GetFibo(nb1) << endl;                     // 21
    cout << "Conversion de " << nb1 << " en binaire: " << NbToBin(nb1) << endl; // 0001
    cout << bin1 << " + " << bin2 << " = " << SumBin(bin1, bin2) << endl;       // 101001 + 11001: 100110 OK
    cout << bin1 << " - " << bin2 << " = " << SubBin(bin2, bin1) << endl;       // 101001 - 11001: 100100
    cout << bin1 << " x " << bin2 << " = " << MultBin(bin1, bin2) << endl;      // 100101 x 11001 = 0011 1001 1101
    cout << "100001" << " / " << "101" << " = " << DivBin("100001", "101") << endl;       // 100001 / 101 = Q: 110 R: 011 (Presque)
}
