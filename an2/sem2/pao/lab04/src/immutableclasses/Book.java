package immutableclasses;

public final class Book {

    private final String bookName;

    public Book(String bookName) {
        this.bookName = bookName;
    }

    // fara setter
    public String getBookName() {
        return bookName;
    }
}
