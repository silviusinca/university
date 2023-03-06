package exercise;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // class Car (name, color, String[] reviews)
        // orice masina nou adaugata va avea 0 reviews
        // 1. List all system cars
        // 2. Add new car in the system
        // 3*. Add new review to a car
        // 0. exit app
        // all of the above operations will be stored in a singleton service

        var carService = CarService.getInstance();
        var sc = new Scanner(System.in);

        while (true) {
            System.out.println("Choose one of the following options");
            System.out.println("1. List all cars");
            System.out.println("2. Add new car");
            System.out.println("3. Exit");

            int nr = sc.nextInt();

            switch (nr) {
                case 1 -> carService.listCars();
                case 2 -> {
                    System.out.println("Enter car name: ");
                    String name = sc.next();
                    System.out.println("Enter car colour: ");
                    String colour = sc.next();
                    carService.addCar(new Car(name, colour));
                    System.out.println("The new car was added");
                }
                case 3 -> System.exit(0);
            }

        }

    }
}
