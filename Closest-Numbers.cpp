// from https://www.hackerrank.com/challenges/closest-numbers/forum by bbm833
vector<int> closestNumbers(vector<int> arr)
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
