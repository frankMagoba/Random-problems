import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the flatlandSpaceStations function below.
    static int flatlandSpaceStations(int n, int[] c) {
           int i=0;
  int m=c.length;
  int max=0;
  int diff=90;
  int j,x;
  int temp=1;
 
  for(i=0;i<n;i++)
  {
  temp=1;
  for( j=0;j<m;j++)
    {
    if(c[j]==i)
      {
      temp=0;
      break;
      }
    }
 
    if(temp!=0)
     {
      diff=Math.abs(c[0]-i);
      for(j=1;j<m;j++)
       {
        x=Math.abs(c[j]-i);
        if(x<diff)
          {
          diff=x;
          } 
        }
      if(diff>max)
        max=diff;
       }
   }
    return max;


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nm[0]);

        int m = Integer.parseInt(nm[1]);

        int[] c = new int[m];

        String[] cItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < m; i++) {
            int cItem = Integer.parseInt(cItems[i]);
            c[i] = cItem;
        }

        int result = flatlandSpaceStations(n, c);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
