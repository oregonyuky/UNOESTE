import java.util.Random;
import java.util.Scanner;
public class ex10{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite uma palavra para embaralhar: ");
        String word = scanner.nextLine();
        scanner.close();
        System.out.println("Palavra embaralhada: " + shuffleWord(word));
    }
    private static String shuffleWord(String word) {
        char[] characters = word.toCharArray();
        Random random = new Random();
        for (int i = characters.length - 1; i > 0; i--) {
            int j = random.nextInt(i + 1);
            char temp = characters[i];
            characters[i] = characters[j];
            characters[j] = temp;
        }
        return new String(characters);
    }
}

