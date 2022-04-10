//220409
//백준 1406번 에디터 (실버 3)
//bojkr/1406

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    list<char> editor;
    string initialString;
    cin >> initialString;
    
    for(int i = 0; i<initialString.length(); i++)
        editor.push_back(initialString[i]);
    
    int numOfCommand = 0;
    cin >> numOfCommand;
    list<char>::iterator cursor = editor.end();
    
    for(int i =0; i<numOfCommand; i++)
    {
        char command;
        cin >> command;
        
        switch(command)
        {
            case 'L':
                if(cursor != editor.begin()) cursor--;
                break;
            case 'D':
                if(cursor != editor.end()) cursor++;
                break;
            case 'B':
                if(cursor != editor.begin()) cursor = editor.erase(--cursor);
                break;
            case 'P':
                char target;
                cin >> target;
                editor.insert(cursor, target);
                break;
        }
    }
    
    for(auto ch: editor) cout << ch;
   
   
}
