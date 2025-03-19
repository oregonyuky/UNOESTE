import java.util.Scanner;
public class ex6{
    public static void main(String[] argc){
        Scanner leitor = new Scanner(System.in);
        System.out.println("Informe o valor do saque (valor inteiro): ");
        double valor1= leitor.nextDouble();
        int valor = (int)Math.round(valor1 * 100);
        System.out.println(valor);
        System.out.println("O valor do saque pode ser expresso em:\n");
        int reais[] = {1, 5, 10, 20, 50, 100};
        int centavos[] = {1, 5, 10, 25, 50};
        for(int i=0; i<6 ; i++){
            int result = valor / (reais[5-i] * 100);
            if(result > 0){
                System.out.println(result + " nota(s) de " + reais[5-i]);
            }
                valor %= (reais[5-i] * 100);
        }
        for(int i=0; i<5 ; i++){
            int result = valor / centavos[4-i];
            if(result > 0){
                System.out.println(result + " nota(s) de " + centavos[4-i] + " centavos");
            }
            valor %= centavos[4-i];
        }
        leitor.close();
    }
}
