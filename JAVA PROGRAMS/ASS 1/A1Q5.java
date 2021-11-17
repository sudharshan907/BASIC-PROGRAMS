package com.company1;
import java.util.Scanner;

public class Q5 {
    public static void main(String[] args) {
        //n and all elements should be in range of int and n should be positive also
        System.out.println("enter size of array=");
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(),i=0,j=0,t;
        System.out.println("enter elements of array");
        int a[] = new int[n];
        //takling input array
        for (i = 0; i < n; i++)
        a[i]=in.nextInt();
        //insertion sort
        for(i=1;i<n;i++){
            t=a[i];
            j=i-1;
            while((j>=0)&&(a[j]<t)){
                a[j+1]=a[j];
                j--;               }
            a[j+1]=t;
        }
      // printing sorted array
        for(i=0;i<n;i++)
            System.out.print(a[i]+" ");
    }
}
