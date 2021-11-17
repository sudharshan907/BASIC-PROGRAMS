package com.company1;
import java.util.Scanner;

public class Q3 {
    public static void main(String[] args) {
        //input must be integer in long range
        Scanner in=new Scanner(System.in);
        long n=in.nextLong();
        int i=0;
        if(n==0){
            System.out.println("1");
            return ;
        }
        while(n!=0){
            i++;
            n=n/10;
        }
        System.out.println(i);
    }
}
