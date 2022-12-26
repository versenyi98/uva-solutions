import java.math.BigInteger;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {

        BigInteger A[] = new BigInteger[100];
        int temp;
        int i = 0;

        Scanner s = new Scanner(System.in);
        while (s.hasNextInt()) {
            temp = s.nextInt();
            if (temp == -999999) {
                
                BigInteger maximum = A[0];
                for (int j = 0; j < i; j++) {
                    for (int k = 0; k <= j; k++) {
                        
                        BigInteger big = BigInteger.ONE;
                        for (int l = k; l <= j; l++) {
                            big = big.multiply(A[l]);
                        }
                        maximum = maximum.max(big);
                    }
                }

                System.out.println(maximum);
                i = 0;
                
            } else {
                A[i] = BigInteger.valueOf(temp);
                i++;
            }
        }
    }
}