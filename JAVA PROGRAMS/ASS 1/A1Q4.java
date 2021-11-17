package com.company1;
import java.util.Scanner;

public class Q4 {
    public static void main(String[] args) {
        //input should be integer in long range
        Scanner in=new Scanner(System.in);
        long n=in.nextLong(),r=0,i;
        while(n!=0){
            i=n%10;
            r=r*10+i;
            n=n/10;
        }
        System.out.println(r);
    }
}
