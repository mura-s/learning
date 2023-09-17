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
        void rec(int h, int w, boolean[][] visited, int[][] c) {
            if (visited[h][w] || c[h][w] == 0) {
                return;
            }
            visited[h][w] = true;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int y = h + i;
                    int x = w + j;
                    if (x >= 0 && y >= 0 && x < visited[0].length && y < visited.length) {
                        rec(y, x, visited, c);
                    }
                }
            }
        }

        // write your code
        void solve(InputReader in, PrintWriter out) {
            while (true) {
                int w = in.nextInt();
                int h = in.nextInt();
                if (w == 0 && h == 0) {
                    break;
                }
                int[][] c = new int[h][w];
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                        c[i][j] = in.nextInt();
                    }
                }
                boolean[][] visited = new boolean[h][w];
                int sum = 0;
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                        if (!visited[i][j] && c[i][j] == 1) {
                            rec(i, j, visited, c);
                            sum++;
                        }
                    }
                }
                out.println(sum);
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
