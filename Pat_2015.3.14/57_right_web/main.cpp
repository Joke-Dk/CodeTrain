//Ë¼Â·ºÜÇÉÃî£¡£¡£¡
#include <iostream>
#include <stack>
#include <set>
#include<vector>
#include <functional>
using namespace std;
multiset<int> uppers;
stack<int> stk;
multiset<int,greater<int> > lowers;
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("sample.in", "r", stdin);
    //freopen("D:\\out.txt", "w", stdout);
#endif
    int N;
    char ch[80];
    int n(0);
    while (scanf("%d", &N) != EOF)
    {
        int mid = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%s", ch);
            switch (ch[1])
            {
            case('u') :
                scanf("%d", &n);
                stk.push(n);
                if (n>mid)
                {
                    uppers.insert(n);
                }
                else
                {
                    lowers.insert(n);
                }
                if (uppers.size() > lowers.size())
                {
                    lowers.insert(*uppers.begin());
                    uppers.erase(uppers.begin());
                }
                else if (lowers.size() > uppers.size() + 1)
                {
                    uppers.insert(*lowers.begin());
                    lowers.erase(lowers.begin());
                }
                mid = *lowers.begin();
                break;
            case('o'):
                if (stk.empty())
                {
                    printf("%s\n", "Invalid");
                }
                else
                {
                    int t = stk.top();
                    stk.pop();
                    printf("%d\n",t);
                    if (t > *lowers.begin())
                    {
                        uppers.erase(uppers.find(t));
                    }
                    else
                    {
                        lowers.erase(lowers.find(t));
                    }
                    if (stk.empty())
                    {
                        mid = 0;
                    }
                    else
                    {
                        if (uppers.size() > lowers.size())
                        {
                            lowers.insert(*uppers.begin());
                            uppers.erase(uppers.begin());
                        }
                        else if (lowers.size() > uppers.size() + 1)
                        {
                            uppers.insert(*lowers.begin());
                            lowers.erase(lowers.begin());
                        }
                        mid = *lowers.begin();
                    }
                }
                     break;
            case('e'):
                if (stk.empty())
                {
                    printf("%s\n", "Invalid");
                }
                else
                {
                    printf("%d\n", mid);
                }
                     break;
            }
                
        }
    }
    
    return 0;
}