package singleton;

public class SingletonService {

    private SingletonService(){}

    private static class SingletonHolder {
        private static final SingletonService INSTANCE = new SingletonService();
    }

    public static SingletonService getInstance() {
        return SingletonHolder.INSTANCE;
    }

    // methods...

}
