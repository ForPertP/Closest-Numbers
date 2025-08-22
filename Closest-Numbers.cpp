#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'closestNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> closestNumbers(vector<int> arr)
{
    vector<int> result;
    if (arr.size() < 2) return result;

    sort(arr.begin(), arr.end());

    vector<int> diffs(arr.size() - 1);
    transform(arr.begin(), arr.end() - 1, arr.begin() + 1, diffs.begin(),
              [](int a, int b) { return b - a; });

    int minDiff = *min_element(diffs.begin(), diffs.end());

    for (size_t i = 0; i < diffs.size(); ++i)
    {
        if (diffs[i] == minDiff)
        {
            result.push_back(arr[i]);
            result.push_back(arr[i + 1]);
        }
    }
    return result;
}

// from https://www.hackerrank.com/challenges/closest-numbers/forum by bbm833
vector<int> closestNumbers2(vector<int> arr)
{
    std::vector<int> result{}; 

    if (arr.size() == 0)
    {
        return result;
    }

    std::sort(arr.begin(), arr.end());
    int min = INT32_MAX;

    for (int i = 0; i < arr.size()-1; ++i)
    {
        const int difference = arr[i+1] - arr[i];
        
        if (difference < min)
        {
            result.clear();
            result.push_back(arr[i]);
            result.push_back(arr[i+1]);
            min = difference;
        }
        else if (difference == min)
        {
            result.push_back(arr[i]);
            result.push_back(arr[i+1]);
        }
    }

    return result;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = closestNumbers(arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
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
