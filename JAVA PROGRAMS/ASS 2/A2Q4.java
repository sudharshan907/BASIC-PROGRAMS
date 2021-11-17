package com.company1;
import java.util.Scanner;

public class Q4 {
    private static boolean pal(String s,int l,int r){
        while(l<r){
            if(s.charAt(l)!=s.charAt(r))
                return false;
            l++;r--;    }
        return true;   }

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String s=in.nextLine();
        int n=s.length(),i,j,m=0;
        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                if(pal(s,i,j)){   if(m<j-i+1)   m=j-i+1;  }}}
        System.out.println(m);
        in.close();
    }  }
