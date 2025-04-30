public class java_example {
  public static void main(String[] args) {
    int[] numbers = {1, 2, 3, 4, 5};

    for (int num : numbers) {
      if (num % 2 == 0) {
        System.out.println(num + " is even");
      } else {
        System.out.println(num + " is odd");
      }
    }
  }
}
