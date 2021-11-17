package com.company1;
import java.util.Scanner;

interface convert{
     int cr(int n);
     int cd(int n);
    int cp(int n);
}

class bank implements convert{
     public int cr(int n){ return n;  }
    public int cd(int n) {  return n*70; }
    public int cp(int n) {  return n*100; }
    public int result(int a,int b,int c,int n){
         return (n-cr(a)-cd(b)-cp(c));
    }
}

public class Q1 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n,a,b,c,m;
        n=in.nextInt();
        a=in.nextInt();
        b=in.nextInt();
        c=in.nextInt();
        bank bk=new bank();
        n=bk.result(a,b,c,n);
        if(n<0)
            System.out.println("Insufficient balance");
        else
            System.out.println(n);
    }
}
