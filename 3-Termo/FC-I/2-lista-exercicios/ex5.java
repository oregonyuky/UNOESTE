import java.io.*;
public class ex5{
    public static void main(String[] args) {
        BufferedReader leitor = null;
        BufferedWriter escritor = null;

        try {
            System.out.print("Digite o nome do arquivo Java (sem extensão .java): ");
            BufferedReader inputReader = new BufferedReader(new InputStreamReader(System.in));
            String nomeArquivo = inputReader.readLine();
            String caminhoArquivoFonte = nomeArquivo + ".java";
            String caminhoArquivoEnum = nomeArquivo + ".java.enum";

            leitor = new BufferedReader(new FileReader(caminhoArquivoFonte));
            escritor = new BufferedWriter(new FileWriter(caminhoArquivoEnum));

            String linha;
            int numeroLinha = 1;

            while ((linha = leitor.readLine()) != null) {
                escritor.write(numeroLinha + " " + linha);
                escritor.newLine();
                numeroLinha++;
            }

            System.out.println("Arquivo " + caminhoArquivoEnum + " criado com sucesso!");
        } catch (IOException e) {
            System.err.println("Erro ao processar o arquivo: " + e.getMessage());
        } finally {
            try {
                if (leitor != null) leitor.close();
                if (escritor != null) escritor.close();
            } catch (IOException e) {
                System.err.println("Erro ao fechar arquivos: " + e.getMessage());
            }
        }
    }
}

