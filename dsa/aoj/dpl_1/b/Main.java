import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;
import java.awt.Point;

public class Main {
    // static int INF = (1 << 30) - 1;
    // static long L_INF = (1L << 62) - 1;
    // static long MOD = (long) 1e9 + 7;

    static class Solver {
        int N, W;
        int[] v, w;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            W = in.nextInt();
            v = new int[N];
            w = new int[N];
            for (int i = 0; i < N; i++) {
                v[i] = in.nextInt();
                w[i] = in.nextInt();
            }

            int[] dp = new int[W + 1];
            Arrays.fill(dp, -1);
            dp[0] = 0;
            for (int i = 0; i < N; i++) {
                for (int j = W; j >= 0; j--) {
                    if (dp[j] != -1 && j + w[i] <= W) {
                        dp[j + w[i]] = Math.max(dp[j + w[i]], dp[j] + v[i]);
                    }
                }
            }
            int ans = 0;
            for (int i = 0; i < W + 1; i++) {
                ans = Math.max(ans, dp[i]);
            }
            out.println(ans);
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
