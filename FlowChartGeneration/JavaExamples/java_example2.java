public class java_example2 {
    public static void main(String[] args) {
        int rows = 3;
        int cols = 4;

        int i = 1;
        while (i <= rows) {
            int j = 1;
            while (j <= cols) {
                if ((i * j) % 2 == 0) {
                    System.out.print("(" + i + "," + j + ") is even  ");
                } else {
                    System.out.print("(" + i + "," + j + ") is odd   ");
                }
                j++;
            }
            System.out.println(); // Newline after each row
            i++;
        }
    }
}