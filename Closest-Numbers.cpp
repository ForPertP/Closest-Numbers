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

vector<int> closestNumbers(vector<int> arr) {

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
