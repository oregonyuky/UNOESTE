import java.time.LocalDate;
import java.util.Scanner;
public class ex3{
    public static void main(String[] args){
        Scanner leitor = new Scanner(System.in);
        System.out.println("Digite o ano que voce nasceu: ");
        int ano = leitor.nextInt();
        int anoAtual = LocalDate.now().getYear();
        int idade = anoAtual-ano;
        System.out.println("A idade eh: " + idade);
    }
}
