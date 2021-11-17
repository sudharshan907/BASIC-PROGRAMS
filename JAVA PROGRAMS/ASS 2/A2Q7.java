package com.company2;
import java.util.Arrays;
import java.util.Scanner;

class student implements Comparable<student> {
    String name,rollno;  int h,w;
    public void setn(String name)     {   this.name = name;            }
    public void setr(String rollno) {     this.rollno = rollno;        }
    public void seth(String s)           {
        for(int i=0;i<s.length();i++)
            h=h*10+(s.charAt(i)-48);
    }
    public void setw(String s)          {
        for(int i=0;i<s.length();i++)
            w=w*10+(s.charAt(i)-48);
    }
    public int compareTo(student obj){
        if(h==obj.h)
            return 0;
        else if(h>obj.h)
        return 1;
        return -1;                  }
    public String tostring(){
        return rollno+","+name+"," +h+"cm,"+w+"kg"; }
}

public class Q7 {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        System.out.println("enter number of students:");
        int n=in.nextInt(),i,p,q;
        student[] a=new student[n];
        for(i=0;i<n;i++)
            a[i]=new student();
        String s=in.nextLine();
        System.out.println("enter details:  (rollno,name,height,weight)" +
                "seperated by comma in each line");
        //only seperated by single comma should not be any space
        //c should be small and k should be capital
        for(i=0;i<n;i++){
            s=in.nextLine();
            p=0; q=0;
            while(s.charAt(q)!=',')  {  q++;  }
               a[i].setr(s.substring(p,q));
            p=q+1;q=q+1;
            while(s.charAt(q)!=','){     q++; }
                a[i].setn(s.substring(p,q));
            p=q+1;q=q+1;
            while(s.charAt(q)!='c'){    q++;  }
            a[i].seth(s.substring(p,q));
            p=q+3;q=q+3;
            while(s.charAt(q)!='K'){  q++;  }
            a[i].setw(s.substring(p,q));
        }
       /* for(i=0;i<n;i++){
           a[i].setr(in.next());
           a[i].setn(in.next());
           a[i].seth(in.nextInt());
           a[i].setw(in.nextInt());
        }  */
        Arrays.sort(a);
        for(i=0;i<n;i++)
            System.out.println(a[i].tostring());
    }
}
