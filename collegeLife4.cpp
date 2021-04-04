#include <bits/stdc++.h>
using namespace std;

set<long double> cost;
unordered_map<int, pair<int, int>> A, B;
unordered_map<int, int> C;

void calcCost(int op, int n, int e, int h, int a, int b, int cc)
{
    int t = 0, t1 = 0;
    long double c = 0;
    switch (op)
    {

    //ABC
    case 0:
        if (e > 0)
        {
            t = t + A.find(e)->second.first;
            e = A.find(e)->second.second;
        }
        if (t >= n)
        {
            cost.insert(a * n);
            return;
        }
        else
            c = c + t * a;

        if (B.find(h) == B.end() && h > 0)
            B.insert(pair<int, pair<int, int>>(h, pair<int, int>(h / 3, h % 3)));
        if (h > 0)
        {
            t1 = t1 + B.find(h)->second.first;
            h = B.find(h)->second.second;
        }
        if (t1 >= (n - t))
        {
            t1 = n - t;
            c = c + t1 * b;
            cost.insert(c);
            return;
        }
        else
        {
            c = c + t1 * b;
            t = t + t1;
            t1 = 0;
        }

        if (C.find(min(e, h)) == C.end() && min(e, h) > 0)
            C.insert(pair<int, int>(min(e, h), min(e, h)));
        if (min(e, h) < (n - t))
        {
            return;
        }
        else
        {
            c = c + (min(min(e, h), (n - t)) * cc);
            cost.insert(c);
            return;
        }

    //ACB
    case 1:
        if (e > 0)
        {
            t = t + A.find(e)->second.first;
            e = A.find(e)->second.second;
        }
        if (t >= n)
        {
            cost.insert(a * n);
            return;
        }
        else
            c = c + t * a;

        if (C.find(min(e, h)) == C.end() && min(e, h) > 0)
            C.insert(pair<int, int>(min(e, h), min(e, h)));
        if (min(e, h) >= (n - t))
        {
            c = c + min(e, h) * cc;
            cost.insert(c);
            return;
        }
        else
        {
            c = c + (min(e, h) * cc);
            h = h - min(e, h);
            t = t + min(e, h);
        }

        if (B.find(h) == B.end() && h > 0)
            B.insert(pair<int, pair<int, int>>(h, pair<int, int>(h / 3, h % 3)));
        if (h > 0)
        {
            t1 = t1 + B.find(h)->second.first;
        }
        if (t1 < (n - t))
        {
            return;
        }
        else
        {
            c = c + min(t1, (n - t)) * b;
            cost.insert(c);
            return;
        }

    //BAC
    case 2:
        if (h > 0)
        {
            t = t + B.find(h)->second.first;
            h = B.find(h)->second.second;
        }
        if (t >= n)
        {
            cost.insert(b * n);
            return;
        }
        else
            c = c + t * b;

        if (A.find(e) == A.end() && e > 0)
            A.insert(pair<int, pair<int, int>>(e, pair<int, int>(e / 2, e % 2)));
        if (e > 0)
        {
            t1 = t1 + A.find(e)->second.first;
            e = B.find(e)->second.second;
        }
        if (t1 >= (n - t))
        {
            t1 = n - t;
            c = c + t1 * a;
            cost.insert(c);
            return;
        }
        else
        {
            c = c + t1 * a;
            t = t + t1;
            t1 = 0;
        }

        if (C.find(min(e, h)) == C.end() && min(e, h) > 0)
            C.insert(pair<int, int>(min(e, h), min(e, h)));
        if (min(e, h) < (n - t))
        {
            return;
        }
        else
        {
            c = c + (min(e, h) * cc);
            cost.insert(c);
            return;
        }

    //BCA
    case 3:
        if (h > 0)
        {
            t = t + B.find(h)->second.first;
            h = B.find(h)->second.second;
        }
        if (t >= n)
        {
            cost.insert(b * n);
            return;
        }
        else
            c = c + t * b;

        if (C.find(min(e, h)) == C.end() && min(e, h) > 0)
            C.insert(pair<int, int>(min(e, h), min(e, h)));
        if (min(e, h) >= (n - t))
        {
            c = c + min(e, h) * cc;
            cost.insert(c);
            return;
        }
        else
        {
            c = c + (min(e, h) * cc);
            e = e - min(e, h);
            t = t + min(e, h);
        }

        if (A.find(e) == A.end() && e > 0)
            A.insert(pair<int, pair<int, int>>(e, pair<int, int>(e / 2, e % 2)));
        if (e > 0)
        {
            t1 = t1 + A.find(e)->second.first;
        }
        if (t1 < (n - t))
        {
            return;
        }
        else
        {
            c = c + min(t1, (n - t)) * a;
            cost.insert(c);
            return;
        }

    //CAB
    case 4:
        t = min(e, h);
        h = h - t;
        e = e - t;
        if (t >= n)
        {
            cost.insert(cc * n);
            return;
        }
        else
            c = c + t * cc;

        if (A.find(e) == A.end() && e > 0)
            A.insert(pair<int, pair<int, int>>(e, pair<int, int>(e / 2, e % 2)));
        if (e > 0)
        {
            t1 = t1 + A.find(e)->second.first;
        }
        if (t1 >= (n - t))
        {
            t1 = n - t;
            c = c + t1 * a;
            cost.insert(c);
            return;
        }
        else
        {
            c = c + t1 * a;
            t = t + t1;
            t1 = 0;
        }

        if (B.find(h) == B.end() && h > 0)
            B.insert(pair<int, pair<int, int>>(h, pair<int, int>(h / 3, h % 3)));
        if (h > 0)
        {
            t1 = t1 + B.find(h)->second.first;
        }
        if (t1 >= (n - t))
        {
            t1 = n - t;
            c = c + t1 * b;
            cost.insert(c);
            return;
        }
        else
        {
            return;
        }

    //CBA
    case 5:
        t = min(e, h);
        h = h - t;
        e = e - t;
        if (t >= n)
        {
            cost.insert(cc * n);
            return;
        }
        else
            c = c + t * cc;

        if (B.find(h) == B.end() && h > 0)
            B.insert(pair<int, pair<int, int>>(h, pair<int, int>(h / 3, h % 3)));
        if (h > 0)
        {
            t1 = t1 + B.find(h)->second.first;
        }
        if (t1 >= (n - t))
        {
            t1 = n - t;
            c = c + t1 * b;
            cost.insert(c);
            return;
        }
        else
        {
            c = c + t1 * b;
            t = t + t1;
            t1 = 0;
        }

        if (A.find(e) == A.end() && e > 0)
            A.insert(pair<int, pair<int, int>>(e, pair<int, int>(e / 2, e % 2)));
        if (e > 0)
        {
            t1 = t1 + A.find(e)->second.first;
        }
        if (t1 >= (n - t))
        {
            t1 = n - t;
            c = c + t1 * a;
            cost.insert(c);
            return;
        }
        else
        {
            return;
        }

    default:
        return;
    }
}

