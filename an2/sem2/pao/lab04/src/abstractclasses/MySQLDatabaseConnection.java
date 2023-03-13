package abstractclasses;

public class MySQLDatabaseConnection extends DBConnection{
    @Override
    public void connectToDb() {
        System.out.println("Connecting via MySQL...");
    }
}
