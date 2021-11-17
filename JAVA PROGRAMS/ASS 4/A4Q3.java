package com.company2;
import java.util.Scanner;

class student{
String name,rollno,height;
student(String name,String rollno,String height){
    this.name=name;
    this.rollno=rollno;
    this.height=height;
}
public String toString(){   return ","+name;  }
}

public class Q3 {
    private static void get(student[] arr) {
        int c = 1,j=0,i,n=arr.length,f=0;
        //remove duplicate heights
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(arr[i]==null || arr[j]==null)
                    continue;
                if(arr[i].height.compareTo(arr[j].height)==0) {
                    if (arr[i].name.compareTo(arr[j].name) > 0)
                        arr[i] = null;
                    else
                        arr[j] = null;
                }  }}
        //finding first student
        for(i=0;i<n;i++){
            if(arr[i]!=null){
                j=i;break;  }}
        f=j;
        //calculating final count seperately bcz count should be printed before student names
        for ( i =f+1; i < arr.length; i++) {
            if(arr[i]==null)
                continue;
            if (arr[i].height.compareTo(arr[j].height) > 0){
                c++;j=i;}
        }
        System.out.println(c);
        System.out.print(arr[f].name);
        j=f;
        //printing selected students
        for (i =f+1; i < arr.length; i++) {
            if(arr[i]==null)
                continue;
            if (arr[i].height.compareTo(arr[j].height) > 0){
                System.out.print(arr[i]);
                j=i;}
        }  }

    public static void main(String[] args) {
       Scanner in=new Scanner(System.in);
       int n=in.nextInt(),i;
       String s=in.nextLine();
       student[] arr=new student[n];
       for(i=0;i<n;i++){
           s=in.nextLine();
           s=s.substring(1,s.length()-1);
           String[] str=s.split(",");
             arr[i]=new student(str[0],str[1],str[2]);
            }
     get(arr);
    }
}
