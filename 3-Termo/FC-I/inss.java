import java.util.Scanner;

import javax.swing.JOptionPane;

public class Main
{
    //metodo
    static double lerReal(String mensagem)
    {
        double valor;
        do{
            try{
                String str;
                str = JOptionPane.showInputDialog(null, "IRRF CALCULATOR V.1");
                valor = Double.parseDouble(str); // converte para double
            }
            
            catch(Exception e)
            {
                JOptionPane.showMessageDialog(null, "Erro na entrada de dados, tente novamente");
                valor = -1;
            }
        }while(valor ==-1);
        return valor;
    }

    static double calcImpostoRenda(double salarioBase)
    {
        double aliquota = 27.5;
        double irrf, deducao=896;
        if (salarioBase < 4664.68)
        {
            if(salarioBase >= 3751.06)
            
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
        return irrf;
    }

    public static void main (String[] args)
    {
        boolean deNovo=true;
        do{
            String nome;
            //nome = leitura.nextLine(); ler string completa
            //int valor = Integer.parseInt(strEntrada); string para int
            //float valor Float.parseFloat(strEntrada); float para int
            final double DED_DEPENDENTE=189.59;
            System.out.println("IRFF Calculator v 0.1");
            double rendaMensal = 10000.50, inss = 900.00;
            int qDependentes = 2;
            double pensao=0;
            double salarioBase;
        

            //Leitura dos dados
            rendaMensal = lerReal("Informe a sua renda mensal: ");
            inss = lerReal("Informe o valor do INSS: ");
            pensao = lerReal("Informe o valor da pensão: ");
            qDependentes = (int)lerReal("Informe a quantidade de dependentes: ");
            
            salarioBase = rendaMensal-inss-pensao-qDependentes*DED_DEPENDENTE;
            JOptionPane.showMessageDialog(null, "Salário Base para o cálculo do IRRF:" + salarioBase + "O valor do IRRF é de R$ %.2f " + calcImpostoRenda(salarioBase));
            if(JOptionPane.showConfirmDialog(null, "Deseja novo cálculo?") ==JOptionPane.NO_OPTION)
            deNovo=false;
        }while(deNovo);

    }
}
