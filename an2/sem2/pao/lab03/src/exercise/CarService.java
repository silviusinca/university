package exercise;

import java.util.Arrays;

public class CarService {
    private Car[] cars;

    private CarService() {}

    private static class CarHandler {
        private static final CarService INSTANCE = new CarService();
    }

    public static CarService getInstance() {
        return CarHandler.INSTANCE;
    }

    public void listCars() {
        for (Car car : cars) {
            System.out.println(car.getName() + " is " + car.getColour() + " and has the following revies: " + Arrays.toString(car.getReviews()));
        }
    }

    public void addCar(Car carToAdd) {
        Car[] aux = new Car[cars.length + 1];
        for (int i = 0; i < cars.length; i++) {
            aux[i] = cars[i];
        }
        aux[aux.length - 1] = carToAdd;

        cars = aux;
    }
}
