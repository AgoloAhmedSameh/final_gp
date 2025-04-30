public class java_example4 {
    public static void main(String[] args) {
        String[] fruits = {"apple", "banana", "cherry"};

        for (String fruit : fruits) {
            switch (fruit) {
                case "apple":
                    System.out.println("This is an apple.");
                    break;
                case "banana":
                    System.out.println("This is a banana.");
                    break;
                case "cherry":
                    System.out.println("This is a cherry.");
                    break;
                default:
                    System.out.println("Unknown fruit.");
            }
        }
    }
}