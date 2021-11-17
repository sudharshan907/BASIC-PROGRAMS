package com.company1;
import java.util.Scanner;

class areas{
    void area(int r){
      double f=r*r*3.1416;
        System.out.print("Circle:"+String.format("%.2f",f)   );
    }
    void area(int l,int b){
      double f=l*b*1.00;
        System.out.print("Rectangle:"+String.format("%.2f",f)   );
    }
    void area(int a,int b,int c){
     double s=(a+b+c)/2.0;
       s=s*(s-a)*(s-b)*(s-c);
        s=Math.sqrt(s);
       System.out.print("Triangle:"+String.format("%.2f",s)   );
    }
}

public class Q2 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String[] s=in.nextLine().split(" ");
        int n=s.length,a,b=0,c=0;
        areas ar=new areas();
        a =Integer.parseInt(s[0]);
        if(n==2)
            b = Integer.parseInt(s[1]);
        if (n == 3) {
                b = Integer.parseInt(s[1]);
                c = Integer.parseInt(s[2]);
            }
        if(n==1)      {        ar.area(a);  }
        else if(n==2) {    ar.area(a,b);    }
        else if(n==3) {    ar.area(a,b,c);  }
    }
}
