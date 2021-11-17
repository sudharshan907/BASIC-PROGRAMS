package com.company1;
import java.util.Scanner;

public class Q7 {

    private static int fib(int i){
        if(i==1)
            return 0;
        if (i==2)
            return 1;
        return(fib(i-1)+fib(i-2));   }

    public static void main(String[] args) {
        //n should be in range of int and should be a natural number
        Scanner in=new Scanner(System.in);
        int n=in.nextInt(),i;
       // Q7 ob=new Q7();
        for(i=1;i<=n;i++)
            System.out.print(Q7.fib(i)+" ");
    }  }
