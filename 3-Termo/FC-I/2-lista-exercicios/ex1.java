import java.util.Random;
import java.util.Scanner;
public class ex1{
    public static int[][] gerarMatriz(int linhas, int colunas, int minimo, int maximo) {
        Random rand = new Random();
        int[][] matriz = new int[linhas][colunas];
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                matriz[i][j] = rand.nextInt(maximo - minimo + 1) + minimo;
            }
        }
        return matriz;
    }
    public static boolean matrizMajoritaria(int[][] matriz) {
        int linhas = matriz.length, colunas = matriz[0].length, tamanho = linhas * colunas;
        int[] valores = new int[1001];
        for (int[] linha : matriz) {
            for (int valor : linha) {
                valores[valor + 500]++;
            }
        }
        for (int qtd : valores) {
            if (qtd > tamanho / 2) return true;
        }
        return false;
    }
    public static void imprimirMatriz(int[][] matriz) {
        for (int[] linha : matriz) {
            for (int valor : linha) {
                System.out.print(valor + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner leitura = new Scanner(System.in);
        System.out.println("Digite a qtd de linhas: ");
        int linhas = leitura.nextInt();
        System.out.println("Digite a qtd de colunas: ");
        int colunas = leitura.nextInt();
        System.out.println("Digite a qtd de minimo: ");
        int minimo = leitura.nextInt();
        System.out.println("Digite a qtd de maximo: ");
        int maximo = leitura.nextInt();
        int[][] matriz = gerarMatriz(linhas, colunas, minimo, maximo);
        System.out.println("Matriz Gerada:");
        imprimirMatriz(matriz);
        System.out.println(matrizMajoritaria(matriz) ? "A matriz é majoritária." : "A matriz não é majoritária.");
    }
}
