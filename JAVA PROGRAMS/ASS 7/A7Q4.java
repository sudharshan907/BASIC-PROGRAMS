package com.company1;
import java.util.Scanner;

public class Q4 {
    static int dec(int n)
    {
        int num = n,dec_value = 0,base = 1,temp = num;
        while (temp > 0) {
            int last_digit = temp % 10;
            temp = temp / 10;
            dec_value += last_digit * base;
            base = base * 2;
        }
        return dec_value;
    }

    public static void main(String[] args) {
        //first byte is not representing length of data packet but working for xor operation
     Scanner in=new Scanner(System.in);
     String s=in.nextLine();
      int n=s.length();
      if(n%8!=0){
          System.out.println("Incorrect Input");
          return ;
      }
      int b=n/8;
      int[] arr=new int[b];
      for(int i=0;i<b;i++){
          arr[i]=dec(Integer.parseInt(s.substring(8*i,8*i+8)));
      }
      for(int i=1;i<b;i++){
          System.out.print((char)(arr[i]^arr[0]));
      }
    }}
