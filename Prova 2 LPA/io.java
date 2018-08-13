import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class JavaScanner {

    public static void main(String[] args) {
        BufferedReader reader = null;

        try {
            FileReader fr = new FileReader("src/input.txt");
            InputStreamReader isr = new InputStreamReader(System.in);
            reader = new BufferedReader(fr);

            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }

        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                reader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

}