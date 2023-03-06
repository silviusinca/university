package com.company;

import singleton.SingletonService;

public class Main {

    public static void main(String[] args) {
        var singletonService1 = SingletonService.getInstance();
        var singletonService2 = SingletonService.getInstance();

        System.out.println(singletonService1.hashCode());
        System.out.println(singletonService2.hashCode());

    }
}


/*
public class Main {

    public static void main(String[] args) {
        int [] arr = new int[25]; // array-urile au dimensiune fixa
        int [] arr2 = {1, 2, 3, 4, 5};
        int [] arr3 = new int[]{1, 2, 5, 7, 102};
        int [][] arr4 = {
                {1, 2, 3, 4},
                {2, 3},
                {4, 5, 12}
        };

        for (int i = 0; i < arr2.length; i++) {
            System.out.println("Elementul cu valoarea: " + arr2[i]);
        }

        for (int num : arr2) {
            System.out.println("Elementul cu valoarea: " + num);
        }

        Arrays.stream(arr2).forEach(e -> System.out.println("Elementul cu valoarea: " + e));

        System.out.println("=================================");

        System.out.println(arr2 + " sau " + Arrays.toString(arr2));
        System.out.println(Arrays.deepToString(arr4));

        System.out.println("=================================");

        System.out.println("Before sorting");
        System.out.println(Arrays.toString(arr2));
        Arrays.sort(arr2);
        System.out.println("After sorting");
        System.out.println(Arrays.toString(arr2));

        System.out.println("=================================");

        arr2 = addElementToArray(arr2, 3);
        arr2 = addElementToArray(arr2, 15);
        arr2 = addElementToArray(arr2, 2);

        System.out.println(Arrays.toString(arr2));

        arr2 = deleteElementFromArray(arr2, 3);
        System.out.println(Arrays.toString(arr2));

    }

    private static int[] deleteElementFromArray(int[] arr, int value) {
        return Arrays.stream(arr).filter(e -> e != value).toArray();
    }

    public static int[] addElementToArray(int[] arr, int value) {
        int [] newArr = new int [arr.length + 1];
        for (int i = 0; i < arr.length; i++) {
            newArr[i] = arr[i];
        }
        newArr[newArr.length - 1] = value;

        return newArr;
    }

}
*/

