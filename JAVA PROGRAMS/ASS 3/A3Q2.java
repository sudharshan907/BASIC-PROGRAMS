package com.company1;

import java.util.ArrayList;
import java.util.Scanner;

class item{
    String name,id;
    int price,count=0;
    item(String id,String name,String price){
        this.id=id;
        this.name=name;
        this.price=Integer.parseInt(price);
    }
    public String toString(){ return id+","+name+","+price+","+count;  }
}

class management{
    ArrayList<item> l=new ArrayList<>();
    int tp;
     void setcount(String id,String count){
         for(int i=0;i<l.size();i++){
             if(l.get(i).id.compareTo(id)==0)
                 l.get(i).count=Integer.parseInt(count);
         }
     }

     void resetcount(){
         for(int i=0;i<l.size();i++){
             l.get(i).count=0;
         } }

   void printinvoice(){
       System.out.println("****INVOICE****");
       for(int i=0;i<l.size();i++){
           if(l.get(i).count!=0){
               System.out.println(l.get(i));
           }
       }
       System.out.print("Total:");
       System.out.println(updatetp());
       System.out.println("********");
   }
    int updatetp(){
         tp=0;
         for(int i=0;i<l.size();i++)
             tp=tp+l.get(i).price*l.get(i).count;
         return tp;
    }
}

public class Q2 {
    public static void main(String[] args) {
        //assuming all contain different id's
      Scanner in=new Scanner(System.in);
        System.out.println("Enter the available inventory items line by line," +
                " type OKAY at the end of the list:");
          String id,name,price,s,st="OKAY",count;
          int ch=0;
          management m=new management();
          while(true){
              s=in.nextLine();
              id=in.next();
              if(id.compareTo(st)==0){
                //  s=in.nextLine();
                  break;
              }
              name=in.next();
              price=in.next();
              m.l.add(new item(id,name,price));
          }

          while(true) {
              System.out.println("1.Add Invoice");
              System.out.println("2.Exit");
              System.out.println("Choice:");
              ch = in.nextInt();
              if (ch == 2) {
                  break;
              }
              if (ch == 1) {
                  System.out.println("Add Invoice Item(Y/N)");
                  s = in.nextLine();
                  s=in.nextLine();
                  if (s.charAt(0) == 'Y') {
                      System.out.println("Enter Inventory ID and Quantity line by line," +
                              " type OKAY at the end of the list");
                      while (true) {
                          id = in.next();
                          if (id.compareTo(st) == 0)
                              break;
                          count = in.next();
                          m.setcount(id, count);
                      }
                      m.printinvoice();
                      m.resetcount();
                  } else {
                      //no to add invoice
                  }
              }
          }}
}
