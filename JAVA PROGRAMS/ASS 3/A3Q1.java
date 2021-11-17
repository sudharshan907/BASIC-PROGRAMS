package com.company1;
import java.util.Scanner;

class L {
    node h;
    class node {
        char data;
        node nx;
        node() { nx = null;  }
    }

     node createnode(char c) {
        node nw = new node();
        nw.data = c;
        nw.nx = null;
        return nw;
    }

    void insert( node n) {
        if (h == null) {
            h = n;
        } else {
            node y = h;
            while (y.nx != null) {
                y = y.nx;
            }
            y.nx = n;
        }  }

    void print() {
        node y = h;
        while (y!= null){
            System.out.print(y.data);
            if(y.nx!=null)
            System.out.print("->");
            y=y.nx;}
    }
    void reverselist(){
        if(h==null)   return;
       node cur=h;
        node next=h.nx;
        h=null;
        while(cur!=null){
            cur.nx=h;
            h=cur;
            cur=next;
            if(next!=null)
                next=next.nx;
        }
    }
}
public class Q1 {
        public static void main(String[] args) {
            L li=new L();
            System.out.print("Enter the numbers of nodes:");
            Scanner in=new Scanner(System.in);
            int n=in.nextInt();
            String s;
            for(int i=0;i<n;i++){
                System.out.print("Enter the data in Node"+(i+1)+":");
                s=in.next();
                char c=s.charAt(0);
                L.node ne=li.createnode(c);
                li.insert(ne);
            }
            li.reverselist();
            System.out.println("The reversed list is:");
            li.print();
        }
    }
