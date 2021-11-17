package com.company1;
import java.util.Scanner;

abstract class student{
    String name,rollno,type;
    student(String name,String rollno,String type){
        this.name=name;
        this.rollno=rollno;
        this.type=type;
    }
    public abstract void setfee(int n);
    public abstract int getfee();
}

class ug extends student{
    int fee;
    ug(String name,String rollno,String type,int ug){
        super(name,rollno,type);
        setfee(ug);
    }
    public void setfee(int n){
        fee=n;
    }
    public int getfee(){
        return fee;
    }
}

class pg extends student{
    int fee;
    pg(String name,String rollno,String type,int pg){
        super(name,rollno,type);
        setfee(pg);
    }
    public void setfee(int n){
        fee=n;
    }
    public int getfee(){
        return fee;
    }
}

public class Q5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int ug = in.nextInt(), pg = in.nextInt(), n = in.nextInt();
        student[] arr = new student[n];
        String s = in.nextLine();
        String[] a;
        for (int i = 0; i < n; i++) {
            a = in.nextLine().split(" ");
            if (a[2].compareTo("UG") == 0)
                arr[i] = new ug(a[0], a[1], a[2], ug);
            else if (a[2].compareTo("PG") == 0)
                arr[i] = new pg(a[0], a[1], a[2], pg);
        }
        s = in.next();
        for (int i = 0; i < n; i++) {
            if (s.compareTo(arr[i].rollno) == 0) {
                System.out.println(arr[i].getfee());
            }
        }
    }
}
