package com.company1;
import java.util.LinkedList;
import java.util.Scanner;


public class Q6 {
    public static void main(String[] args) {
     Scanner in=new Scanner(System.in);
        LinkedList<Integer> q=new LinkedList<>();
        String s;
        while(true) {
            s = in.nextLine();
            try {
                if (s.charAt(0) == 'E') {
                    int n = Integer.parseInt(s.substring(2, s.length()));
                    q.add(n);
                    System.out.println("Success");
                } else if (s.charAt(0) == 'D') {
                    if (q.isEmpty()) {
                        System.out.println("EmptyQueue");
                    } else
                        System.out.println(q.removeFirst());
                }
            }
            catch (Exception c) {
                break;
            }
        }

    }

}