int main()
{

    int t = 0, n = 0, e = 0, h = 0, a = 0, b = 0, c = 0;
 /*
    A.insert(pair<int, pair<int, int>>(1, pair<int, int>(0, 1)));
    A.insert(pair<int, pair<int, int>>(2, pair<int, int>(1, 0)));
    B.insert(pair<int, pair<int, int>>(1, pair<int, int>(0, 1)));
    B.insert(pair<int, pair<int, int>>(2, pair<int, int>(0, 2)));
    B.insert(pair<int, pair<int, int>>(3, pair<int, int>(1, 0)));
    C.insert(pair<int, int>(1, 1));
*/
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> e >> h >> a >> b >> c;

//        if(e==0 && n>3*h)
//            return(-1)

        if (A.find(e) == A.end() && e > 0)
        {
            A.insert(pair<int, pair<int, int>>(e, pair<int, int>(e / 2, e % 2)));
        }
        if (B.find(h) == B.end() && h > 0)
        {
            B.insert(pair<int, pair<int, int>>(h, pair<int, int>(h / 3, h % 3)));
        }
        if (C.find(e) == C.end())
        {
            C.insert(pair<int, int>(e, e));
        }
        if (C.find(h) == C.end())
        {
            C.insert(pair<int, int>(h, h));
        }

        for (int j = 0; j < 6; j++)
            calcCost(j, n, e, h, a, b, c);

        if (cost.empty())
        {
            cout << "-1\n";
        }
        else
        {
            cout << *cost.begin() << "\n";
        }

        cost.clear();
    }

    return (0);
}