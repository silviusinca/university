package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        System.out.println("hello");

        Scanner scanner = new Scanner(System.in);
        System.out.println("Introduceti 2 numere");
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        System.out.println("Introduceti operatia dorita(adunare/scadere/inmultire/impartire)");
        String op = scanner.next();

        int rez = 0;

        switch (op.toLowerCase()) {
            case "adunare":
                rez = a + b;
                break;
            case "inmultire":
                rez = a * b;
                break;
            case "scadere":
                rez = a - b;
                break;
            case "impartire":
                if (a == 0) {
                    System.out.println("nu e posibila impartirea la 0");
                }
                rez = a/b;
                break;
            default:
                break;
        }
        System.out.println(rez);

    }
}
