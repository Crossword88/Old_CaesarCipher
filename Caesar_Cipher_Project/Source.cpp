#include <iostream> 

using namespace std;

string encryption(char abecede[], char Message[], int sz)
{
    int shift = 0;
    char Direction;
    int szM = strlen(Message);
    cout << szM << endl;
    cout << "Enter number of shifts: ";
    cin >> shift;
    cout << "Enter Direction ('+' - right, '-' - left): ";
    cin >> Direction;
    int gov = 0;
    if (Direction == '+')
        for (int j = 0; j < szM; j++)
            for (int i = 0; i < sz; i++)
                if (Message[j] == abecede[i])
                {
                    if (i + shift < sz)
                        Message[j] = abecede[i + shift];
                    else if (i + shift >= sz)
                    {
                        for (int r = i; r < sz; r++)
                            gov++;
                        Message[j] = abecede[shift - gov];
                        gov = 0;
                    }
                    break;
                }
    if (Direction == '-')
        for (int j = 0; j < szM; j++)
            for (int i = 0; i < sz; i++)
                if (Message[j] == abecede[i])
                {
                    if (i - shift >= 0)
                        Message[j] = abecede[i - shift];
                    else if (i - shift < 0)
                    {
                        for (int r = i; r > 0; r--)
                            gov++;
                        short int q = shift - gov;
                        Message[j] = abecede[sz - q];
                        gov = 0;
                    }
                    break;
                }
    return Message;
}
 
int main()
{
    const int sz = 26;
    char Message[] = "";
    char abecede[sz] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    while (true)
    {
        cout << "Enter the message that you want to cipher/decipher: ";
        cin >> Message;
        cout <<encryption(abecede, Message, sz);
        cout << endl << endl;
    }
    return 0;
}

//+- old shit code