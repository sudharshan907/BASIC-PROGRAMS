package com.company1;
import java.util.Scanner;

public class Q1 {
    public static void main(String[] args) {
        //assumes operator input is correct and one of four operators
      Scanner in=new Scanner(System.in);
        char op=in.nextLine().charAt(0);
        int a=0,b=0,d=0;
        try{
        a =Integer.parseInt(in.nextLine());
        b=Integer.parseInt(in.nextLine());
        }
        catch(Exception c){
            System.out.println(c+" handled");
            System.out.println("please enter a valid input");
            return ;
        }
        if(op=='+')
            d=a+b;
        else if(op=='-')
            d=a-b;
        else if(op=='*')
            d=a*b;
        else if(op=='/') {
            try {
                d=a/b;
            }
            catch (Exception c) {
                System.out.println(c+" handled");
                System.out.println("please enter a valid input");
                return;
            }
        }
        System.out.println(d);
    }
}
