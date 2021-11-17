package com.company1;
import java.util.Scanner;

class bank{
    public void getinterest(int n){
        System.out.println(" ");
    }
}

class sbi extends bank{
    public void getinterest(int n){
        System.out.print("SBI interest is:");
        System.out.println(5*n/100);
    }
}

class icici extends bank{
    public void getinterest(int n){
        System.out.print("ICICI interest is:");
        System.out.println(6*n/100);
    }
}

class axis extends bank{
    public void getinterest(int n){
        System.out.print("AXIS interest is:");
        System.out.println(7*n/100);
    }
}

public class Q2 {
    public static void main(String[] args) {
    Scanner in=new Scanner(System.in);
    int n=in.nextInt();
    new sbi().getinterest(n);
    new icici().getinterest(n);
    new axis().getinterest(n);
    }
}
