package abstractclasses;

public class Main {
    public static void main(String[] args) {
        MySQLDatabaseConnection mySQLDatabaseConnection = new MySQLDatabaseConnection();
        OracleDatabaseConnection oracleDatabaseConnection = new OracleDatabaseConnection();

        mySQLDatabaseConnection.connectToDb();
        oracleDatabaseConnection.connectToDb();

        DBConnection dbConnection1 = new MySQLDatabaseConnection();
        DBConnection dbConnection2 = new OracleDatabaseConnection();
    }
}
