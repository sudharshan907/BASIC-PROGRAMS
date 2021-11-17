package com.company1;
import java.util.Scanner;

abstract class addition{
    public abstract void add();
}

class inadd extends addition {
    int a,b;
    inadd(int a,int b){ this.a=a;   this.b=b; }
    public void add() {  System.out.println(a+b);  }
}

class fradd extends addition{
    int a,b,c,d;
    fradd(int a,int b,int c,int d){ this.a=a; this.b=b; this.c=c; this.d=d; }

    public int gcd(int x,int y){
        if(y%x==0)
            return x;
      return  gcd(y%x,x);
    }

    public void reduceandprint(int x,int y){
        int d=gcd(x,y);
        x=x/d;
        y=y/d;
        System.out.println(x+"/"+y);
    }
    public void add(){
        int x=a*d+b*c,y=b*d;
        reduceandprint(x,y);
    }
}

public class Q4 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String[] a=in.nextLine().split(" ");
        String[] b=in.nextLine().split(" ");
        new inadd(Integer.parseInt(a[0]),Integer.parseInt(a[1])).add();
        new fradd(Integer.parseInt(b[0]),Integer.parseInt(b[1]),
                Integer.parseInt(b[2]),Integer.parseInt(b[3])).add();
    }
}
