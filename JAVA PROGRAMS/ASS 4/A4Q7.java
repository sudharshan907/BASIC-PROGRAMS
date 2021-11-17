package com.company1;
import java.util.Arrays;
import java.util.Scanner;

class person{
    String name,age;
    person(String name,String age){
        this.name=name;
        this.age=age;
    }
}

class student extends person{
    String roll,per;
    student(String name,String age,String per){
        super(name,age);
        this.per=per;
    }
}

class pgstudent extends student implements Comparable<pgstudent>{
    String elective,noofsub;
    pgstudent(String name,String age,String el,String per){
        super(name,age,per);
        elective=el;
    }
    public int compareTo(pgstudent p){ return p.per.compareTo(this.per);  }
    public String toString() {      return name;   }
}

public class Q7 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt(),i;
        String s=in.nextLine();
        pgstudent[] arr=new pgstudent[n];
        String[] str;
        for(i=0;i<n;i++){
         str=in.nextLine().split(":");
         arr[i]=new pgstudent(str[0],str[1],str[2],str[3]);
        }
        Arrays.sort(arr);
        for(pgstudent pg:arr)
            System.out.println(pg);
    }
}
