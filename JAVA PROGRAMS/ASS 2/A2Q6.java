package com.company1;
import java.util.Scanner;

 class student{
    String name;  String rollno;  float cgpa;   float percentage;
     public void setName(String name)     {  this.name = name;            }
     public void setRollno(String rollno) {  this.rollno = rollno;        }
     public void setCgpa(float cgpa)      {  this.cgpa = cgpa;            }
     public void setPercentage()          {  this.percentage =cgpa*9.5f;  }
     public String getName()              {  return name;                 }
     public String getRollno()            {  return rollno;               }
     public float getCgpa()               {  return cgpa;                 }
     public float getPercentage()         {  return percentage;           }
 }

public class Q6 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("enter number of students:");
        int n=in.nextInt(),i;
        student a[]=new student[n];
        for(i=0;i<n;i++)
            a[i]=new student();
        System.out.println("enter student details:");
        for(i=0;i<n;i++){
            a[i].setName(in.next());
            a[i].setRollno(in.next());
            a[i].setCgpa(in.nextFloat());
            a[i].setPercentage();
        }
        in.close();
        for(i=0;i<n;i++)
            System.out.println(a[i].getName()+" "+a[i].getRollno()+" "+a[i].getCgpa()
                    +" "+a[i].getPercentage()+"%");
    }
}
