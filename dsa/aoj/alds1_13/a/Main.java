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
        int k;
        HashMap<Integer, Point> mp;

        boolean check(ArrayList<Point> al, Point p1) {
            for (Point p2 : al) {
                if (p1.x == p2.x) {
                    return false;
                }
                if (Math.abs(p1.x - p2.x) == Math.abs(p1.y - p2.y)) {
                    return false;
                }
            }
            return true;
        }

        ArrayList<Point> rec(ArrayList<Point> al, int idx) {
            if (idx == 8) {
                return al;
            }
            ArrayList<Point> newPoints = new ArrayList<>();
            if (mp.containsKey(idx)) {
                newPoints.add(mp.get(idx));
            } else {
                for (int i = 0; i < 8; i++) {
                    newPoints.add(new Point(i, idx));
                }
            }
            for (Point p : newPoints) {
                if (check(al, p)) {
                    @SuppressWarnings("unchecked")
                    ArrayList<Point> newAL = (ArrayList<Point>) al.clone();
                    newAL.add(p);
                    ArrayList<Point> ans = rec(newAL, idx + 1);
                    if (ans != null) {
                        return ans;
                    }
                }
            }
            return null;
        }

        // write your code
        void solve(InputReader in, PrintWriter out) {
            k = in.nextInt();
            mp = new HashMap<>();
            for (int i = 0; i < k; i++) {
                int r = in.nextInt();
                int c = in.nextInt();
                mp.put(c, new Point(r, c));
            }

            ArrayList<Point> al = rec(new ArrayList<Point>(), 0);
            char[][] ans = new char[8][8];
            for (int i = 0; i < 8; i++) {
                Arrays.fill(ans[i], '.');
            }
            for (Point p : al) {
                ans[p.x][p.y] = 'Q';
            }
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    out.print(ans[i][j]);
                }
                out.println();
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
