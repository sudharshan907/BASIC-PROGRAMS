package com.company1;
import java.util.Scanner;

class employee{
    String id,name;
    int sal;
    employee(String id,String name) { this.id = id;   this.name = name; }
    int calsal()                    { return sal;  }
}

class per_emp extends employee{
    int basic;
    float pfa;
    per_emp(String id,String name,String basic) {
     super(id,name);
     this.basic=Integer.parseInt(basic);
     pfa=12.0f/100*this.basic;
     sal=this.basic-(int)pfa;
    }
    int calsal()             { return sal; }
    public String toString() {  return id+" "+name+" "+sal;  }
}

class tem_emp extends employee{
    int h_wo,h_wa;
    tem_emp(String id,String name,String hwo,String hwa) {
        super(id, name);
        h_wo = Integer.parseInt(hwo);
        h_wa = Integer.parseInt(hwa);
        sal=h_wo*h_wa;
    }
    int calsal()             {  return sal;  }
    public String toString() { return id+" "+name+" "+sal;  }
}

public class Q6 {
    public static void main(String[] args) {
     Scanner in=new Scanner(System.in);
     int n=in.nextInt(),i,f=0;
     String s;
     employee[] list=new employee[n];
     for(i=0;i<n;i++) {
         s = in.next();
         if (s.charAt(0) == '1')
             list[i] = new per_emp(in.next(), in.next(), in.next());
         else if (s.charAt(0) == '2')
             list[i] = new tem_emp(in.next(),in.next(),in.next(),in.next());
     }
     s=in.next();
     for(i=0;i<n;i++) {
         if (list[i].id.compareTo(s) == 0) {
             f=1;
             System.out.println(list[i]);
         } }
     if(f==0)    System.out.println("-1");
     }
    }

