import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    // static int INF = (1 << 30) - 1;
    // static long L_INF = (1L << 62) - 1;
    // static long MOD = (long) 1e9 + 7;

    static class Solver {
        int n;
        int[] A;
        int q;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            n = in.nextInt();
            A = new int[n];
            for (int i = 0; i < n; i++) {
                A[i] = in.nextInt();
            }
            q = in.nextInt();

            for (int k = 0; k < q; k++) {
                int m = in.nextInt();
                boolean flag = false;
                int max = 1 << n;
                for (int i = 1; i < max; i++) {
                    int sum = 0;
                    int bit = i;
                    int digit = 0;
                    while (bit > 0) {
                        if (bit % 2 == 1) {
                            sum += A[digit];
                        }
                        bit /= 2;
                        digit++;
                    }
                    if (sum == m) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    out.println("yes");
                } else {
                    out.println("no");
                }
            }
        }

        void debug(Object... os) {
            System.err.println(Arrays.deepToString(os));
        }
    }

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        solver.solve(in, out);
        out.close();
    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}
