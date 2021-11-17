package com.company1;
import java.util.Scanner;

public class Q1 {
    private static int count(int[] a,int i,int x){
        int c=0,j;
        for(j=0;j<=i;j++){
            if(a[j]==x)
                c++;     }
        return c;                                }

    public static void main(String[] args) {
        //all elements should be in range of int
        Scanner in = new Scanner(System.in);
        int n=1,i,c=0,ind=0;
        String s=in.nextLine();
        for(i=0;i<s.length();i++){
            if(s.charAt(i)==',')
                n++;
        }
        int[] a= new int[n];
       for(i=1;i<s.length();i++){
           int d=0;
           while(s.charAt(i)>='0' && s.charAt(i)<='9'){
               d=d*10+s.charAt(i)-'0';
               i++;           }
           a[ind++]=d;
       }
       for(i=0;i<n;i++){
            if(!(Q1.count(a,i,a[i])>2)){
          //  if((Q1.count(a,i-1,a[i])==0)  ||  (Q1.count(a,i-1,a[i])==1))
                c++;    } }
        System.out.println("length of original array="+n);
        System.out.println("length of new array="+c);
        in.close();
    }   }