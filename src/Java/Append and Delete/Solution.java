import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the appendAndDelete function below.
    static String appendAndDelete(String s, String t, int k) {

        String result = "No";
        int sLength = s.length();
        int tlength = t.length();
        int len = sLength > tlength ? tlength : sLength;
        int matchCharCount = 0;
        for (int i = 0; i < len; i++) {
            if (s.charAt(i) == t.charAt(i)) {
                matchCharCount++;
            } else {
                break;
            }
        }
        int minOpRequired = sLength + tlength - 2 * matchCharCount;
        if (k == minOpRequired) {
            return result = "Yes";
        } else if (k > minOpRequired && (k - minOpRequired) % 2 == 0 || k >= (sLength + tlength)) {
            result = "Yes";
        }
        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String t = scanner.nextLine();

        int k = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String result = appendAndDelete(s, t, k);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
