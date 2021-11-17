package com.company1;
import java.util.Scanner;

class employee{
    String id,name,department;
    int salary;
    employee(String id,String name,String dep,String sal){
        salary=Integer.parseInt(sal);
        this.id=id;
        this.name=name;
        this.department=dep;
    }
}
class manager extends employee{
    int bonus;
    manager(String id,String name,String dep,String sal,String bon){
        super(id,name,dep,sal);
        bonus=Integer.parseInt(bon);
    }
    public String toString(){  return id+" "+name+" "+department+" "+salary+" "+bonus;  }
}
public class Q4 {
    static void display(manager[] arr){
        int max=0;
        for(int i=0;i<arr.length;i++) {
            if (max<arr[i].bonus+arr[i].salary)
                max=arr[i].bonus+arr[i].salary;
        }
        for(int i=0;i<arr.length;i++){
            if(arr[i].bonus+arr[i].salary==max)
                System.out.println(arr[i]);
        }
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        String s=in.nextLine();
        manager[] arr=new manager[n];
        for(int i=0;i<n;i++){
           String id=in.next();
           String name=in.next();
           String dep=in.next();
           String sal=in.next();
           String bon=in.next();
           s=in.nextLine();
           arr[i]=new manager(id,name,dep,sal,bon);
        }
        display(arr);
    }
}
