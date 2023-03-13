package abstractclasses;

public abstract class DBConnection {
    public DBConnection() {}

    public abstract void connectToDb();

    public void afterConnection() {
        System.out.println("After database connection...");
    }
}
