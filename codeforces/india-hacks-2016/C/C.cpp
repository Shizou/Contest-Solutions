#include<bits/stdc++.h>
#define needforspeed ios::sync_with_stdio(0);cin.tie(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define mp3(a,b,c) make_pair(a,make_pair(b,c))
#define mp4(a,b,c,d) make_pair(make_pair(a,b),make_pair(c,d))
#define trace1(a) cout << (a) << endl;
#define trace2(a,b) cout << (a)  << " " << (b) << endl;
#define trace3(a,b,c) cout << (a)  << " " << (b) << " " << (c) << endl;
#define trace4(a,b,c,d) cout << (a)  << " " << (b) << " " << (c) <<  " " << (d) << endl;
#define trace5(a,b,c,d,e) cout << (a)  << " " << (b) << " " << (c) <<  " " << (d) <<  " " << (e) << endl;
#define ms(a,b) memset( (a), (b), sizeof(a))
#define fi(x) freopen(x,"r",stdin)
#define fo(x) freopen(x,"w",stdout)
#define wi(x) for(int  (i) = (0); (i) < (x);(i)++)
#define wj(x) for(int  (j) = (0); (j) < (x);(j)++)
#define wk(x) for(int  (k) = (0); (k) < (x);(k)++)
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define xx first
#define yy second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN (int)1e9
#define inf 0x3f3f3f3f
#define nullptr 0
#define db 0
using namespace std;

int N;
int arr[150005];

bool valid(int a, int b)
{
     if(a >= 0 && a < N && b >= 0 && b < N)
     {
         swap(arr[a], arr[b]);
         bool pos = true;
         for(int i = 0;i < N-1;i++)
         {
            if((i+1)%2 != 0 && arr[i] >= arr[i+1])
            {
                pos &= false;
                break;
            }
            else if((i+1)%2 == 0 && arr[i] <= arr[i+1])
            {
                pos &= false;
                break;
            }
         }
         swap(arr[b], arr[a]);
         return pos;
     }
     else
     {
        return false;
     }
}

int main() {
  fi("C-input.txt");
  needforspeed;
  cin >> N;
  for(int i = 0;i < N;i++)
  {
    cin >> arr[i];
  }
  int cnt = 0;
  for(int i = 0;i < N-1;i++)
  {
        if((i+1)%2 != 0 && arr[i] >= arr[i+1])
        {
            cnt++;
        }
        else if((i+1)%2 == 0 && arr[i] <= arr[i+1])
        {
            cnt++;
        }
  }
  if(cnt > 2)
     cout << 0 << endl;
  else if(cnt == 2)
  {
     vector<int>ind;
     for(int i = 0;i < N-1;i++)
     {
        if((i+1)%2 != 0 && arr[i] >= arr[i+1])
        {
            ind.pb(i);
        }
        else if((i+1)%2 == 0 && arr[i] <= arr[i+1])
        {
            ind.pb(i);
        }
     }
     int cnt = 0;
     cnt += valid(ind[0],ind[1]) ? 1:0;
     cnt += valid(ind[0]-1,ind[1]) ? 1:0;
     cnt += valid(ind[0]+1,ind[1]) ? 1:0;
     cnt += valid(ind[0],ind[1]-1) ? 1:0;
     cnt += valid(ind[0],ind[1]+1) ? 1:0;
     cout << cnt << endl;
  }
  else if(cnt == 1)
  {
     int ind = -1;
     for(int i = 0;i < N-1;i++)
     {
        if((i+1)%2 != 0 && arr[i] >= arr[i+1])
        {
            ind = i;
            break;
        }
        else if((i+1)%2 == 0 && arr[i] <= arr[i+1])
        {
            ind = i;
            break;
        }
     }
     int cnt = 0;
     for(int i = 0;i < N;i++)
     {
        if(i == ind)continue;
        swap(arr[i], arr[ind]);
        bool pos = true;
        // first index
        if((i+1)%2 != 0)
        {
            if(arr[i] >= arr[i+1])
                pos &= false;
        }
        else
        {
            if(arr[i] <= arr[i+1])
                pos &= false;
        }
        // second index
        if((ind+1) % 2 != 0)
        {
            if(arr[ind] >= arr[ind+1])
                pos &= false;
        }
        else
        {
            if(arr[ind] <= arr[ind+1])
                pos &= false;
        }
        cnt+= pos ? 1:0;
        swap(arr[i], arr[ind]);

        if(i != N-1)
        {
            swap(arr[i], arr[ind+1]);
            pos = true;
            // first index
            if((i+1)%2 != 0)
            {
                if(arr[i] >= arr[i+1])
                    pos &= false;
            }
            else
            {
                if(arr[i] <= arr[i+1])
                    pos &= false;
            }
            // second index
            if((ind+1) % 2 != 0)
            {
                if(arr[ind] >= arr[ind+1])
                    pos &= false;
            }
            else
            {
                if(arr[ind] <= arr[ind+1])
                    pos &= false;
            }
            cnt += pos ? 1:0;
            swap(arr[i], arr[ind+1]);
        }

     }
     cout << cnt << endl;
  }
  return 0;
}