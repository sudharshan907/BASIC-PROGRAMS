package com.company1;
import java.util.Scanner;

interface hdfc {
   void t1(int a,int b);
}

interface icici{
    void t2(int a,int b);
}

class flipkart implements hdfc,icici {
    int f=0;
   public void t1(int a,int b){
        f=f+b;
        System.out.println(f+" "+(a-b));
    }
    public void t2(int a,int b) {
        f=f+b;
        System.out.println(f+" "+(a-b));
    }
}
public class Q2 {
    public static void main(String[] args) {
     Scanner in=new Scanner(System.in);
     int n=in.nextInt(),i,a,b;
     String s;
     flipkart f=new flipkart();
     for(i=0;i<n;i++){
         s=in.next();a=in.nextInt();b=in.nextInt();
         if(s.compareTo("HDFC")==0)
             f.t1(a,b);
         else
             f.t2(a,b);
     }
    }
}
