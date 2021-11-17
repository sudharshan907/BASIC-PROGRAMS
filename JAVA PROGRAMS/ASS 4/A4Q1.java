package com.company1;
import java.util.Scanner;

class bitwise{
    int bitwiseand(int a,int b)        {         return a & b;   }
    int bitwiseand(int a,int b,int c)  {   return a & b & c;  }
}

public class Q1 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String[] s=in.nextLine().split(" ");
        int n=s.length,a,b,c;
        bitwise bit=new bitwise();
        a=Integer.parseInt(s[0]);
        b=Integer.parseInt(s[1]);
        if(n==2)
            System.out.println(bit.bitwiseand(a,b));
        if(n==3){
            c=Integer.parseInt(s[2]);
            System.out.println(bit.bitwiseand(a,b,c));
        }
        in.close();
    }
}
