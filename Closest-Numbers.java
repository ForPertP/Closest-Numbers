import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'closestNumbers' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static List<Integer> closestNumbers(List<Integer> arr) {
        if (arr.size() < 2) return new ArrayList<>();

        Collections.sort(arr);

        List<Integer> diffs = IntStream.range(0, arr.size() - 1)
                .map(i -> arr.get(i + 1) - arr.get(i))
                .boxed()
                .collect(Collectors.toList());

        int minDiff = Collections.min(diffs);

        List<Integer> result = new ArrayList<>();
        IntStream.range(0, diffs.size())
                .filter(i -> diffs.get(i) == minDiff)
                .forEach(i -> {
                    result.add(arr.get(i));
                    result.add(arr.get(i + 1));
                });

        return result;
    }


    public static List<Integer> closestNumbers2(List<Integer> arr) {
        List<Integer> result = new ArrayList<>();
        if (arr.size() < 2) return result;

        Collections.sort(arr);

        List<Integer> diffs = new ArrayList<>();
        for (int i = 0; i < arr.size() - 1; i++) {
            diffs.add(arr.get(i + 1) - arr.get(i));
        }

        int minDiff = Collections.min(diffs);

        for (int i = 0; i < diffs.size(); i++) {
            if (diffs.get(i) == minDiff) {
                result.add(arr.get(i));
                result.add(arr.get(i + 1));
            }
        }
        return result;
    }
}


public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        List<Integer> result = Result.closestNumbers(arr);

        bufferedWriter.write(
            result.stream()
                .map(Object::toString)
                .collect(joining(" "))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
