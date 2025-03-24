import java.util.Random;

public class ex2{
    
    public static int[][] geraCartela() {
        Random rand = new Random();
        int[][] cartela = new int[5][5];
        
        for (int col = 0; col < 5; col++) {
            boolean[] numerosUsados = new boolean[16];
            int inicio = col * 15 + 1;
            
            for (int row = 0; row < 5; row++) {
                if (row == 2 && col == 2) {
                    cartela[row][col] = 0;
                } else {
                    int num;
                    do {
                        num = rand.nextInt(15) + inicio;
                    } while (numerosUsados[num - inicio]);
                    cartela[row][col] = num;
                    numerosUsados[num - inicio] = true;
                }
            }
        }
        return cartela;
    }
    
    public static boolean verificaDiagonal(int[][] cartela, int[] sorteados, int qtdSorteados) {
        boolean principal = true, secundaria = true;
        for (int i = 0; i < 5; i++) {
            if (i != 2 && !contido(cartela[i][i], sorteados, qtdSorteados)) principal = false;
            if (i != 2 && !contido(cartela[i][4 - i], sorteados, qtdSorteados)) secundaria = false;
        }
        return principal || secundaria;
    }
    
    public static boolean verificaHorizontal(int[][] cartela, int[] sorteados, int qtdSorteados) {
        for (int i = 0; i < 5; i++) {
            boolean completa = true;
            for (int j = 0; j < 5; j++) {
                if (j != 2 || i != 2) {
                    if (!contido(cartela[i][j], sorteados, qtdSorteados)) completa = false;
                }
            }
            if (completa) return true;
        }
        return false;
    }
    
    public static boolean verificaVertical(int[][] cartela, int[] sorteados, int qtdSorteados) {
        for (int j = 0; j < 5; j++) {
            boolean completa = true;
            for (int i = 0; i < 5; i++) {
                if (j != 2 || i != 2) {
                    if (!contido(cartela[i][j], sorteados, qtdSorteados)) completa = false;
                }
            }
            if (completa) return true;
        }
        return false;
    }
    
    public static boolean verificaCartelaCheia(int[][] cartela, int[] sorteados, int qtdSorteados) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (j != 2 || i != 2) {
                    if (!contido(cartela[i][j], sorteados, qtdSorteados)) return false;
                }
            }
        }
        return true;
    }
    
    public static void sorteiaNumero(int[] sorteados, int qtdSorteados) {
        Random rand = new Random();
        int num;
        do {
            num = rand.nextInt(75) + 1;
        } while (contido(num, sorteados, qtdSorteados));
        sorteados[qtdSorteados] = num;
    }
    
    public static boolean contido(int num, int[] sorteados, int qtdSorteados) {
        for (int i = 0; i < qtdSorteados; i++) {
            if (sorteados[i] == num) return true;
        }
        return false;
    }
    
    public static void mostraSorteados(int[] sorteados, int qtdSorteados) {
        System.out.print("Números sorteados: ");
        for (int i = 0; i < qtdSorteados; i++) {
            System.out.print(sorteados[i] + " ");
        }
        System.out.println();
    }
    
    public static void mostraCartela(int[][] cartela) {
        for (int[] linha : cartela) {
            for (int valor : linha) {
                System.out.print((valor == 0 ? "*" : valor) + "\t");
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        int[][][] cartelas = new int[5][5][5];
        int[] sorteados = new int[75];
        int qtdSorteados = 0;
        for (int i = 0; i < 5; i++) {
            cartelas[i] = geraCartela();
        }
        boolean jogoAtivo = true;
        int a, b, c;
        a = b = c =0;
        while (jogoAtivo) {
            sorteiaNumero(sorteados, qtdSorteados);
            qtdSorteados++;
            mostraSorteados(sorteados, qtdSorteados);
            for (int i = 0; i < 5; i++) {
                System.out.println("Cartela " + (i + 1) + ":");
                mostraCartela(cartelas[i]);
                if (verificaCartelaCheia(cartelas[i], sorteados, qtdSorteados)) {
                    System.out.println("Cartela " + (i + 1) + " venceu com cartela cheia!");
                    jogoAtivo = false;
                    break;
                } else if (verificaHorizontal(cartelas[i], sorteados, qtdSorteados) && a < 2){
                    System.out.println("Cartela " + (i + 1) + " venceu com linha completa!"); a++;
                    break;
                } else if (verificaVertical(cartelas[i], sorteados, qtdSorteados) && b < 2){
                    System.out.println("Cartela " + (i + 1) + " venceu com coluna completa!"); b++;
                    break;
                } else if (verificaDiagonal(cartelas[i], sorteados, qtdSorteados) && c < 2){
                    System.out.println("Cartela " + (i + 1) + " venceu com diagonal completa!"); c++;
                    break;
                }
            }
        }
    }
}

