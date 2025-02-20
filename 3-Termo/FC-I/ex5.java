import java.util.Scanner;
public class ex5{
    public static void main(String[] argc){
        Scanner leitor = new Scanner(System.in);
        System.out.println("Digite os 4 pontos do x1, x2, y1, y2 respectivamente: ");
        double x1 = leitor.nextDouble();
        double x2 = leitor.nextDouble();
        double y1 = leitor.nextDouble();
        double y2 = leitor.nextDouble();
        double distancia =  Math.sqrt(Math.pow(x2-x1, 2) + Math.pow(y2-y1, 2));
        System.out.println("A distancia eh: " + distancia);

    }
}

