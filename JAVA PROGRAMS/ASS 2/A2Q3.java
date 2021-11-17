package com.company1;
import java.util.Scanner;

public class Q3 {
    private static boolean dup(StringBuilder s,char c,int n){
        for(int i=0;i<n;i++){
            if(s.charAt(i)==c)
                return true; }
        return false;  }

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        StringBuilder s=new StringBuilder(in.nextLine());
        int n=s.length(),i;
        for(i=0;i<n;i++){
            if(Q3.dup(s,s.charAt(i),i)){
                s.delete(i,i+1);
                i--;n--;   }   }
      System.out.println(s);
        in.close();
    }  }
