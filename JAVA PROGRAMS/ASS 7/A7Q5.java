package com.company1;
import java.util.Scanner;

public class Q5 {
    public static void main(String[] args) {
        //took chess board in 4th quadrant and (x,y)=(column,-row)
        //assumes input format is valid
    Scanner in=new Scanner(System.in);
     int a=in.nextInt(),b=in.nextInt();
     in.nextLine();
     int n=in.nextInt();
     in.nextLine();
     String[] s;
        //System.out.println("n="+n);
      //  System.out.println("["+a+","+b+"]");
     for(int i=0;i<n;i++){
         s=in.nextLine().split(" ");
         if(s[0].compareTo("Up")==0){
             a=a-Integer.parseInt(s[1]);
           //  System.out.println("["+a+","+b+"]");
         }
         if(s[0].compareTo("Right")==0){
             b=b+Integer.parseInt(s[1]);
            // System.out.println("["+a+","+b+"]");
         }
         if(s[0].compareTo("Down")==0){
             a=a+Integer.parseInt(s[1]);
            // System.out.println("["+a+","+b+"]");
         }
         if(s[0].compareTo("Left")==0){
             b=b-Integer.parseInt(s[1]);
           //  System.out.println("["+a+","+b+"]");
         }
     }
     if( (a<=8)&&(a>=1) &&(b<=8) && (b>=1))
         System.out.println("["+a+","+b+"]");
     else
         System.out.println("Overflow");
    }
}
