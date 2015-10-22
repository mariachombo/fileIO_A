//Maria Chombo
//22 October 2015
//Description: 

#include <iostream> //cout and cin 
#include <fstream>//files
#include <cstdlib>//random 
#include <string>//string 
using namespace std;


int main()
{
    string valA;
    ifstream fin;
    ofstream fout;
    ofstream foutTwo;
    ofstream foutThree;
    int counter = 0;
    int perChar = 0;
    int num = 0;
    int wordLength = 0;
    int countA = 0;
    int countB = 0;
    int countC = 0;
    int countD = 0;
    char valB;
    char valC;
    string newWord;
    string newWord2;
    
    fin.open("gba.txt");
    fout.open("results.txt");
   foutTwo.open("capitalize.txt");
   foutThree.open("uppercase.txt");
    
    
    if (fin.fail())//files failed 
    {
            cout << "Error opening input file" << endl;
            exit(1);
    }  
    
    if (fout.fail())//files for output fail 
    {
            cout << "Error opening output file" << endl;
            exit(1);
    }  
    /*while (fin >> valA)
    {
        cout << valA << " "; 
    }*/    
    while ( fin >>  valA)
    {
        wordLength += valA.length();
        counter ++;
        
        switch (valA.length())
        {
                case 2:
                countA ++;             
                break;
                
                case 3:
                countB ++;
                break;
                
                case 4:
                countC ++;
                break; 
                
                default:
                countD ++;
                break;    
        }
        for (int ix = 0; ix < valA.length(); ix++)
        {
               valB = toupper(valA.at(ix));
               newWord +=valB ;
        }
        newWord+=" ";
        
        for (int i = 0; i < valA.length(); i ++)
        {
                if ((i) == 0)
                {
                    newWord2+=toupper(valA.at(i));
                }
                else
                {
                    newWord2+= valA[i];
                }
        }    
         newWord2+=" ";
    }
 
        fout << "average characters per word:"  <<wordLength / counter << endl;
        fout << countA << " Words of length 2" << endl; 
       fout << countB << " Words of length 3" << endl;
       fout << countC << " Words of length 4" << endl; 
      fout << countD << " Words of length 11 or more" << endl;
      fout << counter << " total number of words" << endl; 
     foutTwo << newWord ;
     foutThree << newWord2 ;   
  
  
    fin.close();
    fout.close();
    foutTwo.close();
    foutThree.close();
    return 0;
}

