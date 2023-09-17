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
        int n;
        int[] S;
        int q;
        int[] T;

        boolean binarySearch(int[] arr, int v) {
            int left = 0;
            int right = arr.length;
            while (left < right) {
                int mid = (left + right) / 2;
                if (arr[mid] == v) {
                    return true;
                } else if (arr[mid] < v) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            return false;
        }

        // write your code
        void solve(InputReader in, PrintWriter out) {
            n = in.nextInt();
            S = new int[n];
            for (int i = 0; i < n; i++) {
                S[i] = in.nextInt();
            }
            q = in.nextInt();
            T = new int[q];
            for (int i = 0; i < q; i++) {
                T[i] = in.nextInt();
            }

            int ans = 0;
            for (int i = 0; i < q; i++) {
                if (binarySearch(S, T[i])) {
                    ans++;
                }
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
