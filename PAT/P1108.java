import java.util.Scanner;

/**
 * Created by Buffalo on 16/3/12.
 */
public class P1108 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String[] d = new String[n];
        for(int i = 0; i < n; i++) d[i] = in.next();
        double sum = 0;
        int match = 0;
        for (int i = 0; i < d.length; i++) {
            try {
                double result = Double.valueOf(d[i]);
                if (result <= 1000 && result >= -1000 &&
                        Math.abs(Math.round(result * 100) - result * 100) < 1e-4) {
                    ++match;
                    sum += Double.valueOf(d[i]);
                } else {
                    throw new Exception();
                }
            } catch (Throwable throwable) {
                System.out.println("ERROR: " + d[i] + " is not a legal number");
            }
        }
        if(match == 0) {
            System.out.println("The average of 0 numbers is Undefined");
        } else if (match == 1) {
            System.out.println(String.format("The average of %d number is %.2f", match, sum));
        } else {
            System.out.println(String.format("The average of %d numbers is %.2f", match, sum / (1.0 * match)));
        }
    }
}
