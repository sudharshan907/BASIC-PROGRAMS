package com.company1;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class m implements Comparable<m>{
    String title,date,start,end,des;
    m(String title,String date,String start,String end,String des){
        this.title=title;
        this.date=date;
        this.start=start;
        this.end=end;
        this.des=des;
    }
    public String toString(){
        return "On "+date+","+"from "+start+" "+"to"+" "+end+":"+title+":"+des;
    }
    public int compareTo(m obj){
        return start.compareTo(obj.start);
    }
}

class dms{
    ArrayList<m> l=new ArrayList<>();
    void schedule(m obj){
        boolean v=true;
        for(int i=0;i<l.size();i++){
            int s1,s2;
            s2=obj.start.compareTo(l.get(i).end);
            s1=obj.start.compareTo(l.get(i).start);
           if(s1==1 && s2==0)
               v=false;
            s2=obj.end.compareTo(l.get(i).end);
            s1=obj.end.compareTo(l.get(i).start);
            if(s1==1 && s2==0)
                v= false;
    }
        if(v) {
            l.add(obj);
            System.out.println("Scheduled successfully");
        }
        else{
            System.out.println("Collision!Already another meeting is scheduled");
        }
}
void display(String dat){
    Collections.sort(l);
        for (int i=0;i<l.size();i++){
            if(l.get(i).date.compareTo(dat)==0){
                System.out.println(l.get(i));
            }
        }
}
}

public class Q3 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int c;
        String title,date,start,end,des,s;
        dms d=new dms();
        System.out.println("1. Schedule Meeting");
        System.out.println("2. List Meetings");
        while(true){
            System.out.println();
            System.out.print("enter your choice:");
            c=in.nextInt();
            s=in.nextLine();
            if(c==1) {
                System.out.print("Title:");
                title= in.nextLine();
                System.out.print("Date:");
                date=in.nextLine();
                System.out.print("Start time:");
                start=in.nextLine();
                System.out.print("End time:");
                end=in.nextLine();
                System.out.print("Description:");
                des=in.nextLine();
                m obj=new m(title,date,start,end,des);
                d.schedule(obj);
            }
           if(c==2){
               System.out.print("date:");
               date=in.nextLine();
               d.display(date);
           }
        }
    }
}



