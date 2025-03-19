import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class VerificaBlocos {
    public static boolean verificaBlocos(String nomeArquivo) {
        int contador = 0;
        try (BufferedReader br = new BufferedReader(new FileReader(nomeArquivo))) {
            String linha;
            while ((linha = br.readLine()) != null) {
                for (char c : linha.toCharArray()) {
                    if (c == '{') contador++;
                    else if (c == '}') contador--;
                    if (contador < 0) return false;
                }
            }
        } catch (IOException e) {
            System.out.println("Erro ao ler o arquivo: " + e.getMessage());
            return false;
        }
        return contador == 0;
    }
    
    public static void main(String[] args) {
        String nomeArquivo = "codigo.java";
        System.out.println(verificaBlocos(nomeArquivo) ? "Blocos corretos" : "Blocos incorretos");
    }
}

