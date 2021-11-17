package com.company1;
import java.util.Scanner;
import java.util.Arrays;

class student{
    String id,name;
    student(String id,String name){
        this.id=id;
        this.name=name;
    }
}
class studentde extends student implements Comparable<studentde> {
    private String location;
    studentde(String id,String name,String location){
      super(id,name);
        this.location=location;
    }
    public int compareTo(studentde obj)  {  return id.compareTo(obj.id);     }
    public String toString()           { return id+" "+name+" "+location;  }
}

public class Q6 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n,i;
        System.out.print("Enter the number of students:");
        n=in.nextInt();
        studentde[] arr=new studentde[n];
        for(i=0;i<n;i++){
            System.out.print("Enter the details of Student ");
            System.out.println((i+1)+"(id,name,location):");
            arr[i]=new studentde(in.next(),in.next(),in.next());
        }
        Arrays.sort(arr);
        System.out.println("The Student Details are:");
        for(i=0;i<n;i++)
            System.out.println(arr[i]);
    }
}
