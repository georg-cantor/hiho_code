#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char ss[205];
char ss_low[205];

int main()
{
    while (cin>>ss)
    {
        int num = 0;
        for (int i = 0; i <= strlen(ss); i++)
        {
            ss_low[i] = tolower(ss[i]);
        }
        char *pch = NULL;
        char *ppch = NULL;
        while((pch = strstr(ss_low, "marshtomp")) != NULL)
        {
            num++;
            ppch = ss + (pch - ss_low);
            char* tmp = ppch+9;
            strncpy(ppch, "fjxmlhx", 7);
            while (tmp++)
            {
                *(tmp - 2) = *tmp;
            }
            char* ttmp = pch+9;
            strncpy(pch, "fjxmlhx", 7);
            while (ttmp++)
            {
                *(ttmp - 2) = *ttmp;
            }
        }
        ss[strlen(ss) - 2*num]  = '\0';
        cout<<ss<<endl;
    }
    return 0;
}
