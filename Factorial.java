// Link Problem is : https://a2oj.com/p?ID=412
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    private static Scanner s;

    public static void main(String[] args) {

        s = new Scanner(System.in);
        BigInteger [] arr = new BigInteger [53];
        arr[0]=new BigInteger("0");
        arr[1]=new BigInteger ("1");
        arr[2]=new BigInteger ("2");
        arr[3]=new BigInteger ("6");
        
         for (int i = 4; i <= 52; i++) {
                arr[i] = arr[i - 1].multiply(new BigInteger(String.valueOf(i)));
            }
         int v=s.nextInt();
         System.out.println(arr[v]);
    
    }
}