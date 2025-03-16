import java.util.Scanner;
public class ex9{
    public static void main(String[] args){
        Scanner leitura = new Scanner(System.in);
        String str = leitura.nextLine();
        leitura.close();
        String[] cada_palavras = str.split("[\\s,\\.]+");
        int tamanho = str.length();
        int tamanho_palavra = cada_palavras.length;
        System.out.println("Quantidade de caracteres: " + tamanho);
        System.out.println("Quantidade de palavras: " + tamanho_palavra);
    }
}
