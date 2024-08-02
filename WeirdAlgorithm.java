import java.util.Scanner;

public class WeirdAlgorithm {
    public static void weirdAlgorithm(long n) {
        System.out.print(n + " ");
        while (n != 1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }
            System.out.print(n + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("");
        long n = scanner.nextLong();
        if (n <= 0) {
            System.err.println("Please enter a positive integer.");
            scanner.close();
            return;
        }
        weirdAlgorithm(n);
        scanner.close();
    }
}
