package com.company1;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

interface orderstudents{
    void orderbyrollno(ArrayList<student> li);
    void orderbyname(ArrayList<student> li);
}

class name implements Comparator<student>{
    public int compare(student a,student b){
        return a.name.compareTo(b.name);
    }}

class rollno implements Comparator<student>{
    public int compare(student a,student b){
        return a.rollno.compareTo(b.rollno);
    }}

class student implements orderstudents{
    String name,rollno,add;
    student(){ }
    student(String name,String rollno,String add){
        this.name=name;
        this.rollno=rollno;
        this.add=add;
    }
    public void orderbyrollno(ArrayList<student> li){
        Collections.sort(li,new name());
        for(int i=0;i<li.size();i++)
            System.out.println(li.get(i));
    }

   public  void orderbyname(ArrayList<student> li){
        Collections.sort(li,new rollno());
       for(int i=0;i<li.size();i++)
           System.out.println(li.get(i));
   }
    public String toString(){
        return rollno+" "+name+" "+add;
    }
}

public class Q5 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        ArrayList<student> li=new ArrayList<>();
        int n=in.nextInt();
        String[] a;
        String s=in.nextLine();
        for(int i=0;i<n;i++) {
            a=in.nextLine().split(" ");
           li.add(new student(a[1],a[0],a[2]));
        }
        new student().orderbyname(li);
        System.out.println();
        new student().orderbyrollno(li);
    }
}
