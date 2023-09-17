import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.*;
import java.awt.Point;

public class Main {
    static int INF = (1 << 30) - 1;
    // static long L_INF = (1L << 62) - 1;
    // static long MOD = (long) 1e9 + 7;

    static class Edge {
        int v;
        int dist;

        Edge(int v, int dist) {
            this.v = v;
            this.dist = dist;
        }
    }

    static class Solver {
        int n;
        ArrayList<ArrayList<Integer>> g;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            n = in.nextInt();
            g = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                ArrayList<Integer> al = new ArrayList<>();
                int u = in.nextInt() - 1;
                int k = in.nextInt();
                for (int j = 0; j < k; j++) {
                    al.add(in.nextInt() - 1);
                }
                g.add(al);
            }

            int[] ans = new int[n];
            Arrays.fill(ans, INF);
            ArrayDeque<Edge> que = new ArrayDeque<>();
            que.add(new Edge(0, 0));
            while (!que.isEmpty()) {
                Edge e = que.poll();
                if (ans[e.v] <= e.dist) {
                    continue;
                }
                ans[e.v] = e.dist;
                for (int i = 0; i < g.get(e.v).size(); i++) {
                    Integer next = g.get(e.v).get(i);
                    que.add(new Edge(next, e.dist + 1));
                }
            }
            for (int i = 0; i < n; i++) {
                if (ans[i] == INF) {
                    ans[i] = -1;
                }
                out.printf("%d %d\n", i + 1, ans[i]);
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
