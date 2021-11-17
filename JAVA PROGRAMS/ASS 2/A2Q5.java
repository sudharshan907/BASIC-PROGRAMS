package com.company1;
import java.util.Scanner;

public class Q5 {
    public static void main(String[] args) {
        System.out.println("Enter the inmate details:");
        Scanner in = new Scanner(System.in);
        String s= in.next();
        String s1=in.next();
        String s2=in.next();
        System.out.println("Enter the number of days:");
        int n=in.nextInt();
        String s1a,s1b,s2a,s2b;
        s1a="employee";  s1b="student";  s2a="veg";  s2b="nonveg";
        if(s1.equalsIgnoreCase(s1a)){
            if(s2.equalsIgnoreCase(s2a)){       System.out.println(105*n); }
            else if(s2.equalsIgnoreCase(s2b)){  System.out.println(n*126); }    }
       else if(s1.equalsIgnoreCase(s1b)){
            if(s2.equalsIgnoreCase(s2a)){       System.out.println(n*100);   }
            else if(s2.equalsIgnoreCase(s2b)){   System.out.println(n*120); }    }
        in.close();
    }  }
