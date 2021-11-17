package com.company4;
import java.util.Scanner;

class video{
    String title;
    boolean rented;
    video(String title){
        this.title=title;
        rented=false;
    }
    public boolean isrented(){
        return rented;
    }
}

class videostorelauncher{
    int n;
    video[] v;
    videostorelauncher(int n){
        v=new video[n];
        this.n=n;
    }
    public boolean check(String t){
        for(int i=0;i<n;i++){
            if(v[i].title.compareTo(t)==0)
                return v[i].rented;
        }
        return false;
    }
public int index(String t){
        for(int i=0;i<n;i++){
            if(v[i].title.compareTo(t)==0)
                return i;
        }
        return -1;
}
public void list(){
        for (int i=0;i<n;i++){
            if(!v[i].isrented()) {
                System.out.print("'" + v[i].title + "'");
                if(i!=n-1)
                    System.out.print(",");
            }
        }
    System.out.println();
}
}

public class Q9 {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        System.out.println("1.Addvideo");
        System.out.println("2.check availability");
        System.out.println("3.rent a video");
        System.out.println("4.return");
        System.out.println("5.list the inventory");
        System.out.println("6.exit");
        int ch,n;
        videostorelauncher store=null;
        String s;
        while(true){
            System.out.println("choice:");
            ch=in.nextInt();
            if(ch==1){
                System.out.println("N:");
                n=in.nextInt();
                store=new videostorelauncher(n);
                System.out.println("titles:");
                s=in.nextLine();
                for(int i=0;i<n;i++){
                    store.v[i]=new video(in.nextLine());
                }
            }
            if (ch==2){
                System.out.println("title:");
                s=in.nextLine();
                if(!store.check(in.nextLine()))
                    System.out.println("Available");
                else
                    System.out.println("not available");
            }
            if(ch==3){
                System.out.println("title:");
                s=in.nextLine();
                int i=store.index(in.nextLine());
                store.v[i].rented=true;
            }
            if(ch==4){
                System.out.println("title:");
                s=in.nextLine();
                int i=store.index(in.nextLine());
                store.v[i].rented=false;
            }
            if(ch==5)
                store.list();
           if(ch==6)
               break;
        } }
}
