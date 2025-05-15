#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'substrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING n as parameter.
 */
//48=0
int const mod=(1e9+7);
int substrings(string n) {
    int le=n.size();
    long long tsum=0,csum=0;
    for(int i=0;i<le;i++){
        int d=n[i]-'0';
        csum=(csum*10+(i+1)*d)%mod;
        tsum=(tsum+csum)%mod;
    }
    return tsum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
