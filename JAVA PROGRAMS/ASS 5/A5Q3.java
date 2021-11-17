package com.company1;
import java.util.Scanner;

class rectangle{
    int l,b;
    rectangle(int l,int b){
        this.l=l;
        this.b=b;
    }
    void perimeter(){
        System.out.println("Rectangle Perimeter "+2*(l+b));
    }
    void area() {
        System.out.println("Rectangle Area " + l*b);
    }
}

class square extends rectangle{
    square(int a){
        super(a,a);
    }
    void perimeter(){
        System.out.println("Square Perimeter "+2*(l+b));
    }
    void area() {
        System.out.println("Square Area " + l*b);
    }
}

class driver{
    void display(String s){
        String[] arr=s.split(" ");
        rectangle ref=null;
        if(arr.length==1){
            ref=new square(Integer.parseInt(arr[0]));
        }
        else if(arr.length==2){
            ref=new rectangle(Integer.parseInt(arr[0]),Integer.parseInt(arr[1]));
        }
        ref.perimeter();
        ref.area();
    }
}

public class Q3 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        new driver().display(in.nextLine());
    }
}
