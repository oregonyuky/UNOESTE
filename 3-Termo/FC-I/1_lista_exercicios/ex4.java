import java.util.Scanner;
public class ex4{
    public static void main(String[] argc){
        Scanner leitor = new Scanner(System.in);
        System.out.println("Digite o grau de consciencia: ");
        int grau = leitor.nextInt();
        if(grau >= 2 && grau <=8)System.out.println("TCE Grave, coma profundo");
        else if(grau > 8 && grau <= 13)System.out.println("TCE moderado");
        else if(grau > 13 && grau <=15)System.out.println("TCE Moderado");
        else System.out.println("Fora do alcance");
    }
}
