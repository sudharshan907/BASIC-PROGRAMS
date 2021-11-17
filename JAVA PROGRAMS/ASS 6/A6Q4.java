package com.company1;

import java.util.Comparator;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Collections;

interface sortvotes{
    void ascend();
    void descend();
}

class namecomp implements Comparator<String> {
    public int compare(String a,String b){
     return a.compareTo(b);
    }
}

class asc implements Comparator<candidate>{
    public int compare(candidate a,candidate b){
        if(a.v==b.v)
            return 0;
        if(a.v<b.v)
            return -1;
            return 1;
    }  }

class dsc implements Comparator<candidate>{
    public int compare(candidate a,candidate b){
        if(a.v==b.v)
            return 0;
        if(a.v<b.v)
            return 1;
        return -1;
    }  }

class candidate{
    String s;
    int v;
    candidate(String s,int v) {
        this.s = s;
        this.v = v;
    }
  public String toString(){
        return s+"-"+v;
  }
}

class electionpost implements sortvotes{
    String nameofpost;
    ArrayList<String> can=new ArrayList<>();
    HashMap<String,Integer> h=new HashMap<>();
    ArrayList<candidate> cv= new ArrayList<>();

    void display(){
        System.out.println(nameofpost);
        Collections.sort(can,new namecomp());
        for(int i=0;i<can.size();i++)
            System.out.println(can.get(i));
        for(String ca:h.keySet()){
            cv.add(new candidate(ca,h.get(ca)));
        }
    }

    void add(String s){
        if(h.containsKey(s))
            h.put(s,h.get(s)+1);
        else
            h.put(s,1);
    }

   public void ascend(){
        Collections.sort(cv,new asc());
        for(int i=0;i<cv.size();i++){
            System.out.println(cv.get(i));
        }
   }
    public void descend(){
        Collections.sort(cv,new dsc());
        for(int i=0;i<cv.size();i++) {
            System.out.println(cv.get(i));
        }
    }
}

public class Q4 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        electionpost ep=new electionpost();
        ep.nameofpost=in.nextLine();
       String s;
        int m=in.nextInt(),n,i;
        s=in.nextLine();
        for(i=0;i<m;i++){
            ep.can.add(in.nextLine());
        }
        n=in.nextInt();
        s=in.nextLine();
        for(i=0;i<n;i++){
            s=in.nextLine();
            ep.add(s);
        }
        ep.display();
        ep.ascend();
        ep.descend();
    }
}
