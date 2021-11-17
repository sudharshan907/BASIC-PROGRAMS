package com.company1;
import java.util.Scanner;

class customer{
    String name,no;
    int bal;
    customer(String name,String no,int bal){
        this.name=name;
        this.no=no;
        this.bal=bal;
    }
    void avalbal(){
        System.out.println(name+":"+bal);
    }
}

class silver extends customer{
    silver(String name,String no,int bal){
        super(name,no,bal);
    }
    void avalbal(){
        float pred=(1+5.0f/100)*bal;
        System.out.println(name+":"+bal+":"+"Silver"+":"+(int)pred);
    }
}

class gold extends customer{
    gold(String name,String no,int bal){
        super(name,no,bal);
    }
    void avalbal(){
        float pred=(1+10.0f/100)*bal;
        System.out.println(name+":"+bal+":"+"Gold"+":"+(int)pred);
    }
}

class platinum extends customer{
    platinum(String name,String no,int bal){
        super(name,no,bal);
    }
    void avalbal(){
        float pred=(1+15.0f/100)*bal;
        System.out.println(name+":"+bal+":"+"Platinum"+":"+(int)pred);
    }
}

public class Q4 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt(),i;
        String s=in.nextLine();
        String[] str;
        int bal;
        customer[] list=new customer[n];
        for(i=0;i<n;i++){
            str=in.nextLine().split(":");
            s=str[2];
            bal=Integer.parseInt(s);
            if(bal<=100000)
                list[i]=new silver(str[0],str[1],bal);
            else if(bal<=1000000)
                list[i]=new gold(str[0],str[1],bal);
            else
                list[i]=new platinum(str[0],str[1],bal);
        }
        for(i=0;i<n;i++)
            list[i].avalbal();
    }
}
