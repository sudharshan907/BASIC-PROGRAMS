package com.company1;
import java.util.Scanner;
public class Q1 {
    public static void main(String[] args) {
        //n should only be integer and e should only be whole number in integer range
        Scanner in=new Scanner(System.in);
        System.out.println("enter base of number=");
        int n=in.nextInt();
        System.out.println("enter exponent=");
        int e=in.nextInt(),i,f=1;
        for(i=0;i<e;i++)
            f=f*n;
        System.out.println(f);
    }
}
