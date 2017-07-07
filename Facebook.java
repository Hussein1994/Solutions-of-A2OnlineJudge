// Link Problem is : https://a2oj.com/p?ID=77
import java.util.*;

public class Main {

    private static Scanner s;

    public static void main(String[] args) {
        // you can use HashMap also
        s = new Scanner(System.in);
        int t = Integer.parseInt(s.nextLine());
        int N, K, max;
        ArrayList<String> names = new ArrayList<String>();
        ArrayList<Integer> num = new ArrayList<Integer>();
        String Line, name;
        for (int i = 1; i <= t; i++) {
            String[] x = (s.nextLine()).split(" ");
            N = Integer.parseInt(x[0]);
            K = Integer.parseInt(x[1]);
            while (N > 0) {
                Line = s.nextLine();
                if (Line.contains("liked")) {
                    name = Line.substring(6);
                    name = name.substring(0, name.indexOf("'s photo"));
                    if (names.contains(name)) {
                        num.set(names.indexOf(name),
                                num.get(names.indexOf(name)) + 1);
                    } else {
                        names.add(name);
                        num.add(1);
                    }
                } else {
                    name = Line.substring(13);
                    name = name.substring(0, name.indexOf("'s photo"));
                    if (names.contains(name)) {
                        num.set(names.indexOf(name),
                                num.get(names.indexOf(name)) + 1);
                    } else {
                        names.add(name);
                        num.add(1);
                    }
                }
                N--;
            }
            System.out.println("Case " + i + ":");

            while (K > 0) {

                max = Collections.max(num);
                System.out.println(names.get(num.indexOf(max)));
                num.set(num.indexOf(max), -1);
                K--;
            }

            names.clear();
            num.clear();
        }

    }
}