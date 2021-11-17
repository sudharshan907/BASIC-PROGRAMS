package com.company3;
import java.util.ArrayList;
import java.util.Scanner;

class train {
    int busno,distance,fare;
    char t;
    String from,to;
    train(String busno,String from,String to,String distance,char t){
        this.from=from;
        this.to=to;
        this.t=t;
        int b=0,i=0;
        while(i<busno.length()){   b=b*10+busno.charAt(i)-48;  i++;   }
        this.busno=b;
        b=0;
        i=0;
        while(i<distance.length()){   b=b*10+distance.charAt(i)-48;i++;  }
        this.distance=b;
        calfare();
    }
    public void calfare(){
        if(t=='O')    fare=10*distance;
        if(t=='F')    fare=20*distance;
        if(t=='L')    fare= 24*distance;
    }
    public String show(){
        return busno+" "+from+" "+to+" "+distance+" "+t+" "+fare;
    }
}

public class Q8 {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        ArrayList<train> a=new ArrayList<>();
        //only seperated by single space
        int ch;
        String s;
        int p,q;
        while( true){
            System.out.println("1-add details");
            System.out.println("2-show details");
            System.out.println("3-exit");
            System.out.println("Enter choice:");
            ch=in.nextInt();
            if(ch==1){
                System.out.println("enter bus details(busno,from,to,distance,type)");
                s=in.nextLine();
                s=in.nextLine();
                p=0;q=0;
                while(s.charAt(q)!=32){   q++;  }
                String busno=s.substring(p,q);
                q++;
                p=q;
                while(s.charAt(q)!=32){   q++;  }
                String from=s.substring(p,q);
                q++;
                p=q;
                while(s.charAt(q)!=32){    q++;  }
                String to=s.substring(p,q);
                q++;
                p=q;
                while((q<s.length())&&s.charAt(q)!=32){   q++;  }
                String dis=s.substring(p,q);
                char t;
                if(q==s.length()){   t='O';  }
                else {     t = s.charAt(++q);   }
                a.add(new train(busno, from, to, dis, t));
            }
            else if(ch==2){
                for(train t:a)
                    System.out.println(t.show());
            }
            else if(ch==3)
                break;
        }
    }
}

