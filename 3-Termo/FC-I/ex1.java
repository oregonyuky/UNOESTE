import java.util.Scanner;
public class ex1
{
    static double lerReal(String mensagem){
        Scanner leitura = new Scanner(System.in);
        double valor;
        do{
            try{
                valor = leitura.nextDouble();
            }catch(Exception e){
                System.out.println("Erro na entrada de dados");
                valor = -1;
                leitura.next();
            }

        }while(valor == -1);
        return valor;
    } 
    public static void main (String[] args)
    {
        Scanner leitura = new Scanner(System.in);
        String nome;
        //nome = leitura.nextLine();
        final double DED_DEPENDENTE=189.59;
        System.out.println("IRFF Calculator v 0.1");
        double rendaMensal = 10000.50, inss = 900.00;
        int qDependentes = 2;
        double pensao=0;
        double salarioBase;
        double aliquota = 27.5;
        double irrf, deducao=896;

        rendaMensal = lerReal("Informe a mensagem real: ");
        inss = lerReal("Informe o valor do INSS: ");
        pensao = lerReal("Informe o valor da pensao: ");
        qDependentes = (int)lerReal("Informe a quantidade de dependentes: ");

        salarioBase = rendaMensal-inss-pensao-qDependentes*DED_DEPENDENTE;
        System.out.println("Salário Base para o cálculo do IRRF: " + salarioBase);
        if (salarioBase < 4664.68)
        {
            if(salarioBase >= 3751.06)
            {
                aliquota = 22.5;
                deducao = 662.77;
            } 
             else if (salarioBase >= 2826.66)
            {
                aliquota = 15;
                deducao = 381.44;
            }
            else if (salarioBase >= 2259.20)
            {
                aliquota = 7.5;
                deducao = 169.44;
            }
            else
            {
                aliquota = 0;
                deducao = 0;
            }
        }
        irrf = salarioBase*aliquota/100-deducao;
        System.out.printf("O valor do IRRF é de R$ %.2f\n", irrf);
    }
}
