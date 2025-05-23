#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */

vector<int> generatePrimes(int q) {
    vector<int> primes;
    int num = 2; // Start from first prime
    while (primes.size() < q) {
        bool isPrime = true;
        for (int p : primes) {
            if (num % p == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) primes.push_back(num);
        num++;
    }
    return primes;
}

vector<int> waiter(vector<int> number, int q) {
    vector<int> result;
    vector<int> primes = generatePrimes(q);
    
    stack<int> A, B;
    for (int num : number) A.push(num);

    for (int i = 0; i < q; i++) {
        stack<int> newA;
        while (!A.empty()) {
            int val = A.top();
            A.pop();
            if (val % primes[i] == 0) {
                B.push(val);
            } else {
                newA.push(val);
            }
        }
        while (!B.empty()) {
            result.push_back(B.top());
            B.pop();
        }
        A = newA; // Carry forward remaining elements
    }
    
    while (!A.empty()) {
        result.push_back(A.top());
        A.pop();
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}