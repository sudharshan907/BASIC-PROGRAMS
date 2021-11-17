package com.company1;
import java.util.Scanner;
import java.util.Arrays;

class person{
    String name;
    person(String name){  this.name=name;  }
}

class patient extends person implements Comparable<patient>{
    String id;
    patient(String name,String id){      super(name);   this.id=id;  }
    public int compareTo(patient obj){
        String s1=obj.id.substring(5,8);
        String s2=id.substring(5,8);
        return s1.compareTo(s2);
    }
    public String toString(){  return id+" "+name; }
}

public class Q5 {
    public static void main(String[] args) {
       Scanner in=new Scanner(System.in);
       int n,i;
        System.out.print("Enter number of patients:");
       n=in.nextInt();
       patient[] arr=new patient[n];
       String s=in.nextLine(),nm,id;
        System.out.println();
       for(i=0;i<n;i++){
           System.out.println("Enter details of patient "+(char)(i+49)+":");
           System.out.print("Name:");
           nm=in.nextLine();
           System.out.print("Patient ID:");
           id=in.nextLine();
           arr[i]=new patient(nm,id);
           System.out.println();
       }
       Arrays.sort(arr);
        System.out.println("List of Patients to be tested are:");
       for(patient p:arr)
           System.out.println(p);
    }
}
