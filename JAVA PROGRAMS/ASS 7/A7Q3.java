package com.company1;
import java.util.Scanner;

public class Q3 {
    public static void main(String[] args) {
        //assumes whole array input is valid and all indices are integers
    Scanner in=new Scanner(System.in);
    int n=Integer.parseInt(in.nextLine());
    String[] a=in.nextLine().split(" ");
    int[] arr=new int[n];
    for(int i=0;i<n;i++){
        arr[i]=Integer.parseInt(a[i]);
    }
    a=in.nextLine().split(" ");
    int[] ind=new int[a.length];
    for(int i=0;i<a.length;i++)
        ind[i]=Integer.parseInt(a[i]);
    int s=0;
    try {
        for (int i = 0; i < ind.length; i++)
            s = s + arr[ind[i]];
    }
    catch(Exception c){
        System.out.println(c+" handled");
        System.out.println("please enter a valid index");
        return;
    }
        System.out.println(s);
    }
}
