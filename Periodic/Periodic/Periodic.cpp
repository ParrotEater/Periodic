#include <iostream>
using namespace std;

void computeLPS(string pat, int* lps)
{
    int j = 0;

    lps[0] = 0; // lps[0] is always 0 

    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0) {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int KMPSearch(const string& pat, const string& txt)
{
    int* lps = new int[pat.size()];

    computeLPS(pat, lps);

    int i = 0;
    int j = 0;
    int counter = 0;
    while (i < txt.size()) {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == pat.size()) {                    
            counter++;
            j = lps[j - 1];
        }
        else if (i < txt.size() && pat[j] != txt[i]) {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
    return counter;
}


bool IsKPeriodic(string str, int K)
{
    if(str.size()%K != 0) //проверяем размерность, если, допустим, строка из 5 символов, а К = 2, то уже будет некратно
        return false;
    string substr;
    for (int i = 0; i < K; i++) //находим подстроку
        substr += str[i];
    
    if (KMPSearch(substr, str) == str.size() / K)
        return true;
    else
        return false;    
}
int main()
{
    setlocale(LC_ALL, "RU");
    cout << "введите строку: ";
    string str;
    cin >> str;

    cout << "введите K: ";
    int K;
    cin >> K;
    if (K <= 0 || K > str.size())
    {
        cout << "K должен быть больше нуля и меньше длины самой строки";
        return -1;
    }

    IsKPeriodic(str, K) ? cout << "является" : cout << "не является";

}

