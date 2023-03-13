package equalsandhashcodes;

import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Book b1 = new Book("b1");
        Book b2 = new Book("b1");

        /* doua obiecte care sunt egale au acelasi hashcode, insa 2 obiecte cu acelasi hashcode nu sunt neaparat egale */

        System.out.println(b1.equals(b2));

        Set<Book> hashSet = new HashSet<>();
        hashSet.add(b1);
        hashSet.add(b2);

        System.out.println(hashSet);

    }
}
