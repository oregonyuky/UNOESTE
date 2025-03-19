import java.io.*;

public class EnumeraArquivo {
    public static void enumeraArquivo(String nomeArquivo) {
        String nomeArquivoEnum = nomeArquivo + ".enum";
        try (BufferedReader br = new BufferedReader(new FileReader(nomeArquivo));
             BufferedWriter bw = new BufferedWriter(new FileWriter(nomeArquivoEnum))) {
            String linha;
            int numeroLinha = 1;
            while ((linha = br.readLine()) != null) {
                bw.write(numeroLinha + ": " + linha);
                bw.newLine();
                numeroLinha++;
            }
            System.out.println("Arquivo enumerado salvo como: " + nomeArquivoEnum);
        } catch (IOException e) {
            System.out.println("Erro ao processar o arquivo: " + e.getMessage());
        }
    }
    
    public static void main(String[] args) {
        String nomeArquivo = "codigo.java";
        enumeraArquivo(nomeArquivo);
    }
}

