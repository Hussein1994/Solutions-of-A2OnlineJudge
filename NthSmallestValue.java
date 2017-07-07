// Link Problem is : https://a2oj.com/p?ID=159
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Main {

    public static void main(String[] args) {
        
        Scanner s = new Scanner (System.in);
        int i=0;
        int T=s.nextInt();
        List <Integer> list =new ArrayList();        
        String Line; 
        while (i<=T)
        {
            
            Line =s.nextLine();
             StringTokenizer st = new StringTokenizer(Line);
             while (st.hasMoreTokens()) {
         
                list.add(Integer.parseInt(st.nextToken()));
                
             }
             
                  Collections.sort(list);

                  
                  if (2<list.size())
                  System.out.println(list.get(1));

                 list.clear();
                  i++;
        }
        

    }

}