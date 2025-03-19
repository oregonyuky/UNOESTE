import java.util.Scanner;
public class ex2{
    public static void main(String[] args){
        Scanner leitor  = new Scanner(System.in);
        System.out.println("Digite o numero: ");
        int num = leitor.nextInt();
        int sum=0;
        while(num>0){
            sum += num%10;
            num /= 10;
        }
        System.out.println("A soma dos digitos: " + sum);
    }
}
