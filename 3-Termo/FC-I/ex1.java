import java.util.Scanner;
public class ex1{
    public static void main(String[] args){
        Scanner leitura = new Scanner(System.in);
        double metros = leitura.nextDouble();
        System.out.println("Milhas: " + 0.00062137 * metros);
        System.out.println("Pes: " + 3.2808 * metros);
        System.out.println("Polegadas: " + 39.37007 * metros);
    }
}
