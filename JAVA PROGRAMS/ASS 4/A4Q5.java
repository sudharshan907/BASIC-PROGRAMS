package com.company1;

import java.util.Scanner;

class car{
    String name,no;
    int base,add;
    car(String name,String no,String base,String add){
        this.name=name;
        this.no=no;
        this.base=Integer.parseInt(base);
        this.add=Integer.parseInt(add);
    }
    int totalprice(){  return base+add;   }
}

class dealer{
    String dname;
    float dis;
    car obj;
    dealer(String name,String no,String base,String add,String dealer,String dis) {
        obj=new car(name,no,base,add);
        dname=dealer;
        this.dis=Float.parseFloat(dis);
    }
    float onroadprice(){
       int p= obj.totalprice();
       return 1.0f*p*(100.0f-dis)/100.0f;
    }
    public String toString(){  return obj.name+" "+obj.totalprice()+" "+(int)onroadprice();  }
}

public class Q5 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt(),i;
        dealer[] d=new dealer[n];
        for(i=0;i<n;i++)
            d[i]=new dealer(in.next(),in.next(),in.next(),in.next(),in.next(),in.next());
        for(i=0;i<n;i++)
            System.out.println(d[i]);
    }
}
