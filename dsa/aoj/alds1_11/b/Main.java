import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;
import java.awt.Point;

public class Main {
    static int INF = (1 << 30) - 1;
    // static long L_INF = (1L << 62) - 1;
    // static long MOD = (long) 1e9 + 7;

    static class Solver {
        int n;
        ArrayList<ArrayList<Integer>> g;
        int[] d;
        int[] f;
        int time;

        void rec(int v) {
            if (d[v] != INF) {
                return;
            }
            d[v] = time;
            time++;
            for (int i = 0; i < g.get(v).size(); i++) {
                int newV = g.get(v).get(i);
                rec(newV);
            }
            f[v] = time;
            time++;
            return;
        }

        // write your code
        void solve(InputReader in, PrintWriter out) {
            n = in.nextInt();
            g = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                ArrayList<Integer> al = new ArrayList<>();
                int u = in.nextInt() - 1;
                int k = in.nextInt();
                for (int j = 0; j < k; j++) {
                    int v = in.nextInt() - 1;
                    al.add(v);
                }
                g.add(al);
            }
            d = new int[n];
            Arrays.fill(d, INF);
            f = new int[n];
            Arrays.fill(f, INF);
            for (int i = 0; i < n; i++) {
                if (d[i] == INF) {
                    rec(i);
                }
            }

            for (int i = 0; i < n; i++) {
                out.printf("%d %d %d\n", i + 1, d[i] + 1, f[i] + 1);
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
