import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Buffalo on 16/3/8.
 */
public class B {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

    public static class Task {
        public void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            for(int i = 0; i < n; i++) {
                String s = in.next();
                if(s.matches("R[0-9]+C[0-9]+")) {
                    String[] to = s.replaceAll("[R|C]", " ").trim().split(" ");
                    int t = Integer.valueOf(to[1]);
                    String ans = "";
                    while(t != 0) {
                        t--;
                        ans = (char)('A' + t % 26) + ans;
                        t /= 26;
                    }
                    out.println(ans+to[0]);

                } else {
                    String c = s.replaceAll("[0-9]", "");
                    String r = s.replaceAll("[A-Z]", "");
                    int num = 0;
                    for(int j = 0 ; j < c.length() ; j++){
                        num = num * 26 +(c.charAt(j) - 'A'+ 1);
                    }
                    out.println("R"+r+"C"+num);
                }
            }
        }
    }
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public String nextLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                return null;
            }
        }
    }
}
