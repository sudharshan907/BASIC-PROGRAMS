package com.company1;
import java.util.Scanner;
public class Q2 {
    public static void main(String[] args) {
        //a and b should only be integers in int range
    Scanner in=new Scanner(System.in);
        System.out.println("a=");
        int a=in.nextInt();
        System.out.println("b=");
        int b=in.nextInt();
        a=a+b;
        b=a-b;
        a=a-b;
        System.out.println("a="+a);
        System.out.println("b="+b);
    }
}
