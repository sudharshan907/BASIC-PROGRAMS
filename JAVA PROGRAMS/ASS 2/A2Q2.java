package com.company1;
import java.util.Scanner;

public class Q2 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String s=in.nextLine();
        int n=s.length(),i,w=1;
        for(i=0;i<n;i++){
            if(s.charAt(i)==32)
                w++; }
        System.out.println("words count is "+w);
        for(i=0;i<n;i++){
            int t=s.charAt(i);
            System.out.println("'"+s.charAt(i)+"'"+" "+t); }
        in.close();
    }
}
