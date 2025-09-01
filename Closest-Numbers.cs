using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'closestNumbers' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static List<int> closestNumbers(List<int> arr)
    {
       if (arr.Count < 2) return new List<int>();

        arr.Sort();

        var diffs = Enumerable.Range(0, arr.Count - 1)
                              .Select(i => arr[i + 1] - arr[i])
                              .ToList();

        int minDiff = diffs.Min();

        var result = new List<int>();
        foreach (var i in Enumerable.Range(0, diffs.Count).Where(i => diffs[i] == minDiff))
        {
            result.Add(arr[i]);
            result.Add(arr[i + 1]);
        }

        return result;
    }

    
    public static List<int> closestNumbers2(List<int> arr)
    {
        var result = new List<int>();
        if (arr.Count < 2) return result;

        arr.Sort();

        var diffs = new List<int>();
        for (int i = 0; i < arr.Count - 1; i++) {
            diffs.Add(arr[i + 1] - arr[i]);
        }

        int minDiff = diffs.Min();

        for (int i = 0; i < diffs.Count; i++) {
            if (diffs[i] == minDiff) {
                result.Add(arr[i]);
                result.Add(arr[i + 1]);
            }
        }
        return result;
    }    
}


class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int n = Convert.ToInt32(Console.ReadLine().Trim());

        List<int> arr = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(arrTemp => Convert.ToInt32(arrTemp)).ToList();

        List<int> result = Result.closestNumbers(arr);

        textWriter.WriteLine(String.Join(" ", result));

        textWriter.Flush();
        textWriter.Close();
    }
}
