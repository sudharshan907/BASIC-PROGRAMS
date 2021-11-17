package com.company1;
import java.util.Scanner;

interface shapearea{
    void area(double n);
}

class square implements shapearea{
   public void area(double n){
       System.out.println((int)Math.floor(n*n));
   }
}

class circle implements shapearea{
    public void area(double n){
        System.out.println((int)Math.floor(3.14*n*n));
    }
}

public class Q3 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String s=in.next();
        double n=in.nextInt();
        if(s.compareTo("Circle")==0)
            new circle().area(n);
        if(s.compareTo("Square")==0)
            new square().area(n);
    }
}
