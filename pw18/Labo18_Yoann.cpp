/*
Calvin Graf
18.11.2022
HEIG-VD | PRG | Labo 18

*/

#include <iostream>
#include <vector>
#include <cctype>
#include <fstream>
#include <algorithm>

using namespace std;

class Word
{
          string mot, occurence;

public:
          Word(string _mot, int _occurence)
          {
                    mot = _mot;
                    occurence = _occurence;
          }

          void ShowInfo()
          {
                    cout << mot << " " << occurence << endl;
          }
};

vector<Word> getDico(string &text)
{
          int textSize = text.size();
          string wordToAdd = " ", longestWrd = "";
          vector<Word> dico;

          for (int i = 0; i <= textSize; i++)
          {
                    if (isalpha(text[i]))
                    {
                              wordToAdd += text[i];
                    }
                    else
                    {
                              Word w(wordToAdd, 1);
                            //  dichotomie(dico, w);
                              wordToAdd.clear();
                    }
          }
          return dico;
}

int main()
{
          string fileTxt, row;
          ifstream MyReadFile("la_comedie_humaine.txt");
          while (getline(MyReadFile, row))
          {
                    // Output the text from the file
                    fileTxt += row;
          }

          vector<Word> myDico = getDico(fileTxt);
          cout << "\n---------------------\n";
          for (Word w : myDico)
                    w.ShowInfo();
          cout << "Nombre de mot(s): " << myDico.size();
          cout << "\n---------------------\n";
}
