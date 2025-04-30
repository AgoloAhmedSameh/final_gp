public class java_example3 {
    public static void main(String[] args) {
        int count = 0;
        do {
            count++;
            if (count > 5) {
                System.out.println("Breaking the loop at count: " + count);
                break;
            }
            System.out.println("Count is: " + count);
        } while (count < 10);
    }
}