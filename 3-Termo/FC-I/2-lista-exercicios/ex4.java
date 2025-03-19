import java.io.*;
import java.awt.Desktop;

public class ConverterCidadesHtml {
    public static void converterCidades(String nomeArquivo) {
        String nomeArquivoHtml = "cidades.html";
        try (BufferedReader br = new BufferedReader(new FileReader(nomeArquivo));
             BufferedWriter bw = new BufferedWriter(new FileWriter(nomeArquivoHtml))) {
            bw.write("<!DOCTYPE html>\n<html lang=\"pt-br\">\n<head>\n<title>Cidades do Estado de São Paulo</title>\n</head>\n<body>\n");
            
            String linha;
            char letraAtual = '\0';
            while ((linha = br.readLine()) != null) {
                if (!linha.isEmpty()) {
                    char primeiraLetra = Character.toUpperCase(linha.charAt(0));
                    if (primeiraLetra != letraAtual) {
                        letraAtual = primeiraLetra;
                        bw.write("<h1>" + letraAtual + "</h1>\n");
                    }
                    bw.write("<p>" + linha + "</p>\n");
                }
            }
            
            bw.write("</body>\n</html>");
            System.out.println("Arquivo HTML gerado com sucesso: " + nomeArquivoHtml);
            
            try {
                Desktop.getDesktop().open(new File(nomeArquivoHtml));
            } catch (Exception e) {
                System.out.println("Erro ao abrir o arquivo: " + e.getMessage());
            }
        } catch (IOException e) {
            System.out.println("Erro ao processar o arquivo: " + e.getMessage());
        }
    }
    
    public static void main(String[] args) {
        String nomeArquivo = "cidades.txt";
        converterCidades(nomeArquivo);
    }
}
