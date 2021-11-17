package com.company1;
import java.util.Scanner;

public class Q7 {

    static int dec(String hexVal)
    {
        int len = hexVal.length();
        int base = 1;
        int dec_val = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (hexVal.charAt(i) >= '0'
                    && hexVal.charAt(i) <= '9') {
                dec_val += (hexVal.charAt(i) - 48) * base;
                base = base * 16;
            }
            else if (hexVal.charAt(i) >= 'A'
                    && hexVal.charAt(i) <= 'F') {
                dec_val += (hexVal.charAt(i) - 55) * base;
                base = base * 16;
            }
        }
        return dec_val;
    }

    static boolean isvalid(String s){
     boolean f=true;
     int n=s.length();
     for(int i=0;i<n;i++) {
         int c =(int) s.charAt(i);
         if ((c >= 65 && c <= 70) ||
                 (c >= '0' && c <= '9')) {
         } else {
             f = false;
         }
     }
             return f;
    }

    public static void main(String[] args) {
        //shorten above conversion method
   Scanner in=new Scanner(System.in);
     String s=in.nextLine();
     if(isvalid(s))
         System.out.println(dec(s));
     else
         System.out.println("InvalidHexadecimal");
    }
}
