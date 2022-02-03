#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;

int main()
{
    const ll MAX_NUM = 1000000000;

    vector<ll> cnt(MAX_NUM + 5);
    for(ll i=2; i<=MAX_NUM; i++)
    {
        //소수가 아니면 건너뛰기
        if(cnt[i] > 0)
            continue;

        ll tmp=i;
        while(tmp<=MAX_NUM)
        {
            ll k=tmp;
            while(k<=MAX_NUM)
            {
                cnt[k]++;
                k+=tmp;
            }
            tmp*=i;
        }
    }

    ll even=0;
    ll odd=0;
    vector<ll> op;

    for(ll i=1; i<=MAX_NUM; i++)
    {
        if(cnt[i]%2) //홀수라면
            even++;
        else
            odd++;

        if(even<odd)
            op.push_back(i);

    }

    //반례 구하기. ^^




    //구간 나누기.
    ofstream os;
    os.open("data.txt");

    ll front = op.front();
    ll back = op.front();
    for(int i = 0; i<op.size()-1; i++)
    {
        if(op[i] + 1 != op[i+1])
        {
            os << front << ", " << back << ", \n";
            front = op[i+1];
            back = op[i+1];
        }
        else
            back = op[i+1];
    }
    os << front << ", " << back << ", \n";


    return 0;
}
