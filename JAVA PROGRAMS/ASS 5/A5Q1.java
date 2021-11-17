package com.company1;
import java.util.Scanner;

class dis{
    void display(String s){
        String[] arr=s.split(" ");
        if(arr.length==1){
            display(Integer.parseInt(arr[0]));
        }
        else{
            if(arr[0].charAt(0)>=(char)'0'&&arr[0].charAt(0)<=(char)'9'){
                display(Integer.parseInt(arr[0]),Integer.parseInt(arr[1]));
            }
            else{
                display(arr[0].charAt(0),Integer.parseInt(arr[1]));
            }
        }
    }
    void display(char a,int n){
         for(int i=0;i<n;i++){
             for(int j=0;j<i+1;j++){
                 System.out.print(a+" ");
             }
             System.out.println();
         }
    }
    void display(int n){
        System.out.println(n*(n+1)/2);
    }
    void display(int a,int b){
        System.out.println(a*a+b*b);
    }
}
public class Q1 {
    public static void main(String[] args) {
    Scanner in=new Scanner(System.in);
    String s=in.nextLine();
    dis d=new dis();
    d.display(s);
    }
}
